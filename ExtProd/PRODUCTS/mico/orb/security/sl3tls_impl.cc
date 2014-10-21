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


#ifdef FAST_PCH
#include "csiv2sl3_pch.h"
#endif // FAST_PCH
#ifdef __COMO__
#pragma hdrstop
#endif // __COMO__

#ifndef FAST_PCH
#include <mico/security/sl3tls_impl.h>
#include <mico/security/sl3aqargs_p_impl.h>
//#include <mico/security/securitylevel3_impl.h>
#include <mico/security/sl3pm_impl.h>
#include <mico/impl.h>
#include <mico/security/sl3utils.h>
#include <mico/ssl.h>
#endif // FAST_PCH

using namespace SL3AQArgs;
using namespace MICOSL3_SL3AQArgs;
using namespace TransportSecurity;
using namespace SL3PM;
using namespace SL3CM;
using namespace SL3OM;
using namespace CORBA;
using namespace std;


//
// static members initialization
//
CORBA::ULong
MICOSL3_SL3TLS::CredentialsAcquirer_impl::S_creds_index_ = 0;

CORBA::ULong
MICOSL3_SL3TLS::TLSInitiatingContext::S_ctx_index_ = 0;

CORBA::ULong
MICOSL3_SL3TLS::TLSAcceptingContext::S_ctx_index_ = 0;


//
// module initialization
//

void
MICOSL3_SL3TLS::_init()
{
    PortableInterceptor::register_orb_initializer(new ORBInitializer());
}


//
// ArgBuilder_impl
//

MICOSL3_SL3TLS::ArgBuilder_impl::ArgBuilder_impl(CredentialsUsage usage)
    : MICOSL3_SL3AQArgs::ArgBuilder_impl(usage), MICOSL3_SL3TCPIP::ArgBuilder_impl(usage)
{
    acceptor_config_.use_passphrase = FALSE;
    acceptor_config_.verify_depth = 9;
    initiator_config_.use_passphrase = FALSE;
    initiator_config_.verify_depth = 9;
}


void
MICOSL3_SL3TLS::ArgBuilder_impl::add_tls_acceptor_options
(const char* ca,
 const char* cert,
 const char* key)
{
    if (this->usage() == CU_InitiateOnly)
	mico_throw(BAD_PARAM(50001, CORBA::COMPLETED_NO));
    // kcg: this need to be fix, since we assume ca == ca_file
    // i.e. we need to test if ca is directory or file
    acceptor_config_.ca_file = ca;
    acceptor_config_.cert_file = cert;
    acceptor_config_.key_file = key;
}


void
MICOSL3_SL3TLS::ArgBuilder_impl::add_tls_acceptor_options_with_passphrase
(const char* ca,
 const char* cert,
 const char* key,
 const char* passphrase)
{
    if (this->usage() == CU_InitiateOnly)
	mico_throw(BAD_PARAM(50002, CORBA::COMPLETED_NO));
    this->add_tls_acceptor_options(ca, cert, key);
    acceptor_config_.passphrase = passphrase;
    acceptor_config_.use_passphrase = TRUE;
}


void
MICOSL3_SL3TLS::ArgBuilder_impl::add_tls_initiator_options
(const char* ca,
 const char* cert,
 const char* key)
{
    if (this->usage() == CU_AcceptOnly)
	mico_throw(BAD_PARAM(50003, CORBA::COMPLETED_NO));
    // kcg: this need to be fix, since we assume ca == ca_file
    // i.e. we need to test if ca is directory or file
    initiator_config_.ca_file = ca;
    initiator_config_.cert_file = cert;
    initiator_config_.key_file = key;
}


void
MICOSL3_SL3TLS::ArgBuilder_impl::add_tls_initiator_options_with_passphrase
(const char* ca,
 const char* cert,
 const char* key,
 const char* passphrase)
{
    if (this->usage() == CU_AcceptOnly)
	mico_throw(BAD_PARAM(50004, CORBA::COMPLETED_NO));
    this->add_tls_initiator_options(ca, cert, key);
    initiator_config_.passphrase = passphrase;
    initiator_config_.use_passphrase = TRUE;
}


void
MICOSL3_SL3TLS::ArgBuilder_impl::add_tls_anonymous_initiator_options
(const char* ca)
{
    if (this->usage() == CU_AcceptOnly)
	mico_throw(BAD_PARAM(50005, CORBA::COMPLETED_NO));
    this->add_tls_initiator_options(ca, "", "");
}


void
MICOSL3_SL3TLS::ArgBuilder_impl::add_initiator_cipher(const char* cipher)
{
    initiator_config_.cipher = cipher;
}


void
MICOSL3_SL3TLS::ArgBuilder_impl::add_acceptor_cipher(const char* cipher)
{
    acceptor_config_.cipher = cipher;
}


void
MICOSL3_SL3TLS::ArgBuilder_impl::add_initiator_verify_depth(CORBA::Long depth)
{
    if (this->usage() == CU_AcceptOnly || depth < 0) {
	mico_throw(CORBA::BAD_PARAM(50006, CORBA::COMPLETED_NO));
    }
    initiator_config_.verify_depth = depth;
}


void
MICOSL3_SL3TLS::ArgBuilder_impl::add_acceptor_verify_depth(CORBA::Long depth)
{
    if (this->usage() == CU_InitiateOnly || depth < 0) {
	mico_throw(CORBA::BAD_PARAM(50007, CORBA::COMPLETED_NO));
    }
    acceptor_config_.verify_depth = depth;
}


void
MICOSL3_SL3TLS::ArgBuilder_impl::add_initiator_identity_verifier
(SL3TLS::TLSX509IdentityVerifier_ptr verifier)
{
    if (this->usage() == CU_AcceptOnly || CORBA::is_nil(verifier)) {
	mico_throw(CORBA::BAD_PARAM(50008, CORBA::COMPLETED_NO));
    }
    initiator_verifier_
	= SL3TLS::TLSX509IdentityVerifier::_duplicate(verifier);
}


