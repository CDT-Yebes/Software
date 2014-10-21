//
//  MICO SL3 --- an Open Source SL3 implementation
//  Copyright (C) 2002, 2003, 2004, 2005, 2008 ObjectSecurity Ltd.
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
#include <mico/security/transportsecurity_impl.h>
#include <mico/security/sl3tcpip_impl.h>
#include <mico/security/sl3tls_impl.h>
#include <mico/security/sl3csi_impl.h>
#include <mico/security/sl3ipc_impl.h>
#include <mico/util.h>
#include <mico/impl.h>
#include <mico/ssl.h>
#endif // FAST_PCH

using namespace TransportSecurity;
using namespace SL3PM;
using namespace SL3CM;
using namespace SL3OM;
using namespace SL3OMExt;
using CORBA::ULongLong;
using CORBA::ULong;
using CORBA::Boolean;
using CORBA::String_var;
using CORBA::StringSeq;
using CORBA::Address;
using namespace TimeBase;
using namespace PortableInterceptor;
using namespace std;


//
// module initialization
//

void
MICOSL3_TransportSecurity::_init()
{
    PortableInterceptor::register_orb_initializer(new ORBInitializer());
}


//
// CredentialsInitiator_impl
//

Principal*
MICOSL3_TransportSecurity::CredentialsInitiator_impl::the_principal()
{
    CORBA::add_ref(principal_);
    return principal_;
}


StatementList*
MICOSL3_TransportSecurity::CredentialsInitiator_impl::supporting_statements()
{
    return new StatementList(statement_list_);
}


ResourceNameList*
MICOSL3_TransportSecurity::CredentialsInitiator_impl::restricted_resources()
{
    return new ResourceNameList(rsname_list_);
}


PrinAttributeList*
MICOSL3_TransportSecurity::CredentialsInitiator_impl::environmental_attributes()
{
    return new PrinAttributeList(environmental_attributes_);
}


Boolean
MICOSL3_TransportSecurity::CredentialsInitiator_impl::supports_embodiment()
{
    return supports_embodiment_;
}


Boolean
MICOSL3_TransportSecurity::CredentialsInitiator_impl::supports_endorsement()
{
    return supports_endorsement_;
}


Boolean
MICOSL3_TransportSecurity::CredentialsInitiator_impl::supports_quoting()
{
    return supports_quoting_;
}


Boolean
MICOSL3_TransportSecurity::CredentialsInitiator_impl::supports_client_authentication()
{
    return supports_client_authentication_;
}


Boolean
MICOSL3_TransportSecurity::CredentialsInitiator_impl::supports_target_authentication()
{
    return supports_target_authentication_;
}


Boolean
MICOSL3_TransportSecurity::CredentialsInitiator_impl::supports_confidentiality()
{
    return supports_confidentiality_;
}


Boolean
MICOSL3_TransportSecurity::CredentialsInitiator_impl::supports_integrity()
{
    return supports_integrity_;
}


TimeBase::UtcT
MICOSL3_TransportSecurity::CredentialsInitiator_impl::expiry_time()
{
    return expiry_time_;
}


//
// CredentialsAcceptor_impl
//

Principal*
MICOSL3_TransportSecurity::CredentialsAcceptor_impl::the_principal()
{
    CORBA::add_ref(principal_);
    return principal_;
}


StatementList*
MICOSL3_TransportSecurity::CredentialsAcceptor_impl::supporting_statements()
{
    return new StatementList(statement_list_);
}


ResourceNameList*
MICOSL3_TransportSecurity::CredentialsAcceptor_impl::restricted_resources()
{
    return new ResourceNameList(rsname_list_);
}


PrinAttributeList*
MICOSL3_TransportSecurity::CredentialsAcceptor_impl::environmental_attributes()
{
    return new PrinAttributeList(environmental_attributes_);
}


Boolean
MICOSL3_TransportSecurity::CredentialsAcceptor_impl::supports_endorsement()
{
    return supports_endorsement_;
}


Boolean
MICOSL3_TransportSecurity::CredentialsAcceptor_impl::supports_quoting()
{
    return supports_quoting_;
}


Boolean
MICOSL3_TransportSecurity::CredentialsAcceptor_impl::supports_client_authentication()
{
    return supports_client_authentication_;
}


Boolean
MICOSL3_TransportSecurity::CredentialsAcceptor_impl::supports_target_authentication()
{
    return supports_target_authentication_;
}


Boolean
MICOSL3_TransportSecurity::CredentialsAcceptor_impl::supports_confidentiality()
{
    return supports_confidentiality_;
}


Boolean
MICOSL3_TransportSecurity::CredentialsAcceptor_impl::supports_integrity()
{
    return supports_integrity_;
}


TimeBase::UtcT
MICOSL3_TransportSecurity::CredentialsAcceptor_impl::expiry_time()
{
    return expiry_time_;
}


//
// TransportCredentials_impl
//

MICOSL3_TransportSecurity::TransportCredentials_impl::TransportCredentials_impl()
    : creds_id_(""), creds_state_(SL3CM::CS_Initialized)
{
}


MICOSL3_TransportSecurity::TransportCredentials_impl::TransportCredentials_impl
(const char* id,
 CredentialsState state,
 CredentialsType type,
 CredentialsUsage usage,
 TimeBase::UtcT time)
    : creds_id_(id), creds_state_(state), creds_type_(type), creds_usage_(usage), expiry_time_(time)
{
    //cerr << "TransportCredentials_impl ctor: id == " << id << endl;
    //cerr << "TransportCredentials_impl ctor: creds_id_ == " << creds_id_.in() << endl;
}


char*
MICOSL3_TransportSecurity::TransportCredentials_impl::creds_id()
{
    return CORBA::string_dup(creds_id_.in());
}


CredentialsState
MICOSL3_TransportSecurity::TransportCredentials_impl::creds_state()
{
    return creds_state_;
}


CredentialsType
MICOSL3_TransportSecurity::TransportCredentials_impl::creds_type()
{
    return creds_type_;
}


CredentialsUsage
MICOSL3_TransportSecurity::TransportCredentials_impl::creds_usage()
{
    return creds_usage_;
}


UtcT
MICOSL3_TransportSecurity::TransportCredentials_impl::expiry_time()
{
    return expiry_time_;
}


// extension
void
MICOSL3_TransportSecurity::TransportCredentials_impl::creds_state(CredentialsState state)
{
    creds_state_ = state;
}


//
// OwnCredentials_impl
//

MICOSL3_TransportSecurity::OwnCredentials_impl::OwnCredentials_impl
(const char* id,
 CredentialsState state,
 CredentialsType type,
 CredentialsUsage usage,
 TimeBase::UtcT time,
 TransportSecurity::CredentialsInitiator_ptr initiator,
 TransportSecurity::CredentialsAcceptor_ptr acceptor,
 Boolean csiv1_support,
 Boolean csiv2_support,
 const ObserverSeq& observers)
    : TransportCredentials_impl(id, state, type, usage, time)
{
    initiator_ = CredentialsInitiator::_duplicate(initiator);
    acceptor_ = CredentialsAcceptor::_duplicate(acceptor);
    csiv1_support_ = csiv1_support;
    csiv2_support_ = csiv2_support;
    observers_ = observers;
    for (CORBA::ULong i = 0; i < observers_.length(); i++) {
	CredentialsObserver_var creds_observer = CredentialsObserver::_narrow
	    (observers_[i]);
	if (!CORBA::is_nil(creds_observer)) {
	    credentials_observers_.push_back(creds_observer);
	    CredentialsDestroyObserver_var dtor_observer
		= CredentialsDestroyObserver::_narrow(observers_[i]);
	    if (!CORBA::is_nil(dtor_observer)) {
		destroy_observers_.push_back(dtor_observer);
	    }
	}
    }
}

