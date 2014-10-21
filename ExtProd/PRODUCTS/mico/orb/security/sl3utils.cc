//
//  MICO SL3 --- an Open Source SL3 implementation
//  Copyright (C) 2002, 2003, 2004 ObjectSecurity Ltd.
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Library General Public
//  License as published by the Free Software Foundation; either
//  version 2 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Library General Public License for more details.
//
//  You should have received a copy of the GNU Library General Public
//  License along with this library; if not, write to the Free
//  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

//  Send comments and/or bug reports to:
//                 micosec@objectsecurity.com
//

//  Written by Karel Gardas, <kgardas@objectsecurity.com>


#ifdef FAST_PCH
#include "csiv2sl3_pch.h"
#endif // FAST_PCH
#ifdef __COMO__
#pragma hdrstop
#endif // __COMO__

#ifndef FAST_PCH
#include <mico/impl.h>
#include <mico/security/sl3utils.h>
#endif // FAST_PCH


using namespace MICOSL3Utils;
using namespace CORBA;
using namespace std;


long MICOSL3Utils::PP::i_count_ = 0;

//
// PP
//

void
MICOSL3Utils::PP::indent(wostream* out)
{
    for (long i=0; i<i_count_; i++)
	(*out) << " ";
    return;
}


void
MICOSL3Utils::PP::inner_scope()
{
    i_count_ = i_count_ + 2;
    assert(i_count_ >= 0);
    return;
}


void
MICOSL3Utils::PP::outer_scope()
{
    i_count_ = i_count_ - 2;
    assert(i_count_ >= 0);
    return;
}


void
MICOSL3Utils::PP::print_time
(std::wostream* out,
 const TimeBase::UtcT& time)
{
    (*out) << "UtcT(" << (long long)time.time << "," << time.inacclo
	   << "," << time.inacchi << "," << time.tdf << ")" << endl;
    return;
}


void
MICOSL3Utils::PP::print_principal_name
(wostream* out,
 const SL3PM::PrincipalName& name)
{
    (*out) << "struct PrincipalName {" << endl;
    PP::inner_scope();
    PP::indent(out);
    (*out) << "the_type = " << name.the_type << endl;
    PP::indent(out);
    (*out) << "the_name = {" << endl;
    PP::inner_scope();
    for (CORBA::ULong i = 0; i < name.the_name.length(); i++) {
	PP::indent(out);
	(*out) << L"\"" << name.the_name[i].in() << L"\"" << endl;
    }
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
}


void
MICOSL3Utils::PP::print_principal
(wostream* out,
 SL3PM::Principal* principal)
{
    if (principal->the_type() == SL3PM::PT_Simple)
	(*out) << "valuetype SimplePrincipal {" << endl;
    if (principal->the_type() == SL3PM::PT_Proxy)
	(*out) << "valuetype ProxyPrincipal {" << endl;
    if (principal->the_type() == SL3PM::PT_Quoting)
	(*out) << "valuetype QuotingPrincipal {" << endl;
    PP::inner_scope();
    PP::indent(out);
    (*out) << "the_type = " << principal->the_type() << endl;
    PP::indent(out);
    (*out) << "the_name = ";
    PP::print_principal_name(out, principal->the_name());
    (*out) << endl;
    PP::indent(out);
//      (*out) << "environmental_attributes = {" << endl;
//      PP::inner_scope();
//      SL3PM::PrinAttributeList env_attr = principal->environmental_attributes();
//      for (CORBA::ULong i = 0; i < env_attr.length(); i++) {
//  	PP::indent(out);
//  	(*out) << "PrinAttribute(\"" << env_attr[i].the_type << "\"" << ","
//  	       << "\"" << env_attr[i].the_value.in() << "\")" << endl;
//      }
//      PP::outer_scope();
//      PP::indent(out);
//      (*out) << "}" << endl;
//      PP::indent(out);
    (*out) << "with_privileges = {" << endl;
    PP::inner_scope();
    SL3PM::ScopedPrivilegesList privs = principal->with_privileges();
    for (CORBA::ULong i = 0; i < privs.length(); i++) {
	PP::print_scoped_privilege(*out, privs[i]);
    }
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
    if (principal->the_type() == SL3PM::PT_Simple) {
	PP::indent(out);
	(*out) << "authenticated = ";
	SL3PM::SimplePrincipal* sp = SL3PM::SimplePrincipal::_downcast(principal);
	assert(sp != NULL);
	if (sp->authenticated()) {
	    (*out) << "true" << endl;
	}
	else {
	    (*out) << "false" << endl;
	}
	PP::indent(out);
	(*out) << "alternate_names = {" << endl;
	PP::inner_scope();
	SL3PM::PrincipalNameList pnlist = sp->alternate_names();
	for (CORBA::ULong i = 0; i < pnlist.length(); i++) {
	    PP::indent(out);
	    (*out) << "todo: printing of alternate names" << endl;
	}
	PP::outer_scope();
	PP::indent(out);
	(*out) << "}" << endl;
    }
    if (principal->the_type() == SL3PM::PT_Proxy) {
	PP::indent(out);
	SL3PM::ProxyPrincipal* pp = SL3PM::ProxyPrincipal::_downcast(principal);
	assert(pp != NULL);
	(*out) << "speaking = ";
	PP::print_principal(out, pp->speaking());
	PP::indent(out);
	(*out) << "speaks_for = ";
	PP::print_principal(out, pp->speaks_for());
    }
    if (principal->the_type() == SL3PM::PT_Quoting) {
	PP::indent(out);
	SL3PM::QuotingPrincipal* pp = SL3PM::QuotingPrincipal::_downcast(principal);
	assert(pp != NULL);
	(*out) << "speaking = ";
	PP::print_principal(out, pp->speaking());
	PP::indent(out);
	(*out) << "quotes_for = ";
	PP::print_principal(out, pp->quotes_for());
    }
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
    return;
}