void
MICOSL3_SL3TLS::ArgBuilder_impl::add_acceptor_identity_verifier
(SL3TLS::TLSX509IdentityVerifier_ptr verifier)
{
    if (this->usage() == CU_InitiateOnly || CORBA::is_nil(verifier)) {
	mico_throw(CORBA::BAD_PARAM(50009, CORBA::COMPLETED_NO));
    }
    acceptor_verifier_
	= SL3TLS::TLSX509IdentityVerifier::_duplicate(verifier);
}


Argument_ptr
MICOSL3_SL3TLS::ArgBuilder_impl::reap_args()
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3TLS: ArgBuilder_impl::reap_args()" << endl;
    }
    // initiator options
    if (this->usage() == CU_InitiateOnly
	|| this->usage() == CU_InitiateAndAccept) {
	Argument_var arg = new OpenSSLInitiatorArgument_impl(initiator_config_);
	this->add_arg(arg);
	if (!CORBA::is_nil(initiator_verifier_)) {
	    arg = new TLSX509IdentityVerifierInitiatorArgument_impl(initiator_verifier_);
	    this->add_arg(arg);
	}
    }
    // acceptor options
    if (this->usage() == CU_AcceptOnly
	|| this->usage() == CU_InitiateAndAccept) {
	Argument_var arg = new OpenSSLAcceptorArgument_impl(acceptor_config_);
	this->add_arg(arg);
	if (!CORBA::is_nil(acceptor_verifier_)) {
	    arg = new TLSX509IdentityVerifierAcceptorArgument_impl(acceptor_verifier_);
	    this->add_arg(arg);
	}
    }
    return MICOSL3_SL3TCPIP::ArgBuilder_impl::reap_args();
}


//
// ArgumentFactory_impl
//

ArgBuilder_ptr
MICOSL3_SL3TLS::ArgumentFactory_impl::create_arg_builder(CredentialsUsage usage)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3TLS: ArgumentFactory_impl::create_arg_builder("
	    << usage << ")" << endl;
    }
    return new ArgBuilder_impl(usage);
}


//
// CredentialsAcquirer_impl
//

MICOSL3_SL3TLS::CredentialsAcquirer_impl::CredentialsAcquirer_impl
(SL3AQArgs::Argument_ptr value)
    : curator_impl_(NULL)
{
    ArgsHolder_var args = ArgsHolder::_narrow(value);
    assert(!CORBA::is_nil(args));
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3TLS: CredentialsAcquirer_impl" << endl
	    << "        value->type(): " <<  value->type() << endl
	    << "        usage: " << args->usage() << endl;
    }
    ArgumentSeq_var argslist = args->args();

    CredentialsAcceptor_var acceptor = CredentialsAcceptor::_nil();
    CredentialsInitiator_var initiator = CredentialsInitiator::_nil();
    TCPIPInitiatorArgument_var tcpip_initiator_arg
	= TCPIPInitiatorArgument::_nil();
    TCPIPAcceptorArgument_var tcpip_acceptor_arg
	= TCPIPAcceptorArgument::_nil();
    CSIv1Support_var csiv1_arg = CSIv1Support::_nil();
    CSIv2Support_var csiv2_arg = CSIv2Support::_nil();
    OpenSSLInitiatorArgument_var ssl_initiator_arg
	= OpenSSLInitiatorArgument::_nil();
    OpenSSLAcceptorArgument_var ssl_acceptor_arg
	= OpenSSLAcceptorArgument::_nil();
    TLSX509IdentityVerifierInitiatorArgument_var verifier_initiator_arg
	= TLSX509IdentityVerifierInitiatorArgument::_nil();
    TLSX509IdentityVerifierAcceptorArgument_var verifier_acceptor_arg
	= TLSX509IdentityVerifierAcceptorArgument::_nil();
    ObserverSeq observers;
    observers.length(0);
    for (ULong i = 0; i < argslist->length(); i++) {
	String_var type = argslist[i]->type();
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3TLS: type[" << i << "]: " << type.in() << endl;
	}
	if (strcmp(type.in(), TCPIPInitiatorArgumentType) == 0) {
	    tcpip_initiator_arg = TCPIPInitiatorArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(tcpip_initiator_arg));
	}
	else if (strcmp(type.in(), TCPIPAcceptorArgumentType) == 0) {
	    tcpip_acceptor_arg = TCPIPAcceptorArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(tcpip_acceptor_arg));
	}
	else if (strcmp(type.in(), CSIv1SupportType) == 0) {
	    csiv1_arg = CSIv1Support::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(csiv1_arg));
	}
	else if (strcmp(type.in(), CSIv2SupportType) == 0) {
	    csiv2_arg = CSIv2Support::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(csiv2_arg));
	}
	else if (strcmp(type.in(), OpenSSLInitiatorArgumentType) == 0) {
	    ssl_initiator_arg = OpenSSLInitiatorArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(ssl_initiator_arg));
	}
	else if (strcmp(type.in(), OpenSSLAcceptorArgumentType) == 0) {
	    ssl_acceptor_arg = OpenSSLAcceptorArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(ssl_acceptor_arg));
	}
	else if (strcmp(type.in(), TLSX509IdentityVerifierInitiatorArgumentType)
		 == 0) {
	    verifier_initiator_arg
		= TLSX509IdentityVerifierInitiatorArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(verifier_initiator_arg));
	}
	else if (strcmp(type.in(), TLSX509IdentityVerifierAcceptorArgumentType)
		 == 0) {
	    verifier_acceptor_arg
		= TLSX509IdentityVerifierAcceptorArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(verifier_acceptor_arg));
	}
	else if (strcmp(type.in(), ObserverSeqArgumentType) == 0) {
	    ObserverSeqArgument_var observers_arg
		= ObserverSeqArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(observers_arg));
	    ObserverSeq_var obs = observers_arg->observers();
	    observers = obs;
	}
	else {
	    cerr << "ERROR: unsupported argument type!" << endl;
	    assert(0);
	}
    }
    if (args->usage() == CU_AcceptOnly
	&& (!CORBA::is_nil(tcpip_initiator_arg)
	    || !CORBA::is_nil(ssl_initiator_arg))) {
	// argument mismatch?
	assert(0);
    }
    if (args->usage() == CU_InitiateOnly
	&& (!CORBA::is_nil(tcpip_acceptor_arg)
	    || !CORBA::is_nil(ssl_acceptor_arg))) {
	// argument mismatch?
	assert(0);
    }
    if (!CORBA::is_nil(tcpip_initiator_arg)
	&& !CORBA::is_nil(ssl_initiator_arg)) {
  	initiator = new TLSInitiator(tcpip_initiator_arg, ssl_initiator_arg);
    }
    if (!CORBA::is_nil(tcpip_acceptor_arg)
	&& !CORBA::is_nil(ssl_acceptor_arg)) {
  	acceptor = new TLSAcceptor(tcpip_acceptor_arg, ssl_acceptor_arg);
    }
    assert(!CORBA::is_nil(csiv1_arg));
    assert(!CORBA::is_nil(csiv2_arg));
    TimeBase::UtcT tt;
    tt.time = 0xffffffffffffffffULL;
    tt.inacclo = 0;
    tt.inacchi = 0;
    tt.tdf = 0;
    string id = "MICO_TLS:";
    id += xdec(S_creds_index_);
    S_creds_index_++;
    MICOSL3_TransportSecurity::OwnCredentials_impl* cr
	= new MICOSL3_TransportSecurity::OwnCredentials_impl
	(id.c_str(), CS_Valid, CT_OwnCredentials, args->usage(), tt,
	 initiator, acceptor, csiv1_arg->support(), csiv2_arg->support(),
	 observers);
    creds_ = cr;
}


