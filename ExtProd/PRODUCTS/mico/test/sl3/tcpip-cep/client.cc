#include "hello.h"

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef _WINDOWS
#include <direct.h>
#endif

#include <mico/security/sl3utils.h>

using namespace SL3CM;

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

  obj = orb->resolve_initial_references("SL3TCPIP::ArgBuilderFactory");
  SL3AQArgs::ArgBuilderFactory_var fact
      = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
  assert(!CORBA::is_nil(fact));
  SL3TCPIP::TCPIPArgBuilder_var builder
      = SL3TCPIP::TCPIPArgBuilder::_narrow
      (fact->create_arg_builder(SL3CM::CU_InitiateOnly));
  assert(!CORBA::is_nil(builder));
  builder->add_tcpip_initiator_options("localhost", 6689, 6699, 0);
  SL3AQArgs::Argument_ptr arg = builder->reap_args();
  TransportSecurity::CredentialsAcquirer_ptr acquirer
      = curator->acquire_credentials(arg);
  TransportSecurity::OwnCredentials_ptr creds = acquirer->get_credentials(TRUE);
  CORBA::String_var id = creds->creds_id();
  //cerr << "id: " << id.in() << endl;
  TransportSecurity::OwnCredentials_ptr c2 = curator->get_own_credentials(id.in());
  //cerr << "c2id: " << c2->creds_id() << endl;
  MICOSL3Utils::PP::print_own_credentials(&wcout, c2);

  SL3TCPIP::TCPIPArgBuilder_var builder2
      = SL3TCPIP::TCPIPArgBuilder::_narrow
      (fact->create_arg_builder(SL3CM::CU_InitiateOnly));
  assert(!CORBA::is_nil(builder2));
  builder2->add_tcpip_initiator_options("localhost", 12345, 12354, 0);
  SL3AQArgs::Argument_ptr arg2 = builder2->reap_args();
  TransportSecurity::CredentialsAcquirer_ptr acquirer2
      = curator->acquire_credentials(arg2);
  TransportSecurity::OwnCredentials_ptr creds2 = acquirer2->get_credentials(FALSE);
  CORBA::String_var id2 = creds2->creds_id();
  //cerr << "id2: " << id2.in() << endl;
  TransportSecurity::OwnCredentials_ptr c3 = curator->get_own_credentials(id2.in());
  //cerr << "c3id: " << c3->creds_id() << endl;
  MICOSL3Utils::PP::print_own_credentials(&wcout, c3);
  TransportSecurity::OwnCredentialsList creds_list;
  creds_list.length(1);
  creds_list[0] = c3;
  TransportSecurity::ContextEstablishmentPolicy_ptr cep
      = secman->create_context_estab_policy
      (CD_Default, creds_list, FD_UseDefault, FD_UseDefault, FD_UseDefault,
       FD_UseDefault);
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

  CORBA::PolicyList policies;
  policies.length(1);
  policies[0] = cep;
  HelloWorld_var hello2 = HelloWorld::_narrow
      (hello->_set_policy_overrides(policies, CORBA::ADD_OVERRIDE));

  TransportSecurity::TargetCredentials_var tcreds1 = secman->get_target_credentials(hello);
  wcout << endl;
  wcout << "Target credentials1:" << endl;
  MICOSL3Utils::PP::print_target_credentials(&wcout, tcreds1);

  TransportSecurity::TargetCredentials_var tcreds2 = secman->get_target_credentials(hello2);
  wcout << endl;
  wcout << "Target credentials2:" << endl;
  MICOSL3Utils::PP::print_target_credentials(&wcout, tcreds2);

  hello->hello ();
  hello2->hello();
  tcreds1 = secman->get_target_credentials(hello);
  orb->destroy();
  return 0;
}
