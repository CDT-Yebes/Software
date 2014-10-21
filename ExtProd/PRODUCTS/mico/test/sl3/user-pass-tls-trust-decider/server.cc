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
    wcout << "server: Hello World" << endl;
    CORBA::Object_var obj = orb->resolve_initial_references
	("SecurityLevel3::SecurityCurrent");
    SecurityLevel3::SecurityCurrent_var current
	= SecurityLevel3::SecurityCurrent::_narrow(obj);
    assert(!CORBA::is_nil(current));
    SecurityLevel3::ClientCredentials_ptr creds
	= current->client_credentials();
    //cerr << "creds: " << creds << endl;
    wcout << "server: ClientCredentials:" << endl;
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

	obj = orb->resolve_initial_references
	    ("TransportSecurity::SecurityManager");
	TransportSecurity::SecurityManager_var ts_secman
	    = TransportSecurity::SecurityManager::_narrow(obj);
	assert(!CORBA::is_nil(ts_secman));
	TransportSecurity::CredentialsCurator_var ts_curator
	    = ts_secman->credentials_curator();

	obj = orb->resolve_initial_references("SL3TLS::ArgBuilderFactory");
	SL3AQArgs::ArgBuilderFactory_var fact
	    = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
	assert(!CORBA::is_nil(fact));
	SL3TLS::OpenSSLConfigArgBuilder_var builder
	    = SL3TLS::OpenSSLConfigArgBuilder::_narrow
	    (fact->create_arg_builder(SL3CM::CU_AcceptOnly));
	assert(!CORBA::is_nil(builder));
	CORBA::StringSeq sseq(0);
	builder->add_tcpip_acceptor_options(sseq, "localhost", 2345, 0, 0, FALSE);
	builder->add_tls_acceptor_options("ca_cert.pem", "s_cert.pem", "s_key.pem");
	builder->add_acceptor_verify_depth(1);
	SL3AQArgs::Argument_var tls_arg = builder->reap_args();
	TransportSecurity::CredentialsAcquirer_var ts_acquirer
	    = ts_curator->acquire_credentials(tls_arg);
	TransportSecurity::OwnCredentials_var ts_creds
	    = ts_acquirer->get_credentials(TRUE);

	obj = orb->resolve_initial_references("SL3CSI::ArgBuilderFactory");
	SL3AQArgs::ArgBuilderFactory_var csi_fact
	    = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
	assert(!CORBA::is_nil(csi_fact));
	SL3CSI::CSIArgBuilder_var csi_builder
	    = SL3CSI::CSIArgBuilder::_narrow
	    (csi_fact->create_arg_builder(SL3CM::CU_AcceptOnly));
	assert(!CORBA::is_nil(csi_builder));

	csi_builder->add_transport_credentials(ts_creds);
	csi_builder->add_password_processor(new PasswordProcessor_impl);
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
	orb->run();
    } catch (CORBA::UserException& ex) {
	wcout << "UserException caught: " << ex._repoid() << endl;
    } catch (CORBA::SystemException_catch& ex) {
	wcout << "SystemException caught: " << ex._repoid() << endl;
    } catch (...) {
	wcout << "... caught!" << endl;
    }
    return 0;
}