MICOSL3_SL3TLS::CredentialsAcquirer_impl::~CredentialsAcquirer_impl()
{
}


OwnCredentials_ptr
MICOSL3_SL3TLS::CredentialsAcquirer_impl::get_credentials
(CORBA::Boolean on_list)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3TLS: CredentialsAcquirer_impl::get_credentials" << endl
	    << "        creds_: " << creds_.in() << endl;
    }
    curator_impl_->add_own_credentials(creds_, on_list);
    CredentialsAcceptor_var acceptor = creds_->the_acceptor();
    TransportAcceptor_var acc = TransportAcceptor::_narrow(acceptor);
    if (!CORBA::is_nil(acc)) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3TLS: start listening on acceptor" << endl;
	}
	acc->enable();
    }
    MICOSL3_TransportSecurity::OwnCredentials_impl* creds_impl
	= dynamic_cast<MICOSL3_TransportSecurity::OwnCredentials_impl*>
	(creds_.in());
    assert(creds_impl != NULL);
    creds_impl->notify_creation();
    return TransportSecurity::OwnCredentials::_duplicate(creds_);
}


void
MICOSL3_SL3TLS::CredentialsAcquirer_impl::destroy()
{
    assert(0);
}

// extension
void
MICOSL3_SL3TLS::CredentialsAcquirer_impl::creds_curator_impl
(MICOSL3_TransportSecurity::CredentialsCurator_impl* curator)
{
    curator_impl_ = curator;
}


//
// CredentialsAcquirerFactory_impl
//
MICOSL3_SL3TLS::CredentialsAcquirerFactory_impl::CredentialsAcquirerFactory_impl()
{
    supported_types_[ArgsHolderType] = true;
    supported_types_[CSIv1SupportType] = true;
    supported_types_[CSIv2SupportType] = true;
    supported_types_[TCPIPInitiatorArgumentType] = true;
    supported_types_[TCPIPAcceptorArgumentType] = true;
    supported_types_[OpenSSLInitiatorArgumentType] = true;
    supported_types_[OpenSSLAcceptorArgumentType] = true;
    supported_types_[TLSX509IdentityVerifierInitiatorArgumentType] = true;
    supported_types_[TLSX509IdentityVerifierAcceptorArgumentType] = true;
    supported_types_[ObserverSeqArgumentType] = true;
}


CredentialsAcquirer_ptr
MICOSL3_SL3TLS::CredentialsAcquirerFactory_impl::create(Argument_ptr value)
{
    return new CredentialsAcquirer_impl(value);
}


Boolean
MICOSL3_SL3TLS::CredentialsAcquirerFactory_impl::supports_all_args
(Argument_ptr value)
{
    String_var type = value->type();
    if (supported_types_.count(type.in()) < 1)
	return FALSE;
    ArgsHolder_var holder = ArgsHolder::_narrow(value);
    if (CORBA::is_nil(holder))
	return FALSE;
    ArgumentSeq_var args = holder->args();
    for (ULong i = 0; i < args->length(); i++) {
	type = args[i]->type();
	if (supported_types_.count(type.in()) < 1)
	    return FALSE;
    }
    return TRUE;
}

//
// OpenSSLConfigHolder
//
MICOSL3_SL3TLS::OpenSSLConfigHolder::OpenSSLConfigHolder(Argument_ptr arg)
{
    assert(!CORBA::is_nil(arg));
    String_var type = arg->type();
    if (strcmp(type.in(), OpenSSLInitiatorArgumentType) == 0) {
	OpenSSLInitiatorArgument_var init_arg
	    = OpenSSLInitiatorArgument::_narrow(arg);
	assert(!CORBA::is_nil(init_arg));
	OpenSSLConfig_var config = init_arg->config();
	config_ = config;
    }
    else if (strcmp(type.in(), OpenSSLAcceptorArgumentType) == 0) {
	OpenSSLAcceptorArgument_var accept_arg
	    = OpenSSLAcceptorArgument::_narrow(arg);
	assert(!CORBA::is_nil(accept_arg));
	OpenSSLConfig_var config = accept_arg->config();
	config_ = config;
    }
    else {
	assert(0);
    }
}