MICOSL3_TransportSecurity::OwnCredentials_impl::~OwnCredentials_impl()
{
    //cerr << "~OwnCredentials_impl dtor: " << this << endl;
    this->notify_destroy();
}

CredentialsInitiator_ptr
MICOSL3_TransportSecurity::OwnCredentials_impl::the_initiator()
{
    return CredentialsInitiator::_duplicate(initiator_);
}


CredentialsAcceptor_ptr
MICOSL3_TransportSecurity::OwnCredentials_impl::the_acceptor()
{
    return CredentialsAcceptor::_duplicate(acceptor_);
}


Boolean
MICOSL3_TransportSecurity::OwnCredentials_impl::supports_csi_version(CSIVersion version)
{
    if (version == TransportSecurity::CSIv1 && csiv1_support_)
	return TRUE;
    if (version == TransportSecurity::CSIv2 && csiv2_support_)
	return TRUE;
    return FALSE;
}


void
MICOSL3_TransportSecurity::OwnCredentials_impl::release_credentials()
{
    CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
    CORBA::Object_var obj = orb->resolve_initial_references
	("TransportSecurity::SecurityManager");
    SecurityManager_var secman = SecurityManager::_narrow(obj);
    assert(!CORBA::is_nil(secman));
    CredentialsCurator_var curator = secman->credentials_curator();
    assert(!CORBA::is_nil(curator));
    CORBA::String_var id = this->creds_id();
    curator->release_credentials(id);
}


void
MICOSL3_TransportSecurity::OwnCredentials_impl::externalize_credentials
(const char* externalization_type,
 const char* dest_url)
{
    assert(0);
}

// extension

ObserverSeq*
MICOSL3_TransportSecurity::OwnCredentials_impl::observers()
{
    return new ObserverSeq(observers_);
}


void
MICOSL3_TransportSecurity::OwnCredentials_impl::notify_creation()
{
    CORBA::String_var creds_id = this->creds_id();
    for (CORBA::ULong i = 0; i < credentials_observers_.size(); i++) {
	credentials_observers_[i]->create_credentials(creds_id);
    }
}


void
MICOSL3_TransportSecurity::OwnCredentials_impl::notify_remove()
{
    CORBA::String_var creds_id = this->creds_id();
    for (CORBA::ULong i = 0; i < credentials_observers_.size(); i++) {
	credentials_observers_[i]->relinquish_credentials(creds_id);
    }
}


void
MICOSL3_TransportSecurity::OwnCredentials_impl::notify_destroy()
{
    CORBA::String_var creds_id = this->creds_id();
    for (CORBA::ULong i = 0; i < destroy_observers_.size(); i++) {
	destroy_observers_[i]->destroy_credentials(creds_id);
    }
}


//
// ClientCredentials_impl
//

MICOSL3_TransportSecurity::ClientCredentials_impl::ClientCredentials_impl
(OwnCredentials_ptr parent_credentials)
    : parent_credentials_(OwnCredentials::_duplicate(parent_credentials))
{
}


char*
MICOSL3_TransportSecurity::ClientCredentials_impl::context_id()
{
    return CORBA::string_dup(context_id_.in());
}


Principal*
MICOSL3_TransportSecurity::ClientCredentials_impl::client_principal()
{
    return client_principal_;
}


StatementList*
MICOSL3_TransportSecurity::ClientCredentials_impl::client_supporting_statements()
{
    return new StatementList(client_supporting_statements_);
}


ResourceNameList*
MICOSL3_TransportSecurity::ClientCredentials_impl::client_restricted_resources()
{
    return new ResourceNameList(client_restricted_resources_);
}


Principal*
MICOSL3_TransportSecurity::ClientCredentials_impl::target_principal()
{
    return target_principal_;
}


StatementList*
MICOSL3_TransportSecurity::ClientCredentials_impl::target_supporting_statements()
{
    return new StatementList(target_supporting_statements_);
}


ResourceNameList*
MICOSL3_TransportSecurity::ClientCredentials_impl::target_restricted_resources()
{
    return new ResourceNameList(target_restricted_resources_);
}


PrinAttributeList*
MICOSL3_TransportSecurity::ClientCredentials_impl::environmental_attributes()
{
    return new PrinAttributeList(environmental_attributes_);
}


TransportSecurity::OwnCredentials_ptr
MICOSL3_TransportSecurity::ClientCredentials_impl::parent_credentials()
{
    return OwnCredentials::_duplicate(parent_credentials_);
}


Boolean
MICOSL3_TransportSecurity::ClientCredentials_impl::client_authentication()
{
    return client_authentication_;
}


Boolean
MICOSL3_TransportSecurity::ClientCredentials_impl::target_authentication()
{
    return target_authentication_;
}


Boolean
MICOSL3_TransportSecurity::ClientCredentials_impl::confidentiality()
{
    return confidentiality_;
}


Boolean
MICOSL3_TransportSecurity::ClientCredentials_impl::integrity()
{
    return integrity_;
}


Boolean
MICOSL3_TransportSecurity::ClientCredentials_impl::impersonable()
{
    return impersonable_;
}


Boolean
MICOSL3_TransportSecurity::ClientCredentials_impl::endorseable()
{
    return endorseable_;
}


Boolean
MICOSL3_TransportSecurity::ClientCredentials_impl::quotable()
{
    return quotable_;
}


//
// TargetCredentials_impl
//

MICOSL3_TransportSecurity::TargetCredentials_impl::TargetCredentials_impl
(OwnCredentials_ptr parent_credentials)
    : parent_credentials_(OwnCredentials::_duplicate(parent_credentials))
{
}


char*
MICOSL3_TransportSecurity::TargetCredentials_impl::context_id()
{
    return CORBA::string_dup(context_id_.in());
}


Principal*
MICOSL3_TransportSecurity::TargetCredentials_impl::client_principal()
{
    CORBA::add_ref(client_principal_);
    return client_principal_;
}


StatementList*
MICOSL3_TransportSecurity::TargetCredentials_impl::client_supporting_statements()
{
    return new StatementList(client_supporting_statements_);
}


ResourceNameList*
MICOSL3_TransportSecurity::TargetCredentials_impl::client_restricted_resources()
{
    return new ResourceNameList(client_restricted_resources_);
}


Principal*
MICOSL3_TransportSecurity::TargetCredentials_impl::target_principal()
{
    CORBA::add_ref(target_principal_);
    return target_principal_;
}


StatementList*
MICOSL3_TransportSecurity::TargetCredentials_impl::target_supporting_statements()
{
    return new StatementList(target_supporting_statements_);
}


ResourceNameList*
MICOSL3_TransportSecurity::TargetCredentials_impl::target_restricted_resources()
{
    return new ResourceNameList(target_restricted_resources_);
}


