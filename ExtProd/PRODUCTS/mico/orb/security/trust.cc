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
 * Base interface for class LocalTrustInServerDecider
 */

Trust::LocalTrustInServerDecider::~LocalTrustInServerDecider()
{
}

void *
Trust::LocalTrustInServerDecider::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/Trust/LocalTrustInServerDecider:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

Trust::LocalTrustInServerDecider_ptr
Trust::LocalTrustInServerDecider::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/Trust/LocalTrustInServerDecider:1.0" )))
      return _duplicate( (Trust::LocalTrustInServerDecider_ptr) _p );
  }
  return _nil();
}

Trust::LocalTrustInServerDecider_ptr
Trust::LocalTrustInServerDecider::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace Trust
{
CORBA::TypeCodeConst _tc_LocalTrustInServerDecider;
}

struct __tc_init_TRUST {
  __tc_init_TRUST()
  {
    Trust::_tc_LocalTrustInServerDecider = 
    "010000000e0000005a000000010000003300000049444c3a616469726f6e"
    "2e636f6d2f54727573742f4c6f63616c5472757374496e53657276657244"
    "6563696465723a312e3000001a0000004c6f63616c5472757374496e5365"
    "727665724465636964657200";
  }

  ~__tc_init_TRUST()
  {
  }
};

static __tc_init_TRUST __init_TRUST;

