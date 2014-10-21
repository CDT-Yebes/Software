//
// Test for etherealize/incarnate
//

#include "hello.h"
#ifdef HAVE_ANSI_CPLUSPLUS_HEADERS
#include <fstream>
#else // HAVE_ANSI_CPLUSPLUS_HEADERS
#include <fstream.h>
#endif // HAVE_ANSI_CPLUSPLUS_HEADERS

#include <mico/security/sl3utils.h>

using namespace std;

CORBA::ORB_ptr orb = CORBA::ORB::_nil();

// client side

class PasswordGenerator_impl
    : virtual public UserPassword::PasswordGenerator,
      virtual public CORBA::LocalObject
{
public:
    virtual SL3PM::PrincipalName*
    client_authentication_principal();

    virtual UserPassword::ErrorCode
    generate_password
    (const SL3PM::PrincipalName& target,
     CORBA::WString_out username,
     CORBA::WString_out password);
};

SL3PM::PrincipalName*
PasswordGenerator_impl::client_authentication_principal()
{
    //cerr << "PasswordGenerator_impl::client_authentication_principal()" << endl;
    SL3PM::PrincipalName* result = new SL3PM::PrincipalName;
    result->the_type = (const char*)SL3PM::NT_StringName;
    result->the_name.length(1);
    result->the_name[0] = L"karel";
    return result;
}

UserPassword::ErrorCode
PasswordGenerator_impl::generate_password
(const SL3PM::PrincipalName& target,
 CORBA::WString_out username,
 CORBA::WString_out password)
{
    //cerr << "PasswordGenerator_impl::generate_password" << endl;
    wstring realm = L"@objectsecurity.com";
    if (strcmp(SL3PM::NT_StringName, target.the_type) == 0) {
	if (realm == target.the_name[0].in()) {
	    username = L"karel";
	    password = L"cobalt";
	    //password = L"bad_passwd";
	    return UserPassword::EC_Success;
	}
    }
    return UserPassword::EC_BadTarget;
}

// server side

class PasswordProcessor_impl
    : virtual public UserPassword::PasswordProcessor,
      virtual public CORBA::LocalObject
{
public:
    virtual CORBA::Boolean
    client_authen_required();

    virtual SL3PM::PrincipalName*
    password_target();

    virtual UserPassword::ErrorCode
    verify_password
    (const CORBA::WChar* username,
     const CORBA::WChar* password,
     SL3PM::PrincipalName_out principal);
};

CORBA::Boolean
PasswordProcessor_impl::client_authen_required()
{
    return TRUE;
}

SL3PM::PrincipalName*
PasswordProcessor_impl::password_target()
{
    SL3PM::PrincipalName* result = new SL3PM::PrincipalName;
    result->the_type = (const char*)SL3PM::NT_StringName;
    result->the_name.length(1);
    result->the_name[0] = L"@objectsecurity.com";
    return result;
}

UserPassword::ErrorCode
PasswordProcessor_impl::verify_password
(const CORBA::WChar* username,
 const CORBA::WChar* password,
 SL3PM::PrincipalName_out principal)
{
    //cerr << "PasswordProcessor_impl::verify_password" << endl;
    wstring name = username;
    wstring pw = password;
    if (name == L"karel") {
	if (pw == L"cobalt") {
	    principal = new SL3PM::PrincipalName;
	    principal->the_type = (const char*)SL3PM::NT_StringName;
	    principal->the_name.length(1);
	    principal->the_name[0] = L"karel";
	    return UserPassword::EC_Success;
	}
	return UserPassword::EC_BadPassword;
    }
    return UserPassword::EC_NoUser;
}

class HelloWorld_impl
    : virtual public POA_HelloWorld
{
public:
    void hello();
};

void
HelloWorld_impl::hello()
{
    wcout << "Hello World" << endl;
    CORBA::Object_var obj = orb->resolve_initial_references
	("SecurityLevel3::SecurityCurrent");
    SecurityLevel3::SecurityCurrent_var current
	= SecurityLevel3::SecurityCurrent::_narrow(obj);
    assert(!CORBA::is_nil(current));
    SecurityLevel3::ClientCredentials_ptr creds
	= current->client_credentials();
    //cerr << "creds: " << creds << endl;
    wcout << "ClientCredentials:" << endl;
    MICOSL3Utils::PP::print_client_credentials(&wcout, creds);
    wcout << endl;
}