void
MICOSL3Utils::PP::print_statement
(std::wostream* out,
 SL3PM::Statement* statement)
{
    SL3PM::PrincipalIdentityStatement* pistat = NULL;
    if ((pistat = SL3PM::PrincipalIdentityStatement::_downcast
	 (statement)) != NULL) {
	(*out) << "valuetype PrincipalIdentityStatement {" << endl;
	PP::inner_scope();
	PP::indent(out);
    }
    else if (SL3PM::EndorsementStatement::_downcast(statement) != NULL) {
	(*out) << "valuetype EndorsementStatement {" << endl;
	PP::inner_scope();
	PP::indent(out);
    }
    else {
	(*out) << "valuetype Statement {" << endl;
	PP::inner_scope();
	PP::indent(out);
    }
    (*out) << "the_layer = " << statement->the_layer() << endl;
    PP::indent(out);
    (*out) << "the_type = " << statement->the_type() << endl;
    PP::indent(out);
    (*out) << "encoding_type = ";
    SL3PM::EncodingType_var et = statement->get_encoding_type();
    if (strcmp(et.in(), "") == 0)
	(*out) << "null" << endl;
    else
	(*out) << et.in() << endl;
    PP::indent(out);
    if (pistat != NULL) {
	(*out) << "interpretation_aid = ";
	CORBA::String_var id_aid = pistat->interpretation_aid();
	if (strcmp(id_aid.in(), "") == 0)
	    (*out) << "null" << endl;
	else
	    (*out) << id_aid.in() << endl;
    }
    PP::indent(out);
    (*out) << "the_principal = ";
    PP::print_principal(out, pistat->the_principal());
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
    return;
}


void
MICOSL3Utils::PP::print_statement_list
(wostream* out,
 SL3PM::StatementList* statement_list)
{
    PP::inner_scope();
    SL3PM::StatementList_var stlist = statement_list;
    for (CORBA::ULong i = 0; i < stlist->length(); i++) {
	PP::indent(out);
	PP::print_statement(out, stlist[i]);
    }
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
}


void
MICOSL3Utils::PP::print_resource_name_list
(wostream* out,
 SL3PM::ResourceNameList* rslist)
{
    PP::inner_scope();
    SL3PM::ResourceNameList_var rnlist = rslist;
    for (CORBA::ULong i = 0; i < rnlist->length(); i++) {
	(*out) << "todo: resource name printing" << endl;
    }
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
}


void
MICOSL3Utils::PP::print_credentials_initiator
(std::wostream* out,
 TransportSecurity::CredentialsInitiator_ptr initiator)
{ 
    if (!CORBA::is_nil(initiator)) {
	(*out) << "interface CredentialsInitiator {" << endl;
	PP::inner_scope();
	PP::indent(out);
	(*out) << "the_principal = ";
	PP::print_principal(out, initiator->the_principal());
	PP::indent(out);
	(*out) << "supporting_statements = {" << endl;
	PP::print_statement_list(out, initiator->supporting_statements());
	PP::indent(out);
	(*out) << "restricted_resources = {" << endl;
	PP::print_resource_name_list(out, initiator->restricted_resources());
	PP::indent(out);
	PP::print_environmental_attributes(*out, *initiator->environmental_attributes());
	PP::indent(out);
	(*out) << "supports_endorsement = ";
	if (initiator->supports_endorsement())
	    (*out) << "true" << endl;
	else
	    (*out) << "false" << endl;
	PP::indent(out);
	(*out) << "supports_quoting = ";
	if (initiator->supports_quoting())
	    (*out) << "true" << endl;
	else
	    (*out) << "false" << endl;
	PP::indent(out);
	(*out) << "supports_client_authentication = ";
	if (initiator->supports_client_authentication())
	    (*out) << "true" << endl;
	else
	    (*out) << "false" << endl;
	PP::indent(out);
	(*out) << "supports_target_authentication = ";
	if (initiator->supports_target_authentication())
	    (*out) << "true" << endl;
	else
	    (*out) << "false" << endl;
	PP::indent(out);
	(*out) << "supports_confidentiality = ";
	if (initiator->supports_confidentiality())
	    (*out) << "true" << endl;
	else
	    (*out) << "false" << endl;
	PP::indent(out);
	(*out) << "supports_integrity = ";
	if (initiator->supports_integrity())
	    (*out) << "true" << endl;
	else
	    (*out) << "false" << endl;
	TimeBase::UtcT etime = initiator->expiry_time();
	PP::indent(out);
	(*out) << "expiry_time = ";
	PP::print_time(out, etime);
	PP::outer_scope();
	PP::indent(out);
	(*out) << "}" << endl;
    }
    else {
	(*out) << "(null)" << endl;
    }
    return;
}


