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
 * Base interface for class TCPIPArgBuilder
 */

SL3TCPIP::TCPIPArgBuilder::~TCPIPArgBuilder()
{
}

void *
SL3TCPIP::TCPIPArgBuilder::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SL3TCPIP/TCPIPArgBuilder:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::ArgBuilder::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3TCPIP::TCPIPArgBuilder_ptr
SL3TCPIP::TCPIPArgBuilder::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SL3TCPIP/TCPIPArgBuilder:1.0" )))
      return _duplicate( (SL3TCPIP::TCPIPArgBuilder_ptr) _p );
  }
  return _nil();
}

SL3TCPIP::TCPIPArgBuilder_ptr
SL3TCPIP::TCPIPArgBuilder::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3TCPIP
{
CORBA::TypeCodeConst _tc_TCPIPArgBuilder;
}

struct __tc_init_SL3TCPIP {
  __tc_init_SL3TCPIP()
  {
    SL3TCPIP::_tc_TCPIPArgBuilder = 
    "010000000e00000048000000010000002c00000049444c3a616469726f6e"
    "2e636f6d2f534c3354435049502f54435049504172674275696c6465723a"
    "312e30001000000054435049504172674275696c64657200";
  }

  ~__tc_init_SL3TCPIP()
  {
  }
};

static __tc_init_SL3TCPIP __init_SL3TCPIP;

