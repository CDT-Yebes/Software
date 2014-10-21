/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>
#include <mico/throw.h>
#include <mico/template_impl.h>


using namespace std;

//--------------------------------------------------------
//  Implementation of stubs
//--------------------------------------------------------
namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_InitiatorType;
}


/*
 * Base interface for class CredsInitiator
 */

SecurityLevel3::CredsInitiator::~CredsInitiator()
{
}

void *
SecurityLevel3::CredsInitiator::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SecurityLevel3/CredsInitiator:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SecurityLevel3::CredsInitiator_ptr
SecurityLevel3::CredsInitiator::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SecurityLevel3/CredsInitiator:1.0" )))
      return _duplicate( (SecurityLevel3::CredsInitiator_ptr) _p );
  }
  return _nil();
}

SecurityLevel3::CredsInitiator_ptr
SecurityLevel3::CredsInitiator::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_CredsInitiator;
}


/*
 * Base interface for class CredsAcceptor
 */

SecurityLevel3::CredsAcceptor::~CredsAcceptor()
{
}

void *
SecurityLevel3::CredsAcceptor::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SecurityLevel3/CredsAcceptor:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SecurityLevel3::CredsAcceptor_ptr
SecurityLevel3::CredsAcceptor::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SecurityLevel3/CredsAcceptor:1.0" )))
      return _duplicate( (SecurityLevel3::CredsAcceptor_ptr) _p );
  }
  return _nil();
}

SecurityLevel3::CredsAcceptor_ptr
SecurityLevel3::CredsAcceptor::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_CredsAcceptor;
}


/*
 * Base interface for class Credentials
 */

SecurityLevel3::Credentials::~Credentials()
{
}

void *
SecurityLevel3::Credentials::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SecurityLevel3/Credentials:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SecurityLevel3::Credentials_ptr
SecurityLevel3::Credentials::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SecurityLevel3/Credentials:1.0" )))
      return _duplicate( (SecurityLevel3::Credentials_ptr) _p );
  }
  return _nil();
}

SecurityLevel3::Credentials_ptr
SecurityLevel3::Credentials::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_Credentials;
}

namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_CredentialsList;
}


/*
 * Base interface for class OwnCredentials
 */

SecurityLevel3::OwnCredentials::~OwnCredentials()
{
}

void *
SecurityLevel3::OwnCredentials::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SecurityLevel3/OwnCredentials:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SecurityLevel3::Credentials::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SecurityLevel3::OwnCredentials_ptr
SecurityLevel3::OwnCredentials::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SecurityLevel3/OwnCredentials:1.0" )))
      return _duplicate( (SecurityLevel3::OwnCredentials_ptr) _p );
  }
  return _nil();
}

SecurityLevel3::OwnCredentials_ptr
SecurityLevel3::OwnCredentials::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_OwnCredentials;
}

namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_OwnCredentialsList;
}


/*
 * Base interface for class ClientCredentials
 */

SecurityLevel3::ClientCredentials::~ClientCredentials()
{
}

void *
SecurityLevel3::ClientCredentials::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SecurityLevel3/ClientCredentials:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SecurityLevel3::Credentials::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SecurityLevel3::ClientCredentials_ptr
SecurityLevel3::ClientCredentials::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SecurityLevel3/ClientCredentials:1.0" )))
      return _duplicate( (SecurityLevel3::ClientCredentials_ptr) _p );
  }
  return _nil();
}

SecurityLevel3::ClientCredentials_ptr
SecurityLevel3::ClientCredentials::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_ClientCredentials;
}


/*
 * Base interface for class TargetCredentials
 */

SecurityLevel3::TargetCredentials::~TargetCredentials()
{
}

void *
SecurityLevel3::TargetCredentials::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SecurityLevel3/TargetCredentials:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SecurityLevel3::Credentials::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SecurityLevel3::TargetCredentials_ptr
SecurityLevel3::TargetCredentials::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SecurityLevel3/TargetCredentials:1.0" )))
      return _duplicate( (SecurityLevel3::TargetCredentials_ptr) _p );
  }
  return _nil();
}

SecurityLevel3::TargetCredentials_ptr
SecurityLevel3::TargetCredentials::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_TargetCredentials;
}


/*
 * Base interface for class ContextEstablishmentPolicy
 */