void
MICOSL3Utils::PP::print_credentials_acceptor
(std::wostream* out,
 TransportSecurity::CredentialsAcceptor_ptr acceptor)
{
    if (!CORBA::is_nil(acceptor)) {
	(*out) << "interface CredentialsAcceptor {" << endl;
	PP::inner_scope();
	PP::indent(out);
	(*out) << "the_principal = ";
	PP::print_principal(out, acceptor->the_principal());
	PP::indent(out);
	(*out) << "supporting_statements = {" << endl;
	PP::print_statement_list(out, acceptor->supporting_statements());
	PP::indent(out);
	(*out) << "restricted_resources = {" << endl;
	PP::print_resource_name_list(out, acceptor->restricted_resources());
	PP::indent(out);
	PP::print_environmental_attributes(*out, *acceptor->environmental_attributes());
	PP::indent(out);
	(*out) << "supports_endorsement = ";
	if (acceptor->supports_endorsement())
	    (*out) << "true" << endl;
	else
	    (*out) << "false" << endl;
	PP::indent(out);
	(*out) << "supports_quoting = ";
	if (acceptor->supports_quoting())
	    (*out) << "true" << endl;
	else
	    (*out) << "false" << endl;
	PP::indent(out);
	(*out) << "supports_client_authentication = ";
	if (acceptor->supports_client_authentication())
	    (*out) << "true" << endl;
	else
	    (*out) << "false" << endl;
	PP::indent(out);
	(*out) << "supports_target_authentication = ";
	if (acceptor->supports_target_authentication())
	    (*out) << "true" << endl;
	else
	    (*out) << "false" << endl;
	PP::indent(out);
	(*out) << "supports_confidentiality = ";
	if (acceptor->supports_confidentiality())
	    (*out) << "true" << endl;
	else
	    (*out) << "false" << endl;
	PP::indent(out);
	(*out) << "supports_integrity = ";
	if (acceptor->supports_integrity())
	    (*out) << "true" << endl;
	else
	    (*out) << "false" << endl;
	TimeBase::UtcT etime = acceptor->expiry_time();
	PP::indent(out);
	(*out) << "expiry_time = ";
	PP::print_time(out, etime);
	PP::outer_scope();
	PP::indent(out);
	(*out) << "}" << endl;
    }
    else {
	(*out) << "(null)" << endl;
    }
    return;
}


void
MICOSL3Utils::PP::print_own_credentials
(wostream* out,
 TransportSecurity::OwnCredentials_ptr creds)
{
    (*out) << "interface OwnCredentials {" << endl;
    PP::inner_scope();
    PP::indent(out);
    (*out) << "creds_id = " << creds->creds_id() << endl;
    PP::indent(out);
    (*out) << "creds_usage = " << creds->creds_usage() << endl;
    PP::indent(out);
    (*out) << "supports_csi_version(CSIv1) = ";
    if (creds->supports_csi_version(TransportSecurity::CSIv1))
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "supports_csi_version(CSIv2) = ";
    if (creds->supports_csi_version(TransportSecurity::CSIv2))
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    TimeBase::UtcT etime = creds->expiry_time();
    (*out) << "expiry_time = ";
//  UtcT(" << (long long)etime.time << "," << etime.inacclo
//  	<< "," << etime.inacchi << "," << etime.tdf << ")" << endl;
    PP::print_time(out, etime);
    PP::indent(out);
    (*out) << "the_initiator = {" << endl;
    PP::inner_scope();
    PP::indent(out);
    TransportSecurity::CredentialsInitiator_var initiator = creds->the_initiator();
    PP::print_credentials_initiator(out, initiator);
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
    PP::indent(out);
    (*out) << "the_acceptor = {" << endl;
    PP::inner_scope();
    PP::indent(out);
    TransportSecurity::CredentialsAcceptor_var acceptor = creds->the_acceptor();
    PP::print_credentials_acceptor(out, acceptor);
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
}


void
MICOSL3Utils::PP::print_target_credentials
(wostream* out,
 TransportSecurity::TargetCredentials_ptr creds)
{
    assert(!CORBA::is_nil(creds));
    TransportSecurity::InitiatingContext_ptr ctx
	= TransportSecurity::InitiatingContext::_narrow(creds);
    if (!CORBA::is_nil(ctx)) {
	(*out) << "interface InitiatingContext {" << endl;
	PP::inner_scope();
    }
    else {
	(*out) << "interface TargetCredentials {" << endl;
	PP::inner_scope();
    }
    PP::indent(out);
    (*out) << "context_id = " << creds->context_id() << endl;
    PP::indent(out);
    // client side
    (*out) << "client_principal = ";
    PP::print_principal(out, creds->client_principal());
    PP::indent(out);
    (*out) << "client_supporting_statements = {" << endl;
    PP::print_statement_list(out, creds->client_supporting_statements());
    PP::indent(out);
    (*out) << "client_restricted_resources = {" << endl;
    PP::print_resource_name_list(out, creds->client_restricted_resources());
    // target side
    PP::indent(out);
    (*out) << "target_principal = ";
    PP::print_principal(out, creds->target_principal());
    PP::indent(out);
    (*out) << "target_supporting_statements = {" << endl;
    PP::print_statement_list(out, creds->target_supporting_statements());
    PP::indent(out);
    (*out) << "target_restricted_resources = {" << endl;
    PP::print_resource_name_list(out, creds->target_restricted_resources());
    PP::indent(out);
    // environmental attributes
    PP::print_environmental_attributes(*out, *creds->environmental_attributes());
    PP::indent(out);
    // parent creds
    TransportSecurity::OwnCredentials_var parent = creds->parent_credentials();
    (*out) << "parent_credentials = " << parent->creds_id() << endl;
    // boolean values
    PP::indent(out);
    (*out) << "client_authentication = ";
    if (creds->client_authentication())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "target_authentication = ";
    if (creds->target_authentication())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "confidentiality = ";
    if (creds->confidentiality())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "integrity = ";
    if (creds->integrity())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "expiry_time = ";
    PP::print_time(out, creds->expiry_time());
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
}


