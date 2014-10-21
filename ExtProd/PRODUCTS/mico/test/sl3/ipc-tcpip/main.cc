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

#include <unistd.h>

using namespace std;

CORBA::ORB_ptr orb = CORBA::ORB::_nil();

class HelloWorld_impl
    : virtual public POA_HelloWorld
{
public:
    void hello();
};

void
HelloWorld_impl::hello()
{
    wcout << "main: Hello World" << endl;
    wcout << "main: client credentials: " << endl;
    CORBA::Object_var obj = orb->resolve_initial_references
	("TransportSecurity::SecurityCurrent");
    TransportSecurity::SecurityCurrent_var current
	= TransportSecurity::SecurityCurrent::_narrow(obj);
    assert(!CORBA::is_nil(current));
    TransportSecurity::ClientCredentials_ptr creds
	= current->client_credentials();
    //cerr << "creds: " << creds << endl;
    if (!CORBA::is_nil(creds)) {
	MICOSL3Utils::PP::indent(&wcout);
	MICOSL3Utils::PP::print_client_credentials(&wcout, creds);
	wcout << endl;
    }
    else {
	wcout << "ClientCredentials == NULL" << endl;
    }
}

int
main (int argc, char *argv[])
{
    try {
	orb = CORBA::ORB_init(argc, argv);

	CORBA::Object_var obj = orb->resolve_initial_references
	    ("TransportSecurity::SecurityManager");
	TransportSecurity::SecurityManager_var secman
	    = TransportSecurity::SecurityManager::_narrow(obj);
	assert(!CORBA::is_nil(secman));
	TransportSecurity::CredentialsCurator_var curator
	    = secman->credentials_curator();
	// IPC credentials
	obj = orb->resolve_initial_references("SL3IPC::ArgBuilderFactory");
	SL3AQArgs::ArgBuilderFactory_var fact
	    = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
	assert(!CORBA::is_nil(fact));
	SL3IPC::IPCArgBuilder_var builder
	    = SL3IPC::IPCArgBuilder::_narrow
	    (fact->create_arg_builder(SL3CM::CU_InitiateAndAccept));
	assert(!CORBA::is_nil(builder));
	SL3AQArgs::Argument_var arg = builder->reap_args();
	// TCPIP credentials -- we need them to succesfully generate IOR
	// for target object
	obj = orb->resolve_initial_references("SL3TCPIP::ArgBuilderFactory");
	SL3AQArgs::ArgBuilderFactory_var tcpip_fact
	    = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
	assert(!CORBA::is_nil(tcpip_fact));
	SL3TCPIP::TCPIPArgBuilder_var tcpip_builder
	    = SL3TCPIP::TCPIPArgBuilder::_narrow
//  	    (tcpip_fact->create_arg_builder(SL3CM::CU_AcceptOnly));
	    (tcpip_fact->create_arg_builder(SL3CM::CU_InitiateAndAccept));
	assert(!CORBA::is_nil(tcpip_builder));
        CORBA::StringSeq sseq(0);
        tcpip_builder->add_tcpip_acceptor_options(sseq, "localhost", 2350, 0, 0, FALSE);
  	tcpip_builder->add_tcpip_initiator_options("localhost", 12350, 12354, 0);
	SL3AQArgs::Argument_var arg2 = tcpip_builder->reap_args();

	wcout << "main: own credentials:" << endl;
	TransportSecurity::CredentialsAcquirer_var acquirer
	    = curator->acquire_credentials(arg);
	TransportSecurity::OwnCredentials_var creds = acquirer->get_credentials(TRUE);
	CORBA::String_var id = creds->creds_id();
	TransportSecurity::OwnCredentials_ptr c = curator->get_own_credentials(id.in());
	MICOSL3Utils::PP::print_own_credentials(&wcout, c);
	TransportSecurity::CredentialsAcquirer_var acquirer2
	    = curator->acquire_credentials(arg2);
	TransportSecurity::OwnCredentials_var creds2 = acquirer2->get_credentials(TRUE);
	CORBA::String_var id2 = creds2->creds_id();
	TransportSecurity::OwnCredentials_ptr c2 = curator->get_own_credentials(id2.in());
	wcout << endl;
	MICOSL3Utils::PP::print_own_credentials(&wcout, c2);

	CORBA::Object_var poaobj = orb->resolve_initial_references("RootPOA");
	PortableServer::POA_var poa = PortableServer::POA::_narrow(poaobj);
	PortableServer::POAManager_var mgr = poa->the_POAManager();

	HelloWorld_impl* servant = new HelloWorld_impl;
	PortableServer::ObjectId_var oid = poa->activate_object(servant);
	CORBA::Object_var ref = poa->id_to_reference(oid.in());
//  	ofstream of ("hello.ref");
	CORBA::String_var str = orb->object_to_string(ref);
//  	of << str.in() << endl;
//  	of.close();

	wcout << "main: Running." << endl;

	mgr->activate();
	//orb->run();
	// force marshalling and so PI upcalls
	CORBA::Object_var hello_obj = new CORBA::Object(new CORBA::IOR(str.in()));
	HelloWorld_var hello = HelloWorld::_narrow(hello_obj);
	assert(!CORBA::is_nil(hello));

	char pwd[256], uri[300];
	sprintf (uri, "file://%s/hello.ref", getcwd(pwd, 256));
	CORBA::Object_var remote_obj = orb->string_to_object (uri);
	HelloWorld_var remote_hello = HelloWorld::_narrow (remote_obj);
	assert(!CORBA::is_nil(remote_hello));

	TransportSecurity::TargetCredentials_var tcreds1 = secman->get_target_credentials(hello);
	wcout << endl;
	wcout << "Local Target credentials:" << endl;
	if (!CORBA::is_nil(tcreds1)) {
	    MICOSL3Utils::PP::print_target_credentials(&wcout, tcreds1);
	}
	else {
	    wcout << "TargetCredentials == NULL" << endl;
	}
	TransportSecurity::TargetCredentials_var tcreds2 = secman->get_target_credentials(remote_hello);
	wcout << endl;
	wcout << "Remote Target credentials:" << endl;
	if (!CORBA::is_nil(tcreds2)) {
	    MICOSL3Utils::PP::print_target_credentials(&wcout, tcreds2);
	}
	else {
	    wcout << "TargetCredentials == NULL" << endl;
	}
	hello->hello();
	remote_hello->hello();
    } catch (CORBA::UserException& ex) {
	wcout << "UserException caught: " << ex._repoid() << endl;
    } catch (CORBA::SystemException_catch& ex) {
	wcout << "SystemException caught: " << ex._repoid() << endl;
    } catch (...) {
	wcout << "... caught!" << endl;
    }
    return 0;
}
