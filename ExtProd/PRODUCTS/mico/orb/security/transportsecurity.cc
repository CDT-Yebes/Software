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
namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_CSIVersion;
}


/*
 * Base interface for class CredentialsInitiator
 */

TransportSecurity::CredentialsInitiator::~CredentialsInitiator()
{
}

void *
TransportSecurity::CredentialsInitiator::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/CredentialsInitiator:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

TransportSecurity::CredentialsInitiator_ptr
TransportSecurity::CredentialsInitiator::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/CredentialsInitiator:1.0" )))
      return _duplicate( (TransportSecurity::CredentialsInitiator_ptr) _p );
  }
  return _nil();
}

TransportSecurity::CredentialsInitiator_ptr
TransportSecurity::CredentialsInitiator::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_CredentialsInitiator;
}


/*
 * Base interface for class CredentialsAcceptor
 */

TransportSecurity::CredentialsAcceptor::~CredentialsAcceptor()
{
}

void *
TransportSecurity::CredentialsAcceptor::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/CredentialsAcceptor:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

TransportSecurity::CredentialsAcceptor_ptr
TransportSecurity::CredentialsAcceptor::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/CredentialsAcceptor:1.0" )))
      return _duplicate( (TransportSecurity::CredentialsAcceptor_ptr) _p );
  }
  return _nil();
}

TransportSecurity::CredentialsAcceptor_ptr
TransportSecurity::CredentialsAcceptor::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_CredentialsAcceptor;
}


/*
 * Base interface for class TransportCredentials
 */

TransportSecurity::TransportCredentials::~TransportCredentials()
{
}

void *
TransportSecurity::TransportCredentials::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/TransportCredentials:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

TransportSecurity::TransportCredentials_ptr
TransportSecurity::TransportCredentials::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/TransportCredentials:1.0" )))
      return _duplicate( (TransportSecurity::TransportCredentials_ptr) _p );
  }
  return _nil();
}

TransportSecurity::TransportCredentials_ptr
TransportSecurity::TransportCredentials::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_TransportCredentials;
}


/*
 * Base interface for class OwnCredentials
 */

TransportSecurity::OwnCredentials::~OwnCredentials()
{
}

void *
TransportSecurity::OwnCredentials::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/OwnCredentials:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = TransportSecurity::TransportCredentials::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

TransportSecurity::OwnCredentials_ptr
TransportSecurity::OwnCredentials::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/OwnCredentials:1.0" )))
      return _duplicate( (TransportSecurity::OwnCredentials_ptr) _p );
  }
  return _nil();
}

TransportSecurity::OwnCredentials_ptr
TransportSecurity::OwnCredentials::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_OwnCredentials;
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_OwnCredentialsList;
}


/*
 * Base interface for class ClientCredentials
 */

TransportSecurity::ClientCredentials::~ClientCredentials()
{
}

void *
TransportSecurity::ClientCredentials::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/ClientCredentials:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = TransportSecurity::TransportCredentials::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

TransportSecurity::ClientCredentials_ptr
TransportSecurity::ClientCredentials::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/ClientCredentials:1.0" )))
      return _duplicate( (TransportSecurity::ClientCredentials_ptr) _p );
  }
  return _nil();
}

TransportSecurity::ClientCredentials_ptr
TransportSecurity::ClientCredentials::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_ClientCredentials;
}


/*
 * Base interface for class TargetCredentials
 */

TransportSecurity::TargetCredentials::~TargetCredentials()
{
}

void *
TransportSecurity::TargetCredentials::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/TargetCredentials:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = TransportSecurity::TransportCredentials::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

TransportSecurity::TargetCredentials_ptr
TransportSecurity::TargetCredentials::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/TargetCredentials:1.0" )))
      return _duplicate( (TransportSecurity::TargetCredentials_ptr) _p );
  }
  return _nil();
}

TransportSecurity::TargetCredentials_ptr
TransportSecurity::TargetCredentials::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_TargetCredentials;
}


