// -*- c++ -*-
//
//  MICO SL3 --- an Open Source SL3 implementation
//  Copyright (C) 2002, 2003, 2004, 2005, 2006 ObjectSecurity Ltd.
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


#ifndef __SL3TCPIP_IMPL_H__
#define __SL3TCPIP_IMPL_H__

#include <mico/security/sl3tcpip.h>
#include <mico/security/transportsecurity_impl.h>
#include <mico/security/sl3aqargs_impl.h>


namespace MICOSL3_SL3TCPIP
{
    // initialization function
    void
    _init();


    class ArgBuilder_impl
	: virtual public MICOSL3_SL3AQArgs::ArgBuilder_impl,
	  virtual public SL3TCPIP::TCPIPArgBuilder,
	  virtual public CORBA::LocalObject
    {
    public:
	ArgBuilder_impl(SL3CM::CredentialsUsage usage);

	virtual void
	add_CSIv1_support(CORBA::Boolean support);

	virtual void
	add_CSIv2_support(CORBA::Boolean support);

	virtual void add_tcpip_initiator_options
	(const char* bind,
	 CORBA::Long low_port,
	 CORBA::Long high_port,
	 CORBA::Long timeout);

	virtual void
	add_tcpip_acceptor_options
	(const CORBA::StringSeq& hosts,
	 const char* bind,
	 CORBA::Long low_port,
	 CORBA::Long high_port,
	 CORBA::Long backlog,
	 CORBA::Boolean numeric);

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
	SL3AQArgs::TCPIPAcceptorOptions acceptor_options_;
	SL3AQArgs::TCPIPInitiatorOptions initiator_options_;
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
    private:
	MICOSL3_TransportSecurity::CredentialsCurator_impl* curator_impl_;
	TransportSecurity::OwnCredentials_var creds_;
	static CORBA::ULong S_creds_index_;
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

    class TCPIPInitiator
	: virtual public MICOSL3_TransportSecurity::TransportInitiator_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	TCPIPInitiator(SL3AQArgs::Argument_ptr arg);

	virtual
	~TCPIPInitiator();
    };

    class TCPIPAcceptor
	: virtual public MICOSL3_TransportSecurity::TransportAcceptor_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	TCPIPAcceptor(SL3AQArgs::Argument_ptr arg);

	virtual
	~TCPIPAcceptor();

	char*
	bind();

	CORBA::Long
	low_port();

	CORBA::Long
	high_port();

	CORBA::Boolean
	numeric();

	void
	port(CORBA::Long p);

	virtual void
	shutdown();

	virtual void
	enable();

        const CORBA::Address*
        bound_addr();

        const CORBA::Address*
        ior_addr();
    private:
	SL3AQArgs::TCPIPAcceptorOptions options_;
	CORBA::Address* bound_addr_;
        CORBA::Address* ior_addr_;
    };

    class TCPIPInitiatingContext
	: virtual public MICOSL3_TransportSecurity::InitiatingContext_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	TCPIPInitiatingContext
	(TransportSecurity::OwnCredentials_ptr parent,
	 const CORBA::Address* target,
	 const CORBA::Address* client);

	virtual
	~TCPIPInitiatingContext();

	const CORBA::Address*
	target_addr();

	const CORBA::Address*
	client_addr();

    private:
	const CORBA::Address* target_addr_;
	const CORBA::Address* client_addr_;
	static CORBA::ULong S_ctx_index_;
    };

    class TCPIPAcceptingContext
	: virtual public MICOSL3_TransportSecurity::AcceptingContext_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	TCPIPAcceptingContext
	(TransportSecurity::OwnCredentials_ptr parent,
	 const CORBA::Address* target,
	 const CORBA::Address* client);

	virtual
	~TCPIPAcceptingContext();

	const CORBA::Address*
	target_addr();

	const CORBA::Address*
	client_addr();

    private:
	const CORBA::Address* target_addr_;
	const CORBA::Address* client_addr_;
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

} // MICOSL3_SL3TCPIP

#endif // __SL3TCPIP_IMPL_H__
