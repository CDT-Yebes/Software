#include "hello.h"

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef _WINDOWS
#include <direct.h>
#endif

#include <mico/security/sl3utils.h>
#include <mico/util.h>

using namespace SL3CM;

using namespace std;

int
main (int argc, char *argv[])
{
    CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);
    CORBA::Object_var obj = orb->resolve_initial_references
	("SecurityLevel3::SecurityManager");
    SecurityLevel3::SecurityManager_var secman
	= SecurityLevel3::SecurityManager::_narrow(obj);
    assert(!CORBA::is_nil(secman));
    SecurityLevel3::CredentialsCurator_var curator
	= secman->credentials_curator();

    // first of all we need to acquire transport credentials
    obj = orb->resolve_initial_references("SL3TCPIP::ArgBuilderFactory");
    SL3AQArgs::ArgBuilderFactory_var fact
	= SL3AQArgs::ArgBuilderFactory::_narrow(obj);
    assert(!CORBA::is_nil(fact));
    SL3TCPIP::TCPIPArgBuilder_var ts_builder
	= SL3TCPIP::TCPIPArgBuilder::_narrow
	(fact->create_arg_builder(SL3CM::CU_InitiateOnly));
    assert(!CORBA::is_nil(ts_builder));
    SL3AQArgs::Argument_var ts_args = ts_builder->reap_args();
    obj = orb->resolve_initial_references
	("TransportSecurity::SecurityManager");
    TransportSecurity::SecurityManager_var ts_secman
	= TransportSecurity::SecurityManager::_narrow(obj);
    assert(!CORBA::is_nil(ts_secman));
    TransportSecurity::CredentialsCurator_var ts_curator
	= ts_secman->credentials_curator();
    TransportSecurity::CredentialsAcquirer_ptr ts_acquirer
	= ts_curator->acquire_credentials(ts_args);
    TransportSecurity::OwnCredentials_ptr ts_creds = ts_acquirer->get_credentials(TRUE);

    obj = orb->resolve_initial_references("SL3CSI::ArgBuilderFactory");
    SL3AQArgs::ArgBuilderFactory_var csi_fact
	= SL3AQArgs::ArgBuilderFactory::_narrow(obj);
    assert(!CORBA::is_nil(csi_fact));
    SL3CSI::CSIArgBuilder_var csi_builder
	= SL3CSI::CSIArgBuilder::_narrow
	(csi_fact->create_arg_builder(SL3CM::CU_InitiateOnly));
    assert(!CORBA::is_nil(csi_builder));
    csi_builder->add_transport_credentials(ts_creds);
    SL3PM::PrincipalName qp_name1;
    qp_name1.the_type = (const char*)SL3PM::NT_StringName;
    qp_name1.the_name.length(1);
    qp_name1.the_name[0] = L"ras_identity";
    csi_builder->add_named_quoted_principal(qp_name1);
    SL3AQArgs::Argument_var args = csi_builder->reap_args();
    SecurityLevel3::CredentialsAcquirer_var acquirer
	= curator->acquire_credentials(args);
    SecurityLevel3::OwnCredentials_var creds = acquirer->get_credentials(TRUE);
    //cerr << "creds id: " << creds->creds_id() << endl;
    wcout << "client: OwnCredentials:" << endl;
    MICOSL3Utils::PP::print_own_credentials(&wcout, creds);

    SL3CSI::CSIArgBuilder_var csi_builder2
	= SL3CSI::CSIArgBuilder::_narrow
	(csi_fact->create_arg_builder(SL3CM::CU_InitiateOnly));
    assert(!CORBA::is_nil(csi_builder2));
    csi_builder2->add_transport_credentials(ts_creds);
    SL3PM::PrincipalName qp_name2;
    qp_name2.the_type = (const char*)SL3PM::NT_StringName;
    qp_name2.the_name.length(1);
    qp_name2.the_name[0] = L"karel_identity";
    csi_builder2->add_named_quoted_principal(qp_name2);
    SL3AQArgs::Argument_var args2 = csi_builder2->reap_args();
    SecurityLevel3::CredentialsAcquirer_var acquirer2
	= curator->acquire_credentials(args2);
    SecurityLevel3::OwnCredentials_var creds2 = acquirer2->get_credentials(FALSE);
    //cerr << "creds2 id: " << creds2->creds_id() << endl;
    wcout << "client: OwnCredentials:" << endl;
    MICOSL3Utils::PP::print_own_credentials(&wcout, creds2);

    SecurityLevel3::OwnCredentialsList creds_list;
    creds_list.length(1);
    creds_list[0] = creds2;
    SecurityLevel3::ContextEstablishmentPolicy_ptr cep
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
    SecurityLevel3::TargetCredentials_var tcreds1 = secman->get_target_credentials(hello);
    assert(!CORBA::is_nil(tcreds1));
    wcout << "client: TargetCredentials1:" << endl;
    MICOSL3Utils::PP::print_target_credentials(&wcout, tcreds1);

    CORBA::PolicyList policies;
    policies.length(1);
    policies[0] = cep;
    HelloWorld_var hello2 = HelloWorld::_narrow
	(hello->_set_policy_overrides(policies, CORBA::ADD_OVERRIDE));

    SecurityLevel3::TargetCredentials_var tcreds2 = secman->get_target_credentials(hello2);
    assert(!CORBA::is_nil(tcreds2));
    wcout << "client: TargetCredentials2:" << endl;
    MICOSL3Utils::PP::print_target_credentials(&wcout, tcreds2);

    try {
	hello->hello ();
	hello2->hello();
    } catch (CORBA::NO_PERMISSION& ex) {
	cerr << "client: caught NO_PERMISSION" << endl;
    }
    //SecurityLevel3::TargetCredentials_var tcreds2 = secman->get_target_credentials(hello);
    //MICOSL3Utils::PP::print_target_credentials(&wcout, tcreds1);
    orb->destroy();
    return 0;
}


