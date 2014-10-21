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

/*
 * Base interface for class TLSX509IdentityVerifier
 */

SL3TLS::TLSX509IdentityVerifier::~TLSX509IdentityVerifier()
{
}

void *
SL3TLS::TLSX509IdentityVerifier::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SL3TLS/TLSX509IdentityVerifier:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SL3TLS::TLSX509IdentityVerifier_ptr
SL3TLS::TLSX509IdentityVerifier::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SL3TLS/TLSX509IdentityVerifier:1.0" )))
      return _duplicate( (SL3TLS::TLSX509IdentityVerifier_ptr) _p );
  }
  return _nil();
}

SL3TLS::TLSX509IdentityVerifier_ptr
SL3TLS::TLSX509IdentityVerifier::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3TLS
{
CORBA::TypeCodeConst _tc_TLSX509IdentityVerifier;
}


/*
 * Base interface for class TLSKeyStoreArgBuilder
 */

SL3TLS::TLSKeyStoreArgBuilder::~TLSKeyStoreArgBuilder()
{
}

void *
SL3TLS::TLSKeyStoreArgBuilder::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SL3TLS/TLSKeyStoreArgBuilder:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3TCPIP::TCPIPArgBuilder::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3TLS::TLSKeyStoreArgBuilder_ptr
SL3TLS::TLSKeyStoreArgBuilder::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SL3TLS/TLSKeyStoreArgBuilder:1.0" )))
      return _duplicate( (SL3TLS::TLSKeyStoreArgBuilder_ptr) _p );
  }
  return _nil();
}

SL3TLS::TLSKeyStoreArgBuilder_ptr
SL3TLS::TLSKeyStoreArgBuilder::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3TLS
{
CORBA::TypeCodeConst _tc_TLSKeyStoreArgBuilder;
}


/*
 * Base interface for class TLSX509IdentityProcessor
 */

SL3TLS::TLSX509IdentityProcessor::~TLSX509IdentityProcessor()
{
}

void *
SL3TLS::TLSX509IdentityProcessor::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SL3TLS/TLSX509IdentityProcessor:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SL3TLS::TLSX509IdentityProcessor_ptr
SL3TLS::TLSX509IdentityProcessor::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SL3TLS/TLSX509IdentityProcessor:1.0" )))
      return _duplicate( (SL3TLS::TLSX509IdentityProcessor_ptr) _p );
  }
  return _nil();
}

SL3TLS::TLSX509IdentityProcessor_ptr
SL3TLS::TLSX509IdentityProcessor::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3TLS
{
CORBA::TypeCodeConst _tc_TLSX509IdentityProcessor;
}


/*
 * Base interface for class OpenSSLConfigArgBuilder
 */

SL3TLS::OpenSSLConfigArgBuilder::~OpenSSLConfigArgBuilder()
{
}

void *
SL3TLS::OpenSSLConfigArgBuilder::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SL3TLS/OpenSSLConfigArgBuilder:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3TCPIP::TCPIPArgBuilder::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3TLS::OpenSSLConfigArgBuilder_ptr
SL3TLS::OpenSSLConfigArgBuilder::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SL3TLS/OpenSSLConfigArgBuilder:1.0" )))
      return _duplicate( (SL3TLS::OpenSSLConfigArgBuilder_ptr) _p );
  }
  return _nil();
}

SL3TLS::OpenSSLConfigArgBuilder_ptr
SL3TLS::OpenSSLConfigArgBuilder::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3TLS
{
CORBA::TypeCodeConst _tc_OpenSSLConfigArgBuilder;
}

struct __tc_init_SL3TLS {
  __tc_init_SL3TLS()
  {
    SL3TLS::_tc_TLSX509IdentityVerifier = 
    "010000000e00000058000000010000003200000049444c3a616469726f6e"
    "2e636f6d2f534c33544c532f544c53583530394964656e74697479566572"
    "69666965723a312e3000000018000000544c53583530394964656e746974"
    "79566572696669657200";
    SL3TLS::_tc_TLSKeyStoreArgBuilder = 
    "010000000e00000052000000010000003000000049444c3a616469726f6e"
    "2e636f6d2f534c33544c532f544c534b657953746f72654172674275696c"
    "6465723a312e300016000000544c534b657953746f72654172674275696c"
    "64657200";
    SL3TLS::_tc_TLSX509IdentityProcessor = 
    "010000000e00000059000000010000003300000049444c3a616469726f6e"
    "2e636f6d2f534c33544c532f544c53583530394964656e7469747950726f"
    "636573736f723a312e30000019000000544c53583530394964656e746974"
    "7950726f636573736f7200";
    SL3TLS::_tc_OpenSSLConfigArgBuilder = 
    "010000000e00000058000000010000003200000049444c3a616469726f6e"
    "2e636f6d2f534c33544c532f4f70656e53534c436f6e6669674172674275"
    "696c6465723a312e30000000180000004f70656e53534c436f6e66696741"
    "72674275696c64657200";
  }

  ~__tc_init_SL3TLS()
  {
  }
};

static __tc_init_SL3TLS __init_SL3TLS;

