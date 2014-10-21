//
//  MICO SL3 --- an Open Source SL3 implementation
//  Copyright (C) 2004, 2005 ObjectSecurity Ltd.
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

#include <CORBA.h>
#include <mico/util.h>


using namespace CORBA;
// kcg: don't use `using namespace std;' here and don't remove
// all the `std::' prefixes below, since this leads to the error:
// ``error C2955: 'std::map' : use of class template requires template
// argument list'' while compiling with VC++ 2003

//
// module initialization
//
void
MICOSL3_SL3CMDEXT::_init()
{
    PortableInterceptor::register_orb_initializer(new ORBInitializer());
}

namespace MICOSL3_SL3CMDEXT
{
class PasswordGenerator_impl
    : virtual public UserPassword::PasswordGenerator,
      virtual public CORBA::LocalObject
{
public:
    PasswordGenerator_impl(const std::map<std::wstring, std::pair<std::wstring, std::wstring> >& map);

    virtual SL3PM::PrincipalName*
    client_authentication_principal();

    virtual UserPassword::ErrorCode
    generate_password
    (const SL3PM::PrincipalName& target,
     CORBA::WString_out username,
     CORBA::WString_out password);
private:
    std::map<std::wstring, std::pair<std::wstring, std::wstring> > realm_user_pw_map_;
};


class PasswordProcessor_impl
    : virtual public UserPassword::PasswordProcessor,
      virtual public CORBA::LocalObject
{
public:
    PasswordProcessor_impl
    (const std::wstring& realm,
     const std::map<std::wstring, std::wstring>& users);

    virtual CORBA::Boolean
    client_authen_required();

    virtual SL3PM::PrincipalName*
    password_target();

    virtual UserPassword::ErrorCode
    verify_password
    (const CORBA::WChar* username,
     const CORBA::WChar* password,
     SL3PM::PrincipalName_out principal);
private:
    std::wstring realm_;
    std::map<std::wstring, std::wstring> users_map_;
};
}


//
// PasswordGenerator_impl
//
MICOSL3_SL3CMDEXT::PasswordGenerator_impl::PasswordGenerator_impl
(const std::map<std::wstring, std::pair<std::wstring, std::wstring> >& map)
    : realm_user_pw_map_(map)
{
}


SL3PM::PrincipalName*
MICOSL3_SL3CMDEXT::PasswordGenerator_impl::client_authentication_principal()
{
    std::wstring name = (*realm_user_pw_map_.begin()).second.first;
    SL3PM::PrincipalName* result = new SL3PM::PrincipalName;
    result->the_type = (const char*)SL3PM::NT_StringName;
    result->the_name.length(1);
    result->the_name[0] = name.c_str();
    return result;
}


UserPassword::ErrorCode
MICOSL3_SL3CMDEXT::PasswordGenerator_impl::generate_password
(const SL3PM::PrincipalName& target, WString_out username, WString_out password)
{
    if (strcmp(SL3PM::NT_StringName, target.the_type) == 0) {
        std::wstring realm = CORBA::wstring_dup(target.the_name[0].in());
	if (realm_user_pw_map_.count(realm) > 0) {
	    username = realm_user_pw_map_[realm].first.c_str();
	    password = realm_user_pw_map_[realm].second.c_str();
            return UserPassword::EC_Success;
        }
	return UserPassword::EC_NoUser;
    }
    return UserPassword::EC_BadTarget;
}


//
// PasswordProcessor_impl
//
MICOSL3_SL3CMDEXT::PasswordProcessor_impl::PasswordProcessor_impl
(const std::wstring& realm, const std::map<std::wstring, std::wstring>& users)
    : realm_(realm), users_map_(users)
{
}


Boolean
MICOSL3_SL3CMDEXT::PasswordProcessor_impl::client_authen_required()
{
    return TRUE;
}


SL3PM::PrincipalName*
MICOSL3_SL3CMDEXT::PasswordProcessor_impl::password_target()
{
    SL3PM::PrincipalName* result = new SL3PM::PrincipalName;
    result->the_type = (const char*)SL3PM::NT_StringName;
    result->the_name.length(1);
    result->the_name[0] = realm_.c_str();
    return result;
}


