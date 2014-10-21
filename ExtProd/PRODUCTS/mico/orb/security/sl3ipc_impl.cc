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


#ifdef FAST_PCH
#include "csiv2sl3_pch.h"
#endif // FAST_PCH
#ifdef __COMO__
#pragma hdrstop
#endif // __COMO__

#ifndef FAST_PCH
#include <mico/security/sl3ipc_impl.h>
#include <mico/security/transportsecurity_impl.h>
#include <mico/security/sl3aqargs_p_impl.h>
//#include <mico/security/securitylevel3_impl.h>
#include <mico/security/sl3pm_impl.h>
#include <mico/impl.h>
#include <mico/security/sl3utils.h>
#endif // FAST_PCH

using namespace std;
using namespace SL3IPC;
using namespace TransportSecurity;
using namespace SL3AQArgs;
using namespace SL3PM;
using namespace SL3CM;
using namespace SL3OM;
using namespace CORBA;
using namespace MICOSL3_TransportSecurity;
using namespace MICOSL3_SL3AQArgs;
using namespace MICOSL3_SecurityLevel3;


//
// static members initialization
//
CORBA::ULong
MICOSL3_SL3IPC::CredentialsAcquirer_impl::S_creds_index_ = 0;

CORBA::ULong
MICOSL3_SL3IPC::IPCInitiatingContext::S_ctx_index_ = 0;

CORBA::ULong
MICOSL3_SL3IPC::IPCAcceptingContext::S_ctx_index_ = 0;

MICOSL3_SL3IPC::IPCCredsMapper*
MICOSL3_SL3IPC::IPCCredsMapper::mapper_ = NULL;

//
// module initialization
//
void
MICOSL3_SL3IPC::_init()
{
    PortableInterceptor::register_orb_initializer(new ORBInitializer());
}


//
// ArgBuilder_impl
//

MICOSL3_SL3IPC::ArgBuilder_impl::ArgBuilder_impl(CredentialsUsage usage)
    : MICOSL3_SL3AQArgs::ArgBuilder_impl(usage), csiv1_support_(TRUE), csiv2_support_(FALSE)
{
}


void
MICOSL3_SL3IPC::ArgBuilder_impl::add_CSIv1_support(CORBA::Boolean support)
{
    this->check();
    csiv1_support_ = support;
}


void
MICOSL3_SL3IPC::ArgBuilder_impl::add_CSIv2_support(CORBA::Boolean support)
{
    this->check();
    csiv2_support_ = support;
}


void
MICOSL3_SL3IPC::ArgBuilder_impl::add_accepting_context_observer
(AcceptingContextObserver_ptr observer)
{
    if (CORBA::is_nil(observer) || this->usage() == CU_InitiateOnly) {
	mico_throw(CORBA::BAD_PARAM());
    }
    observers_.length(observers_.length() + 1);
    observers_[observers_.length() - 1] = SL3OM::Observer::_duplicate(observer);
}


void
MICOSL3_SL3IPC::ArgBuilder_impl::add_initiating_context_observer
(InitiatingContextObserver_ptr observer)
{
    if (CORBA::is_nil(observer) || this->usage() == CU_AcceptOnly) {
	mico_throw(CORBA::BAD_PARAM());
    }
    observers_.length(observers_.length() + 1);
    observers_[observers_.length() - 1] = SL3OM::Observer::_duplicate(observer);
}


void
MICOSL3_SL3IPC::ArgBuilder_impl::add_credentials_observer
(CredentialsObserver_ptr observer)
{
    if (CORBA::is_nil(observer)) {
	mico_throw(CORBA::BAD_PARAM());
    }
    observers_.length(observers_.length() + 1);
    observers_[observers_.length() - 1] = SL3OM::Observer::_duplicate(observer);
}


