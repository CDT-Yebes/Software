// -*- c++ -*-
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


#ifndef __SECURITYLEVEL3_IMPL_H__
#define __SECURITYLEVEL3_IMPL_H__

#include <mico/security/securitylevel3.h>

namespace MICOSL3_SecurityLevel3
{
    // initialization function
    void
    _init();


    class CredsInitiator_impl
	: virtual public SecurityLevel3::CredsInitiator,
	  virtual public CORBA::LocalObject
    {
    public:
	virtual SL3PM::Principal*
	the_principal();

	virtual SL3PM::StatementList*
	supporting_statements();

	virtual SL3PM::ResourceNameList*
	restricted_resources();

	virtual SL3PM::PrinAttributeList*
	environmental_attributes();

	virtual SecurityLevel3::InitiatorType
	initiator_type();

	virtual CORBA::Boolean
	supports_embodiment();

	virtual CORBA::Boolean
	supports_endorsement();

	virtual CORBA::Boolean
	supports_quoting();

	virtual TimeBase::UtcT
	expiry_time();
    protected:
	SL3PM::Principal_var principal_;
	SL3PM::StatementList supporting_statements_;
	SL3PM::ResourceNameList restricted_resources_;
	SL3PM::PrinAttributeList environmental_attributes_;
	SecurityLevel3::InitiatorType initiator_type_;
	CORBA::Boolean supports_embodiment_;
	CORBA::Boolean supports_endorsement_;
	CORBA::Boolean supports_quoting_;
	TimeBase::UtcT expiry_time_;
    };


    class CredsAcceptor_impl
	: virtual public SecurityLevel3::CredsAcceptor,
	  virtual public CORBA::LocalObject
    {
    public:
	virtual SL3PM::Principal*
	the_principal();

	virtual SL3PM::StatementList*
	supporting_statements();

	virtual SL3PM::ResourceNameList*
	restricted_resources();

	virtual SL3PM::PrinAttributeList*
	environmental_attributes();

	virtual CORBA::Boolean
	accepts_endorsement();

	virtual CORBA::Boolean
	accepts_quoting();

	virtual TimeBase::UtcT
	expiry_time();
    protected:
	SL3PM::Principal_var principal_;
	SL3PM::StatementList supporting_statements_;
	SL3PM::ResourceNameList restricted_resources_;
	SL3PM::PrinAttributeList environmental_attributes_;
	CORBA::Boolean accepts_endorsement_;
	CORBA::Boolean accepts_quoting_;
	TimeBase::UtcT expiry_time_;
    };


    class Credentials_impl
	: virtual public SecurityLevel3::Credentials,
	  virtual public CORBA::LocalObject
    {
    public:
	virtual char*
	creds_id();

	virtual SL3CM::CredentialsType
	creds_type();

	virtual SL3CM::CredentialsUsage
	creds_usage();

	virtual SL3CM::CredentialsState
	creds_state();

	// extension
	void
	creds_id(const char* id);

	void
	creds_type(SL3CM::CredentialsType creds_type);

	void
	creds_usage(SL3CM::CredentialsUsage creds_usage);

	void
	creds_state(SL3CM::CredentialsState creds_state);
    protected:
	CORBA::String_var creds_id_;
	SL3CM::CredentialsType creds_type_;
	SL3CM::CredentialsUsage creds_usage_;
	SL3CM::CredentialsState creds_state_;
    };


    class OwnCredentials_impl
	: virtual public Credentials_impl,
	  virtual public SecurityLevel3::OwnCredentials,
	  virtual public CORBA::LocalObject
    {
    public:
	OwnCredentials_impl
	(SL3CM::CredentialsUsage usage,
	 SecurityLevel3::CredsInitiator_ptr initiator,
	 SecurityLevel3::CredsAcceptor_ptr acceptor,
	 const SL3OM::ObserverSeq& observers);

	virtual
	~OwnCredentials_impl();

	virtual SecurityLevel3::CredsInitiator_ptr
	creds_initiator();

	virtual SecurityLevel3::CredsAcceptor_ptr
	creds_acceptor();

	virtual void
	release_credentials();

	// extension

	SL3OM::ObserverSeq*
	observers();

	void
	add_observer(SL3OM::Observer_ptr observer);

	void
	notify_creation();

	void
	notify_remove();

	void
	notify_destroy();
    private:
	SecurityLevel3::CredsInitiator_var initiator_;
	SecurityLevel3::CredsAcceptor_var acceptor_;
	static CORBA::ULong S_creds_index_;
	SL3OM::ObserverSeq observers_;
	std::vector<SL3OM::CredentialsObserver_var> credentials_observers_;
	std::vector<SL3OMExt::CredentialsDestroyObserver_var> destroy_observers_;
    };


