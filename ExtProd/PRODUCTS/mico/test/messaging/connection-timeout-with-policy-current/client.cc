#include "hello.h"
#include <mico/os-misc.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef _WIN32
#include <direct.h>
#endif


using namespace CORBA;
using namespace std;

class ClientThread
    : virtual public MICOMT::Thread
{
public:
    ClientThread(HelloWorld_ptr hello)
        : hello_(HelloWorld::_duplicate(hello))
    {}

    void
    _run(void*)
    {
        // check that we do not timeout in this thread
        try {
            hello_->hello();
            cout << "(client thread) ERROR: exception not thrown" << endl;
        }
        catch (const CORBA::TIMEOUT& ex) {
            cout << "(client thread) ERROR: TIMEOUT exception thrown" << endl;
        }
        catch (const CORBA::COMM_FAILURE&) {
            cout << "(client thread) OK: COMM_FAILURE exception thrown" << endl;
        }
    }
private:
    HelloWorld_var hello_;
};

int
main (int argc, char *argv[])
{
  ORB_var orb = ORB_init (argc, argv);

  char pwd[256], uri[300];
  sprintf (uri, "file://%s/hello.ref", getcwd(pwd, 256));

  Object_var obj = orb->string_to_object (uri);
  HelloWorld_var hello = HelloWorld::_narrow (obj);

  if (is_nil (hello)) {
    cout << "oops: could not locate HelloWorld server" << endl;
    exit (1);
  }

  try {
      hello->hello();
      cout << "(main thread) ERROR: exception not thrown" << endl;
  }
  catch (const CORBA::TIMEOUT&) {
      cout << "(main thread) ERROR: TIMEOUT exception thrown" << endl;
  }
  catch (const CORBA::COMM_FAILURE&) {
      cout << "(main thread) OK: COMM_FAILURE exception caught" << endl;
  }

  obj = orb->resolve_initial_references("PolicyCurrent");
  PolicyCurrent_var cur = PolicyCurrent::_narrow(obj);
  assert(!CORBA::is_nil(cur));
  // 2 seconds timeout (1 == 100 nsec)
  TimeBase::TimeT tout = 20000000ULL;
  Any value;
  value <<= tout;
  PolicyList pl(1);
  pl.length(1);
  pl[0] = orb->create_policy(MICOPolicy::RELATIVE_CB_TIMEOUT_POLICY_TYPE, value);
  cur->set_policy_overrides(pl, ADD_OVERRIDE);

  ULong start_time = 0;
  ULong end_time = 0;
  try {
      start_time = OSMisc::timestamp();
      hello->hello();
      cout << "(main thread) ERROR: exception not thrown" << endl;
  }
  catch (CORBA::TIMEOUT& ex) {
      end_time = OSMisc::timestamp();
      cout << "(main thread) OK: TIMEOUT exception caught" << endl;
      ULong delta = end_time - start_time;
      if (delta >= 2000 && delta < 2200) {
          // let's tolerate up to 200ms slowdown
          cout << "(main thread) OK: 2 sec timeout" << endl;
      }
      else {
          cout << "(main thread) ERROR: wrong timeout value: " << delta / 1000 << endl;
      }
  }
  catch (const CORBA::TRANSIENT&) {
      end_time = OSMisc::timestamp();
      cout << "(main thread) ERROR: TRANSIENT exception caught after "
           << (end_time - start_time) / 1000
           << " seconds" << endl;
  }
  catch (const CORBA::COMM_FAILURE&) {
      end_time = OSMisc::timestamp();
      cout << "(main thread) ERROR: COMM_FAILURE exception caught after "
           << (end_time - start_time) / 1000
           << " seconds" << endl;
  }

  ClientThread* thr = new ClientThread(hello);
  thr->start();
  thr->wait();
  delete thr;

  // verify that in this thread everything is running with timeout set
  try {
      start_time = OSMisc::timestamp();
      hello->hello();
      cout << "(main thread) ERROR: exception not thrown" << endl;
  }
  catch (CORBA::TIMEOUT& ex) {
      end_time = OSMisc::timestamp();
      cout << "(main thread) OK: TIMEOUT exception caught" << endl;
      ULong delta = end_time - start_time;
      if (delta >= 2000 && delta < 2200) {
          // let's tolerate up to 200ms slowdown
          cout << "(main thread) OK: 2 sec timeout" << endl;
      }
      else {
          cout << "(main thread) ERROR: wrong timeout value: " << delta / 1000 << endl;
      }
  }
  catch (const CORBA::TRANSIENT&) {
      end_time = OSMisc::timestamp();
      cout << "(main thread) ERROR: TRANSIENT exception caught after "
           << (end_time - start_time) / 1000
           << " seconds" << endl;
  }
  catch (const CORBA::COMM_FAILURE&) {
      end_time = OSMisc::timestamp();
      cout << "(main thread) ERROR: COMM_FAILURE exception caught after "
           << (end_time - start_time) / 1000
           << " seconds" << endl;
  }

  return 0;
}
