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
CORBA::Boolean running = TRUE;
CORBA::Long ctx = 0;

class HelloWorld_impl
    : virtual public POA_HelloWorld
{
public:
    void hello();
};

void
HelloWorld_impl::hello()
{
    ctx++;
    if (ctx == 1) {
	running = FALSE;
    }
    wcout << "Hello World" << endl;
//      wcout << "client credentials: " << endl;
//      CORBA::Object_var obj = orb->resolve_initial_references
//  	("TransportSecurity::SecurityCurrent");
//      TransportSecurity::SecurityCurrent_var current
//  	= TransportSecurity::SecurityCurrent::_narrow(obj);
//      assert(!CORBA::is_nil(current));
//      TransportSecurity::ClientCredentials_ptr creds
//  	= current->client_credentials();
//      //cerr << "creds: " << creds << endl;
//      MICOSL3Utils::PP::indent(&wcout);
//      MICOSL3Utils::PP::print_client_credentials(&wcout, creds);
//      wcout << endl;
}

int
main (int argc, char *argv[])
{
    wcout << "server: started" << endl;
    try {
	orb = CORBA::ORB_init(argc, argv);

	CORBA::Object_var obj = orb->resolve_initial_references
	    ("TransportSecurity::SecurityManager");
	TransportSecurity::SecurityManager_var secman
	    = TransportSecurity::SecurityManager::_narrow(obj);
	assert(!CORBA::is_nil(secman));
	TransportSecurity::CredentialsCurator_var curator
	    = secman->credentials_curator();

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
	SL3AQArgs::Argument_var arg = builder->reap_args();
	TransportSecurity::CredentialsAcquirer_ptr acquirer
	    = curator->acquire_credentials(arg);
	TransportSecurity::OwnCredentials_ptr creds = acquirer->get_credentials(TRUE);
	CORBA::String_var id = creds->creds_id();
//  	TransportSecurity::OwnCredentials_ptr c2 = curator->get_own_credentials(id.in());
//  	wcout << endl;
//  	MICOSL3Utils::PP::print_own_credentials(&wcout, c2);
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

	wcout << "server: running." << endl;

	mgr->activate();
	while (running) {
	    orb->perform_work();
	}
	wcout << "server: finished" << endl;
    } catch (CORBA::UserException& ex) {
	wcout << "UserException caught: " << ex._repoid() << endl;
    } catch (CORBA::SystemException_catch& ex) {
	wcout << "SystemException caught: " << ex._repoid() << endl;
    } catch (...) {
	wcout << "... caught!" << endl;
    }
    return 0;
}
