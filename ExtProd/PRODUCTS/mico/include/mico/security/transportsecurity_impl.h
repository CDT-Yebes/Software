// -*- c++ -*-
//
//  MICO SL3 --- an Open Source SL3 implementation
//  Copyright (C) 2002, 2003, 2004, 2005, 2006, 2008 ObjectSecurity Ltd.
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


#ifndef __TRANSPORTSECURITY_IMPL_H__
#define __TRANSPORTSECURITY_IMPL_H__

#include <mico/security/transportsecurity.h>
#include <mico/security/securitylevel3_impl.h>
#include <mico/security/transportsecurity_p.h>


namespace MICOSL3_TransportSecurity
{
    // initialization function
    void
    _init();


    class CredentialsInitiator_impl
	: virtual public TransportSecurity::CredentialsInitiator,
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
	supports_embodiment();

	virtual CORBA::Boolean
	supports_endorsement();

	virtual CORBA::Boolean
	supports_quoting();

	virtual CORBA::Boolean
	supports_client_authentication();

	virtual CORBA::Boolean
	supports_target_authentication();

	virtual CORBA::Boolean
	supports_confidentiality();

	virtual CORBA::Boolean
	supports_integrity();

	virtual TimeBase::UtcT
	expiry_time();
    protected:
	SL3PM::Principal* principal_;
	SL3PM::StatementList statement_list_;
	SL3PM::ResourceNameList rsname_list_;
	SL3PM::PrinAttributeList environmental_attributes_;
	CORBA::Boolean supports_embodiment_;
	CORBA::Boolean supports_endorsement_;
	CORBA::Boolean supports_quoting_;
	CORBA::Boolean supports_client_authentication_;
	CORBA::Boolean supports_target_authentication_;
	CORBA::Boolean supports_confidentiality_;
	CORBA::Boolean supports_integrity_;
	TimeBase::UtcT expiry_time_;
    };


    class CredentialsAcceptor_impl
	: virtual public TransportSecurity::CredentialsAcceptor,
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
	supports_endorsement();

	virtual CORBA::Boolean
	supports_quoting();

	virtual CORBA::Boolean
	supports_client_authentication();

	virtual CORBA::Boolean
	supports_target_authentication();

	virtual CORBA::Boolean
	supports_confidentiality();

	virtual CORBA::Boolean
	supports_integrity();

	virtual TimeBase::UtcT
	expiry_time();
    protected:
	SL3PM::Principal* principal_;
	SL3PM::StatementList statement_list_;
	SL3PM::ResourceNameList rsname_list_;
	SL3PM::PrinAttributeList environmental_attributes_;
	CORBA::Boolean supports_endorsement_;
	CORBA::Boolean supports_quoting_;
	CORBA::Boolean supports_client_authentication_;
	CORBA::Boolean supports_target_authentication_;
	CORBA::Boolean supports_confidentiality_;
	CORBA::Boolean supports_integrity_;
	TimeBase::UtcT expiry_time_;
    };


    class TransportCredentials_impl
	: virtual public TransportSecurity::TransportCredentials,
	  virtual public CORBA::LocalObject
    {
    public:
	TransportCredentials_impl();

	TransportCredentials_impl
	(const char* id,
	 SL3CM::CredentialsState state,
	 SL3CM::CredentialsType type,
	 SL3CM::CredentialsUsage usage,
	 TimeBase::UtcT time);

	virtual char*
	creds_id();

	virtual SL3CM::CredentialsState
	creds_state();

	virtual SL3CM::CredentialsType
	creds_type();

	virtual SL3CM::CredentialsUsage
	creds_usage();

	virtual TimeBase::UtcT
	expiry_time();

	// extension
	void
	creds_state(SL3CM::CredentialsState state);
    protected:
	CORBA::String_var creds_id_;
	SL3CM::CredentialsState creds_state_;
	SL3CM::CredentialsType creds_type_;
	SL3CM::CredentialsUsage creds_usage_;
	TimeBase::UtcT expiry_time_;
    };


    class OwnCredentials_impl
	: virtual public TransportCredentials_impl,
	  virtual public TransportSecurity::OwnCredentials,
	  virtual public CORBA::LocalObject
    {
    public:
	OwnCredentials_impl
	(const char* id,
	 SL3CM::CredentialsState state,
	 SL3CM::CredentialsType type,
	 SL3CM::CredentialsUsage usage,
	 TimeBase::UtcT time,
	 TransportSecurity::CredentialsInitiator_ptr initiator,
	 TransportSecurity::CredentialsAcceptor_ptr acceptor,
	 CORBA::Boolean csiv1_support,
	 CORBA::Boolean csiv2_support,
	 const SL3OM::ObserverSeq& observers);

	virtual ~OwnCredentials_impl();

	virtual TransportSecurity::CredentialsInitiator_ptr
	the_initiator();

	virtual TransportSecurity::CredentialsAcceptor_ptr
	the_acceptor();

	virtual CORBA::Boolean
	supports_csi_version(TransportSecurity::CSIVersion version);

	virtual void
	release_credentials();

	virtual void
	externalize_credentials
	(const char* externalization_type,
	 const char* dest_url);

	// extension

	SL3OM::ObserverSeq*
	observers();

	void
	notify_creation();

	void
	notify_remove();

	void
	notify_destroy();
    private:
	TransportSecurity::CredentialsInitiator_var initiator_;
	TransportSecurity::CredentialsAcceptor_var acceptor_;
	CORBA::Boolean csiv1_support_;
	CORBA::Boolean csiv2_support_;
	SL3OM::ObserverSeq observers_;
	std::vector<SL3OM::CredentialsObserver_var> credentials_observers_;
	std::vector<SL3OMExt::CredentialsDestroyObserver_var> destroy_observers_;
    };


    class ClientCredentials_impl
	: virtual public TransportCredentials_impl,
	  virtual public TransportSecurity::ClientCredentials,
	  virtual public CORBA::LocalObject
    {
    public:
	ClientCredentials_impl
	(TransportSecurity::OwnCredentials_ptr parent_credentials);

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

	virtual TransportSecurity::OwnCredentials_ptr
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
	impersonable();

	virtual CORBA::Boolean
	endorseable();

	virtual CORBA::Boolean
	quotable();
    protected:
	CORBA::String_var context_id_;
	SL3PM::Principal* client_principal_;
	SL3PM::StatementList client_supporting_statements_;
	SL3PM::ResourceNameList client_restricted_resources_;
	SL3PM::Principal* target_principal_;
	SL3PM::StatementList target_supporting_statements_;
	SL3PM::ResourceNameList target_restricted_resources_;
	SL3PM::PrinAttributeList environmental_attributes_;
	TransportSecurity::OwnCredentials_var parent_credentials_;
	CORBA::Boolean client_authentication_;
	CORBA::Boolean target_authentication_;
	CORBA::Boolean confidentiality_;
	CORBA::Boolean integrity_;
	CORBA::Boolean impersonable_;
	CORBA::Boolean endorseable_;
	CORBA::Boolean quotable_;
    };


    class TargetCredentials_impl
	: virtual public TransportCredentials_impl,
	  virtual public TransportSecurity::TargetCredentials,
	  virtual public CORBA::LocalObject
    {
    public:
	TargetCredentials_impl
	(TransportSecurity::OwnCredentials_ptr parent_credentials);

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

	virtual TransportSecurity::OwnCredentials_ptr
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
    protected:
	CORBA::String_var context_id_;
	SL3PM::Principal_var client_principal_;
	SL3PM::StatementList client_supporting_statements_;
	SL3PM::ResourceNameList client_restricted_resources_;
	SL3PM::Principal_var target_principal_;
	SL3PM::StatementList target_supporting_statements_;
	SL3PM::ResourceNameList target_restricted_resources_;
	SL3PM::PrinAttributeList environmental_attributes_;
	TransportSecurity::OwnCredentials_var parent_credentials_;
	CORBA::Boolean client_authentication_;
	CORBA::Boolean target_authentication_;
	CORBA::Boolean confidentiality_;
	CORBA::Boolean integrity_;
	CORBA::Boolean target_embodied_;
	CORBA::Boolean target_endorsed_;
    };


    class CredentialsCurator_impl
	: virtual public TransportSecurity::CredentialsCurator,
	  virtual public CORBA::LocalObject
    {
    public:
	virtual TransportSecurity::OwnCredentialsList*
	default_creds_list();

	virtual TransportSecurity::CredentialsAcquirer_ptr
	acquire_credentials
	(SL3AQArgs::Argument_ptr acquisition_arguments);

	virtual TransportSecurity::OwnCredentials_ptr
	get_own_credentials(const char* creds_id);

	virtual void
	remove_credentials(const char* creds_id);

	virtual void
	release_credentials(const char* creds_id);

	// extension

	void
	register_acquirer_factory
	(TransportSecurity::CredentialsAcquirerFactory_ptr factory);

	void
	add_own_credentials
	(TransportSecurity::OwnCredentials_ptr creds,
	 CORBA::Boolean on_list);

	void
	add_init_context(TransportSecurity::InitiatingContext_ptr ctx);

	TransportSecurity::TargetCredentials_ptr
	get_target_credentials
	(CORBA::Object_ptr obj,
	 CORBA::Boolean include_ipc_creds);

        TransportSecurity::OwnCredentials_ptr
        find_own_credentials_for(const CORBA::Address* addr);
    private:
	void
	remove_creds_from_default_creds_list(const char* creds_id);

	void
	remove_creds_from_own_creds_list(const char* creds_id);

	std::vector<TransportSecurity::CredentialsAcquirerFactory_ptr>
	factories_;
	typedef std::vector<TransportSecurity::CredentialsAcquirerFactory_ptr>::iterator
	fact_iter_type;
	TransportSecurity::OwnCredentialsList own_creds_list_;
	TransportSecurity::OwnCredentialsList default_creds_list_;
	std::vector<TransportSecurity::InitiatingContext_var> init_contexts_;
	typedef std::vector<TransportSecurity::InitiatingContext_var>::iterator ic_iter_type;
    };


    class SecurityCurrent_impl
	: virtual public TransportSecurity::SecurityCurrent,
	  virtual public CORBA::LocalObject
    {
    public:
	SecurityCurrent_impl();

	virtual TransportSecurity::ClientCredentials_ptr
	client_credentials();

	// extension
	void
	push_client_credentials(TransportSecurity::ClientCredentials_ptr creds);

        void
        pop_client_credentials();
    private:
        typedef std::stack<TransportSecurity::ClientCredentials_var> CCStack;
#ifndef HAVE_THREADS
        CCStack client_credentials_stack_;
#else // HAVE_THREADS
	MICOMT::Thread::ThreadKey thread_key_;
#endif // HAVE_THREADS
    };
    

    class SecurityManager_impl
	: virtual public TransportSecurity::SecurityManager,
	  virtual public CORBA::LocalObject
    {
    public:
	SecurityManager_impl
	(CredentialsCurator_impl* curator,
	 CORBA::Boolean enabled);

	virtual TransportSecurity::CredentialsCurator_ptr
	credentials_curator();

	virtual TransportSecurity::TargetCredentials_ptr
	get_target_credentials(CORBA::Object_ptr the_object);

	virtual TransportSecurity::ContextEstablishmentPolicy_ptr
	create_context_estab_policy
	(SL3CM::CredsDirective creds_directive,
	 const TransportSecurity::OwnCredentialsList& creds_list,
	 SL3CM::FeatureDirective use_client_auth,
	 SL3CM::FeatureDirective use_target_auth,
	 SL3CM::FeatureDirective use_confidentiality,
	 SL3CM::FeatureDirective use_integrity);

	virtual TransportSecurity::ObjectCredentialsPolicy_ptr
	create_object_creds_policy
	(const TransportSecurity::OwnCredentialsList& creds_list);

	// extension

	virtual CORBA::Boolean
	security_enabled();

    private:
	CredentialsCurator_impl* curator_;
	CORBA::Boolean security_enabled_;
    };


    class InitiatingContext_impl
	: virtual public MICOSL3_TransportSecurity::TargetCredentials_impl,
	  virtual public MICOSL3_SecurityLevel3::TargetCredsHolder,
	  virtual public TransportSecurity::InitiatingContext,
	  virtual public CORBA::LocalObject
    {
    public:
	InitiatingContext_impl
	(TransportSecurity::OwnCredentials_ptr parent_credentials);

	virtual
	~InitiatingContext_impl();

	virtual CORBA::Boolean
	is_usable
	(const char* host,
	 CORBA::ULong port,
	 SL3CM::CredsDirective creds_directive,
	 SL3CM::FeatureDirective client_authentication,
	 SL3CM::FeatureDirective target_authentication,
	 SL3CM::FeatureDirective confidentiality,
	 SL3CM::FeatureDirective integrity,
	 TransportSecurity::CSIVersion csi_version,
	 const IOP::TaggedComponentSeq& transport_components);

	virtual void
	shutdown();

	// CredentialsObserver operations
	virtual char*
	name();

	virtual void
	create_credentials(const char* id);

	virtual void
	relinquish_credentials(const char* id);

	// extension
	void
	notify_establish_context();

	void
	notify_close_context();

	void
	notify_destroy_context();
    private:
	std::vector<SL3OM::InitiatingContextObserver_var> context_observers_;
	std::vector<SL3OMExt::InitiatingContextDestroyObserver_var>
	destroy_observers_;
    };


    class AcceptingContext_impl
	: virtual public ClientCredentials_impl,
	  virtual public MICOSL3_SecurityLevel3::ClientCredsHolder,
	  virtual public TransportSecurity::AcceptingContext,
	  virtual public CORBA::LocalObject
    {
    public:
	AcceptingContext_impl
	(TransportSecurity::OwnCredentials_ptr parent_credentials);

	virtual
	~AcceptingContext_impl();

	virtual TransportSecurity::IdentityTokenGenerator_ptr
	create_client_identity_token_generator();

	// CredentialsObserver operations
	virtual char*
	name();

	virtual void
	create_credentials(const char* id);

	virtual void
	relinquish_credentials(const char* id);

	// extension
	void
	notify_establish_context();

	void
	notify_close_context();

	void
	notify_destroy_context();
    private:
	std::vector<SL3OM::AcceptingContextObserver_var> context_observers_;
	std::vector<SL3OMExt::AcceptingContextDestroyObserver_var>
	destroy_observers_;
    };


    class TransportInitiator_impl
	: virtual public CredentialsInitiator_impl,
	  virtual public TransportSecurity::TransportInitiator,
	  virtual public CORBA::LocalObject
    {
    public:
	virtual TransportSecurity::ContextEstablisherList*
	context_establishers();

	virtual char*
	host();

	virtual CORBA::ULong
	low_port();

	virtual CORBA::ULong
	high_port();

	virtual void
	increment_work();

	virtual void
	decrement_work();

	virtual CORBA::Boolean
	supports_invoc_options
	(CSIIOP::AssociationOptions invocation_options_supported,
	 CSIIOP::AssociationOptions invocation_options_required);

	virtual CORBA::Boolean
	supports_csi_version(TransportSecurity::CSIVersion csi_version);

	virtual CORBA::Boolean
	is_usable
	(const char* host,
	 CORBA::ULong port,
	 SL3CM::CredsDirective creds_directive,
	 SL3CM::FeatureDirective client_authentication,
	 SL3CM::FeatureDirective target_authentication,
	 SL3CM::FeatureDirective confidentiality,
	 SL3CM::FeatureDirective integrity,
	 TransportSecurity::CSIVersion csi_version,
	 const IOP::TaggedComponentSeq& transport_components);

	virtual TransportSecurity::ContextEstablisherList*
	create_context_establishers
	(const char* host,
	 CORBA::ULong port,
	 SL3CM::CredsDirective creds_directive,
	 SL3CM::FeatureDirective client_authentication,
	 SL3CM::FeatureDirective target_authentication,
	 SL3CM::FeatureDirective confidentiality,
	 SL3CM::FeatureDirective integrity,
	 TransportSecurity::CSIVersion csi_version,
	 const IOP::TaggedComponentSeq& transport_components);

	virtual TransportSecurity::ContextEstablisher_ptr
	get_context_establisher(const char* id);

    protected:
	CORBA::String_var host_;
	CORBA::ULong low_port_;
	CORBA::ULong high_port_;
    };


    class TransportAcceptor_impl
	: virtual public CredentialsAcceptor_impl,
	  virtual public TransportSecurity::TransportAcceptor,
	  virtual public CORBA::LocalObject
    {
    public:
	virtual CORBA::StringSeq*
	hosts();

	CORBA::ULong
	port();

	virtual CSIIOP::AssociationOptions
	options_required();

	virtual CSIIOP::AssociationOptions
	options_supported();

	virtual void
	increment_work();

	virtual void
	decrement_work();

	virtual IOP::TaggedComponentSeq*
	transport_components(TransportSecurity::CSIVersion csi_version);

	virtual CORBA::Boolean
	transport_matches
	(const char* host,
	 CORBA::ULong port,
	 const IOP::TaggedComponentSeq& transport_components);

	virtual TransportSecurity::AcceptingContext_ptr
	accept(CORBA::Boolean block);

	virtual void
	shutdown();

	virtual void
	enable();

    protected:
	CORBA::StringSeq hosts_;
	CORBA::ULong port_;
	CSIIOP::AssociationOptions options_required_;
	CSIIOP::AssociationOptions options_supported_;
    };


    class ContextEstablishmentPolicy_impl
	: virtual public TransportSecurity::ContextEstablishmentPolicy,
	  virtual public CORBA::LocalObject
    {
    public:
	ContextEstablishmentPolicy_impl
	(SL3CM::CredsDirective creds_directive,
	 const TransportSecurity::OwnCredentialsList& creds_list,
	 SL3CM::FeatureDirective use_client_auth,
	 SL3CM::FeatureDirective use_target_auth,
	 SL3CM::FeatureDirective use_confidentiality,
	 SL3CM::FeatureDirective use_integrity);

	virtual TransportSecurity::OwnCredentialsList*
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
	TransportSecurity::OwnCredentialsList creds_list_;
	SL3CM::CredsDirective creds_directive_;
	SL3CM::FeatureDirective	use_client_auth_;
	SL3CM::FeatureDirective	use_target_auth_;
	SL3CM::FeatureDirective	use_confidentiality_;
	SL3CM::FeatureDirective	use_integrity_;
    };


    class ObjectCredentialsPolicy_impl
	: virtual public TransportSecurity::ObjectCredentialsPolicy,
	  virtual public CORBA::LocalObject
    {
    public:
        ObjectCredentialsPolicy_impl
	(const TransportSecurity::OwnCredentialsList& creds_list);

        virtual TransportSecurity::OwnCredentialsList*
        creds_list();

	// Policy operations

	virtual CORBA::PolicyType
	policy_type();

	virtual CORBA::Policy_ptr
	copy();

	virtual void
	destroy();

    private:
        TransportSecurity::OwnCredentialsList creds_list_;
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

    class CredentialsCuratorImplUser
    {
    public:
        virtual ~CredentialsCuratorImplUser()
        {}

	virtual void
	creds_curator_impl(CredentialsCurator_impl* curator) = 0;
    };

    class TSServerRequestInterceptor
	: virtual public PortableInterceptor::ServerRequestInterceptor,
	  virtual public CORBA::LocalObject
    {
    public:
        TSServerRequestInterceptor
	(SecurityManager_impl* secman,
	 SecurityCurrent_impl* current,
	 const char* name);

	virtual char*
	name();

	virtual void
	destroy();

	virtual void
	receive_request_service_contexts
	(PortableInterceptor::ServerRequestInfo_ptr ri);

	virtual void
	receive_request(PortableInterceptor::ServerRequestInfo_ptr ri);

	virtual void
	send_reply(PortableInterceptor::ServerRequestInfo_ptr ri);

	virtual void
	send_exception(PortableInterceptor::ServerRequestInfo_ptr ri);

	virtual void
	send_other(PortableInterceptor::ServerRequestInfo_ptr ri);

    private:
	SecurityManager_impl* secman_;
	SecurityCurrent_impl* current_;
	CORBA::String_var name_;
    };
} // MICOSL3_TransportSecurity

#endif // __TRANSPORTSECURITY_IMPL_H__