int
main (int argc, char *argv[])
{
    wcout << "wcout init" << endl;
    try {
	orb = CORBA::ORB_init(argc, argv);
	CORBA::Object_var obj = orb->resolve_initial_references
	    ("SecurityLevel3::SecurityManager");
	SecurityLevel3::SecurityManager_var secman
	    = SecurityLevel3::SecurityManager::_narrow(obj);
	assert(!CORBA::is_nil(secman));
	SecurityLevel3::CredentialsCurator_var curator
	    = secman->credentials_curator();
	assert(!CORBA::is_nil(curator));
	// first we need to obtain transport credentials
        // IPC credentials
        obj = orb->resolve_initial_references("SL3IPC::ArgBuilderFactory");
        SL3AQArgs::ArgBuilderFactory_var ipc_fact
            = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
        assert(!CORBA::is_nil(ipc_fact));
        SL3IPC::IPCArgBuilder_var ipc_builder
            = SL3IPC::IPCArgBuilder::_narrow
            (ipc_fact->create_arg_builder(SL3CM::CU_InitiateAndAccept));
        assert(!CORBA::is_nil(ipc_builder));
        SL3AQArgs::Argument_var ipc_args = ipc_builder->reap_args();
        // TCPIP credentials -- we need them to succesfully generate IOR
        // for target object
	obj = orb->resolve_initial_references("SL3TCPIP::ArgBuilderFactory");
	SL3AQArgs::ArgBuilderFactory_var tcpip_fact
	    = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
	assert(!CORBA::is_nil(tcpip_fact));
	SL3TCPIP::TCPIPArgBuilder_var tcpip_builder
	    = SL3TCPIP::TCPIPArgBuilder::_narrow
	    (tcpip_fact->create_arg_builder(SL3CM::CU_AcceptOnly));
	assert(!CORBA::is_nil(tcpip_builder));
	SL3AQArgs::Argument_var tcpip_args = tcpip_builder->reap_args();
	obj = orb->resolve_initial_references
	    ("TransportSecurity::SecurityManager");
	TransportSecurity::SecurityManager_var ts_secman
	    = TransportSecurity::SecurityManager::_narrow(obj);
	assert(!CORBA::is_nil(ts_secman));
	TransportSecurity::CredentialsCurator_var ts_curator
	    = ts_secman->credentials_curator();
	TransportSecurity::CredentialsAcquirer_var ipc_acquirer
	    = ts_curator->acquire_credentials(ipc_args);
	TransportSecurity::OwnCredentials_var ipc_creds = ipc_acquirer->get_credentials(TRUE);
	TransportSecurity::CredentialsAcquirer_var tcpip_acquirer
	    = ts_curator->acquire_credentials(tcpip_args);
	TransportSecurity::OwnCredentials_var tcpip_creds = tcpip_acquirer->get_credentials(TRUE);
	//MICOSL3Utils::PP::print_own_credentials(&wcout, ts_creds);

	obj = orb->resolve_initial_references("SL3CSI::ArgBuilderFactory");
	SL3AQArgs::ArgBuilderFactory_var csi_fact
	    = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
	assert(!CORBA::is_nil(csi_fact));
	SL3CSI::CSIArgBuilder_var csi_builder
	    = SL3CSI::CSIArgBuilder::_narrow
	    (csi_fact->create_arg_builder(SL3CM::CU_InitiateAndAccept));
	assert(!CORBA::is_nil(csi_builder));

	csi_builder->add_transport_credentials(ipc_creds);
	UserPassword::PasswordProcessor_var processor = new PasswordProcessor_impl;
	csi_builder->add_password_processor(processor);
	UserPassword::PasswordGenerator_var generator = new PasswordGenerator_impl;
	csi_builder->add_password_generator(generator);
	SL3AQArgs::Argument_var args = csi_builder->reap_args();

	SecurityLevel3::CredentialsAcquirer_var acquirer
	    = curator->acquire_credentials(args);
	SecurityLevel3::OwnCredentials_var creds = acquirer->get_credentials(TRUE);
	wcout << "server: OwnCredentials:" << endl;
	MICOSL3Utils::PP::print_own_credentials(&wcout, creds);

	CORBA::Object_var poaobj = orb->resolve_initial_references("RootPOA");
	PortableServer::POA_var poa = PortableServer::POA::_narrow(poaobj);
	PortableServer::POAManager_var mgr = poa->the_POAManager();

	HelloWorld_impl* servant = new HelloWorld_impl;
	PortableServer::ObjectId_var oid = poa->activate_object(servant);
	CORBA::Object_var ref = poa->id_to_reference(oid.in());
	ofstream of ("hello.ref");
	CORBA::String_var str = orb->object_to_string(ref);
	of << str.in() << endl;
	of.close();

	wcout << "Running." << endl;

	mgr->activate();
	//orb->run();
        // force marshalling and so PI upcalls
        CORBA::Object_var hello_obj = new CORBA::Object(new CORBA::IOR(str.in()));
        // we need to setup domains to get appropriate transport preference policy
        // from the domain manager -- this is needed for CSIv2, where we need
        // to get correct "active" IOR profile
        hello_obj->_setup_domains(CORBA::Object::_nil());
        HelloWorld_var hello = HelloWorld::_narrow(hello_obj);
        assert(!CORBA::is_nil(hello));
       
        SecurityLevel3::TargetCredentials_var tcreds1 = secman->get_target_credentials(hello);
        wcout << endl;
        wcout << "Target credentials:" << endl;
        if (!CORBA::is_nil(tcreds1)) {
            MICOSL3Utils::PP::print_target_credentials(&wcout, tcreds1);
        }
        else {
            wcout << "TargetCredentials == NULL" << endl;
        }
        hello->hello();
    } catch (CORBA::UserException& ex) {
	wcout << "UserException caught: " << ex._repoid() << endl;
    } catch (CORBA::SystemException_catch& ex) {
	wcout << "SystemException caught: " << ex._repoid() << endl;
    } catch (...) {
	wcout << "... caught!" << endl;
    }
    return 0;
}
