
#include <CORBA.h>


using namespace std;

int
main(int argc, char* argv[])
{
    CORBA::ORB_ptr orb = CORBA::ORB_init(argc, argv);
    // transport security
    CORBA::Object_var obj = orb->resolve_initial_references
	("TransportSecurity::SecurityManager");
    assert(!CORBA::is_nil(obj));
    TransportSecurity::SecurityManager_var mgr
	= TransportSecurity::SecurityManager::_narrow(obj);
    assert(!CORBA::is_nil(mgr));
    obj = orb->resolve_initial_references
	("TransportSecurity::SecurityCurrent");
    assert(!CORBA::is_nil(obj));
    TransportSecurity::SecurityCurrent_var current
	= TransportSecurity::SecurityCurrent::_narrow(obj);
    assert(!CORBA::is_nil(current));
    try {
	obj = orb->resolve_initial_references
	    ("TransportSecurity::CredentialsCurator");
	assert(!CORBA::is_nil(obj));
	TransportSecurity::CredentialsCurator_var currator
	    = TransportSecurity::CredentialsCurator::_narrow(obj);
	assert(!CORBA::is_nil(currator));
	assert(0);
    } catch (CORBA::ORB::InvalidName& ex) {
    }
    // TCPIP
    obj = orb->resolve_initial_references("SL3TCPIP::ArgBuilderFactory");
    assert(!CORBA::is_nil(obj));
    SL3AQArgs::ArgBuilderFactory_var tcpip_fact
	= SL3AQArgs::ArgBuilderFactory::_narrow(obj);
    assert(!CORBA::is_nil(tcpip_fact));
    // TLS
    obj = orb->resolve_initial_references("SL3TLS::ArgBuilderFactory");
    assert(!CORBA::is_nil(obj));
    SL3AQArgs::ArgBuilderFactory_var tls_fact
	= SL3AQArgs::ArgBuilderFactory::_narrow(obj);
    assert(!CORBA::is_nil(tls_fact));
    // csiv2 + sl3
    obj = orb->resolve_initial_references("SL3CSI::ArgBuilderFactory");
    assert(!CORBA::is_nil(obj));
    SL3AQArgs::ArgBuilderFactory_var csi_fact
	= SL3AQArgs::ArgBuilderFactory::_narrow(obj);
    assert(!CORBA::is_nil(csi_fact));
    obj = orb->resolve_initial_references("SecurityLevel3::SecurityManager");
    assert(!CORBA::is_nil(obj));
    SecurityLevel3::SecurityManager_var secman
	= SecurityLevel3::SecurityManager::_narrow(obj);
    assert(!CORBA::is_nil(secman));
    obj = orb->resolve_initial_references("SecurityLevel3::SecurityCurrent");
    assert(!CORBA::is_nil(obj));
    SecurityLevel3::SecurityCurrent_var seccurr
	= SecurityLevel3::SecurityCurrent::_narrow(obj);
    assert(!CORBA::is_nil(seccurr));
    try {
	obj = orb->resolve_initial_references("SecurityLevel3::CredentialsCurator");
	assert(!CORBA::is_nil(obj));
	SecurityLevel3::CredentialsCurator_var seccurator
	    = SecurityLevel3::CredentialsCurator::_narrow(obj);
	assert(!CORBA::is_nil(seccurator));
	assert(0);
    } catch (CORBA::ORB::InvalidName&) {
    }
    cout << "All tests completed successfully." << endl;
    return(0);
}



