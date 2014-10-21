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

using namespace std;

CORBA::ORB_ptr orb = CORBA::ORB::_nil();
SecurityLevel3::OwnCredentials_ptr creds_for_release
= SecurityLevel3::OwnCredentials::_nil();

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
    //cerr << "PasswordProcessor_impl::verify_password" << endl;
    wstring name = username;
    wstring pw = password;
    if (name == L"karel") {
	if (pw == L"cobalt") {
	    principal = new SL3PM::PrincipalName;
	    principal->the_type = (const char*)SL3PM::NT_StringName;
	    principal->the_name.length(1);
	    principal->the_name[0] = L"karel";
	    return UserPassword::EC_Success;
	}
	return UserPassword::EC_BadPassword;
    }
    return UserPassword::EC_NoUser;
}

class HelloWorld_impl
    : virtual public POA_HelloWorld
{
public:
    void hello();
};

void
HelloWorld_impl::hello()
{
    wcout << "server: Hello World" << endl;
//      CORBA::Object_var obj = orb->resolve_initial_references
//  	("SecurityLevel3::SecurityCurrent");
//      SecurityLevel3::SecurityCurrent_var current
//  	= SecurityLevel3::SecurityCurrent::_narrow(obj);
//      assert(!CORBA::is_nil(current));
//      SecurityLevel3::ClientCredentials_var creds
//  	= current->client_credentials();
//      wcout << "server: ClientCredentials:" << endl;
//      MICOSL3Utils::PP::print_client_credentials(&wcout, creds);
//      wcout << endl;
    creds_for_release->release_credentials();
}

class CredsObserver
    : virtual public SL3OMExt::CredentialsDestroyObserver,
      virtual public CORBA::LocalObject
{
public:
    CredsObserver(const wstring& name);

    virtual char*
    name();

    virtual void
    create_credentials(const char* id);

    virtual void
    relinquish_credentials(const char* id);

    virtual void
    destroy_credentials(const char* id);
private:
    wstring name_;
};

CredsObserver::CredsObserver(const wstring& name)
    : name_(name)
{
}

char*
CredsObserver::name()
{
    return CORBA::string_dup(wstr2str(name_).c_str());
}

void
CredsObserver::create_credentials(const char* id)
{
    wcout << name_ << " create_credentials: " << id << endl;
}

void
CredsObserver::relinquish_credentials(const char* id)
{
    wcout << name_ << " relinquish_credentials: " << id << endl;
}

void
CredsObserver::destroy_credentials(const char* id)
{
    wcout << name_ << " destroy_credentials: " << id << endl;
}


class AcceptingContextObserver
    : virtual public SL3OMExt::AcceptingContextDestroyObserver,
      virtual public CORBA::LocalObject
{
public:
    AcceptingContextObserver(const wstring& name);

    virtual char*
    name();

    virtual void
    establish_context(TransportSecurity::ClientCredentials_ptr ctx);

    virtual void
    close_context(TransportSecurity::ClientCredentials_ptr ctx);

    virtual void
    destroy_context(TransportSecurity::ClientCredentials_ptr ctx);
private:
    wstring name_;
};

AcceptingContextObserver::AcceptingContextObserver(const wstring& name)
    : name_(name)
{
}

char*
AcceptingContextObserver::name()
{
    return CORBA::string_dup(wstr2str(name_).c_str());
}

void
AcceptingContextObserver::establish_context
(TransportSecurity::ClientCredentials_ptr ctx)
{
    wcout << name_ << " establish_context: " << ctx->context_id() << endl;
}

void
AcceptingContextObserver::close_context
(TransportSecurity::ClientCredentials_ptr ctx)
{
    wcout << name_ << " close_context: " << ctx->context_id() << endl;
}

void
AcceptingContextObserver::destroy_context
(TransportSecurity::ClientCredentials_ptr ctx)
{
    wcout << name_ << " destroy_context: " << ctx->context_id() << endl;
}

class ClientCredentialsObserver
    : virtual public SL3OMExt::ClientCredentialsDestroyObserver,
      virtual public CORBA::LocalObject
{
public:
    ClientCredentialsObserver(const wstring& name);

    virtual char*
    name();

    virtual void
    create_credentials(SecurityLevel3::ClientCredentials_ptr creds);

    virtual void
    release_credentials(SecurityLevel3::ClientCredentials_ptr creds);

    virtual void
    destroy_credentials(SecurityLevel3::ClientCredentials_ptr creds);
private:
    wstring name_;
};

ClientCredentialsObserver::ClientCredentialsObserver(const wstring& name)
    : name_(name)
{
}

char*
ClientCredentialsObserver::name()
{
    return CORBA::string_dup(wstr2str(name_).c_str());
}

void
ClientCredentialsObserver::create_credentials
(SecurityLevel3::ClientCredentials_ptr creds)
{
    wcout << name_ << " create_credentials: " << creds->context_id() << endl;
}

void
ClientCredentialsObserver::release_credentials
(SecurityLevel3::ClientCredentials_ptr creds)
{
    wcout << name_ << " release_credentials: " << creds->context_id() << endl;
}

void
ClientCredentialsObserver::destroy_credentials
(SecurityLevel3::ClientCredentials_ptr creds)
{
    wcout << name_ << " destroy_credentials: " << creds->context_id() << endl;
}

int
main (int argc, char *argv[])
{
    wcout << "wcout init" << endl;
    try {
	orb = CORBA::ORB_init(argc, argv);
	CORBA::Object_var obj = orb->resolve_initial_references
	    ("SecurityLevel3::SecurityManager");
	SecurityLevel3::SecurityManager_var secman
	    = SecurityLevel3::SecurityManager::_narrow(obj);
	assert(!CORBA::is_nil(secman));
	SecurityLevel3::CredentialsCurator_var curator
	    = secman->credentials_curator();
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
	ts_builder->add_credentials_observer
	    (new CredsObserver(L"ServerCredsObserver"));
	ts_builder->add_accepting_context_observer
	    (new AcceptingContextObserver(L"AcceptingContextObserver"));
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
	csi_builder->add_credentials_observer
	    (new CredsObserver(L"SL3:ServerCredsObserver"));
	csi_builder->add_client_credentials_observer
	    (new ClientCredentialsObserver(L"SL3:ClientCredentialsObserver"));
	SL3AQArgs::Argument_var args = csi_builder->reap_args();
	{
	    SecurityLevel3::OwnCredentials_var creds
		= SecurityLevel3::OwnCredentials::_nil();
	    SecurityLevel3::CredentialsAcquirer_var acquirer
		= curator->acquire_credentials(args);
	    creds = acquirer->get_credentials(TRUE);
	    creds_for_release = creds.in();
	}
	//MICOSL3Utils::PP::print_own_credentials(&wcout, creds);

	CORBA::Object_var poaobj = orb->resolve_initial_references("RootPOA");
	PortableServer::POA_var poa = PortableServer::POA::_narrow(poaobj);
	PortableServer::POAManager_var mgr = poa->the_POAManager();

	HelloWorld_impl* servant = new HelloWorld_impl;
	PortableServer::ObjectId_var oid = poa->activate_object(servant);
	CORBA::Object_var ref = poa->id_to_reference(oid.in());
	ofstream of ("hello.ref");
	CORBA::String_var str = orb->object_to_string(ref);
	of << str.in() << endl;
	of.close();

	wcout << "Running." << endl;

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
