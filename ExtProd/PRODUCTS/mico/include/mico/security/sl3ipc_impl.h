// -*- c++ -*-
//
//  MICO SL3 --- an Open Source SL3 implementation
//  Copyright (C) 2004 ObjectSecurity Ltd.
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


#ifndef __SL3IPC_IMPL_H__
#define __SL3IPC_IMPL_H__

#include <mico/security/sl3ipc.h>
#include <mico/security/transportsecurity_impl.h>
#include <mico/security/sl3aqargs_impl.h>


namespace MICOSL3_SL3IPC
{
    // initialization function
    void
    _init();


    class ArgBuilder_impl
	: virtual public MICOSL3_SL3AQArgs::ArgBuilder_impl,
	  virtual public SL3IPC::IPCArgBuilder,
	  virtual public CORBA::LocalObject
    {
    public:
	ArgBuilder_impl(SL3CM::CredentialsUsage usage);

	virtual void
	add_CSIv1_support(CORBA::Boolean support);

	virtual void
	add_CSIv2_support(CORBA::Boolean support);

	virtual void
	add_accepting_context_observer(SL3OM::AcceptingContextObserver_ptr observer);

	virtual void
	add_initiating_context_observer(SL3OM::InitiatingContextObserver_ptr observer);

	virtual void
	add_credentials_observer(SL3OM::CredentialsObserver_ptr observer);

	virtual SL3AQArgs::Argument_ptr
	reap_args();
    private:
	CORBA::Boolean csiv1_support_;
	CORBA::Boolean csiv2_support_;
	SL3OM::ObserverSeq observers_;
    };


    class ArgumentFactory_impl
	: virtual public SL3AQArgs::ArgBuilderFactory,
	  virtual public CORBA::LocalObject
    {
    public:
	virtual SL3AQArgs::ArgBuilder_ptr
	create_arg_builder(SL3CM::CredentialsUsage usage);	
    };


    class CredentialsAcquirer_impl
	: virtual public TransportSecurity::CredentialsAcquirer,
	  virtual public MICOSL3_TransportSecurity::CredentialsCuratorImplUser,
	  virtual public CORBA::LocalObject
    {
    public:
	CredentialsAcquirer_impl(SL3AQArgs::Argument_ptr value);

	virtual
	~CredentialsAcquirer_impl();

	virtual TransportSecurity::OwnCredentials_ptr
	get_credentials(CORBA::Boolean on_list);

	virtual void
	destroy();

	// extension
	virtual void
	creds_curator_impl
	(MICOSL3_TransportSecurity::CredentialsCurator_impl* curator);
    private:
	MICOSL3_TransportSecurity::CredentialsCurator_impl* curator_impl_;
	TransportSecurity::OwnCredentials_var creds_;
	static CORBA::ULong S_creds_index_;
    };


    //
    // Factory
    // 
    class CredentialsAcquirerFactory_impl
	: virtual public TransportSecurity::CredentialsAcquirerFactory,
	  virtual public CORBA::LocalObject
    {
    public:
	CredentialsAcquirerFactory_impl();

	virtual TransportSecurity::CredentialsAcquirer_ptr
	create(SL3AQArgs::Argument_ptr value);

	virtual CORBA::Boolean
	supports_all_args(SL3AQArgs::Argument_ptr value);
    private:
	std::map<std::string, bool> supported_types_;
    };


    class IPCInitiator
	: virtual public MICOSL3_TransportSecurity::TransportInitiator_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	IPCInitiator(SL3AQArgs::Argument_ptr arg);
    };


    class IPCAcceptor
	: virtual public MICOSL3_TransportSecurity::TransportAcceptor_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	IPCAcceptor(SL3AQArgs::Argument_ptr arg);

	virtual void
	shutdown();

	virtual void
	enable();
    };


    class IPCInitiatingContext
	: virtual public MICOSL3_TransportSecurity::InitiatingContext_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	IPCInitiatingContext
	(TransportSecurity::OwnCredentials_ptr parent);

    private:
	static CORBA::ULong S_ctx_index_;
    };


    class IPCAcceptingContext
	: virtual public MICOSL3_TransportSecurity::AcceptingContext_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	IPCAcceptingContext
	(TransportSecurity::OwnCredentials_ptr parent);

    private:
	static CORBA::ULong S_ctx_index_;
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


    class IPCCredsMapper
    {
    public:
	IPCCredsMapper();

	static IPCCredsMapper*
	self();

	TransportSecurity::ClientCredentials_ptr
	get_client_credentials(TransportSecurity::OwnCredentials_ptr creds);

	TransportSecurity::TargetCredentials_ptr
	get_target_credentials(TransportSecurity::OwnCredentials_ptr creds);

	void
	add_client_credentials
	(TransportSecurity::OwnCredentials_ptr own_creds,
	 TransportSecurity::ClientCredentials_ptr client_creds);

	void
	add_target_credentials
	(TransportSecurity::OwnCredentials_ptr own_creds,
	 TransportSecurity::TargetCredentials_ptr target_creds);

	void
	remove_credentials(TransportSecurity::OwnCredentials_ptr own_creds);
    private:
	// self static reference
	static IPCCredsMapper* mapper_;
	// maps
	std::map<std::string, TransportSecurity::ClientCredentials_var, std::less<std::string> >
	client_creds_map_;
	std::map<std::string, TransportSecurity::TargetCredentials_var, std::less<std::string> >
	target_creds_map_;	
    };


    class IPCCredsCreator
    {
    public:
	TransportSecurity::ClientCredentials_ptr
	create_client_credentials
	(TransportSecurity::OwnCredentials_ptr own_creds);

	TransportSecurity::TargetCredentials_ptr
	create_target_credentials
	(TransportSecurity::OwnCredentials_ptr own_creds);
    };
} // MICOSL3_SL3IPC

#endif // __SL3IPC_IMPL_H__
