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

#ifdef FAST_PCH
#include "csiv2sl3_pch.h"
#endif // FAST_PCH
#ifdef __COMO__
#pragma hdrstop
#endif // __COMO__

#ifndef FAST_PCH
#include <mico/security/sl3csi_impl.h>
#include <mico/security/sl3pm_impl.h>
#include <mico/security/sl3aqargs_p_impl.h>
#include <mico/security/csiv2_impl.h>
#include <mico/impl.h>
#include <mico/security/sl3utils.h>
#endif // FAST_PCH


using namespace SL3AQArgs;
using namespace SecurityLevel3;
using namespace UserPassword;
using namespace Trust;
using namespace SL3CSI;
using namespace SL3CM;
using namespace SL3PM;
using namespace SL3OM;
using namespace ATLAS;
using namespace MICOSL3_SL3AQArgs;
using namespace SL3Authorization;
using namespace SL3TLS;
// this will lead to ambigous Principal symbol
// since it is declared in both CORBA and SL3PM namespaces
//using namespace CORBA;
using CORBA::Boolean;
using CORBA::String_var;
using CORBA::BAD_PARAM;
using CORBA::ULong;
using namespace std;

//
// module initialization
//
void
MICOSL3_SL3CSI::_init()
{
    PortableInterceptor::register_orb_initializer(new ORBInitializer());
}


//
// ArgBuilder_impl
//

MICOSL3_SL3CSI::ArgBuilder_impl::ArgBuilder_impl
(CredentialsUsage usage)
    : MICOSL3_SL3AQArgs::ArgBuilder_impl(usage)
{
    tpseq_.length(0);
}


MICOSL3_SL3CSI::ArgBuilder_impl::~ArgBuilder_impl()
{
}


void
MICOSL3_SL3CSI::ArgBuilder_impl::add_password_generator
(UserPassword::PasswordGenerator_ptr generator)
{
    if ((this->usage() != CU_InitiateOnly
	 && this->usage() != CU_InitiateAndAccept)
	|| CORBA::is_nil(generator)) {
	mico_throw(CORBA::BAD_PARAM(60001, CORBA::COMPLETED_NO));
    }
    generator_ = UserPassword::PasswordGenerator::_duplicate(generator);
}


void
MICOSL3_SL3CSI::ArgBuilder_impl::add_password_processor
(UserPassword::PasswordProcessor_ptr processor)
{
    if ((this->usage() != CU_AcceptOnly
	 && this->usage() != CU_InitiateAndAccept)
	|| CORBA::is_nil(processor)) {
	mico_throw(CORBA::BAD_PARAM(60002, CORBA::COMPLETED_NO));
    }
    processor_ = UserPassword::PasswordProcessor::_duplicate(processor);
}


void
MICOSL3_SL3CSI::ArgBuilder_impl::add_named_quoted_principal
(const PrincipalName& principal_name)
{
    SimplePrincipal_var sp = new MICOSL3_SL3PM::SimplePrincipal_impl;
    sp->the_name(principal_name);
    quoting_principal_ = new MICOSL3_SL3PM::QuotingPrincipal_impl(NULL, sp);
}


void
MICOSL3_SL3CSI::ArgBuilder_impl::add_encoded_quoted_principal
(IdentityStatement* identity)
{
    assert(0);
}


void
MICOSL3_SL3CSI::ArgBuilder_impl::add_trust_in_server_decider
(Trust::LocalTrustInServerDecider_ptr trust_decider)
{
    if ((this->usage() != CU_InitiateOnly
	 && this->usage() != CU_InitiateAndAccept)
	|| CORBA::is_nil(trust_decider)) {
	mico_throw(CORBA::BAD_PARAM(60003, CORBA::COMPLETED_NO));
    }
    decider_ = Trust::LocalTrustInServerDecider::_duplicate(trust_decider);
}


