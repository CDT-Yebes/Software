//
// Test for etherealize/incarnate
//

#include "hello.h"
#ifdef HAVE_ANSI_CPLUSPLUS_HEADERS
#include <fstream>
#else // HAVE_ANSI_CPLUSPLUS_HEADERS
#include <fstream.h>
#endif // HAVE_ANSI_CPLUSPLUS_HEADERS

#include <mico/security/sl3utils.h>
#include <mico/util.h>

using namespace SL3PM;
using namespace SL3CM;
using namespace SecurityLevel3;

using namespace std;

CORBA::ORB_ptr orb = CORBA::ORB::_nil();
SecurityManager_var secman = SecurityManager::_nil();
SecurityLevel3::CredentialsCurator_var curator
= SecurityLevel3::CredentialsCurator::_nil();
TransportSecurity::OwnCredentials_var ts_creds
= TransportSecurity::OwnCredentials::_nil();

class PasswordProcessor_impl
    : virtual public UserPassword::PasswordProcessor,
      virtual public CORBA::LocalObject
{
public:
    virtual CORBA::Boolean
    client_authen_required();

    virtual SL3PM::PrincipalName*
    password_target();

    virtual UserPassword::ErrorCode
    verify_password
    (const CORBA::WChar* username,
     const CORBA::WChar* password,
     SL3PM::PrincipalName_out principal);
};

CORBA::Boolean
PasswordProcessor_impl::client_authen_required()
{
    return TRUE;
}

SL3PM::PrincipalName*
PasswordProcessor_impl::password_target()
{
    SL3PM::PrincipalName* result = new SL3PM::PrincipalName;
    result->the_type = (const char*)SL3PM::NT_StringName;
    result->the_name.length(1);
    result->the_name[0] = L"@objectsecurity.com";
    return result;
}

UserPassword::ErrorCode
PasswordProcessor_impl::verify_password
(const CORBA::WChar* username,
 const CORBA::WChar* password,
 SL3PM::PrincipalName_out principal)
{
    //cerr << "relay: PasswordProcessor_impl::verify_password" << endl;
    wstring name = username;
    wstring pw = password;
    //cerr << "name: " << wstr2str(name) << endl;
    principal = new SL3PM::PrincipalName;
    principal->the_type = (const char*)SL3PM::NT_StringName;
    principal->the_name.length(1);
    principal->the_name[0] = CORBA::wstring_dup(name.c_str());
    return UserPassword::EC_Success;
}

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

class Relay_impl
    : virtual public POA_HelloWorld
{
public:
    Relay_impl(HelloWorld_ptr hello);
    void hello();
private:
    HelloWorld_var hello_;
};

Relay_impl::Relay_impl(HelloWorld_ptr hello)
    : hello_(HelloWorld::_duplicate(hello))
{
}

void
Relay_impl::hello()
{
    CORBA::Object_var obj = orb->resolve_initial_references
	("SecurityLevel3::SecurityCurrent");
    SecurityLevel3::SecurityCurrent_var current
	= SecurityLevel3::SecurityCurrent::_narrow(obj);
    assert(!CORBA::is_nil(current));
    SecurityLevel3::ClientCredentials_var creds
	= current->client_credentials();
//      cerr << "creds: " << creds << endl;
//      wcout << "server: ClientCredentials:" << endl;
//      MICOSL3Utils::PP::print_client_credentials(&wcout, creds);
//      wcout << endl;

    Principal_var princ = creds->client_principal();
    PrincipalName name = princ->the_name();
    if (princ->the_type() == PT_Proxy) {
	wcout << "relay: operation executed by: ``" << name.the_name[0].in() << "''" << endl;
    }
    // transport creds
    if (CORBA::is_nil(ts_creds)) {
	// create transport credentials which will be used
	// in all relayed SL3CSI credentials
	obj = orb->resolve_initial_references("SL3TCPIP::ArgBuilderFactory");
	SL3AQArgs::ArgBuilderFactory_var ts_fact
	    = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
	assert(!CORBA::is_nil(ts_fact));
	SL3TCPIP::TCPIPArgBuilder_var ts_builder
	    = SL3TCPIP::TCPIPArgBuilder::_narrow
	    (ts_fact->create_arg_builder(SL3CM::CU_InitiateOnly));
	assert(!CORBA::is_nil(ts_builder));
	SL3AQArgs::Argument_var ts_args = ts_builder->reap_args();
	obj = orb->resolve_initial_references
	    ("TransportSecurity::SecurityManager");
	TransportSecurity::SecurityManager_var ts_secman
	    = TransportSecurity::SecurityManager::_narrow(obj);
	assert(!CORBA::is_nil(ts_secman));
	TransportSecurity::CredentialsCurator_var ts_curator
	    = ts_secman->credentials_curator();
	TransportSecurity::CredentialsAcquirer_var ts_acquirer
	    = ts_curator->acquire_credentials(ts_args);
	ts_creds = ts_acquirer->get_credentials(FALSE);
    }
    //cerr << "ts_creds: " << ts_creds->creds_id() << endl;
    // csi creds
    obj = orb->resolve_initial_references("SL3CSI::ArgBuilderFactory");
    SL3AQArgs::ArgBuilderFactory_var csi_fact
	= SL3AQArgs::ArgBuilderFactory::_narrow(obj);
    assert(!CORBA::is_nil(csi_fact));
    SL3AQArgs::ArgBuilder_var builder_obj = csi_fact->create_arg_builder
	(SL3CM::CU_InitiateOnly);
    SL3CSI::CSIArgBuilder_var csi_builder = SL3CSI::CSIArgBuilder::_narrow
	(builder_obj);
    assert(!CORBA::is_nil(csi_builder));
    // transport creds
    csi_builder->add_transport_credentials(ts_creds);
    // passwd generator
    UserPassword::PasswordGenerator_var generator = new PasswordGenerator_impl
	("relay", "relay_pw", "@objectsecurity.com");
    csi_builder->add_password_generator(generator);
    // quoted principal
    csi_builder->add_named_quoted_principal(name);

    SL3AQArgs::Argument_var args = csi_builder->reap_args();
    SecurityLevel3::CredentialsAcquirer_var acquirer
	= curator->acquire_credentials(args);
    SecurityLevel3::OwnCredentials_var own_creds = acquirer->get_credentials(FALSE);

    // policy
    SecurityLevel3::OwnCredentialsList creds_list;
    creds_list.length(1);
    creds_list[0] = own_creds;
    SecurityLevel3::ContextEstablishmentPolicy_var cep
	= secman->create_context_estab_policy
        (CD_Default, creds_list, FD_UseDefault, FD_UseDefault, FD_UseDefault,
	 FD_UseDefault);
    CORBA::PolicyList policies;
    policies.length(1);
    policies[0] = ContextEstablishmentPolicy::_duplicate(cep);
    CORBA::Object_var hello2_obj = hello_->_set_policy_overrides
	(policies, CORBA::ADD_OVERRIDE);
    HelloWorld_var hello2 = HelloWorld::_narrow(hello2_obj);

    wcout << "relay: server->hello()" << endl;
    hello2->hello();
    // cleanup credentials
    own_creds->release_credentials();
}