SL3AQArgs::Argument_ptr
MICOSL3_SL3IPC::ArgBuilder_impl::reap_args()
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3IPC: ArgBuilder_impl::reap_args()" << endl;
    }
    // initiator options
    if (this->usage() == CU_InitiateOnly
	|| this->usage() == CU_InitiateAndAccept) {
	Argument_var arg = new IPCInitiatorArgument_impl;
	this->add_arg(arg);
    }
    // acceptor options
    if (this->usage() == CU_AcceptOnly
	|| this->usage() == CU_InitiateAndAccept) {
	Argument_var arg = new IPCAcceptorArgument_impl;
	this->add_arg(arg);
    }
    // csiv1 support
    Argument_var csiv1_arg = new CSIv1Support_impl(csiv1_support_);
    this->add_arg(csiv1_arg);
    // csiv2 support
    Argument_var csiv2_arg = new CSIv2Support_impl(csiv2_support_);
    this->add_arg(csiv2_arg);
    // observers
    Argument_var observers_arg = new ObserverSeqArgument_impl(observers_);
    this->add_arg(observers_arg);
    return MICOSL3_SL3AQArgs::ArgBuilder_impl::reap_args();
}


//
// ArgumentFactory_impl
//

ArgBuilder_ptr
MICOSL3_SL3IPC::ArgumentFactory_impl::create_arg_builder(CredentialsUsage usage)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3IPC: ArgumentFactory_impl::create_arg_builder("
	    << usage << ")" << endl;
    }
    return new ArgBuilder_impl(usage);
}


//
// CredentialsAcquirer_impl
//

MICOSL3_SL3IPC::CredentialsAcquirer_impl::CredentialsAcquirer_impl
(SL3AQArgs::Argument_ptr value)
    : curator_impl_(NULL)
{
    ArgsHolder_var args = ArgsHolder::_narrow(value);
    assert(!CORBA::is_nil(args));
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3IPC: CredentialsAcquirer_impl" << endl
	    << "          args->usage(): " << args->usage() << endl;
    }
    ArgumentSeq_var argslist = args->args();
    CredentialsAcceptor_var acceptor = CredentialsAcceptor::_nil();
    CredentialsInitiator_var initiator = CredentialsInitiator::_nil();
    IPCInitiatorArgument_var initiator_arg = IPCInitiatorArgument::_nil();
    IPCAcceptorArgument_var acceptor_arg = IPCAcceptorArgument::_nil();
    CSIv1Support_var csiv1_arg = CSIv1Support::_nil();
    CSIv2Support_var csiv2_arg = CSIv2Support::_nil();    
    ObserverSeq observers;
    observers.length(0);
    for (ULong i = 0; i < argslist->length(); i++) {
	String_var type = argslist[i]->type();
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3IPC: type[" << i << "]: " << type.in() << endl;
	}
	if (strcmp(type.in(), IPCInitiatorArgumentType) == 0) {
	    initiator_arg = IPCInitiatorArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(initiator_arg));
	}
	else if (strcmp(type.in(), IPCAcceptorArgumentType) == 0) {
	    acceptor_arg = IPCAcceptorArgument::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(acceptor_arg));
	}
	else if (strcmp(type.in(), CSIv1SupportType) == 0) {
	    csiv1_arg = CSIv1Support::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(csiv1_arg));
	}
	else if (strcmp(type.in(), CSIv2SupportType) == 0) {
	    csiv2_arg = CSIv2Support::_narrow(argslist[i]);
	    assert(!CORBA::is_nil(csiv2_arg));
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
	&& !CORBA::is_nil(initiator_arg)) {
	// argument mismatch?
	assert(0);
    }
    if (args->usage() == CU_InitiateOnly
	&& !CORBA::is_nil(acceptor_arg)) {
	// argument mismatch?
	assert(0);
    }
    if (args->usage() == CU_InitiateOnly
	||args->usage() == CU_InitiateAndAccept) {
	assert(!CORBA::is_nil(initiator_arg));
    }
    if (args->usage() == CU_AcceptOnly
	||args->usage() == CU_InitiateAndAccept) {
	assert(!CORBA::is_nil(acceptor_arg));
    }
    if (!CORBA::is_nil(initiator_arg)) {
  	initiator = new IPCInitiator(initiator_arg);
    }
    if (!CORBA::is_nil(acceptor_arg)) {
  	acceptor = new IPCAcceptor(acceptor_arg);
    }
    assert(!CORBA::is_nil(csiv1_arg));
    assert(!CORBA::is_nil(csiv2_arg));
    TimeBase::UtcT tt;
    tt.time = 0xffffffffffffffffULL;
    tt.inacclo = 0;
    tt.inacchi = 0;
    tt.tdf = 0;
    string id = "MICO_IPC:";
    id += xdec(S_creds_index_);
    S_creds_index_++;
    MICOSL3_TransportSecurity::OwnCredentials_impl* cr
	= new MICOSL3_TransportSecurity::OwnCredentials_impl
	(id.c_str(), CS_Valid, CT_OwnCredentials, args->usage(), tt,
	 initiator, acceptor, csiv1_arg->support(), csiv2_arg->support(),
	 observers);
    creds_ = cr;
}


