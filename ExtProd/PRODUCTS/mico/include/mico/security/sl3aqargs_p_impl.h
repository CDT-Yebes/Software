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


#ifndef __SL3AQARGS_P_IMPL_H__
#define __SL3AQARGS_P_IMPL_H__

#include <mico/security/sl3aqargs_p.h>
#include <mico/security/sl3aqargs_impl.h>


namespace MICOSL3_SL3AQArgs
{
    class ArgsHolder_impl
	: virtual public SL3AQArgs::ArgsHolder,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	ArgsHolder_impl
	(SL3CM::CredentialsUsage usage,
	 const SL3AQArgs::ArgumentSeq& args);

	virtual SL3CM::CredentialsUsage
	usage();

	virtual SL3AQArgs::ArgumentSeq*
	args();

    private:
	SL3CM::CredentialsUsage usage_;
	SL3AQArgs::ArgumentSeq args_;
    };


    class CSIv1Support_impl
	: virtual public SL3AQArgs::CSIv1Support,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	CSIv1Support_impl(CORBA::Boolean support);

	virtual CORBA::Boolean
	support();
    private:
	CORBA::Boolean support_;
    };


    class CSIv2Support_impl
	: virtual public SL3AQArgs::CSIv2Support,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	CSIv2Support_impl(CORBA::Boolean support);

	virtual CORBA::Boolean
	support();
    private:
	CORBA::Boolean support_;
    };


    class TCPIPInitiatorArgument_impl
	: virtual public SL3AQArgs::TCPIPInitiatorArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	TCPIPInitiatorArgument_impl(const SL3AQArgs::TCPIPInitiatorOptions& options);

	virtual SL3AQArgs::TCPIPInitiatorOptions*
	options();
    private:
	SL3AQArgs::TCPIPInitiatorOptions options_;
    };


    class TCPIPAcceptorArgument_impl
	: virtual public SL3AQArgs::TCPIPAcceptorArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	TCPIPAcceptorArgument_impl(const SL3AQArgs::TCPIPAcceptorOptions& options);

	virtual SL3AQArgs::TCPIPAcceptorOptions*
	options();
    private:
	SL3AQArgs::TCPIPAcceptorOptions options_;
    };


    class TLSX509IdentityVerifierInitiatorArgument_impl
	: virtual public SL3AQArgs::TLSX509IdentityVerifierInitiatorArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	TLSX509IdentityVerifierInitiatorArgument_impl
	(SL3TLS::TLSX509IdentityVerifier_ptr verifier);

	virtual SL3TLS::TLSX509IdentityVerifier_ptr
	verifier();
    private:
	SL3TLS::TLSX509IdentityVerifier_var verifier_;
    };


    class TLSX509IdentityVerifierAcceptorArgument_impl
	: virtual public SL3AQArgs::TLSX509IdentityVerifierAcceptorArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	TLSX509IdentityVerifierAcceptorArgument_impl
	(SL3TLS::TLSX509IdentityVerifier_ptr verifier);

	virtual SL3TLS::TLSX509IdentityVerifier_ptr
	verifier();
    private:
	SL3TLS::TLSX509IdentityVerifier_var verifier_;
    };


    class OpenSSLInitiatorArgument_impl
	: virtual public SL3AQArgs::OpenSSLInitiatorArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	OpenSSLInitiatorArgument_impl(const SL3AQArgs::OpenSSLConfig& config);

	virtual SL3AQArgs::OpenSSLConfig*
	config();
    private:
	SL3AQArgs::OpenSSLConfig config_;
    };


    class OpenSSLAcceptorArgument_impl
	: virtual public SL3AQArgs::OpenSSLAcceptorArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	OpenSSLAcceptorArgument_impl(const SL3AQArgs::OpenSSLConfig& config);

	virtual SL3AQArgs::OpenSSLConfig*
	config();
    private:
	SL3AQArgs::OpenSSLConfig config_;
    };


    class TransportCredentialsArgument_impl
	: virtual public SL3AQArgs::TransportCredentialsArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	TransportCredentialsArgument_impl
	(TransportSecurity::OwnCredentials_ptr creds);

	virtual TransportSecurity::OwnCredentials_ptr
	creds();
    private:
	TransportSecurity::OwnCredentials_var creds_;
    };


    class DeciderArgument_impl
	: virtual public SL3AQArgs::DeciderArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	DeciderArgument_impl(Trust::LocalTrustInServerDecider_ptr decider);

	virtual Trust::LocalTrustInServerDecider_ptr
	decider();
    private:
	Trust::LocalTrustInServerDecider_var decider_;
    };


    class GeneratorArgument_impl
	: virtual public SL3AQArgs::GeneratorArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	GeneratorArgument_impl(UserPassword::PasswordGenerator_ptr generator);

	virtual UserPassword::PasswordGenerator_ptr
	generator();
    private:
	UserPassword::PasswordGenerator_var generator_;
    };


    class ProcessorArgument_impl
	: virtual public SL3AQArgs::ProcessorArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	ProcessorArgument_impl(UserPassword::PasswordProcessor_ptr generator);

	virtual UserPassword::PasswordProcessor_ptr
	processor();
    private:
	UserPassword::PasswordProcessor_var processor_;
    };


    class QuotingPrincipalArgument_impl
	: virtual public SL3AQArgs::QuotingPrincipalArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	QuotingPrincipalArgument_impl(SL3PM::QuotingPrincipal* principal);

	virtual SL3PM::QuotingPrincipal*
	principal();
    private:
	SL3PM::QuotingPrincipal_var principal_;
    };


    class ATLASArgument_impl
	: virtual public SL3AQArgs::ATLASArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	ATLASArgument_impl
	(const ATLAS::ATLASCacheId& cache_id,
	 ATLAS::AuthTokenDispenser_ptr token_dispenser,
	 SL3Authorization::TokenProcessor_ptr token_processor);

	virtual ATLAS::ATLASCacheId*
	cache_id();

	virtual ATLAS::AuthTokenDispenser_ptr
	token_dispenser();

	virtual SL3Authorization::TokenProcessor_ptr
	token_processor();
    private:
	ATLAS::ATLASCacheId cache_id_;
	ATLAS::AuthTokenDispenser_var token_dispenser_;
	CORBA::Boolean supports_delegation_by_client_;
	CORBA::Boolean requires_delegation_by_client_;
	SL3Authorization::TokenProcessor_var token_processor_;
    };


    class TokenProcessorSeqArgument_impl
	: virtual public SL3AQArgs::TokenProcessorSeqArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	TokenProcessorSeqArgument_impl
	(const SL3AQArgs::TokenProcessorSeq& tpseq);

	virtual SL3AQArgs::TokenProcessorSeq*
	tpseq();
    private:
	SL3AQArgs::TokenProcessorSeq tpseq_;
    };


    class IPCInitiatorArgument_impl
	: virtual public SL3AQArgs::IPCInitiatorArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	IPCInitiatorArgument_impl();
    };


    class IPCAcceptorArgument_impl
	: virtual public SL3AQArgs::IPCAcceptorArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	IPCAcceptorArgument_impl();
    };


    class ObserverSeqArgument_impl
	: virtual public SL3AQArgs::ObserverSeqArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	ObserverSeqArgument_impl(const SL3OM::ObserverSeq& observers);

	virtual SL3OM::ObserverSeq*
	observers();
    private:
	SL3OM::ObserverSeq observers_;
    };


    class IdentityProcessorArgument_impl
	: virtual public SL3AQArgs::IdentityProcessorArgument,
	  virtual public Argument_impl,
	  virtual public CORBA::LocalObject
    {
    public:
	IdentityProcessorArgument_impl
	(SL3TLS::TLSX509IdentityProcessor_ptr processor);

	virtual SL3TLS::TLSX509IdentityProcessor_ptr
	processor();
    private:
	SL3TLS::TLSX509IdentityProcessor_var processor_;
    };
} // MICOSL3_SL3AQArgs
    
#endif // __SL3AQARGS_P_IMPL_H__

