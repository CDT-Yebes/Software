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
#include <mico/security/sl3aqargs_p_impl.h>
#endif // FAST_PCH

using namespace SL3AQArgs;
using namespace SL3CM;
using namespace SL3PM;
using namespace CORBA;
using namespace ATLAS;
using namespace SL3Authorization;
using namespace std;

MICOSL3_SL3AQArgs::ArgsHolder_impl::ArgsHolder_impl
(SL3CM::CredentialsUsage usage,
 const SL3AQArgs::ArgumentSeq& args)
    : Argument_impl(ArgsHolderType), usage_(usage), args_(args)
{
}

CredentialsUsage
MICOSL3_SL3AQArgs::ArgsHolder_impl::usage()
{
    return usage_;
}

ArgumentSeq*
MICOSL3_SL3AQArgs::ArgsHolder_impl::args()
{
    return new ArgumentSeq(args_);
}

MICOSL3_SL3AQArgs::CSIv1Support_impl::CSIv1Support_impl
(Boolean support)
    : Argument_impl(SL3AQArgs::CSIv1SupportType), support_(support)
{
}

Boolean
MICOSL3_SL3AQArgs::CSIv1Support_impl::support()
{
    return support_;
}

MICOSL3_SL3AQArgs::CSIv2Support_impl::CSIv2Support_impl
(Boolean support)
    : Argument_impl(SL3AQArgs::CSIv2SupportType), support_(support)
{
}

Boolean
MICOSL3_SL3AQArgs::CSIv2Support_impl::support()
{
    return support_;
}

MICOSL3_SL3AQArgs::TCPIPInitiatorArgument_impl::TCPIPInitiatorArgument_impl
(const TCPIPInitiatorOptions& options)
    : Argument_impl(SL3AQArgs::TCPIPInitiatorArgumentType), options_(options)
{
}

TCPIPInitiatorOptions*
MICOSL3_SL3AQArgs::TCPIPInitiatorArgument_impl::options()
{
    return new TCPIPInitiatorOptions(options_);
}

MICOSL3_SL3AQArgs::TCPIPAcceptorArgument_impl::TCPIPAcceptorArgument_impl
(const TCPIPAcceptorOptions& options)
    : Argument_impl(SL3AQArgs::TCPIPAcceptorArgumentType), options_(options)
{
}

TCPIPAcceptorOptions*
MICOSL3_SL3AQArgs::TCPIPAcceptorArgument_impl::options()
{
    return new TCPIPAcceptorOptions(options_);
}

MICOSL3_SL3AQArgs::TLSX509IdentityVerifierInitiatorArgument_impl::TLSX509IdentityVerifierInitiatorArgument_impl
(SL3TLS::TLSX509IdentityVerifier_ptr verifier)
    : Argument_impl(SL3AQArgs::TLSX509IdentityVerifierInitiatorArgumentType), verifier_(SL3TLS::TLSX509IdentityVerifier::_duplicate(verifier))
{
}

SL3TLS::TLSX509IdentityVerifier_ptr
MICOSL3_SL3AQArgs::TLSX509IdentityVerifierInitiatorArgument_impl::verifier()
{
    return SL3TLS::TLSX509IdentityVerifier::_duplicate(verifier_);
}

MICOSL3_SL3AQArgs::TLSX509IdentityVerifierAcceptorArgument_impl::TLSX509IdentityVerifierAcceptorArgument_impl
(SL3TLS::TLSX509IdentityVerifier_ptr verifier)
    : Argument_impl(SL3AQArgs::TLSX509IdentityVerifierAcceptorArgumentType), verifier_(SL3TLS::TLSX509IdentityVerifier::_duplicate(verifier))
{
}

SL3TLS::TLSX509IdentityVerifier_ptr
MICOSL3_SL3AQArgs::TLSX509IdentityVerifierAcceptorArgument_impl::verifier()
{
    return SL3TLS::TLSX509IdentityVerifier::_duplicate(verifier_);
}

MICOSL3_SL3AQArgs::OpenSSLInitiatorArgument_impl::OpenSSLInitiatorArgument_impl
(const OpenSSLConfig& config)
    : Argument_impl(SL3AQArgs::OpenSSLInitiatorArgumentType), config_(config)
{
}

OpenSSLConfig*
MICOSL3_SL3AQArgs::OpenSSLInitiatorArgument_impl::config()
{
    return new OpenSSLConfig(config_);
}

MICOSL3_SL3AQArgs::OpenSSLAcceptorArgument_impl::OpenSSLAcceptorArgument_impl
(const OpenSSLConfig& config)
    : Argument_impl(SL3AQArgs::OpenSSLAcceptorArgumentType), config_(config)
{
}

OpenSSLConfig*
MICOSL3_SL3AQArgs::OpenSSLAcceptorArgument_impl::config()
{
    return new OpenSSLConfig(config_);
}

MICOSL3_SL3AQArgs::TransportCredentialsArgument_impl::TransportCredentialsArgument_impl
(TransportSecurity::OwnCredentials_ptr creds)
    : Argument_impl(SL3AQArgs::TransportCredentialsArgumentType), creds_(TransportSecurity::OwnCredentials::_duplicate(creds))
{
}

