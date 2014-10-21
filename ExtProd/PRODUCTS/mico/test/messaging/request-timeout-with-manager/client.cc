#include "hello.h"

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
  DomainManager_var dommgr;
  orb->get_default_domain_manager(dommgr);
  assert(!is_nil(dommgr));
  // 2 seconds timeout (1 == 100 nsec)
  TimeBase::TimeT tout = 20000000ULL;
  Any value;
  value <<= tout;
  Policy_var timeout_policy = orb->create_policy(Messaging::RELATIVE_RT_TIMEOUT_POLICY_TYPE, value);
  dommgr->set_domain_policy(timeout_policy);

  char pwd[256], uri[300];
  sprintf (uri, "file://%s/hello.ref", getcwd(pwd, 256));

  Object_var obj = orb->string_to_object (uri);
  HelloWorld_var hello = HelloWorld::_narrow (obj);

  if (is_nil (hello)) {
    cout << "oops: could not locate HelloWorld server" << endl;
    exit (1);
  }
  hello->hello();
  try {
      hello->hello_with_timeout(1);
  }
  catch (CORBA::TIMEOUT& ex) {
      cout << "ERROR: TIMEOUT exception thrown too fast" << endl;
  }
  try {
      hello->hello_with_timeout(3);
      cout << "ERROR: TIMEOUT exception not thrown" << endl;
  }
  catch (CORBA::TIMEOUT& ex) {
      cout << "caught expected TIMEOUT exception" << endl;
  }
  return 0;
}