    class ClientCredentials_impl
	: virtual public Credentials_impl,
	  virtual public SecurityLevel3::ClientCredentials,
	  virtual public CORBA::LocalObject
    {
    public:
	virtual
	~ClientCredentials_impl();

	virtual char*
	context_id();

	virtual SL3PM::Principal*
	client_principal();

	virtual SL3PM::StatementList*
	client_supporting_statements();

	virtual SL3PM::ResourceNameList*
	client_restricted_resources();

	virtual SL3PM::Principal*
	target_principal();

	virtual SL3PM::StatementList*
	target_supporting_statements();

	virtual SL3PM::ResourceNameList*
	target_restricted_resources();

	virtual SL3PM::PrinAttributeList*
	environmental_attributes();

	virtual SecurityLevel3::OwnCredentials_ptr
	parent_credentials();

	virtual CORBA::Boolean
	client_authentication();

	virtual CORBA::Boolean
	target_authentication();

	virtual CORBA::Boolean
	confidentiality();

	virtual CORBA::Boolean
	integrity();

	// extensions
	void
	context_id(const char* id);

	void
	client_principal(SL3PM::Principal* principal);

	void
	client_supporting_statements
	(const SL3PM::StatementList& statements);

	void
	client_restricted_resources
	(const SL3PM::ResourceNameList& resources);

	void
	target_principal(SL3PM::Principal* principal);

	void
	target_supporting_statements
	(const SL3PM::StatementList& statements);

	void
	target_restricted_resources
	(const SL3PM::ResourceNameList& resources);

	void
	environmental_attributes
	(const SL3PM::PrinAttributeList& attrs);

	void
	parent_credentials(SecurityLevel3::OwnCredentials_ptr creds);

	void
	client_authentication(CORBA::Boolean authentication);

	void
	target_authentication(CORBA::Boolean authentication);

	void
	confidentiality(CORBA::Boolean confidentiality);

	void
	integrity(CORBA::Boolean integrity);

	void
	notify_creation();

	void
	notify_release();

	void
	notify_destroy();
    private:
	CORBA::String_var context_id_;
	SL3PM::Principal_var client_principal_;
	SL3PM::StatementList client_supporting_statements_;
	SL3PM::ResourceNameList client_restricted_resources_;
	SL3PM::Principal_var target_principal_;
	SL3PM::StatementList target_supporting_statements_;
	SL3PM::ResourceNameList target_restricted_resources_;
	SL3PM::PrinAttributeList environmental_attributes_;
	SecurityLevel3::OwnCredentials_var parent_credentials_;
	CORBA::Boolean client_authentication_;
	CORBA::Boolean target_authentication_;
	CORBA::Boolean confidentiality_;
	CORBA::Boolean integrity_;
	std::vector<SL3OM::ClientCredentialsObserver_var> credentials_observers_;
	std::vector<SL3OMExt::ClientCredentialsDestroyObserver_var> destroy_observers_;
    };