MICOSL3_SL3IPC::CredentialsAcquirer_impl::~CredentialsAcquirer_impl()
{
}


OwnCredentials_ptr
MICOSL3_SL3IPC::CredentialsAcquirer_impl::get_credentials
(CORBA::Boolean on_list)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3IPC: CredentialsAcquirer_impl::get_credentials" << endl
	    << "          creds_: " << creds_.in() << endl;
    }
    curator_impl_->add_own_credentials(creds_, on_list);
    TransportAcceptor_ptr acc = dynamic_cast<TransportSecurity::TransportAcceptor*>(creds_->the_acceptor());
    if (acc != NULL) {
	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	    MICOMT::AutoDebugLock lock;
	    MICO::Logger::Stream(MICO::Logger::Security)
		<< "SL3IPC: start listening on acceptor" << endl;
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
MICOSL3_SL3IPC::CredentialsAcquirer_impl::destroy()
{
    assert(0);
}

// extension
void
MICOSL3_SL3IPC::CredentialsAcquirer_impl::creds_curator_impl
(MICOSL3_TransportSecurity::CredentialsCurator_impl* curator)
{
    curator_impl_ = curator;
}


//
// CredentialsAcquirerFactory_impl
//

MICOSL3_SL3IPC::CredentialsAcquirerFactory_impl::CredentialsAcquirerFactory_impl()
{
    supported_types_[ArgsHolderType] = true;
    supported_types_[CSIv1SupportType] = true;
    supported_types_[CSIv2SupportType] = true;
    supported_types_[IPCInitiatorArgumentType] = true;
    supported_types_[IPCAcceptorArgumentType] = true;
    supported_types_[ObserverSeqArgumentType] = true;
}


CredentialsAcquirer_ptr
MICOSL3_SL3IPC::CredentialsAcquirerFactory_impl::create
(Argument_ptr value)
{
    return new CredentialsAcquirer_impl(value);
}


Boolean
MICOSL3_SL3IPC::CredentialsAcquirerFactory_impl::supports_all_args
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
// IPCInitiator
//

MICOSL3_SL3IPC::IPCInitiator::IPCInitiator(SL3AQArgs::Argument_ptr arg)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3IPC: IPCInitiator" << endl;
    }
    IPCInitiatorArgument_var argument = IPCInitiatorArgument::_narrow(arg);
    assert(!CORBA::is_nil(argument));
//      IPCInitiatorOptions_var options = argument->options();
//      host_ = options->bind;
//      low_port_ = options->low_port;
//      high_port_ = options->high_port;
    supports_endorsement_ = FALSE;
    supports_quoting_ = FALSE;
    supports_client_authentication_ = FALSE;
    supports_target_authentication_ = FALSE;
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
    name.the_type = (const char*)NT_Anonymous;
    name.the_name.length(1);
    name.the_name[0] = L"anonymous";
    principal->the_name(name);
    principal_ = principal;
    PrinAttributeList env_attr;
    env_attr.length(1);
    PrinAttribute a1;
    a1.the_type = "SL3:TransportMechanism";
    a1.the_value = L"IPC";
    env_attr[0] = a1;
    environmental_attributes_ = env_attr;
    statement_list_.length(1);
    MICOSL3_SL3PM::PrincipalIdentityStatement_impl* pistat
	= new MICOSL3_SL3PM::PrincipalIdentityStatement_impl;
    pistat->the_layer(SL_Transport);
    pistat->the_type(ST_IdentityStatement);
    CORBA::add_ref(principal_);
    pistat->the_principal(principal_);
    statement_list_[0] = pistat;
}