char*
MICOSL3_SL3TLS::OpenSSLConfigHolder::cert_file()
{
    return CORBA::string_dup(config_.cert_file);
}


char*
MICOSL3_SL3TLS::OpenSSLConfigHolder::key_file()
{
    return CORBA::string_dup(config_.key_file);
}


char*
MICOSL3_SL3TLS::OpenSSLConfigHolder::ca_file()
{
    return CORBA::string_dup(config_.ca_file);
}


char*
MICOSL3_SL3TLS::OpenSSLConfigHolder::ca_path()
{
    return CORBA::string_dup(config_.ca_path);
}


char*
MICOSL3_SL3TLS::OpenSSLConfigHolder::cipher()
{
    return CORBA::string_dup(config_.cipher);
}


Boolean
MICOSL3_SL3TLS::OpenSSLConfigHolder::use_passphrase()
{
    return config_.use_passphrase;
}


char*
MICOSL3_SL3TLS::OpenSSLConfigHolder::passphrase()
{
    return CORBA::string_dup(config_.passphrase);
}


Long
MICOSL3_SL3TLS::OpenSSLConfigHolder::verify_depth()
{
    return config_.verify_depth;
}


//
// TLSInitiator
//

MICOSL3_SL3TLS::TLSInitiator::TLSInitiator
(Argument_ptr tcpip_arg,
 Argument_ptr openssl_arg)
    : OpenSSLConfigHolder(openssl_arg)
{
    TCPIPInitiatorArgument_var init_arg = TCPIPInitiatorArgument::_narrow
	(tcpip_arg);
    assert(!CORBA::is_nil(init_arg));
    TCPIPInitiatorOptions_var options = init_arg->options();
    //    assert(arg.arg >>= options);
    host_ = options->bind;
    low_port_ = options->low_port;
    high_port_ = options->high_port;
    supports_endorsement_ = FALSE;
    supports_quoting_ = FALSE;
    supports_client_authentication_ = FALSE;
    supports_target_authentication_ = TRUE;
    supports_confidentiality_ = TRUE;
    supports_integrity_ = TRUE;
    expiry_time_.time = 0xffffffffffffffffULL;
    expiry_time_.inacclo = 0;
    expiry_time_.inacchi = 0;
    expiry_time_.tdf = 0;
    SimplePrincipal* principal
	= new MICOSL3_SL3PM::SimplePrincipal_impl;
    principal->the_type(PT_Simple);
    PrincipalName name;
    String_var cert_file = this->cert_file();
    if (strcmp(cert_file.in(), "") != 0) {
	name.the_type = (const char*)NT_X509DirectoryNamePath;
	name.the_name.length(2);
	MICOSL3Utils::X509Cert cert(cert_file.in());
	string subject = cert.subject();
	wstring wsubject = str2wstr(subject);
	name.the_name[0] = wsubject.c_str();
	string issuer = cert.issuer();
	wstring wissuer = str2wstr(issuer);
	name.the_name[1] = wissuer.c_str();
	principal->authenticated(TRUE);
	supports_client_authentication_ = TRUE;
    }
    else {
	// kcg: is this annonymous connection?
	name.the_type = (const char*)NT_Anonymous;
	name.the_name.length(1);
	name.the_name[0] = L"anonymous";
    }
    principal->the_name(name);
    principal_ = principal;
    PrinAttributeList env_attr;
    env_attr.length(1);
    PrinAttribute a1;
    a1.the_type = "SL3:TransportMechanism";
    a1.the_value = L"TLS";
    env_attr[0] = a1;
    environmental_attributes_ = env_attr;
    statement_list_.length(1);
    CORBA::OctetSeq encoding;
    encoding.length(0);
    MICOSL3_SL3PM::PrincipalIdentityStatement_impl* pistat
  	= new MICOSL3_SL3PM::PrincipalIdentityStatement_impl
  	((const char*)ET_Unknown, encoding);
    pistat->interpretation_aid("X509:V1IdentityCertificate");
    pistat->the_layer(SL_Transport);
    pistat->the_type(ST_IdentityStatement);
    CORBA::add_ref(principal_);
    pistat->the_principal(principal_);
    statement_list_[0] = pistat;
}


MICOSL3_SL3TLS::TLSInitiator::~TLSInitiator()
{
    //cerr << "~TLSInitiator" << endl;
}


//
// TLSAcceptor
//

MICOSL3_SL3TLS::TLSAcceptor::TLSAcceptor
(Argument_ptr tcpip_arg,
 Argument_ptr openssl_arg)
    : OpenSSLConfigHolder(openssl_arg), bound_addr_(NULL), ior_addr_(NULL)
{
    TCPIPAcceptorArgument_var accept_arg = TCPIPAcceptorArgument::_narrow
	(tcpip_arg);
    TCPIPAcceptorOptions_var options = accept_arg->options();
    options_ = options;
    hosts_ = options->hosts;
    options_required_ = 0;
    options_supported_ = 0;
    supports_endorsement_ = FALSE;
    supports_quoting_ = FALSE;
    supports_client_authentication_ = TRUE;
    supports_target_authentication_ = TRUE;
    supports_confidentiality_ = TRUE;
    supports_integrity_ = TRUE;
    expiry_time_.time = 0xffffffffffffffffULL;
    expiry_time_.inacclo = 0;
    expiry_time_.inacchi = 0;
    expiry_time_.tdf = 0;
    SimplePrincipal* principal
	= new MICOSL3_SL3PM::SimplePrincipal_impl;
    principal->the_type(PT_Simple);
    PrincipalName name;
    String_var cert_file = this->cert_file();
    if (strcmp(cert_file.in(), "") != 0) {
	name.the_type = (const char*)NT_X509DirectoryNamePath;
	name.the_name.length(2);
	MICOSL3Utils::X509Cert cert(cert_file.in());
	string subject = cert.subject();
	wstring wsubject = str2wstr(subject);
	name.the_name[0] = wsubject.c_str();
	string issuer = cert.issuer();
	wstring wissuer = str2wstr(issuer);
	name.the_name[1] = wissuer.c_str();
	principal->authenticated(TRUE);
    }
    else {
	// kcg: is this annonymous connection?
	name.the_type = (const char*)NT_Anonymous;
	name.the_name.length(1);
	name.the_name[0] = L"anonymous";
    }
    principal->the_name(name);
    principal_ = principal;
    statement_list_.length(1);
    CORBA::OctetSeq encoding;
    encoding.length(0);
    MICOSL3_SL3PM::PrincipalIdentityStatement_impl* pistat
  	= new MICOSL3_SL3PM::PrincipalIdentityStatement_impl
  	((const char*)ET_Unknown, encoding);
    pistat->interpretation_aid("X509:V1IdentityCertificate");
    pistat->the_layer(SL_Transport);
    pistat->the_type(ST_IdentityStatement);
    CORBA::add_ref(principal_);
    pistat->the_principal(principal_);
    statement_list_[0] = pistat;
    rsname_list_.length(0);
}