void
MICOSL3Utils::PP::print_client_credentials
(wostream* out,
 TransportSecurity::ClientCredentials_ptr creds)
{
    TransportSecurity::AcceptingContext_ptr ctx
	= TransportSecurity::AcceptingContext::_narrow(creds);
    if (!CORBA::is_nil(ctx)) {
	(*out) << "interface AcceptingContext {" << endl;
	PP::inner_scope();
    }
    else {
	(*out) << "interface ClientCredentials {" << endl;
	PP::inner_scope();
    }
    PP::indent(out);
    (*out) << "context_id = " << creds->context_id() << endl;
    PP::indent(out);
    // client side
    (*out) << "client_principal = ";
    PP::print_principal(out, creds->client_principal());
    PP::indent(out);
    (*out) << "client_supporting_statements = {" << endl;
    PP::print_statement_list(out, creds->client_supporting_statements());
    PP::indent(out);
    (*out) << "client_restricted_resources = {" << endl;
    PP::print_resource_name_list(out, creds->client_restricted_resources());
    // target side
    PP::indent(out);
    (*out) << "target_principal = ";
    PP::print_principal(out, creds->target_principal());
    PP::indent(out);
    (*out) << "target_supporting_statements = {" << endl;
    PP::print_statement_list(out, creds->target_supporting_statements());
    PP::indent(out);
    (*out) << "target_restricted_resources = {" << endl;
    PP::print_resource_name_list(out, creds->target_restricted_resources());
    PP::indent(out);
    // environmental attributes
    PP::print_environmental_attributes(*out, *creds->environmental_attributes());
    PP::indent(out);
    // parent creds
    TransportSecurity::OwnCredentials_var parent = creds->parent_credentials();
    (*out) << "parent_credentials = " << parent->creds_id() << endl;
    // boolean values
    PP::indent(out);
    (*out) << "client_authentication = ";
    if (creds->client_authentication())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "target_authentication = ";
    if (creds->target_authentication())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "confidentiality = ";
    if (creds->confidentiality())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "integrity = ";
    if (creds->integrity())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "expiry_time = ";
    PP::print_time(out, creds->expiry_time());
    PP::indent(out);
    (*out) << "impersonalble = ";
    if (creds->impersonable())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "endorseable = ";
    if (creds->endorseable())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "quotable = ";
    if (creds->quotable())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
}


void
MICOSL3Utils::PP::print_creds_initiator
(wostream* out,
 SecurityLevel3::CredsInitiator_ptr initiator)
{
    (*out) << "interface CredsInitiator {" << endl;
    PP::inner_scope();
    PP::indent(out);
    (*out) << "the_principal = ";
    PP::print_principal(out, initiator->the_principal());
    PP::indent(out);
    (*out) << "supporting_statements = {" << endl;
    PP::print_statement_list(out, initiator->supporting_statements());
    PP::indent(out);
    (*out) << "restricted_resources = {" << endl;
    PP::print_resource_name_list(out, initiator->restricted_resources());
    PP::indent(out);
    PP::print_environmental_attributes(*out, *initiator->environmental_attributes());
    PP::indent(out);
    (*out) << "initiator_type = " << initiator->initiator_type() << endl;
    PP::indent(out);
    (*out) << "supports_embodiment = ";
    if (initiator->supports_embodiment())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "supports_endorsement = ";
    if (initiator->supports_endorsement())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "supports_quoting = ";
    if (initiator->supports_quoting())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);	
    (*out) << "expiry_time = ";
    PP::print_time(out, initiator->expiry_time());
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
}


void
MICOSL3Utils::PP::print_creds_acceptor
(wostream* out,
 SecurityLevel3::CredsAcceptor_ptr acceptor)
{
    (*out) << "interface CredsAcceptor {" << endl;
    PP::inner_scope();
    PP::indent(out);
    (*out) << "the_principal = ";
    PP::print_principal(out, acceptor->the_principal());
    PP::indent(out);
    (*out) << "supporting_statements = {" << endl;
    PP::print_statement_list(out, acceptor->supporting_statements());
    PP::indent(out);
    (*out) << "restricted_resources = {" << endl;
    PP::print_resource_name_list(out, acceptor->restricted_resources());
    PP::indent(out);
    PP::print_environmental_attributes(*out, *acceptor->environmental_attributes());
    PP::indent(out);
    (*out) << "accepts_endorsement = ";
    if (acceptor->accepts_endorsement())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "accepts_quoting = ";
    if (acceptor->accepts_quoting())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "expiry_time = ";
    PP::print_time(out, acceptor->expiry_time());
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
}


