#include "hello.h"

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef _WINDOWS
#include <direct.h>
#endif

#include <mico/security/sl3utils.h>

using namespace std;

int
main (int argc, char *argv[])
{
  CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);
  CORBA::Object_var obj = orb->resolve_initial_references
      ("TransportSecurity::SecurityManager");
  TransportSecurity::SecurityManager_var secman
      = TransportSecurity::SecurityManager::_narrow(obj);
  assert(!CORBA::is_nil(secman));

  /*
   * IOR is in hello.ref in the local directory
   */

  char pwd[256], uri[300];
  sprintf (uri, "file://%s/hello.ref", getcwd(pwd, 256));

  /*
   * Bind to Hello World server
   */

  CORBA::Object_var obj2 = orb->string_to_object (uri);
  HelloWorld_var hello = HelloWorld::_narrow (obj2);

  if (CORBA::is_nil (hello)) {
    printf ("oops: could not locate HelloWorld server\n");
    exit (1);
  }
  TransportSecurity::TargetCredentials_var tcreds1 = secman->get_target_credentials(hello);
  wcout << endl;
  wcout << "Target credentials:" << endl;
  MICOSL3Utils::PP::print_target_credentials(&wcout, tcreds1);
  hello->hello ();
  TransportSecurity::TargetCredentials_var tcreds2 = secman->get_target_credentials(hello);
  orb->destroy();
  return 0;
}