MICOSL3_SL3TLS::TLSAcceptor::~TLSAcceptor()
{
    //cerr << "~TLSAcceptor" << endl;
    if (bound_addr_ != NULL) {
        delete bound_addr_;
    }
    if (ior_addr_ != NULL) {
        delete ior_addr_;
    }
}


char*
MICOSL3_SL3TLS::TLSAcceptor::bind()
{
    return CORBA::string_dup(options_.bind);
}


Long
MICOSL3_SL3TLS::TLSAcceptor::low_port()
{
    return options_.low_port;
}


Long
MICOSL3_SL3TLS::TLSAcceptor::high_port()
{
    return options_.high_port;
}


Boolean
MICOSL3_SL3TLS::TLSAcceptor::numeric()
{
    return options_.numeric;
}


void
MICOSL3_SL3TLS::TLSAcceptor::port(Long p)
{
    port_ = p;
}


void
MICOSL3_SL3TLS::TLSAcceptor::shutdown()
{
    MICO::IIOPServer* iiop_srv = MICO::IIOPServer::iiopserver_instance();
    assert(bound_addr_ != NULL && iiop_srv != NULL);
    iiop_srv->shutdown(bound_addr_);
}


void
MICOSL3_SL3TLS::TLSAcceptor::enable()
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3TLS: TLSAcceptor::enable" << endl;
    }
    MICO::IIOPServer* server = MICO::IIOPServer::iiopserver_instance();
    if (server == NULL) {
        CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
        server = new MICO::IIOPServer
            (orb, 0x0102 /* giop 1.2 */, 0 /* disable msg size checking */);
    }
    string addr = "ssl:inet:";
    addr += this->bind();
    addr += ":";
    MICOSSL::SSLAddress* i_addr = NULL;
    MICOSSL::SSLAddress* i_ior_addr = NULL;
    StringSeq_var hosts = this->hosts();
    assert(hosts->length() <= 1);
    if (this->low_port() != 0) {
	if (this->low_port() < this->high_port()) {
	    // we will try to bind to specified port range
	    for (Long i = this->low_port(); i <= this->high_port(); i++) {
		string naddr = addr + xdec(i);
		if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
		    MICOMT::AutoDebugLock lock;
		    MICO::Logger::Stream(MICO::Logger::Security)
			<< "SL3TLS: naddr: " << naddr << endl;
		}
		Address* addr = Address::parse(naddr.c_str());
		assert(addr);
                Address* ior_addr = NULL;
                if (hosts->length() == 1) {
                    string ior_addr_str = "ssl:inet:";
                    ior_addr_str +=  hosts[(CORBA::ULong)0].in();
                    ior_addr_str += ":" + xdec(i);
                    ior_addr = Address::parse(ior_addr_str.c_str());
                }
		if (server->listen(addr, ior_addr)) {
		    i_addr = dynamic_cast<MICOSSL::SSLAddress*>(addr);
		    assert(i_addr != NULL);
                    if (ior_addr != NULL) {
                        i_ior_addr = dynamic_cast<MICOSSL::SSLAddress*>(ior_addr);
                        assert(i_ior_addr != NULL);
                    }
		    break;
		}
		if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
		    MICOMT::AutoDebugLock lock;
		    MICO::Logger::Stream(MICO::Logger::Security)
			<< "SL3TLS: binding to "
			<< naddr << " failed" << endl;
		}
		delete addr;
	    }
	}
	else {
	    // high_port < low_port => we will try to bind to low_port
	    string naddr = addr + xdec(this->low_port());
	    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
		MICOMT::AutoDebugLock lock;
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "SL3TLS: naddr2: " << naddr << endl;
	    }
	    Address* addr = Address::parse(naddr.c_str());
	    assert(addr);
            Address* ior_addr = NULL;
            if (hosts->length() == 1) {
                string ior_addr_str = "ssl:inet:";
                ior_addr_str +=  hosts[(CORBA::ULong)0].in();
                ior_addr_str += ":" + xdec(this->low_port());
                ior_addr = Address::parse(ior_addr_str.c_str());
            }
	    if (server->listen(addr, ior_addr)) {
		i_addr = dynamic_cast<MICOSSL::SSLAddress*>(addr);
		assert(i_addr != NULL);
                if (ior_addr != NULL) {
                    i_ior_addr = dynamic_cast<MICOSSL::SSLAddress*>(ior_addr);
                    assert(i_ior_addr != NULL);
                }
	    }
	    else {
		if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
		    MICOMT::AutoDebugLock lock;
		    MICO::Logger::Stream(MICO::Logger::Security)
			<< "SL3TLS: binding(2) to "
			<< naddr << " failed" << endl;
		}
		delete addr;
	    }
	}
    }
    else {
	// we will try binding to system default.
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3TLS: we will try binding to system default." << endl;
	}
	string naddr = addr + "0";
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3TLS: naddr3: " << naddr << endl;
	}
	Address* addr = Address::parse(naddr.c_str());
        const Address* baddr;
	assert(addr);
        if (hosts->length() > 0) {
            // unsupported case
            assert(0);
        }
	if (server->listen(addr, 0, baddr)) {
            Address* clone_addr = baddr->clone();
	    i_addr = dynamic_cast<MICOSSL::SSLAddress*>(clone_addr);
	    assert(i_addr != NULL);
	}
	else {
	    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
		MICOMT::AutoDebugLock lock;
		MICO::Logger::Stream(MICO::Logger::Security)
		    << "SL3TLS: binding(3) to "
		    << naddr << " failed" << endl;
	    }
	    delete addr;
	}
    }
    wstring t_addr = L"";
    wstring t_port = L"";
    if (i_addr != NULL) {
	t_addr = MICOSL3Utils::Address::ip_to_wstring(i_addr);
	t_port = MICOSL3Utils::Address::port_to_wstring(i_addr);
	bound_addr_ = i_addr;
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3TLS: bound address: `" << bound_addr_->stringify() << "'" << endl;
	}        
    }
    else {
	vector<CORBA::Octet> id = MICO::InetAddress::hostid();
	assert(id.size() == 4);
	t_addr = wxdec(id[0]) + L"." + wxdec(id[1]) + L"."
	    + wxdec(id[2]) + L"." + wxdec(id[3]);
	t_port = L"<unspecified value>";
    }
    if (i_ior_addr != NULL) {
        ior_addr_ = i_ior_addr;
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3TCPIP: IOR address: `" << ior_addr_->stringify() << "'" << endl;
	}
    }
    CORBA::WString_var ip = t_addr.c_str();
    CORBA::WString_var port = t_port.c_str();
    PrinAttributeList env_attr;
    env_attr.length(3);
    PrinAttribute attr;
    attr.the_type = "SL3:TransportMechanism";
    attr.the_value = L"TLS";
    env_attr[0] = attr;
    attr.the_type = "SL3:LocalAddress";
    attr.the_value = ip.in();
    env_attr[1] = attr;
    attr.the_type = "SL3:LocalPort";
    attr.the_value = port.in();
    env_attr[2] = attr;
    environmental_attributes_ = env_attr;
}