void
MICOSL3Utils::PP::print_own_credentials
(wostream* out,
 SecurityLevel3::OwnCredentials_ptr creds)
{
    (*out) << "interface OwnCredentials {" << endl;
    PP::inner_scope();
    PP::indent(out);
    (*out) << "creds_id = " << creds->creds_id() << endl;
    PP::indent(out);
    (*out) << "creds_type = " << creds->creds_type() << endl;
    PP::indent(out);
    (*out) << "creds_usage = " << creds->creds_usage() << endl;
    PP::indent(out);
    (*out) << "creds_state = " << creds->creds_state() << endl;
    SecurityLevel3::CredsInitiator_var initiator = creds->creds_initiator();
    if (!CORBA::is_nil(initiator)) {
	PP::indent(out);
	PP::print_creds_initiator(out, initiator);
    }
    SecurityLevel3::CredsAcceptor_var acceptor = creds->creds_acceptor();
    if (!CORBA::is_nil(acceptor)) {
	PP::indent(out);	
	PP::print_creds_acceptor(out, acceptor);
    }
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
}


void
MICOSL3Utils::PP::print_target_credentials
(wostream* out,
 SecurityLevel3::TargetCredentials_ptr creds)
{
    (*out) << "interface TargetCredentials {" << endl;
    PP::inner_scope();
    PP::indent(out);
    (*out) << "creds_id = " << creds->creds_id() << endl;
    PP::indent(out);
    (*out) << "creds_type = " << creds->creds_type() << endl;
    PP::indent(out);
    (*out) << "creds_usage = " << creds->creds_usage() << endl;
    PP::indent(out);
    (*out) << "creds_state = " << creds->creds_state() << endl;
    PP::indent(out);
    (*out) << "context_id = " << creds->context_id() << endl;
    PP::indent(out);
    (*out) << "client_principal = ";
    PP::print_principal(out, creds->client_principal());
    PP::indent(out);
    (*out) << "client_supporting_statements = {" << endl;
    //PP::inner_scope();
    PP::print_statement_list(out, creds->client_supporting_statements());
    //PP::outer_scope();
    //PP::indent(out);
    //(*out) << "}" << endl;
    PP::indent(out);
    (*out) << "client_restricted_resources = {" << endl;
    //PP::inner_scope();
    PP::print_resource_name_list(out, creds->client_restricted_resources());
    //PP::outer_scope();
    //PP::indent(out);
    //(*out) << "}" << endl;
    PP::indent(out);
    (*out) << "target_principal = ";
    PP::print_principal(out, creds->target_principal());
    PP::indent(out);
    (*out) << "target_supporting_statements = {" << endl;
    //PP::inner_scope();
    //PP::indent(out);
    PP::print_statement_list(out, creds->target_supporting_statements());
    //PP::outer_scope();
    //PP::indent(out);
    //(*out) << "}" << endl;
    PP::indent(out);
    (*out) << "target_restricted_resources = {" << endl;
    //PP::inner_scope();
    //PP::indent(out);
    PP::print_resource_name_list(out, creds->target_restricted_resources());
    //PP::outer_scope();
    //PP::indent(out);
    //(*out) << "}" << endl;
    //PP::outer_scope();
    PP::indent(out);
    PP::print_environmental_attributes(*out, *creds->environmental_attributes());
    PP::indent(out);
    (*out) << "parent_credentials = " << creds->parent_credentials()->creds_id() << endl;
    PP::indent(out);
    (*out) << "client_authentication = ";
    if (creds->client_authentication())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "target_authentication = ";
    if (creds->target_authentication())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;	
    PP::indent(out);
    (*out) << "confidentiality = ";
    if (creds->confidentiality())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "integrity = ";
    if (creds->integrity())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "target_embodied = ";
    if (creds->target_embodied())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "target_endorsed = ";
    if (creds->target_endorsed())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
}


void
MICOSL3Utils::PP::print_client_credentials
(wostream* out,
 SecurityLevel3::ClientCredentials_ptr creds)
{
    (*out) << "interface ClientCredentials {" << endl;
    PP::inner_scope();
    PP::indent(out);
    (*out) << "creds_id = " << creds->creds_id() << endl;
    PP::indent(out);
    (*out) << "creds_type = " << creds->creds_type() << endl;
    PP::indent(out);
    (*out) << "creds_usage = " << creds->creds_usage() << endl;
    PP::indent(out);
    (*out) << "creds_state = " << creds->creds_state() << endl;
    PP::indent(out);
    (*out) << "context_id = " << creds->context_id() << endl;
    PP::indent(out);
    (*out) << "client_principal = ";
    PP::print_principal(out, creds->client_principal());
    PP::indent(out);
    (*out) << "client_supporting_statements = {" << endl;
    PP::print_statement_list(out, creds->client_supporting_statements());
    PP::indent(out);
    (*out) << "client_restricted_resources = {" << endl;
    PP::print_resource_name_list(out, creds->client_restricted_resources());
    PP::indent(out);
    (*out) << "target_principal = ";
    PP::print_principal(out, creds->target_principal());
    PP::indent(out);
    (*out) << "target_supporting_statements = {" << endl;
    PP::print_statement_list(out, creds->target_supporting_statements());
    PP::indent(out);
    (*out) << "target_restricted_resources = {" << endl;
    PP::print_resource_name_list(out, creds->target_restricted_resources());
    PP::indent(out);
    PP::print_environmental_attributes(*out, *creds->environmental_attributes());
    PP::indent(out);
    (*out) << "parent_credentials = " << creds->parent_credentials()->creds_id() << endl;
    PP::indent(out);
    (*out) << "client_authentication = ";
    if (creds->client_authentication())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "target_authentication = ";
    if (creds->target_authentication())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;	
    PP::indent(out);
    (*out) << "confidentiality = ";
    if (creds->confidentiality())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::indent(out);
    (*out) << "integrity = ";
    if (creds->integrity())
	(*out) << "true" << endl;
    else
	(*out) << "false" << endl;
    PP::outer_scope();
    PP::indent(out);
    (*out) << "}" << endl;
}


