/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __SL3OMEXT_H__
#define __SL3OMEXT_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace SL3OMExt
{

class CredentialsDestroyObserver;
typedef CredentialsDestroyObserver *CredentialsDestroyObserver_ptr;
typedef CredentialsDestroyObserver_ptr CredentialsDestroyObserverRef;
typedef ObjVar< CredentialsDestroyObserver > CredentialsDestroyObserver_var;
typedef ObjOut< CredentialsDestroyObserver > CredentialsDestroyObserver_out;

class AcceptingContextDestroyObserver;
typedef AcceptingContextDestroyObserver *AcceptingContextDestroyObserver_ptr;
typedef AcceptingContextDestroyObserver_ptr AcceptingContextDestroyObserverRef;
typedef ObjVar< AcceptingContextDestroyObserver > AcceptingContextDestroyObserver_var;
typedef ObjOut< AcceptingContextDestroyObserver > AcceptingContextDestroyObserver_out;

class InitiatingContextDestroyObserver;
typedef InitiatingContextDestroyObserver *InitiatingContextDestroyObserver_ptr;
typedef InitiatingContextDestroyObserver_ptr InitiatingContextDestroyObserverRef;
typedef ObjVar< InitiatingContextDestroyObserver > InitiatingContextDestroyObserver_var;
typedef ObjOut< InitiatingContextDestroyObserver > InitiatingContextDestroyObserver_out;

class ClientCredentialsDestroyObserver;
typedef ClientCredentialsDestroyObserver *ClientCredentialsDestroyObserver_ptr;
typedef ClientCredentialsDestroyObserver_ptr ClientCredentialsDestroyObserverRef;
typedef ObjVar< ClientCredentialsDestroyObserver > ClientCredentialsDestroyObserver_var;
typedef ObjOut< ClientCredentialsDestroyObserver > ClientCredentialsDestroyObserver_out;

class TargetCredentialsDestroyObserver;
typedef TargetCredentialsDestroyObserver *TargetCredentialsDestroyObserver_ptr;
typedef TargetCredentialsDestroyObserver_ptr TargetCredentialsDestroyObserverRef;
typedef ObjVar< TargetCredentialsDestroyObserver > TargetCredentialsDestroyObserver_var;
typedef ObjOut< TargetCredentialsDestroyObserver > TargetCredentialsDestroyObserver_out;

}






namespace SL3OMExt
{


/*
 * Base class and common definitions for local interface CredentialsDestroyObserver
 */

class CredentialsDestroyObserver : 
  virtual public ::SL3OM::CredentialsObserver
{
  public:
    virtual ~CredentialsDestroyObserver();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef CredentialsDestroyObserver_ptr _ptr_type;
    typedef CredentialsDestroyObserver_var _var_type;
    #endif

    static CredentialsDestroyObserver_ptr _narrow( CORBA::Object_ptr obj );
    static CredentialsDestroyObserver_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static CredentialsDestroyObserver_ptr _duplicate( CredentialsDestroyObserver_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static CredentialsDestroyObserver_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void destroy_credentials( const char* id ) = 0;

  protected:
    CredentialsDestroyObserver() {};
  private:
    CredentialsDestroyObserver( const CredentialsDestroyObserver& );
    void operator=( const CredentialsDestroyObserver& );
};



/*
 * Base class and common definitions for local interface AcceptingContextDestroyObserver
 */

class AcceptingContextDestroyObserver : 
  virtual public ::SL3OM::AcceptingContextObserver
{
  public:
    virtual ~AcceptingContextDestroyObserver();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef AcceptingContextDestroyObserver_ptr _ptr_type;
    typedef AcceptingContextDestroyObserver_var _var_type;
    #endif

    static AcceptingContextDestroyObserver_ptr _narrow( CORBA::Object_ptr obj );
    static AcceptingContextDestroyObserver_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static AcceptingContextDestroyObserver_ptr _duplicate( AcceptingContextDestroyObserver_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static AcceptingContextDestroyObserver_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void destroy_context( ::TransportSecurity::ClientCredentials_ptr ctx ) = 0;

  protected:
    AcceptingContextDestroyObserver() {};
  private:
    AcceptingContextDestroyObserver( const AcceptingContextDestroyObserver& );
    void operator=( const AcceptingContextDestroyObserver& );
};



/*
 * Base class and common definitions for local interface InitiatingContextDestroyObserver
 */

class InitiatingContextDestroyObserver : 
  virtual public ::SL3OM::InitiatingContextObserver
{
  public:
    virtual ~InitiatingContextDestroyObserver();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef InitiatingContextDestroyObserver_ptr _ptr_type;
    typedef InitiatingContextDestroyObserver_var _var_type;
    #endif

    static InitiatingContextDestroyObserver_ptr _narrow( CORBA::Object_ptr obj );
    static InitiatingContextDestroyObserver_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static InitiatingContextDestroyObserver_ptr _duplicate( InitiatingContextDestroyObserver_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static InitiatingContextDestroyObserver_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void destroy_context( ::TransportSecurity::TargetCredentials_ptr ctx ) = 0;

  protected:
    InitiatingContextDestroyObserver() {};
  private:
    InitiatingContextDestroyObserver( const InitiatingContextDestroyObserver& );
    void operator=( const InitiatingContextDestroyObserver& );
};



/*
 * Base class and common definitions for local interface ClientCredentialsDestroyObserver
 */

class ClientCredentialsDestroyObserver : 
  virtual public ::SL3OM::ClientCredentialsObserver
{
  public:
    virtual ~ClientCredentialsDestroyObserver();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ClientCredentialsDestroyObserver_ptr _ptr_type;
    typedef ClientCredentialsDestroyObserver_var _var_type;
    #endif

    static ClientCredentialsDestroyObserver_ptr _narrow( CORBA::Object_ptr obj );
    static ClientCredentialsDestroyObserver_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ClientCredentialsDestroyObserver_ptr _duplicate( ClientCredentialsDestroyObserver_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ClientCredentialsDestroyObserver_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void destroy_credentials( ::SecurityLevel3::ClientCredentials_ptr creds ) = 0;

  protected:
    ClientCredentialsDestroyObserver() {};
  private:
    ClientCredentialsDestroyObserver( const ClientCredentialsDestroyObserver& );
    void operator=( const ClientCredentialsDestroyObserver& );
};



/*
 * Base class and common definitions for local interface TargetCredentialsDestroyObserver
 */

class TargetCredentialsDestroyObserver : 
  virtual public ::SL3OM::TargetCredentialsObserver
{
  public:
    virtual ~TargetCredentialsDestroyObserver();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TargetCredentialsDestroyObserver_ptr _ptr_type;
    typedef TargetCredentialsDestroyObserver_var _var_type;
    #endif

    static TargetCredentialsDestroyObserver_ptr _narrow( CORBA::Object_ptr obj );
    static TargetCredentialsDestroyObserver_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TargetCredentialsDestroyObserver_ptr _duplicate( TargetCredentialsDestroyObserver_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TargetCredentialsDestroyObserver_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void destroy_credentials( ::SecurityLevel3::TargetCredentials_ptr creds ) = 0;

  protected:
    TargetCredentialsDestroyObserver() {};
  private:
    TargetCredentialsDestroyObserver( const TargetCredentialsDestroyObserver& );
    void operator=( const TargetCredentialsDestroyObserver& );
};


}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

#endif