const CORBA::Address*
MICOSL3_SL3TLS::TLSAcceptor::bound_addr()
{
    return this->bound_addr_;
}


const CORBA::Address*
MICOSL3_SL3TLS::TLSAcceptor::ior_addr()
{
    return this->ior_addr_;
}


//
// TLSInitiatingContext
//

MICOSL3_SL3TLS::TLSInitiatingContext::TLSInitiatingContext
(TransportSecurity::OwnCredentials_ptr parent,
 CORBA::Transport* transport)
    : TargetCredentials_impl(parent), InitiatingContext_impl(parent)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3TLS: TLSInitiatingContext" << endl;
    }
    target_addr_ = transport->peer();
    client_addr_ = transport->addr();
    string id = "MICO_TLSInitiatingContext:";
    id += xdec(S_ctx_index_);
    S_ctx_index_++;
    context_id_ = id.c_str();
    string ss = parent->creds_id();
    ss += context_id_.in();
    creds_id_ = ss.c_str();
    creds_type_ = CT_TargetCredentials;
    creds_usage_ = CU_None;
    expiry_time_.time = 0xffffffffffffffffULL;
    expiry_time_.inacclo = 0;
    expiry_time_.inacchi = 0;
    expiry_time_.tdf = 0;
    TransportSecurity::CredentialsInitiator_var initiator
	= parent_credentials_->the_initiator();
    assert(!CORBA::is_nil(initiator));
    OpenSSLConfigHolder* ssl_config = dynamic_cast<OpenSSLConfigHolder*>
	(initiator.in());
    assert(ssl_config != NULL);
    // names
    CORBA::Boolean c_princ_authenticated = FALSE;
    PrincipalName c_name;
    String_var cert_file = ssl_config->cert_file();
    if (strcmp(cert_file.in(), "") != 0) {
	c_princ_authenticated = TRUE;
	c_name.the_type = (const char*)NT_X509DirectoryNamePath;
	c_name.the_name.length(2);
	MICOSL3Utils::X509Cert cert(cert_file.in());
	string subject = cert.subject();
	wstring wsubject = str2wstr(subject);
	c_name.the_name[0] = wsubject.c_str();
	string issuer = cert.issuer();
	wstring wissuer = str2wstr(issuer);
	c_name.the_name[1] = wissuer.c_str();
    }
    else {
	// kcg: is this annonymous connection?
	c_name.the_type = (const char*)NT_Anonymous;
	c_name.the_name.length(1);
	c_name.the_name[0] = L"anonymous";
    }
    PrincipalName t_name;
    t_name.the_type = (const char*)NT_X509DirectoryNamePath;
    t_name.the_name.length(2);
    MICOSSL::SSLTransport* ssl_transp = dynamic_cast<MICOSSL::SSLTransport*>
	(transport);
    assert(ssl_transp != NULL);
    MICOSL3Utils::X509Cert t_cert(SSL_get_peer_certificate(ssl_transp->get_ssl()));
    string subject = t_cert.subject();
    wstring wsubject = str2wstr(subject);
    t_name.the_name[0] = wsubject.c_str();
    string issuer = t_cert.issuer();
    wstring wissuer = str2wstr(issuer);
    t_name.the_name[1] = wissuer.c_str();
    // env attributes
    PrinAttributeList env_attr;
    env_attr.length(4);
    PrinAttribute a1;
    a1.the_type = "SL3:TransportMechanism";
    a1.the_value = L"TLS";
    env_attr[0] = a1;
    string cipher = SSL_get_cipher(ssl_transp->get_ssl());
    wstring wcipher = str2wstr(cipher);
    a1.the_type = "SL3:TLSCipherSuite";
    a1.the_value = wcipher.c_str();
    env_attr[1] = a1;
    a1.the_type = "SL3:ChannelIdentifier";
    wstring channel_id = L"TCPIPv4:"
	+ MICOSL3Utils::Address::addr_to_wstring(client_addr_)
	+ L"-" + MICOSL3Utils::Address::addr_to_wstring(target_addr_);
    a1.the_value = channel_id.c_str();
    env_attr[2] = a1;
    a1.the_type = "SL3:EstablishmentTime";
    wstring time = wxdec(OSMisc::gettime().tv_sec);
    //    wstring time = wxdec(::time(0));
    a1.the_value = time.c_str();
    env_attr[3] = a1;
    environmental_attributes_ = env_attr;
    // pricipals
    SimplePrincipal* c_principal
	= new MICOSL3_SL3PM::SimplePrincipal_impl;
    c_principal->the_type(PT_Simple);
    c_principal->the_name(c_name);
    c_principal->authenticated(c_princ_authenticated);
    client_principal_ = c_principal;
    SimplePrincipal* t_principal
	= new MICOSL3_SL3PM::SimplePrincipal_impl;
    t_principal->the_type(PT_Simple);
    t_principal->the_name(t_name);
    t_principal->authenticated(TRUE);
    target_principal_ = t_principal;
    // supporting statements
    client_supporting_statements_.length(1);
    CORBA::OctetSeq encoding;
    encoding.length(0);
    MICOSL3_SL3PM::PrincipalIdentityStatement_impl* c_pis
	= new MICOSL3_SL3PM::PrincipalIdentityStatement_impl
	((const char*)ET_Unknown, encoding);
    c_pis->interpretation_aid("X509:V1IdentityCertificate");
    c_pis->the_layer(SL_Transport);
    c_pis->the_type(ST_IdentityStatement);
    CORBA::add_ref(client_principal_);
    c_pis->the_principal(client_principal_);
    client_supporting_statements_[0] = c_pis;
    target_supporting_statements_.length(1);
    MICOSL3_SL3PM::PrincipalIdentityStatement_impl* t_pis
	= new MICOSL3_SL3PM::PrincipalIdentityStatement_impl
	((const char*)ET_Unknown, encoding);
    t_pis->interpretation_aid("X509:V1IdentityCertificate");
    t_pis->the_layer(SL_Transport);
    t_pis->the_type(ST_IdentityStatement);
    CORBA::add_ref(target_principal_);
    t_pis->the_principal(target_principal_);
    target_supporting_statements_[0] = t_pis;
    // restricted resources
    client_restricted_resources_.length(0);
    target_restricted_resources_.length(0);
    // other (boolean) values
    client_authentication_ = c_princ_authenticated;
    target_authentication_ = TRUE;
    confidentiality_ = TRUE;
    integrity_ = TRUE;
    target_embodied_ = FALSE;
    target_endorsed_ = FALSE;
}


