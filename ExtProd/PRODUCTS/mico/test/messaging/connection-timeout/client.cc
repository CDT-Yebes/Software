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
  // 2 seconds timeout (1 == 100 nsec)
  TimeBase::TimeT tout = 20000000ULL;
  Any value;
  value <<= tout;
  PolicyList pl;
  pl.length(1);
  pl[0] = orb->create_policy(MICOPolicy::RELATIVE_CB_TIMEOUT_POLICY_TYPE, value);
  try {
      hello->hello();
      cout << "ERROR: exception not thrown" << endl;
  }
  catch (const CORBA::COMM_FAILURE&) {
      cout << "OK: COMM_FAILURE exception caught" << endl;
  }
  obj = hello->_set_policy_overrides(pl, ADD_OVERRIDE);
  HelloWorld_var hello_tout = HelloWorld::_narrow(obj);
  assert(!is_nil(hello_tout));
  ULong start_time = 0;
  ULong end_time = 0;
  try {
      start_time = OSMisc::timestamp();
      hello_tout->hello();
      cout << "ERROR: exception not thrown" << endl;
  }
  catch (CORBA::TIMEOUT& ex) {
      end_time = OSMisc::timestamp();
      cout << "OK: TIMEOUT exception caught" << endl;
      ULong delta = end_time - start_time;
      if (delta >= 2000 && delta < 2200) {
          // let's tolerate up to 200ms slowdown
          cout << "OK: 2 sec timeout" << endl;
      }
      else {
          cout << "ERROR: wrong timeout value: " << delta / 1000 << endl;
      }
  }
  catch (const CORBA::TRANSIENT&) {
      cout << "ERROR: TRANSIENT exception caught" << endl;
  }
  catch (const CORBA::COMM_FAILURE&) {
      cout << "ERROR: COMM_FAILURE exception caught" << endl;
  }
  return 0;
}