int
main (int argc, char *argv[])
{
    //wcout << "wcout init" << endl;
    try {
	orb = CORBA::ORB_init(argc, argv);
	CORBA::Object_var obj = orb->resolve_initial_references
	    ("SecurityLevel3::SecurityManager");
	secman = SecurityLevel3::SecurityManager::_narrow(obj);
	assert(!CORBA::is_nil(secman));
	curator = secman->credentials_curator();
	assert(!CORBA::is_nil(curator));
	// first we need to obtain transport credentials
	obj = orb->resolve_initial_references("SL3TCPIP::ArgBuilderFactory");
	SL3AQArgs::ArgBuilderFactory_var ts_fact
	    = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
	assert(!CORBA::is_nil(ts_fact));
	SL3TCPIP::TCPIPArgBuilder_var ts_builder
	    = SL3TCPIP::TCPIPArgBuilder::_narrow
	    (ts_fact->create_arg_builder(SL3CM::CU_AcceptOnly));
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
	TransportSecurity::OwnCredentials_var ts_creds = ts_acquirer->get_credentials(TRUE);
	//MICOSL3Utils::PP::print_own_credentials(&wcout, ts_creds);

	obj = orb->resolve_initial_references("SL3CSI::ArgBuilderFactory");
	SL3AQArgs::ArgBuilderFactory_var csi_fact
	    = SL3AQArgs::ArgBuilderFactory::_narrow(obj);
	assert(!CORBA::is_nil(csi_fact));
	SL3CSI::CSIArgBuilder_var csi_builder
	    = SL3CSI::CSIArgBuilder::_narrow
	    (csi_fact->create_arg_builder(SL3CM::CU_AcceptOnly));
	assert(!CORBA::is_nil(csi_builder));

	csi_builder->add_transport_credentials(ts_creds);
	UserPassword::PasswordProcessor_var processor = new PasswordProcessor_impl;
	csi_builder->add_password_processor(processor);

	SL3AQArgs::Argument_var args = csi_builder->reap_args();
	SecurityLevel3::CredentialsAcquirer_var acquirer
	    = curator->acquire_credentials(args);
	SecurityLevel3::OwnCredentials_var creds = acquirer->get_credentials(TRUE);
	//wcout << "server: OwnCredentials:" << endl;
	//MICOSL3Utils::PP::print_own_credentials(&wcout, creds);

	CORBA::Object_var poaobj = orb->resolve_initial_references("RootPOA");
	PortableServer::POA_var poa = PortableServer::POA::_narrow(poaobj);
	PortableServer::POAManager_var mgr = poa->the_POAManager();

	char pwd[256], uri[300];
	sprintf (uri, "file://%s/hello.ref", getcwd(pwd, 256));
	obj = orb->string_to_object (uri);
	HelloWorld_var hello = HelloWorld::_narrow (obj);

	Relay_impl* servant = new Relay_impl(hello);
	PortableServer::ObjectId_var oid = poa->activate_object(servant);
	CORBA::Object_var ref = poa->id_to_reference(oid.in());
	ofstream of ("relay.ref");
	CORBA::String_var str = orb->object_to_string(ref);
	of << str.in() << endl;
	of.close();

	wcout << "relay: Running." << endl;

	mgr->activate();
	orb->run();
    } catch (CORBA::UserException& ex) {
	wcout << "UserException caught: " << ex._repoid() << endl;
    } catch (CORBA::SystemException_catch& ex) {
	wcout << "SystemException caught: " << ex._repoid() << endl;
    } catch (...) {
	wcout << "... caught!" << endl;
    }
    return 0;
}
