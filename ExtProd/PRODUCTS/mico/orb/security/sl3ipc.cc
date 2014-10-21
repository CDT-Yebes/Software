/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2003 by The Mico Team
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
 * Base interface for class IPCArgBuilder
 */

SL3IPC::IPCArgBuilder::~IPCArgBuilder()
{
}

void *
SL3IPC::IPCArgBuilder::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3IPC/IPCArgBuilder:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::ArgBuilder::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3IPC::IPCArgBuilder_ptr
SL3IPC::IPCArgBuilder::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3IPC/IPCArgBuilder:1.0" )))
      return _duplicate( (SL3IPC::IPCArgBuilder_ptr) _p );
  }
  return _nil();
}

SL3IPC::IPCArgBuilder_ptr
SL3IPC::IPCArgBuilder::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3IPC
{
CORBA::TypeCodeConst _tc_IPCArgBuilder;
}

struct __tc_init_SL3IPC {
  __tc_init_SL3IPC()
  {
    SL3IPC::_tc_IPCArgBuilder = 
    "010000000e0000003a000000010000001d00000049444c3a534c33495043"
    "2f4950434172674275696c6465723a312e30000000000e00000049504341"
    "72674275696c64657200";
  }

  ~__tc_init_SL3IPC()
  {
  }
};

static __tc_init_SL3IPC __init_SL3IPC;