void
MICOSL3_SL3CSI::ArgBuilder_impl::add_transport_credentials
(TransportSecurity::OwnCredentials_ptr credentials)
{
    if (CORBA::is_nil(credentials)) {
	mico_throw(CORBA::BAD_PARAM(60004, CORBA::COMPLETED_NO));
    }
    TransportSecurity::CredentialsAcceptor_var acceptor
	= credentials->the_acceptor();
    TransportSecurity::CredentialsInitiator_var initiator
	= credentials->the_initiator();
    if ((this->usage() == CU_InitiateOnly
	 || this->usage() == CU_InitiateAndAccept)
	&& CORBA::is_nil(initiator)) {
	mico_throw(CORBA::BAD_PARAM(60005, CORBA::COMPLETED_NO));
    }
    if ((this->usage() == CU_AcceptOnly
	 || this->usage() == CU_InitiateAndAccept)
	&& CORBA::is_nil(acceptor)) {
	mico_throw(CORBA::BAD_PARAM(60006, CORBA::COMPLETED_NO));
    }
    if (this->usage() == CU_InitiateOnly
	&& !CORBA::is_nil(acceptor)) {
	mico_throw(CORBA::BAD_PARAM(60007, CORBA::COMPLETED_NO));
    }
    if (this->usage() == CU_AcceptOnly
	&& !CORBA::is_nil(initiator)) {
	mico_throw(CORBA::BAD_PARAM(60008, CORBA::COMPLETED_NO));
    }
    transport_creds_ = TransportSecurity::OwnCredentials::_duplicate(credentials);
}


void
MICOSL3_SL3CSI::ArgBuilder_impl::add_credentials_observer
(CredentialsObserver_ptr observer)
{
    if (CORBA::is_nil(observer)) {
	mico_throw(CORBA::BAD_PARAM(60009, CORBA::COMPLETED_NO));
    }
    observers_.length(observers_.length() + 1);
    observers_[observers_.length() - 1] = SL3OM::Observer::_duplicate(observer);
}


void
MICOSL3_SL3CSI::ArgBuilder_impl::add_client_credentials_observer
(ClientCredentialsObserver_ptr observer)
{
    if (CORBA::is_nil(observer) || this->usage() == CU_InitiateOnly) {
	mico_throw(CORBA::BAD_PARAM(60010, CORBA::COMPLETED_NO));
    }
    observers_.length(observers_.length() + 1);
    observers_[observers_.length() - 1] = SL3OM::Observer::_duplicate(observer);
}


void
MICOSL3_SL3CSI::ArgBuilder_impl::add_target_credentials_observer
(TargetCredentialsObserver_ptr observer)
{
    if (CORBA::is_nil(observer) || this->usage() == CU_AcceptOnly) {
	mico_throw(CORBA::BAD_PARAM(60011, CORBA::COMPLETED_NO));
    }
    observers_.length(observers_.length() + 1);
    observers_[observers_.length() - 1] = SL3OM::Observer::_duplicate(observer);
}


void
MICOSL3_SL3CSI::ArgBuilder_impl::add_ATLAS_object
(const ATLASCacheId& cache_id,
 AuthTokenDispenser_ptr token_dispenser,
 SL3Authorization::TokenProcessor_ptr token_processor)
{
    if (this->usage() == CU_InitiateOnly
	|| CORBA::is_nil(token_dispenser)
	|| CORBA::is_nil(token_processor)) {
	mico_throw(CORBA::BAD_PARAM(60012, CORBA::COMPLETED_NO));
    }
    cache_id_ = cache_id;
    token_dispenser_ = AuthTokenDispenser::_duplicate(token_dispenser);
    token_processor_ = TokenProcessor::_duplicate(token_processor);
}


void
MICOSL3_SL3CSI::ArgBuilder_impl::add_token_processor
(TokenProcessor_ptr token_processor)
{
    if (this->usage() == CU_AcceptOnly
	|| CORBA::is_nil(token_processor)) {
	mico_throw(CORBA::BAD_PARAM(60013, CORBA::COMPLETED_NO));
    }
    tpseq_.length(tpseq_.length() + 1);
    tpseq_[tpseq_.length() - 1] = TokenProcessor::_duplicate
	(token_processor);
}


void
MICOSL3_SL3CSI::ArgBuilder_impl::add_identity_processor
(SL3TLS::TLSX509IdentityProcessor_ptr processor)
{
    if (this->usage() != CU_AcceptOnly
	&& this->usage() != CU_InitiateAndAccept) {
	mico_throw(CORBA::BAD_PARAM(60014, CORBA::COMPLETED_NO));
    }
    identity_processor_ = SL3TLS::TLSX509IdentityProcessor::_duplicate(processor);
}


