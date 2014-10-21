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
#include <mico/security/sl3pm_impl.h>
#include <mico/security/securitylevel3_impl.h>
#include <mico/security/sl3csi_impl.h>
#include <mico/util.h>

#include <stack>
#endif // FAST_PCH

using namespace SL3PM;
using namespace SL3CM;
using namespace SL3OM;
using namespace SL3OMExt;
using namespace SecurityLevel3;
using namespace SL3CSI;
using CORBA::Boolean;
using CORBA::ULong;
using CORBA::ValueBase;
using namespace std;


//
// static members initialization
//
CORBA::ULong
MICOSL3_SecurityLevel3::OwnCredentials_impl::S_creds_index_ = 0;


//
// module initialization
//

void
MICOSL3_SecurityLevel3::_init()
{
    PortableInterceptor::register_orb_initializer(new ORBInitializer());
}


//
// CredsInitiator_impl
//

Principal*
MICOSL3_SecurityLevel3::CredsInitiator_impl::the_principal()
{
    CORBA::add_ref(principal_);
    return principal_;
}


StatementList*
MICOSL3_SecurityLevel3::CredsInitiator_impl::supporting_statements()
{
    return new StatementList(supporting_statements_);
}


ResourceNameList*
MICOSL3_SecurityLevel3::CredsInitiator_impl::restricted_resources()
{
    return new ResourceNameList(restricted_resources_);
}


PrinAttributeList*
MICOSL3_SecurityLevel3::CredsInitiator_impl::environmental_attributes()
{
    return new PrinAttributeList(environmental_attributes_);
}


InitiatorType
MICOSL3_SecurityLevel3::CredsInitiator_impl::initiator_type()
{
    return initiator_type_;
}


Boolean
MICOSL3_SecurityLevel3::CredsInitiator_impl::supports_embodiment()
{
    return supports_embodiment_;
}


Boolean
MICOSL3_SecurityLevel3::CredsInitiator_impl::supports_endorsement()
{
    return supports_endorsement_;
}


Boolean
MICOSL3_SecurityLevel3::CredsInitiator_impl::supports_quoting()
{
    return supports_quoting_;
}


TimeBase::UtcT
MICOSL3_SecurityLevel3::CredsInitiator_impl::expiry_time()
{
    return expiry_time_;
}


//
// CredsAcceptor_impl
//

Principal*
MICOSL3_SecurityLevel3::CredsAcceptor_impl::the_principal()
{
    CORBA::add_ref(principal_);
    return principal_;
}


StatementList*
MICOSL3_SecurityLevel3::CredsAcceptor_impl::supporting_statements()
{
    return new StatementList(supporting_statements_);
}


ResourceNameList*
MICOSL3_SecurityLevel3::CredsAcceptor_impl::restricted_resources()
{
    return new ResourceNameList(restricted_resources_);
}


PrinAttributeList*
MICOSL3_SecurityLevel3::CredsAcceptor_impl::environmental_attributes()
{
    return new PrinAttributeList(environmental_attributes_);
}


Boolean
MICOSL3_SecurityLevel3::CredsAcceptor_impl::accepts_endorsement()
{
    return accepts_endorsement_;
}


Boolean
MICOSL3_SecurityLevel3::CredsAcceptor_impl::accepts_quoting()
{
    return accepts_quoting_;
}


TimeBase::UtcT
MICOSL3_SecurityLevel3::CredsAcceptor_impl::expiry_time()
{
    return expiry_time_;
}


//
// Credentials_impl
//

char*
MICOSL3_SecurityLevel3::Credentials_impl::creds_id()
{
    return CORBA::string_dup(creds_id_.in());
}


CredentialsType
MICOSL3_SecurityLevel3::Credentials_impl::creds_type()
{
    return creds_type_;
}


CredentialsUsage
MICOSL3_SecurityLevel3::Credentials_impl::creds_usage()
{
    return creds_usage_;
}


CredentialsState
MICOSL3_SecurityLevel3::Credentials_impl::creds_state()
{
    return creds_state_;
}


void
MICOSL3_SecurityLevel3::Credentials_impl::creds_id(const char* id)
{
    creds_id_ = id;
}


void
MICOSL3_SecurityLevel3::Credentials_impl::creds_type(CredentialsType creds_type)
{
    creds_type_ = creds_type;
}


void
MICOSL3_SecurityLevel3::Credentials_impl::creds_usage
(CredentialsUsage creds_usage)
{
    creds_usage_ = creds_usage;
}

void
MICOSL3_SecurityLevel3::Credentials_impl::creds_state
(CredentialsState creds_state)
{
    creds_state_ = creds_state;
}