PrinAttributeList*
MICOSL3_TransportSecurity::TargetCredentials_impl::environmental_attributes()
{
    return new PrinAttributeList(environmental_attributes_);
}


TransportSecurity::OwnCredentials_ptr
MICOSL3_TransportSecurity::TargetCredentials_impl::parent_credentials()
{
    return TransportSecurity::OwnCredentials::_duplicate(parent_credentials_);
}


Boolean
MICOSL3_TransportSecurity::TargetCredentials_impl::client_authentication()
{
    return client_authentication_;
}


Boolean
MICOSL3_TransportSecurity::TargetCredentials_impl::target_authentication()
{
    return target_authentication_;
}


Boolean
MICOSL3_TransportSecurity::TargetCredentials_impl::confidentiality()
{
    return confidentiality_;
}


Boolean
MICOSL3_TransportSecurity::TargetCredentials_impl::integrity()
{
    return integrity_;
}


Boolean
MICOSL3_TransportSecurity::TargetCredentials_impl::target_embodied()
{
    return target_embodied_;
}


Boolean
MICOSL3_TransportSecurity::TargetCredentials_impl::target_endorsed()
{
    return target_endorsed_;
}


//
// CredentialsCurator_impl
//
OwnCredentialsList*
MICOSL3_TransportSecurity::CredentialsCurator_impl::default_creds_list()
{
    return new OwnCredentialsList(default_creds_list_);
}


CredentialsAcquirer_ptr
MICOSL3_TransportSecurity::CredentialsCurator_impl::acquire_credentials
(SL3AQArgs::Argument_ptr acquisition_arguments)
{
    CredentialsAcquirerFactory_ptr fact = CredentialsAcquirerFactory::_nil();
    for (fact_iter_type i = factories_.begin(); i != factories_.end(); i++) {
  	if ((*i)->supports_all_args(acquisition_arguments)) {
  	    fact = (*i);
  	    break;
  	}
    }
    assert(!CORBA::is_nil(fact));
    CredentialsAcquirer_ptr ca = fact->create(acquisition_arguments);
    CredentialsCuratorImplUser* user = dynamic_cast
	<MICOSL3_TransportSecurity::CredentialsCuratorImplUser*>(ca);
    assert(user != NULL);
    user->creds_curator_impl(this);
    return ca;
}


OwnCredentials_ptr
MICOSL3_TransportSecurity::CredentialsCurator_impl::get_own_credentials
(const char* creds_id)
{
    //cerr << "MICOSL3_TransportSecurity::CredentialsCurator_impl::get_own_credentials(" << creds_id << ")" << endl;
    String_var id = "";
    for (ULong i = 0; i < own_creds_list_.length(); i++) {
	id = own_creds_list_[i]->creds_id();
	//cerr << i << ":" << id << endl;
	if (strcmp(id.in(), creds_id) == 0) {
	    return OwnCredentials::_duplicate(own_creds_list_[i]);
	}
    }
    //cerr << "NIL returned" << endl;
    return OwnCredentials::_nil();
}


void
MICOSL3_TransportSecurity::CredentialsCurator_impl::remove_credentials
(const char* creds_id)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3TS: remove_credentials: " << creds_id << endl;
    }
    CORBA::String_var id = "";
    CORBA::Boolean found = FALSE;
    for (CORBA::ULong i = 0; i < default_creds_list_.length(); i++) {
	id = default_creds_list_[i]->creds_id();
	if (strcmp(id.in(), creds_id) == 0) {
	    found = TRUE;
	    // in case of acceptor we have to shutdown accepting
	    // transport server
	    CredentialsAcceptor_var acceptor = default_creds_list_[i]->the_acceptor();
	    TransportAcceptor_impl* tsacceptor
		= dynamic_cast<MICOSL3_TransportSecurity::TransportAcceptor_impl*>
		(acceptor.in());
	    if (tsacceptor != NULL) {
		tsacceptor->shutdown();
	    }
	    OwnCredentials_impl* creds_impl
		= dynamic_cast<OwnCredentials_impl*>
		(default_creds_list_[i].in());
	    assert(creds_impl != NULL);
	    creds_impl->notify_remove();
	    break;
	}
    }
    if (!found) {
	mico_throw(CORBA::BAD_PARAM(20001, CORBA::COMPLETED_NO));
    }
    this->remove_creds_from_default_creds_list(creds_id);
}


void
MICOSL3_TransportSecurity::CredentialsCurator_impl::release_credentials
(const char* creds_id)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3TS: release_credentials: " << creds_id << endl;
    }
    OwnCredentials_var creds = this->get_own_credentials(creds_id);
    if (CORBA::is_nil(creds)) {
	mico_throw(CORBA::BAD_PARAM(20002, CORBA::COMPLETED_NO));
    }
    try {
	// first of all, we need to remove credentials
	// this also shutdowns appropriate transport server
	this->remove_credentials(creds_id);
    } catch (const CORBA::BAD_PARAM& ex) {
	// ok, creds are already removed
    }
    TransportCredentials_impl* tscreds
	= dynamic_cast<MICOSL3_TransportSecurity::TransportCredentials_impl*>
	(creds.in());
    assert(tscreds != NULL);
    tscreds->creds_state(SL3CM::CS_PendingRelease);
    // remove creds from own_creds_list_
    this->remove_creds_from_own_creds_list(creds_id);
    // release references of depending initiating contexts
    // i.e. target credentials
    for (ic_iter_type it = init_contexts_.begin();
	 it != init_contexts_.end(); ) {
	OwnCredentials_var tcr = (*it)->parent_credentials();
	CORBA::String_var parent_id = tcr->creds_id();
	if (strcmp(parent_id.in(), creds_id) == 0) {
	    it = init_contexts_.erase(it);
	}
	else {
	    it++;
	}
    }
}

// extension
void
MICOSL3_TransportSecurity::CredentialsCurator_impl::register_acquirer_factory
(CredentialsAcquirerFactory_ptr factory)
{
    factories_.push_back(CredentialsAcquirerFactory::_duplicate(factory));
}


void
MICOSL3_TransportSecurity::CredentialsCurator_impl::add_own_credentials
(OwnCredentials_ptr creds, Boolean on_list)
{
    own_creds_list_.length(own_creds_list_.length() + 1);
    own_creds_list_[own_creds_list_.length() - 1]
	= OwnCredentials::_duplicate(creds);
    if (on_list) {
	default_creds_list_.length(default_creds_list_.length() + 1);
	default_creds_list_[default_creds_list_.length() - 1]
	    = OwnCredentials::_duplicate(creds);
    }
}


void
MICOSL3_TransportSecurity::CredentialsCurator_impl::add_init_context
(InitiatingContext_ptr ctx)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "CredentialsCurator_impl::add_init_context: " << ctx << endl;
    }
    init_contexts_.push_back(TransportSecurity::InitiatingContext::_duplicate(ctx));
}