MICOSL3_SL3TLS::TLSInitiatingContext::~TLSInitiatingContext()
{
    //cerr << "~TLSInitiatingContext" << endl;
}

const CORBA::Address*
MICOSL3_SL3TLS::TLSInitiatingContext::target_addr()
{
    return target_addr_;
}


const CORBA::Address*
MICOSL3_SL3TLS::TLSInitiatingContext::client_addr()
{
    return client_addr_;
}


//
// TLSAcceptingContext
//

MICOSL3_SL3TLS::TLSAcceptingContext::TLSAcceptingContext
(TransportSecurity::OwnCredentials_ptr parent,
 CORBA::Transport* transport)
    : ClientCredentials_impl(parent), AcceptingContext_impl(parent)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3TLS: TLSAcceptingContext" << endl;
    }
    target_addr_ = transport->addr();
    client_addr_ = transport->peer();
    context_id_ = "MICO:TLSAcceptingContext";
    string id = "MICO_TLSAcceptingContext:";
    id += xdec(S_ctx_index_);
    S_ctx_index_++;
    context_id_ = id.c_str();
    string ss = parent->creds_id();
    ss += context_id_.in();
    creds_id_ = ss.c_str();
    creds_type_ = CT_ClientCredentials;
    creds_usage_ = CU_None;
    expiry_time_.time = 0xffffffffffffffffULL;
    expiry_time_.inacclo = 0;
    expiry_time_.inacchi = 0;
    expiry_time_.tdf = 0;
    TransportSecurity::CredentialsAcceptor_var acceptor
	= parent_credentials_->the_acceptor();
    assert(!CORBA::is_nil(acceptor));
    OpenSSLConfigHolder* ssl_config = dynamic_cast<OpenSSLConfigHolder*>
	(acceptor.in());
    assert(ssl_config != NULL);
    // name
    CORBA::Boolean t_princ_authenticated = FALSE;
    PrincipalName t_name;
    String_var cert_file = ssl_config->cert_file();
    if (strcmp(cert_file.in(), "") != 0) {
	t_princ_authenticated = TRUE;
	t_name.the_type = (const char*)NT_X509DirectoryNamePath;
	t_name.the_name.length(2);
	MICOSL3Utils::X509Cert cert(cert_file.in());
	string subject = cert.subject();
	wstring wsubject = str2wstr(subject);
	t_name.the_name[0] = wsubject.c_str();
	string issuer = cert.issuer();
	wstring wissuer = str2wstr(issuer);
	t_name.the_name[1] = wissuer.c_str();
    }
    else {
	// kcg: is this annonymous connection?
	t_name.the_type = (const char*)NT_Anonymous;
	t_name.the_name.length(1);
	t_name.the_name[0] = L"anonymous";
    }
    MICOSSL::SSLTransport* ssl_transp = dynamic_cast<MICOSSL::SSLTransport*>
	(transport);
    assert(ssl_transp != NULL);
    CORBA::Boolean c_princ_authenticated = FALSE;
    PrincipalName c_name;
    try {
	c_name.the_type = (const char*)NT_X509DirectoryNamePath;
	c_name.the_name.length(2);
	// will throw BAD_PARAM in case of NULL certificate
	MICOSL3Utils::X509Cert c_cert(SSL_get_peer_certificate(ssl_transp->get_ssl()));
	string subject = c_cert.subject();
	wstring wsubject = str2wstr(subject);
	c_name.the_name[0] = wsubject.c_str();
	string issuer = c_cert.issuer();
	wstring wissuer = str2wstr(issuer);
	c_name.the_name[1] = wissuer.c_str();
	c_princ_authenticated = TRUE;
    } catch (CORBA::BAD_PARAM&) {
	c_name.the_type = (const char*)NT_Anonymous;
	c_name.the_name.length(1);
	c_name.the_name[0] = L"anonymous";
	c_princ_authenticated = FALSE;
    }
    // env attributes
    PrinAttributeList env_attr;
    env_attr.length(4);
    PrinAttribute a1;
    a1.the_type = "SL3:TransportMechanism";
    a1.the_value = L"TLS";
    env_attr[0] = a1;
    string cipher = SSL_get_cipher(ssl_transp->get_ssl());
    wstring wcipher = str2wstr(cipher);
    a1.the_type = "SL3:TLSCipherSuite";
    a1.the_value = wcipher.c_str();
    env_attr[1] = a1;
    a1.the_type = "SL3:ChannelIdentifier";
    wstring channel_id = L"TCPIPv4:"
	+ MICOSL3Utils::Address::addr_to_wstring(client_addr_)
	+ L"-" + MICOSL3Utils::Address::addr_to_wstring(target_addr_);
    a1.the_value = channel_id.c_str();
    env_attr[2] = a1;
    a1.the_type = "SL3:EstablishmentTime";
    wstring time = wxdec(OSMisc::gettime().tv_sec);
    //    wstring time = wxdec(::time(0));
    a1.the_value = time.c_str();
    env_attr[3] = a1;
    environmental_attributes_ = env_attr;
    // pricipals
    SimplePrincipal* c_principal
	= new MICOSL3_SL3PM::SimplePrincipal_impl;
    c_principal->the_type(PT_Simple);
    c_principal->the_name(c_name);
    c_principal->authenticated(c_princ_authenticated);
    client_principal_ = c_principal;
    SimplePrincipal* t_principal
	= new MICOSL3_SL3PM::SimplePrincipal_impl;
    t_principal->the_type(PT_Simple);
    t_principal->the_name(t_name);
    t_principal->authenticated(t_princ_authenticated);
    target_principal_ = t_principal;
    // supporting statements
    client_supporting_statements_.length(1);
    CORBA::OctetSeq encoding;
    encoding.length(0);
    MICOSL3_SL3PM::PrincipalIdentityStatement_impl* c_pis = NULL;
    if (c_princ_authenticated) {
	c_pis = new MICOSL3_SL3PM::PrincipalIdentityStatement_impl
	    ((const char*)ET_Unknown, encoding);
	c_pis->interpretation_aid("X509:V1IdentityCertificate");
    }
    else {
	c_pis = new MICOSL3_SL3PM::PrincipalIdentityStatement_impl;
    }
    c_pis->the_layer(SL_Transport);
    c_pis->the_type(ST_IdentityStatement);
    CORBA::add_ref(client_principal_);
    c_pis->the_principal(client_principal_);
    client_supporting_statements_[0] = c_pis;
    target_supporting_statements_.length(1);
    MICOSL3_SL3PM::PrincipalIdentityStatement_impl* t_pis = NULL;
    if (t_princ_authenticated) {
	t_pis = new MICOSL3_SL3PM::PrincipalIdentityStatement_impl
	    ((const char*)ET_Unknown, encoding);
	t_pis->interpretation_aid("X509:V1IdentityCertificate");
    }
    else {
	t_pis = new MICOSL3_SL3PM::PrincipalIdentityStatement_impl;
    }
    t_pis->the_layer(SL_Transport);
    t_pis->the_type(ST_IdentityStatement);
    CORBA::add_ref(target_principal_);
    t_pis->the_principal(target_principal_);
    target_supporting_statements_[0] = t_pis;
    // restricted resources
    client_restricted_resources_.length(0);
    target_restricted_resources_.length(0);
    // other (boolean) values
    client_authentication_ = c_princ_authenticated;
    target_authentication_ = t_princ_authenticated;
    confidentiality_ = TRUE;
    integrity_ = TRUE;
    impersonable_ = FALSE;
    endorseable_ = FALSE;
    quotable_ = FALSE;
}