TransportSecurity::OwnCredentials_ptr
MICOSL3_SL3AQArgs::TransportCredentialsArgument_impl::creds()
{
    return TransportSecurity::OwnCredentials::_duplicate(creds_);
}

MICOSL3_SL3AQArgs::DeciderArgument_impl::DeciderArgument_impl
(Trust::LocalTrustInServerDecider_ptr decider)
    : Argument_impl(SL3AQArgs::DeciderArgumentType), decider_(Trust::LocalTrustInServerDecider::_duplicate(decider))
{
}

Trust::LocalTrustInServerDecider_ptr
MICOSL3_SL3AQArgs::DeciderArgument_impl::decider()
{
    return Trust::LocalTrustInServerDecider::_narrow(decider_);
}

MICOSL3_SL3AQArgs::GeneratorArgument_impl::GeneratorArgument_impl
(UserPassword::PasswordGenerator_ptr generator)
    : Argument_impl(SL3AQArgs::GeneratorArgumentType), generator_(UserPassword::PasswordGenerator::_duplicate(generator))
{
}

UserPassword::PasswordGenerator_ptr
MICOSL3_SL3AQArgs::GeneratorArgument_impl::generator()
{
    return UserPassword::PasswordGenerator::_duplicate(generator_);
}

MICOSL3_SL3AQArgs::ProcessorArgument_impl::ProcessorArgument_impl
(UserPassword::PasswordProcessor_ptr processor)
    : Argument_impl(SL3AQArgs::ProcessorArgumentType), processor_(UserPassword::PasswordProcessor::_duplicate(processor))
{
}

UserPassword::PasswordProcessor_ptr
MICOSL3_SL3AQArgs::ProcessorArgument_impl::processor()
{
    return UserPassword::PasswordProcessor::_duplicate(processor_);
}

MICOSL3_SL3AQArgs::QuotingPrincipalArgument_impl::QuotingPrincipalArgument_impl
(SL3PM::QuotingPrincipal* principal)
    : Argument_impl(SL3AQArgs::QuotingPrincipalArgumentType)
{
    CORBA::add_ref(principal);
    principal_ = principal;
}

QuotingPrincipal*
MICOSL3_SL3AQArgs::QuotingPrincipalArgument_impl::principal()
{
    CORBA::add_ref(principal_);
    return principal_.in();
}

MICOSL3_SL3AQArgs::ATLASArgument_impl::ATLASArgument_impl
(const ATLAS::ATLASCacheId& cache_id,
 AuthTokenDispenser_ptr token_dispenser,
 TokenProcessor_ptr token_processor)
    : Argument_impl(ATLASArgumentType), cache_id_(cache_id), token_dispenser_(AuthTokenDispenser::_duplicate(token_dispenser)), token_processor_(TokenProcessor::_duplicate(token_processor))
{
}

ATLASCacheId*
MICOSL3_SL3AQArgs::ATLASArgument_impl::cache_id()
{
    return new ATLASCacheId(cache_id_);
}

AuthTokenDispenser_ptr
MICOSL3_SL3AQArgs::ATLASArgument_impl::token_dispenser()
{
    return AuthTokenDispenser::_duplicate(token_dispenser_);
}

TokenProcessor_ptr
MICOSL3_SL3AQArgs::ATLASArgument_impl::token_processor()
{
    return TokenProcessor::_duplicate(token_processor_);
}

MICOSL3_SL3AQArgs::TokenProcessorSeqArgument_impl::TokenProcessorSeqArgument_impl
(const TokenProcessorSeq& tpseq)
    : Argument_impl(TokenProcessorSeqArgumentType), tpseq_(tpseq)
{
}

TokenProcessorSeq*
MICOSL3_SL3AQArgs::TokenProcessorSeqArgument_impl::tpseq()
{
    return new TokenProcessorSeq(tpseq_);
}

MICOSL3_SL3AQArgs::IPCInitiatorArgument_impl::IPCInitiatorArgument_impl()
    : Argument_impl(IPCInitiatorArgumentType)
{
}

MICOSL3_SL3AQArgs::IPCAcceptorArgument_impl::IPCAcceptorArgument_impl()
    : Argument_impl(IPCAcceptorArgumentType)
{
}

MICOSL3_SL3AQArgs::ObserverSeqArgument_impl::ObserverSeqArgument_impl
(const SL3OM::ObserverSeq& observers)
    : Argument_impl(ObserverSeqArgumentType), observers_(observers)
{
}

SL3OM::ObserverSeq*
MICOSL3_SL3AQArgs::ObserverSeqArgument_impl::observers()
{
    return new SL3OM::ObserverSeq(observers_);
}

MICOSL3_SL3AQArgs::IdentityProcessorArgument_impl::IdentityProcessorArgument_impl
(SL3TLS::TLSX509IdentityProcessor_ptr processor)
    : Argument_impl(SL3AQArgs::IdentityProcessorArgumentType),
      processor_(SL3TLS::TLSX509IdentityProcessor::_duplicate(processor))
{
}

SL3TLS::TLSX509IdentityProcessor_ptr
MICOSL3_SL3AQArgs::IdentityProcessorArgument_impl::processor()
{
    return SL3TLS::TLSX509IdentityProcessor::_duplicate(processor_);
}

