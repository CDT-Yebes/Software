//
//  MICO CSIv2 --- an Open Source CSIv2 implementation
//  Copyright (C) 2002, 2003, 2004, 2005 ObjectSecurity Ltd.
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
#include <mico/security/csiv2_impl.h>
#ifdef USE_SL3
#include <mico/security/sl3csi_impl.h>
#include <mico/security/sl3pm_impl.h>
#include <mico/security/transportsecurity_impl.h>
#include <mico/security/sl3utils.h>
#endif // USE_SL3
#include <mico/codec_impl.h>
#include <mico/util.h>
#include <iostream>
#include <iomanip>
#ifdef USE_SL3
#include <sstream>
#endif // USE_SL3
#endif // FAST_PCH

#ifndef HAVE_SSL
// this is an error since CSIv2 depends on MICO SSL support
#error "Please build MICO with SSL support in order to use MICO CSIv2"
#endif // HAVE_SSL

#define USE_ENCODE_VALUE


using namespace std;
#ifdef USE_SL3
using namespace SL3PM;
using namespace SL3CM;
using namespace SL3Authorization;
using namespace CSI;
#endif // USE_SL3
using CORBA::Boolean;


//
// static members initialization
//
#ifdef USE_SL3
CORBA::ULong
CSIv2::SecurityManager_impl::S_client_creds_index_ = 0;
CORBA::ULong
CSIv2::CSS_impl::S_target_creds_index_ = 0;
#endif // USE_SL3

//
// This is primitive debug function for printing octetseq in form:
// <hexa> <16 repeat>  <char> <16 repeat>
//

void debug(ostream* out, const CORBA::OctetSeq* seq)
{
    CORBA::ULong i,j;
    for (i=0; i<seq->length(); i+=16) {
	for (j=i; j<i+16; j++) {
	    if ((*seq).length() > j) {
		(*out) << setw(2) << setfill('0') << hex
		       << (short)(*seq)[j] << " ";
	    }
	    else {
		(*out) << "   ";
	    }
	    if ((j+1)%8 == 0)
		(*out) << "  ";
	}
	(*out) << "  ";
	for (j=i; j<seq->length() && j<i+16; j++) {
	    if (isprint((*seq)[j]))
		(*out) << (char)(*seq)[j];
	    else
		(*out) << '.';
	    if ((j+1)%8 == 0)
		(*out) << "  ";
	}
	(*out) << endl;
    }
    // restore settings
    (*out) << setw(0) << dec;
}

CSIv2::CSS_impl::CSS_impl()
    : sec_manager_(SecurityManager::_nil())
{
    CORBA::Any any;
    CSI::SASContextBody body;
    any <<= body;
    sas_body_tc_ = CORBA::TypeCode::_duplicate(any.type());
#ifdef USE_SL3
    supports_at_delegation_ = FALSE;
#endif // USE_SL3
}


void
CSIv2::CSS_impl::security_manager(SecurityManager_ptr manager)
{
    if (!CORBA::is_nil(sec_manager_)) {
	CORBA::release(sec_manager_);
	sec_manager_ = SecurityManager::_nil();
    }
    sec_manager_ = SecurityManager::_duplicate(manager);
}

CSIv2::SecurityManager_ptr
CSIv2::CSS_impl::security_manager()
{
    return sec_manager_;
}

void
CSIv2::CSS_impl::write_sas_context
(PortableInterceptor::ClientRequestInfo_ptr info,
 const CSIIOP::CompoundSecMechList& plist)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "CSIv2::CSS_impl::write_sas_context" << endl;
    //assert(plist.mechanism_list.length() > 0);
    if (plist.mechanism_list.length() == 0) {
	// non-CSIv2 enabled target
	return;
    }
    CSIIOP::CompoundSecMech mech = plist.mechanism_list[0];
#ifdef USE_SL3
    // invoke trust in server decider, if available at the first
    CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
    assert(!CORBA::is_nil(orb));
    CORBA::Object_var t_obj = orb->resolve_initial_references
        ("TransportSecurity::SecurityManager");
    TransportSecurity::SecurityManager_var ts_secman
	= TransportSecurity::SecurityManager::_narrow(t_obj);
    assert(!CORBA::is_nil(ts_secman));
    MICOSL3_TransportSecurity::SecurityManager_impl* tsm_impl
	= dynamic_cast<MICOSL3_TransportSecurity::SecurityManager_impl*>(t_obj.in());
    assert(tsm_impl != NULL);
    if (tsm_impl->security_enabled()) {
	CORBA::Object_var target = info->target();
	SecurityLevel3::OwnCredentials_var creds
	    = MICOSL3Utils::CredsRetriever::get_client_side_own_credentials
	    (orb, target, TRUE);
	assert(!CORBA::is_nil(creds));
	SecurityLevel3::CredsInitiator_var initiator = creds->creds_initiator();
	assert(!CORBA::is_nil(initiator));
	MICOSL3_SL3CSI::CSICredsInitiator* initiator_impl
	    = dynamic_cast<MICOSL3_SL3CSI::CSICredsInitiator*>
	    (initiator.in());
	assert(initiator_impl != NULL);
	Trust::LocalTrustInServerDecider_var decider
	    = initiator_impl->trust_decider();
	if (!CORBA::is_nil(decider)) {
	    // trust decider available => invoke it
	    // first, we need to check if we have already been here
	    // and call _non_existent operation as a result of calling
	    // get_target_credentials(target)
	    CORBA::String_var operation = info->operation();
	    CORBA::Boolean non_existent_call = FALSE;
	    string call_key = "";
	    if (strcmp(operation.in(), "_non_existent") == 0) {
		// do we already call ::get_target_credentials
		// and so _non_existent operation?
		CORBA::String_var ref = orb->object_to_string(target);
		call_key = ref.in();
		CallSet::iterator iter = non_existent_calls_.find(call_key);
		if (iter != non_existent_calls_.end()) {
		    // recursion detected, we need to escape from it
		    return;
		}
		// no recursion, we need to add key to the set
		non_existent_calls_.insert(call_key);
		non_existent_call = TRUE;
	    }
	    CORBA::Object_var target = info->target();
	    TransportSecurity::TargetCredentials_var ts_target_creds
		= ts_secman->get_target_credentials(target);
	    if (non_existent_call) {
		CallSet::iterator iter = non_existent_calls_.find(call_key);
		assert(iter != non_existent_calls_.end());
		non_existent_calls_.erase(iter);
	    }
	    assert(!CORBA::is_nil(ts_target_creds));
	    SL3PM::Principal* target_principal
		= ts_target_creds->target_principal();
	    SL3PM::StatementList_var target_supporting_statements
		= ts_target_creds->target_supporting_statements();
	    CORBA::Boolean confidentiality = ts_target_creds->confidentiality();
	    CORBA::Boolean integrity = ts_target_creds->integrity();
	    CORBA::Boolean result = decider->is_trusted
		(target_principal,
		 target_supporting_statements,
		 confidentiality,
		 integrity,
		 SL3CM::CD_Default);
	    if (!result) {
		mico_throw(CORBA::NO_PERMISSION(70001, CORBA::COMPLETED_NO));
	    }
	}
    }
    ATLAS::AuthTokenData_var authorization_token = NULL;
    AuthorizationToken_var auth_tok = NULL;
    CORBA::Boolean use_authorization_token = FALSE;
    CORBA::Boolean delegate_authorization_token = FALSE;
    if (mech.sas_context_mech.privilege_authorities.length() > 0) {
	for (CORBA::ULong i = 0;
	     i < mech.sas_context_mech.privilege_authorities.length();
	     i++) {
	    if (mech.sas_context_mech.privilege_authorities[i].syntax
		== ATLAS::SCS_ATLAS) {
		if (MICO::Logger::IsLogged(MICO::Logger::Security))
		    MICO::Logger::Stream(MICO::Logger::Security)
			<< "CSS: ATLAS reference found..." << endl;
		if (this->supports_at_delegation()) {
		    // we will look if there is any current AT setuped in TSS
		    TSS_impl* tss_impl = dynamic_cast<CSIv2::TSS_impl*>(sec_manager_->tss());
		    assert(tss_impl != NULL);
		    auth_tok = tss_impl->current_at();
		    if (auth_tok->length() > 0) {
			if (MICO::Logger::IsLogged(MICO::Logger::Security))
			    MICO::Logger::Stream(MICO::Logger::Security)
				<< "CSS: Found current AT in TSS => delegate it" << endl;
			delegate_authorization_token = TRUE;
			break;
		    }
		}
		IOP::Codec_var codec = sec_manager_->codec();
		CORBA::Any* any = codec->decode_value
		    (mech.sas_context_mech.privilege_authorities[i].name,
		     ATLAS::_tc_ATLASProfile);
		CORBA::Any_var any_deleter = any;
		if (any != NULL) {
		    ATLAS::ATLASProfile prof;
		    CORBA::Boolean result;
		    result = ((*any) >>= prof);
		    assert(result);
		    string key = "";
		    if (prof.the_cache_id.length() > 0) {
			for (CORBA::ULong i = 0;
			     i < prof.the_cache_id.length();
			     i++) {
			    key += prof.the_cache_id[i];
			}
		    }
		    CORBA::ULong dis = prof.the_locator._d();
		    if (dis == ATLAS::ATLASObject) {
			ATLAS::AuthTokenDispenser_var dispenser
			    = ATLAS::AuthTokenDispenser::_duplicate
			    (prof.the_locator.the_dispenser());
			assert(!CORBA::is_nil(dispenser));
			if (key == "") {
			    // cache id not defined => we will use locator
			    // reference as a key
			    assert(!CORBA::is_nil(orb));
			    CORBA::String_var tmp = orb->object_to_string
				(dispenser);
			    key = tmp.in();
			}
			if (auth_token_map_.count(key) > 0) {
			    if (MICO::Logger::IsLogged(MICO::Logger::Security))
				MICO::Logger::Stream(MICO::Logger::Security)
				    << "CSS: obtain auth token from token cache" << endl;
			    authorization_token = auth_token_map_[key];
			}
			else {
			    if (MICO::Logger::IsLogged(MICO::Logger::Security))
				MICO::Logger::Stream(MICO::Logger::Security)
				    << "CSS: call ATLAS" << endl;
			    authorization_token = dispenser->get_my_authorization_token();
			    if (MICO::Logger::IsLogged(MICO::Logger::Security))
				MICO::Logger::Stream(MICO::Logger::Security)
				    << "CSS: update token cache" << endl;
			    auth_token_map_[key] = authorization_token;
			}
			use_authorization_token = TRUE;
			if (MICO::Logger::IsLogged(MICO::Logger::Security))
			    MICO::Logger::Stream(MICO::Logger::Security)
				<< "CSS: authorization token obtained" << endl;
		    }
		    else {
			// unsupported ATLAS locator type
			assert(0);
		    }
		}
	    }
	}
    }
#endif // USE_SL3
    CSI::GSS_NT_ExportedName target_name;
    target_name.length(0);
    target_name = mech.as_context_mech.target_name;
    // EstablishContext message
    CSI::EstablishContext msg;
    msg.client_context_id = 0;
    msg.authorization_token = 0;
#ifdef USE_SL3
    if (use_authorization_token)
	msg.authorization_token = authorization_token->auth_token;
    if (delegate_authorization_token)
	msg.authorization_token = auth_tok;
#endif // USE_SL3
    // auth layer checking
    CSI::GSSToken* token = NULL;
    CORBA::Boolean auth_mech_matched = FALSE;
    // we are supporting GSSUPMechOID as naming mech for auth layer
    CORBA::String_var mech_oid = ASN1::Codec::decode_oid
	(mech.as_context_mech.client_authentication_mech);
    if (strcmp(mech_oid.in(), GSSUP::GSSUPMechOID) == 0)
	auth_mech_matched = TRUE;
    // checking what tss auth support/require
    CORBA::UShort tss_auth = 0;
    if (mech.as_context_mech.target_supports >= 64) {
	// it supports EstablishTrustInClient
	tss_auth++;
    }
    if (mech.as_context_mech.target_requires >= 64) {
	// it requires EstablishTrustInClient
	tss_auth++;
    }
    // checking if client meets server needs
    if ((tss_auth - this->auth_layer() == 2)
	||((tss_auth == 2) && (!auth_mech_matched))) {
	// no because client doesn't support auth
	// and server requires it
	// or tss requires auth but naming mechanisms do not
	// matched
	CORBA::NO_PERMISSION ex(210301, CORBA::COMPLETED_NO);
	mico_throw(ex);
    }
    CORBA::Object_var obj = info->target();
    CORBA::String_var name;
    token = sec_manager_->get_gss_init_token(target_name, obj, name);
#ifdef USE_SL3
    NamesHolder nholder;
    if (use_authorization_token || delegate_authorization_token) {
	nholder.authorization_token_ = msg.authorization_token;
    }
    else {
	nholder.authorization_token_.length(0);
    }
    if (token != NULL) {
	string s1 = "";
	if (name.in() != NULL) {
	    // -ORBSL3 is on
	    s1 = name.in();
	}
	wstring ws1 = str2wstr(s1);
	nholder.auth_name_.the_type = (const char*)SL3PM::NT_StringName;
	nholder.auth_name_.the_name.length(1);
	nholder.auth_name_.the_name[0] = CORBA::wstring_dup(ws1.c_str());
	nholder.authenticated_ = TRUE;
    }
    else {
	nholder.authenticated_ = FALSE;
    }
#endif // USE_SL3
    if (!token && this->auth_layer() > 0) {
	// CSS supports auth layer but user forgot
	// to suply user name on command line
	cerr << endl
	     << "CSIv2 ERROR: please supply client user name/passwd"
	     << " or disable CSS auth layer" << endl
	     << "             by using appropriate"
	     <<"  command-line parameter." << endl << endl;
	assert(0);
    }
    
    // checking attr layer
    CSI::GSS_NT_ExportedName* id = NULL;

    //int distinguished_name = mech.sas_context_mech.supported_identity_types/8;
    int r1 = mech.sas_context_mech.supported_identity_types%8;
    //int x509_certchain = r1/4;
    int r2 = r1%4;
    int principal_name = r2/2;
    //int r3 = r2%2;
    //int anonymous = r3/1;

    // naming mech.
    CORBA::Boolean attr_mech_matched = FALSE;
    CORBA::ULong i;
    for (i=0;
	 i<mech.sas_context_mech.supported_naming_mechanisms.length();
	 i++) {
	CORBA::String_var sas_mech_name = ASN1::Codec::decode_oid
	    (mech.sas_context_mech.supported_naming_mechanisms[i]);
	if (strcmp(sas_mech_name.in(), GSSUP::GSSUPMechOID) == 0) {
	    // we are supporting only GSSUPMechOID at the moment
	    attr_mech_matched = TRUE;
	}
    }
    CORBA::UShort tss_attr = 0;
    // checking what TSS attr supports/requires
    if (mech.sas_context_mech.target_supports >= 1024) {
	// it supports IdentityAssertion
	tss_attr++;
    }
    if (mech.sas_context_mech.target_requires >= 1024) {
	// it requires IdentityAssertion
	tss_attr++;
    }
    // checking if client meets server needs
    if ((tss_attr - this->attr_layer() == 2)
	||((tss_attr == 2) && (!attr_mech_matched))
	||(principal_name == 0)) {
	// no because client doesn't support attr
	// and server requires it
	// or tss requires attr but naming mechanisms do not
	// matched
	// or tss doesn't support ITTPrincipalName identity type
	CORBA::NO_PERMISSION ex(210302, CORBA::COMPLETED_NO);
	mico_throw(ex);
    }
    CORBA::String_var identity;
    // kcg: hack
    id = sec_manager_->client_identity_token(obj, identity);
