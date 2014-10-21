#include "hello.h"

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef _WINDOWS
#include <direct.h>
#endif

#include <mico/security/sl3utils.h>
#include <mico/util.h>


using namespace std;

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


class InitiatingContextObserver
    : virtual public SL3OMExt::InitiatingContextDestroyObserver,
      virtual public CORBA::LocalObject
{
public:
    InitiatingContextObserver(const wstring& name);

    virtual char*
    name();

    virtual void
    establish_context(TransportSecurity::TargetCredentials_ptr ctx);

    virtual void
    close_context(TransportSecurity::TargetCredentials_ptr ctx);

    virtual void
    destroy_context(TransportSecurity::TargetCredentials_ptr ctx);
private:
    wstring name_;
};

InitiatingContextObserver::InitiatingContextObserver(const wstring& name)
    : name_(name)
{
}

char*
InitiatingContextObserver::name()
{
    return CORBA::string_dup(wstr2str(name_).c_str());
}

void
InitiatingContextObserver::establish_context
(TransportSecurity::TargetCredentials_ptr ctx)
{
    wcout << name_ << " establish_context: " << ctx->context_id() << endl;
}

void
InitiatingContextObserver::close_context
(TransportSecurity::TargetCredentials_ptr ctx)
{
    wcout << name_ << " close_context: " << ctx->context_id() << endl;
}

void
InitiatingContextObserver::destroy_context
(TransportSecurity::TargetCredentials_ptr ctx)
{
    wcout << name_ << " destroy_context: " << ctx->context_id() << endl;
}


int
main (int argc, char *argv[])
{
    wcout << "client started" << endl;
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
    //builder->addSupportCSIv1(FALSE);
    //builder->addSupportCSIv2(TRUE);
    builder->add_tls_initiator_options("ca_cert.pem", "c_cert.pem", "c_key.pem");
    builder->add_initiator_verify_depth(1);
    builder->add_credentials_observer
	(new CredsObserver(L"ClientCredsObserver_1"));
    builder->add_credentials_observer
	(new CredsObserver(L"ClientCredsObserver_2"));
    builder->add_credentials_observer
	(new CredsObserver(L"ClientCredsObserver_3"));
    builder->add_credentials_observer
	(new CredsObserver(L"ClientCredsObserver_4"));
    builder->add_initiating_context_observer
	(new InitiatingContextObserver(L"InitiatingContextObserver_1"));
    builder->add_initiating_context_observer
	(new InitiatingContextObserver(L"InitiatingContextObserver_2"));
    builder->add_initiating_context_observer
	(new InitiatingContextObserver(L"InitiatingContextObserver_3"));
    builder->add_initiating_context_observer
	(new InitiatingContextObserver(L"InitiatingContextObserver_4"));
    SL3AQArgs::Argument_var arg = builder->reap_args();

    TransportSecurity::CredentialsAcquirer_var acquirer
	= curator->acquire_credentials(arg);
    TransportSecurity::OwnCredentials_var creds = acquirer->get_credentials(TRUE);

    char pwd[256], uri[300];
    sprintf (uri, "file://%s/hello.ref", getcwd(pwd, 256));

    CORBA::Object_var obj2 = orb->string_to_object (uri);
    HelloWorld_var hello = HelloWorld::_narrow (obj2);

    if (CORBA::is_nil (hello)) {
	printf ("oops: could not locate HelloWorld server\n");
	exit (1);
    }
    hello->hello ();
    hello->hello ();
    hello->hello ();
    hello->hello ();
    CORBA::String_var id = creds->creds_id();
    wcout << L"client remove creds: " << id.in() << endl;
    curator->remove_credentials(id);
    wcout << L"client release creds: " << id.in() << endl;
    curator->release_credentials(id);
    hello->hello ();
    hello->hello ();
    hello->hello ();
    hello->hello ();
    //wcout << "creds refcnt: " << creds->_refcnt() << endl;
    orb->destroy();
    //wcout << "orb refcnt(): " << orb->_refcnt() << endl;
    //CORBA::release(orb);
    //wcout << "creds refcnt: " << creds->_refcnt() << endl;
    wcout << "client finished" << endl;
    return 0;
}
