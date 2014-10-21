
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
    orb = CORBA::ORB_init (argc, argv);

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