#ifndef USE_SL3
    // for SL3 we wouldn't like to suply additional
    // -ORBCSSNoAttr option
    //id = sec_manager_->client_identity_token();
    if (!id && this->attr_layer() > 0) {
	// CSS supports attr layer but user either 
	// forgot to suply user identity on command line
	// or identity can not be obtained from transport
	// layer
	cerr << endl
	     << "CSIv2 ERROR: please supply user identity or use"
	     << " TLS transport layer with identity" << endl
	     << "             or disable CSS attr layer by using appropriate"
	     << " command-line parameter." << endl << endl;
	assert(0);
    }
#endif // USE_SL3

    // auth layer
    if (token != NULL && this->auth_layer() > 0 && tss_auth > 0) {
	// TSS & CSS supports auth + token != NULL
	msg.client_authentication_token = (*token);
    }
    else {
	msg.client_authentication_token = 0;
    }
    // attr layer
#ifdef USE_SL3
    if (id != NULL) {
	string s1 = "";
	if (identity.in() != NULL) {
	    // -ORBSL3 is on
	    s1 = identity.in();
	    nholder.identity_used_ = TRUE;
	}
	wstring ws1 = str2wstr(s1);
	nholder.identity_name_.the_type = (const char*)SL3PM::NT_StringName;
	nholder.identity_name_.the_name.length(1);
	nholder.identity_name_.the_name[0] = CORBA::wstring_dup(ws1.c_str());
#else // USE_SL3
    if (id != NULL && this->attr_layer() > 0 && tss_attr > 0) {
#endif // USE_SL3
	// TSS & CSS supports attr + id != NULL
	CSI::IdentityToken id_tok;
	id_tok.principal_name(*id);
	msg.identity_token = id_tok;
    }
    else {
	CSI::IdentityToken id_tok;
	id_tok.absent(TRUE);
	msg.identity_token = id_tok;
    }
#ifdef USE_SL3
    names_map_[info->request_id()] = nholder;
#endif // USE_SL3
    CSI::SASContextBody body;
    body.establish_msg(msg);
    CORBA::Any a;
    IOP::ServiceContext service_context;
    service_context.context_id = IOP::SecurityAttributeService;
    a <<= body;
    IOP::Codec_ptr codec = sec_manager_->codec();
#ifdef USE_ENCODE_VALUE
    CORBA::OctetSeq* data = codec->encode_value(a);
#else
    CORBA::OctetSeq* data = codec->encode(a);
#endif
    service_context.context_data.length(data->length());
    for (i=0; i<data->length(); i++) {
	service_context.context_data[i] = (*data)[i];
    }
    CORBA::release(codec);
    info->add_request_service_context(service_context, FALSE);
    if (id != NULL)
	delete id;
    delete token;
    delete data;
}

void
CSIv2::CSS_impl::send_request(PortableInterceptor::ClientRequestInfo_ptr info)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "CSS_impl::send_request" << endl;
    CSIIOP::CompoundSecMechList list;
    list.mechanism_list.length(0);
    try {
	IOP::TaggedComponent* c = info->get_effective_component
	    (CSIIOP::TAG_CSI_SEC_MECH_LIST);
//  	CORBA::Any t_any;
//  	t_any <<= list;
//  	CORBA::TypeCode_ptr tc = t_any.type();
//  	IOP::Codec_ptr codec = sec_manager_->codec();
//  	CORBA::Any* any = codec->decode_value(c->component_data, tc);
//  	(*any) >>= list;
	CORBA::Buffer* buf = new CORBA::Buffer;
	for (CORBA::ULong i=0; i<c->component_data.length(); i++)
	    buf->put(c->component_data[i]);
	CORBA::DataDecoder* dec = new MICO::CDRDecoder(buf);
	_marshaller_CSIIOP_CompoundSecMechList->demarshal(*dec, &list);
	delete c;
	delete dec;
    } catch (CORBA::BAD_PARAM& ex) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "catch CORBA::BAD_PARAM" << endl;
	}
    }
    this->write_sas_context(info, list);
}

void
CSIv2::CSS_impl::receive_reply(PortableInterceptor::ClientRequestInfo_ptr info)
{
    //cerr << "CCS_impl::receive_reply to " << info->operation() << endl;
    assert(!CORBA::is_nil(info));
    IOP::ServiceContext_var sas_context = info->get_request_service_context
	(IOP::SecurityAttributeService);
    assert(sas_context);
    IOP::Codec_ptr codec = sec_manager_->codec();
#ifdef USE_ENCODE_VALUE
    CORBA::Any* a1 = codec->decode_value
	(sas_context->context_data, sas_body_tc_);
#else // USE_ENCODE_VALUE
    CORBA::Any* a1 = codec->decode(sas_context->context_data);
#endif // USE_ENCODE_VALUE
#ifdef USE_SL3
    NamesHolder nholder;
    if (names_map_.count(info->request_id())) {
	nholder = names_map_[info->request_id()];
	names_map_.erase(info->request_id());
    }
    else {
	assert(0);
    }
#endif // USE_SL3
    CSI::SASContextBody rec_body;
    (*a1) >>= rec_body;
    delete a1;
    if (rec_body._d() == CSI::MTEstablishContext) {
	assert(0);
    } else if (rec_body._d() == CSI::MTMessageInContext) {
	assert(0);
    } else if (rec_body._d() == CSI::MTContextError) {
	assert(0);
    } else if (rec_body._d() == CSI::MTCompleteEstablishContext) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "CSS_impl: received complete establish context msg!" << endl;
#ifdef USE_SL3
	CORBA::Object_var target = info->target();
	CORBA::String_var operation = info->operation();
  	this->create_csi_creds
	    (nholder.auth_name_, nholder.authenticated_, nholder.identity_name_,
	     nholder.identity_used_, nholder.authorization_token_,
	     target, operation);
#endif // USE_SL3
    }
}

void
CSIv2::CSS_impl::receive_exception
(PortableInterceptor::ClientRequestInfo_ptr info)
{
    //cerr << "CCS_impl::receive_exception to " << info->operation() << endl;
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "CSS_impl::receive_exception" << endl;
    assert(!CORBA::is_nil(info));
    IOP::ServiceContext_var sas_context = info->get_request_service_context
	(IOP::SecurityAttributeService);
    assert(sas_context);
    IOP::Codec_ptr codec = sec_manager_->codec();
#ifdef USE_ENCODE_VALUE
    CORBA::Any* a1 = codec->decode_value
	(sas_context->context_data, sas_body_tc_);
#else // USE_ENCODE_VALUE
    CORBA::Any* a1 = codec->decode(sas_context->context_data);
#endif // USE_ENCODE_VALUE
#ifdef USE_SL3
    NamesHolder nholder;
    if (names_map_.count(info->request_id())) {
	nholder = names_map_[info->request_id()];
	names_map_.erase(info->request_id());
    }
    else {
	assert(0);
    }
#endif // USE_SL3
    CSI::SASContextBody rec_body;
    (*a1) >>= rec_body;
    delete a1;
    if (rec_body._d() == CSI::MTEstablishContext) {
	// it's ok to receive system exception with establish context msg
	// assert(0);
    } else if (rec_body._d() == CSI::MTMessageInContext) {
	assert(0);
    } else if (rec_body._d() == CSI::MTContextError) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "CSS_impl: received context error msg!" << endl
		<< "client_context_id: "
#ifdef _MSC_VER
		<< (CORBA::Long)rec_body.error_msg().client_context_id << endl
#else // _MSC_VER
		<< rec_body.error_msg().client_context_id << endl
#endif // _MSC_VER
		<< "major_status: "
		<< rec_body.error_msg().major_status << endl
		<< "minor_status: "
		<< rec_body.error_msg().minor_status << endl;
	if (rec_body.error_msg().error_token.length() > 0) {
	    CORBA::Any* any;
	    GSSUP::ErrorToken et;
	    CORBA::Any ta;
	    ta <<= et;
	    CORBA::TypeCode_ptr et_tc = ta.type();
	    IOP::Codec_ptr codec = sec_manager_->codec();
	    any = codec->decode_value(rec_body.error_msg().error_token, et_tc);
	    (*any) >>= et;
	    CORBA::release(codec);
	    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
		if (et.error_code == GSSUP::GSS_UP_S_G_UNSPECIFIED)
		    MICO::Logger::Stream(MICO::Logger::Security)
			<< "GSS_UP_S_G_UNSPECIFIED" << endl;
		if (et.error_code == GSSUP::GSS_UP_S_G_NOUSER)
		    MICO::Logger::Stream(MICO::Logger::Security)
			<< "GSS_UP_S_G_NOUSER" << endl;
		if (et.error_code == GSSUP::GSS_UP_S_G_BAD_PASSWORD)
		    MICO::Logger::Stream(MICO::Logger::Security)
			<< "GSS_UP_S_G_BAD_PASSWORD" << endl;
		if (et.error_code == GSSUP::GSS_UP_S_G_BAD_TARGET)
		    MICO::Logger::Stream(MICO::Logger::Security)
			<< "GSS_UP_S_G_BAD_TARGET" << endl;
	    }
	}
#ifdef USE_SL3
	CORBA::Object_var target = info->target();
	CORBA::String_var operation = info->operation();
	this->create_csi_creds
	    (nholder.auth_name_, false, nholder.identity_name_,
	     nholder.identity_used_, nholder.authorization_token_,
	     target, operation);
#endif // USE_SL3
    } else if (rec_body._d() == CSI::MTCompleteEstablishContext) {
	assert(0);
    }
}

void
CSIv2::CSS_impl::receive_other(PortableInterceptor::ClientRequestInfo_ptr info)
{
}

#ifdef USE_SL3
CSIv2::CSS_impl::NamesHolder::NamesHolder()
    : authenticated_(FALSE), identity_used_(FALSE)
{
}

CSIv2::CSS_impl::NamesHolder::NamesHolder(const NamesHolder& holder)
    : auth_name_(holder.auth_name_), authenticated_(holder.authenticated_), identity_name_(holder.identity_name_), identity_used_(holder.identity_used_), authorization_token_(holder.authorization_token_)
{
    //cerr << "NamesHolder copy-ctor" << endl;
}

CSIv2::CSS_impl::NamesHolder&
CSIv2::CSS_impl::NamesHolder::operator=(const NamesHolder& holder)
{
    //cerr << "NamesHolder =" << endl;
    auth_name_ = holder.auth_name_;
    authenticated_ = holder.authenticated_;
    identity_name_ = holder.identity_name_;
    identity_used_ = holder.identity_used_;
    authorization_token_ = holder.authorization_token_;
    return *this;
}

