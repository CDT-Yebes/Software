#include "hello.h"

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef _WIN32
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
  TransportSecurity::CredentialsCurator_var curator
      = secman->credentials_curator();

  obj = orb->resolve_initial_references("SL3TLS::ArgBuilderFactory");
  SL3AQArgs::ArgBuilderFactory_var fact
      = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
  assert(!CORBA::is_nil(fact));
  SL3TLS::OpenSSLConfigArgBuilder_var builder
      = SL3TLS::OpenSSLConfigArgBuilder::_narrow
      (fact->create_arg_builder(SL3CM::CU_InitiateOnly));
  assert(!CORBA::is_nil(builder));
  builder->add_tcpip_initiator_options("localhost", 6789, 6799, 0);
  builder->add_tls_anonymous_initiator_options("ca_cert.pem");
  builder->add_initiator_verify_depth(1);
  SL3AQArgs::Argument_var arg = builder->reap_args();
  TransportSecurity::CredentialsAcquirer_var acquirer
      = curator->acquire_credentials(arg);
  TransportSecurity::OwnCredentials_ptr creds = acquirer->get_credentials(TRUE);
  CORBA::String_var id = creds->creds_id();
  TransportSecurity::OwnCredentials_ptr c2 = curator->get_own_credentials(id.in());
  MICOSL3Utils::PP::print_own_credentials(&wcout, c2);

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