//
// IPCAcceptor
//

MICOSL3_SL3IPC::IPCAcceptor::IPCAcceptor(SL3AQArgs::Argument_ptr arg)
{
    IPCAcceptorArgument_var argument = IPCAcceptorArgument::_narrow(arg);
    assert(!CORBA::is_nil(argument));
//      IPCAcceptorOptions_var options = argument->options();
//      options_ = options;
//      hosts_ = options->hosts;
//      options_required_ = 0;
//      options_supported_ = 0;
    supports_endorsement_ = FALSE;
    supports_quoting_ = FALSE;
    supports_client_authentication_ = FALSE;
    supports_target_authentication_ = FALSE;
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
    name.the_type = (const char*)NT_Anonymous;
    name.the_name.length(1);
    name.the_name[0] = L"anonymous";
    principal->the_name(name);
    principal_ = principal;
    statement_list_.length(1);
    MICOSL3_SL3PM::PrincipalIdentityStatement_impl* pistat
	= new MICOSL3_SL3PM::PrincipalIdentityStatement_impl;
    pistat->the_layer(SL_Transport);
    pistat->the_type(ST_IdentityStatement);
    CORBA::add_ref(principal_);
    pistat->the_principal(principal_);
    statement_list_[0] = pistat;
    rsname_list_.length(0);
    PrinAttributeList env_attr;
    env_attr.length(1);
    PrinAttribute attr;
    attr.the_type = "SL3:TransportMechanism";
    attr.the_value = L"IPC";
    env_attr[0] = attr;
    environmental_attributes_ = env_attr;
}


void
MICOSL3_SL3IPC::IPCAcceptor::shutdown()
{
}


void
MICOSL3_SL3IPC::IPCAcceptor::enable()
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3IPC: IPCAcceptor::enable" << endl;
    }
