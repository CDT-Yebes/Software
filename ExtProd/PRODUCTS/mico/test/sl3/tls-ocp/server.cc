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
    TransportSecurity::ClientCredentials_var creds
	= current->client_credentials();
    //cerr << "creds: " << creds << endl;
    MICOSL3Utils::PP::indent(&wcout);
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
	builder->add_tcpip_acceptor_options(sseq, "localhost", 2563, 0, 0, FALSE);
	builder->add_tls_acceptor_options("ca_cert.pem", "s_cert.pem", "s_key.pem");
	builder->add_acceptor_verify_depth(1);
	SL3AQArgs::Argument_var arg = builder->reap_args();
	TransportSecurity::CredentialsAcquirer_var acquirer
	    = curator->acquire_credentials(arg);
	TransportSecurity::OwnCredentials_var creds = acquirer->get_credentials(TRUE);

	builder = SL3TLS::OpenSSLConfigArgBuilder::_narrow
	    (fact->create_arg_builder(SL3CM::CU_AcceptOnly));
	assert(!CORBA::is_nil(builder));
	builder->add_tcpip_acceptor_options(sseq, "127.0.0.1", 4451, 0, 0, FALSE);
	builder->add_tls_acceptor_options("ca_cert.pem", "s_cert.pem", "s_key.pem");
	builder->add_acceptor_verify_depth(1);
	arg = builder->reap_args();
	acquirer = curator->acquire_credentials(arg);
	creds = acquirer->get_credentials(TRUE);

	builder = SL3TLS::OpenSSLConfigArgBuilder::_narrow
	    (fact->create_arg_builder(SL3CM::CU_AcceptOnly));
	assert(!CORBA::is_nil(builder));
	builder->add_tcpip_acceptor_options(sseq, "localhost", 1000, 2000, 0, FALSE);
	builder->add_tls_acceptor_options("ca_cert.pem", "s_cert.pem", "s_key.pem");
	builder->add_acceptor_verify_depth(1);
	arg = builder->reap_args();
	acquirer = curator->acquire_credentials(arg);
	creds = acquirer->get_credentials(TRUE);

        TransportSecurity::OwnCredentialsList_var creds_list = curator->default_creds_list();
	wcout << endl;
        for (CORBA::ULong i = 0; i < creds_list->length(); i++) {
            wcout << i << ". creds:" << endl;
            MICOSL3Utils::PP::print_own_credentials(&wcout, creds_list[i]);
        }

        TransportSecurity::OwnCredentialsList_var ocp_list
            = new TransportSecurity::OwnCredentialsList;
        ocp_list->length(1);
        ocp_list[0u] = creds_list[1u];

        TransportSecurity::ObjectCredentialsPolicy_var ocp
            = secman->create_object_creds_policy(ocp_list);

	CORBA::Object_var poaobj = orb->resolve_initial_references("RootPOA");
	PortableServer::POA_var poa = PortableServer::POA::_narrow(poaobj);
	PortableServer::POAManager_var mgr = poa->the_POAManager();

        CORBA::PolicyList policies;
        policies.length(1);
        policies[0] = CORBA::Policy::_duplicate(ocp);
        PortableServer::POA_var poa2 = poa->create_POA("HelloPOA", mgr, policies);

	HelloWorld_impl* servant = new HelloWorld_impl;
	PortableServer::ObjectId_var oid = poa2->activate_object(servant);
	CORBA::Object_var ref = poa2->id_to_reference(oid.in());
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
