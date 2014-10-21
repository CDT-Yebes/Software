#include "hello.h"
#include <coss/CosNaming.h>

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
  TransportSecurity::CredentialsCurator_var curator
      = secman->credentials_curator();

  obj = orb->resolve_initial_references("SL3TCPIP::ArgBuilderFactory");
  SL3AQArgs::ArgBuilderFactory_var tcpip_fact
      = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
  assert(!CORBA::is_nil(tcpip_fact));
  SL3TCPIP::TCPIPArgBuilder_var tcpip_builder
      = SL3TCPIP::TCPIPArgBuilder::_narrow
      (tcpip_fact->create_arg_builder(SL3CM::CU_InitiateOnly));
  assert(!CORBA::is_nil(tcpip_builder));
  tcpip_builder->add_tcpip_initiator_options("localhost", 6619, 6629, 0);
  SL3AQArgs::Argument_var arg = tcpip_builder->reap_args();
  TransportSecurity::CredentialsAcquirer_var acquirer
      = curator->acquire_credentials(arg);
  TransportSecurity::OwnCredentials_var tcpip_creds = acquirer->get_credentials(TRUE);
  MICOSL3Utils::PP::print_own_credentials(&wcout, tcpip_creds);

  obj = orb->resolve_initial_references("SL3TLS::ArgBuilderFactory");
  SL3AQArgs::ArgBuilderFactory_var fact
      = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
  assert(!CORBA::is_nil(fact));
  SL3TLS::OpenSSLConfigArgBuilder_var builder
      = SL3TLS::OpenSSLConfigArgBuilder::_narrow
      (fact->create_arg_builder(SL3CM::CU_InitiateOnly));
  assert(!CORBA::is_nil(builder));
  try {
      CORBA::StringSeq sseq(0);
      builder->add_tcpip_acceptor_options(sseq, "localhost", 2345, 0, 0, FALSE);
      assert(0);
  } catch (CORBA::BAD_PARAM& ex) {
      // ok
      wcout << "caught CORBA::BAD_PARAM which is ok" << endl;
  }
  builder->add_tcpip_initiator_options("localhost", 6799, 6819, 0);
  //builder->addSupportCSIv1(FALSE);
  //builder->addSupportCSIv2(TRUE);
  builder->add_tls_initiator_options("ca_cert.pem", "c_cert.pem", "c_key.pem");
  builder->add_initiator_verify_depth(1);
  SL3AQArgs::Argument_var arg2 = builder->reap_args();
  try {
      builder->reap_args();
      assert(0);
  } catch (CORBA::BAD_INV_ORDER& ex) {
      // ok since builder is destroyed
      wcout << "catch CORBA::BAD_INV_ORDER correctly" << endl;
  }
  acquirer = curator->acquire_credentials(arg2);
  TransportSecurity::OwnCredentials_ptr creds = acquirer->get_credentials(TRUE);
  CORBA::String_var id = creds->creds_id();
  TransportSecurity::OwnCredentials_ptr c2 = curator->get_own_credentials(id.in());
  MICOSL3Utils::PP::print_own_credentials(&wcout, c2);

  /*
   * IOR is in hello.ref in the local directory
   */

//    char pwd[256], uri[300];
//    sprintf (uri, "file://%s/hello.ref", getcwd(pwd, 256));

  CORBA::Object_var obj2;

  CORBA::Object_var nsobj = orb->resolve_initial_references
      ("NameService");
  CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow(nsobj);
  if (CORBA::is_nil (nc)) {
      wcout << "oops, I cannot access the Naming Service!" << endl;
      exit (1);
  }
  TransportSecurity::TargetCredentials_var tcreds_nc = secman->get_target_credentials(nc);
  wcout << endl;
  wcout << "Target credentials of Naming Context:" << endl;
  MICOSL3Utils::PP::print_target_credentials(&wcout, tcreds_nc);
  wcout << endl;
  CosNaming::Name name;
  name.length (1);
  name[0].id = CORBA::string_dup ("HelloServer");
  name[0].kind = CORBA::string_dup ("");

  wcout << "Looking up HelloServer ... " << flush;
  try {
      obj2 = nc->resolve (name);
  }
  catch (CosNaming::NamingContext::NotFound &exc) {
      wcout << "NotFound exception." << endl;
      exit (1);
  }
  catch (CosNaming::NamingContext::CannotProceed &exc) {
      wcout << "CannotProceed exception." << endl;
      exit (1);
  }
  catch (CosNaming::NamingContext::InvalidName &exc) {
      wcout << "InvalidName exception." << endl;
      exit (1);
  }
  wcout << "done." << endl;

  HelloWorld_var hello = HelloWorld::_narrow (obj2);

  if (CORBA::is_nil (hello)) {
      wcout << "oops: could not locate HelloWorld server" << endl;
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
