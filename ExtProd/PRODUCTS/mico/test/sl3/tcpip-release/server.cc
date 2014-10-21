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
// _ptr is used to see real cleanup!
TransportSecurity::OwnCredentials_ptr creds_for_remove
= TransportSecurity::OwnCredentials::_nil();
long ctx = 0;

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


class HelloWorld_impl
    : virtual public POA_HelloWorld
{
public:
    void hello();
};

void
HelloWorld_impl::hello()
{
    ctx++;
    wcout << "Hello World" << endl;
    CORBA::Object_var obj = orb->resolve_initial_references
	("TransportSecurity::SecurityCurrent");
    TransportSecurity::SecurityCurrent_var current
	= TransportSecurity::SecurityCurrent::_narrow(obj);
    assert(!CORBA::is_nil(current));
    TransportSecurity::ClientCredentials_var creds
	= current->client_credentials();
    if (ctx == 4) {
	creds_for_remove->release_credentials();
    }
}

int
main (int argc, char *argv[])
{
    wcout << "server started" << endl;
    try {
	orb = CORBA::ORB_init(argc, argv);

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
	    (fact->create_arg_builder(SL3CM::CU_AcceptOnly));
	assert(!CORBA::is_nil(builder));
	CORBA::StringSeq sseq(0);
	builder->add_tcpip_acceptor_options(sseq, "localhost", 2345, 0, 0, FALSE);
	//builder->addSupportCSIv1(FALSE);
	//builder->addSupportCSIv2(TRUE);
	//CORBA::Any* arg = builder->reapAQArg();
	builder->add_credentials_observer
	    (new CredsObserver(L"ServerCredsObserver_1"));
	builder->add_credentials_observer
	    (new CredsObserver(L"ServerCredsObserver_2"));
	builder->add_credentials_observer
	    (new CredsObserver(L"ServerCredsObserver_3"));
	builder->add_credentials_observer
	    (new CredsObserver(L"ServerCredsObserver_4"));
	builder->add_accepting_context_observer
	    (new AcceptingContextObserver(L"AcceptingContextObserver_1"));
	builder->add_accepting_context_observer
	    (new AcceptingContextObserver(L"AcceptingContextObserver_2"));
	builder->add_accepting_context_observer
	    (new AcceptingContextObserver(L"AcceptingContextObserver_3"));
	builder->add_accepting_context_observer
	    (new AcceptingContextObserver(L"AcceptingContextObserver_4"));
	SL3AQArgs::Argument_var arg = builder->reap_args();
	{
	    TransportSecurity::CredentialsAcquirer_var acquirer
		= curator->acquire_credentials(arg);
	    TransportSecurity::OwnCredentials_var creds = acquirer->get_credentials(TRUE);
	    // we do not duplicate here, to see real cleanup and to be able
	    // to call creds_for_remove->release_credentials() above
	    // in ::hello() operation
	    creds_for_remove = creds.in();
	}
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
