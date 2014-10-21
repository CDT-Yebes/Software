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
 * Base interface for class CredentialsDestroyObserver
 */

SL3OMExt::CredentialsDestroyObserver::~CredentialsDestroyObserver()
{
}

void *
SL3OMExt::CredentialsDestroyObserver::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3OMExt/CredentialsDestroyObserver:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3OM::CredentialsObserver::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3OMExt::CredentialsDestroyObserver_ptr
SL3OMExt::CredentialsDestroyObserver::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3OMExt/CredentialsDestroyObserver:1.0" )))
      return _duplicate( (SL3OMExt::CredentialsDestroyObserver_ptr) _p );
  }
  return _nil();
}

SL3OMExt::CredentialsDestroyObserver_ptr
SL3OMExt::CredentialsDestroyObserver::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3OMExt
{
CORBA::TypeCodeConst _tc_CredentialsDestroyObserver;
}


/*
 * Base interface for class AcceptingContextDestroyObserver
 */

SL3OMExt::AcceptingContextDestroyObserver::~AcceptingContextDestroyObserver()
{
}

void *
SL3OMExt::AcceptingContextDestroyObserver::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3OMExt/AcceptingContextDestroyObserver:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3OM::AcceptingContextObserver::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3OMExt::AcceptingContextDestroyObserver_ptr
SL3OMExt::AcceptingContextDestroyObserver::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3OMExt/AcceptingContextDestroyObserver:1.0" )))
      return _duplicate( (SL3OMExt::AcceptingContextDestroyObserver_ptr) _p );
  }
  return _nil();
}

SL3OMExt::AcceptingContextDestroyObserver_ptr
SL3OMExt::AcceptingContextDestroyObserver::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3OMExt
{
CORBA::TypeCodeConst _tc_AcceptingContextDestroyObserver;
}


/*
 * Base interface for class InitiatingContextDestroyObserver
 */

SL3OMExt::InitiatingContextDestroyObserver::~InitiatingContextDestroyObserver()
{
}

void *
SL3OMExt::InitiatingContextDestroyObserver::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3OMExt/InitiatingContextDestroyObserver:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3OM::InitiatingContextObserver::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3OMExt::InitiatingContextDestroyObserver_ptr
SL3OMExt::InitiatingContextDestroyObserver::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3OMExt/InitiatingContextDestroyObserver:1.0" )))
      return _duplicate( (SL3OMExt::InitiatingContextDestroyObserver_ptr) _p );
  }
  return _nil();
}

SL3OMExt::InitiatingContextDestroyObserver_ptr
SL3OMExt::InitiatingContextDestroyObserver::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3OMExt
{
CORBA::TypeCodeConst _tc_InitiatingContextDestroyObserver;
}


/*
 * Base interface for class ClientCredentialsDestroyObserver
 */

SL3OMExt::ClientCredentialsDestroyObserver::~ClientCredentialsDestroyObserver()
{
}

void *
SL3OMExt::ClientCredentialsDestroyObserver::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3OMExt/ClientCredentialsDestroyObserver:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3OM::ClientCredentialsObserver::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3OMExt::ClientCredentialsDestroyObserver_ptr
SL3OMExt::ClientCredentialsDestroyObserver::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3OMExt/ClientCredentialsDestroyObserver:1.0" )))
      return _duplicate( (SL3OMExt::ClientCredentialsDestroyObserver_ptr) _p );
  }
  return _nil();
}

SL3OMExt::ClientCredentialsDestroyObserver_ptr
SL3OMExt::ClientCredentialsDestroyObserver::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3OMExt
{
CORBA::TypeCodeConst _tc_ClientCredentialsDestroyObserver;
}


/*
 * Base interface for class TargetCredentialsDestroyObserver
 */

SL3OMExt::TargetCredentialsDestroyObserver::~TargetCredentialsDestroyObserver()
{
}

void *
SL3OMExt::TargetCredentialsDestroyObserver::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3OMExt/TargetCredentialsDestroyObserver:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3OM::TargetCredentialsObserver::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3OMExt::TargetCredentialsDestroyObserver_ptr
SL3OMExt::TargetCredentialsDestroyObserver::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3OMExt/TargetCredentialsDestroyObserver:1.0" )))
      return _duplicate( (SL3OMExt::TargetCredentialsDestroyObserver_ptr) _p );
  }
  return _nil();
}

SL3OMExt::TargetCredentialsDestroyObserver_ptr
SL3OMExt::TargetCredentialsDestroyObserver::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3OMExt
{
CORBA::TypeCodeConst _tc_TargetCredentialsDestroyObserver;
}

struct __tc_init_SL3OMEXT {
  __tc_init_SL3OMEXT()
  {
    SL3OMExt::_tc_CredentialsDestroyObserver = 
    "010000000e00000053000000010000002c00000049444c3a534c334f4d45"
    "78742f43726564656e7469616c7344657374726f794f627365727665723a"
    "312e30001b00000043726564656e7469616c7344657374726f794f627365"
    "7276657200";
    SL3OMExt::_tc_AcceptingContextDestroyObserver = 
    "010000000e00000060000000010000003100000049444c3a534c334f4d45"
    "78742f416363657074696e67436f6e7465787444657374726f794f627365"
    "727665723a312e300000000020000000416363657074696e67436f6e7465"
    "787444657374726f794f6273657276657200";
    SL3OMExt::_tc_InitiatingContextDestroyObserver = 
    "010000000e00000061000000010000003200000049444c3a534c334f4d45"
    "78742f496e6974696174696e67436f6e7465787444657374726f794f6273"
    "65727665723a312e3000000021000000496e6974696174696e67436f6e74"
    "65787444657374726f794f6273657276657200";
    SL3OMExt::_tc_ClientCredentialsDestroyObserver = 
    "010000000e00000061000000010000003200000049444c3a534c334f4d45"
    "78742f436c69656e7443726564656e7469616c7344657374726f794f6273"
    "65727665723a312e3000000021000000436c69656e7443726564656e7469"
    "616c7344657374726f794f6273657276657200";
    SL3OMExt::_tc_TargetCredentialsDestroyObserver = 
    "010000000e00000061000000010000003200000049444c3a534c334f4d45"
    "78742f54617267657443726564656e7469616c7344657374726f794f6273"
    "65727665723a312e300000002100000054617267657443726564656e7469"
    "616c7344657374726f794f6273657276657200";
  }

  ~__tc_init_SL3OMEXT()
  {
  }
};

static __tc_init_SL3OMEXT __init_SL3OMEXT;

