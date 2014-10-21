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
 * Base interface for class RelativeRoundtripTimeoutPolicy
 */

Messaging::RelativeRoundtripTimeoutPolicy::~RelativeRoundtripTimeoutPolicy()
{
}

void *
Messaging::RelativeRoundtripTimeoutPolicy::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/Messaging/RelativeRoundtripTimeoutPolicy:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = CORBA::Policy::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

Messaging::RelativeRoundtripTimeoutPolicy_ptr
Messaging::RelativeRoundtripTimeoutPolicy::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/Messaging/RelativeRoundtripTimeoutPolicy:1.0" )))
      return _duplicate( (Messaging::RelativeRoundtripTimeoutPolicy_ptr) _p );
  }
  return _nil();
}

Messaging::RelativeRoundtripTimeoutPolicy_ptr
Messaging::RelativeRoundtripTimeoutPolicy::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace Messaging
{
CORBA::TypeCodeConst _tc_RelativeRoundtripTimeoutPolicy;
}

struct __tc_init_MESSAGING {
  __tc_init_MESSAGING()
  {
    Messaging::_tc_RelativeRoundtripTimeoutPolicy = 
    "010000000e00000067000000010000003900000049444c3a6f6d672e6f72"
    "672f4d6573736167696e672f52656c6174697665526f756e647472697054"
    "696d656f7574506f6c6963793a312e30000000001f00000052656c617469"
    "7665526f756e647472697054696d656f7574506f6c69637900";
  }

  ~__tc_init_MESSAGING()
  {
  }
};

static __tc_init_MESSAGING __init_MESSAGING;

//--------------------------------------------------------
//  Implementation of skeletons
//--------------------------------------------------------