SecurityLevel3::ContextEstablishmentPolicy::~ContextEstablishmentPolicy()
{
}

void *
SecurityLevel3::ContextEstablishmentPolicy::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SecurityLevel3/ContextEstablishmentPolicy:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = CORBA::Policy::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SecurityLevel3::ContextEstablishmentPolicy_ptr
SecurityLevel3::ContextEstablishmentPolicy::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SecurityLevel3/ContextEstablishmentPolicy:1.0" )))
      return _duplicate( (SecurityLevel3::ContextEstablishmentPolicy_ptr) _p );
  }
  return _nil();
}

SecurityLevel3::ContextEstablishmentPolicy_ptr
SecurityLevel3::ContextEstablishmentPolicy::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_ContextEstablishmentPolicy;
}


/*
 * Base interface for class ObjectCredentialsPolicy
 */

SecurityLevel3::ObjectCredentialsPolicy::~ObjectCredentialsPolicy()
{
}

void *
SecurityLevel3::ObjectCredentialsPolicy::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SecurityLevel3/ObjectCredentialsPolicy:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = CORBA::Policy::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SecurityLevel3::ObjectCredentialsPolicy_ptr
SecurityLevel3::ObjectCredentialsPolicy::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SecurityLevel3/ObjectCredentialsPolicy:1.0" )))
      return _duplicate( (SecurityLevel3::ObjectCredentialsPolicy_ptr) _p );
  }
  return _nil();
}

SecurityLevel3::ObjectCredentialsPolicy_ptr
SecurityLevel3::ObjectCredentialsPolicy::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_ObjectCredentialsPolicy;
}


/*
 * Base interface for class CredentialsAcquirer
 */

SecurityLevel3::CredentialsAcquirer::~CredentialsAcquirer()
{
}

void *
SecurityLevel3::CredentialsAcquirer::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SecurityLevel3/CredentialsAcquirer:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SecurityLevel3::CredentialsAcquirer_ptr
SecurityLevel3::CredentialsAcquirer::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SecurityLevel3/CredentialsAcquirer:1.0" )))
      return _duplicate( (SecurityLevel3::CredentialsAcquirer_ptr) _p );
  }
  return _nil();
}

SecurityLevel3::CredentialsAcquirer_ptr
SecurityLevel3::CredentialsAcquirer::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_CredentialsAcquirer;
}


/*
 * Base interface for class CredentialsCurator
 */

SecurityLevel3::CredentialsCurator::~CredentialsCurator()
{
}

void *
SecurityLevel3::CredentialsCurator::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SecurityLevel3/CredentialsCurator:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SecurityLevel3::CredentialsCurator_ptr
SecurityLevel3::CredentialsCurator::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SecurityLevel3/CredentialsCurator:1.0" )))
      return _duplicate( (SecurityLevel3::CredentialsCurator_ptr) _p );
  }
  return _nil();
}

SecurityLevel3::CredentialsCurator_ptr
SecurityLevel3::CredentialsCurator::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_CredentialsCurator;
}


/*
 * Base interface for class SecurityManager
 */

SecurityLevel3::SecurityManager::~SecurityManager()
{
}

void *
SecurityLevel3::SecurityManager::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SecurityLevel3/SecurityManager:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SecurityLevel3::SecurityManager_ptr
SecurityLevel3::SecurityManager::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SecurityLevel3/SecurityManager:1.0" )))
      return _duplicate( (SecurityLevel3::SecurityManager_ptr) _p );
  }
  return _nil();
}

SecurityLevel3::SecurityManager_ptr
SecurityLevel3::SecurityManager::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_SecurityManager;
}


/*
 * Base interface for class SecurityCurrent
 */

SecurityLevel3::SecurityCurrent::~SecurityCurrent()
{
}

void *
SecurityLevel3::SecurityCurrent::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SecurityLevel3/SecurityCurrent:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SecurityLevel3::SecurityCurrent_ptr
SecurityLevel3::SecurityCurrent::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SecurityLevel3/SecurityCurrent:1.0" )))
      return _duplicate( (SecurityLevel3::SecurityCurrent_ptr) _p );
  }
  return _nil();
}

SecurityLevel3::SecurityCurrent_ptr
SecurityLevel3::SecurityCurrent::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SecurityLevel3
{
CORBA::TypeCodeConst _tc_SecurityCurrent;
}