void
MICOSL3Utils::PP::print_environmental_attributes
(std::wostream& out,
 const SL3PM::PrinAttributeList& env_attr)
{
    out << "environmental_attributes = {" << endl;
    PP::inner_scope();
    for (CORBA::ULong i = 0; i < env_attr.length(); i++) {
	PP::indent(&out);
	out << "PrinAttribute(\"" << env_attr[i].the_type << "\"" << ","
	    << "\"" << env_attr[i].the_value.in() << "\")" << endl;
    }
    PP::outer_scope();
    PP::indent(&out);
    out << "}" << endl;
}


void
MICOSL3Utils::PP::print_scoped_privilege
(wostream& out,
 const SL3PM::ScopedPrivileges& privilege)
{
    PP::indent(&out);
    out << "struct ScopedPrivileges {" << endl;
    PP::inner_scope();
    PP::indent(&out);
    out << "privilege_authority = ";
    PP::print_principal_name(&out, privilege.privilege_authority);
    out << endl;
    PP::indent(&out);
    out << "privileges = {" << endl;
    PP::inner_scope();
    for (CORBA::ULong i = 0; i < privilege.privileges.length(); i++) {
	PP::indent(&out);
	PP::print_prinattribute(out, privilege.privileges[i]);
    }
    PP::outer_scope();
    PP::indent(&out);
    out << "}" << endl;
    PP::outer_scope();
    PP::indent(&out);
    out << "}" << endl;
}


void
MICOSL3Utils::PP::print_prinattribute
(wostream& out,
 const SL3PM::PrinAttribute& attr)
{
    out << "PrinAttribute(\"" << attr.the_type
	<< "\", \"" << attr.the_value.in() << "\")" << endl;
}


//
// Address
//

string
MICOSL3Utils::Address::addr_to_string(const CORBA::Address* addr)
{
    const MICO::InetAddress* i_addr
	= dynamic_cast<const MICO::InetAddress*>(addr);
    if (i_addr == NULL) {
	// it might be SSLAddress
	const MICOSSL::SSLAddress* ssladdr
	    = dynamic_cast<const MICOSSL::SSLAddress*>(addr);
	if (ssladdr != NULL) {
	    i_addr = dynamic_cast<const MICO::InetAddress*>
		(ssladdr->content());
	}
    }
    assert(i_addr != NULL);
    string t_addr = "";
    vector<CORBA::Octet> ip_addr = i_addr->ipaddr();
    assert(ip_addr.size() == 4);
    t_addr = xdec(ip_addr[0]) + "." + xdec(ip_addr[1]) + "."
	+ xdec(ip_addr[2]) + "." + xdec(ip_addr[3]);
    t_addr = t_addr + ":" + xdec(i_addr->port());
    return t_addr;
}


wstring
MICOSL3Utils::Address::addr_to_wstring(const CORBA::Address* addr)
{
    const MICO::InetAddress* i_addr
	= dynamic_cast<const MICO::InetAddress*>(addr);
    if (i_addr == NULL) {
	// it might be SSLAddress
	const MICOSSL::SSLAddress* ssladdr
	    = dynamic_cast<const MICOSSL::SSLAddress*>(addr);
	if (ssladdr != NULL) {
	    i_addr = dynamic_cast<const MICO::InetAddress*>
		(ssladdr->content());
	}
    }
    assert(i_addr != NULL);
    wstring t_addr = L"";
    vector<CORBA::Octet> ip_addr = i_addr->ipaddr();
    assert(ip_addr.size() == 4);
    t_addr = wxdec(ip_addr[0]) + L"." + wxdec(ip_addr[1]) + L"."
	+ wxdec(ip_addr[2]) + L"." + wxdec(ip_addr[3]);
    t_addr = t_addr + L":" + wxdec(i_addr->port());
    return t_addr;
}


