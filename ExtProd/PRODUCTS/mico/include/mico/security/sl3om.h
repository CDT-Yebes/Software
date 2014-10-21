/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __SL3OM_H__
#define __SL3OM_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace SL3OM
{

class Observer;
typedef Observer *Observer_ptr;
typedef Observer_ptr ObserverRef;
typedef ObjVar< Observer > Observer_var;
typedef ObjOut< Observer > Observer_out;

class CredentialsObserver;
typedef CredentialsObserver *CredentialsObserver_ptr;
typedef CredentialsObserver_ptr CredentialsObserverRef;
typedef ObjVar< CredentialsObserver > CredentialsObserver_var;
typedef ObjOut< CredentialsObserver > CredentialsObserver_out;

class AcceptingContextObserver;
typedef AcceptingContextObserver *AcceptingContextObserver_ptr;
typedef AcceptingContextObserver_ptr AcceptingContextObserverRef;
typedef ObjVar< AcceptingContextObserver > AcceptingContextObserver_var;
typedef ObjOut< AcceptingContextObserver > AcceptingContextObserver_out;

class InitiatingContextObserver;
typedef InitiatingContextObserver *InitiatingContextObserver_ptr;
typedef InitiatingContextObserver_ptr InitiatingContextObserverRef;
typedef ObjVar< InitiatingContextObserver > InitiatingContextObserver_var;
typedef ObjOut< InitiatingContextObserver > InitiatingContextObserver_out;

class ClientCredentialsObserver;
typedef ClientCredentialsObserver *ClientCredentialsObserver_ptr;
typedef ClientCredentialsObserver_ptr ClientCredentialsObserverRef;
typedef ObjVar< ClientCredentialsObserver > ClientCredentialsObserver_var;
typedef ObjOut< ClientCredentialsObserver > ClientCredentialsObserver_out;

class TargetCredentialsObserver;
typedef TargetCredentialsObserver *TargetCredentialsObserver_ptr;
typedef TargetCredentialsObserver_ptr TargetCredentialsObserverRef;
typedef ObjVar< TargetCredentialsObserver > TargetCredentialsObserver_var;
typedef ObjOut< TargetCredentialsObserver > TargetCredentialsObserver_out;

}






