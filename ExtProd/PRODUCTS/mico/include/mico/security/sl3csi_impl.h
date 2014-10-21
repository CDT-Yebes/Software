// -*- c++ -*-
//
//  MICO SL3 --- an Open Source SL3 implementation
//  Copyright (C) 2003, 2004 ObjectSecurity Ltd.
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


#ifndef __SL3CSI_IMPL_H__
#define __SL3CSI_IMPL_H__

#include <mico/security/sl3aqargs_impl.h>
#include <mico/security/sl3csi.h>
#include <mico/security/securitylevel3_impl.h>


namespace MICOSL3_SL3CSI
{
    // initialization function
    void
    _init();


    class ArgBuilder_impl
	: virtual public MICOSL3_SL3AQArgs::ArgBuilder_impl,
	  virtual public SL3CSI::CSIArgBuilder,
	  virtual public CORBA::LocalObject
    {
    public:
	ArgBuilder_impl(SL3CM::CredentialsUsage usage);

	virtual
	~ArgBuilder_impl();

	virtual void
	add_password_generator(UserPassword::PasswordGenerator_ptr generator);

	virtual void
	add_password_processor(UserPassword::PasswordProcessor_ptr processor);

	virtual void
	add_named_quoted_principal(const SL3PM::PrincipalName& principal_name);

	virtual void
	add_encoded_quoted_principal(SL3PM::IdentityStatement* identity);

	virtual void
	add_trust_in_server_decider
	(Trust::LocalTrustInServerDecider_ptr trust_decider);

	virtual void
	add_transport_credentials
	(TransportSecurity::OwnCredentials_ptr credentials);

	virtual void
	add_credentials_observer(SL3OM::CredentialsObserver_ptr observer);

	virtual void
	add_client_credentials_observer(SL3OM::ClientCredentialsObserver_ptr observer);

	virtual void
	add_target_credentials_observer(SL3OM::TargetCredentialsObserver_ptr observer);

	virtual void
	add_ATLAS_object
	(const ATLAS::ATLASCacheId& cache_id,
	 ATLAS::AuthTokenDispenser_ptr token_dispenser,
	 SL3Authorization::TokenProcessor_ptr token_processor);

	virtual void
	add_token_processor
	(SL3Authorization::TokenProcessor_ptr token_processor);

	virtual void
	add_identity_processor
	(SL3TLS::TLSX509IdentityProcessor_ptr processor);

	virtual SL3AQArgs::Argument_ptr
	reap_args();
    private:
  	UserPassword::PasswordGenerator_var generator_;
  	UserPassword::PasswordProcessor_var processor_;
//  	SL3AQArgs::ArgNamedQuotedPrincipal_var named_quoted_principal_;
//  	SL3AQArgs::ArgEncodedQuotedPrincipal_var encoded_quoted_principal_;
  	Trust::LocalTrustInServerDecider_var decider_;
	TransportSecurity::OwnCredentials_var transport_creds_;
	SL3PM::QuotingPrincipal_var quoting_principal_;
	ATLAS::ATLASCacheId cache_id_;
	ATLAS::AuthTokenDispenser_var token_dispenser_;
	SL3Authorization::TokenProcessor_var token_processor_;
	//std::vector<SL3Authorization::TokenProcessor_var> tps_;
	SL3AQArgs::TokenProcessorSeq tpseq_;
	SL3OM::ObserverSeq observers_;
	SL3TLS::TLSX509IdentityProcessor_var identity_processor_;
    };


    class ArgumentFactory_impl
	: virtual public SL3AQArgs::ArgBuilderFactory,
	  virtual public CORBA::LocalObject
    {
    public:
	virtual SL3AQArgs::ArgBuilder_ptr
	create_arg_builder(SL3CM::CredentialsUsage usage);
    };


    class CSICredsInitiator
	: virtual public MICOSL3_SecurityLevel3::CredsInitiator_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	CSICredsInitiator
	(TransportSecurity::OwnCredentials_ptr creds,
	 UserPassword::PasswordGenerator_ptr generator,
	 Trust::LocalTrustInServerDecider_ptr decider,
	 SL3PM::QuotingPrincipal* quoting_principal,
	 const SL3AQArgs::TokenProcessorSeq& tpseq);

	virtual
	~CSICredsInitiator();

	UserPassword::PasswordGenerator_ptr
	password_generator();

	Trust::LocalTrustInServerDecider_ptr
	trust_decider();

	TransportSecurity::OwnCredentials_ptr
	transport_credentials();

	SL3AQArgs::TokenProcessorSeq*
	tpseq();
    private:
	UserPassword::PasswordGenerator_var generator_;
	Trust::LocalTrustInServerDecider_var trust_decider_;
	TransportSecurity::OwnCredentials_var transport_creds_;
	SL3AQArgs::TokenProcessorSeq tpseq_;
    };


    class CSICredsAcceptor
	: virtual public MICOSL3_SecurityLevel3::CredsAcceptor_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	CSICredsAcceptor
	(TransportSecurity::OwnCredentials_ptr creds,
	 UserPassword::PasswordProcessor_ptr processor,
	 SL3PM::QuotingPrincipal* quoting_principal,
	 const ATLAS::ATLASCacheId& cache_id,
	 ATLAS::AuthTokenDispenser_ptr token_dispenser,
	 SL3Authorization::TokenProcessor_ptr token_processor,
	 SL3TLS::TLSX509IdentityProcessor_ptr identity_processor);

	UserPassword::PasswordProcessor_ptr
	password_processor();

	ATLAS::ATLASCacheId*
	cache_id();

	ATLAS::AuthTokenDispenser_ptr
	token_dispenser();

	SL3Authorization::TokenProcessor_ptr
	token_processor();

	SL3TLS::TLSX509IdentityProcessor_ptr
	identity_processor();
    private:
	UserPassword::PasswordProcessor_var processor_;
	ATLAS::ATLASCacheId cache_id_;
	ATLAS::AuthTokenDispenser_var token_dispenser_;
	CORBA::Boolean supports_delegation_by_client_;
	CORBA::Boolean requires_delegation_by_client_;
	SL3Authorization::TokenProcessor_var token_processor_;
	SL3TLS::TLSX509IdentityProcessor_var identity_processor_;
    };


    class CredentialsAcquirer_impl
	: virtual public SecurityLevel3::CredentialsAcquirer,
	  virtual public CORBA::LocalObject
    {
    public:
	CredentialsAcquirer_impl
	(MICOSL3_SecurityLevel3::CredentialsCurator_impl* curator,
	 SL3AQArgs::Argument_ptr value);

	virtual
	~CredentialsAcquirer_impl();

	virtual SecurityLevel3::OwnCredentials_ptr
	get_credentials(CORBA::Boolean on_list);

	virtual void
	destroy();
    private:
	MICOSL3_SecurityLevel3::CredentialsCurator_impl* curator_;
	SecurityLevel3::OwnCredentials_var creds_;
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
}

#endif // __SL3CSI_IMPL_H__
