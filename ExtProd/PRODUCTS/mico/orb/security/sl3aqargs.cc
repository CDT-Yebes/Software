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
 * Base interface for class Argument
 */

SL3AQArgs::Argument::~Argument()
{
}

void *
SL3AQArgs::Argument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SL3AQArgs/Argument:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SL3AQArgs::Argument_ptr
SL3AQArgs::Argument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SL3AQArgs/Argument:1.0" )))
      return _duplicate( (SL3AQArgs::Argument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::Argument_ptr
SL3AQArgs::Argument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_Argument;
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_ArgumentSeq;
}


/*
 * Base interface for class ArgBuilder
 */

SL3AQArgs::ArgBuilder::~ArgBuilder()
{
}

void *
SL3AQArgs::ArgBuilder::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SL3AQArgs/ArgBuilder:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SL3AQArgs::ArgBuilder_ptr
SL3AQArgs::ArgBuilder::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SL3AQArgs/ArgBuilder:1.0" )))
      return _duplicate( (SL3AQArgs::ArgBuilder_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::ArgBuilder_ptr
SL3AQArgs::ArgBuilder::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_ArgBuilder;
}


/*
 * Base interface for class ArgBuilderFactory
 */

SL3AQArgs::ArgBuilderFactory::~ArgBuilderFactory()
{
}

void *
SL3AQArgs::ArgBuilderFactory::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SL3AQArgs/ArgBuilderFactory:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SL3AQArgs::ArgBuilderFactory_ptr
SL3AQArgs::ArgBuilderFactory::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SL3AQArgs/ArgBuilderFactory:1.0" )))
      return _duplicate( (SL3AQArgs::ArgBuilderFactory_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::ArgBuilderFactory_ptr
SL3AQArgs::ArgBuilderFactory::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_ArgBuilderFactory;
}

struct __tc_init_SL3AQARGS {
  __tc_init_SL3AQARGS()
  {
    SL3AQArgs::_tc_Argument = 
    "010000000e0000003d000000010000002600000049444c3a616469726f6e"
    "2e636f6d2f534c334151417267732f417267756d656e743a312e30000000"
    "09000000417267756d656e7400";
    SL3AQArgs::_tc_ArgumentSeq = 
    "01000000150000009c000000010000002900000049444c3a616469726f6e"
    "2e636f6d2f534c334151417267732f417267756d656e745365713a312e30"
    "000000000c000000417267756d656e745365710013000000500000000100"
    "00000e0000003d000000010000002600000049444c3a616469726f6e2e63"
    "6f6d2f534c334151417267732f417267756d656e743a312e300000000900"
    "0000417267756d656e740000000000000000";
    SL3AQArgs::_tc_ArgBuilder = 
    "010000000e0000003f000000010000002800000049444c3a616469726f6e"
    "2e636f6d2f534c334151417267732f4172674275696c6465723a312e3000"
    "0b0000004172674275696c64657200";
    SL3AQArgs::_tc_ArgBuilderFactory = 
    "010000000e0000004e000000010000002f00000049444c3a616469726f6e"
    "2e636f6d2f534c334151417267732f4172674275696c646572466163746f"
    "72793a312e300000120000004172674275696c646572466163746f727900"
    ;
  }

  ~__tc_init_SL3AQARGS()
  {
  }
};

static __tc_init_SL3AQARGS __init_SL3AQARGS;