void
CSIv2::CSS_impl::create_csi_creds
(const SL3PM::PrincipalName& auth_name,
 CORBA::Boolean authenticated,
 const SL3PM::PrincipalName& identity_name,
 CORBA::Boolean identity_supplied,
 const CSI::AuthorizationToken& authorization_token,
 CORBA::Object_ptr target,
 const char* operation)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	if (authenticated)
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3::CSS_impl::create_csi_creds(true, " << target << ")" << endl;
	else
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3::CSS_impl::create_csi_creds(false, " << target << ")" << endl;
    }
    string key = "";
    if (authenticated) {
	wstring wid = auth_name.the_name[0].in();
	key = wstr2str(wid);
    }
    if (identity_supplied) {
	wstring wid = identity_name.the_name[0].in();
	key += "_" + wstr2str(wid);
    }
    //cerr << "CSS_impl::create_csi_creds: map key: " << key << endl;
    CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
    assert(!CORBA::is_nil(orb));
    CORBA::Object_var secobj = orb->resolve_initial_references
	("TransportSecurity::SecurityManager");
    TransportSecurity::SecurityManager_var secman
	= TransportSecurity::SecurityManager::_narrow(secobj);
    assert(!CORBA::is_nil(secman));
    MICOSL3_TransportSecurity::SecurityManager_impl* secman_impl
	= dynamic_cast<MICOSL3_TransportSecurity::SecurityManager_impl*>(secman.in());
    assert(secman_impl != NULL);
    if (secman_impl->security_enabled()) {
	// SL3 is enabled
	CORBA::Boolean non_existent_call = FALSE;
	string call_key = "";
	if (strcmp(operation, "_non_existent") == 0) {
	    // do we already call ::get_target_credentials
	    // and so _non_existent operation?
	    CORBA::String_var ref = orb->object_to_string(target);
	    call_key = ref.in();
	    CallSet::iterator iter = non_existent_calls_.find(call_key);
	    if (iter != non_existent_calls_.end()) {
		// recursion detected, we need to escape from it
		return;
	    }
	    // no recursion, we need to add key to the set
	    non_existent_calls_.insert(call_key);
	    non_existent_call = TRUE;
	}
	TransportSecurity::TargetCredentials_var t_creds
	    = secman->get_target_credentials(target);
	if (non_existent_call) {
	    CallSet::iterator iter = non_existent_calls_.find(call_key);
	    assert(iter != non_existent_calls_.end());
	    non_existent_calls_.erase(iter);
	}
	MICOSL3_SecurityLevel3::TargetCredsHolder* holder
	    = dynamic_cast<MICOSL3_SecurityLevel3::TargetCredsHolder*>(t_creds.in());
	assert(holder != NULL);
	SecurityLevel3::TargetCredentials_var test = holder->csi_creds(key);
	if (CORBA::is_nil(test)) {
	    // we have to create CSI creds now
	    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
		MICOMT::AutoDebugLock lock;
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "SL3CSIv2: need to create CSI creds now" << endl;
	    }
	    SecurityLevel3::OwnCredentials_var creds
		= MICOSL3Utils::CredsRetriever::get_client_side_own_credentials
		(orb, target, TRUE);
	    assert(!CORBA::is_nil(creds));
	    SecurityLevel3::CredsInitiator_var initiator = creds->creds_initiator();
	    assert(!CORBA::is_nil(initiator));
	    MICOSL3_SL3CSI::CSICredsInitiator* initiator_impl
		= dynamic_cast<MICOSL3_SL3CSI::CSICredsInitiator*>(initiator.in());
	    assert(initiator_impl != NULL);
	    Principal_var creds_princ = initiator->the_principal();
	    TokenProcessor_var token_processor = TokenProcessor::_nil();
	    SL3AQArgs::TokenProcessorSeq_var tpseq = initiator_impl->tpseq();
	    if (authorization_token.length() > 0
		&& tpseq->length() > 0) {
		//cerr << "searching for suitable token processor..." << endl;
		// we need to find suitable token processor for the supplied
		// authorized token (we just look at the first authorization element
		for (CORBA::ULong i = 0; i < tpseq->length(); i++) {
		    if (tpseq[i]->accept_token_type()
			== authorization_token[0].the_type) {
			//cerr << "token processor found!" << endl;
			token_processor = tpseq[i];
			break;
		    }
		}
		// we have tpseq & autorization token => we need to have
		// suitable token processor
		assert(!CORBA::is_nil(token_processor));
	    }
	    // following (commented) code is broken because of IDL compiler bug
	    // which generates _strange_ _copy_value operation for ProxyPrincipal
	    // in securitylevel3.cc
//  		    SecurityLevel3::ProxyPrincipal* principal = SecurityLevel3::ProxyPrincipal::_downcast
//  			(creds_princ->_copy_value());
	    AuthorizationInfo* auth_info = NULL;
	    if (!CORBA::is_nil(token_processor)) {
		// we have suitable token processor
		Principal_var transport_principal
		    = t_creds->client_principal();
		StatementList_var transport_statements
		    = t_creds->client_supporting_statements();
		ResourceNameList_var transport_resources
		    = t_creds->client_restricted_resources();
		SimplePrincipal* client_auth_principal = NULL;
		IdentityStatement* client_auth_statement = NULL;
		if (creds_princ->the_type() == PT_Proxy) {
		    ProxyPrincipal* pp = ProxyPrincipal::_downcast(creds_princ);
		    client_auth_principal = SimplePrincipal::_downcast
			(pp->speaks_for());
		}
		if (creds_princ->the_type() == PT_Quoting) {
		    QuotingPrincipal* quoting = QuotingPrincipal::_downcast
			(creds_princ);
		    Principal* speaking = quoting->speaking();
		    if (speaking->the_type() == PT_Proxy) {
			ProxyPrincipal* proxy = ProxyPrincipal::_downcast
			    (quoting->speaking());
			client_auth_principal = SimplePrincipal::_downcast
			    (proxy->speaks_for());
		    }
		}
		StatementList_var slist = initiator->supporting_statements();
		for (CORBA::ULong i = 0; i < slist->length(); i++) {
		    if (slist[i]->the_layer() == SL_CSIClientAuth) {
			client_auth_statement = IdentityStatement::_downcast(slist[i]);
			break;
		    }
		}
		Principal* identity_assert_principal = NULL;
		StatementList identity_assert_statements;
		identity_assert_statements.length(0);
		auth_info = token_processor->accept_token
		    (transport_principal,
		     transport_statements,
		     transport_resources,
		     client_auth_principal,
		     client_auth_statement,
		     identity_assert_principal,
		     identity_assert_statements,
		     authorization_token);
		
	    }
	    Principal* client_principal = NULL;
	    if (creds_princ->the_type() == PT_Proxy) {
		// proxy principal
		ProxyPrincipal* orig_princ
		    = ProxyPrincipal::_downcast(creds_princ);
		assert(orig_princ != NULL);
		client_principal = new MICOSL3_SL3PM::ProxyPrincipal_impl
		    (Principal::_downcast(orig_princ->speaking()->_copy_value()),
		     Principal::_downcast(orig_princ->speaks_for()->_copy_value()));
	    }
	    else if (creds_princ->the_type() == PT_Quoting) {
		// quoting principal
		QuotingPrincipal* orig_princ
		    = QuotingPrincipal::_downcast(creds_princ);
		assert(orig_princ != NULL);
		client_principal = new MICOSL3_SL3PM::QuotingPrincipal_impl
		    // kcg: TODO: this code is ok, but MICO OBV is broken for
		    // ProxyPrincipal::_copy_value operation
		    // so before fix we just use orig values - vide PR#117
//  			    (Principal::_downcast(orig_princ->speaking()->_copy_value()),
//  			     Principal::_downcast(orig_princ->quotes_for()->_copy_value()));
		    (orig_princ->speaking(), orig_princ->quotes_for());
	    }
	    else {
		// unknown principal type
		// only Proxy || Quoting might be here
		assert(0);
	    }
	    assert(client_principal != NULL);
	    Principal_var t_princ = t_creds->client_principal();
//  		    PrinAttributeList attrs = t_princ->environmental_attributes();
//  		    client_principal->speaking()->environmental_attributes(attrs);
//  		    client_principal->environmental_attributes(attrs);
	    MICOSL3_SecurityLevel3::TargetCredentials_impl* target_creds
		= new MICOSL3_SecurityLevel3::TargetCredentials_impl;
	    SecurityLevel3::TargetCredentials_var target_creds_cleanup
		= target_creds;
	    string id = creds->creds_id();
	    id += "_TargetCredentials:";
	    id += xdec(S_target_creds_index_);
	    string tid = "CSI_TargetCredentials:";
	    tid += xdec(S_target_creds_index_);
	    S_target_creds_index_++;
	    target_creds->creds_id(id.c_str());
	    target_creds->creds_type(CT_TargetCredentials);
	    target_creds->creds_usage(CU_None);
	    target_creds->creds_state(CS_Valid);
	    target_creds->context_id(tid.c_str());
	    if (auth_info != NULL) {
		target_creds->client_principal(auth_info->the_principal);
	    }
	    else {
		target_creds->client_principal(client_principal);
	    }
	    StatementList_var orig_stats = initiator->supporting_statements();
	    StatementList stats;
	    stats.length(orig_stats->length());
	    for (CORBA::ULong i = 0; i < orig_stats->length(); i++) {
		//cerr << "i:" << i << endl;
		stats[i] = orig_stats[i];
	    }
	    PrincipalIdentityStatement* id_stat
		= PrincipalIdentityStatement::_downcast(stats[0]);
	    assert(id_stat != NULL);
//		    Principal* pp = id_stat->the_principal();
//  		    pp->environmental_attributes(client_principal->environmental_attributes());
	    if (auth_info != NULL) {
		target_creds->client_supporting_statements(auth_info->the_statements);
	    }
	    else {
		target_creds->client_supporting_statements(stats);
	    }
	    ResourceNameList res;
	    res.length(0);
	    target_creds->client_restricted_resources(res);
	    target_creds->target_principal
		(Principal::_downcast(t_creds->target_principal()->_copy_value()));
	    StatementList_var transp_target_stats = t_creds->target_supporting_statements();
	    target_creds->target_supporting_statements(transp_target_stats.in());
	    PrinAttributeList_var env_attrs = t_creds->environmental_attributes();
	    target_creds->environmental_attributes(env_attrs);
	    target_creds->parent_credentials(creds);
	    target_creds->client_authentication(authenticated);
	    // kcg: TODO - local trust in server decider needs to be taken
	    // into account here
	    target_creds->target_authentication(t_creds->target_authentication());
	    target_creds->confidentiality(t_creds->confidentiality());
	    target_creds->integrity(t_creds->confidentiality());
	    target_creds->target_embodied(t_creds->target_embodied());
	    target_creds->target_endorsed(t_creds->target_endorsed());
	    holder->csi_creds(key, target_creds);
	    target_creds->notify_creation();
	    MICOSL3_SecurityLevel3::OwnCredentials_impl* owncreds_impl
		= dynamic_cast<MICOSL3_SecurityLevel3::OwnCredentials_impl*>
		(creds.in());
	    assert(owncreds_impl != NULL);
	    TransportSecurity::InitiatingContext_var init_ctx
		= TransportSecurity::InitiatingContext::_narrow(t_creds);
	    assert(!CORBA::is_nil(init_ctx));
	    owncreds_impl->add_observer(init_ctx);
	}
    }
}
#endif // USE_SL3

CSIv2::TSS_impl::TSS_impl()
    : sec_manager_(CSIv2::SecurityManager::_nil())
{
    CORBA::Any any;
    CSI::SASContextBody body;
    any <<= body;
    sas_body_tc_ = CORBA::TypeCode::_duplicate(any.type());
#ifdef USE_SL3
#ifdef HAVE_THREADS
    MICOMT::Thread::create_key(current_at_key_, NULL);
#endif // HAVE_THREADS
#endif // USE_SL3
}

void
CSIv2::TSS_impl::security_manager(SecurityManager_ptr manager)
{
    if (!CORBA::is_nil(sec_manager_)) {
	CORBA::release(sec_manager_);
	sec_manager_ = SecurityManager::_nil();
    }
    sec_manager_ = SecurityManager::_duplicate(manager);
}

CSIv2::SecurityManager_ptr
CSIv2::TSS_impl::security_manager()
{
    return sec_manager_;
}

IOP::ServiceContext*
CSIv2::TSS_impl::accept_context
(PortableInterceptor::ServerRequestInfo_ptr info,
 CORBA::Boolean_out throw_exc)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "TSS_impl::accept_context" << endl;
    IOP::ServiceContext_var sas_context = info->get_request_service_context
	(IOP::SecurityAttributeService);
    assert(sas_context);
    throw_exc = FALSE;
    //CORBA::OctetSeq data = sas_context->context_data;
    IOP::Codec_ptr codec = sec_manager_->codec();
    CSI::SASContextBody rec_body;
#ifdef USE_ENCODE_VALUE
    CORBA::Any* a1 = codec->decode_value
	(sas_context->context_data, sas_body_tc_);
#else // USE_ENCODE_VALUE
    CORBA::Any* a1 = codec->decode(sas_context->context_data);
#endif // USE_ENCODE_VALUE
    (*a1) >>= rec_body;
    delete a1;
    if (rec_body._d() == CSI::MTEstablishContext) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "TSS_impl: received EstablishContext msg" << endl;
	CSI::CompleteEstablishContext* cec = NULL;
	try {
	    cec = this->establish_context(rec_body.establish_msg());
	    // context established
	    CSI::SASContextBody reply_body;
	    reply_body.complete_msg(*cec);
	    delete cec;
	    CORBA::Any a2;
	    a2 <<= reply_body;
	    IOP::Codec_ptr codec = sec_manager_->codec();
#ifdef USE_ENCODE_VALUE
	    CORBA::OctetSeq* data2 = codec->encode_value(a2);
#else // USE_ENCODE_VALUE
	    CORBA::OctetSeq* data2 = codec->encode(a2);
#endif // USE_ENCODE_VALUE
	    IOP::ServiceContext* sc = new IOP::ServiceContext;
	    sc->context_id = IOP::SecurityAttributeService;
	    sc->context_data = (*data2);
	    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "TSS_impl: reply SAS msg data" << endl;
		debug(&(MICO::Logger::Stream(MICO::Logger::Security)), data2);
	    }
	    delete data2;
	    CORBA::release(codec);
	    return sc;
	} catch (CSIv2::GSSAuthError_catch& ex) {
	    // context error
	    if (MICO::Logger::IsLogged(MICO::Logger::Security))
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "context error" << endl;
	    throw_exc = TRUE;
	    CSI::ContextError ctxerr;
	    ctxerr.client_context_id = 0;
	    ctxerr.major_status = 1;
	    ctxerr.minor_status = 1;
	    CORBA::OctetSeq_var e_tok = sec_manager_->error_token(ex.reason);
	    ctxerr.error_token = (*e_tok);
	    CSI::SASContextBody reply_body;
	    reply_body.error_msg(ctxerr);
	    CORBA::Any a3;
	    a3 <<= reply_body;
	    IOP::Codec_ptr codec = sec_manager_->codec();
#ifdef USE_ENCODE_VALUE
	    CORBA::OctetSeq* data3 = codec->encode_value(a3);
#else // USE_ENCODE_VALUE
	    CORBA::OctetSeq* data3 = codec->encode(a3);
#endif
	    IOP::ServiceContext* sc = new IOP::ServiceContext;
	    sc->context_id = IOP::SecurityAttributeService;
	    sc->context_data = (*data3);
	    delete data3;
	    CORBA::release(codec);
	    return sc;
	} catch (CSIv2::TrustIdentityError_catch& ex) {
	    // identity error
	    if (MICO::Logger::IsLogged(MICO::Logger::Security))
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "identity error" << endl;
	    throw_exc = TRUE;
	    // invalid evidence
	    CSI::ContextError ctxerr;
	    ctxerr.client_context_id = 0;
	    ctxerr.major_status = 1;
	    ctxerr.minor_status = 1;
	    CSI::SASContextBody reply_body;
	    reply_body.error_msg(ctxerr);
	    CORBA::Any a;
	    a <<= reply_body;
	    IOP::Codec_ptr codec = sec_manager_->codec();
#ifdef USE_ENCODE_VALUE
	    CORBA::OctetSeq* data = codec->encode_value(a);
#else // USE_ENCODE_VALUE
	    CORBA::OctetSeq* data = codec->encode(a);
#endif
	    IOP::ServiceContext* sc = new IOP::ServiceContext;
	    sc->context_id = IOP::SecurityAttributeService;
	    sc->context_data = (*data);
	    delete data;
	    CORBA::release(codec);
	    return sc;
	} catch (CSIv2::InvalidMechanism_catch& ex) {
	    // invalid mechanism
	    if (MICO::Logger::IsLogged(MICO::Logger::Security))
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "invalid mechanism" << endl;
	    throw_exc = TRUE;
	    // invalid mechanism
	    CSI::ContextError ctxerr;
	    ctxerr.client_context_id = 0;
	    ctxerr.major_status = 2;
	    ctxerr.minor_status = 1;
	    CSI::SASContextBody reply_body;
	    reply_body.error_msg(ctxerr);
	    CORBA::Any a;
	    a <<= reply_body;
	    IOP::Codec_ptr codec = sec_manager_->codec();
#ifdef USE_ENCODE_VALUE
	    CORBA::OctetSeq* data = codec->encode_value(a);
#else // USE_ENCODE_VALUE
	    CORBA::OctetSeq* data = codec->encode(a);
#endif
	    IOP::ServiceContext* sc = new IOP::ServiceContext;
	    sc->context_id = IOP::SecurityAttributeService;
	    sc->context_data = (*data);
	    delete data;
	    CORBA::release(codec);
	    return sc;
#ifdef USE_SL3
	} catch (SL3Authorization::InvalidEvidence_catch& ex) {
	    // invalid evidence
	    if (MICO::Logger::IsLogged(MICO::Logger::Security))
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "invalid evidence" << endl;
	    throw_exc = TRUE;
	    // invalid evidence
	    CSI::ContextError ctxerr;
	    ctxerr.client_context_id = 0;
	    ctxerr.major_status = 1;
	    ctxerr.minor_status = 1;
	    CSI::SASContextBody reply_body;
	    reply_body.error_msg(ctxerr);
	    CORBA::Any a;
	    a <<= reply_body;
	    IOP::Codec_ptr codec = sec_manager_->codec();
#ifdef USE_ENCODE_VALUE
	    CORBA::OctetSeq* data = codec->encode_value(a);
#else // USE_ENCODE_VALUE
	    CORBA::OctetSeq* data = codec->encode(a);
#endif
	    IOP::ServiceContext* sc = new IOP::ServiceContext;
	    sc->context_id = IOP::SecurityAttributeService;
	    sc->context_data = (*data);
	    delete data;
	    CORBA::release(codec);
	    return sc;
	} catch (SL3Authorization::InvalidMechanism_catch& ex) {
	    // invalid mechanism
	    if (MICO::Logger::IsLogged(MICO::Logger::Security))
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "invalid mechanism" << endl;
	    throw_exc = TRUE;
	    // invalid mechanism
	    CSI::ContextError ctxerr;
	    ctxerr.client_context_id = 0;
	    ctxerr.major_status = 2;
	    ctxerr.minor_status = 1;
	    CSI::SASContextBody reply_body;
	    reply_body.error_msg(ctxerr);
	    CORBA::Any a;
	    a <<= reply_body;
	    IOP::Codec_ptr codec = sec_manager_->codec();
#ifdef USE_ENCODE_VALUE
	    CORBA::OctetSeq* data = codec->encode_value(a);
#else // USE_ENCODE_VALUE
	    CORBA::OctetSeq* data = codec->encode(a);
#endif
	    IOP::ServiceContext* sc = new IOP::ServiceContext;
	    sc->context_id = IOP::SecurityAttributeService;
	    sc->context_data = (*data);
	    delete data;
	    CORBA::release(codec);
	    return sc;
#endif // USE_SL3
	}
    }
    else if (rec_body._d() == CSI::MTMessageInContext) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "TSS_impl: received MessageInContext msg" << endl;
	throw_exc = TRUE;
	CSI::ContextError ctxerr;
	ctxerr.client_context_id = 0;
	ctxerr.major_status = 4;
	ctxerr.minor_status = 1;
	CSI::SASContextBody reply_body;
	reply_body.error_msg(ctxerr);
	CORBA::Any a4;
	a4 <<= reply_body;
	IOP::Codec_ptr codec = sec_manager_->codec();