//      CORBA::ORB_ptr orb = CORBA::ORB_instance("mico-local-orb", FALSE);
//      MICO::IIOPServer* server = new MICO::IIOPServer
//  	(orb, 0x0102 /* giop 1.2 */, 0 /* disable msg size checking */);
//      string addr = "inet:";
//      addr += this->bind();
//      addr += ":";
//      MICO::InetAddress* i_addr = NULL;
//      if (this->low_port() != 0) {
//  	if (this->low_port() < this->high_port()) {
//  	    // we will try to bind to specified port range
//  	    for (Long i = this->low_port(); i <= this->high_port(); i++) {
//  		string naddr = addr + xdec(i);
//  		if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
//  		    MICOMT::AutoDebugLock lock;
//  		    MICO::Logger::Stream(MICO::Logger::Security)
//  			<< "SL3IPC: naddr: " << naddr << endl;
//  		}
//  		Address* addr = Address::parse(naddr.c_str());
//  		assert(addr);
//  		if (server->listen(addr, 0)) {
//  		    i_addr = dynamic_cast<MICO::InetAddress*>(addr);
//  		    assert(i_addr != NULL);
//  		    break;
//  		}
//  		if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
//  		    MICOMT::AutoDebugLock lock;
//  		    MICO::Logger::Stream(MICO::Logger::Security)
//  			<< "SL3IPC: binding to "
//  			<< naddr << " failed" << endl;
//  		}
//  		delete addr;
//  	    }
//  	}
//  	else {
//  	    // high_port < low_port => we will try to bind to low_port
//  	    string naddr = addr + xdec(this->low_port());
//  	    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
//  		MICOMT::AutoDebugLock lock;
//  		MICO::Logger::Stream(MICO::Logger::Security)
//  		    << "SL3IPC: naddr2: " << naddr << endl;
//  	    }
//  	    Address* addr = Address::parse(naddr.c_str());
//  	    assert(addr);
//  	    if (server->listen(addr, 0)) {
//  		i_addr = dynamic_cast<MICO::InetAddress*>(addr);
//  		assert(i_addr != NULL);
//  	    }
//  	    else {
//  		if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
//  		    MICOMT::AutoDebugLock lock;
//  		    MICO::Logger::Stream(MICO::Logger::Security)
//  			<< "SL3IPC: binding(2) to "
//  			<< naddr << " failed" << endl;
//  		}
//  		delete addr;
//  	    }
//  	}
//      }
//      else {
//  	// we will try binding to system default.
//  	if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
//  	    MICOMT::AutoDebugLock lock;
//  	    MICO::Logger::Stream(MICO::Logger::Security)
//  		<< "SL3IPC: we will try binding to system default." << endl;
//  	}
//  	server->listen();
//      }
//      wstring t_addr = L"";
//      wstring t_port = L"";
//      if (i_addr != NULL) {
//  	t_addr = MICOSL3Utils::Address::ip_to_wstring(i_addr);
//  	t_port = MICOSL3Utils::Address::port_to_wstring(i_addr);
//      }
//      else {
//  	vector<CORBA::Octet> id = MICO::InetAddress::hostid();
//  	assert(id.size() == 4);
//  	t_addr = wxdec(id[0]) + L"." + wxdec(id[1]) + L"."
//  	    + wxdec(id[2]) + L"." + wxdec(id[3]);
//  	t_port = L"<unspecified value>";
//      }
//      CORBA::WString_var ip = t_addr.c_str();
//      CORBA::WString_var port = t_port.c_str();
//      PrinAttributeList env_attr;
//      env_attr.length(3);
//      PrinAttribute attr;
//      attr.the_type = "SL3:TransportMechanism";
//      attr.the_value = L"IPC";
//      env_attr[0] = attr;
//      attr.the_type = "SL3:LocalAddress";
//      attr.the_value = ip.in();
//      env_attr[1] = attr;
//      attr.the_type = "SL3:LocalPort";
//      attr.the_value = port.in();
//      env_attr[2] = attr;
//      environmental_attributes_ = env_attr;
}


//
// IPCInitiatingContext
//

MICOSL3_SL3IPC::IPCInitiatingContext::IPCInitiatingContext
(TransportSecurity::OwnCredentials_ptr parent)
    : TargetCredentials_impl(parent), InitiatingContext_impl(parent)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3IPC: IPCInitiatingContext" << endl;
    }
//      target_addr_ = target;
//      client_addr_ = client;
    string id = "MICO_IPCInitiatingContext:";
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
    // name
    PrincipalName name;
    name.the_type = (const char*)NT_Anonymous;
    name.the_name.length(1);
    name.the_name[0] = L"anonymous";
    // env attributes
    PrinAttributeList env_attr;
    env_attr.length(2);
    PrinAttribute a1;
    a1.the_type = "SL3:TransportMechanism";
    a1.the_value = L"IPC";
    env_attr[0] = a1;