string
MICOSL3Utils::Address::ip_to_string(const CORBA::Address* addr)
{
    const MICO::InetAddress* i_addr
	= dynamic_cast<const MICO::InetAddress*>(addr);
    if (i_addr == NULL) {
	// it might be SSLAddress
	const MICOSSL::SSLAddress* ssladdr
	    = dynamic_cast<const MICOSSL::SSLAddress*>(addr);
	if (ssladdr != NULL) {
	    i_addr = dynamic_cast<const MICO::InetAddress*>
		(ssladdr->content());
	}
    }
    assert(i_addr != NULL);
    string t_addr = "";
    vector<CORBA::Octet> ip_addr = i_addr->ipaddr();
    assert(ip_addr.size() == 4);
    t_addr = xdec(ip_addr[0]) + "." + xdec(ip_addr[1]) + "."
	+ xdec(ip_addr[2]) + "." + xdec(ip_addr[3]);
    return t_addr;
}


wstring
MICOSL3Utils::Address::ip_to_wstring(const CORBA::Address* addr)
{
    const MICO::InetAddress* i_addr
	= dynamic_cast<const MICO::InetAddress*>(addr);
    if (i_addr == NULL) {
	// it might be SSLAddress
	const MICOSSL::SSLAddress* ssladdr
	    = dynamic_cast<const MICOSSL::SSLAddress*>(addr);
	if (ssladdr != NULL) {
	    i_addr = dynamic_cast<const MICO::InetAddress*>
		(ssladdr->content());
	}
    }
    assert(i_addr != NULL);
    wstring t_addr = L"";
    vector<CORBA::Octet> ip_addr = i_addr->ipaddr();
    assert(ip_addr.size() == 4);
    t_addr = wxdec(ip_addr[0]) + L"." + wxdec(ip_addr[1]) + L"."
	+ wxdec(ip_addr[2]) + L"." + wxdec(ip_addr[3]);
    return t_addr;
}


string
MICOSL3Utils::Address::port_to_string(const CORBA::Address* addr)
{
    const MICO::InetAddress* i_addr
	= dynamic_cast<const MICO::InetAddress*>(addr);
    if (i_addr == NULL) {
	// it might be SSLAddress
	const MICOSSL::SSLAddress* ssladdr
	    = dynamic_cast<const MICOSSL::SSLAddress*>(addr);
	if (ssladdr != NULL) {
	    i_addr = dynamic_cast<const MICO::InetAddress*>
		(ssladdr->content());
	}
    }
    assert(i_addr != NULL);
    string t_port = xdec(i_addr->port());
    return t_port;
}


wstring
MICOSL3Utils::Address::port_to_wstring(const CORBA::Address* addr)
{
    const MICO::InetAddress* i_addr
	= dynamic_cast<const MICO::InetAddress*>(addr);
    if (i_addr == NULL) {
	// it might be SSLAddress
	const MICOSSL::SSLAddress* ssladdr
	    = dynamic_cast<const MICOSSL::SSLAddress*>(addr);
	if (ssladdr != NULL) {
	    i_addr = dynamic_cast<const MICO::InetAddress*>
		(ssladdr->content());
	}
    }
    assert(i_addr != NULL);
    wstring t_port = wxdec(i_addr->port());
    return t_port;
}


//
// X509Cert
//

MICOSL3Utils::X509Cert::X509Cert(const string& cert)
{
    verified_ = FALSE;
    FILE* in = fopen(cert.c_str(), "r");
    if (in == NULL)
	mico_throw(BAD_PARAM());
    X509* x = PEM_read_X509(in, NULL, NULL, NULL);
    this->init_from_x509(x);
    X509_free(x);
}


MICOSL3Utils::X509Cert::X509Cert(X509* cert)
{
    verified_ = FALSE;
    this->init_from_x509(cert);
}


MICOSL3Utils::X509Cert::X509Cert
(const string& cert,
 const string& verification_cert)
{
    //cerr << "MICOSL3Utils::X509Cert ctor: " << cert << ", " << verification_cert << endl;
    verified_ = FALSE;
    FILE* cf = fopen(cert.c_str(), "r");
    if (cf == NULL)
	mico_throw(BAD_PARAM());
    X509* c = PEM_read_X509(cf, NULL, NULL, NULL);
    FILE* vf = fopen(verification_cert.c_str(), "r");
    if (vf == NULL)
  	mico_throw(BAD_PARAM());
    X509* v = PEM_read_X509(vf, NULL, NULL, NULL);
    verified_ = this->verify(c, v);
    this->init_from_x509(c);
    fclose(cf);
    fclose(vf);
    X509_free(c);
    X509_free(v);
}


MICOSL3Utils::X509Cert::X509Cert(X509* cert, X509* verification_cert)
{
    verified_ = FALSE;
    // kcg: the call below might throw exception and I would
    // like to be 100% sure that verified_ == FALSE
    verified_ = this->verify(cert, verification_cert);
    this->init_from_x509(cert);
}


MICOSL3Utils::X509Cert::X509Cert(const X509Cert& cert)
{
    verified_ = cert.verified_;
    issuer_ = cert.issuer_;
    subject_ = cert.subject_;
}


MICOSL3Utils::X509Cert::X509Cert()
    : issuer_(""), subject_(""), verified_(FALSE)
{
}


MICOSL3Utils::X509Cert&
MICOSL3Utils::X509Cert::operator=(const X509Cert& cert)
{
    verified_ = cert.verified_;
    issuer_ = cert.issuer_;
    subject_ = cert.subject_;
    return *this;
}


