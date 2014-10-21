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
 * Base interface for class CSIArgBuilder
 */

SL3CSI::CSIArgBuilder::~CSIArgBuilder()
{
}

void *
SL3CSI::CSIArgBuilder::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SL3CSI/CSIArgBuilder:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::ArgBuilder::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3CSI::CSIArgBuilder_ptr
SL3CSI::CSIArgBuilder::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SL3CSI/CSIArgBuilder:1.0" )))
      return _duplicate( (SL3CSI::CSIArgBuilder_ptr) _p );
  }
  return _nil();
}

SL3CSI::CSIArgBuilder_ptr
SL3CSI::CSIArgBuilder::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3CSI
{
CORBA::TypeCodeConst _tc_CSIArgBuilder;
}

struct __tc_init_SL3CSI {
  __tc_init_SL3CSI()
  {
    SL3CSI::_tc_CSIArgBuilder = 
    "010000000e00000042000000010000002800000049444c3a616469726f6e"
    "2e636f6d2f534c334353492f4353494172674275696c6465723a312e3000"
    "0e0000004353494172674275696c64657200";
  }

  ~__tc_init_SL3CSI()
  {
  }
};

static __tc_init_SL3CSI __init_SL3CSI;