SL3AQArgs::Argument_ptr
MICOSL3_SL3CSI::ArgBuilder_impl::reap_args()
{
    this->check();
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3CSI: ArgBuilder_impl::reap_args()" << endl;
    }
    if (!CORBA::is_nil(generator_)) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3CSI: add generator" << endl;
	}
  	Argument_var arg = new GeneratorArgument_impl(generator_);
  	this->add_arg(arg);
    }
    if (!CORBA::is_nil(processor_)) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3CSI: add processor" << endl;
	}
  	Argument_var arg = new ProcessorArgument_impl(processor_);
  	this->add_arg(arg);
    }
    if (!CORBA::is_nil(decider_)) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3CSI: add decider" << endl;
	}
	Argument_var arg = new DeciderArgument_impl(decider_);
	this->add_arg(arg);
    }
    if (!CORBA::is_nil(transport_creds_)) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3CSI: add transport credentials" << endl;
	}
	Argument_var arg = new TransportCredentialsArgument_impl
	    (transport_creds_);
	this->add_arg(arg);
    }
    if (quoting_principal_.in() != NULL) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3CSI: add quoting principal" << endl;
	}
	Argument_var arg = new QuotingPrincipalArgument_impl
	    (quoting_principal_);
	this->add_arg(arg);
    }
    if (!CORBA::is_nil(token_dispenser_)
	&& !CORBA::is_nil(token_processor_)) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3CSI: add ATLAS object reference" << endl;
	}
	Argument_var arg = new ATLASArgument_impl
	    (cache_id_, token_dispenser_, token_processor_);
	this->add_arg(arg);
    }
    if (tpseq_.length() > 0) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3CSI: add token processor reference" << endl;
	}
	Argument_var arg = new TokenProcessorSeqArgument_impl
	    (tpseq_);
	this->add_arg(arg);
    }
    // observers
    if (observers_.length() > 0) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3CSI: add observer references" << endl;
	}
	Argument_var observers_arg = new ObserverSeqArgument_impl(observers_);
	this->add_arg(observers_arg);
    }
    if (!CORBA::is_nil(identity_processor_)) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3CSI: add identity processor" << endl;
	}
  	Argument_var arg = new IdentityProcessorArgument_impl(identity_processor_);
  	this->add_arg(arg);
    }
    return MICOSL3_SL3AQArgs::ArgBuilder_impl::reap_args();
}


//
// ArgBuilderFactory_impl
//

ArgBuilder_ptr
MICOSL3_SL3CSI::ArgumentFactory_impl::create_arg_builder
(CredentialsUsage usage)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3CSI: ArgumentFactory_impl::create_arg_builder("
	    << usage << ")" << endl;
    }
    return new ArgBuilder_impl(usage);
}


//
// CSICredsInitiator
//

MICOSL3_SL3CSI::CSICredsInitiator::CSICredsInitiator
(TransportSecurity::OwnCredentials_ptr creds,
 PasswordGenerator_ptr generator,
 LocalTrustInServerDecider_ptr decider,
 QuotingPrincipal* quoting_principal,
 const TokenProcessorSeq& tpseq)
{
    assert(!CORBA::is_nil(creds));
    assert(!CORBA::is_nil(generator) || quoting_principal != NULL);
    transport_creds_ = TransportSecurity::OwnCredentials::_duplicate(creds);
    TransportSecurity::CredentialsInitiator_var initiator = transport_creds_->the_initiator();
    assert(!CORBA::is_nil(initiator));
    SimplePrincipal_var tprinc = NULL;
    Principal_var transp_princ = initiator->the_principal();
    principal_ = NULL;
    if (!CORBA::is_nil(generator)) {
	PrincipalName_var name = generator->client_authentication_principal();
	tprinc = new MICOSL3_SL3PM::SimplePrincipal_impl;
	tprinc->the_name(name);
	tprinc->authenticated(true);
	ProxyPrincipal_var proxy = new MICOSL3_SL3PM::ProxyPrincipal_impl
	    (transp_princ, tprinc);
	CORBA::add_ref(proxy);
	principal_ = proxy;
	initiator_type_ = IT_Proxy;
    }
    SL3PM::Principal* iprinc = NULL;
    if (quoting_principal != NULL) {
	iprinc = quoting_principal->quotes_for();
	QuotingPrincipal* qprincipal = NULL;
	if (principal_ != NULL) {
	    qprincipal = new MICOSL3_SL3PM::QuotingPrincipal_impl
		(principal_, iprinc);
	}
	else {
	    qprincipal = new MICOSL3_SL3PM::QuotingPrincipal_impl
		(transp_princ, iprinc);
	}
	principal_ = qprincipal;
	initiator_type_ = IT_Quoting;
    }
    StatementList_var stlist = initiator->supporting_statements();
    supporting_statements_ = stlist;
    if (tprinc != NULL) {
	PrincipalIdentityStatement* pistat
	    = new MICOSL3_SL3PM::PrincipalIdentityStatement_impl;
	pistat->the_layer(SL_CSIClientAuth);
	pistat->the_type(ST_IdentityStatement);
	pistat->the_principal(tprinc);
	supporting_statements_.length(supporting_statements_.length() + 1);
	supporting_statements_[supporting_statements_.length() - 1] = pistat;
    }
    if (iprinc != NULL) {
	PrincipalIdentityStatement* pistat
	    = new MICOSL3_SL3PM::PrincipalIdentityStatement_impl;
	pistat->the_layer(SL_CSIIdentity);
	pistat->the_type(ST_IdentityStatement);
	pistat->the_principal(iprinc);
	supporting_statements_.length(supporting_statements_.length() + 1);
	supporting_statements_[supporting_statements_.length() - 1] = pistat;	
    }
    ResourceNameList_var rslist = initiator->restricted_resources();
    restricted_resources_ = rslist;
    PrinAttributeList_var env_attrs = initiator->environmental_attributes();
    environmental_attributes_ = env_attrs;
    supports_embodiment_ = false;
    supports_endorsement_ = false;
    supports_quoting_ = true;
    expiry_time_ = initiator->expiry_time();
    generator_ = UserPassword::PasswordGenerator::_duplicate(generator);
    trust_decider_ = Trust::LocalTrustInServerDecider::_duplicate(decider);
    tpseq_ = tpseq;
}