//      a1.the_type = "SL3:ChannelIdentifier";
//      wstring channel_id = L"IPCv4:"
//  	+ MICOSL3Utils::Address::addr_to_wstring(client)
//  	+ L"-" + MICOSL3Utils::Address::addr_to_wstring(target);
//      a1.the_value = channel_id.c_str();
//      env_attr[1] = a1;
    a1.the_type = "SL3:EstablishmentTime";
    wstring time = wxdec(OSMisc::gettime().tv_sec);
    //    wstring time = wxdec(::time(0));
    a1.the_value = time.c_str();
    env_attr[1] = a1;
    environmental_attributes_ = env_attr;
    // pricipals
    SimplePrincipal* c_principal
	= new MICOSL3_SL3PM::SimplePrincipal_impl;
    c_principal->the_type(PT_Simple);
    c_principal->the_name(name);
    client_principal_ = c_principal;
    SimplePrincipal* t_principal
	= new MICOSL3_SL3PM::SimplePrincipal_impl;
    t_principal->the_type(PT_Simple);
    t_principal->the_name(name);
    target_principal_ = t_principal;
    // supporting statements
    client_supporting_statements_.length(1);
    MICOSL3_SL3PM::PrincipalIdentityStatement_impl* c_pis
	= new MICOSL3_SL3PM::PrincipalIdentityStatement_impl;
    c_pis->the_layer(SL_Transport);
    c_pis->the_type(ST_IdentityStatement);
    CORBA::add_ref(client_principal_);
    c_pis->the_principal(client_principal_);
    client_supporting_statements_[0] = c_pis;
    target_supporting_statements_.length(1);
    MICOSL3_SL3PM::PrincipalIdentityStatement_impl* t_pis
	= new MICOSL3_SL3PM::PrincipalIdentityStatement_impl;
    t_pis->the_layer(SL_Transport);
    t_pis->the_type(ST_IdentityStatement);
    CORBA::add_ref(target_principal_);
    t_pis->the_principal(target_principal_);
    target_supporting_statements_[0] = t_pis;
    // restricted resources
    client_restricted_resources_.length(0);
    target_restricted_resources_.length(0);
    // other (boolean) values
    client_authentication_ = FALSE;
    target_authentication_ = FALSE;
    confidentiality_ = TRUE;
    integrity_ = TRUE;
    target_embodied_ = FALSE;
    target_endorsed_ = FALSE;
}


//
// IPCAcceptingContext
//

MICOSL3_SL3IPC::IPCAcceptingContext::IPCAcceptingContext
(TransportSecurity::OwnCredentials_ptr parent)
    : ClientCredentials_impl(parent), AcceptingContext_impl(parent)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3IPC: IPCAcceptingContext" << endl;
    }
//      target_addr_ = target;
//      client_addr_ = client;
    string id = "MICO_IPCAcceptingContext:";
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
    // name
    PrincipalName name;
    name.the_type = (const char*)NT_Anonymous;
    name.the_name.length(1);
    name.the_name[0] = L"anonymous";
    // env attributes
    PrinAttributeList env_attr;
    env_attr.length(2);
    PrinAttribute a1;
    a1.the_type = "SL3:TransportMechanism";
    a1.the_value = L"IPC";
    env_attr[0] = a1;
//      a1.the_type = "SL3:ChannelIdentifier";
//      wstring channel_id = L"IPCv4:"
//  	+ MICOSL3Utils::Address::addr_to_wstring(client)
//  	+ L"-" + MICOSL3Utils::Address::addr_to_wstring(target);
//      a1.the_value = channel_id.c_str();
//      env_attr[1] = a1;
    a1.the_type = "SL3:EstablishmentTime";
    wstring time = wxdec(OSMisc::gettime().tv_sec);
    //    wstring time = wxdec(::time(0));
    a1.the_value = time.c_str();
    env_attr[1] = a1;
    environmental_attributes_ = env_attr;
    // pricipals
    SimplePrincipal* c_principal
	= new MICOSL3_SL3PM::SimplePrincipal_impl;
    c_principal->the_type(PT_Simple);
    c_principal->the_name(name);
    client_principal_ = c_principal;
    SimplePrincipal* t_principal
	= new MICOSL3_SL3PM::SimplePrincipal_impl;
    t_principal->the_type(PT_Simple);
    t_principal->the_name(name);
    target_principal_ = t_principal;
    // supporting statements
    client_supporting_statements_.length(1);
    MICOSL3_SL3PM::PrincipalIdentityStatement_impl* c_pis
	= new MICOSL3_SL3PM::PrincipalIdentityStatement_impl;
    c_pis->the_layer(SL_Transport);
    c_pis->the_type(ST_IdentityStatement);
    CORBA::add_ref(client_principal_);
    c_pis->the_principal(client_principal_);
    client_supporting_statements_[0] = c_pis;
    target_supporting_statements_.length(1);
    MICOSL3_SL3PM::PrincipalIdentityStatement_impl* t_pis
	= new MICOSL3_SL3PM::PrincipalIdentityStatement_impl;
    t_pis->the_layer(SL_Transport);
    t_pis->the_type(ST_IdentityStatement);
    CORBA::add_ref(target_principal_);
    t_pis->the_principal(target_principal_);
    target_supporting_statements_[0] = t_pis;
    // restricted resources
    client_restricted_resources_.length(0);
    target_restricted_resources_.length(0);
    // other (boolean) values
    client_authentication_ = FALSE;
    target_authentication_ = FALSE;
    confidentiality_ = TRUE;
    integrity_ = TRUE;
    impersonable_ = FALSE;
    endorseable_ = FALSE;
    quotable_ = FALSE;
}