UserPassword::ErrorCode
MICOSL3_SL3CMDEXT::PasswordProcessor_impl::verify_password
(const CORBA::WChar* username,
 const CORBA::WChar* password,
 SL3PM::PrincipalName_out principal)
{
    std::wstring name = username;
    std::wstring pw = password;
    if (users_map_.count(name) > 0) {
	if (users_map_[name] == pw) {
	    principal = new SL3PM::PrincipalName;
	    principal->the_type = (const char*)SL3PM::NT_StringName;
	    principal->the_name.length(1);
	    principal->the_name[0] = name.c_str();
	    return UserPassword::EC_Success;
	}
	else {
	    return UserPassword::EC_BadPassword;
	}
    }
    return UserPassword::EC_NoUser;
}


//
// module specific ORBInitializer
//
MICOSL3_SL3CMDEXT::ORBInitializer::ORBInitializer()
{
}


MICOSL3_SL3CMDEXT::ORBInitializer::~ORBInitializer()
{
}


void
MICOSL3_SL3CMDEXT::ORBInitializer::pre_init
(PortableInterceptor::ORBInitInfo_ptr info)
{
}


void
MICOSL3_SL3CMDEXT::ORBInitializer::post_init
(PortableInterceptor::ORBInitInfo_ptr info)
{
    Boolean sl3_cmd_ext_used = FALSE;
    Boolean tcpip_initiator_used = FALSE;
    std::string tcpip_initiator_options = "";
    Boolean tcpip_acceptor_used = FALSE;
    std::string tcpip_acceptor_options = "";
    Boolean tls_initiator_used = FALSE;
    std::string tls_initiator_options = "";
    Boolean tls_acceptor_used = FALSE;
    std::string tls_acceptor_options = "";
    std::string tls_certs_initiator_options = "";
    std::string tls_certs_acceptor_options = "";
    Long tls_initiator_verify_depth = -1;
    Long tls_acceptor_verify_depth = -1;
    Boolean ipc_initiator_used = FALSE;
    Boolean ipc_acceptor_used = FALSE;
    std::map<std::wstring, std::pair<std::wstring, std::wstring> > client_users;
    std::map<std::wstring, std::wstring> server_users;
    std::wstring realm = L"";
    ORB_var orb = ORB_instance("mico-local-orb", FALSE);
    assert(!CORBA::is_nil(orb));
    StringSeq_var args = info->arguments();
    for (ULong i = 0; i < args->length(); i++) {
	if (strcmp(args[i].in(), "-ORBSL3CmdExt") == 0) {
	    sl3_cmd_ext_used = TRUE;
	    orb->register_option_for_removal("-ORBSL3CmdExt", false);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3TCPIPInitiator") == 0) {
	    tcpip_initiator_used = TRUE;
	    orb->register_option_for_removal("-ORBSL3TCPIPInitiator", false);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3TCPIPInitiator2") == 0) {
	    tcpip_initiator_used = TRUE;
	    i++;
	    tcpip_initiator_options = CORBA::string_dup(args[i].in());
	    orb->register_option_for_removal("-ORBSL3TCPIPInitiator2", true);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3TCPIPAcceptor") == 0) {
	    tcpip_acceptor_used = TRUE;
	    orb->register_option_for_removal("-ORBSL3TCPIPAcceptor", false);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3TCPIPAcceptor2") == 0) {
	    tcpip_acceptor_used = TRUE;
	    i++;
	    tcpip_acceptor_options = CORBA::string_dup(args[i].in());
	    orb->register_option_for_removal("-ORBSL3TCPIPAcceptor2", true);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3TLSInitiator") == 0) {
	    tls_initiator_used = TRUE;
	    orb->register_option_for_removal("-ORBSL3TLSInitiator", false);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3TLSInitiator2") == 0) {
	    tls_initiator_used = TRUE;
	    i++;
	    tls_initiator_options = CORBA::string_dup(args[i].in());
	    orb->register_option_for_removal("-ORBSL3TLSInitiator2", true);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3TLSInitiatorOptions") == 0) {
	    i++;
	    tls_certs_initiator_options = CORBA::string_dup(args[i].in());
	    orb->register_option_for_removal("-ORBSL3TLSInitiatorOptions", true);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3TLSAcceptor") == 0) {
	    tls_acceptor_used = TRUE;
	    tls_acceptor_options = CORBA::string_dup("0.0.0.0:0");
	    orb->register_option_for_removal("-ORBSL3TLSAcceptor", false);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3TLSAcceptor2") == 0) {
	    tls_acceptor_used = TRUE;
	    i++;
	    tls_acceptor_options = CORBA::string_dup(args[i].in());
	    orb->register_option_for_removal("-ORBSL3TLSAcceptor2", true);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3TLSAcceptorOptions") == 0) {
	    i++;
	    tls_certs_acceptor_options = CORBA::string_dup(args[i].in());
	    orb->register_option_for_removal("-ORBSL3TLSAcceptorOptions", true);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3TLSInitiatorVerifyDepth") == 0) {
	    i++;
	    tls_initiator_verify_depth = atoi(args[i].in());
	    orb->register_option_for_removal("-ORBSL3TLSInitiatorVerifyDepth", true);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3TLSAcceptorVerifyDepth") == 0) {
	    i++;
	    tls_acceptor_verify_depth = atoi(args[i].in());
	    orb->register_option_for_removal("-ORBSL3TLSAcceptorVerifyDepth", true);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3IPCInitiator") == 0) {
	    ipc_initiator_used = TRUE;
	    orb->register_option_for_removal("-ORBSL3IPCInitiator", false);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3IPCAcceptor") == 0) {
	    ipc_acceptor_used = TRUE;
	    orb->register_option_for_removal("-ORBSL3IPCAcceptor", false);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3CSIClientUser") == 0) {
	    i++;
	    std::string user = CORBA::string_dup(args[i].in());
	    assert(user.find(",") != std::string::npos);
	    std::string realm = user.substr(0, user.find(","));
	    std::string tmp = user.substr(user.find(",") + 1);
	    std::string name = tmp.substr(0, tmp.find(","));
	    std::string pw = user.substr(user.rfind(",") + 1);
	    std::wstring wrealm = str2wstr(realm);
	    std::wstring wname = str2wstr(name);
	    std::wstring wpw = str2wstr(pw);
	    client_users[wrealm] = std::pair<std::wstring, std::wstring>(wname, wpw);
	    orb->register_option_for_removal("-ORBSL3CSIClientUser", true);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3CSIServerUser") == 0) {
	    i++;
	    std::string user = CORBA::string_dup(args[i].in());
	    assert(user.find(",") != std::string::npos);
	    std::string name = user.substr(0, user.find(","));
	    std::string pw = user.substr(user.find(",") + 1);
	    std::wstring wname = str2wstr(name);
	    std::wstring wpw = str2wstr(pw);
	    server_users[wname] = wpw;
	    orb->register_option_for_removal("-ORBSL3CSIServerUser", true);
	    continue;
	}
	else if (strcmp(args[i].in(), "-ORBSL3CSIServerRealm") == 0) {
	    i++;
	    std::string arg = CORBA::string_dup(args[i].in());
	    realm = str2wstr(arg);
	    orb->register_option_for_removal("-ORBSL3CSIServerRealm", true);
	    continue;
	}
    }
    // ignore any extension command-line arguments if -ORBSL3CmdExt
    // is not used
    if (!sl3_cmd_ext_used) {
	return;
    }
    TransportSecurity::OwnCredentials_var transp_creds
	= TransportSecurity::OwnCredentials::_nil();
    if (ipc_initiator_used || ipc_acceptor_used) {
	// setup IPC transport
	SL3CM::CredentialsUsage usage = SL3CM::CU_None;
	if (ipc_initiator_used && ipc_acceptor_used) {
	    usage = SL3CM::CU_InitiateAndAccept;
	}
	else {
	    std::cerr << "For correct usage of IPC security, the application has"
                      << " to setup both: initiator and acceptor sides." << std::endl;
	    assert(0);
	}
        Object_var obj = orb->resolve_initial_references
	    ("SL3IPC::ArgBuilderFactory");
        SL3AQArgs::ArgBuilderFactory_var fact
            = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
        assert(!CORBA::is_nil(fact));
        SL3IPC::IPCArgBuilder_var ts_builder
            = SL3IPC::IPCArgBuilder::_narrow
            (fact->create_arg_builder(usage));
        assert(!CORBA::is_nil(ts_builder));
        SL3AQArgs::Argument_var ts_args = ts_builder->reap_args();
	obj = orb->resolve_initial_references
	    ("TransportSecurity::SecurityManager");
	TransportSecurity::SecurityManager_var ts_secman
	    = TransportSecurity::SecurityManager::_narrow(obj);
	assert(!CORBA::is_nil(ts_secman));
	TransportSecurity::CredentialsCurator_var ts_curator
	    = ts_secman->credentials_curator();
	TransportSecurity::CredentialsAcquirer_var ts_acquirer
	    = ts_curator->acquire_credentials(ts_args);
	// we do not use transp_creds here
	// since we wouldn't like to propagate IPC creds
	// globaly
	TransportSecurity::OwnCredentials_var creds
	    = ts_acquirer->get_credentials(TRUE);
    }
    if (tcpip_initiator_used || tcpip_acceptor_used) {
	// setup TCPIP transport
	SL3CM::CredentialsUsage usage = SL3CM::CU_None;
	if (tcpip_initiator_used && tcpip_acceptor_used) {
	    usage = SL3CM::CU_InitiateAndAccept;
	}
	else if (tcpip_acceptor_used) {
	    usage = SL3CM::CU_AcceptOnly;
	}
	else if (tcpip_initiator_used) {
	    usage = SL3CM::CU_InitiateOnly;
	}
	Object_var obj = orb->resolve_initial_references
	    ("SL3TCPIP::ArgBuilderFactory");
	SL3AQArgs::ArgBuilderFactory_var ts_fact
	    = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
	assert(!CORBA::is_nil(ts_fact));
	SL3TCPIP::TCPIPArgBuilder_var ts_builder
	    = SL3TCPIP::TCPIPArgBuilder::_narrow
	    (ts_fact->create_arg_builder(usage));
	assert(!CORBA::is_nil(ts_builder));
	if (tcpip_acceptor_used && tcpip_acceptor_options != "") {
	    assert(tcpip_acceptor_options.find(":") != std::string::npos);
	    std::string host = tcpip_acceptor_options.substr
		(0, tcpip_acceptor_options.find(":"));
	    ULong port = atoi(tcpip_acceptor_options.substr
			      (tcpip_acceptor_options.find(":") + 1).c_str());
	    CORBA::StringSeq sseq(0);
	    ts_builder->add_tcpip_acceptor_options(sseq, host.c_str(), port, 0, 0, FALSE);
	}
	if (tcpip_initiator_used && tcpip_initiator_options != "") {
	    assert(tcpip_initiator_options.find(":") != std::string::npos);
	    std::string host = tcpip_initiator_options.substr
		(0, tcpip_initiator_options.find(":"));
	    ULong port = atoi(tcpip_initiator_options.substr
			      (tcpip_initiator_options.find(":") + 1).c_str());
	    ts_builder->add_tcpip_initiator_options(host.c_str(), port, 0, 0);
	}
	SL3AQArgs::Argument_var ts_args = ts_builder->reap_args();
	obj = orb->resolve_initial_references
	    ("TransportSecurity::SecurityManager");
	TransportSecurity::SecurityManager_var ts_secman
	    = TransportSecurity::SecurityManager::_narrow(obj);
	assert(!CORBA::is_nil(ts_secman));
	TransportSecurity::CredentialsCurator_var ts_curator
	    = ts_secman->credentials_curator();
	TransportSecurity::CredentialsAcquirer_var ts_acquirer
	    = ts_curator->acquire_credentials(ts_args);
	transp_creds = ts_acquirer->get_credentials(TRUE);
    }
    if (tls_initiator_used || tls_acceptor_used) {
	// setup TLS transport
	SL3CM::CredentialsUsage usage = SL3CM::CU_None;
	if (tls_initiator_used && tls_acceptor_used) {
	    usage = SL3CM::CU_InitiateAndAccept;
	}
	else if (tls_acceptor_used) {
	    usage = SL3CM::CU_AcceptOnly;
	}
	else if (tls_initiator_used) {
	    usage = SL3CM::CU_InitiateOnly;
	}
	Object_var obj = orb->resolve_initial_references
	    ("SL3TLS::ArgBuilderFactory");
	SL3AQArgs::ArgBuilderFactory_var ts_fact
	    = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
	assert(!CORBA::is_nil(ts_fact));
	SL3TLS::OpenSSLConfigArgBuilder_var ts_builder
	    = SL3TLS::OpenSSLConfigArgBuilder::_narrow
	    (ts_fact->create_arg_builder(usage));
	assert(!CORBA::is_nil(ts_builder));
	if (tls_acceptor_used && tls_acceptor_options != "") {
	    assert(tls_acceptor_options.find(":") != std::string::npos);
	    std::string host = tls_acceptor_options.substr
		(0, tls_acceptor_options.find(":"));
	    ULong port = atoi(tls_acceptor_options.substr
			      (tls_acceptor_options.find(":") + 1).c_str());
	    CORBA::StringSeq sseq(0);
	    ts_builder->add_tcpip_acceptor_options(sseq, host.c_str(), port, 0, 0, FALSE);
	}
	if (tls_acceptor_used && tls_certs_acceptor_options != "") {
	    std::string ca = "";
	    std::string cert = "";
	    std::string key = "";
	    ca = tls_certs_acceptor_options.substr(0, tls_certs_acceptor_options.find(","));
	    std::string tmp = tls_certs_acceptor_options.substr(0, tls_certs_acceptor_options.rfind(","));
	    cert = tmp.substr(tmp.find(",") + 1);
	    key = tls_certs_acceptor_options.substr(tls_certs_acceptor_options.rfind(",") + 1);
	    ts_builder->add_tls_acceptor_options(ca.c_str(), cert.c_str(), key.c_str());
	}
	if (tls_initiator_used && tls_initiator_options != "") {
	    assert(tls_initiator_options.find(":") != std::string::npos);
	    std::string host = tls_initiator_options.substr
		(0, tls_initiator_options.find(":"));
	    ULong port = atoi(tls_initiator_options.substr
			      (tls_initiator_options.find(":") + 1).c_str());
	    ts_builder->add_tcpip_initiator_options(host.c_str(), port, 0, 0);
	}
	if (tls_initiator_used && tls_certs_initiator_options != "") {
	    std::string ca = "";
	    std::string cert = "";
	    std::string key = "";
	    ca = tls_certs_initiator_options.substr(0, tls_certs_initiator_options.find(","));
	    std::string tmp = tls_certs_initiator_options.substr(0, tls_certs_initiator_options.rfind(","));
	    cert = tmp.substr(tmp.find(",") + 1);
	    key = tls_certs_initiator_options.substr(tls_certs_initiator_options.rfind(",") + 1);
	    ts_builder->add_tls_initiator_options(ca.c_str(), cert.c_str(), key.c_str());
	}
	if (tls_acceptor_verify_depth != -1) {
	    ts_builder->add_acceptor_verify_depth(tls_acceptor_verify_depth);
	}
	if (tls_initiator_verify_depth != -1) {
	    ts_builder->add_initiator_verify_depth(tls_initiator_verify_depth);
	}
	SL3AQArgs::Argument_var ts_args = ts_builder->reap_args();
	obj = orb->resolve_initial_references
	    ("TransportSecurity::SecurityManager");
	TransportSecurity::SecurityManager_var ts_secman
	    = TransportSecurity::SecurityManager::_narrow(obj);
	assert(!CORBA::is_nil(ts_secman));
	TransportSecurity::CredentialsCurator_var ts_curator
	    = ts_secman->credentials_curator();
	TransportSecurity::CredentialsAcquirer_var ts_acquirer
	    = ts_curator->acquire_credentials(ts_args);
	transp_creds = ts_acquirer->get_credentials(TRUE);
    }
    if (client_users.size() != 0 || server_users.size() != 0) {
	// setup SL3CSI credentials
	SL3CM::CredentialsUsage usage = SL3CM::CU_None;
	if (client_users.size() != 0 && server_users.size() != 0) {
	    usage = SL3CM::CU_InitiateAndAccept;
	}
	else if (client_users.size() != 0 && server_users.size() == 0) {
	    usage = SL3CM::CU_InitiateOnly;
	}
	else if (client_users.size() == 0 && server_users.size() != 0) {
	    usage = SL3CM::CU_AcceptOnly;
	}
	Object_var obj = orb->resolve_initial_references("SL3CSI::ArgBuilderFactory");
	SL3AQArgs::ArgBuilderFactory_var csi_fact
	    = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
	assert(!CORBA::is_nil(csi_fact));
	SL3CSI::CSIArgBuilder_var csi_builder
	    = SL3CSI::CSIArgBuilder::_narrow
	    (csi_fact->create_arg_builder(usage));
	assert(!CORBA::is_nil(csi_builder));
	csi_builder->add_transport_credentials(transp_creds);
	if (client_users.size() != 0) {
	    UserPassword::PasswordGenerator_var generator
		= new PasswordGenerator_impl(client_users);
	    csi_builder->add_password_generator(generator);
	}
	if (server_users.size() != 0) {
	    UserPassword::PasswordProcessor_var processor
		= new PasswordProcessor_impl(realm, server_users);
	    csi_builder->add_password_processor(processor);
	}
	SL3AQArgs::Argument_var args = csi_builder->reap_args();
	obj = orb->resolve_initial_references
	    ("SecurityLevel3::SecurityManager");
	SecurityLevel3::SecurityManager_var secman
	    = SecurityLevel3::SecurityManager::_narrow(obj);
	assert(!CORBA::is_nil(secman));
	SecurityLevel3::CredentialsCurator_var curator
	    = secman->credentials_curator();
	SecurityLevel3::CredentialsAcquirer_var acquirer
	    = curator->acquire_credentials(args);
	SecurityLevel3::OwnCredentials_var creds = acquirer->get_credentials(TRUE);
    }
}