TargetCredentials_ptr
MICOSL3_TransportSecurity::CredentialsCurator_impl::get_target_credentials
(CORBA::Object_ptr obj,
 CORBA::Boolean include_ipc_creds)
{
    TargetCredentials_ptr result = TargetCredentials::_nil();
    const CORBA::Address* tcpip_target_addr = obj->_ior()->addr
	(CORBA::IORProfile::TAG_INTERNET_IOP);
    const CORBA::Address* tls_target_addr = obj->_ior()->addr
	(CORBA::IORProfile::TAG_SSL_INTERNET_IOP);
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3TS: CredentialsCurator_impl::get_target_credentials" << endl;
	if (tcpip_target_addr != NULL)
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "       tcpip_target_addr: " << tcpip_target_addr->stringify() << endl;
	if (tls_target_addr != NULL)
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "       tls_target_addr: " << tls_target_addr->stringify() << endl;
    }
    CredentialsIdList creds_ids(0);
    OwnCredentialsList_var creds_list = NULL;
    ContextEstablishmentPolicy_var policy
	= ContextEstablishmentPolicy::_nil();
    SecurityLevel3::ContextEstablishmentPolicy_var sl3_policy
	= SecurityLevel3::ContextEstablishmentPolicy::_nil();
    // we try transport policy first
    try {
	CORBA::Policy_var p = obj->_get_policy(ContextEstablishmentPolicyType);
	policy = ContextEstablishmentPolicy::_narrow(p);
    } catch (CORBA::BAD_PARAM&) {
	// this is thrown by MICO and CORBA 2.2. It seems MICO
	// is not compliant here with CORBA 2.3.
    } catch (CORBA::SystemException) {
	// CORBA 2.3 and highers might throw either INV_POLICY
	// or BAD_INV_ORDER exceptions
    }
    // and security level3 policy as the second
    try {
	CORBA::Policy_var p = obj->_get_policy
	    (SecurityLevel3::ContextEstablishmentPolicyType);
	sl3_policy = SecurityLevel3::ContextEstablishmentPolicy::_narrow(p);
    } catch (CORBA::BAD_PARAM&) {
	// this is thrown by MICO and CORBA 2.2. It seems MICO
	// is not compliant here with CORBA 2.3.
    } catch (CORBA::SystemException) {
	// CORBA 2.3 and highers might throw either INV_POLICY
	// or BAD_INV_ORDER exceptions
    }
    if (!CORBA::is_nil(policy)) {
	// there are credentials set directly on this object reference
	//cerr << "use policy's creds list" << endl;
	creds_list = policy->creds_list();
    }
    else if (!CORBA::is_nil(sl3_policy)) {
	// there are credentials set directly on this object reference
	// but in the form of CSI creds => we need to transform this list
	// to the list of underlaying transport creds
	//cerr << "use securitylevel3 policy's creds list" << endl;
	SecurityLevel3::OwnCredentialsList_var sl3_creds_list
	    = sl3_policy->creds_list();
	//cerr << "sl3_creds_list->length(): " << sl3_creds_list->length()
	//<< endl;
	creds_list = new OwnCredentialsList;
	creds_list->length(0);
	for (CORBA::ULong i = 0; i < sl3_creds_list->length(); i++) {
	    SecurityLevel3::CredsInitiator_var init
		= sl3_creds_list[i]->creds_initiator();
	    if (!CORBA::is_nil(init)) {
		MICOSL3_SL3CSI::CSICredsInitiator* csi_init
		    = dynamic_cast<MICOSL3_SL3CSI::CSICredsInitiator*>
		    (init.in());
		if (csi_init != NULL) {
		    // so finally we have CSICredsInitiator and we can
		    // obtain underlaying transport credentials
		    creds_list->length(creds_list->length() + 1);
		    creds_list[creds_list->length() - 1]
			= csi_init->transport_credentials();
		    //cerr << "found: " << creds_list[creds_list->length() - 1]->creds_id() << endl;
		}
	    }
	}
    }
    else {
	// we will use default credentials
	//cerr << "default creds list used" << endl;
	creds_list = this->default_creds_list();
    }
    // we need just ids
    creds_ids.length(creds_list->length());
    for (ULong i = 0; i < creds_list->length(); i++) {
	creds_ids[i] = creds_list[i]->creds_id();
    }
//      if (strcmp("inet", target_addr->proto()) == 0
//  	||strcmp("inet-dgram", target_addr->proto()) == 0) {
//      cerr << "tcpip target" << endl;
    for (ULong j = 0; j < creds_ids.length(); j++) {
	for (ic_iter_type i = init_contexts_.begin();
	     i != init_contexts_.end();
	     i++) {
	    MICOSL3_SL3TCPIP::TCPIPInitiatingContext* tcpip_ic
		= dynamic_cast<MICOSL3_SL3TCPIP::TCPIPInitiatingContext*>((*i).in());
	    MICOSL3_SL3TLS::TLSInitiatingContext* tls_ic
		= dynamic_cast<MICOSL3_SL3TLS::TLSInitiatingContext*>((*i).in());
	    //cerr << "ic: " << ic << endl;
	    //if (ic != NULL)
	    //cerr << "ic->target_addr(): " << ic->target_addr()->stringify() << endl;
	    OwnCredentials_var parent = (*i).in()->parent_credentials();
	    String_var id = parent->creds_id();
	    //cerr << "id: " << id.in() << endl;
	    //cerr << "creds_ids[j]: " << creds_ids[j].in() << endl;
	    if (((tcpip_ic != NULL
		  && tcpip_target_addr != NULL
		  && (*tcpip_target_addr) == (*(tcpip_ic->target_addr())))
		 || (tls_ic != NULL
		    && tls_target_addr != NULL
		    && (*tls_target_addr) == (*(tls_ic->target_addr()))))
		&& strcmp(creds_ids[j].in(), id.in()) == 0) {
		result = TargetCredentials::_duplicate((*i).in());
		if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
		    MICOMT::AutoDebugLock lock;
		    MICO::Logger::Stream(MICO::Logger::Security)
			<< "       found TargetCredentials(addr base): "
			<< result << endl;
		}
		break;
	    }
	}
    }
    if (CORBA::is_nil(result) && include_ipc_creds) {
	// we are not able to find appropriate TCPIP or TLS target credentials
	// but caller would also like to include IPC creds if possible
	// so we will try to find appropriate IPC target credentials now
	for (ULong j = 0; j < creds_ids.length(); j++) {
	    string key = creds_ids[j].in();
	    if (key.find("MICO_IPC:") != string::npos) {
		// found IPC own credentials
		TargetCredentials_ptr tmp_target
		    = MICOSL3_SL3IPC::IPCCredsMapper::self()
		    ->get_target_credentials(creds_list[j]);
		if (CORBA::is_nil(tmp_target)) {
		    // we need to create appropriate target credentials now
		    tmp_target = new MICOSL3_SL3IPC::IPCInitiatingContext
			(creds_list[j]);
		    MICOSL3_SL3IPC::IPCCredsMapper::self()
			->add_target_credentials(creds_list[j], tmp_target);
		}
		result = tmp_target;
		break;
	    }
	}
    }