//
// OwnCredentials_impl
//

MICOSL3_SecurityLevel3::OwnCredentials_impl::OwnCredentials_impl
(CredentialsUsage usage,
 CredsInitiator_ptr initiator,
 CredsAcceptor_ptr acceptor,
 const SL3OM::ObserverSeq& observers)
{
    string id = "MICO_SL3CSI:";
    id += xdec(S_creds_index_);
    S_creds_index_++;
    creds_id_ = CORBA::string_dup(id.c_str());
    creds_state_ = CS_Valid;
    creds_type_ = CT_OwnCredentials;
    creds_usage_ = usage;
    initiator_ = CredsInitiator::_duplicate(initiator);
    acceptor_ = CredsAcceptor::_duplicate(acceptor);
    for (CORBA::ULong i = 0; i < observers.length(); i++) {
	this->add_observer(observers[i].in());
    }
    observers_ = observers;
    this->notify_creation();
}


MICOSL3_SecurityLevel3::OwnCredentials_impl::~OwnCredentials_impl()
{
    this->notify_destroy();
}


CredsInitiator_ptr
MICOSL3_SecurityLevel3::OwnCredentials_impl::creds_initiator()
{
    return CredsInitiator::_duplicate(initiator_);
}


CredsAcceptor_ptr
MICOSL3_SecurityLevel3::OwnCredentials_impl::creds_acceptor()
{
    return CredsAcceptor::_duplicate(acceptor_);
}


void
MICOSL3_SecurityLevel3::OwnCredentials_impl::release_credentials()
{
    CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
    assert(!CORBA::is_nil(orb));
    CORBA::Object_var obj = orb->resolve_initial_references
	("SecurityLevel3::SecurityManager");
    SecurityManager_var secman = SecurityManager::_narrow(obj);
    assert(!CORBA::is_nil(secman));
    CredentialsCurator_var curator = secman->credentials_curator();
    assert(!CORBA::is_nil(curator));
    CORBA::String_var id = this->creds_id();
    curator->release_own_credentials(id);
}

// extension

ObserverSeq*
MICOSL3_SecurityLevel3::OwnCredentials_impl::observers()
{
    return new ObserverSeq(observers_);
}


void
MICOSL3_SecurityLevel3::OwnCredentials_impl::add_observer(SL3OM::Observer_ptr observer)
{
    CredentialsObserver_var creds_observer = CredentialsObserver::_narrow
	(observer);
    if (!CORBA::is_nil(creds_observer)) {
	credentials_observers_.push_back(creds_observer);
	CredentialsDestroyObserver_var dtor_observer
	    = CredentialsDestroyObserver::_narrow(observer);
	if (!CORBA::is_nil(dtor_observer)) {
	    destroy_observers_.push_back(dtor_observer);
	}
    }    
}


void
MICOSL3_SecurityLevel3::OwnCredentials_impl::notify_creation()
{
    CORBA::String_var creds_id = this->creds_id();
    for (CORBA::ULong i = 0; i < credentials_observers_.size(); i++) {
	credentials_observers_[i]->create_credentials(creds_id);
    }
}


void
MICOSL3_SecurityLevel3::OwnCredentials_impl::notify_remove()
{
    CORBA::String_var creds_id = this->creds_id();
    for (CORBA::ULong i = 0; i < credentials_observers_.size(); i++) {
	credentials_observers_[i]->relinquish_credentials(creds_id);
    }
}


void
MICOSL3_SecurityLevel3::OwnCredentials_impl::notify_destroy()
{
    CORBA::String_var creds_id = this->creds_id();
    for (CORBA::ULong i = 0; i < destroy_observers_.size(); i++) {
	destroy_observers_[i]->destroy_credentials(creds_id);
    }
}


//
// ClientCredentials_impl
//

MICOSL3_SecurityLevel3::ClientCredentials_impl::~ClientCredentials_impl()
{
    this->notify_destroy();
}


char*
MICOSL3_SecurityLevel3::ClientCredentials_impl::context_id()
{
    return CORBA::string_dup(context_id_.in());
}


Principal*
MICOSL3_SecurityLevel3::ClientCredentials_impl::client_principal()
{
    CORBA::add_ref(client_principal_);
    return client_principal_;
}


StatementList*
MICOSL3_SecurityLevel3::ClientCredentials_impl::client_supporting_statements()
{
    return new StatementList(client_supporting_statements_);
}


ResourceNameList*
MICOSL3_SecurityLevel3::ClientCredentials_impl::client_restricted_resources()
{
    return new ResourceNameList(client_restricted_resources_);
}