void
MICOSL3Utils::X509Cert::init_from_x509(X509* data)
{
    if (data == NULL)
	mico_throw(BAD_PARAM());
    X509_NAME* issuer = X509_get_issuer_name(data);
    char* t = X509_NAME_oneline(issuer, 0, 0);
    issuer_ = t;
    OPENSSL_free(t);
    X509_NAME* subject = X509_get_subject_name(data);
    t = X509_NAME_oneline(subject, 0, 0);
    subject_ = t;
    OPENSSL_free(t);
}


string
MICOSL3Utils::X509Cert::issuer() const
{
    return issuer_;
}


string
MICOSL3Utils::X509Cert::subject() const
{
    return subject_;
}


bool
MICOSL3Utils::X509Cert::verify() const
{
    return verified_;
}


bool
MICOSL3Utils::X509Cert::verify(X509* cert, X509* verification_cert)
{
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    //cerr << "509Cert::verify" << endl;
    if (cert == NULL || verification_cert == NULL) {
	mico_throw(BAD_PARAM());
    }
    EVP_PKEY* pubkey = X509_get_pubkey(verification_cert);
    if (pubkey == NULL) {
	mico_throw(BAD_PARAM());
    }
    int result = X509_verify(cert, pubkey);
    EVP_PKEY_free(pubkey);
    //cerr << "result: " << result << endl;
    if (result == 1) {
	//cerr << "verified OK" << endl;
	return TRUE;
    }
    //cerr << "Cert CORRUPTED!!!" << endl;
    return FALSE;
}


//
// CredsRetriever
//

SecurityLevel3::OwnCredentialsList*
MICOSL3Utils::CredsRetriever::get_own_credentials_list
(CORBA::ORB_ptr orb,
 CORBA::Object_ptr target,
 CORBA::Boolean use_context_establishment_policy)
{
    CORBA::Object_var obj = orb->resolve_initial_references
	("SecurityLevel3::SecurityManager");
    SecurityLevel3::SecurityManager_var secman
	= SecurityLevel3::SecurityManager::_narrow(obj);
    assert(!CORBA::is_nil(secman));
    SecurityLevel3::CredentialsCurator_var curator
	= secman->credentials_curator();
    SecurityLevel3::OwnCredentialsList_var creds_list = NULL;
    SecurityLevel3::ContextEstablishmentPolicy_var policy
	= SecurityLevel3::ContextEstablishmentPolicy::_nil();
    try {
	CORBA::Policy_var p = target->_get_policy
	    (SecurityLevel3::ContextEstablishmentPolicyType);
	policy = SecurityLevel3::ContextEstablishmentPolicy::_narrow(p);
    } catch (CORBA::BAD_PARAM& ex) {
	//cerr << ex._repoid() << endl;
	// this is thrown by MICO and CORBA 2.2. It seems MICO
	// is not compliant here with CORBA 2.3.
    } catch (CORBA::SystemException& ex) {
	//cerr << ex._repoid() << endl;
	// CORBA 2.3 and highers might throw either INV_POLICY
	// or BAD_INV_ORDER exceptions
    }
    if (use_context_establishment_policy && !CORBA::is_nil(policy)) {
	// there are credentials set directly on this object reference
	//cerr << "use policy's creds list" << endl;
	creds_list = policy->creds_list();
    }
    else {
	// we will use default credentials
	//cerr << "default creds list used" << endl;
	creds_list = curator->default_creds_list();
    }
    return creds_list._retn();
}


SecurityLevel3::OwnCredentials_ptr
MICOSL3Utils::CredsRetriever::get_client_side_own_credentials
(CORBA::ORB_ptr orb,
 CORBA::Object_ptr target,
 CORBA::Boolean use_context_establishment_policy)
{
    SecurityLevel3::OwnCredentialsList_var creds_list
	= MICOSL3Utils::CredsRetriever::get_own_credentials_list
	(orb, target, use_context_establishment_policy);
    for (CORBA::ULong i = 0; i < creds_list->length(); i++) {
	SecurityLevel3::OwnCredentials_var creds = (*creds_list)[i];
	if (creds->creds_usage() == SL3CM::CU_InitiateOnly
	    ||creds->creds_usage() == SL3CM::CU_InitiateAndAccept) {
	    return creds._retn();
	}
    }
    return SecurityLevel3::OwnCredentials::_nil();
}


SecurityLevel3::OwnCredentials_ptr
MICOSL3Utils::CredsRetriever::get_server_side_own_credentials
(CORBA::ORB_ptr orb)
{
    CORBA::Object_var obj = orb->resolve_initial_references
	("SecurityLevel3::SecurityManager");
    SecurityLevel3::SecurityManager_var secman
	= SecurityLevel3::SecurityManager::_narrow(obj);
    assert(!CORBA::is_nil(secman));
    SecurityLevel3::CredentialsCurator_var curator
	= secman->credentials_curator();
    SecurityLevel3::OwnCredentialsList_var creds_list
	= curator->default_creds_list();
    for (CORBA::ULong i = 0; i < creds_list->length(); i++) {
	SecurityLevel3::OwnCredentials_var creds = (*creds_list)[i];
	if (creds->creds_usage() == SL3CM::CU_AcceptOnly
	    ||creds->creds_usage() == SL3CM::CU_InitiateAndAccept) {
	    return creds._retn();
	}
    }
    return SecurityLevel3::OwnCredentials::_nil();
}

