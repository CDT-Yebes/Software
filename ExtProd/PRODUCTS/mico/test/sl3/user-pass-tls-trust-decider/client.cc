#include "hello.h"

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef _WINDOWS
#include <direct.h>
#endif

#include <mico/security/sl3utils.h>

using namespace std;

class PasswordGenerator_impl
    : virtual public UserPassword::PasswordGenerator,
      virtual public CORBA::LocalObject
{
public:
    virtual SL3PM::PrincipalName*
    client_authentication_principal();

    virtual UserPassword::ErrorCode
    generate_password
    (const SL3PM::PrincipalName& target,
     CORBA::WString_out username,
     CORBA::WString_out password);
};

SL3PM::PrincipalName*
PasswordGenerator_impl::client_authentication_principal()
{
    //cerr << "PasswordGenerator_impl::client_authentication_principal()" << endl;
    SL3PM::PrincipalName* result = new SL3PM::PrincipalName;
    result->the_type = (const char*)SL3PM::NT_StringName;
    result->the_name.length(1);
    result->the_name[0] = L"karel";
    return result;
}

UserPassword::ErrorCode
PasswordGenerator_impl::generate_password
(const SL3PM::PrincipalName& target,
 CORBA::WString_out username,
 CORBA::WString_out password)
{
    //cerr << "PasswordGenerator_impl::generate_password" << endl;
    wstring realm = L"@objectsecurity.com";
    if (strcmp(SL3PM::NT_StringName, target.the_type) == 0) {
	if (realm == target.the_name[0].in()) {
	    username = L"karel";
	    password = L"cobalt";
	    //password = L"bad_passwd";
	    return UserPassword::EC_Success;
	}
    }
    return UserPassword::EC_BadTarget;
}

class TrustDecider
    : virtual public Trust::LocalTrustInServerDecider,
      virtual public CORBA::LocalObject
{
public:
    TrustDecider(CORBA::Boolean allow)
	: allow_(allow)
    {}

    virtual CORBA::Boolean
    is_trusted
    (SL3PM::Principal* server_principal,
     const SL3PM::StatementList& supporting_statements,
     CORBA::Boolean confidentiality,
     CORBA::Boolean integrity,
     SL3CM::CredsDirective creds_directive);
private:
    CORBA::Boolean allow_;
};

CORBA::Boolean
TrustDecider::is_trusted
(SL3PM::Principal* server_principal,
 const SL3PM::StatementList& supporting_statements,
 CORBA::Boolean confidentiality,
 CORBA::Boolean integrity,
 SL3CM::CredsDirective creds_directive)
{
    wcout << "TrustDecider::is_trusted?" << endl;
    MICOSL3Utils::PP::print_principal(&wcout, server_principal);
    //SL3PM::StatementList_var stats = new SL3PM::StatementList(supporting_statements);
    //MICOSL3Utils::PP::print_statement_list(&wcout, stats);
    if (confidentiality)
	wcout << "confidentiality == TRUE" << endl;
    else
	wcout << "confidentiality == FALSE" << endl;
    if (integrity)
	wcout << "integrity == TRUE" << endl;
    else
	wcout << "integrity == FALSE" << endl;
    if (allow_)
	wcout << "will return TRUE" << endl;
    else
	wcout << "will return FALSE" << endl;
    return allow_;
}

int
main (int argc, char *argv[])
{
    CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);
    assert(argc == 2);
    string param = argv[1];
    CORBA::Boolean trust = FALSE;
    if (param == "trust") {
	trust = TRUE;
    }
    if (param == "not-trust") {
	trust = FALSE;
    }
    CORBA::Object_var obj = orb->resolve_initial_references
	("SecurityLevel3::SecurityManager");
    SecurityLevel3::SecurityManager_var secman
	= SecurityLevel3::SecurityManager::_narrow(obj);
    assert(!CORBA::is_nil(secman));
    SecurityLevel3::CredentialsCurator_var curator
	= secman->credentials_curator();

    obj = orb->resolve_initial_references
	("TransportSecurity::SecurityManager");
    TransportSecurity::SecurityManager_var ts_secman
	= TransportSecurity::SecurityManager::_narrow(obj);
    assert(!CORBA::is_nil(ts_secman));
    TransportSecurity::CredentialsCurator_var ts_curator
	= ts_secman->credentials_curator();

    obj = orb->resolve_initial_references("SL3TLS::ArgBuilderFactory");
    SL3AQArgs::ArgBuilderFactory_var fact
	= SL3AQArgs::ArgBuilderFactory::_narrow(obj);
    assert(!CORBA::is_nil(fact));
    SL3TLS::OpenSSLConfigArgBuilder_var builder
	= SL3TLS::OpenSSLConfigArgBuilder::_narrow
	(fact->create_arg_builder(SL3CM::CU_InitiateOnly));
    assert(!CORBA::is_nil(builder));
    builder->add_tls_initiator_options("ca_cert.pem", "c_cert.pem", "c_key.pem");
    builder->add_initiator_verify_depth(1);
    SL3AQArgs::Argument_var tls_arg = builder->reap_args();
    TransportSecurity::CredentialsAcquirer_var ts_acquirer
	= ts_curator->acquire_credentials(tls_arg);
    TransportSecurity::OwnCredentials_var ts_creds
	= ts_acquirer->get_credentials(TRUE);

    obj = orb->resolve_initial_references("SL3CSI::ArgBuilderFactory");
    SL3AQArgs::ArgBuilderFactory_var csi_fact
	= SL3AQArgs::ArgBuilderFactory::_narrow(obj);
    assert(!CORBA::is_nil(csi_fact));
    SL3CSI::CSIArgBuilder_var csi_builder
	= SL3CSI::CSIArgBuilder::_narrow
	(csi_fact->create_arg_builder(SL3CM::CU_InitiateOnly));
    assert(!CORBA::is_nil(csi_builder));

    csi_builder->add_transport_credentials(ts_creds);
    csi_builder->add_password_generator(new PasswordGenerator_impl);
    csi_builder->add_trust_in_server_decider(new TrustDecider(trust));
    SL3AQArgs::Argument_var args = csi_builder->reap_args();

    SecurityLevel3::CredentialsAcquirer_var acquirer
	= curator->acquire_credentials(args);
    SecurityLevel3::OwnCredentials_var creds = acquirer->get_credentials(TRUE);
    wcout << "client: OwnCredentials:" << endl;
    MICOSL3Utils::PP::print_own_credentials(&wcout, creds);

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
    wcout << "client: TargetCredentials:";
    if (!CORBA::is_nil(tcreds1)) {
	wcout << endl;
	MICOSL3Utils::PP::print_target_credentials(&wcout, tcreds1);
    }
    else {
	wcout << " NULL" << endl;
    }
    try {
	hello->hello ();
    } catch (const CORBA::Exception& ex) {
	wcout << "client: caught " << ex._repoid() << endl;
    }
    //SecurityLevel3::TargetCredentials_var tcreds2 = secman->get_target_credentials(hello);
    //MICOSL3Utils::PP::print_target_credentials(&wcout, tcreds1);
    orb->destroy();
    return 0;
}