//  }
//      if (strcmp("ssl", target_addr->proto()) == 0) {
//  	cerr << "ssl target" << endl;
//  	for (ULong j = 0; j < creds_ids.length(); j++) {
//  	    for (ic_iter_type i = init_contexts_.begin();
//  		 i != init_contexts_.end();
//  		 i++) {
//  		MICOSL3_SL3TLS::TLSInitiatingContext* ic
//  		    = dynamic_cast<MICOSL3_SL3TLS::TLSInitiatingContext*>((*i).in());
//  		//cerr << "ic: " << ic << endl;
//  		//if (ic != NULL)
//  		//cerr << "ic->target_addr(): " << ic->target_addr()->stringify() << endl;
//  		OwnCredentials_var parent = (*i).in()->parent_credentials();
//  		String_var id = parent->creds_id();
//  		cerr << "id: " << id.in() << endl;
//  		cerr << "creds_ids[j]: " << creds_ids[j].in() << endl;
//  		if (ic != NULL && (*target_addr) == (*(ic->target_addr()))
//  		    && strcmp(creds_ids[j].in(), id.in()) == 0) {
//  		    result = TargetCredentials::_duplicate(ic);
//  		    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
//  			MICOMT::AutoDebugLock lock;
//  			MICO::Logger::Stream(MICO::Logger::Security)
//  			    << "       found TargetCredentials(ssl addr base): "
//  			    << result << endl;
//  		    }
//  		    break;
//  		}
//  	    }
//  	}
//      }
    return result;
}


OwnCredentials_ptr
MICOSL3_TransportSecurity::CredentialsCurator_impl::find_own_credentials_for
(const Address* addr)
{
    //cerr << "find_own_credentials_for: " << addr->stringify() << endl;
    for (ULong i = 0; i < this->own_creds_list_.length(); i++) {
        CredentialsAcceptor_var acceptor
            = this->own_creds_list_[i]->the_acceptor();
        String_var id = this->own_creds_list_[i]->creds_id();
        if (!CORBA::is_nil(acceptor)) {
            MICOSL3_SL3TCPIP::TCPIPAcceptor* tcpip_acceptor
                = dynamic_cast<MICOSL3_SL3TCPIP::TCPIPAcceptor*>(acceptor.in());
//             if (tcpip_acceptor != NULL) {
//                 cerr << i << ". (" << id.in() << ") bound to: " << tcpip_acceptor->bound_addr()->stringify() << endl;
//             }
            if (tcpip_acceptor != NULL && strcmp(tcpip_acceptor->bound_addr()->proto(), addr->proto()) == 0) {
                const MICO::InetAddress* i_bound_addr = dynamic_cast<const MICO::InetAddress*>
                    (tcpip_acceptor->bound_addr());
                const MICO::InetAddress* i_addr = dynamic_cast<const MICO::InetAddress*>
                    (addr);
                assert(i_bound_addr != NULL);
                assert(i_addr != NULL);
                if ((*(i_bound_addr)) == (*i_addr)
                    || (strcmp(i_bound_addr->host(), "0.0.0.0") == 0
                        && strcmp(i_bound_addr->proto(), i_addr->proto()) == 0
                        && i_bound_addr->port() == i_addr->port())) {
                    return OwnCredentials::_duplicate(this->own_creds_list_[i]);
                }
            }
            MICOSL3_SL3TLS::TLSAcceptor* tls_acceptor
                = dynamic_cast<MICOSL3_SL3TLS::TLSAcceptor*>(acceptor.in());
            if (tls_acceptor != NULL && strcmp(tls_acceptor->bound_addr()->proto(), addr->proto()) == 0) {
                const MICOSSL::SSLAddress* ssl_bound_addr = dynamic_cast<const MICOSSL::SSLAddress*>
                    (tls_acceptor->bound_addr());
                const MICOSSL::SSLAddress* ssl_addr = dynamic_cast<const MICOSSL::SSLAddress*>
                    (addr);
                const MICO::InetAddress* i_bound_addr = dynamic_cast<const MICO::InetAddress*>
                    (ssl_bound_addr->content());
                const MICO::InetAddress* i_addr = dynamic_cast<const MICO::InetAddress*>
                    (ssl_addr->content());
                assert(ssl_bound_addr != NULL);
                assert(ssl_addr != NULL);
                assert(i_bound_addr != NULL);
                assert(i_addr != NULL);
                if ((*(ssl_bound_addr)) == (*ssl_addr)
                    || (strcmp(i_bound_addr->host(), "0.0.0.0") == 0
                        && strcmp(ssl_bound_addr->proto(), ssl_addr->proto()) == 0
                        && i_bound_addr->port() == i_addr->port())) {
                    return OwnCredentials::_duplicate(this->own_creds_list_[i]);
                }
            }
        }
    }
    return OwnCredentials::_nil();
}


void
MICOSL3_TransportSecurity::CredentialsCurator_impl::remove_creds_from_default_creds_list
(const char* creds_id)
{
    CORBA::LongLong ctx = -1;
    CORBA::String_var id = "";
    for (CORBA::ULong i = 0; i < default_creds_list_.length(); i++) {
	id = default_creds_list_[i]->creds_id();
	if (strcmp(id.in(), creds_id) == 0) {
	    ctx = i;
	    break;
	}
    }
    if (ctx > -1) {
	for (CORBA::ULong i = ctx; i < default_creds_list_.length() - 1; i++) {
	    default_creds_list_[i] = default_creds_list_[i + 1];
	}
	default_creds_list_.length(default_creds_list_.length() - 1);
    }
}


void
MICOSL3_TransportSecurity::CredentialsCurator_impl::remove_creds_from_own_creds_list
(const char* creds_id)
{
    CORBA::LongLong ctx = -1;
    CORBA::String_var id = "";
    for (CORBA::ULong i = 0; i < own_creds_list_.length(); i++) {
	id = own_creds_list_[i]->creds_id();
	if (strcmp(id.in(), creds_id) == 0) {
	    ctx = i;
	    break;
	}
    }
    if (ctx > -1) {
	for (CORBA::ULong i = ctx; i < own_creds_list_.length() - 1; i++) {
	    own_creds_list_[i] = own_creds_list_[i + 1];
	}
	own_creds_list_.length(own_creds_list_.length() - 1);
    }
}


//
// SecurityCurrent_impl
//

MICOSL3_TransportSecurity::SecurityCurrent_impl::SecurityCurrent_impl()
{
#ifdef HAVE_THREADS
    MICOMT::Thread::create_key(thread_key_, NULL);
#endif // HAVE_THREADS
}


ClientCredentials_ptr
MICOSL3_TransportSecurity::SecurityCurrent_impl::client_credentials()
{
#ifndef HAVE_THREADS
    if (!client_credentials_stack_.empty())
        return TransportSecurity::ClientCredentials::_duplicate(client_credentials_stack_.top());
    else
        return TransportSecurity::ClientCredentials::_nil();        
#else // HAVE_THREADS
    CCStack* stack = static_cast<CCStack*>(MICOMT::Thread::get_specific(thread_key_));
    if (stack != NULL && !stack->empty())
        return TransportSecurity::ClientCredentials::_duplicate(stack->top());
    else
        return TransportSecurity::ClientCredentials::_nil();
#endif // HAVE_THREADS
}


void
MICOSL3_TransportSecurity::SecurityCurrent_impl::push_client_credentials
(TransportSecurity::ClientCredentials_ptr creds)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3TS: SecurityCurrent_impl::push_client_credentials: " << creds << endl;
    }
#ifndef HAVE_THREADS
    client_credentials_stack_.push
        (TransportSecurity::ClientCredentials::_duplicate(creds));
