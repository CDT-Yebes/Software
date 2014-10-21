
#include "hello.h"
#include <mico/impl.h>

#ifdef HAVE_ANSI_CPLUSPLUS_HEADERS
#include <fstream>
#else
#include <fstream.h>
#endif


using namespace CORBA;
using namespace MICOMT;
using namespace std;


ORB_var orb = ORB::_nil();

class HelloWorld_impl : virtual public POA_HelloWorld
{
public:
    void
    hello();
};

void
HelloWorld_impl::hello ()
{
    cout << "server: Hello World!"
         << " I'm running with ";
    if (MICO::MTManager::thread_pool())
        cout << "thread pool";
    else if (MICO::MTManager::thread_per_connection())
        cout << "thread per connection";
    else
        assert(0);
    cout << " concurrency model" << endl
         << "        maximum number of requests processed in parallel is "
         << orb->resource_manager().request_limit() << endl
         << "        maximum number of connections is ";
    if (orb->resource_manager().connection_limit() == 0)
        cout << "unlimited";
    else
        cout << orb->resource_manager().connection_limit();
    cout << endl;
}

int
main (int argc, char *argv[])
{
    assert(argc == 4);
    CORBA::ULong cl = 0;
    CORBA::ULong rl = 0;
    ServerConcurrencyModel model;
    string strcm = argv[1];
    if (strcm == "thread-pool")
        model = MICOMT::THREAD_POOL;
    else if (strcm == "thread-per-connection")
        model = MICOMT::THREAD_PER_CONNECTION;
    else
        assert(0);
    rl = atoi(argv[2]);
    cl = atoi(argv[3]);

    orb = CORBA::ORB_init (argc, argv);

    Any value;
    value <<= model;
    PolicyList pl;
    pl.length(3);
    pl[0] = orb->create_policy(MICOMT::SERVER_CONCURRENCY_MODEL_POLICY_TYPE, value);
    value <<= rl;
    pl[1] = orb->create_policy(MICOMT::REQUEST_LIMIT_POLICY_TYPE, value);
    value <<= cl;
    pl[2] = orb->create_policy(MICOMT::CONNECTION_LIMIT_POLICY_TYPE, value);

    Object_var obj = orb->resolve_initial_references("ORBPolicyManager");
    PolicyManager_var pmgr = PolicyManager::_narrow(obj);
    assert(!CORBA::is_nil(pmgr));
    pmgr->set_policy_overrides(pl, SET_OVERRIDE);

    CORBA::Object_var poaobj = orb->resolve_initial_references ("RootPOA");
    PortableServer::POA_var poa = PortableServer::POA::_narrow (poaobj);
    PortableServer::POAManager_var mgr = poa->the_POAManager();

    HelloWorld_impl * hello = new HelloWorld_impl;

    PortableServer::ObjectId_var oid = poa->activate_object (hello);

    ofstream of ("hello.ref");
    CORBA::Object_var ref = poa->id_to_reference (oid.in());
    CORBA::String_var str = orb->object_to_string (ref.in());
    of << str.in() << endl;
    of.close ();

    cout << "Running." << endl;

    mgr->activate ();
    orb->run();

    poa->destroy (TRUE, TRUE);
    delete hello;

    return 0;
}