#ifdef USE_ENCODE_VALUE
	CORBA::OctetSeq* data4 = codec->encode_value(a4);
#else // USE_ENCODE_VALUE
	CORBA::OctetSeq* data4 = codec->encode(a4);
#endif
	IOP::ServiceContext* sc = new IOP::ServiceContext;
	sc->context_id = IOP::SecurityAttributeService;
	sc->context_data = (*data4);
	delete data4;
	CORBA::release(codec);
	return sc;
    }
    else {
	assert(0);
    }
    // never reached
    return 0;
}

CSI::CompleteEstablishContext*
CSIv2::TSS_impl::establish_context(const CSI::EstablishContext& msg)
{
    if ((msg.client_authentication_token.length() == 0
	 && this->auth_layer() == 2)
	||(msg.client_authentication_token.length() > 0
	   && this->auth_layer() == 0)) {
	// CSS send msg without using auth layer
	// && TSS requires auth layer usage
	// or CSS send msg with auth token but TSS doesn't
	// support auth layer usage
	mico_throw(CSIv2::InvalidMechanism());
    }
    if ((msg.identity_token._d() != CSI::ITTPrincipalName
	 && this->attr_layer() == 2)
	||(msg.identity_token._d() != CSI::ITTAbsent
	   && this->attr_layer() == 0)) {
	// CSS send msg w/o asserted identity but TSS requires id assertion
	// or CSS send some identity but TSS doesn't support identity assertion
	mico_throw(CSIv2::InvalidMechanism());
    }
#ifdef USE_SL3
    this->current_at(msg.authorization_token);
#endif // USE_SL3
    sec_manager_->establish_context
	(msg.client_authentication_token, msg.identity_token, msg.authorization_token);
    CSI::CompleteEstablishContext* cec = new CSI::CompleteEstablishContext;
    cec->client_context_id = msg.client_context_id;
    cec->context_stateful = FALSE;
    cec->final_context_token.length(0);
    return cec;
}

void
CSIv2::TSS_impl::accept_transport_context()
{
    CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
#ifdef USE_SL3
    CORBA::Object_var t_obj = orb->resolve_initial_references
        ("TransportSecurity::SecurityManager");
    MICOSL3_TransportSecurity::SecurityManager_impl* tsm_impl
	= dynamic_cast<MICOSL3_TransportSecurity::SecurityManager_impl*>(t_obj.in());
    assert(tsm_impl != NULL);
    if (tsm_impl->security_enabled()) {
	CORBA::Object_var obj = orb->resolve_initial_references
	    ("TransportSecurity::SecurityCurrent");
	TransportSecurity::SecurityCurrent_var current
	    = TransportSecurity::SecurityCurrent::_narrow(obj);
	assert(!CORBA::is_nil(current));
	TransportSecurity::ClientCredentials_var ts_client_creds
	    = current->client_credentials();
	SecurityLevel3::OwnCredentials_var creds
	    = MICOSL3Utils::CredsRetriever::get_server_side_own_credentials
	    (orb);
	assert(!CORBA::is_nil(creds));
	SecurityLevel3::CredsAcceptor_var acceptor = creds->creds_acceptor();
	assert(!CORBA::is_nil(acceptor));
	MICOSL3_SL3CSI::CSICredsAcceptor* acceptor_impl
	    = dynamic_cast<MICOSL3_SL3CSI::CSICredsAcceptor*>
	    (acceptor.in());
	assert(acceptor_impl != NULL);
	SL3TLS::TLSX509IdentityProcessor_var identity_processor
	    = acceptor_impl->identity_processor();
	if (!CORBA::is_nil(identity_processor)) {
	    Principal* client_princ = ts_client_creds->client_principal();
	    PrincipalName auth_name = client_princ->the_name();
	    PrincipalName identity_name;
	    AuthorizationToken token;
	    if (identity_processor->verify_identity(client_princ)) {
		// identity allowed to do a call
		SecurityManager_impl* secman_impl
		    = dynamic_cast<SecurityManager_impl*>
		    (sec_manager_);
		assert(secman_impl != NULL);
		secman_impl->create_csi_creds_from_transport
		    (auth_name, creds);
		return;
	    }
	}
	mico_throw(CORBA::NO_PERMISSION(70002, CORBA::COMPLETED_NO));
    }
#endif // USE_SL3
    CORBA::Object_var obj = orb->resolve_initial_references("PrincipalCurrent");
    CORBA::PrincipalCurrent_var p_current = CORBA::PrincipalCurrent::_narrow
	(obj);
    CORBA::Principal_var princ = p_current->get_principal();
    const char* str;
    CORBA::Any_var t_any;

    t_any = princ->get_property ("auth-method");
    t_any >>= str;
    string auth = str;
    if (auth != "ssl") {
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "TSS_impl: TLS not used, will throw NO_PERMISSION" << endl;
	mico_throw(CORBA::NO_PERMISSION());
    }
    t_any = princ->get_property ("ssl-x509-subject");
    t_any >>= str;
    CORBA::String_var user_name = str;
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "TSS_impl: accept_transport_context - user name: `"
	    << user_name << "'" << endl;
    CSIv2::DistinguishedNameList* user_list = sec_manager_->tls_user_list();
    for (CORBA::ULong i=0; i<user_list->length(); i++)
	if (user_name == (*user_list)[i])
	    return;
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "TSS_impl: accept_transport_context - name not found!" << endl;
    mico_throw(CORBA::NO_PERMISSION());
}

void
CSIv2::TSS_impl::receive_request_service_contexts
(PortableInterceptor::ServerRequestInfo_ptr info)
{
}

void
CSIv2::TSS_impl::receive_request
(PortableInterceptor::ServerRequestInfo_ptr info)
{
    CORBA::Boolean msg_with_sas_context = FALSE;
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "TSS_impl: received request, will try SAS context" << endl;
    try {
	IOP::ServiceContext_var ctx
	    = info->get_request_service_context(IOP::SecurityAttributeService);
	msg_with_sas_context = TRUE;
    } catch (CORBA::SystemException_catch& ex) {
	// the server run under CSIv2 and receive msg without SAS context.
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "TSS_impl: someone is trying to send me msg"
		<< " whithout SAS context." << endl;
    }
    if (msg_with_sas_context) {
	// msg contains SAS context message
	// we will try to enstablish contex
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "TSS_impl: received request with SAS context" << endl
		<< "received data:" << endl;
	    IOP::ServiceContext_var t = info->get_request_service_context
		(IOP::SecurityAttributeService);
	    debug(&(MICO::Logger::Stream(MICO::Logger::Security)),
		  &(t->context_data));
	}
	CORBA::Boolean throw_exc;
	IOP::ServiceContext* reply_context = this->accept_context
	    (info, throw_exc);
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "reply data:" << endl;
	    debug(&(MICO::Logger::Stream(MICO::Logger::Security)),
		  &(reply_context->context_data));
	}
	if (throw_exc) {
	    if (MICO::Logger::IsLogged(MICO::Logger::Security))
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "TSS_impl: throwing exc from the sri..." << endl;
	    info->add_reply_service_context(*reply_context, TRUE);
	    mico_throw(CORBA::NO_PERMISSION());
	}
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "TSS_impl: add context into request map" << endl;
	request_map_[info->request_id()] = (*reply_context);
	delete reply_context;
    }
    else {
	// msg doesn't contain SAS context message
	// we will try to accept context from transport layer

	// accept_transport_context throw appropriate
	// CORBA::NO_PERMISSION
	this->accept_transport_context();
    }
}

void
CSIv2::TSS_impl::send_reply(PortableInterceptor::ServerRequestInfo_ptr info)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "TSS_impl: send reply" << endl;
    if (request_map_.count(info->request_id()) > 0) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "TSS_impl: found SAS context for reply" << endl;
	RequestMapIterator i = request_map_.find(info->request_id());
	info->add_reply_service_context((*i).second, FALSE);
	request_map_.erase(i);
    }
#ifdef USE_SL3
    AuthorizationToken tok;
    tok.length(0);
    this->current_at(tok);
#endif // USE_SL3
}

void
CSIv2::TSS_impl::send_exception(PortableInterceptor::ServerRequestInfo_ptr info)
{
#ifdef USE_SL3
    AuthorizationToken tok;
    tok.length(0);
    this->current_at(tok);
#endif // USE_SL3
}

void
CSIv2::TSS_impl::send_other(PortableInterceptor::ServerRequestInfo_ptr info)
{
#ifdef USE_SL3
    AuthorizationToken tok;
    tok.length(0);
    this->current_at(tok);
#endif // USE_SL3
}

#ifdef USE_SL3
CSIv2::TSS_impl::ATHolder::ATHolder(const CSI::AuthorizationToken& tok)
    : token_(tok)
{
}

CSIv2::TSS_impl::ATHolder::ATHolder(const ATHolder& holder)
    : token_(holder.token_)
{
}

CSIv2::TSS_impl::ATHolder&
CSIv2::TSS_impl::ATHolder::operator=(const ATHolder& holder)
{
    token_ = holder.token_;
    return *this;
}

AuthorizationToken*
CSIv2::TSS_impl::ATHolder::token()
{
    return new AuthorizationToken(token_);
}

void
CSIv2::TSS_impl::ATHolder::token(const AuthorizationToken& tok)
{
    token_ = tok;
}

AuthorizationToken*
CSIv2::TSS_impl::current_at()
{
#ifdef HAVE_THREADS
    ATHolder* holder = dynamic_cast<ATHolder*>
	(static_cast<ATHolder*>(MICOMT::Thread::get_specific(current_at_key_)));
    if (holder != NULL) {
	return holder->token();
    }
    AuthorizationToken* retval = new AuthorizationToken;
    retval->length(0);
    return retval;
#else // HAVE_THREADS
    return new AuthorizationToken(current_at_);
#endif // HAVE_THREADS
}

void
CSIv2::TSS_impl::current_at(const AuthorizationToken& tok)
{
#ifdef HAVE_THREADS
    ATHolder* holder = dynamic_cast<ATHolder*>
	(static_cast<ATHolder*>(MICOMT::Thread::get_specific(current_at_key_)));
    if (holder != NULL) {
	holder->token(tok);
    }
    else {
	MICOMT::Thread::set_specific(current_at_key_, new ATHolder(tok));
    }
#else // HAVE_THREADS
    current_at_ = tok;
#endif // HAVE_THREADS
}
#endif // USE_SL3

CSIv2::SecurityManager_impl::SecurityManager_impl()
    : csiv2_(FALSE), codec_factory_(IOP::CodecFactory::_nil()),
      codec_(IOP::Codec::_nil())
{
    tss_ = new TSS_impl;
    tss_->security_manager(this);
    css_ = new CSS_impl;
    css_->security_manager(this);
    GSSUP::InitialContextToken tok;
    CORBA::Any any;
    any <<= tok;
    init_token_tc_ = CORBA::TypeCode::_duplicate(any.type());
    csml_.stateful = FALSE;
    CSIIOP::CompoundSecMech mech;
    // transport layer configuration
    mech.transport_mech.tag = CSIIOP::TAG_NULL_TAG;
    csml_.mechanism_list.length(1);
    csml_.mechanism_list[0] = mech;
    // authentication layer configuration
    this->auth_layer(2);
    // attribute layer configuration
    this->attr_layer(1, 0);
    // global compound mechanism target requires
    this->recompute_cm_req();
    // seting default realm
    this->realm_name("@default_realm");
}

void
CSIv2::SecurityManager_impl::tss(TSS_ptr value)
{
    CORBA::release(tss_);
    tss_ = TSS::_duplicate(value);
}

void
CSIv2::SecurityManager_impl::css(CSS_ptr value)
{
    CORBA::release(css_);
    css_ = CSS::_duplicate(value);
}

void
CSIv2::SecurityManager_impl::add_server_user(char* name, char* passwd)
{
    tss_users_.push_back(name);
    tss_passwds_.push_back(passwd);
}

void
CSIv2::SecurityManager_impl::client_user(char* name, char* passwd)
{
    css_user_ = name;
    css_passwd_ = passwd;
}

void
CSIv2::SecurityManager_impl::realm_name(const char* name)
{
    realm_ = name;
    // works only for the first element of csml_ list
    CORBA::OctetSeq* gss_realm_name = this->gss_export_name
	(GSSUP::GSSUPMechOID, name);
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "encoded realm name: " << endl;
	debug(&(MICO::Logger::Stream(MICO::Logger::Security)), gss_realm_name);
    }
    csml_.mechanism_list[0].as_context_mech.target_name = *gss_realm_name;
}

CORBA::OctetSeq*
CSIv2::SecurityManager_impl::string2octet_seq(string str)
{
    CORBA::OctetSeq* seq = new CORBA::OctetSeq;
    seq->length(str.length());
    for (CORBA::ULong i=0; i<str.length(); i++)
	(*seq)[i] = (CORBA::Octet)str[i];
    return seq;
}

