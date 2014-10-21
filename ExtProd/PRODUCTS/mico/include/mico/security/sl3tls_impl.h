// -*- c++ -*-
//
//  MICO SL3 --- an Open Source SL3 implementation
//  Copyright (C) 2003, 2004, 2005, 2006 ObjectSecurity Ltd.
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


#ifndef __SL3TLS_IMPL_H__
#define __SL3TLS_IMPL_H__

#include <mico/security/sl3tls.h>
#include <mico/security/sl3tcpip_impl.h>


namespace MICOSL3_SL3TLS
{
    // initialization function
    void
    _init();


    class ArgBuilder_impl
	: virtual public MICOSL3_SL3TCPIP::ArgBuilder_impl,
	  virtual public SL3TLS::OpenSSLConfigArgBuilder,
	  virtual public CORBA::LocalObject
    {
    public:
	ArgBuilder_impl(SL3CM::CredentialsUsage usage);

	virtual void
	add_tls_acceptor_options
	(const char* ca,
	 const char* cert,
	 const char* key);

	virtual void
	add_tls_acceptor_options_with_passphrase
	(const char* ca,
	 const char* cert,
	 const char* key,
	 const char* passphrase);

	virtual void
	add_tls_initiator_options
	(const char* ca,
	 const char* cert,
	 const char* key);

	virtual void
	add_tls_initiator_options_with_passphrase
	(const char* ca,
	 const char* cert,
	 const char* key,
	 const char* passphrase);

	virtual void
	add_tls_anonymous_initiator_options(const char* ca);

	virtual void
	add_initiator_cipher(const char* cipher);

	virtual void
	add_acceptor_cipher(const char* cipher);

	virtual void
	add_initiator_verify_depth(CORBA::Long depth);

	virtual void
	add_acceptor_verify_depth(CORBA::Long depth);

	virtual void
	add_initiator_identity_verifier
	(SL3TLS::TLSX509IdentityVerifier_ptr verifier);

	virtual void
	add_acceptor_identity_verifier
	(SL3TLS::TLSX509IdentityVerifier_ptr verifier);

	virtual SL3AQArgs::Argument_ptr
	reap_args();
    private:
	SL3AQArgs::OpenSSLConfig acceptor_config_;
	SL3AQArgs::OpenSSLConfig initiator_config_;
	SL3TLS::TLSX509IdentityVerifier_var acceptor_verifier_;
	SL3TLS::TLSX509IdentityVerifier_var initiator_verifier_;
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


    class OpenSSLConfigHolder
    {
    public:
	OpenSSLConfigHolder(SL3AQArgs::Argument_ptr arg);

	char*
	cert_file();

	char*
	key_file();

	char*
	ca_file();

	char*
	ca_path();

	char*
	cipher();

	CORBA::Boolean
	use_passphrase();

	char*
	passphrase();

	CORBA::Long
	verify_depth();
    private:
	SL3AQArgs::OpenSSLConfig config_;
    };


    class TLSInitiator
	: virtual public MICOSL3_TransportSecurity::TransportInitiator_impl,
	  virtual public OpenSSLConfigHolder,
	  virtual public CORBA::LocalObject
    {
    public:
	TLSInitiator
	(SL3AQArgs::Argument_ptr tcpip_arg,
	 SL3AQArgs::Argument_ptr openssl_arg);

	virtual
	~TLSInitiator();
    };


    class TLSAcceptor
	: virtual public MICOSL3_TransportSecurity::TransportAcceptor_impl,
	  virtual public OpenSSLConfigHolder,
	  virtual public CORBA::LocalObject
    {
    public:
	TLSAcceptor
	(SL3AQArgs::Argument_ptr tcpip_arg,
	 SL3AQArgs::Argument_ptr openssl_arg);

	virtual
	~TLSAcceptor();

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


    class TLSInitiatingContext
	: virtual public MICOSL3_TransportSecurity::InitiatingContext_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	TLSInitiatingContext
	(TransportSecurity::OwnCredentials_ptr parent,
	 CORBA::Transport* transport);

	virtual
	~TLSInitiatingContext();

	const CORBA::Address*
	target_addr();

	const CORBA::Address*
	client_addr();

    private:
	const CORBA::Address* target_addr_;
	const CORBA::Address* client_addr_;
	static CORBA::ULong S_ctx_index_;
    };


    class TLSAcceptingContext
	: virtual public MICOSL3_TransportSecurity::AcceptingContext_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	TLSAcceptingContext
	(TransportSecurity::OwnCredentials_ptr parent,
	 CORBA::Transport* transport);

	virtual
	~TLSAcceptingContext();

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
} // MICOSL3_SL3TLS

#endif // __SL3TLS_IMPL_H__