Principal*
MICOSL3_SecurityLevel3::ClientCredentials_impl::target_principal()
{
    CORBA::add_ref(target_principal_);
    return target_principal_;
}


StatementList*
MICOSL3_SecurityLevel3::ClientCredentials_impl::target_supporting_statements()
{
    return new StatementList(target_supporting_statements_);
}


ResourceNameList*
MICOSL3_SecurityLevel3::ClientCredentials_impl::target_restricted_resources()
{
    return new ResourceNameList(target_restricted_resources_);
}


PrinAttributeList*
MICOSL3_SecurityLevel3::ClientCredentials_impl::environmental_attributes()
{
    return new PrinAttributeList(environmental_attributes_);
}


OwnCredentials_ptr
MICOSL3_SecurityLevel3::ClientCredentials_impl::parent_credentials()
{
    return OwnCredentials::_duplicate(parent_credentials_);
}


Boolean
MICOSL3_SecurityLevel3::ClientCredentials_impl::client_authentication()
{
    return client_authentication_;
}


Boolean
MICOSL3_SecurityLevel3::ClientCredentials_impl::target_authentication()
{
    return target_authentication_;
}


Boolean
MICOSL3_SecurityLevel3::ClientCredentials_impl::confidentiality()
{
    return confidentiality_;
}


Boolean
MICOSL3_SecurityLevel3::ClientCredentials_impl::integrity()
{
    return integrity_;
}

// extension