CSI::GSSToken*
CSIv2::SecurityManager_impl::get_gss_init_token
(const CSI::GSS_NT_ExportedName& target_name,
 CORBA::Object_ptr target,
 CORBA::String_out auth_name)
{
#ifdef USE_SL3
    CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
    CORBA::Object_var t_obj = orb->resolve_initial_references
        ("TransportSecurity::SecurityManager");
    MICOSL3_TransportSecurity::SecurityManager_impl* tsm_impl
	= dynamic_cast<MICOSL3_TransportSecurity::SecurityManager_impl*>(t_obj.in());
    assert(tsm_impl != NULL);
    if (tsm_impl->security_enabled()) {
	SecurityLevel3::OwnCredentials_var creds
	    = MICOSL3Utils::CredsRetriever::get_client_side_own_credentials
	    (orb, target, TRUE);
	assert(!CORBA::is_nil(creds));
	SecurityLevel3::CredsInitiator_var initiator = creds->creds_initiator();
	assert(!CORBA::is_nil(initiator));
	MICOSL3_SL3CSI::CSICredsInitiator* i_impl
	    = dynamic_cast<MICOSL3_SL3CSI::CSICredsInitiator*>(initiator.in());
	assert(i_impl != NULL);
	// kcg: TODO add local trust in server decider usage
	UserPassword::PasswordGenerator_var generator = i_impl->password_generator();
	if (generator.in() == NULL) {
	    // this is a case when client does not provide password generator
	    // possible situation is that it just runs identity
	    // and transport layer. In this situation we also have to disable
	    // auth layer for CSS
	    this->css_->auth_layer(0);
	    return NULL;
	}
	PrincipalName* name = generator->client_authentication_principal();
	assert(name != NULL);
	wstring wtn = name->the_name[0].in();
	delete name;
	string tn = wstr2str(wtn);
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3CSI: client authentication principal name: `"
		<< tn << "'" << endl;
	CORBA::WString_var login;
	CORBA::WString_var passwd;
	PrincipalName target;
	target.the_type = (const char*)NT_StringName;
	target.the_name.length(1);
	CORBA::OctetSeq target_name_seq(target_name);
	char* tmp = this->gss_import_name(GSSUP::GSSUPMechOID, &target_name_seq);
	string ttname = tmp;
	delete[] tmp;
	wstring wname = str2wstr(ttname);
	//wcout << "converted name: " << wname << endl;
	target.the_name[0] = CORBA::wstring_dup(wname.c_str());
	generator->generate_password(target, login, passwd);
	//wcout << "generated login: " << login.in() << endl;
	//wcout << "generated passwd: " << passwd.in() << endl;
	wstring wuser = login.in();
	wstring wpass = passwd.in();
	css_user_ = wstr2str(wuser);
	auth_name = CORBA::string_dup(css_user_.c_str());
	css_passwd_ = wstr2str(wpass);
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3CSI: generated login name: `"
		<< css_user_ << "'" << endl
		<< "SL3CSI: generated password: `"
		<< css_passwd_ << "'" << endl;
    }
#endif // USE_SL3
    if (css_user_ == "") {
	// the user doesn't set ''user name'' on command-line
	// so we will try to run without using auth layer
	return NULL;
    }
    GSSUP::InitialContextToken init_token;
    CORBA::OctetSeq* name = this->string2octet_seq(css_user_);
    CORBA::OctetSeq* passwd = this->string2octet_seq(css_passwd_);
    init_token.username.length(name->length());
    init_token.password.length(passwd->length());
    if (target_name.length() > 0)
	init_token.target_name = target_name;
    CORBA::ULong i;
    for (i=0; i<name->length(); i++)
	init_token.username[i] = (*name)[i];
    for (i=0; i<passwd->length(); i++)
	init_token.password[i] = (*passwd)[i];
    delete name;
    delete passwd;
    CSI::GSSToken* i_tok;
    CORBA::Any a;
    a <<= init_token;
    IOP::Codec_ptr codec = this->codec();
#ifdef USE_ENCODE_VALUE
    i_tok = codec->encode_value(a);
#else // USE_ENCODE_VALUE
    i_tok = codec->encode(a);
#endif
    CORBA::release(codec);
    CORBA::OctetSeq* oid = ASN1::Codec::encode_oid(GSSUP::GSSUPMechOID);
    CORBA::OctetSeq* ret_tok = new CORBA::OctetSeq;
    ret_tok->length(2 + oid->length() + i_tok->length());
    (*ret_tok)[0] = 0x60;
    assert(oid->length() + i_tok->length() < 128);
    (*ret_tok)[1] = oid->length() + i_tok->length();
    int s_ix = 2;
    for (i=0; i<oid->length(); i++)
	(*ret_tok)[i + s_ix] = (*oid)[i];
    s_ix = 2 + oid->length();
    for (i=0; i<i_tok->length(); i++)
	(*ret_tok)[i + s_ix] = (*i_tok)[i];
    delete i_tok;
    delete oid;
    return ret_tok;
}

void
CSIv2::SecurityManager_impl::codec_factory(IOP::CodecFactory_ptr factory)
{
    if (!CORBA::is_nil(codec_factory_)) {
	CORBA::release(codec_factory_);
	codec_factory_ = IOP::CodecFactory::_nil();
    }
    codec_factory_ = IOP::CodecFactory::_duplicate(factory);
}

IOP::Codec_ptr
CSIv2::SecurityManager_impl::codec()
{
    if (CORBA::is_nil(codec_)) {
	IOP::Encoding encoding;
	encoding.format = IOP::ENCODING_CDR_ENCAPS;
	encoding.major_version = 1;
	//encoding.minor_version = 0;
	encoding.minor_version = giop_version_ % 256;
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SecurityManager uses GIOP version 1."
		<< (short)encoding.minor_version << endl;
	assert(!CORBA::is_nil(this->codec_factory()));
	codec_ = IOP::Codec::_duplicate
	    (this->codec_factory()->create_codec(encoding));
    }
    return IOP::Codec::_duplicate(codec_);
}

#ifndef USE_SL3
void
CSIv2::SecurityManager_impl::auth_token
(const CSI::GSSToken& token,
 string& current_user)
#else // USE_SL3
void
CSIv2::SecurityManager_impl::auth_token
(const CSI::GSSToken& token,
 string& current_user,
 SecurityLevel3::OwnCredentials_ptr creds,
 SL3PM::PrincipalName_out auth_name)
#endif // USE_SL3
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SecurityManager_impl::auth_token: " << endl;
	debug(&MICO::Logger::Stream(MICO::Logger::Security), &token);
    }
    CSIv2::GSSAuthError ex;
    if (token[0] != 0x60) {
	// bad begining of token - it has to be 0x60
	ex.reason = GSSUP::GSS_UP_S_G_UNSPECIFIED;
	mico_throw(ex);
    }
    if (token[2] != 0x06) {
	// object identifier tag
	ex.reason = GSSUP::GSS_UP_S_G_UNSPECIFIED;
	mico_throw(ex);
    }
    CORBA::OctetSeq oid;
    int oid_len = token[3] + 2;  // OID length + tag + length
    oid.length(oid_len);
    for (int j=0; j<oid_len; j++)
	oid[j] = token[j+2];
    CORBA::String_var oid_str = ASN1::Codec::decode_oid(oid);
    if (strcmp(oid_str.in(), GSSUP::GSSUPMechOID) != 0) {
	// we support only GSSUP at the moment
	ex.reason = GSSUP::GSS_UP_S_G_UNSPECIFIED;
	mico_throw(ex);
    }
    CORBA::OctetSeq inner_token;
    int ix = oid_len + 2;
    inner_token.length(token.length() - ix);
    CORBA::ULong i;
    for (i=0; i<inner_token.length(); i++)
	inner_token[i] = token[ix + i];
    IOP::Codec_ptr codec = this->codec();
    CORBA::Any* a;
    GSSUP::InitialContextToken init_token;
#ifdef USE_ENCODE_VALUE
    a = codec->decode_value(inner_token, init_token_tc_);
#else // USE_ENCODE_VALUE
    a = codec->decode(inner_token);
#endif // USE_ENCODE_VALUE
    CORBA::release(codec);
    (*a) >>= init_token;
    string name = "";
    string passwd = "";
    for (i=0; i<init_token.username.length(); i++)
	name += init_token.username[i];
    for (i=0; i<init_token.password.length(); i++)
	passwd += init_token.password[i];
    delete a;
#ifdef USE_SL3
    if (!CORBA::is_nil(creds)) {
	// SL3 is enabled
	SecurityLevel3::CredsAcceptor_var acceptor = creds->creds_acceptor();
	if (!CORBA::is_nil(acceptor)) {
	    MICOSL3_SL3CSI::CSICredsAcceptor* a_impl
		= dynamic_cast<MICOSL3_SL3CSI::CSICredsAcceptor*>(acceptor.in());
	    assert(a_impl != NULL);
	    UserPassword::PasswordProcessor_var processor = a_impl->password_processor();
	    if (processor->client_authen_required()) {
		if (MICO::Logger::IsLogged(MICO::Logger::Security))
		    MICO::Logger::Stream(MICO::Logger::Security)
			<< "SL3CSI: client authentication required." << endl
			<< "SL3CSI: going to invoke verify_password." << endl;
		wstring wname = str2wstr(name);
		wstring wpass = str2wstr(passwd);
		CORBA::WString_var wn = wname.c_str();
		CORBA::WString_var wp = wpass.c_str();
		PrincipalName_var name;
		UserPassword::ErrorCode err = processor->verify_password
		    (wn, wp, name);
		switch(err) {
		case UserPassword::EC_Success:
		    if (MICO::Logger::IsLogged(MICO::Logger::Security))
			MICO::Logger::Stream(MICO::Logger::Security)
			    << "SL3CSI: UserPassword::EC_Success returned"
			    << endl;
		    auth_name = new PrincipalName(name);
		    return;
		case UserPassword::EC_BadPassword:
		    if (MICO::Logger::IsLogged(MICO::Logger::Security))
			MICO::Logger::Stream(MICO::Logger::Security)
			    << "SL3CSI: UserPassword::EC_BadPassword returned"
			    << endl;
		    ex.reason = GSSUP::GSS_UP_S_G_BAD_PASSWORD;
		    mico_throw(ex);
		case UserPassword::EC_NoUser:
		    if (MICO::Logger::IsLogged(MICO::Logger::Security))
			MICO::Logger::Stream(MICO::Logger::Security)
			    << "SL3CSI: UserPassword::EC_NoUser returned"
			    << endl;
		    ex.reason = GSSUP::GSS_UP_S_G_NOUSER;
		    mico_throw(ex);
		default:
		    assert(0);
		}
	    }
	    else {
		// auth is not required
		PrincipalName_var name = new PrincipalName;
		name->the_type = (const char*)NT_Anonymous;
		name->the_name.length(1);
		name->the_name[0] = L"anonymous";
		auth_name = new PrincipalName(name);
		return;
	    }
	}
    }
    else {
	// SL3 is disabled
	// but we still need to inicialize `out' variables
	auth_name = new PrincipalName;
    }
#endif // USE_SL3
    list<string>::iterator it;
    list<string>::iterator jt;
    //CORBA::Boolean ret_val = FALSE;
    for (it = tss_users_.begin(), jt = tss_passwds_.begin();
	 it != tss_users_.end(), jt != tss_passwds_.end();
	 it++, jt++) {
	if ((*it) == name) {
	    if (MICO::Logger::IsLogged(MICO::Logger::Security))
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "found auth name: " << name << endl;
	    if ((*jt) == passwd) {
		if (MICO::Logger::IsLogged(MICO::Logger::Security))
		    MICO::Logger::Stream(MICO::Logger::Security)
			<< "passwd is ok!" << endl;
		current_user = name;
		//ret_val = TRUE;
		//break;
		return;
	    }
	    else {
		if (MICO::Logger::IsLogged(MICO::Logger::Security))
		    MICO::Logger::Stream(MICO::Logger::Security)
		        << "bad passwd!" << endl;
		ex.reason = GSSUP::GSS_UP_S_G_BAD_PASSWORD;
		mico_throw(ex);
	    }
	}
    }
    current_user = "";
    ex.reason = GSSUP::GSS_UP_S_G_NOUSER;
    mico_throw(ex);
}

IOP::CodecFactory_ptr
CSIv2::SecurityManager_impl::codec_factory()
{
    return codec_factory_;
}

CSI::GSSToken*
CSIv2::SecurityManager_impl::error_token(GSSUP::ErrorCode reason)
{
    CORBA::Any any;
    GSSUP::ErrorToken tok;
    tok.error_code = reason;
    any <<= tok;
    //CORBA::TypeCode_ptr token_tc;
    //token_tc = any.type();
    CSI::GSSToken* ret_token = codec_->encode_value(any);
    return ret_token;
}

CORBA::OctetSeq*
CSIv2::SecurityManager_impl::ior_component_data()
{
    //cerr << "::ior_component_data()" << endl;
//      CORBA::Any any;
//      any <<= csml_;
//      assert(!CORBA::is_nil(this->codec()));
//      CORBA::OctetSeq* data = this->codec()->encode_value(any);
    // this is used for seting client delegation support/reqs
    CORBA::UShort delegation_value = 0;
#ifdef USE_SL3
    // update realm name
    CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
    CORBA::Object_var t_obj = orb->resolve_initial_references
        ("TransportSecurity::SecurityManager");
    MICOSL3_TransportSecurity::SecurityManager_impl* tsm_impl
	= dynamic_cast<MICOSL3_TransportSecurity::SecurityManager_impl*>(t_obj.in());
    assert(tsm_impl != NULL);
    if (tsm_impl->security_enabled()) {
	SecurityLevel3::OwnCredentials_var creds
	    = MICOSL3Utils::CredsRetriever::get_server_side_own_credentials(orb);
	assert(!CORBA::is_nil(creds));
	SecurityLevel3::CredsAcceptor_ptr acceptor = creds->creds_acceptor();
	assert(!CORBA::is_nil(acceptor));
	MICOSL3_SL3CSI::CSICredsAcceptor* a_impl
	    = dynamic_cast<MICOSL3_SL3CSI::CSICredsAcceptor*>(acceptor);
	assert(a_impl != NULL);
	UserPassword::PasswordProcessor_var processor = a_impl->password_processor();
	PrincipalName* target = processor->password_target();
	wstring tname = target->the_name[0].in();
	delete target;
	string sname = wstr2str(tname);
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3CSI: generated realm: `" << sname << "'" << endl;
	this->realm_name(sname.c_str());
	if (!processor->client_authen_required()
	    && this->tss()->auth_layer() == 2) {
	    // we do not require client authentication
	    this->tss()->auth_layer(1);
	}
	SL3Authorization::TokenProcessor_var tp
	    = a_impl->token_processor();
	if (!CORBA::is_nil(tp)) {
	    // token processor presented
	    if (tp->supports_endorsement_by_client()
		&& !tp->requires_endorsement_by_client()) {
		delegation_value = 1;
	    }
	    else if (tp->supports_endorsement_by_client()
		     && tp->requires_endorsement_by_client()) {
		delegation_value = 2;
	    }
	    else if (!tp->supports_endorsement_by_client()
		     && tp->requires_endorsement_by_client()) {
		assert(0);
	    }
	}
	// ATLAS
	ATLAS::ATLASCacheId_var id = a_impl->cache_id();
	ATLAS::AuthTokenDispenser_var token_dispenser
	    = a_impl->token_dispenser();
	if (!CORBA::is_nil(token_dispenser)) {
	    // assign ATLAS ref into the csml_
	    //cerr << "assign ATLAS ref into the csml_" << endl;
	    ATLAS::ATLASProfile prof;
	    prof.the_cache_id = id;
	    ATLAS::ATLASLocator locator;
	    locator.the_dispenser(token_dispenser);			
	    prof.the_locator = locator;
	    CORBA::Any a;
	    a <<= prof;
	    CORBA::OctetSeq_var prof_data = codec_->encode_value(a);
	    //cerr << "prof_data.length(): " << prof_data->length() << endl;
	    csml_.mechanism_list[0].sas_context_mech.privilege_authorities.length(1);
	    csml_.mechanism_list[0].sas_context_mech.privilege_authorities[0].syntax
		= ATLAS::SCS_ATLAS;
	    csml_.mechanism_list[0].sas_context_mech.privilege_authorities[0].name
		= prof_data;
	}
    }
#endif // USE_SL3
    this->auth_layer(this->tss()->auth_layer());
    this->attr_layer(this->tss()->attr_layer(), delegation_value);
    this->recompute_cm_req();

    //
    // This is a hack for the moment. The big item on TODO
    // list is to correct it and consult with spec. acording
    // the encapsulation usage e.g. coding with using IOP::Codec.
    // (above)
    //

    CORBA::Buffer* buf = new CORBA::Buffer;
    MICO::CDREncoder* encoder = new MICO::CDREncoder(buf);
    _marshaller_CSIIOP_CompoundSecMechList->marshal(*encoder, (void*)&csml_);
    buf->rseek_beg(0);
    CORBA::OctetSeq* data = new CORBA::OctetSeq;
    data->length(buf->length());
    for (CORBA::ULong i=0; i<data->length(); i++)
	(*data)[i] = (buf->data())[i];
    return data;
}

CORBA::OctetSeq*
CSIv2::SecurityManager_impl::gss_export_name(const char* oid, const char* name)
{
    //cerr << "gss_export_name(" << oid << ", " << name << ")" << endl;
    CORBA::OctetSeq* ret_val = new CORBA::OctetSeq;
    ret_val->length(2);
    (*ret_val)[0] = 0x04; // token id
    (*ret_val)[1] = 0x01; // token id
    CORBA::OctetSeq* t_oid = ASN1::Codec::encode_oid(oid);
    CORBA::OctetSeq* t_name = this->string2octet_seq(name);
    //cerr << "t_name->length(): " << t_name->length() << endl;
    // token id + OID + string length + string
    ret_val->length(2 + 2 + t_oid->length() + 4 + t_name->length());
    short oid_length = t_oid->length();
    (*ret_val)[2] = oid_length / 0xFF; // length of ASN1 OID
    (*ret_val)[3] = oid_length % 0xFF; // in big-endian order
    int i;
    for (i=0; i<oid_length; i++)
	(*ret_val)[i+4] = (*t_oid)[i];
    int name_length = t_name->length();
    char b4 = name_length / 0xFFFFFF;
    int l2 = name_length % 0xFFFFFF;
    char b3 = l2 / 0xFFFF;
    int l3 = l2 % 0xFFFF;
    char b2 = l3 / 0xFF;
    char b1 = l3 % 0xFF;
    (*ret_val)[4+oid_length+0] = b4;
    (*ret_val)[4+oid_length+1] = b3;
    (*ret_val)[4+oid_length+2] = b2;
    (*ret_val)[4+oid_length+3] = b1;
    for (i=0; i<name_length; i++)
	(*ret_val)[i+4+oid_length+4] = (*t_name)[i];
    delete t_oid;
    delete t_name;
    return ret_val;
}

char*
CSIv2::SecurityManager_impl::gss_import_name
(const char* oid,
 CORBA::OctetSeq* data)
{
    CORBA::ULong oid_length = (*data)[2] * 0xFF + (*data)[3];
    CORBA::OctetSeq oid_data;
    oid_data.length(oid_length);
    CORBA::ULong i;
    for (i=0; i<oid_length; i++)
	oid_data[i] = (*data)[i+4];
    CORBA::String_var s_oid = ASN1::Codec::decode_oid(oid_data);
    if (strcmp(s_oid.in(), oid) != 0) {
	// we are not supporting other mechanism than GSSUP
	return NULL;
    }
    CORBA::ULong name_length = 
	(*data)[4+oid_length+0] * 0xFFFFFF
	+ (*data)[4+oid_length+1] * 0xFFFF
	+ (*data)[4+oid_length+2] * 0xFF
	+ (*data)[4+oid_length+3];
    char* buf = new char[name_length+1];
    buf[name_length] = 0;
    for (i=0; i<name_length; i++)
	buf[i] = (*data)[4+oid_length+4+i];
    return buf;
}

void
CSIv2::SecurityManager_impl::tls_user_list
(const DistinguishedNameList& user_list)
{
    tls_user_list_ = user_list;
}

CSIv2::DistinguishedNameList*
CSIv2::SecurityManager_impl::tls_user_list()
{
    return &tls_user_list_;
}

void
CSIv2::SecurityManager_impl::user_id_list(const UserIdentityList& user_id_list)
{
    user_id_list_ = user_id_list;
}

CSIv2::UserIdentityList*
CSIv2::SecurityManager_impl::user_id_list()
{
    return &user_id_list_;
}

CSI::GSS_NT_ExportedName*
CSIv2::SecurityManager_impl::client_identity_token
(CORBA::Object_ptr target,
 CORBA::String_out identity)
{
    CSI::GSS_NT_ExportedName* name = NULL;
    string id = "";
#ifdef USE_SL3
    CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
    CORBA::Object_var t_obj = orb->resolve_initial_references
        ("TransportSecurity::SecurityManager");
    MICOSL3_TransportSecurity::SecurityManager_impl* tsm_impl
	= dynamic_cast<MICOSL3_TransportSecurity::SecurityManager_impl*>(t_obj.in());
    assert(tsm_impl != NULL);
    if (tsm_impl->security_enabled()) {
	SecurityLevel3::OwnCredentials_var creds
	    = MICOSL3Utils::CredsRetriever::get_client_side_own_credentials
	    (orb, target, TRUE);
	assert(!CORBA::is_nil(creds));
	SecurityLevel3::CredsInitiator_var initiator = creds->creds_initiator();
	assert(!CORBA::is_nil(initiator));
	Principal_var pr = initiator->the_principal();
	QuotingPrincipal* qp = NULL;
	if (pr->the_type() == PT_Quoting
	    && ((qp = QuotingPrincipal::_downcast(pr)) != NULL)) {
	    // quoting principal => we can generate identity token
	    PrincipalName qp_name = qp->the_name();
	    CORBA::WString_var name = CORBA::wstring_dup(qp_name.the_name[0]);
	    wstring wname = name.in();
	    id = wstr2str(wname);
	    identity = CORBA::string_dup(id.c_str());
	    if (MICO::Logger::IsLogged(MICO::Logger::Security))
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "SL3CSI: client identity: `"
		    << id << "'" << endl;
	}
    }
