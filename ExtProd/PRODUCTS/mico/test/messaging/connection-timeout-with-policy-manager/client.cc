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

  CORBA::Object_var obj = orb->string_to_object (uri);
  HelloWorld_var hello = HelloWorld::_narrow (obj);

  if (is_nil (hello)) {
    cout << "oops: could not locate HelloWorld server" << endl;
    exit (1);
  }

  try {
      hello->hello();
      cout << "ERROR: exception not thrown" << endl;
  }
  catch (const CORBA::TIMEOUT&) {
      cout << "ERROR: TIMEOUT exception thrown" << endl;
  }
  catch (const CORBA::COMM_FAILURE&) {
      cout << "OK: COMM_FAILURE exception caught" << endl;
  }

  obj = orb->resolve_initial_references("ORBPolicyManager");
  PolicyManager_var mgr = PolicyManager::_narrow(obj);
  assert(!CORBA::is_nil(mgr));
  // 2 seconds timeout (1 == 100 nsec)
  TimeBase::TimeT tout = 20000000ULL;
  Any value;
  value <<= tout;
  PolicyList pl(1);
  pl.length(1);
  pl[0] = orb->create_policy(MICOPolicy::RELATIVE_CB_TIMEOUT_POLICY_TYPE, value);
  mgr->set_policy_overrides(pl, ADD_OVERRIDE);

  ULong start_time = 0;
  ULong end_time = 0;
  try {
      start_time = OSMisc::timestamp();
      hello->hello();
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
      end_time = OSMisc::timestamp();
      cout << "ERROR: TRANSIENT exception caught after "
           << (end_time - start_time) / 1000
           << " seconds" << endl;
  }
  catch (const CORBA::COMM_FAILURE&) {
      end_time = OSMisc::timestamp();
      cout << "ERROR: COMM_FAILURE exception caught after "
           << (end_time - start_time) / 1000
           << " seconds" << endl;
  }

  return 0;
}
