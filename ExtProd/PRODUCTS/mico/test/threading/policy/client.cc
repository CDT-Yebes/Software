#include "hello.h"
#include <mico/impl.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef _WIN32
#include <direct.h>
#endif


using namespace CORBA;
using namespace MICOMT;
using namespace std;

int
main (int argc, char *argv[])
{
    assert(argc == 4);
    CORBA::ULong cl = 0;
    CORBA::ULong rl = 0;
    ClientConcurrencyModel model;
    string strcm = argv[1];
    if (strcm == "threaded")
        model = MICOMT::THREADED;
    else if (strcm == "blocking-threaded")
        model = MICOMT::BLOCKING_THREADED;
    else if (strcm == "reactive")
        model = MICOMT::REACTIVE;
    else
        assert(0);
    rl = atoi(argv[2]);
    cl = atoi(argv[3]);

    CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);

    Any value;
    value <<= model;
    PolicyList pl;
    pl.length(3);
    pl[0] = orb->create_policy(MICOMT::CLIENT_CONCURRENCY_MODEL_POLICY_TYPE, value);
    value <<= rl;
    pl[1] = orb->create_policy(MICOMT::REQUEST_LIMIT_POLICY_TYPE, value);
    value <<= cl;
    pl[2] = orb->create_policy(MICOMT::CONNECTION_LIMIT_POLICY_TYPE, value);

    Object_var obj = orb->resolve_initial_references("ORBPolicyManager");
    PolicyManager_var pmgr = PolicyManager::_narrow(obj);
    assert(!CORBA::is_nil(pmgr));
    pmgr->set_policy_overrides(pl, SET_OVERRIDE);

    char pwd[256], uri[300];
    sprintf (uri, "file://%s/hello.ref", getcwd(pwd, 256));

    obj = orb->string_to_object (uri);
    HelloWorld_var hello = HelloWorld::_narrow (obj);

    if (CORBA::is_nil (hello)) {
        cout << "oops: could not locate HelloWorld server" << endl;
        exit (1);
    }

    hello->hello ();
    cout << "client: hello operation invoked."
         << " I'm running with ";
    if (MICO::MTManager::threaded_client())
        cout << "threaded client";
    else if (MICO::MTManager::blocking_threaded_client())
        cout << "blocking threaded client";
    else if (MICO::MTManager::reactive_client())
        cout << "reactive client";
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
    return 0;
}
