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
namespace UserPassword
{
CORBA::TypeCodeConst _tc_ErrorCode;
}


/*
 * Base interface for class PasswordGenerator
 */

UserPassword::PasswordGenerator::~PasswordGenerator()
{
}

void *
UserPassword::PasswordGenerator::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/UserPassword/PasswordGenerator:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

UserPassword::PasswordGenerator_ptr
UserPassword::PasswordGenerator::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/UserPassword/PasswordGenerator:1.0" )))
      return _duplicate( (UserPassword::PasswordGenerator_ptr) _p );
  }
  return _nil();
}

UserPassword::PasswordGenerator_ptr
UserPassword::PasswordGenerator::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace UserPassword
{
CORBA::TypeCodeConst _tc_PasswordGenerator;
}


/*
 * Base interface for class PasswordProcessor
 */

UserPassword::PasswordProcessor::~PasswordProcessor()
{
}

void *
UserPassword::PasswordProcessor::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/UserPassword/PasswordProcessor:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

UserPassword::PasswordProcessor_ptr
UserPassword::PasswordProcessor::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/UserPassword/PasswordProcessor:1.0" )))
      return _duplicate( (UserPassword::PasswordProcessor_ptr) _p );
  }
  return _nil();
}

UserPassword::PasswordProcessor_ptr
UserPassword::PasswordProcessor::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace UserPassword
{
CORBA::TypeCodeConst _tc_PasswordProcessor;
}

struct __tc_init_USERPASSWORD {
  __tc_init_USERPASSWORD()
  {
    UserPassword::_tc_ErrorCode = 
    "010000001500000048000000010000002a00000049444c3a616469726f6e"
    "2e636f6d2f5573657250617373776f72642f4572726f72436f64653a312e"
    "300000000a0000004572726f72436f646500000005000000";
    UserPassword::_tc_PasswordGenerator = 
    "010000000e00000052000000010000003200000049444c3a616469726f6e"
    "2e636f6d2f5573657250617373776f72642f50617373776f726447656e65"
    "7261746f723a312e300000001200000050617373776f726447656e657261"
    "746f7200";
    UserPassword::_tc_PasswordProcessor = 
    "010000000e00000052000000010000003200000049444c3a616469726f6e"
    "2e636f6d2f5573657250617373776f72642f50617373776f726450726f63"
    "6573736f723a312e300000001200000050617373776f726450726f636573"
    "736f7200";
  }

  ~__tc_init_USERPASSWORD()
  {
  }
};

static __tc_init_USERPASSWORD __init_USERPASSWORD;