#endif // USE_SL3
    if (id == "")
	id = this->client_identity();
    if (id != "") {
	name = this->gss_export_name
	    (GSSUP::GSSUPMechOID, id.c_str());
    }
    return name;
}

#ifndef USE_SL3
void
CSIv2::SecurityManager_impl::verify_client_identity
(const CSI::IdentityToken& identity,
 CORBA::Boolean use_auth_layer,
 const string& current_user)
#else // USE_SL3
void
CSIv2::SecurityManager_impl::verify_client_identity
(const CSI::IdentityToken& identity,
 CORBA::Boolean use_auth_layer,
 const string& current_user,
 SecurityLevel3::OwnCredentials_ptr creds,
 SL3PM::PrincipalName_out identity_name,
 CORBA::Boolean_out identity_used)
#endif // USE_SL3
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SecurityManager_impl: verify client identity" << endl;
    if (identity._d() == CSI::ITTAbsent) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SecurityManager_impl: client identity is absent..." << endl;
#ifdef USE_SL3
	identity_name = new PrincipalName;
	identity_used = FALSE;
#endif // USE_SL3
	return;
    }
    if (identity._d() != CSI::ITTPrincipalName) {
	// throw exception because CSIv2 L0 supports either ITTAbsent
	// or ITTPrincipalName identity types
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SecurityManager_impl: client identity is other type"
		<< " than ITTAbsent or ITTPrincipalName!" << endl;
	// we do not need to setup client credentials in this call
	// since it will result in throwing NO_PERMISSION exception
	// from the TSS
	mico_throw(CSIv2::TrustIdentityError());
    }
    if (identity._d() == CSI::ITTPrincipalName) {
	// checking if asserted identity is valid for this client
	CORBA::OctetSeq id_data = identity.principal_name();
	char* t_name = this->gss_import_name(GSSUP::GSSUPMechOID, &id_data);
	if (t_name == NULL) {
	    mico_throw(CSIv2::TrustIdentityError());
	}
	string id = t_name;
	delete t_name;
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "decoded identity string `" << id << "'" << endl;
#ifdef USE_SL3
	if (!CORBA::is_nil(creds)) {
	    // SL3 is enabled
	    identity_used = TRUE;
	    PrincipalName_var id_name = new PrincipalName;
	    id_name->the_type = (const char*)SL3PM::NT_StringName;
	    id_name->the_name.length(1);
	    wstring wname = str2wstr(id);
	    id_name->the_name[0] = wname.c_str();
	    assert(!CORBA::is_nil(creds));
	    identity_name = new PrincipalName(id_name);
	    return;
	}
	else {
	    // SL3 is disabled
	    // but we still need to initialize `out' variables
	    identity_name = new PrincipalName;
	    identity_used = FALSE;
	}
#endif // USE_SL3
	if (use_auth_layer) {
	    // we'll check identity by using auth layer gss user name
	    for (CORBA::ULong i=0; i<user_id_list_.length(); i++) {
		if (current_user == user_id_list_[i].user_name.in()) {
		    if (MICO::Logger::IsLogged(MICO::Logger::Security))
			MICO::Logger::Stream(MICO::Logger::Security)
			    << "found identity user" << endl;
		    if (id == user_id_list_[i].identity_name.in()) {
			if (MICO::Logger::IsLogged(MICO::Logger::Security))
			    MICO::Logger::Stream(MICO::Logger::Security)
				<< "identity is ok!" << endl;
			return;
		    }
		    break;
		}
	    }
	}
	else {
	    // we'll check identity on the basis of TLS
	    // layer subject name
	    CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
	    CORBA::Object_var obj
		= orb->resolve_initial_references("PrincipalCurrent");
	    CORBA::PrincipalCurrent_var p_current
		= CORBA::PrincipalCurrent::_narrow(obj);
	    CORBA::Principal_var princ = p_current->get_principal();
	    const char* str;
	    CORBA::Any_var t_any;

	    t_any = princ->get_property ("auth-method");
	    t_any >>= str;
	    string auth = str;
	    if (auth == "ssl") {
		t_any = princ->get_property ("ssl-x509-subject");
		t_any >>= str;
		string tls_user_name = str;
		if (MICO::Logger::IsLogged(MICO::Logger::Security))
		    MICO::Logger::Stream(MICO::Logger::Security)
			<< "TLS user name: `" << tls_user_name << "'" << endl;
		for (CORBA::ULong i=0; i<user_id_list_.length(); i++) {
		    if (tls_user_name == user_id_list_[i].user_name.in()) {
			if (MICO::Logger::IsLogged(MICO::Logger::Security))
			    MICO::Logger::Stream(MICO::Logger::Security)
				<< "found identity user" << endl;
			if (id == user_id_list_[i].identity_name.in()) {
			    if (MICO::Logger::IsLogged(MICO::Logger::Security))
				MICO::Logger::Stream(MICO::Logger::Security)
				    << "identity is ok!" << endl;
			    return;
			}
			break;
		    }
		}
	    }
	}
    }
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "identity is not valid!" << endl;
    mico_throw(CSIv2::TrustIdentityError());
}

void
CSIv2::SecurityManager_impl::client_identity(const char* identity)
{
    client_identity_ = identity;
}

char*
CSIv2::SecurityManager_impl::client_identity()
{
    return client_identity_;
}

void
CSIv2::SecurityManager_impl::establish_context
(const CSI::GSSToken& auth_token,
 const CSI::IdentityToken& identity_token,
 const CSI::AuthorizationToken& authorization_token)
{
#ifdef USE_SL3
    PrincipalName_var auth_name;
    PrincipalName_var identity_name;
    CORBA::Boolean identity_used = FALSE;
    CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
    CORBA::Object_var t_obj = orb->resolve_initial_references
	("TransportSecurity::SecurityManager");
    MICOSL3_TransportSecurity::SecurityManager_impl* tsm_impl
	= dynamic_cast<MICOSL3_TransportSecurity::SecurityManager_impl*>(t_obj.in());
    assert(tsm_impl != NULL);
    SecurityLevel3::OwnCredentials_var creds = SecurityLevel3::OwnCredentials::_nil();
    if (tsm_impl->security_enabled()) {
	creds = MICOSL3Utils::CredsRetriever::get_server_side_own_credentials
	    (orb);
	assert(!CORBA::is_nil(creds));
    }
#endif // USE_SL3
    string current_user = "";
    CORBA::Boolean tb = FALSE;
    CORBA::Boolean authenticated = FALSE;
    if (auth_token.length() > 0) {
	authenticated = TRUE;
#ifndef USE_SL3
	this->auth_token(auth_token, current_user);
#else // USE_SL3
	this->auth_token(auth_token, current_user, creds, auth_name);
#endif // USE_SL3
	tb = TRUE;
    }
    else {
#ifdef USE_SL3
	auth_name = new PrincipalName;
	auth_name->the_type = (const char*)NT_Anonymous;
	auth_name->the_name.length(1);
	auth_name->the_name[0] = L"anonymous";
#endif // USE_SL3
    }
#ifndef USE_SL3
    this->verify_client_identity(identity_token, tb, current_user);
#else // USE_SL3
    this->verify_client_identity
	(identity_token, tb, current_user, creds,
	 identity_name, identity_used);
    if (!CORBA::is_nil(creds)) {
	// SL3 is enabled
	this->create_csi_creds
	    (auth_name, authenticated, identity_name, identity_used,
	     authorization_token, creds);
    }
#endif // USE_SL3
}

void
CSIv2::SecurityManager_impl::auth_layer(CORBA::UShort value)
{
    if (value > 0) {
	// authentication layer configuration
	CSIIOP::AS_ContextSec as_context_mech;
	as_context_mech.target_supports = 64;
	if (value == 2) // requires
	    as_context_mech.target_requires = 64;
	else
	    as_context_mech.target_requires = 0;
	CORBA::OctetSeq* gssup_oid = ASN1::Codec::encode_oid
	    (GSSUP::GSSUPMechOID);
	as_context_mech.client_authentication_mech = (*gssup_oid);
	delete gssup_oid;
	for (CORBA::ULong i=0; i<csml_.mechanism_list.length(); i++) {
	    as_context_mech.target_name
		= csml_.mechanism_list[i].as_context_mech.target_name;
	    csml_.mechanism_list[i].as_context_mech = as_context_mech;
	}
    }
    else {
	for (CORBA::ULong i=0; i<csml_.mechanism_list.length(); i++)
	    csml_.mechanism_list[i].as_context_mech.target_supports = 0;
    }	
}

void
CSIv2::SecurityManager_impl::attr_layer
(CORBA::UShort identity_assertion_value,
 CORBA::UShort delegation_value)
{
    if (identity_assertion_value > 0) {
	// attribute layer configuration
	CSIIOP::SAS_ContextSec sas_context_mech;
	sas_context_mech.target_supports = 1024;
	if (identity_assertion_value == 2) // requires
	    sas_context_mech.target_requires = 1024;
	else
	    sas_context_mech.target_requires = 0;
	sas_context_mech.privilege_authorities.length(0);
	sas_context_mech.supported_naming_mechanisms.length(1);
	CORBA::OctetSeq* gssup_oid = ASN1::Codec::encode_oid
	    (GSSUP::GSSUPMechOID);
	sas_context_mech.supported_naming_mechanisms[0] = (*gssup_oid);
	delete gssup_oid;
	sas_context_mech.supported_identity_types = CSI::ITTPrincipalName;
	for (CORBA::ULong i=0; i<csml_.mechanism_list.length(); i++) {
	    if (csml_.mechanism_list[i].sas_context_mech.privilege_authorities.length() > 0)
		sas_context_mech.privilege_authorities
		    = csml_.mechanism_list[i].sas_context_mech.privilege_authorities;
	    csml_.mechanism_list[i].sas_context_mech = sas_context_mech;
	}
    }
    else {
	for (CORBA::ULong i=0; i<csml_.mechanism_list.length(); i++)
	    csml_.mechanism_list[i].sas_context_mech.target_supports = 0;
    }
    if (delegation_value == 1) {
	// update support for delegation
	for (CORBA::ULong i=0; i<csml_.mechanism_list.length(); i++) {
	    csml_.mechanism_list[i].sas_context_mech.target_supports
		= csml_.mechanism_list[i].sas_context_mech.target_supports
		+ CSIIOP::DelegationByClient;
	}
    }
    if (delegation_value == 2) {
	// update support/requires delegation
	for (CORBA::ULong i=0; i<csml_.mechanism_list.length(); i++) {
	    csml_.mechanism_list[i].sas_context_mech.target_supports
		= csml_.mechanism_list[i].sas_context_mech.target_supports
		+ CSIIOP::DelegationByClient;
	    csml_.mechanism_list[i].sas_context_mech.target_requires
		= csml_.mechanism_list[i].sas_context_mech.target_requires
		+ CSIIOP::DelegationByClient;
	}
    }
}

