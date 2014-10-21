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
    ORB_var orb = ORB_init (argc, argv);

    char pwd[256], uri[300];
    sprintf (uri, "file://%s/hello.ref", getcwd(pwd, 256));

    Object_var obj = orb->string_to_object (uri);
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