/*
 * Base interface for class CredentialsAcquirer
 */

TransportSecurity::CredentialsAcquirer::~CredentialsAcquirer()
{
}

void *
TransportSecurity::CredentialsAcquirer::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/CredentialsAcquirer:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

TransportSecurity::CredentialsAcquirer_ptr
TransportSecurity::CredentialsAcquirer::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/CredentialsAcquirer:1.0" )))
      return _duplicate( (TransportSecurity::CredentialsAcquirer_ptr) _p );
  }
  return _nil();
}

TransportSecurity::CredentialsAcquirer_ptr
TransportSecurity::CredentialsAcquirer::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_CredentialsAcquirer;
}


/*
 * Base interface for class CredentialsCurator
 */

TransportSecurity::CredentialsCurator::~CredentialsCurator()
{
}

void *
TransportSecurity::CredentialsCurator::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/CredentialsCurator:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

TransportSecurity::CredentialsCurator_ptr
TransportSecurity::CredentialsCurator::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/CredentialsCurator:1.0" )))
      return _duplicate( (TransportSecurity::CredentialsCurator_ptr) _p );
  }
  return _nil();
}

TransportSecurity::CredentialsCurator_ptr
TransportSecurity::CredentialsCurator::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_CredentialsCurator;
}


/*
 * Base interface for class ContextEstablishmentPolicy
 */

TransportSecurity::ContextEstablishmentPolicy::~ContextEstablishmentPolicy()
{
}

void *
TransportSecurity::ContextEstablishmentPolicy::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/ContextEstablishmentPolicy:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = CORBA::Policy::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

TransportSecurity::ContextEstablishmentPolicy_ptr
TransportSecurity::ContextEstablishmentPolicy::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/ContextEstablishmentPolicy:1.0" )))
      return _duplicate( (TransportSecurity::ContextEstablishmentPolicy_ptr) _p );
  }
  return _nil();
}

TransportSecurity::ContextEstablishmentPolicy_ptr
TransportSecurity::ContextEstablishmentPolicy::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_ContextEstablishmentPolicy;
}


/*
 * Base interface for class ObjectCredentialsPolicy
 */

TransportSecurity::ObjectCredentialsPolicy::~ObjectCredentialsPolicy()
{
}

void *
TransportSecurity::ObjectCredentialsPolicy::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/ObjectCredentialsPolicy:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = CORBA::Policy::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

TransportSecurity::ObjectCredentialsPolicy_ptr
TransportSecurity::ObjectCredentialsPolicy::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/ObjectCredentialsPolicy:1.0" )))
      return _duplicate( (TransportSecurity::ObjectCredentialsPolicy_ptr) _p );
  }
  return _nil();
}

TransportSecurity::ObjectCredentialsPolicy_ptr
TransportSecurity::ObjectCredentialsPolicy::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_ObjectCredentialsPolicy;
}


/*
 * Base interface for class SecurityManager
 */

TransportSecurity::SecurityManager::~SecurityManager()
{
}

void *
TransportSecurity::SecurityManager::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/SecurityManager:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

TransportSecurity::SecurityManager_ptr
TransportSecurity::SecurityManager::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/SecurityManager:1.0" )))
      return _duplicate( (TransportSecurity::SecurityManager_ptr) _p );
  }
  return _nil();
}

TransportSecurity::SecurityManager_ptr
TransportSecurity::SecurityManager::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_SecurityManager;
}


/*
 * Base interface for class SecurityCurrent
 */

TransportSecurity::SecurityCurrent::~SecurityCurrent()
{
}

void *
TransportSecurity::SecurityCurrent::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/SecurityCurrent:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

TransportSecurity::SecurityCurrent_ptr
TransportSecurity::SecurityCurrent::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/SecurityCurrent:1.0" )))
      return _duplicate( (TransportSecurity::SecurityCurrent_ptr) _p );
  }
  return _nil();
}

TransportSecurity::SecurityCurrent_ptr
TransportSecurity::SecurityCurrent::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_SecurityCurrent;
}