#else // HAVE_THREADS
    CCStack* stack = static_cast<CCStack*>(MICOMT::Thread::get_specific(thread_key_));
    if (stack == NULL) {
        stack = new CCStack;
        MICOMT::Thread::set_specific(thread_key_, stack);
    }
    stack->push(TransportSecurity::ClientCredentials::_duplicate(creds));
#endif // HAVE_THREADS
}


void
MICOSL3_TransportSecurity::SecurityCurrent_impl::pop_client_credentials()
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3TS: SecurityCurrent_impl::pop_client_credentials" << endl;
    }
#ifndef HAVE_THREADS
    if (!client_credentials_stack_.empty())
        client_credentials_stack_.pop();
#else // HAVE_THREADS
    CCStack* stack = static_cast<CCStack*>(MICOMT::Thread::get_specific(thread_key_));
    if (stack == NULL) {
        stack = new CCStack;
        MICOMT::Thread::set_specific(thread_key_, stack);
    }
    if (!stack->empty())
        stack->pop();
#endif // HAVE_THREADS
}

//
// SecurityManager_impl
//

MICOSL3_TransportSecurity::SecurityManager_impl::SecurityManager_impl
(CredentialsCurator_impl* curator, Boolean enabled)
{
    curator_ = curator;
    security_enabled_ = enabled;
}


CredentialsCurator_ptr
MICOSL3_TransportSecurity::SecurityManager_impl::credentials_curator()
{
    return CredentialsCurator::_duplicate(curator_);
}


TargetCredentials_ptr
MICOSL3_TransportSecurity::SecurityManager_impl::get_target_credentials
(CORBA::Object_ptr the_object)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3TS: SecurityManager_impl::get_target_credentials: "
	    << the_object << endl;
    }
    TargetCredentials_ptr result = curator_->get_target_credentials(the_object, FALSE);
    if (CORBA::is_nil(result)) {
	the_object->_non_existent();
	result = curator_->get_target_credentials(the_object, TRUE);
    }
    return result;
}


ContextEstablishmentPolicy_ptr
MICOSL3_TransportSecurity::SecurityManager_impl::create_context_estab_policy
(CredsDirective creds_directive,
 const OwnCredentialsList& creds_list,
 FeatureDirective use_client_auth,
 FeatureDirective use_target_auth,
 FeatureDirective use_confidentiality,
 FeatureDirective use_integrity)
{
    return new ContextEstablishmentPolicy_impl
	(creds_directive, creds_list, use_client_auth, use_target_auth,
	 use_confidentiality, use_integrity);
}


ObjectCredentialsPolicy_ptr
MICOSL3_TransportSecurity::SecurityManager_impl::create_object_creds_policy
(const OwnCredentialsList& creds_list)
{
    return new ObjectCredentialsPolicy_impl(creds_list);
}

// extension

Boolean
MICOSL3_TransportSecurity::SecurityManager_impl::security_enabled()
{
    return security_enabled_;
}


//
// InitiatingContext_impl
//

MICOSL3_TransportSecurity::InitiatingContext_impl::InitiatingContext_impl
(OwnCredentials_ptr parent_credentials)
    : TargetCredentials_impl(parent_credentials)
{
    // we need parent credentials to obtain all observers
    assert(!CORBA::is_nil(parent_credentials_));
    OwnCredentials_impl* impl = dynamic_cast<OwnCredentials_impl*>
	(parent_credentials_.in());
    assert(impl != NULL);
    SL3OM::ObserverSeq_var observers = impl->observers();
    for (CORBA::ULong i = 0; i < observers->length(); i++) {
	InitiatingContextObserver_var ic_observer = InitiatingContextObserver::_narrow
	    (observers[i]);
	if (!CORBA::is_nil(ic_observer)) {
	    context_observers_.push_back(ic_observer);
	    InitiatingContextDestroyObserver_var dtor_observer
		= InitiatingContextDestroyObserver::_narrow(observers[i]);
	    if (!CORBA::is_nil(dtor_observer)) {
		destroy_observers_.push_back(dtor_observer);
	    }
	}
    }
}


MICOSL3_TransportSecurity::InitiatingContext_impl::~InitiatingContext_impl()
{
    //cerr << "~InitiatingContext_impl" << endl;
    this->notify_destroy_context();
}


Boolean
MICOSL3_TransportSecurity::InitiatingContext_impl::is_usable
(const char* host,
 ULong port,
 CredsDirective creds_directive,
 FeatureDirective client_authentication,
 FeatureDirective target_authentication,
 FeatureDirective confidentiality,
 FeatureDirective integrity,
 CSIVersion csi_version,
 const IOP::TaggedComponentSeq& transport_components)
{
    assert(0);
    return FALSE;
}


void
MICOSL3_TransportSecurity::InitiatingContext_impl::shutdown()
{
    //cerr << "InitiatingContext_impl::shutdown" << endl;
}


char*
MICOSL3_TransportSecurity::InitiatingContext_impl::name()
{
    return this->creds_id();
}


void
MICOSL3_TransportSecurity::InitiatingContext_impl::create_credentials(const char* id)
{
}


void
MICOSL3_TransportSecurity::InitiatingContext_impl::relinquish_credentials(const char* id)
{
    this->release_credentials(id);
}

// extension

void
MICOSL3_TransportSecurity::InitiatingContext_impl::notify_establish_context()
{
    for (CORBA::ULong i = 0; i < context_observers_.size(); i++) {
	context_observers_[i]->establish_context(this);
    }
}


void
MICOSL3_TransportSecurity::InitiatingContext_impl::notify_close_context()
{
    for (CORBA::ULong i = 0; i < context_observers_.size(); i++) {
	context_observers_[i]->close_context(this);
    }
}


void
MICOSL3_TransportSecurity::InitiatingContext_impl::notify_destroy_context()
{
    for (CORBA::ULong i = 0; i < destroy_observers_.size(); i++) {
	destroy_observers_[i]->destroy_context(this);
    }
}


//
// AcceptingContext_impl
//

MICOSL3_TransportSecurity::AcceptingContext_impl::AcceptingContext_impl
(OwnCredentials_ptr parent_credentials)
    : ClientCredentials_impl(OwnCredentials::_duplicate(parent_credentials))
{
    // we need parent credentials to obtain all observers
    assert(!CORBA::is_nil(parent_credentials_));
    OwnCredentials_impl* impl = dynamic_cast<OwnCredentials_impl*>
	(parent_credentials_.in());
    assert(impl != NULL);
    SL3OM::ObserverSeq_var observers = impl->observers();
    for (CORBA::ULong i = 0; i < observers->length(); i++) {
	AcceptingContextObserver_var ac_observer = AcceptingContextObserver::_narrow
	    (observers[i]);
	if (!CORBA::is_nil(ac_observer)) {
	    context_observers_.push_back(ac_observer);
	    AcceptingContextDestroyObserver_var dtor_observer
		= AcceptingContextDestroyObserver::_narrow(observers[i]);
	    if (!CORBA::is_nil(dtor_observer)) {
		destroy_observers_.push_back(dtor_observer);
	    }
	}
    }
}


MICOSL3_TransportSecurity::AcceptingContext_impl::~AcceptingContext_impl()
{
    //cerr << "~AcceptingContext_impl" << endl;
    this->notify_destroy_context();
}