MICOSL3_SL3CSI::CSICredsInitiator::~CSICredsInitiator()
{
}


PasswordGenerator_ptr
MICOSL3_SL3CSI::CSICredsInitiator::password_generator()
{
    return UserPassword::PasswordGenerator::_duplicate(generator_);
}


LocalTrustInServerDecider_ptr
MICOSL3_SL3CSI::CSICredsInitiator::trust_decider()
{
    return Trust::LocalTrustInServerDecider::_duplicate(trust_decider_);
}


TransportSecurity::OwnCredentials_ptr
MICOSL3_SL3CSI::CSICredsInitiator::transport_credentials()
{
    return TransportSecurity::OwnCredentials::_duplicate(transport_creds_);
}


TokenProcessorSeq*
MICOSL3_SL3CSI::CSICredsInitiator::tpseq()
{
    return new TokenProcessorSeq(tpseq_);
}


//
// CSICredsAcceptor
//

MICOSL3_SL3CSI::CSICredsAcceptor::CSICredsAcceptor
(TransportSecurity::OwnCredentials_ptr creds,
 PasswordProcessor_ptr processor,
 QuotingPrincipal* quoting_principal,
 const ATLASCacheId& cache_id,
 AuthTokenDispenser_ptr token_dispenser,
 TokenProcessor_ptr token_processor,
 TLSX509IdentityProcessor_ptr identity_processor)
{
    TransportSecurity::CredentialsAcceptor_var acceptor = creds->the_acceptor();
    assert(!CORBA::is_nil(acceptor));
    principal_ = acceptor->the_principal();
    StatementList_var stlist = acceptor->supporting_statements();
    supporting_statements_ = stlist;
    ResourceNameList_var rslist = acceptor->restricted_resources();
    restricted_resources_ = rslist;
    PrinAttributeList_var env_attrs = acceptor->environmental_attributes();
    environmental_attributes_ = env_attrs;
    accepts_endorsement_ = false;
    accepts_quoting_ = true;
    expiry_time_ = acceptor->expiry_time();
    processor_ = UserPassword::PasswordProcessor::_duplicate(processor);
    cache_id_ = cache_id;
    token_dispenser_ = AuthTokenDispenser::_duplicate(token_dispenser);
    // seting delegation on CSS_impl (singleton)
    if (!CORBA::is_nil(token_processor)) {
	CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
	assert(!CORBA::is_nil(orb));
	CORBA::Object_var obj = orb->resolve_initial_references
	    ("CSIv2SecurityManager");
	CSIv2::SecurityManager_var secman = CSIv2::SecurityManager::_narrow(obj);
	assert(!CORBA::is_nil(secman));
	CSIv2::CSS_impl* cssimpl = dynamic_cast<CSIv2::CSS_impl*>
	    (secman->css()); // ok, since css() does not duplicate css reference
	assert(cssimpl != NULL);
	cssimpl->supports_at_delegation
	    (token_processor->supports_endorsement_by_client());
    }
    token_processor_ = TokenProcessor::_duplicate(token_processor);
    identity_processor_ = TLSX509IdentityProcessor::_duplicate
	(identity_processor);
}

