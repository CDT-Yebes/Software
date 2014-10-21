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

class PasswordGenerator_impl
    : virtual public UserPassword::PasswordGenerator,
      virtual public CORBA::LocalObject
{
public:
    PasswordGenerator_impl
    (const char* user,
     const char* passwd,
     const char* realm);

    virtual SL3PM::PrincipalName*
    client_authentication_principal();

    virtual UserPassword::ErrorCode
    generate_password
    (const SL3PM::PrincipalName& target,
     CORBA::WString_out username,
     CORBA::WString_out password);

private:
    wstring user_;
    wstring passwd_;
    wstring realm_;
};

PasswordGenerator_impl::PasswordGenerator_impl
(const char* user, const char* passwd, const char* realm)
    //    user_(user), passwd_(passwd), realm_(realm)
{
    string u = user;
    string p = passwd;
    string r = realm;
    user_ = str2wstr(u);
    passwd_ = str2wstr(p);
    realm_ = str2wstr(r);
}

SL3PM::PrincipalName*
PasswordGenerator_impl::client_authentication_principal()
{
    //cerr << "PasswordGenerator_impl::client_authentication_principal(): " << wstr2str(user_) << endl;
    SL3PM::PrincipalName* result = new SL3PM::PrincipalName;
    result->the_type = (const char*)SL3PM::NT_StringName;
    result->the_name.length(1);
    result->the_name[0] = CORBA::wstring_dup(user_.c_str());
    return result;
}

UserPassword::ErrorCode
PasswordGenerator_impl::generate_password
(const SL3PM::PrincipalName& target,
 CORBA::WString_out username,
 CORBA::WString_out password)
{
    //cerr << "PasswordGenerator_impl::generate_password" << endl;
    if (strcmp(SL3PM::NT_StringName, target.the_type) == 0) {
	if (realm_ == target.the_name[0].in()) {
	    username = CORBA::wstring_dup(user_.c_str());
	    password = CORBA::wstring_dup(passwd_.c_str());
	    //cerr << wstr2str(user_) << ":" << wstr2str(passwd_) << endl;
	    return UserPassword::EC_Success;
	}
    }
    return UserPassword::EC_BadTarget;
}

int
main (int argc, char *argv[])
{
    CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);
    //cerr << "argc: " << argc << endl;
    if (argc != 4) {
	cerr << "Usage: client <user> <passwd> <realm>" << endl;
	cerr << endl;
	return 1;
    }
    string user = argv[1];
    string pw = argv[2];
    string realm = argv[3];
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
    UserPassword::PasswordGenerator_var generator = new PasswordGenerator_impl
	(user.c_str(), pw.c_str(), realm.c_str());
    csi_builder->add_password_generator(generator);
    SL3AQArgs::Argument_var args = csi_builder->reap_args();
    SecurityLevel3::CredentialsAcquirer_var acquirer
	= curator->acquire_credentials(args);
    SecurityLevel3::OwnCredentials_var creds = acquirer->get_credentials(TRUE);

    /*
     * IOR is in hello.ref in the local directory
     */

    char pwd[256], uri[300];
    sprintf (uri, "file://%s/relay.ref", getcwd(pwd, 256));

    /*
     * Bind to Hello World server
     */

    obj = orb->string_to_object (uri);
    HelloWorld_var hello = HelloWorld::_narrow (obj);

    if (CORBA::is_nil (hello)) {
	printf ("oops: could not locate HelloWorld server\n");
	exit (1);
    }
/*    SecurityLevel3::TargetCredentials_var tcreds1 = secman->get_target_credentials(hello);
    assert(!CORBA::is_nil(tcreds1));
    wcout << "client: TargetCredentials:" << endl;
    MICOSL3Utils::PP::print_target_credentials(&wcout, tcreds1);
*/
    cout << "client: user ``" << user << "'' calls hello() operation" << endl;
    hello->hello ();

    //SecurityLevel3::TargetCredentials_var tcreds2 = secman->get_target_credentials(hello);
    //MICOSL3Utils::PP::print_target_credentials(&wcout, tcreds1);
    orb->destroy();
    return 0;
}

