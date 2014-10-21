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
 * Base interface for class Observer
 */

SL3OM::Observer::~Observer()
{
}

void *
SL3OM::Observer::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3OM/Observer:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SL3OM::Observer_ptr
SL3OM::Observer::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3OM/Observer:1.0" )))
      return _duplicate( (SL3OM::Observer_ptr) _p );
  }
  return _nil();
}

SL3OM::Observer_ptr
SL3OM::Observer::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3OM
{
CORBA::TypeCodeConst _tc_Observer;
}

namespace SL3OM
{
CORBA::TypeCodeConst _tc_ObserverSeq;
}


/*
 * Base interface for class CredentialsObserver
 */

SL3OM::CredentialsObserver::~CredentialsObserver()
{
}

void *
SL3OM::CredentialsObserver::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3OM/CredentialsObserver:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3OM::Observer::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3OM::CredentialsObserver_ptr
SL3OM::CredentialsObserver::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3OM/CredentialsObserver:1.0" )))
      return _duplicate( (SL3OM::CredentialsObserver_ptr) _p );
  }
  return _nil();
}

SL3OM::CredentialsObserver_ptr
SL3OM::CredentialsObserver::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3OM
{
CORBA::TypeCodeConst _tc_CredentialsObserver;
}


/*
 * Base interface for class AcceptingContextObserver
 */

SL3OM::AcceptingContextObserver::~AcceptingContextObserver()
{
}

void *
SL3OM::AcceptingContextObserver::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3OM/AcceptingContextObserver:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3OM::Observer::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3OM::AcceptingContextObserver_ptr
SL3OM::AcceptingContextObserver::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3OM/AcceptingContextObserver:1.0" )))
      return _duplicate( (SL3OM::AcceptingContextObserver_ptr) _p );
  }
  return _nil();
}

SL3OM::AcceptingContextObserver_ptr
SL3OM::AcceptingContextObserver::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3OM
{
CORBA::TypeCodeConst _tc_AcceptingContextObserver;
}


/*
 * Base interface for class InitiatingContextObserver
 */

SL3OM::InitiatingContextObserver::~InitiatingContextObserver()
{
}

void *
SL3OM::InitiatingContextObserver::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3OM/InitiatingContextObserver:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3OM::Observer::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3OM::InitiatingContextObserver_ptr
SL3OM::InitiatingContextObserver::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3OM/InitiatingContextObserver:1.0" )))
      return _duplicate( (SL3OM::InitiatingContextObserver_ptr) _p );
  }
  return _nil();
}

SL3OM::InitiatingContextObserver_ptr
SL3OM::InitiatingContextObserver::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3OM
{
CORBA::TypeCodeConst _tc_InitiatingContextObserver;
}


/*
 * Base interface for class ClientCredentialsObserver
 */

SL3OM::ClientCredentialsObserver::~ClientCredentialsObserver()
{
}

void *
SL3OM::ClientCredentialsObserver::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3OM/ClientCredentialsObserver:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3OM::Observer::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3OM::ClientCredentialsObserver_ptr
SL3OM::ClientCredentialsObserver::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3OM/ClientCredentialsObserver:1.0" )))
      return _duplicate( (SL3OM::ClientCredentialsObserver_ptr) _p );
  }
  return _nil();
}

SL3OM::ClientCredentialsObserver_ptr
SL3OM::ClientCredentialsObserver::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3OM
{
CORBA::TypeCodeConst _tc_ClientCredentialsObserver;
}


/*
 * Base interface for class TargetCredentialsObserver
 */

SL3OM::TargetCredentialsObserver::~TargetCredentialsObserver()
{
}

void *
SL3OM::TargetCredentialsObserver::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3OM/TargetCredentialsObserver:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3OM::Observer::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3OM::TargetCredentialsObserver_ptr
SL3OM::TargetCredentialsObserver::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3OM/TargetCredentialsObserver:1.0" )))
      return _duplicate( (SL3OM::TargetCredentialsObserver_ptr) _p );
  }
  return _nil();
}

SL3OM::TargetCredentialsObserver_ptr
SL3OM::TargetCredentialsObserver::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3OM
{
CORBA::TypeCodeConst _tc_TargetCredentialsObserver;
}

struct __tc_init_SL3OM {
  __tc_init_SL3OM()
  {
    SL3OM::_tc_Observer = 
    "010000000e0000002d000000010000001700000049444c3a534c334f4d2f"
    "4f627365727665723a312e300000090000004f6273657276657200";
    SL3OM::_tc_ObserverSeq = 
    "01000000150000007c000000010000001a00000049444c3a534c334f4d2f"
    "4f627365727665725365713a312e300000000c0000004f62736572766572"
    "536571001300000040000000010000000e0000002d000000010000001700"
    "000049444c3a534c334f4d2f4f627365727665723a312e30000009000000"
    "4f627365727665720000000000000000";
    SL3OM::_tc_CredentialsObserver = 
    "010000000e00000044000000010000002200000049444c3a534c334f4d2f"
    "43726564656e7469616c734f627365727665723a312e3000000014000000"
    "43726564656e7469616c734f6273657276657200";
    SL3OM::_tc_AcceptingContextObserver = 
    "010000000e0000004d000000010000002700000049444c3a534c334f4d2f"
    "416363657074696e67436f6e746578744f627365727665723a312e300000"
    "19000000416363657074696e67436f6e746578744f6273657276657200";
    SL3OM::_tc_InitiatingContextObserver = 
    "010000000e0000004e000000010000002800000049444c3a534c334f4d2f"
    "496e6974696174696e67436f6e746578744f627365727665723a312e3000"
    "1a000000496e6974696174696e67436f6e746578744f6273657276657200"
    ;
    SL3OM::_tc_ClientCredentialsObserver = 
    "010000000e0000004e000000010000002800000049444c3a534c334f4d2f"
    "436c69656e7443726564656e7469616c734f627365727665723a312e3000"
    "1a000000436c69656e7443726564656e7469616c734f6273657276657200"
    ;
    SL3OM::_tc_TargetCredentialsObserver = 
    "010000000e0000004e000000010000002800000049444c3a534c334f4d2f"
    "54617267657443726564656e7469616c734f627365727665723a312e3000"
    "1a00000054617267657443726564656e7469616c734f6273657276657200"
    ;
  }

  ~__tc_init_SL3OM()
  {
  }
};

static __tc_init_SL3OM __init_SL3OM;

