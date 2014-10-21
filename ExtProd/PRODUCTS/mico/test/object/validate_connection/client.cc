#include "hello.h"

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef _WIN32
#include <direct.h>
#endif


using namespace std;


class HelloWorld_impl : virtual public POA_HelloWorld
{
public:
  void hello ();
};

void
HelloWorld_impl::hello ()
{
  cout << "Hello World" << endl;
}


int
main (int argc, char *argv[])
{
  CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);

  /*
   * IOR is in hello.ref in the local directory
   */

  char pwd[256], uri[300];
  sprintf (uri, "file://%s/hello.ref", getcwd(pwd, 256));

  /*
   * Bind to Hello World server
   */

  CORBA::Object_var obj = orb->string_to_object (uri);
  CORBA::PolicyList_var pl;
  cout << "client: validate connection..." << endl;
  CORBA::Boolean binded = FALSE;
  try {
      binded = obj->_validate_connection(pl);
      assert(binded);
      cout << "....OK!" << endl;
  }
  catch (const CORBA::Exception& ex) {
      cout << "....ERROR: " << ex._repoid() << " exception caught!" << endl;
      assert(0);
  }
  HelloWorld_var hello = HelloWorld::_narrow (obj);

  if (CORBA::is_nil (hello)) {
    cout << "oops: could not locate HelloWorld server" << endl;
    exit (1);
  }

  hello->hello ();
  sleep(3);
  // here, server should be already down
  // but our connection does not know it
  // we will receice CORBA::COMM_FAILURE
  // on next invocation though
  cout << "client: validate connection after server shutdown..." << endl;
  try {
      binded = hello->_validate_connection(pl);
      cout << "....ERROR: does not throw COMM_FAILURE!" << endl;
      assert(0);
  }
  catch (const CORBA::COMM_FAILURE& ex) {
      cout << "....OK: " << ex._repoid() << " exception caught!" << endl;
  }
  cout << "client: validate connection of collocated object..." << endl;
  // collocated server side testing
  
  CORBA::Object_var poaobj = orb->resolve_initial_references ("RootPOA");
  PortableServer::POA_var poa = PortableServer::POA::_narrow (poaobj);
  PortableServer::POAManager_var mgr = poa->the_POAManager();
  HelloWorld_impl* srv = new HelloWorld_impl;
  HelloWorld_var collocated_hello = srv->_this();
  binded = FALSE;
  try {
      binded = collocated_hello->_validate_connection(pl);
      assert(binded);
      cout << "....OK!" << endl;
  }
  catch (const CORBA::Exception& ex) {
      cout << "....ERROR: " << ex._repoid() << " exception caught!" << endl;
      assert(0);
  }
  return 0;
}
