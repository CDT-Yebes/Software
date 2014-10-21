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
    wcout << "client credentials: " << endl;
    CORBA::Object_var obj = orb->resolve_initial_references
	("TransportSecurity::SecurityCurrent");
    TransportSecurity::SecurityCurrent_var current
	= TransportSecurity::SecurityCurrent::_narrow(obj);
    assert(!CORBA::is_nil(current));
    TransportSecurity::ClientCredentials_ptr creds
	= current->client_credentials();
    MICOSL3Utils::PP::indent(&wcout);
    MICOSL3Utils::PP::print_client_credentials(&wcout, creds);
    wcout << endl;
}

int
main (int argc, char *argv[])
{
    orb = CORBA::ORB_init(argc, argv);

    CORBA::Object_var obj = orb->resolve_initial_references
	("TransportSecurity::SecurityManager");
    TransportSecurity::SecurityManager_var secman
	= TransportSecurity::SecurityManager::_narrow(obj);
    assert(!CORBA::is_nil(secman));
    TransportSecurity::CredentialsCurator_var curator
	= secman->credentials_curator();

    obj = orb->resolve_initial_references("SL3TCPIP::ArgBuilderFactory");
    SL3AQArgs::ArgBuilderFactory_var fact
	= SL3AQArgs::ArgBuilderFactory::_narrow(obj);
    assert(!CORBA::is_nil(fact));
    SL3TCPIP::TCPIPArgBuilder_var builder
	= SL3TCPIP::TCPIPArgBuilder::_narrow
	(fact->create_arg_builder(SL3CM::CU_AcceptOnly));
    assert(!CORBA::is_nil(builder));
    CORBA::StringSeq sseq(0);
    builder->add_tcpip_acceptor_options(sseq, "localhost", 2345, 0, 0, FALSE);
    SL3AQArgs::Argument_var arg = builder->reap_args();
    SL3AQArgs::ArgsHolder_var holder = SL3AQArgs::ArgsHolder::_narrow(arg);
    TransportSecurity::CredentialsAcquirer_ptr acquirer
	= curator->acquire_credentials(arg);
    TransportSecurity::OwnCredentials_ptr creds = acquirer->get_credentials(TRUE);
    CORBA::String_var id = creds->creds_id();
    TransportSecurity::OwnCredentials_ptr c2 = curator->get_own_credentials(id.in());
    MICOSL3Utils::PP::print_own_credentials(&wcout, c2);
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
    return 0;
}