    class TargetCredentials_impl
	: virtual public Credentials_impl,
	  virtual public SecurityLevel3::TargetCredentials,
	  virtual public CORBA::LocalObject
    {
    public:
	virtual
	~TargetCredentials_impl();

	virtual char*
	context_id();

	virtual SL3PM::Principal*
	client_principal();

	virtual SL3PM::StatementList*
	client_supporting_statements();

	virtual SL3PM::ResourceNameList*
	client_restricted_resources();

	virtual SL3PM::Principal*
	target_principal();

	virtual SL3PM::StatementList*
	target_supporting_statements();

	virtual SL3PM::ResourceNameList*
	target_restricted_resources();

	virtual SL3PM::PrinAttributeList*
	environmental_attributes();

	virtual SecurityLevel3::OwnCredentials_ptr
	parent_credentials();

	virtual CORBA::Boolean
	client_authentication();

	virtual CORBA::Boolean
	target_authentication();

	virtual CORBA::Boolean
	confidentiality();

	virtual CORBA::Boolean
	integrity();

	virtual CORBA::Boolean
	target_embodied();

	virtual CORBA::Boolean
	target_endorsed();

	virtual void
	release();

	// extensions
	void
	context_id(const char* id);

	void
	client_principal(SL3PM::Principal* principal);

	void
	client_supporting_statements
	(const SL3PM::StatementList& statements);

	void
	client_restricted_resources
	(const SL3PM::ResourceNameList& resources);

	void
	target_principal(SL3PM::Principal* principal);

	void
	target_supporting_statements
	(const SL3PM::StatementList& statements);

	void
	target_restricted_resources
	(const SL3PM::ResourceNameList& resources);

	void
	environmental_attributes
	(const SL3PM::PrinAttributeList& attrs);

	void
	parent_credentials(SecurityLevel3::OwnCredentials_ptr creds);

	void
	client_authentication(CORBA::Boolean authentication);

	void
	target_authentication(CORBA::Boolean authentication);

	void
	confidentiality(CORBA::Boolean confidentiality);

	void
	integrity(CORBA::Boolean integrity);

	void
	target_embodied(CORBA::Boolean embodied);

	void
	target_endorsed(CORBA::Boolean endorsed);

	void
	notify_creation();

	void
	notify_release();

	void
	notify_destroy();
    private:
	CORBA::String_var context_id_;
	SL3PM::Principal_var client_principal_;
	SL3PM::StatementList client_supporting_statements_;
	SL3PM::ResourceNameList client_restricted_resources_;
	SL3PM::Principal_var target_principal_;
	SL3PM::StatementList target_supporting_statements_;
	SL3PM::ResourceNameList target_restricted_resources_;
	SL3PM::PrinAttributeList environmental_attributes_;
	SecurityLevel3::OwnCredentials_var parent_credentials_;
	CORBA::Boolean client_authentication_;
	CORBA::Boolean target_authentication_;
	CORBA::Boolean confidentiality_;
	CORBA::Boolean integrity_;
	CORBA::Boolean target_embodied_;
	CORBA::Boolean target_endorsed_;
	std::vector<SL3OM::TargetCredentialsObserver_var> credentials_observers_;
	std::vector<SL3OMExt::TargetCredentialsDestroyObserver_var> destroy_observers_;
    };


    class CredentialsCurator_impl
	: virtual public SecurityLevel3::CredentialsCurator,
	  virtual public CORBA::LocalObject
    {
    public:
	virtual SecurityLevel3::OwnCredentialsList*
	default_creds_list();

	virtual SL3CM::CredentialsIdList*
	default_creds_ids();

	virtual SecurityLevel3::CredentialsAcquirer_ptr
	acquire_credentials
	(SL3AQArgs::Argument_ptr acquisition_arguments);

	virtual SecurityLevel3::OwnCredentials_ptr
	get_own_credentials(const char* credentials_id);

	virtual void
	release_own_credentials(const char* credentials_id);

	// extension

	void
	add_own_credentials
	(SecurityLevel3::OwnCredentials_ptr creds,
	 CORBA::Boolean on_list);
    private:
	MICOMT::RWLock default_creds_list_lock_;
	SecurityLevel3::OwnCredentialsList default_creds_list_;
	MICOMT::RWLock own_creds_list_lock_;
	SecurityLevel3::OwnCredentialsList own_creds_list_;
    };


    class SecurityManager_impl
	: virtual public SecurityLevel3::SecurityManager,
	  virtual public CORBA::LocalObject
    {
    public:
	SecurityManager_impl(SecurityLevel3::CredentialsCurator_ptr curator);

	virtual SecurityLevel3::CredentialsCurator_ptr
	credentials_curator();

	virtual SecurityLevel3::TargetCredentials_ptr
	get_target_credentials(CORBA::Object_ptr the_object);

	virtual SecurityLevel3::ContextEstablishmentPolicy_ptr
	create_context_estab_policy
	(SL3CM::CredsDirective creds_directive,
	 const SecurityLevel3::OwnCredentialsList& creds_list,
	 SL3CM::FeatureDirective use_client_auth,
	 SL3CM::FeatureDirective use_target_auth,
	 SL3CM::FeatureDirective use_confidentiality,
	 SL3CM::FeatureDirective use_integrity);

	virtual SecurityLevel3::ObjectCredentialsPolicy_ptr
	create_object_creds_policy
	(const SecurityLevel3::OwnCredentialsList& creds_list);
    private:
	SecurityLevel3::CredentialsCurator_var curator_;
    };