struct __tc_init_SECURITYLEVEL3 {
  __tc_init_SECURITYLEVEL3()
  {
    SecurityLevel3::_tc_InitiatorType = 
    "010000001500000050000000010000003000000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f496e69746961746f7254"
    "7970653a312e30000e000000496e69746961746f72547970650000000500"
    "0000";
    SecurityLevel3::_tc_CredsInitiator = 
    "010000000e0000004f000000010000003100000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f4372656473496e697469"
    "61746f723a312e30000000000f0000004372656473496e69746961746f72"
    "00";
    SecurityLevel3::_tc_CredsAcceptor = 
    "010000000e0000004a000000010000003000000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f43726564734163636570"
    "746f723a312e30000e00000043726564734163636570746f7200";
    SecurityLevel3::_tc_Credentials = 
    "010000000e00000048000000010000002e00000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f43726564656e7469616c"
    "733a312e300000000c00000043726564656e7469616c7300";
    SecurityLevel3::_tc_CredentialsList = 
    "0100000015000000b0000000010000003200000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f43726564656e7469616c"
    "734c6973743a312e300000001000000043726564656e7469616c734c6973"
    "74001300000058000000010000000e00000048000000010000002e000000"
    "49444c3a616469726f6e2e636f6d2f53656375726974794c6576656c332f"
    "43726564656e7469616c733a312e300000000c00000043726564656e7469"
    "616c730000000000";
    SecurityLevel3::_tc_OwnCredentials = 
    "010000000e0000004f000000010000003100000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f4f776e43726564656e74"
    "69616c733a312e30000000000f0000004f776e43726564656e7469616c73"
    "00";
    SecurityLevel3::_tc_OwnCredentialsList = 
    "0100000015000000c0000000010000003500000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f4f776e43726564656e74"
    "69616c734c6973743a312e3000000000130000004f776e43726564656e74"
    "69616c734c69737400001300000060000000010000000e0000004f000000"
    "010000003100000049444c3a616469726f6e2e636f6d2f53656375726974"
    "794c6576656c332f4f776e43726564656e7469616c733a312e3000000000"
    "0f0000004f776e43726564656e7469616c73000000000000";
    SecurityLevel3::_tc_ClientCredentials = 
    "010000000e00000052000000010000003400000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f436c69656e7443726564"
    "656e7469616c733a312e300012000000436c69656e7443726564656e7469"
    "616c7300";
    SecurityLevel3::_tc_TargetCredentials = 
    "010000000e00000052000000010000003400000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f54617267657443726564"
    "656e7469616c733a312e30001200000054617267657443726564656e7469"
    "616c7300";
    SecurityLevel3::_tc_ContextEstablishmentPolicy = 
    "010000000e00000067000000010000003d00000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f436f6e74657874457374"
    "61626c6973686d656e74506f6c6963793a312e30000000001b000000436f"
    "6e7465787445737461626c6973686d656e74506f6c69637900";
    SecurityLevel3::_tc_ObjectCredentialsPolicy = 
    "010000000e00000060000000010000003a00000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f4f626a65637443726564"
    "656e7469616c73506f6c6963793a312e30000000180000004f626a656374"
    "43726564656e7469616c73506f6c69637900";
    SecurityLevel3::_tc_CredentialsAcquirer = 
    "010000000e00000058000000010000003600000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f43726564656e7469616c"
    "7341637175697265723a312e300000001400000043726564656e7469616c"
    "73416371756972657200";
    SecurityLevel3::_tc_CredentialsCurator = 
    "010000000e00000057000000010000003500000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f43726564656e7469616c"
    "7343757261746f723a312e30000000001300000043726564656e7469616c"
    "7343757261746f7200";
    SecurityLevel3::_tc_SecurityManager = 
    "010000000e00000050000000010000003200000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f53656375726974794d61"
    "6e616765723a312e300000001000000053656375726974794d616e616765"
    "7200";
    SecurityLevel3::_tc_SecurityCurrent = 
    "010000000e00000050000000010000003200000049444c3a616469726f6e"
    "2e636f6d2f53656375726974794c6576656c332f53656375726974794375"
    "7272656e743a312e3000000010000000536563757269747943757272656e"
    "7400";
  }

  ~__tc_init_SECURITYLEVEL3()
  {
  }
};

static __tc_init_SECURITYLEVEL3 __init_SECURITYLEVEL3;