IdentityTokenGenerator_ptr
MICOSL3_TransportSecurity::AcceptingContext_impl::create_client_identity_token_generator()
{
    assert(0);
    return NULL;
}

char*
MICOSL3_TransportSecurity::AcceptingContext_impl::name()
{
    return this->creds_id();
}


void
MICOSL3_TransportSecurity::AcceptingContext_impl::create_credentials(const char* id)
{
}


void
MICOSL3_TransportSecurity::AcceptingContext_impl::relinquish_credentials(const char* id)
{
    this->release_credentials(id);
}

// extension

void
MICOSL3_TransportSecurity::AcceptingContext_impl::notify_establish_context()
{
    for (CORBA::ULong i = 0; i < context_observers_.size(); i++) {
	context_observers_[i]->establish_context(this);
    }
}


void
MICOSL3_TransportSecurity::AcceptingContext_impl::notify_close_context()
{
    for (CORBA::ULong i = 0; i < context_observers_.size(); i++) {
	context_observers_[i]->close_context(this);
    }
}


void
MICOSL3_TransportSecurity::AcceptingContext_impl::notify_destroy_context()
{
    for (CORBA::ULong i = 0; i < destroy_observers_.size(); i++) {
	destroy_observers_[i]->destroy_context(this);
    }
}


//
// TransportInitiator_impl
//

TransportSecurity::ContextEstablisherList*
MICOSL3_TransportSecurity::TransportInitiator_impl::context_establishers()
{
    assert(0);
    return NULL;
}


char*
MICOSL3_TransportSecurity::TransportInitiator_impl::host()
{
    return CORBA::string_dup(host_.in());
}


ULong
MICOSL3_TransportSecurity::TransportInitiator_impl::low_port()
{
    return low_port_;
}


ULong
MICOSL3_TransportSecurity::TransportInitiator_impl::high_port()
{
    return high_port_;
}


void
MICOSL3_TransportSecurity::TransportInitiator_impl::increment_work()
{
    assert(0);
}


void
MICOSL3_TransportSecurity::TransportInitiator_impl::decrement_work()
{
    assert(0);
}


Boolean
MICOSL3_TransportSecurity::TransportInitiator_impl::supports_invoc_options
(CSIIOP::AssociationOptions invocation_options_supported,
 CSIIOP::AssociationOptions invocation_options_required)
{
    assert(0);
    return FALSE;
}


Boolean
MICOSL3_TransportSecurity::TransportInitiator_impl::supports_csi_version
(CSIVersion csi_version)
{
    assert(0);
    return FALSE;
}


Boolean
MICOSL3_TransportSecurity::TransportInitiator_impl::is_usable
(const char* host,
 ULong port,
 SL3CM::CredsDirective creds_directive,
 SL3CM::FeatureDirective client_authentication,
 SL3CM::FeatureDirective target_authentication,
 SL3CM::FeatureDirective confidentiality,
 SL3CM::FeatureDirective integrity,
 TransportSecurity::CSIVersion csi_version,
 const IOP::TaggedComponentSeq& transport_components)
{
    assert(0);
    return FALSE;
}


ContextEstablisherList*
MICOSL3_TransportSecurity::TransportInitiator_impl::create_context_establishers
(const char* host,
 ULong port,
 SL3CM::CredsDirective creds_directive,
 SL3CM::FeatureDirective client_authentication,
 SL3CM::FeatureDirective target_authentication,
 SL3CM::FeatureDirective confidentiality,
 SL3CM::FeatureDirective integrity,
 TransportSecurity::CSIVersion csi_version,
 const IOP::TaggedComponentSeq& transport_components)
{
    assert(0);
    return NULL;
}


TransportSecurity::ContextEstablisher_ptr
MICOSL3_TransportSecurity::TransportInitiator_impl::get_context_establisher
(const char* id)
{
    assert(0);
    return NULL;
}


//
// TransportAcceptor_impl
//

StringSeq*
MICOSL3_TransportSecurity::TransportAcceptor_impl::hosts()
{
    return new StringSeq(hosts_);
}


ULong
MICOSL3_TransportSecurity::TransportAcceptor_impl::port()
{
    return port_;
}


CSIIOP::AssociationOptions
MICOSL3_TransportSecurity::TransportAcceptor_impl::options_required()
{
    return options_required_;
}


CSIIOP::AssociationOptions
MICOSL3_TransportSecurity::TransportAcceptor_impl::options_supported()
{
    return options_supported_;
}


void
MICOSL3_TransportSecurity::TransportAcceptor_impl::increment_work()
{
    assert(0);
}


void
MICOSL3_TransportSecurity::TransportAcceptor_impl::decrement_work()
{
    assert(0);
}


IOP::TaggedComponentSeq*
MICOSL3_TransportSecurity::TransportAcceptor_impl::transport_components
(TransportSecurity::CSIVersion csi_version)
{
    assert(0);
    return NULL;
}


Boolean
MICOSL3_TransportSecurity::TransportAcceptor_impl::transport_matches
(const char* host,
 ULong port,
 const IOP::TaggedComponentSeq& transport_components)
{
    assert(0);
    return FALSE;
}


TransportSecurity::AcceptingContext_ptr
MICOSL3_TransportSecurity::TransportAcceptor_impl::accept(Boolean block)
{
    assert(0);
    return NULL;
}


void
MICOSL3_TransportSecurity::TransportAcceptor_impl::shutdown()
{
    assert(0);
}


void
MICOSL3_TransportSecurity::TransportAcceptor_impl::enable()
{
    assert(0);
}


//
// ContextEstablishmentPolicy_impl
//

MICOSL3_TransportSecurity::ContextEstablishmentPolicy_impl::ContextEstablishmentPolicy_impl
(CredsDirective creds_directive,
 const OwnCredentialsList& creds_list,
 FeatureDirective use_client_auth,
 FeatureDirective use_target_auth,
 FeatureDirective use_confidentiality,
 FeatureDirective use_integrity)
    : creds_list_(creds_list), creds_directive_(creds_directive),
      use_client_auth_(use_client_auth), use_target_auth_(use_target_auth),
      use_confidentiality_(use_confidentiality), use_integrity_(use_integrity)
{
}


OwnCredentialsList*
MICOSL3_TransportSecurity::ContextEstablishmentPolicy_impl::creds_list()
{
    return new OwnCredentialsList(creds_list_);
}


CredsDirective
MICOSL3_TransportSecurity::ContextEstablishmentPolicy_impl::creds_directive()
{
    return creds_directive_;
}


FeatureDirective
MICOSL3_TransportSecurity::ContextEstablishmentPolicy_impl::use_client_auth()
{
    return use_client_auth_;
}


FeatureDirective
MICOSL3_TransportSecurity::ContextEstablishmentPolicy_impl::use_target_auth()
{
    return use_target_auth_;
}


FeatureDirective
MICOSL3_TransportSecurity::ContextEstablishmentPolicy_impl::use_confidentiality()
{
    return use_confidentiality_;
}


FeatureDirective
MICOSL3_TransportSecurity::ContextEstablishmentPolicy_impl::use_integrity()
{
    return use_integrity_;
}