void
MICOSL3_SecurityLevel3::ClientCredentials_impl::context_id(const char* id)
{
    context_id_ = CORBA::string_dup(id);
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::client_principal
(Principal* principal)
{
    CORBA::add_ref(principal);
    client_principal_ = principal;
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::client_supporting_statements
(const StatementList& statements)
{
    client_supporting_statements_ = statements;
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::client_restricted_resources
(const ResourceNameList& resources)
{
    client_restricted_resources_ = resources;
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::target_principal
(Principal* principal)
{
    CORBA::add_ref(principal);
    target_principal_ = principal;
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::target_supporting_statements
(const StatementList& statements)
{
    target_supporting_statements_ = statements;
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::target_restricted_resources
(const ResourceNameList& resources)
{
    target_restricted_resources_ = resources;
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::environmental_attributes
(const PrinAttributeList& attrs)
{
    environmental_attributes_ = attrs;
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::parent_credentials
(OwnCredentials_ptr creds)
{
    parent_credentials_ = OwnCredentials::_duplicate(creds);
    assert(!CORBA::is_nil(parent_credentials_));
    OwnCredentials_impl* impl = dynamic_cast<OwnCredentials_impl*>
	(parent_credentials_.in());
    assert(impl != NULL);
    SL3OM::ObserverSeq_var observers = impl->observers();
    for (CORBA::ULong i = 0; i < observers->length(); i++) {
	ClientCredentialsObserver_var cc_observer = ClientCredentialsObserver::_narrow
	    (observers[i]);
	if (!CORBA::is_nil(cc_observer)) {
	    credentials_observers_.push_back(cc_observer);
	    ClientCredentialsDestroyObserver_var dtor_observer
		= ClientCredentialsDestroyObserver::_narrow(observers[i]);
	    if (!CORBA::is_nil(dtor_observer)) {
		destroy_observers_.push_back(dtor_observer);
	    }
	}
    }
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::client_authentication
(CORBA::Boolean authentication)
{
    client_authentication_ = authentication;
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::target_authentication
(CORBA::Boolean authentication)
{
    target_authentication_ = authentication;
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::confidentiality
(CORBA::Boolean confidentiality)
{
    confidentiality_ = confidentiality;
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::integrity
(CORBA::Boolean integrity)
{
    integrity_ = integrity;
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::notify_creation()
{
    for (CORBA::ULong i = 0; i < credentials_observers_.size(); i++) {
	credentials_observers_[i]->create_credentials(this);
    }
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::notify_release()
{
    for (CORBA::ULong i = 0; i < credentials_observers_.size(); i++) {
	credentials_observers_[i]->release_credentials(this);
    }
}


void
MICOSL3_SecurityLevel3::ClientCredentials_impl::notify_destroy()
{
    for (CORBA::ULong i = 0; i < destroy_observers_.size(); i++) {
	destroy_observers_[i]->destroy_credentials(this);
    }
}

//
// TargetCredentials_impl
//

MICOSL3_SecurityLevel3::TargetCredentials_impl::~TargetCredentials_impl()
{
    this->notify_destroy();
}


char*
MICOSL3_SecurityLevel3::TargetCredentials_impl::context_id()
{
    return CORBA::string_dup(context_id_.in());
}


Principal*
MICOSL3_SecurityLevel3::TargetCredentials_impl::client_principal()
{
    CORBA::add_ref(client_principal_);
    return client_principal_;
}


StatementList*
MICOSL3_SecurityLevel3::TargetCredentials_impl::client_supporting_statements()
{
    return new StatementList(client_supporting_statements_);
}


ResourceNameList*
MICOSL3_SecurityLevel3::TargetCredentials_impl::client_restricted_resources()
{
    return new ResourceNameList(client_restricted_resources_);
}


Principal*
MICOSL3_SecurityLevel3::TargetCredentials_impl::target_principal()
{
    CORBA::add_ref(target_principal_);
    return target_principal_;
}


StatementList*
MICOSL3_SecurityLevel3::TargetCredentials_impl::target_supporting_statements()
{
    return new StatementList(target_supporting_statements_);
}


ResourceNameList*
MICOSL3_SecurityLevel3::TargetCredentials_impl::target_restricted_resources()
{
    return new ResourceNameList(target_restricted_resources_);
}


PrinAttributeList*
MICOSL3_SecurityLevel3::TargetCredentials_impl::environmental_attributes()
{
    return new PrinAttributeList(environmental_attributes_);
}


OwnCredentials_ptr
MICOSL3_SecurityLevel3::TargetCredentials_impl::parent_credentials()
{
    return OwnCredentials::_duplicate(parent_credentials_);
}


Boolean
MICOSL3_SecurityLevel3::TargetCredentials_impl::client_authentication()
{
    return client_authentication_;
}


Boolean
MICOSL3_SecurityLevel3::TargetCredentials_impl::target_authentication()
{
    return target_authentication_;
}


Boolean
MICOSL3_SecurityLevel3::TargetCredentials_impl::confidentiality()
{
    return confidentiality_;
}


Boolean
MICOSL3_SecurityLevel3::TargetCredentials_impl::integrity()
{
    return integrity_;
}


Boolean
MICOSL3_SecurityLevel3::TargetCredentials_impl::target_embodied()
{
    return target_embodied_;
}


Boolean
MICOSL3_SecurityLevel3::TargetCredentials_impl::target_endorsed()
{
    return target_endorsed_;
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::release()
{
    assert(0);
}

// extension

void
MICOSL3_SecurityLevel3::TargetCredentials_impl::context_id(const char* id)
{
    context_id_ = CORBA::string_dup(id);
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::client_principal
(Principal* principal)
{
    CORBA::add_ref(principal);
    client_principal_ = principal;
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::client_supporting_statements
(const StatementList& statements)
{
    client_supporting_statements_ = statements;
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::client_restricted_resources
(const ResourceNameList& resources)
{
    client_restricted_resources_ = resources;
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::target_principal
(Principal* principal)
{
    CORBA::add_ref(principal);
    target_principal_ = principal;
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::target_supporting_statements
(const StatementList& statements)
{
    target_supporting_statements_ = statements;
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::target_restricted_resources
(const ResourceNameList& resources)
{
    target_restricted_resources_ = resources;
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::environmental_attributes
(const PrinAttributeList& attrs)
{
    environmental_attributes_ = attrs;
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::parent_credentials
(OwnCredentials_ptr creds)
{
    parent_credentials_ = OwnCredentials::_duplicate(creds);
    assert(!CORBA::is_nil(parent_credentials_));
    OwnCredentials_impl* impl = dynamic_cast<OwnCredentials_impl*>
	(parent_credentials_.in());
    assert(impl != NULL);
    SL3OM::ObserverSeq_var observers = impl->observers();
    for (CORBA::ULong i = 0; i < observers->length(); i++) {
	TargetCredentialsObserver_var cc_observer = TargetCredentialsObserver::_narrow
	    (observers[i]);
	if (!CORBA::is_nil(cc_observer)) {
	    credentials_observers_.push_back(cc_observer);
	    TargetCredentialsDestroyObserver_var dtor_observer
		= TargetCredentialsDestroyObserver::_narrow(observers[i]);
	    if (!CORBA::is_nil(dtor_observer)) {
		destroy_observers_.push_back(dtor_observer);
	    }
	}
    }
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::client_authentication
(CORBA::Boolean authentication)
{
    client_authentication_ = authentication;
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::target_authentication
(CORBA::Boolean authentication)
{
    target_authentication_ = authentication;
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::confidentiality
(CORBA::Boolean confidentiality)
{
    confidentiality_ = confidentiality;
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::integrity
(CORBA::Boolean integrity)
{
    integrity_ = integrity;
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::target_embodied
(CORBA::Boolean embodied)
{
    target_embodied_ = embodied;
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::target_endorsed
(CORBA::Boolean endorsed)
{
    target_endorsed_ = endorsed;
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::notify_creation()
{
    for (CORBA::ULong i = 0; i < credentials_observers_.size(); i++) {
	credentials_observers_[i]->create_credentials(this);
    }
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::notify_release()
{
    for (CORBA::ULong i = 0; i < credentials_observers_.size(); i++) {
	credentials_observers_[i]->release_credentials(this);
    }
}


void
MICOSL3_SecurityLevel3::TargetCredentials_impl::notify_destroy()
{
    for (CORBA::ULong i = 0; i < destroy_observers_.size(); i++) {
	destroy_observers_[i]->destroy_credentials(this);
    }
}


//
// CredentialsCurator_impl
//

OwnCredentialsList*
MICOSL3_SecurityLevel3::CredentialsCurator_impl::default_creds_list()
{
    MICOMT::AutoRDLock lock(default_creds_list_lock_);
    return new OwnCredentialsList(default_creds_list_);
}


CredentialsIdList*
MICOSL3_SecurityLevel3::CredentialsCurator_impl::default_creds_ids()
{
    MICOMT::AutoRDLock lock(default_creds_list_lock_);
    CredentialsIdList* list = new CredentialsIdList;
    list->length(default_creds_list_.length());
    for (ULong i = 0; i < default_creds_list_.length(); i++) {
	(*list)[i] = default_creds_list_[i]->creds_id();
    }
    return list;
}


CredentialsAcquirer_ptr
MICOSL3_SecurityLevel3::CredentialsCurator_impl::acquire_credentials
(SL3AQArgs::Argument_ptr acquisition_arguments)
{
    // argument checking is done in CredentialsAcquirer_impl ctor.
    return new MICOSL3_SL3CSI::CredentialsAcquirer_impl
	(this, acquisition_arguments);
}


OwnCredentials_ptr
MICOSL3_SecurityLevel3::CredentialsCurator_impl::get_own_credentials
(const char* credentials_id)
{
    MICOMT::AutoRDLock lock(own_creds_list_lock_);
    for (ULong i = 0; i < own_creds_list_.length(); i++) {
	CORBA::String_var id = own_creds_list_[i]->creds_id();
	if (strcmp(id.in(), credentials_id) == 0) {
	    return OwnCredentials::_duplicate(own_creds_list_[i]);
	}
    }
    return OwnCredentials::_nil();
}


void
MICOSL3_SecurityLevel3::CredentialsCurator_impl::release_own_credentials
(const char* credentials_id)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3: CredentialsCurator::release_own_credentials: "
	    << credentials_id << endl;
    }
    CORBA::LongLong ctx = -1;
    CORBA::String_var id = "";
    {
	MICOMT::AutoWRLock lock(default_creds_list_lock_);
	for (CORBA::ULong i = 0; i < default_creds_list_.length(); i++) {
	    id = default_creds_list_[i]->creds_id();
	    if (strcmp(id.in(), credentials_id) == 0) {
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
    ctx = -1;
    {
	MICOMT::AutoWRLock lock(own_creds_list_lock_);
	for (CORBA::ULong i = 0; i < own_creds_list_.length(); i++) {
	    id = own_creds_list_[i]->creds_id();
	    if (strcmp(id.in(), credentials_id) == 0) {
		ctx = i;
		break;
	    }
	}
	if (ctx > -1) {
	    OwnCredentials_impl* creds_impl
		= dynamic_cast<OwnCredentials_impl*>
		(own_creds_list_[ctx].in());
	    assert(creds_impl != NULL);
	    creds_impl->notify_remove();
	    for (CORBA::ULong i = ctx; i < own_creds_list_.length() - 1; i++) {
		own_creds_list_[i] = own_creds_list_[i + 1];
	    }
	    own_creds_list_.length(own_creds_list_.length() - 1);
	}
	else {
	    mico_throw(CORBA::BAD_PARAM(30001, CORBA::COMPLETED_NO));
	}
    }
}


void
MICOSL3_SecurityLevel3::CredentialsCurator_impl::add_own_credentials
(OwnCredentials_ptr creds, Boolean on_list)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3: CredentialsCurator_impl::add_own_credentials: "
	    << creds << endl;
    }
    {
	MICOMT::AutoWRLock lock(own_creds_list_lock_);
	own_creds_list_.length(own_creds_list_.length() + 1);
	own_creds_list_[own_creds_list_.length() - 1]
	    = OwnCredentials::_duplicate(creds);
    }
    if (on_list) {
	MICOMT::AutoWRLock lock(default_creds_list_lock_);
	default_creds_list_.length(default_creds_list_.length() + 1);
	default_creds_list_[default_creds_list_.length() - 1]
	    = OwnCredentials::_duplicate(creds);
    }
}


//
// SecurityManager_impl
//

MICOSL3_SecurityLevel3::SecurityManager_impl::SecurityManager_impl
(CredentialsCurator_ptr curator)
    : curator_(CredentialsCurator::_duplicate(curator))
{
}


CredentialsCurator_ptr
MICOSL3_SecurityLevel3::SecurityManager_impl::credentials_curator()
{
    return CredentialsCurator::_duplicate(curator_);
}


TargetCredentials_ptr
MICOSL3_SecurityLevel3::SecurityManager_impl::get_target_credentials
(CORBA::Object_ptr the_object)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3: SecurityManager_impl::get_target_credentials" << endl;
    }
    CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
    assert(!CORBA::is_nil(orb));
    CORBA::Object_var secobj = orb->resolve_initial_references
	("TransportSecurity::SecurityManager");
    TransportSecurity::SecurityManager_var secman
	= TransportSecurity::SecurityManager::_narrow(secobj);
    assert(!CORBA::is_nil(secman));
    TransportSecurity::TargetCredentials_var t_creds
	= secman->get_target_credentials(the_object);
    if (CORBA::is_nil(t_creds)) {
	// probably communication error with target
	// (something like COMM_FAILURE or TRANSIENT)
	// so we need to return NIL creds
	return TargetCredentials::_nil();
    }
    TargetCredsHolder* holder = dynamic_cast<TargetCredsHolder*>(t_creds.in());
    assert(holder != NULL);
    // kcg: find appropriate creds properties to find the right
    // target credentials
    SecurityLevel3::CredentialsCurator_var curator
	= this->credentials_curator();
    SecurityLevel3::OwnCredentialsList_var creds_list = NULL;
    SecurityLevel3::ContextEstablishmentPolicy_var policy
	= SecurityLevel3::ContextEstablishmentPolicy::_nil();
    try {
	CORBA::Policy_var p = the_object->_get_policy
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
    if (!CORBA::is_nil(policy)) {
	// there are credentials set directly on this object reference
	//cerr << "use policy's creds list" << endl;
	creds_list = policy->creds_list();
    }
    else {
	// we will use default credentials
	//cerr << "default creds list used" << endl;
	creds_list = curator->default_creds_list();
    }
    string key = "";
    for (CORBA::ULong i = 0; i < creds_list->length(); i++) {
	SecurityLevel3::OwnCredentials_var creds = (*creds_list)[i];
	if (creds->creds_usage() == CU_InitiateOnly
	    ||creds->creds_usage() == CU_InitiateAndAccept) {
	    SecurityLevel3::CredsInitiator_var initiator = creds->creds_initiator();
	    MICOSL3_SL3CSI::CSICredsInitiator* i_impl
		= dynamic_cast<MICOSL3_SL3CSI::CSICredsInitiator*>(initiator.in());
	    assert(i_impl != NULL);
	    UserPassword::PasswordGenerator_var generator = i_impl->password_generator();
	    if (generator.in() != NULL) {
		PrincipalName* name = generator->client_authentication_principal();
		assert(name != NULL);
		wstring wtn = name->the_name[0].in();
		delete name;
		key += wstr2str(wtn);
	    }
	    Principal_var pr = initiator->the_principal();
	    QuotingPrincipal* qp = NULL;
	    if (pr->the_type() == PT_Quoting
		&& ((qp = QuotingPrincipal::_downcast(pr)) != NULL)) {
		// quoting principal => we can generate identity token
		PrincipalName qp_name = qp->the_name();
		CORBA::WString_var name = CORBA::wstring_dup(qp_name.the_name[0]);
		wstring wname = name.in();
		string id = wstr2str(wname);
		key += "_" + id;
	    }
	    break;
	}
    }
    //cerr << "key: " << key << endl;
    TargetCredentials_ptr tc = holder->csi_creds(key);
    if (CORBA::is_nil(tc)) {
	// target credentials doesn't exist yet
	// => force to create them by calling remote
	// operation
	//cerr << "target credentials == NULL => call _non_existent() operation" << endl;
	the_object->_non_existent();
	tc = holder->csi_creds(key);
	// tc might still be NULL here, i.e. own credentials' LocalTrustInServerDecider
	// does not consider the target trusted and SL3/CSIv2 throws NO_PERMISSION
	// exception which is caught inside _non_existent call, but SL3CSI
	// TargetCredentials are not created for this target.
    }
    return tc;
}


ContextEstablishmentPolicy_ptr
MICOSL3_SecurityLevel3::SecurityManager_impl::create_context_estab_policy
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


MICOSL3_SecurityLevel3::ContextEstablishmentPolicy_impl::~ContextEstablishmentPolicy_impl()
{
}


ObjectCredentialsPolicy_ptr
MICOSL3_SecurityLevel3::SecurityManager_impl::create_object_creds_policy
(const OwnCredentialsList& creds_list)
{
    assert(0);
    return ObjectCredentialsPolicy::_nil();
}


//
// SecurityCurrent_impl
//

ClientCredentials_ptr
MICOSL3_SecurityLevel3::SecurityCurrent_impl::client_credentials()
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3: SecurityCurrent_impl::client_credentials()" << endl;
    }
    CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
    assert(!CORBA::is_nil(orb));
    CORBA::Object_var obj = orb->resolve_initial_references
	("TransportSecurity::SecurityCurrent");
    TransportSecurity::SecurityCurrent_var current
	= TransportSecurity::SecurityCurrent::_narrow(obj);
    TransportSecurity::ClientCredentials_var t_creds
	= current->client_credentials();
    MICOSL3_SecurityLevel3::ClientCredsHolder* holder
	= dynamic_cast<MICOSL3_SecurityLevel3::ClientCredsHolder*>(t_creds.in());
    assert(holder != NULL);
    return holder->current_creds();
}


Boolean
MICOSL3_SecurityLevel3::SecurityCurrent_impl::request_is_local()
{
    assert(0);
    return FALSE;
}


//
// ContextEstablishmentPolicy_impl
//

MICOSL3_SecurityLevel3::ContextEstablishmentPolicy_impl::ContextEstablishmentPolicy_impl
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
MICOSL3_SecurityLevel3::ContextEstablishmentPolicy_impl::creds_list()
{
    //cerr << "ContextEstablishmentPolicy_impl::creds_list()" << endl;
    return new OwnCredentialsList(creds_list_);
}


CredsDirective
MICOSL3_SecurityLevel3::ContextEstablishmentPolicy_impl::creds_directive()
{
    return creds_directive_;
}


FeatureDirective
MICOSL3_SecurityLevel3::ContextEstablishmentPolicy_impl::use_client_auth()
{
    return use_client_auth_;
}


FeatureDirective
MICOSL3_SecurityLevel3::ContextEstablishmentPolicy_impl::use_target_auth()
{
    return use_target_auth_;
}


FeatureDirective
MICOSL3_SecurityLevel3::ContextEstablishmentPolicy_impl::use_confidentiality()
{
    return use_confidentiality_;
}


FeatureDirective
MICOSL3_SecurityLevel3::ContextEstablishmentPolicy_impl::use_integrity()
{
    return use_integrity_;
}


CORBA::PolicyType
MICOSL3_SecurityLevel3::ContextEstablishmentPolicy_impl::policy_type()
{
    //cerr << "ContextEstablishmentPolicy_impl::policy_type()" << endl;
    return ContextEstablishmentPolicyType;
}


CORBA::Policy_ptr
MICOSL3_SecurityLevel3::ContextEstablishmentPolicy_impl::copy()
{
    //cerr << "ContextEstablishmentPolicy_impl::copy()" << endl;
    return new ContextEstablishmentPolicy_impl
	(creds_directive_, creds_list_, use_client_auth_, use_target_auth_,
	 use_confidentiality_, use_integrity_);
}


void
MICOSL3_SecurityLevel3::ContextEstablishmentPolicy_impl::destroy()
{
    // not implemented yet
    assert(0);
}


//
// various supporting classes
//

MICOSL3_SecurityLevel3::ORBInitializer::ORBInitializer()
{
}


MICOSL3_SecurityLevel3::ORBInitializer::~ORBInitializer()
{
}


void
MICOSL3_SecurityLevel3::ORBInitializer::pre_init
(PortableInterceptor::ORBInitInfo_ptr info)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3: ORBInitializer::pre_init" << endl;
    }
    // object registration
    SecurityCurrent_impl* current = new SecurityCurrent_impl;
    info->register_initial_reference
	("SecurityLevel3::SecurityCurrent", current);
    CredentialsCurator_impl* curator = new CredentialsCurator_impl;
//      info->register_initial_reference
//  	("SecurityLevel3::CredentialsCurator", curator);
    SecurityManager_impl* secman = new SecurityManager_impl(curator);
    info->register_initial_reference
	("SecurityLevel3::SecurityManager", secman);
}


void
MICOSL3_SecurityLevel3::ORBInitializer::post_init
(PortableInterceptor::ORBInitInfo_ptr info)
{
}


//
// TargetCredsHolder
//

SecurityLevel3::TargetCredentials_ptr
MICOSL3_SecurityLevel3::TargetCredsHolder::csi_creds(const string& key)
{
    if (creds_map_.count(key) > 0) {
	return TargetCredentials::_duplicate(creds_map_[key]);
    }
    return TargetCredentials::_nil();
}


void
MICOSL3_SecurityLevel3::TargetCredsHolder::csi_creds
(const string& key, TargetCredentials_ptr creds)
{
    creds_map_[key] = TargetCredentials::_duplicate(creds);
}


void
MICOSL3_SecurityLevel3::TargetCredsHolder::release_credentials(const char* id)
{
    stack<string> key_stack;
    for (TargetCredentialsMapIterator it = creds_map_.begin();
	 it != creds_map_.end();
	 it++) {
	OwnCredentials_var tcr = (*it).second->parent_credentials();
	CORBA::String_var parent_id = tcr->creds_id();
	if (strcmp(parent_id.in(), id) == 0) {
	    string key = (*it).first;
	    key_stack.push(key);
	    // notify release
	    TargetCredentials_impl* impl = dynamic_cast<TargetCredentials_impl*>
		(creds_map_[key].in());
	    assert(impl != NULL);
	    impl->notify_release();
	    creds_map_[key] = TargetCredentials::_nil();
	}
    }
    while (!key_stack.empty()) {
	string key = key_stack.top();
	key_stack.pop();
	long i = creds_map_.erase(key);
	assert(i == 1);
    }
}


//
// ClientCredsHolder
//

MICOSL3_SecurityLevel3::ClientCredsHolder::ClientCredsHolder()
{
#ifdef HAVE_THREADS
    MICOMT::Thread::create_key(thread_key_, NULL);
#else // HAVE_THREADS
    current_creds_ = ClientCredentials::_nil();
#endif // HAVE_THREADS
}


SecurityLevel3::ClientCredentials_ptr
MICOSL3_SecurityLevel3::ClientCredsHolder::csi_creds(const string& key)
{
    if (creds_map_.count(key) > 0) {
	return ClientCredentials::_duplicate(creds_map_[key]);
    }
    return ClientCredentials::_nil();
}


void
MICOSL3_SecurityLevel3::ClientCredsHolder::csi_creds
(const string& key, ClientCredentials_ptr creds)
{
    creds_map_[key] = ClientCredentials::_duplicate(creds);
}


ClientCredentials_ptr
MICOSL3_SecurityLevel3::ClientCredsHolder::current_creds()
{
#ifdef HAVE_THREADS
    ClientCredentials_ptr creds
	= static_cast<ClientCredentials*>
	(MICOMT::Thread::get_specific(thread_key_));
    return ClientCredentials::_duplicate(creds);
#else // HAVE_THREADS
    return ClientCredentials::_duplicate(current_creds_);
#endif // HAVE_THREADS
}


void
MICOSL3_SecurityLevel3::ClientCredsHolder::current_creds
(ClientCredentials_ptr creds)
{
#ifdef HAVE_THREADS
    ClientCredentials_ptr prev_creds
	= static_cast<ClientCredentials*>
	(MICOMT::Thread::get_specific(thread_key_));
    if (!CORBA::is_nil(prev_creds)) {
	CORBA::release(prev_creds);
    }
    MICOMT::Thread::set_specific
	(thread_key_, ClientCredentials::_duplicate(creds));
#else // HAVE_THREADS
    current_creds_ = ClientCredentials::_duplicate(creds);
#endif // HAVE_THREADS
}


void
MICOSL3_SecurityLevel3::ClientCredsHolder::release_credentials(const char* id)
{
    stack<string> key_stack;
    CORBA::Object_ptr ttt = CORBA::Object::_nil();
    for (ClientCredentialsMapIterator it = creds_map_.begin();
	 it != creds_map_.end();
	 it++) {
	OwnCredentials_var tcr = (*it).second->parent_credentials();
	CORBA::String_var parent_id = tcr->creds_id();
	if (strcmp(parent_id.in(), id) == 0) {
	    string key = (*it).first;
	    key_stack.push(key);
	    ttt = creds_map_[key];
	    // notify release
	    ClientCredentials_impl* impl = dynamic_cast<ClientCredentials_impl*>
		(creds_map_[key].in());
	    assert(impl != NULL);
	    impl->notify_release();
	    creds_map_[key] = ClientCredentials::_nil();
	}
    }
    while (!key_stack.empty()) {
	string key = key_stack.top();
	key_stack.pop();
	long i = creds_map_.erase(key);
	assert(i == 1);
    }
    this->current_creds(ClientCredentials::_nil());
}