PasswordProcessor_ptr
MICOSL3_SL3CSI::CSICredsAcceptor::password_processor()
{
    return UserPassword::PasswordProcessor::_duplicate(processor_);
}

ATLASCacheId*
MICOSL3_SL3CSI::CSICredsAcceptor::cache_id()
{
    return new ATLASCacheId(cache_id_);
}

AuthTokenDispenser_ptr
MICOSL3_SL3CSI::CSICredsAcceptor::token_dispenser()
{
    return AuthTokenDispenser::_duplicate(token_dispenser_);
}

TokenProcessor_ptr
MICOSL3_SL3CSI::CSICredsAcceptor::token_processor()
{
    return TokenProcessor::_duplicate(token_processor_);
}

TLSX509IdentityProcessor_ptr
MICOSL3_SL3CSI::CSICredsAcceptor::identity_processor()
{
    return TLSX509IdentityProcessor::_duplicate(identity_processor_);
}

//
// CredentialsAcquirer_impl
//

MICOSL3_SL3CSI::CredentialsAcquirer_impl::CredentialsAcquirer_impl
(MICOSL3_SecurityLevel3::CredentialsCurator_impl* curator,
 Argument_ptr value)
    : curator_(curator)
{
    String_var type = value->type();
    if (strcmp(type.in(), ArgsHolderType) != 0)
	mico_throw(BAD_PARAM(60015, CORBA::COMPLETED_NO));
    ArgsHolder_var args = ArgsHolder::_narrow(value);
    if (CORBA::is_nil(args))
	mico_throw(BAD_PARAM(60016, CORBA::COMPLETED_NO));
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3CSI: CredentialsAcquirer_impl" << endl
	    << "        value->type(): " << type.in() << endl
	    << "        usage: " << args->usage() << endl;
    }
    PasswordGenerator_var generator = PasswordGenerator::_nil();
    PasswordProcessor_var processor = PasswordProcessor::_nil();
    LocalTrustInServerDecider_var decider = LocalTrustInServerDecider::_nil();
    TransportSecurity::OwnCredentials_var transp_creds
	= TransportSecurity::OwnCredentials::_nil();
    QuotingPrincipal_var quoting_principal = NULL;
    GeneratorArgument_var gen_arg = GeneratorArgument::_nil();
    ProcessorArgument_var proc_arg = ProcessorArgument::_nil();
    DeciderArgument_var decider_arg = DeciderArgument::_nil();
    TransportCredentialsArgument_var tc_arg
	= TransportCredentialsArgument::_nil();
    QuotingPrincipalArgument_var qp_arg = QuotingPrincipalArgument::_nil();
    CredsAcceptor_var acceptor = CredsAcceptor::_nil();
    CredsInitiator_var initiator = CredsInitiator::_nil();
    // ATLAS
    ATLASCacheId cache_id;
    cache_id.length(0);
    AuthTokenDispenser_var dispenser = AuthTokenDispenser::_nil();
    TokenProcessor_var token_processor = TokenProcessor::_nil();
    ATLASArgument_var atlas_arg = ATLASArgument::_nil();
    // token processor seq
    TokenProcessorSeq_var tpseq = new TokenProcessorSeq;
    tpseq->length(0);
    // observers
    ObserverSeq observers;
    observers.length(0);
    ArgumentSeq_var argslist = args->args();
    // identity processor
    TLSX509IdentityProcessor_var identity_processor
	= TLSX509IdentityProcessor::_nil();
    //cerr << "argslist->length(): " << argslist->length() << endl;
    for (ULong i = 0; i < argslist->length(); i++) {
	type = argslist[i]->type();
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3CSI: type[" << i << "]: " << type.in() << endl;
	}
  	if (strcmp(type.in(), GeneratorArgumentType) == 0) {
	    gen_arg = GeneratorArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(gen_arg));
	    generator = gen_arg->generator();
	}
	else if (strcmp(type.in(), ProcessorArgumentType) == 0) {
	    proc_arg = ProcessorArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(proc_arg));
	    processor = proc_arg->processor();
	}
	else if (strcmp(type.in(), DeciderArgumentType) == 0) {
	    decider_arg = DeciderArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(decider_arg));
	    decider = decider_arg->decider();
	}
	else if (strcmp(type.in(), TransportCredentialsArgumentType) == 0) {
	    //cerr << "add transport creds" << endl;
	    tc_arg = TransportCredentialsArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(tc_arg));
	    transp_creds = tc_arg->creds();
	}
	else if (strcmp(type.in(), QuotingPrincipalArgumentType) == 0) {
	    //cerr << "add quotingprincipalargumenttype" << endl;
	    qp_arg = QuotingPrincipalArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(qp_arg));
	    quoting_principal = qp_arg->principal();
	}
	else if (strcmp(type.in(), ATLASArgumentType) == 0) {
	    //cerr << "add atlas argument" << endl;
	    atlas_arg = ATLASArgument::_narrow(argslist[i]);
	    ATLASCacheId_var tid = atlas_arg->cache_id();
	    cache_id = tid;
	    dispenser = atlas_arg->token_dispenser();
	    token_processor = atlas_arg->token_processor();
	}
	else if (strcmp(type.in(), TokenProcessorSeqArgumentType) == 0) {
	    TokenProcessorSeqArgument_var tpseq_arg
		= TokenProcessorSeqArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(tpseq_arg));
	    tpseq = tpseq_arg->tpseq();
	}
	else if (strcmp(type.in(), ObserverSeqArgumentType) == 0) {
	    ObserverSeqArgument_var observers_arg
		= ObserverSeqArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(observers_arg));
	    ObserverSeq_var obs = observers_arg->observers();
	    observers = obs;
	}
	else if (strcmp(type.in(), IdentityProcessorArgumentType) == 0) {
	    IdentityProcessorArgument_var arg
		= IdentityProcessorArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(arg));
	    identity_processor = arg->processor();
	}
	else {
	    // unsupported value
	    mico_throw(BAD_PARAM(60017, CORBA::COMPLETED_NO));
	}
    }
    if (args->usage() == CU_AcceptOnly
	&& !CORBA::is_nil(generator)) {
	// argument mismatch?
	assert(0);
    }
    if (args->usage() == CU_InitiateOnly
	&& !CORBA::is_nil(processor)) {
	// argument mismatch?
	assert(0);
    }
    if (CORBA::is_nil(transp_creds)) {
	// we need transport credentials
	assert(0);
    }
    if (args->usage() == CU_InitiateOnly
	&& !CORBA::is_nil(identity_processor)) {
	// argument mismatch?
	assert(0);
    }
    if (args->usage() == CU_InitiateOnly
	|| args->usage() == CU_InitiateAndAccept) {
	initiator = new CSICredsInitiator
	    (transp_creds, generator, decider, quoting_principal, tpseq);
    }
    if (args->usage() == CU_AcceptOnly
	||args->usage() == CU_InitiateAndAccept) {
	acceptor = new CSICredsAcceptor
	    (transp_creds, processor, quoting_principal, cache_id, dispenser,
	     token_processor, identity_processor);
    }
    creds_ = new MICOSL3_SecurityLevel3::OwnCredentials_impl
	(args->usage(), initiator, acceptor, observers);
}


MICOSL3_SL3CSI::CredentialsAcquirer_impl::~CredentialsAcquirer_impl()
{
}


OwnCredentials_ptr
MICOSL3_SL3CSI::CredentialsAcquirer_impl::get_credentials(Boolean on_list)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3CSI: CredentialsAcquirer_impl::get_credentials" << endl;
    }
    curator_->add_own_credentials(creds_, on_list);
    return OwnCredentials::_duplicate(creds_);
}


void
MICOSL3_SL3CSI::CredentialsAcquirer_impl::destroy()
{
    assert(0);
}


//
// various supporting classes
//

MICOSL3_SL3CSI::ORBInitializer::ORBInitializer()
{
}


MICOSL3_SL3CSI::ORBInitializer::~ORBInitializer()
{
}


void
MICOSL3_SL3CSI::ORBInitializer::pre_init
(PortableInterceptor::ORBInitInfo_ptr info)
{
    ArgumentFactory_impl* factory = new ArgumentFactory_impl;
    info->register_initial_reference("SL3CSI::ArgBuilderFactory", factory);
}


void
MICOSL3_SL3CSI::ORBInitializer::post_init
(PortableInterceptor::ORBInitInfo_ptr info)
{
}