CORBA::PolicyType
MICOSL3_TransportSecurity::ContextEstablishmentPolicy_impl::policy_type()
{
    return ContextEstablishmentPolicyType;
}


CORBA::Policy_ptr
MICOSL3_TransportSecurity::ContextEstablishmentPolicy_impl::copy()
{
    return new ContextEstablishmentPolicy_impl
	(creds_directive_, creds_list_, use_client_auth_, use_target_auth_,
	 use_confidentiality_, use_integrity_);
}


void
MICOSL3_TransportSecurity::ContextEstablishmentPolicy_impl::destroy()
{
    // not implemented yet
    assert(0);
}


//
// ObjectCredentialsPolicy_impl
//

MICOSL3_TransportSecurity::ObjectCredentialsPolicy_impl::ObjectCredentialsPolicy_impl
(const OwnCredentialsList& creds_list)
    : creds_list_(creds_list)
{
}


TransportSecurity::OwnCredentialsList*
MICOSL3_TransportSecurity::ObjectCredentialsPolicy_impl::creds_list()
{
    return new OwnCredentialsList(this->creds_list_);
}


CORBA::PolicyType
MICOSL3_TransportSecurity::ObjectCredentialsPolicy_impl::policy_type()
{
    return ObjectCredentialsPolicyType;
}


CORBA::Policy_ptr
MICOSL3_TransportSecurity::ObjectCredentialsPolicy_impl::copy()
{
    return new ObjectCredentialsPolicy_impl(this->creds_list_);
}


void
MICOSL3_TransportSecurity::ObjectCredentialsPolicy_impl::destroy()
{
    // not implemented yet
    assert(0);
}


//
// various supporting classes
//

MICOSL3_TransportSecurity::ORBInitializer::ORBInitializer()
{
}


MICOSL3_TransportSecurity::ORBInitializer::~ORBInitializer()
{
}


void
MICOSL3_TransportSecurity::ORBInitializer::pre_init
(PortableInterceptor::ORBInitInfo_ptr info)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "MICOSL3_TransportSecurity::ORBInitializer::pre_init" << endl;
    }
    Boolean enabled = FALSE;
    StringSeq* args = info->arguments();
    for (ULong i = 0; i < args->length(); i++) {
	String_var ttt = (*args)[i];
	if (strcmp((*args)[i].in(), "-ORBSL3") == 0)
	    enabled = TRUE;
    }
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	if (enabled)
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3 security enabled." << endl;
	else
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3 security disabled." << endl;
    }
    SecurityCurrent_impl* current = new SecurityCurrent_impl;
    info->register_initial_reference
	("TransportSecurity::SecurityCurrent", current);
    CredentialsCurator_impl* curator = new CredentialsCurator_impl;
//      info->register_initial_reference
//  	("TransportSecurity::CredentialsCurator", curator);
    SecurityManager_impl* secman = new SecurityManager_impl(curator, enabled);
    info->register_initial_reference
	("TransportSecurity::SecurityManager", secman);
    if (enabled) {
        // register server interceptor
        TSServerRequestInterceptor* interceptor
            = new TSServerRequestInterceptor(secman, current, "TSServerRequestInterceptor");
        info->add_server_request_interceptor(interceptor);
    }
}


void
MICOSL3_TransportSecurity::ORBInitializer::post_init
(PortableInterceptor::ORBInitInfo_ptr info)
{
}


//
// TSServerRequestInterceptor
//

MICOSL3_TransportSecurity::TSServerRequestInterceptor::TSServerRequestInterceptor
(SecurityManager_impl* secman,
 SecurityCurrent_impl* current,
 const char* name)
    : secman_(secman), current_(current), name_(name)
{
    //cerr << "TSServerRequestInterceptor ctor" << endl;
}


char*
MICOSL3_TransportSecurity::TSServerRequestInterceptor::name()
{
    return CORBA::string_dup(name_.in());
}


void
MICOSL3_TransportSecurity::TSServerRequestInterceptor::destroy()
{
}


void
MICOSL3_TransportSecurity::TSServerRequestInterceptor::receive_request_service_contexts
(ServerRequestInfo_ptr ri)
{
}


void
MICOSL3_TransportSecurity::TSServerRequestInterceptor::receive_request
(PortableInterceptor::ServerRequestInfo_ptr ri)
{
    if (secman_->security_enabled()) {
	CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
	assert(!CORBA::is_nil(orb));
	void* hint = orb->get_orbid(ri->request_id())->get_request_hint();
	if (hint != NULL) {
	    MICO::IIOPServerInvokeRec* rec
		= static_cast<MICO::IIOPServerInvokeRec*>(hint);
	    assert(rec != NULL);
	    CORBA::Object_var ctx = rec->conn()->accepting_context();
	    TransportSecurity::ClientCredentials_var creds
		= TransportSecurity::ClientCredentials::_narrow(ctx);
	    current_->push_client_credentials(creds);
	}
	else {
	    // hint == NULL means that we do in process call
	    CredentialsCurator_var curator = secman_->credentials_curator();
	    OwnCredentialsList_var creds = curator->default_creds_list();
	    OwnCredentials_var ipc_creds = OwnCredentials::_nil();
	    for (CORBA::ULong i = 0; i < creds->length(); i++) {
		String_var id = creds[i]->creds_id();
		string tmp = id.in();
		if (tmp.find("MICO_IPC:") != string::npos) {
		    // IPC own credentials
		    ipc_creds = creds[i];
		    break;
		}
	    }
	    if (CORBA::is_nil(ipc_creds)) {
		// the user have to setup IPC credentials before going
		// to use in process calls
		assert(0);
	    }
	    ClientCredentials_ptr res 
		= MICOSL3_SL3IPC::IPCCredsMapper::self()->get_client_credentials
		(ipc_creds);
	    if (CORBA::is_nil(res)) {
		// needs to create client credentials for given own credentials
		res = new MICOSL3_SL3IPC::IPCAcceptingContext(ipc_creds);
		MICOSL3_SL3IPC::IPCCredsMapper::self()->add_client_credentials
		    (ipc_creds, res);
	    }
	    assert(!CORBA::is_nil(res));
	    current_->push_client_credentials(res);
	}
    }
}


void
MICOSL3_TransportSecurity::TSServerRequestInterceptor::send_reply
(PortableInterceptor::ServerRequestInfo_ptr ri)
{
    // we have to clear current's client credentials here
    // this is required for credentials cleanup, since otherwise
    // we would hold one reference in SecurityCurrent perfectly
    // prohibitting theirs cleanup
    current_->pop_client_credentials();
}


void
MICOSL3_TransportSecurity::TSServerRequestInterceptor::send_exception
(PortableInterceptor::ServerRequestInfo_ptr ri)
{
    // we have to clear current's client credentials here
    // this is required for credentials cleanup, since otherwise
    // we would hold one reference in SecurityCurrent perfectly
    // prohibitting theirs cleanup
    current_->pop_client_credentials();
}


void
MICOSL3_TransportSecurity::TSServerRequestInterceptor::send_other
(PortableInterceptor::ServerRequestInfo_ptr ri)
{
    // we have to clear current's client credentials here
    // this is required for credentials cleanup, since otherwise
    // we would hold one reference in SecurityCurrent perfectly
    // prohibitting theirs cleanup
    current_->pop_client_credentials();
}


