/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2003 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __SL3IPC_H__
#define __SL3IPC_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace SL3IPC
{

class IPCArgBuilder;
typedef IPCArgBuilder *IPCArgBuilder_ptr;
typedef IPCArgBuilder_ptr IPCArgBuilderRef;
typedef ObjVar< IPCArgBuilder > IPCArgBuilder_var;
typedef ObjOut< IPCArgBuilder > IPCArgBuilder_out;

}






namespace SL3IPC
{


/*
 * Base class and common definitions for local interface IPCArgBuilder
 */

class IPCArgBuilder : 
  virtual public ::SL3AQArgs::ArgBuilder
{
  public:
    virtual ~IPCArgBuilder();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef IPCArgBuilder_ptr _ptr_type;
    typedef IPCArgBuilder_var _var_type;
    #endif

    static IPCArgBuilder_ptr _narrow( CORBA::Object_ptr obj );
    static IPCArgBuilder_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static IPCArgBuilder_ptr _duplicate( IPCArgBuilder_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static IPCArgBuilder_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void add_CSIv1_support( CORBA::Boolean support ) = 0;
    virtual void add_CSIv2_support( CORBA::Boolean support ) = 0;
    virtual void add_accepting_context_observer( ::SL3OM::AcceptingContextObserver_ptr observer ) = 0;
    virtual void add_initiating_context_observer( ::SL3OM::InitiatingContextObserver_ptr observer ) = 0;
    virtual void add_credentials_observer( ::SL3OM::CredentialsObserver_ptr observer ) = 0;

  protected:
    IPCArgBuilder() {};
  private:
    IPCArgBuilder( const IPCArgBuilder& );
    void operator=( const IPCArgBuilder& );
};


}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

#endif