namespace SL3OM
{


/*
 * Base class and common definitions for local interface Observer
 */

class Observer : 
  virtual public CORBA::Object
{
  public:
    virtual ~Observer();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef Observer_ptr _ptr_type;
    typedef Observer_var _var_type;
    #endif

    static Observer_ptr _narrow( CORBA::Object_ptr obj );
    static Observer_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static Observer_ptr _duplicate( Observer_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static Observer_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual char* name() = 0;

  protected:
    Observer() {};
  private:
    Observer( const Observer& );
    void operator=( const Observer& );
};


typedef IfaceSequenceTmpl< Observer_var,Observer_ptr> ObserverSeq;
typedef TSeqVar< IfaceSequenceTmpl< Observer_var,Observer_ptr> > ObserverSeq_var;
typedef TSeqOut< IfaceSequenceTmpl< Observer_var,Observer_ptr> > ObserverSeq_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ObserverSeq;


/*
 * Base class and common definitions for local interface CredentialsObserver
 */

class CredentialsObserver : 
  virtual public ::SL3OM::Observer
{
  public:
    virtual ~CredentialsObserver();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef CredentialsObserver_ptr _ptr_type;
    typedef CredentialsObserver_var _var_type;
    #endif

    static CredentialsObserver_ptr _narrow( CORBA::Object_ptr obj );
    static CredentialsObserver_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static CredentialsObserver_ptr _duplicate( CredentialsObserver_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static CredentialsObserver_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void create_credentials( const char* id ) = 0;
    virtual void relinquish_credentials( const char* id ) = 0;

  protected:
    CredentialsObserver() {};
  private:
    CredentialsObserver( const CredentialsObserver& );
    void operator=( const CredentialsObserver& );
};



/*
 * Base class and common definitions for local interface AcceptingContextObserver
 */

class AcceptingContextObserver : 
  virtual public ::SL3OM::Observer
{
  public:
    virtual ~AcceptingContextObserver();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef AcceptingContextObserver_ptr _ptr_type;
    typedef AcceptingContextObserver_var _var_type;
    #endif

    static AcceptingContextObserver_ptr _narrow( CORBA::Object_ptr obj );
    static AcceptingContextObserver_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static AcceptingContextObserver_ptr _duplicate( AcceptingContextObserver_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static AcceptingContextObserver_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void establish_context( ::TransportSecurity::ClientCredentials_ptr ctx ) = 0;
    virtual void close_context( ::TransportSecurity::ClientCredentials_ptr ctx ) = 0;

  protected:
    AcceptingContextObserver() {};
  private:
    AcceptingContextObserver( const AcceptingContextObserver& );
    void operator=( const AcceptingContextObserver& );
};



/*
 * Base class and common definitions for local interface InitiatingContextObserver
 */

class InitiatingContextObserver : 
  virtual public ::SL3OM::Observer
{
  public:
    virtual ~InitiatingContextObserver();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef InitiatingContextObserver_ptr _ptr_type;
    typedef InitiatingContextObserver_var _var_type;
    #endif

    static InitiatingContextObserver_ptr _narrow( CORBA::Object_ptr obj );
    static InitiatingContextObserver_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static InitiatingContextObserver_ptr _duplicate( InitiatingContextObserver_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static InitiatingContextObserver_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void establish_context( ::TransportSecurity::TargetCredentials_ptr ctx ) = 0;
    virtual void close_context( ::TransportSecurity::TargetCredentials_ptr ctx ) = 0;

  protected:
    InitiatingContextObserver() {};
  private:
    InitiatingContextObserver( const InitiatingContextObserver& );
    void operator=( const InitiatingContextObserver& );
};



/*
 * Base class and common definitions for local interface ClientCredentialsObserver
 */

class ClientCredentialsObserver : 
  virtual public ::SL3OM::Observer
{
  public:
    virtual ~ClientCredentialsObserver();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ClientCredentialsObserver_ptr _ptr_type;
    typedef ClientCredentialsObserver_var _var_type;
    #endif

    static ClientCredentialsObserver_ptr _narrow( CORBA::Object_ptr obj );
    static ClientCredentialsObserver_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ClientCredentialsObserver_ptr _duplicate( ClientCredentialsObserver_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ClientCredentialsObserver_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void create_credentials( ::SecurityLevel3::ClientCredentials_ptr creds ) = 0;
    virtual void release_credentials( ::SecurityLevel3::ClientCredentials_ptr creds ) = 0;

  protected:
    ClientCredentialsObserver() {};
  private:
    ClientCredentialsObserver( const ClientCredentialsObserver& );
    void operator=( const ClientCredentialsObserver& );
};



/*
 * Base class and common definitions for local interface TargetCredentialsObserver
 */

class TargetCredentialsObserver : 
  virtual public ::SL3OM::Observer
{
  public:
    virtual ~TargetCredentialsObserver();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TargetCredentialsObserver_ptr _ptr_type;
    typedef TargetCredentialsObserver_var _var_type;
    #endif

    static TargetCredentialsObserver_ptr _narrow( CORBA::Object_ptr obj );
    static TargetCredentialsObserver_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TargetCredentialsObserver_ptr _duplicate( TargetCredentialsObserver_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TargetCredentialsObserver_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void create_credentials( ::SecurityLevel3::TargetCredentials_ptr creds ) = 0;
    virtual void release_credentials( ::SecurityLevel3::TargetCredentials_ptr creds ) = 0;

  protected:
    TargetCredentialsObserver() {};
  private:
    TargetCredentialsObserver( const TargetCredentialsObserver& );
    void operator=( const TargetCredentialsObserver& );
};


}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

#endif
