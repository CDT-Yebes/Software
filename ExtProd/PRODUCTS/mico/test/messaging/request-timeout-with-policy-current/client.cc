#include "hello.h"

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
            hello_->hello_with_timeout(3);
        }
        catch (CORBA::TIMEOUT& ex) {
            cout << "ERROR: TIMEOUT exception thrown" << endl;
        }
    }
private:
    HelloWorld_var hello_;
};

int
main (int argc, char *argv[])
{
  ORB_var orb = ORB_init (argc, argv);
  Object_var obj = orb->resolve_initial_references("PolicyCurrent");
  PolicyCurrent_var cur = PolicyCurrent::_narrow(obj);
  assert(!CORBA::is_nil(cur));
  // 2 seconds timeout (1 == 100 nsec)
  TimeBase::TimeT tout = 20000000ULL;
  Any value;
  value <<= tout;
  PolicyList pl(1);
  pl.length(1);
  pl[0] = orb->create_policy(Messaging::RELATIVE_RT_TIMEOUT_POLICY_TYPE, value);
  cur->set_policy_overrides(pl, SET_OVERRIDE);

  char pwd[256], uri[300];
  sprintf (uri, "file://%s/hello.ref", getcwd(pwd, 256));

  obj = orb->string_to_object (uri);
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
  ClientThread* thr = new ClientThread(hello);
  thr->start();
  thr->wait();
  delete thr;
  // verify that in this thread everything is running with timeout set
  try {
      hello->hello_with_timeout(3);
      cout << "ERROR: TIMEOUT exception not thrown" << endl;
  }
  catch (CORBA::TIMEOUT& ex) {
      cout << "caught expected TIMEOUT exception" << endl;
  }
  return 0;
}