void
CSIv2::SecurityManager_impl::recompute_cm_req()
{
    for (CORBA::ULong i=0; i<csml_.mechanism_list.length(); i++) {
	// global compound mechanism target requires
	CORBA::UShort reqs = 0;
	if (csml_.mechanism_list[i].transport_mech.tag != CSIIOP::TAG_NULL_TAG)
	    reqs = reqs|70;
	else
	    reqs = reqs|64;
	if (csml_.mechanism_list[i].as_context_mech.target_supports != 0)
	    reqs = reqs
		|csml_.mechanism_list[i].as_context_mech.target_requires;
	if (csml_.mechanism_list[i].sas_context_mech.target_supports != 0)
	    reqs = reqs
		|csml_.mechanism_list[i].sas_context_mech.target_requires;
	csml_.mechanism_list[i].target_requires = reqs;
    }
}

#ifdef USE_SL3
void
CSIv2::SecurityManager_impl::create_csi_creds
(const PrincipalName& auth_name,
 CORBA::Boolean authenticated,
 const PrincipalName& identity_name,
 CORBA::Boolean identity_supplied,
 const AuthorizationToken& auth_token,
 SecurityLevel3::OwnCredentials_ptr own_creds,
 CORBA::Boolean accept_based_on_transport)
{
    assert(authenticated || identity_supplied);
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3CSIv2: SecurityManager_impl::create_csi_creds" << endl;
    }
    string key = "";
    if (authenticated) {
	wstring wid = auth_name.the_name[0].in();
	key = wstr2str(wid);
    }
    if (identity_supplied) {
	wstring wid = identity_name.the_name[0].in();
	key += "_" + wstr2str(wid);
    }
    //cerr << "SecurityManager_impl::create_csi_creds: map key: " << key << endl;
    CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
    CORBA::Object_var obj = orb->resolve_initial_references
	("TransportSecurity::SecurityCurrent");
    TransportSecurity::SecurityCurrent_var current
	= TransportSecurity::SecurityCurrent::_narrow(obj);
    assert(!CORBA::is_nil(current));
    TransportSecurity::ClientCredentials_var transp_client_creds
	= current->client_credentials();
    assert(!CORBA::is_nil(transp_client_creds));
    MICOSL3_SecurityLevel3::ClientCredsHolder* holder
	= dynamic_cast<MICOSL3_SecurityLevel3::ClientCredsHolder*>
	(transp_client_creds.in());
    SecurityLevel3::ClientCredentials_var client_credentials
	= holder->csi_creds(key);
    if (CORBA::is_nil(client_credentials)) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3CSIv2: need to create CSI client creds now" << endl;
	}
	MICOSL3_SecurityLevel3::ClientCredentials_impl* creds
	    = new MICOSL3_SecurityLevel3::ClientCredentials_impl;
	SecurityLevel3::ClientCredentials_var creds_remove_helper = creds;
	assert(!CORBA::is_nil(own_creds));
	SecurityLevel3::CredsAcceptor_var acceptor = own_creds->creds_acceptor();
	assert(!CORBA::is_nil(acceptor));
	MICOSL3_SL3CSI::CSICredsAcceptor* acceptor_impl
	    = dynamic_cast<MICOSL3_SL3CSI::CSICredsAcceptor*>(acceptor.in());
	assert(acceptor_impl != NULL);
	TokenProcessor_var token_processor = acceptor_impl->token_processor();
	string id = own_creds->creds_id();
	id += "_ClientCredentials:";
	id += xdec(S_client_creds_index_);
	string cid = "CSI_ClientCredentials:";
	cid += xdec(S_client_creds_index_);
	S_client_creds_index_++;
	creds->creds_id(id.c_str());
	creds->creds_type(CT_ClientCredentials);
	creds->creds_usage(CU_None);
	creds->creds_state(CS_Valid);
	creds->context_id(cid.c_str());
	// transport principal
	Principal_var transport_principal
	    = transp_client_creds->client_principal();
	StatementList_var transport_statements
	    = transp_client_creds->client_supporting_statements();
	ResourceNameList_var transport_resources
	    = transp_client_creds->client_restricted_resources();
	// client auth principal
	PrinAttributeList envattrs;
	envattrs.length(0);
	ScopedPrivilegesList privs;
	privs.length(0);
	PrincipalNameList alts;
	alts.length(0);
	SimplePrincipal_var client_auth_principal = NULL;
	PrincipalIdentityStatement* client_auth_statement = NULL;
	ProxyPrincipal_var proxy_principal = NULL;
	if (authenticated) {
	    client_auth_principal = new MICOSL3_SL3PM::SimplePrincipal_impl
		(auth_name, privs, alts);
	    client_auth_principal->authenticated(true);
	    client_auth_statement
		= new MICOSL3_SL3PM::PrincipalIdentityStatement_impl;
	    client_auth_statement->the_layer(SL_CSIClientAuth);
	    client_auth_statement->the_type(ST_IdentityStatement);
	    CORBA::add_ref(client_auth_principal);
	    client_auth_statement->the_principal(client_auth_principal);
	    proxy_principal = new MICOSL3_SL3PM::ProxyPrincipal_impl
		(transport_principal, client_auth_principal);
	}
	// identity asserted principal
	SimplePrincipal_var q_princ = NULL;
	QuotingPrincipal_var identity_assert_principal = NULL;
	PrincipalIdentityStatement* qpistat = NULL;
	StatementList identity_assert_statements;
	identity_assert_statements.length(0);
	if (identity_supplied) {
	    // we will create appropriate QuotingPrincipal
	    q_princ = new MICOSL3_SL3PM::SimplePrincipal_impl
		(identity_name, privs, alts);
	    qpistat = new MICOSL3_SL3PM::PrincipalIdentityStatement_impl;
	    qpistat->the_layer(SL_CSIIdentity);
	    qpistat->the_type(ST_IdentityStatement);
	    CORBA::add_ref(q_princ);
	    qpistat->the_principal(q_princ);
	    // we will create appropriate QuotingPrincipal
	    if (authenticated) {
		identity_assert_principal = new MICOSL3_SL3PM::QuotingPrincipal_impl
		    (proxy_principal, q_princ);
	    }
	    else {
		// not authenticated
		identity_assert_principal = new MICOSL3_SL3PM::QuotingPrincipal_impl
		    (transport_principal, q_princ);
	    }
	    for (CORBA::ULong i = 0; i < transport_statements->length(); i++) {
		identity_assert_statements.length
		    (identity_assert_statements.length() + 1);
		identity_assert_statements
		    [identity_assert_statements.length() - 1]
		    = transport_statements[i];
	    }
	    if (authenticated) {
		identity_assert_statements.length
		    (identity_assert_statements.length() + 1);
		CORBA::add_ref(client_auth_statement);
		identity_assert_statements
		    [identity_assert_statements.length() - 1]
		    = client_auth_statement;
	    }
	    identity_assert_statements.length
		(identity_assert_statements.length() + 1);
	    CORBA::add_ref(qpistat);
	    identity_assert_statements
		[identity_assert_statements.length() - 1]
		= qpistat;
	}
	AuthorizationInfo* info = NULL;
	if (!CORBA::is_nil(token_processor)) {
	    // to be removed, just for test
	    TSS_impl* tss_impl = dynamic_cast<CSIv2::TSS_impl*>(tss_);
	    assert(tss_impl != NULL);
	    info = token_processor->accept_token
		(transport_principal,
		 transport_statements,
		 transport_resources,
		 client_auth_principal,
		 client_auth_statement,
		 identity_assert_principal,
		 identity_assert_statements,
		 auth_token);
	}
	Principal_var client_principal = NULL;
	if (info != NULL) {
	    // manage info information
	    creds->client_principal(info->the_principal);
	    creds->client_supporting_statements(info->the_statements);
	}
	else {
	    // info is NULL
	    if (identity_supplied) {
		CORBA::add_ref(identity_assert_principal);
		client_principal = identity_assert_principal;
	    }
	    else if (accept_based_on_transport) {
		CORBA::add_ref(client_auth_principal);
		client_principal = client_auth_principal;
	    }
	    else {
		CORBA::add_ref(proxy_principal);
		client_principal = proxy_principal;
	    }
	    creds->client_principal(client_principal);
	    // statements
	    StatementList csstats;
	    csstats.length(0);
	    StatementList_var transp_c_stats
		= transp_client_creds->client_supporting_statements();
//  	    StatementList_var csi_c_stats
//  		= acceptor->supporting_statements();
	    for (CORBA::ULong i = 0; i < transp_c_stats->length(); i++) {
		csstats.length(csstats.length() + 1);
		csstats[csstats.length() - 1] = transp_c_stats[i];
	    }
	    if (authenticated && !accept_based_on_transport) {
		csstats.length(csstats.length() + 1);
		csstats[csstats.length() - 1] = client_auth_statement;
	    }
	    if (identity_supplied) {
		csstats.length(csstats.length() + 1);
		csstats[csstats.length() - 1] = qpistat;
	    }
	    creds->client_supporting_statements(csstats);
	}
	Principal_var transp_target_principal
	    = transp_client_creds->target_principal();
	creds->target_principal(transp_target_principal);
	StatementList_var tsstats
	    = transp_client_creds->target_supporting_statements();
	creds->target_supporting_statements(tsstats);
	PrinAttributeList_var env_attrs = transp_client_creds->environmental_attributes();
	creds->environmental_attributes(env_attrs);
	creds->parent_credentials(own_creds);
	creds->client_authentication(authenticated);
	creds->target_authentication(transp_client_creds->target_authentication());
	creds->confidentiality(transp_client_creds->confidentiality());
	creds->integrity(transp_client_creds->integrity());
	holder->csi_creds(key, creds);
	creds->notify_creation();
	MICOSL3_SecurityLevel3::OwnCredentials_impl* owncreds_impl
	    = dynamic_cast<MICOSL3_SecurityLevel3::OwnCredentials_impl*>
	    (own_creds);
	assert(owncreds_impl != NULL);
	TransportSecurity::AcceptingContext_var accept_ctx
	    = TransportSecurity::AcceptingContext::_narrow(transp_client_creds);
	assert(!CORBA::is_nil(accept_ctx));
	owncreds_impl->add_observer(accept_ctx);
	holder->current_creds(creds);
    }
    else {
	holder->current_creds(client_credentials);
    }
}

void
CSIv2::SecurityManager_impl::create_csi_creds
(const PrincipalName& auth_name,
 CORBA::Boolean authenticated,
 const PrincipalName& identity_name,
 CORBA::Boolean identity_supplied,
 const AuthorizationToken& auth_token,
 SecurityLevel3::OwnCredentials_ptr own_creds)
{
    this->create_csi_creds
	(auth_name, authenticated, identity_name, identity_supplied,
	 auth_token, own_creds, FALSE);
}

void
CSIv2::SecurityManager_impl::create_csi_creds_from_transport
(const PrincipalName& auth_name,
 SecurityLevel3::OwnCredentials_ptr own_creds)
{
    PrincipalName identity_name;
    AuthorizationToken auth_token;
    this->create_csi_creds
	(auth_name, TRUE, identity_name, FALSE, auth_token,
	 own_creds, TRUE);
}

#endif // USE_SL3

void
CSIv2::ServerRequestInterceptor_impl::destroy()
{
    CORBA::release(sec_manager_);
    CORBA::release(codec_factory_);
    CORBA::release(tss_);
}

void
CSIv2::ServerRequestInterceptor_impl::receive_request_service_contexts
(PortableInterceptor::ServerRequestInfo_ptr info)
{
    //
    // kcg: It seems this PI bug is resolved =>
    // I have moved this code into ::receive_request
    // If anything is broken, complain!
    //

    // it's here because PI has a bug
    // that calling add_reply_service_context
    // will not add context while throwing exception
    // in SRI::receive_context, which is a bug!
    // Here it's safe :-(((
//      if (sec_manager_->csiv2()) {
//  	tss_->receive_request(info);
//      }
}

void
CSIv2::ServerRequestInterceptor_impl::receive_request
(PortableInterceptor::ServerRequestInfo_ptr info)
{
    if (sec_manager_->csiv2()) {
	tss_->receive_request(info);
    }
}

void
CSIv2::ServerRequestInterceptor_impl::send_reply
(PortableInterceptor::ServerRequestInfo_ptr info)
{
    if (sec_manager_->csiv2()) {
	tss_->send_reply(info);
    }
}

void
CSIv2::ServerRequestInterceptor_impl::send_exception
(PortableInterceptor::ServerRequestInfo_ptr info)
{
}

void
CSIv2::ServerRequestInterceptor_impl::send_other
(PortableInterceptor::ServerRequestInfo_ptr info)
{
}

void
CSIv2::ClientRequestInterceptor_impl::destroy()
{
    CORBA::release(sec_manager_);
    CORBA::release(codec_factory_);
    CORBA::release(css_);
}

void
CSIv2::ClientRequestInterceptor_impl::send_request
(PortableInterceptor::ClientRequestInfo_ptr info)
{
    assert(!CORBA::is_nil(sec_manager_));
    if (sec_manager_->csiv2()) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "client: send_request with SAS service context" << endl;
	// we are using CSIv2
	css_->send_request(info);
    }
}

void
CSIv2::ClientRequestInterceptor_impl::receive_reply
(PortableInterceptor::ClientRequestInfo_ptr info)
{
    if (sec_manager_->csiv2()) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "client: receive_reply" << endl;
	try {
	    IOP::ServiceContext_var ctx
		= info->get_request_service_context(IOP::SecurityAttributeService);
	    css_->receive_reply(info);
	} catch (CORBA::BAD_PARAM& ex) {
	    // service context doesn't contain SAS msg
	}
    }
}

void
CSIv2::ClientRequestInterceptor_impl::receive_exception
(PortableInterceptor::ClientRequestInfo_ptr info)
{
    if (sec_manager_->csiv2()) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "client: receive_exception" << endl;
	try {
	    IOP::ServiceContext_var ctx
		= info->get_request_service_context(IOP::SecurityAttributeService);
	    css_->receive_exception(info);
	} catch (CORBA::BAD_PARAM& ex) {
	    if (MICO::Logger::IsLogged(MICO::Logger::Security))
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "client: service context doesn't contain SAS msg"
		    << endl;
	}
    }
}

void
CSIv2::ClientRequestInterceptor_impl::receive_other
(PortableInterceptor::ClientRequestInfo_ptr info)
{
    if (sec_manager_->csiv2()) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "client: receive_other" << endl;
    }
}

void
CSIv2::InterceptorInitializer_impl::pre_init
(PortableInterceptor::ORBInitInfo_ptr info)
{
    IOP::CodecFactory_ptr factory = info->codec_factory();
    sec_manager_->codec_factory(factory);
    if (sec_manager_->csiv2()) {
	ClientRequestInterceptor_impl* cri 
	    = new ClientRequestInterceptor_impl
	    ("CSIv2::ClientRequestInterceptor_impl", sec_manager_, factory);
	info->add_client_request_interceptor(cri);
	ServerRequestInterceptor_impl* sri
	    = new ServerRequestInterceptor_impl
	    ("CSIv2::ServerRequestInterceptor_impl", sec_manager_, factory);
	info->add_server_request_interceptor(sri);
	IORInterceptor_impl* ii = new IORInterceptor_impl
	    ("CSIv2::IORInterceptor_impl", sec_manager_);
	info->add_ior_interceptor(ii);
    }
    // it register itself
    CSIv2::ComponentDecoder* dc = new CSIv2::ComponentDecoder;
    dc->codec(sec_manager_->codec());
}

void
CSIv2::IORInterceptor_impl::destroy()
{
    CORBA::release(sec_manager_);
}

