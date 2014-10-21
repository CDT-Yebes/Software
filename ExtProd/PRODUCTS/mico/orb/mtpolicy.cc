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
 * Base interface for class ServerConcurrencyModelPolicy
 */

MICOMT::ServerConcurrencyModelPolicy::~ServerConcurrencyModelPolicy()
{
}

void *
MICOMT::ServerConcurrencyModelPolicy::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:MICOMT/ServerConcurrencyModelPolicy:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = CORBA::Policy::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

MICOMT::ServerConcurrencyModelPolicy_ptr
MICOMT::ServerConcurrencyModelPolicy::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:MICOMT/ServerConcurrencyModelPolicy:1.0" )))
      return _duplicate( (MICOMT::ServerConcurrencyModelPolicy_ptr) _p );
  }
  return _nil();
}

MICOMT::ServerConcurrencyModelPolicy_ptr
MICOMT::ServerConcurrencyModelPolicy::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace MICOMT
{
CORBA::TypeCodeConst _tc_ServerConcurrencyModelPolicy;
}


/*
 * Base interface for class ClientConcurrencyModelPolicy
 */

MICOMT::ClientConcurrencyModelPolicy::~ClientConcurrencyModelPolicy()
{
}

void *
MICOMT::ClientConcurrencyModelPolicy::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:MICOMT/ClientConcurrencyModelPolicy:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = CORBA::Policy::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

MICOMT::ClientConcurrencyModelPolicy_ptr
MICOMT::ClientConcurrencyModelPolicy::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:MICOMT/ClientConcurrencyModelPolicy:1.0" )))
      return _duplicate( (MICOMT::ClientConcurrencyModelPolicy_ptr) _p );
  }
  return _nil();
}

MICOMT::ClientConcurrencyModelPolicy_ptr
MICOMT::ClientConcurrencyModelPolicy::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace MICOMT
{
CORBA::TypeCodeConst _tc_ClientConcurrencyModelPolicy;
}


/*
 * Base interface for class ConnectionLimitPolicy
 */

MICOMT::ConnectionLimitPolicy::~ConnectionLimitPolicy()
{
}

void *
MICOMT::ConnectionLimitPolicy::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:MICOMT/ConnectionLimitPolicy:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = CORBA::Policy::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

MICOMT::ConnectionLimitPolicy_ptr
MICOMT::ConnectionLimitPolicy::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:MICOMT/ConnectionLimitPolicy:1.0" )))
      return _duplicate( (MICOMT::ConnectionLimitPolicy_ptr) _p );
  }
  return _nil();
}

MICOMT::ConnectionLimitPolicy_ptr
MICOMT::ConnectionLimitPolicy::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace MICOMT
{
CORBA::TypeCodeConst _tc_ConnectionLimitPolicy;
}


/*
 * Base interface for class RequestLimitPolicy
 */

MICOMT::RequestLimitPolicy::~RequestLimitPolicy()
{
}

void *
MICOMT::RequestLimitPolicy::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:MICOMT/RequestLimitPolicy:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = CORBA::Policy::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

MICOMT::RequestLimitPolicy_ptr
MICOMT::RequestLimitPolicy::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:MICOMT/RequestLimitPolicy:1.0" )))
      return _duplicate( (MICOMT::RequestLimitPolicy_ptr) _p );
  }
  return _nil();
}

MICOMT::RequestLimitPolicy_ptr
MICOMT::RequestLimitPolicy::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace MICOMT
{
CORBA::TypeCodeConst _tc_RequestLimitPolicy;
}

struct __tc_init_MTPOLICY {
  __tc_init_MTPOLICY()
  {
    MICOMT::_tc_ServerConcurrencyModelPolicy = 
    "010000000e00000055000000010000002c00000049444c3a4d49434f4d54"
    "2f536572766572436f6e63757272656e63794d6f64656c506f6c6963793a"
    "312e30001d000000536572766572436f6e63757272656e63794d6f64656c"
    "506f6c69637900";
    MICOMT::_tc_ClientConcurrencyModelPolicy = 
    "010000000e00000055000000010000002c00000049444c3a4d49434f4d54"
    "2f436c69656e74436f6e63757272656e63794d6f64656c506f6c6963793a"
    "312e30001d000000436c69656e74436f6e63757272656e63794d6f64656c"
    "506f6c69637900";
    MICOMT::_tc_ConnectionLimitPolicy = 
    "010000000e0000004a000000010000002500000049444c3a4d49434f4d54"
    "2f436f6e6e656374696f6e4c696d6974506f6c6963793a312e3000000000"
    "16000000436f6e6e656374696f6e4c696d6974506f6c69637900";
    MICOMT::_tc_RequestLimitPolicy = 
    "010000000e00000043000000010000002200000049444c3a4d49434f4d54"
    "2f526571756573744c696d6974506f6c6963793a312e3000000013000000"
    "526571756573744c696d6974506f6c69637900";
  }

  ~__tc_init_MTPOLICY()
  {
  }
};

static __tc_init_MTPOLICY __init_MTPOLICY;

//--------------------------------------------------------
//  Implementation of skeletons
//--------------------------------------------------------