struct __tc_init_TRANSPORTSECURITY {
  __tc_init_TRANSPORTSECURITY()
  {
    TransportSecurity::_tc_CSIVersion = 
    "01000000150000004c000000010000003000000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f43534956657273"
    "696f6e3a312e30000b00000043534956657273696f6e000003000000";
    TransportSecurity::_tc_CredentialsInitiator = 
    "010000000e0000005d000000010000003a00000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f43726564656e74"
    "69616c73496e69746961746f723a312e300000001500000043726564656e"
    "7469616c73496e69746961746f7200";
    TransportSecurity::_tc_CredentialsAcceptor = 
    "010000000e0000005c000000010000003900000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f43726564656e74"
    "69616c734163636570746f723a312e30000000001400000043726564656e"
    "7469616c734163636570746f7200";
    TransportSecurity::_tc_TransportCredentials = 
    "010000000e0000005d000000010000003a00000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f5472616e73706f"
    "727443726564656e7469616c733a312e30000000150000005472616e7370"
    "6f727443726564656e7469616c7300";
    TransportSecurity::_tc_OwnCredentials = 
    "010000000e0000004f000000010000003400000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f4f776e43726564"
    "656e7469616c733a312e30000f0000004f776e43726564656e7469616c73"
    "00";
    TransportSecurity::_tc_OwnCredentialsList = 
    "0100000015000000c0000000010000003800000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f4f776e43726564"
    "656e7469616c734c6973743a312e3000130000004f776e43726564656e74"
    "69616c734c69737400001300000060000000010000000e0000004f000000"
    "010000003400000049444c3a616469726f6e2e636f6d2f5472616e73706f"
    "727453656375726974792f4f776e43726564656e7469616c733a312e3000"
    "0f0000004f776e43726564656e7469616c73000000000000";
    TransportSecurity::_tc_ClientCredentials = 
    "010000000e00000056000000010000003700000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f436c69656e7443"
    "726564656e7469616c733a312e30000012000000436c69656e7443726564"
    "656e7469616c7300";
    TransportSecurity::_tc_TargetCredentials = 
    "010000000e00000056000000010000003700000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f54617267657443"
    "726564656e7469616c733a312e3000001200000054617267657443726564"
    "656e7469616c7300";
    TransportSecurity::_tc_CredentialsAcquirer = 
    "010000000e0000005c000000010000003900000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f43726564656e74"
    "69616c7341637175697265723a312e30000000001400000043726564656e"
    "7469616c73416371756972657200";
    TransportSecurity::_tc_CredentialsCurator = 
    "010000000e00000057000000010000003800000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f43726564656e74"
    "69616c7343757261746f723a312e30001300000043726564656e7469616c"
    "7343757261746f7200";
    TransportSecurity::_tc_ContextEstablishmentPolicy = 
    "010000000e00000067000000010000004000000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f436f6e74657874"
    "45737461626c6973686d656e74506f6c6963793a312e30001b000000436f"
    "6e7465787445737461626c6973686d656e74506f6c69637900";
    TransportSecurity::_tc_ObjectCredentialsPolicy = 
    "010000000e00000064000000010000003d00000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f4f626a65637443"
    "726564656e7469616c73506f6c6963793a312e3000000000180000004f62"
    "6a65637443726564656e7469616c73506f6c69637900";
    TransportSecurity::_tc_SecurityManager = 
    "010000000e00000054000000010000003500000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f53656375726974"
    "794d616e616765723a312e30000000001000000053656375726974794d61"
    "6e6167657200";
    TransportSecurity::_tc_SecurityCurrent = 
    "010000000e00000054000000010000003500000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f53656375726974"
    "7943757272656e743a312e30000000001000000053656375726974794375"
    "7272656e7400";
  }

  ~__tc_init_TRANSPORTSECURITY()
  {
  }
};

static __tc_init_TRANSPORTSECURITY __init_TRANSPORTSECURITY;