void
CSIv2::IORInterceptor_impl::establish_components
(PortableInterceptor::IORInfo_ptr info)
{
    if (sec_manager_->csiv2()) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security))
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "IOR: establish_components" << endl;
	IOP::TaggedComponent component;
	component.tag = CSIIOP::TAG_CSI_SEC_MECH_LIST;
	CORBA::OctetSeq_var tmp = sec_manager_->ior_component_data();
	component.component_data = tmp;
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    debug(&(MICO::Logger::Stream(MICO::Logger::Security)),
		  &(component.component_data));
	}
	//info->add_ior_component(component);
	// we need to add this component into IIOP profile
	// we can't simply add it into every profile, because
	// every in MICO means MultiComponent profile too, and
	// as CSIv2 spec. says the usage of MultiComponent profile
	// is not supported at the moment
	try {
	    info->add_ior_component_to_profile
		(component, CORBA::IORProfile::TAG_INTERNET_IOP);
	} catch (CORBA::BAD_PARAM& ex) {
	    if (MICO::Logger::IsLogged(MICO::Logger::Security))
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "IOR: can't find IIOP profile" << endl;
	}
	try {
	    info->add_ior_component_to_profile
		(component, CORBA::IORProfile::TAG_SSL_INTERNET_IOP);
	} catch (CORBA::BAD_PARAM& ex) {
	    if (MICO::Logger::IsLogged(MICO::Logger::Security))
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "IOR: can't find SSL IIOP profile" << endl;
	}
    }
}

//
// CSIv2 IOR Component and ComponentDecoder
//

CSIv2::Component::Component(const Component& c)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "CSIv2::Component::Component(const Component& c)" << endl;
    csml_ = c.csml_;
    codec_ = IOP::Codec::_duplicate(c.codec_);
}

void
CSIv2::Component::encode(CORBA::DataEncoder& encoder) const
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "CSIv2::Component::encode(CORBA::DataEncoder& encoder) const"
	    << endl
	    << "stateful: " << (short)csml_.stateful << endl;
    assert(!CORBA::is_nil(codec_));
    _marshaller_CSIIOP_CompoundSecMechList->marshal(encoder, (void*)&csml_);
//      CORBA::Any any;
//      any <<= csml_;
//      CORBA::OctetSeq* t_buf = codec_->encode_value(any);
//      CORBA::Octet* t_octets = new CORBA::Octet[t_buf->length()];
//      for (CORBA::ULong i=0; i<t_buf->length(); i++) {
//  	t_octets[i] = ((*t_buf)[i]);
//  	cerr << (short)t_octets[i] << ", ";
//      }
//      encoder.put_octets(t_octets, t_buf->length());
}

CORBA::Component::ComponentId
CSIv2::Component::id() const
{
    return CSIIOP::TAG_CSI_SEC_MECH_LIST;
}

void
CSIv2::Component::print(ostream& out) const
{
    out << endl;
    out << "              ";
    out << "CSIv2:" << endl;
    out << "              ";
    out << "ComponentId: TAG_CSI_SEC_MECH_LIST" << endl;
    out << "              ";
    out << "   Stateful: ";
    if (csml_.stateful)
	out << "true" << endl;
    else
	out << "false" << endl;
    out << "              ";
    out << "     Length: " << csml_.mechanism_list.length() << endl;
    for (CORBA::ULong i=0; i<csml_.mechanism_list.length(); i++) {
	out << "              ";
	out << "        [" << i << "]: ";
	//out << "              ";
	//out << "              ";
	out << "target_requires: "
	    << csml_.mechanism_list[i].target_requires << endl;
	out << "              ";
	out << "            ";
	out << " transport_mech:  tag: ";
	if (csml_.mechanism_list[i].transport_mech.tag == CSIIOP::TAG_NULL_TAG)
	    out << "TAG_NULL_TAG" << endl;
	else if (csml_.mechanism_list[i].transport_mech.tag
		 == CSIIOP::TAG_SECIOP_SEC_TRANS) {
	    out << "TAG_SECIOP_SEC_TRANS" << endl;
	    out << "              ";
	    out << "              ";
	    out << "             ";
	    out << "  data: `";
	    for (CORBA::ULong j=0;
		 j<csml_.mechanism_list[i].transport_mech
		     .component_data.length();
		 j++) {
		CORBA::Octet c = csml_.mechanism_list[i]
		    .transport_mech.component_data[j];
		if (isprint(c))
		    out << (char)c;
		else
		    out << '.';
	    }
	    out << "'" << endl;
	}
	else if (csml_.mechanism_list[i].transport_mech.tag
		 == CSIIOP::TAG_TLS_SEC_TRANS) {
	    out << "TAG_TLS_SEC_TRANS" << endl;
	    out << "              ";
	    out << "              ";
	    out << "              ";
	    out << "       ";
	    CORBA::Any tc_any;
	    CSIIOP::TLS_SEC_TRANS tls_sec_trans;
	    tc_any <<= tls_sec_trans;
	    CORBA::OctetSeq tls_comp_data
		= csml_.mechanism_list[i].transport_mech.component_data;
	    CORBA::Any* tls_sec_trans_any
		= codec_->decode_value(tls_comp_data, tc_any.type());
	    (*tls_sec_trans_any) >>= tls_sec_trans;
	    out << "target supports: " << tls_sec_trans.target_supports << endl;
	    out << "              ";
	    out << "              ";
	    out << "              ";
	    out << "       ";
	    out << "target requires: " << tls_sec_trans.target_requires << endl;
	    out << "              ";
	    out << "              ";
	    out << "              ";
	    out << "       ";
	    for (CORBA::ULong j = 0; j<tls_sec_trans.addresses.length(); j++) {
		out << "addresses: ";
		out << tls_sec_trans.addresses[j].host_name;
		out << ":";
		out << tls_sec_trans.addresses[j].port;
		if (j+1 < tls_sec_trans.addresses.length())
		    out << ", ";
	    }
	    out << endl;
	}
	else {
	    out << "Unknown tag: "
		<< csml_.mechanism_list[i].transport_mech.tag << endl;
	    out << "              ";
	    out << "              ";
	    out << "             ";
	    out << "  data: `";
	    for (CORBA::ULong j=0;
		 j<csml_.mechanism_list[i]
		     .transport_mech.component_data.length();
		 j++) {
		CORBA::Octet c
		    = csml_.mechanism_list[i].transport_mech.component_data[j];
		if (isprint(c))
		    out << (char)c;
		else
		    out << '.';
	    }
	    out << "'" << endl;
	}
	// AS_ContextSec as_context_mech;
	if (csml_.mechanism_list[i].as_context_mech.target_supports == 0) {
	    out << "              ";
	    out << "             ";
	    out << "as_context_mech.target_supports = 0" << endl;
	}
	else {
	    CSIIOP::AS_ContextSec cs = csml_.mechanism_list[i].as_context_mech;
	    out << "              ";
	    out << "             ";
	    out << "as_context_mech.target_supports: ";
	    out << cs.target_supports << endl;
	    out << "              ";
	    out << "             ";
	    out << "as_context_mech.target_requires: ";
	    out << cs.target_requires << endl;
	    out << "              ";
	    out << "             ";
	    out << "as_context_mech.client_authentication_mech: ";
	    string str = ASN1::Codec::decode_oid(cs.client_authentication_mech);
	    out << str;
	    if (str == GSSUP::GSSUPMechOID)
		out << " (GSSUP::GSSUPMechOID)";
	    else if (str == CSI::KRB5MechOID)
		out << " (CSI::KRB5MechOID)";
	    else if (str == CSI::GSS_NT_Export_Name_OID)
		out << " (CSI::GSS_NT_Export_Name_OID)";
	    else if (str == CSI::GSS_NT_Scoped_Username_OID)
		out << " (CSI::GSS_NT_Scoped_Username_OID)";
	    out << endl;
	    out << "              ";
	    out << "             ";
	    out << "as_context_mech.target_name: `";
	    for (CORBA::ULong j=0; j<cs.target_name.length(); j++) {
		CORBA::Octet c = cs.target_name[j];
		if (isprint(c))
		    out << (char)c;
		else
		    out << '.';
	    }
	    out << "'" << endl;
	}
	if (csml_.mechanism_list[i].sas_context_mech.target_supports == 0) {
	    out << "              ";
	    out << "             ";
	    out << "sas_context_mech.target_supports = 0" << endl;
	}
	else {
	    CSIIOP::SAS_ContextSec scs
		= csml_.mechanism_list[i].sas_context_mech;
	    out << "              ";
	    out << "             ";
	    out << "sas_context_mech.target_supports: ";
	    out << scs.target_supports << endl;
	    out << "              ";
	    out << "             ";
	    out << "sas_context_mech.target_requires: ";
	    out << scs.target_requires << endl;
	    CSIIOP::ServiceConfigurationList pa = scs.privilege_authorities;
	    CORBA::ULong j;
	    for (j=0; j<pa.length(); j++) {
		out << "              ";
		out << "             ";
		out << "sas_context_mech.privilege_authorities[";
		out << j << "].syntax: " << pa[j].syntax << endl;
		out << "              ";
		out << "             ";
#ifdef USE_SL3
		if (pa[j].syntax != ATLAS::SCS_ATLAS) {
#endif // USE_SL3
		    out << "sas_context_mech.privilege_authorities[";
		    out << j << "].name: `";
		    for (CORBA::ULong k=0; k<pa[j].name.length(); k++) {
			CORBA::Octet c = pa[j].name[k];
			if (isprint(c))
			    out << (char)c;
			else
			    out << '.';
		    }
		    out << "'" << endl;
#ifdef USE_SL3
		}
		else {
		    // ATLAS profile
		    CORBA::Any* any = codec_->decode_value
			(pa[j].name, ATLAS::_tc_ATLASProfile);
		    if (any != NULL) {
			ATLAS::ATLASProfile prof;
			CORBA::Boolean result;
			result = ((*any) >>= prof);
			assert(result);
			CORBA::ULong dis = prof.the_locator._d();
			if (dis == ATLAS::ATLASObject) {
			    ATLAS::AuthTokenDispenser_var dispenser
				= ATLAS::AuthTokenDispenser::_duplicate
				(prof.the_locator.the_dispenser());
			    assert(!CORBA::is_nil(dispenser));
			    out << "sas_context_mech.privilege_authorities[";
			    out << j << "].name: ATLASLocator with ATLAS object reference:" << endl << endl;
			    string atlas_iordump = "";
			    ostringstream ostr;
			    dispenser->_ior()->print(ostr);
			    atlas_iordump = ostr.str();
			    CORBA::ULong pos = 0;
			    while ((pos = atlas_iordump.find('\n')) != string::npos) {
				string nstr = atlas_iordump.substr(0, pos);
				out << "                               " << nstr << endl;
				string tmp = atlas_iordump;
				atlas_iordump = tmp.substr(pos + 1, tmp.length() - 1);
			    }
			    out << endl << endl;
			}
			else {
			    // unsupported type in MICO SL3
			    out << "sas_context_mech.privilege_authorities[";
			    out << j << "].name: `";
			    for (CORBA::ULong k=0; k<pa[j].name.length(); k++) {
				CORBA::Octet c = pa[j].name[k];
				if (isprint(c))
				    out << (char)c;
				else
				    out << '.';
			    }
			    out << "'" << endl;
			}
		    }
		}
#endif // USE_SL3
	    }
	    CSI::OIDList oid_list = scs.supported_naming_mechanisms;
	    for (j=0; j<oid_list.length(); j++) {
		out << "              ";
		out << "             ";
		out << "sas_context_mech.supported_naming_mechanisms[";
		out << j << "]: ";
		string str = ASN1::Codec::decode_oid(oid_list[j]);
		out << str;
		if (str == GSSUP::GSSUPMechOID)
		    out << " (GSSUP::GSSUPMechOID)";
		else if (str == CSI::KRB5MechOID)
		    out << " (CSI::KRB5MechOID)";
		else if (str == CSI::GSS_NT_Export_Name_OID)
		    out << " (CSI::GSS_NT_Export_Name_OID)";
		else if (str == CSI::GSS_NT_Scoped_Username_OID)
		    out << " (CSI::GSS_NT_Scoped_Username_OID)";
		out << endl;
	    }
	    out << "              ";
	    out << "             ";
	    out << "sas_context_mech.supported_identity_types: ";
	    out << scs.supported_identity_types << endl;
	}
    }
    out << endl;
}

CORBA::Component*
CSIv2::Component::clone() const
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "CSIv2::Component::clone() const" << endl;
    return new CSIv2::Component(*this);
}

CORBA::Long
CSIv2::Component::compare(const CORBA::Component& component) const
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "CSIv2::Component::compare(const CORBA::Component& component)"
	    << " const" << endl;
    if (this->id() != component.id())
	return (CORBA::Long)this->id() - (CORBA::Long)component.id();
    return 0;
}

CORBA::Boolean
CSIv2::Component::operator==(const CORBA::Component& component) const
{
    return this->compare (component) == 0;
}

CORBA::Boolean
CSIv2::Component::operator<(const CORBA::Component& component) const
{
    return this->compare (component) < 0;
}

void
CSIv2::Component::codec(IOP::Codec_ptr codec)
{
    if (!CORBA::is_nil(codec_))
	CORBA::release(codec_);
    codec_ = IOP::Codec::_duplicate(codec);
}

CSIIOP::CompoundSecMechList*
CSIv2::Component::mech_list()
{
    return &csml_;
}

CSIv2::ComponentDecoder::ComponentDecoder()
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "CSIv2::ComponentDecoder::ComponentDecoder()" << endl;
    CORBA::Component::register_decoder(this);
}

CSIv2::ComponentDecoder::~ComponentDecoder()
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "CSIv2::ComponentDecoder::~ComponentDecoder()" << endl;
    CORBA::Component::unregister_decoder(this);
}

CORBA::Component*
CSIv2::ComponentDecoder::decode
(CORBA::DataDecoder& decoder,
 ComponentId id,
 CORBA::ULong length) const
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "CSIv2::ComponentDecoder::decode(...):"
	    << " length(" << length << ")" << endl;
    CSIIOP::CompoundSecMechList list;
    _marshaller_CSIIOP_CompoundSecMechList->demarshal(decoder, &list);
    CSIv2::Component* comp = new CSIv2::Component(list, codec_);
    if (MICO::Logger::IsLogged(MICO::Logger::Security))
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "comp: " << comp << endl;
    return comp;
//      CORBA::Octet* t_buf = new CORBA::Octet[length];
//      if (!decoder.get_octets(t_buf, length)) {
//  	cerr << "return NULL;" << endl;
//  	return NULL;
//      }
//      CORBA::OctetSeq seq;
//      seq.length(length);
//      for (CORBA::ULong i=0; i<length; i++) {
//  	seq[i] = t_buf[i];
//  	cerr << (short)seq[i] << ", ";
//      }
//      assert(!CORBA::is_nil(codec_));
//      CORBA::Any t_any;
//      CSIIOP::CompoundSecMechList list;
//      t_any <<= list;
//      CORBA::TypeCode_ptr tc = t_any.type();
//      assert(!CORBA::is_nil(tc));
//      CORBA::Any* any = codec_->decode_value(seq, tc);
//      (*any) >>= list;
//      CSIv2::Component* comp = new CSIv2::Component(list, codec_);
//      cerr << "comp: " << comp << endl;
//      return comp;
}

CORBA::Boolean
CSIv2::ComponentDecoder::has_id(CORBA::Component::ComponentId id) const
{
    return id == CSIIOP::TAG_CSI_SEC_MECH_LIST;
}

void
CSIv2::ComponentDecoder::codec(IOP::Codec_ptr codec)
{
    codec_ = IOP::Codec::_duplicate(codec);
}