MICOSL3_SL3TLS::TLSAcceptingContext::~TLSAcceptingContext()
{
    //cerr << "~TLSAcceptingContext" << endl;
}


const CORBA::Address*
MICOSL3_SL3TLS::TLSAcceptingContext::target_addr()
{
    return target_addr_;
}


const CORBA::Address*
MICOSL3_SL3TLS::TLSAcceptingContext::client_addr()
{
    return client_addr_;
}


//
// various supporting classes
//

MICOSL3_SL3TLS::ORBInitializer::ORBInitializer()
{
}


MICOSL3_SL3TLS::ORBInitializer::~ORBInitializer()
{
}


void
MICOSL3_SL3TLS::ORBInitializer::pre_init
(PortableInterceptor::ORBInitInfo_ptr info)
{
    ArgumentFactory_impl* factory = new ArgumentFactory_impl;
    info->register_initial_reference("SL3TLS::ArgBuilderFactory", factory);
}


void
MICOSL3_SL3TLS::ORBInitializer::post_init
(PortableInterceptor::ORBInitInfo_ptr info)
{
    CORBA::Object_var obj = info->resolve_initial_references
	("TransportSecurity::SecurityManager");
    SecurityManager_var secman = SecurityManager::_narrow(obj);
    assert(!CORBA::is_nil(secman));
    CredentialsCurator_ptr curator = secman->credentials_curator();
    MICOSL3_TransportSecurity::CredentialsCurator_impl* curator_impl
	= dynamic_cast<MICOSL3_TransportSecurity::CredentialsCurator_impl*>
	(curator);
    assert(curator_impl != NULL);
    CredentialsAcquirerFactory_var fact = new CredentialsAcquirerFactory_impl;
    curator_impl->register_acquirer_factory(fact);
}