    class SecurityCurrent_impl
	: virtual public SecurityLevel3::SecurityCurrent,
	  virtual public CORBA::LocalObject
    {
    public:
	virtual SecurityLevel3::ClientCredentials_ptr
	client_credentials();

	virtual CORBA::Boolean
	request_is_local();
    };


    class ContextEstablishmentPolicy_impl
	: virtual public SecurityLevel3::ContextEstablishmentPolicy,
	  virtual public CORBA::LocalObject
    {
    public:
	ContextEstablishmentPolicy_impl
	(SL3CM::CredsDirective creds_directive,
	 const SecurityLevel3::OwnCredentialsList& creds_list,
	 SL3CM::FeatureDirective use_client_auth,
	 SL3CM::FeatureDirective use_target_auth,
	 SL3CM::FeatureDirective use_confidentiality,
	 SL3CM::FeatureDirective use_integrity);

	virtual
	~ContextEstablishmentPolicy_impl();

	virtual SecurityLevel3::OwnCredentialsList*
	creds_list();

	virtual SL3CM::CredsDirective
	creds_directive();

	virtual SL3CM::FeatureDirective
	use_client_auth();

	virtual SL3CM::FeatureDirective
	use_target_auth();

	virtual SL3CM::FeatureDirective
	use_confidentiality();

	virtual SL3CM::FeatureDirective
	use_integrity();

	// Policy operations

	virtual CORBA::PolicyType
	policy_type();

	virtual CORBA::Policy_ptr
	copy();

	virtual void
	destroy();

    private:
	SecurityLevel3::OwnCredentialsList creds_list_;
	SL3CM::CredsDirective creds_directive_;
	SL3CM::FeatureDirective	use_client_auth_;
	SL3CM::FeatureDirective	use_target_auth_;
	SL3CM::FeatureDirective	use_confidentiality_;
	SL3CM::FeatureDirective	use_integrity_;
    };


    //
    // various supporting classes
    //

    class ORBInitializer
	: virtual public PortableInterceptor::ORBInitializer,
	  virtual public CORBA::LocalObject
    {
    public:
	ORBInitializer();

	virtual
	~ORBInitializer();

	virtual void
	pre_init(PortableInterceptor::ORBInitInfo_ptr info);

	virtual void
	post_init(PortableInterceptor::ORBInitInfo_ptr info);
    };


    class TargetCredsHolder
    {
    public:
	SecurityLevel3::TargetCredentials_ptr
	csi_creds(const std::string& key);

	void
	csi_creds
	(const std::string& key,
	 SecurityLevel3::TargetCredentials_ptr creds);

	void
	release_credentials(const char* id);
    private:
	typedef std::map<std::string, SecurityLevel3::TargetCredentials_var, std::less<std::string> > TargetCredentialsMap;
	typedef std::map<std::string, SecurityLevel3::TargetCredentials_var, std::less<std::string> >::iterator
	TargetCredentialsMapIterator;
	TargetCredentialsMap creds_map_;
    };


    class ClientCredsHolder
    {
    public:
	ClientCredsHolder();

	SecurityLevel3::ClientCredentials_ptr
	csi_creds(const std::string& key);

	void
	csi_creds
	(const std::string& key,
	 SecurityLevel3::ClientCredentials_ptr creds);

	SecurityLevel3::ClientCredentials_ptr
	current_creds();

	void
	current_creds(SecurityLevel3::ClientCredentials_ptr creds);

	void
	release_credentials(const char* id);
    private:
	typedef std::map<std::string, SecurityLevel3::ClientCredentials_var, std::less<std::string> > ClientCredentialsMap;
	typedef std::map<std::string, SecurityLevel3::ClientCredentials_var, std::less<std::string> >::iterator
	ClientCredentialsMapIterator;
	ClientCredentialsMap creds_map_;
#ifdef HAVE_THREADS
	MICOMT::Thread::ThreadKey thread_key_;
#else // HAVE_THREADS
	SecurityLevel3::ClientCredentials_var current_creds_;
#endif // HAVE_THREADS
    };
} // MICOSL3_SecurityLevel3

#endif // __SECURITYLEVEL3_IMPL_H__