//
// various supporting classes
//

MICOSL3_SL3IPC::ORBInitializer::ORBInitializer()
{
}


MICOSL3_SL3IPC::ORBInitializer::~ORBInitializer()
{
}


void
MICOSL3_SL3IPC::ORBInitializer::pre_init
(PortableInterceptor::ORBInitInfo_ptr info)
{
    ArgumentFactory_impl* factory = new ArgumentFactory_impl;
    info->register_initial_reference("SL3IPC::ArgBuilderFactory", factory);
}


void
MICOSL3_SL3IPC::ORBInitializer::post_init
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
    CredentialsAcquirerFactory_ptr fact = new CredentialsAcquirerFactory_impl;
    curator_impl->register_acquirer_factory(fact);
}


//
// IPCCredsMapper
//

MICOSL3_SL3IPC::IPCCredsMapper::IPCCredsMapper()
{
    assert(mapper_ == NULL);
}


MICOSL3_SL3IPC::IPCCredsMapper*
MICOSL3_SL3IPC::IPCCredsMapper::self()
{
    if (mapper_ == NULL)
	mapper_ = new IPCCredsMapper;
    assert(mapper_ != NULL);
    return mapper_;
}


ClientCredentials_ptr
MICOSL3_SL3IPC::IPCCredsMapper::get_client_credentials(OwnCredentials_ptr creds)
{
    assert(!CORBA::is_nil(creds));
    String_var id = creds->creds_id();
    string key = id.in();
    if (client_creds_map_.count(key) > 0) {
	return ClientCredentials::_duplicate(client_creds_map_[key]);
    }
    return ClientCredentials::_nil();
}

TargetCredentials_ptr
MICOSL3_SL3IPC::IPCCredsMapper::get_target_credentials(OwnCredentials_ptr creds)
{
    assert(!CORBA::is_nil(creds));
    String_var id = creds->creds_id();
    string key = id.in();
    if (target_creds_map_.count(key) > 0) {
	return TargetCredentials::_duplicate(target_creds_map_[key]);
    }
    return TargetCredentials::_nil();
}


void
MICOSL3_SL3IPC::IPCCredsMapper::add_client_credentials
(OwnCredentials_ptr own_creds,
 ClientCredentials_ptr client_creds)
{
    assert(!CORBA::is_nil(own_creds));
    String_var id = own_creds->creds_id();
    string key = id.in();
    assert(client_creds_map_.count(key) == 0);
    client_creds_map_[key] = ClientCredentials::_duplicate(client_creds);
}


void
MICOSL3_SL3IPC::IPCCredsMapper::add_target_credentials
(OwnCredentials_ptr own_creds,
 TargetCredentials_ptr target_creds)
{
    assert(!CORBA::is_nil(own_creds));
    String_var id = own_creds->creds_id();
    string key = id.in();
    assert(target_creds_map_.count(key) == 0);
    target_creds_map_[key] = TargetCredentials::_duplicate(target_creds);
}


void
MICOSL3_SL3IPC::IPCCredsMapper::remove_credentials(OwnCredentials_ptr own_creds)
{
    assert(0);
}

