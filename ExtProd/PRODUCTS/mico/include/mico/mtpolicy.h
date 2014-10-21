/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __MTPOLICY_H__
#define __MTPOLICY_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace MICOMT
{

class ServerConcurrencyModelPolicy;
typedef ServerConcurrencyModelPolicy *ServerConcurrencyModelPolicy_ptr;
typedef ServerConcurrencyModelPolicy_ptr ServerConcurrencyModelPolicyRef;
typedef ObjVar< ServerConcurrencyModelPolicy > ServerConcurrencyModelPolicy_var;
typedef ObjOut< ServerConcurrencyModelPolicy > ServerConcurrencyModelPolicy_out;

class ClientConcurrencyModelPolicy;
typedef ClientConcurrencyModelPolicy *ClientConcurrencyModelPolicy_ptr;
typedef ClientConcurrencyModelPolicy_ptr ClientConcurrencyModelPolicyRef;
typedef ObjVar< ClientConcurrencyModelPolicy > ClientConcurrencyModelPolicy_var;
typedef ObjOut< ClientConcurrencyModelPolicy > ClientConcurrencyModelPolicy_out;

class ConnectionLimitPolicy;
typedef ConnectionLimitPolicy *ConnectionLimitPolicy_ptr;
typedef ConnectionLimitPolicy_ptr ConnectionLimitPolicyRef;
typedef ObjVar< ConnectionLimitPolicy > ConnectionLimitPolicy_var;
typedef ObjOut< ConnectionLimitPolicy > ConnectionLimitPolicy_out;

class RequestLimitPolicy;
typedef RequestLimitPolicy *RequestLimitPolicy_ptr;
typedef RequestLimitPolicy_ptr RequestLimitPolicyRef;
typedef ObjVar< RequestLimitPolicy > RequestLimitPolicy_var;
typedef ObjOut< RequestLimitPolicy > RequestLimitPolicy_out;

}






namespace MICOMT
{

const ::CORBA::PolicyType SERVER_CONCURRENCY_MODEL_POLICY_TYPE = 1002;

/*
 * Base class and common definitions for local interface ServerConcurrencyModelPolicy
 */

class ServerConcurrencyModelPolicy : 
  virtual public CORBA::Object,
  virtual public ::CORBA::Policy
{
  public:
    virtual ~ServerConcurrencyModelPolicy();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ServerConcurrencyModelPolicy_ptr _ptr_type;
    typedef ServerConcurrencyModelPolicy_var _var_type;
    #endif

    static ServerConcurrencyModelPolicy_ptr _narrow( CORBA::Object_ptr obj );
    static ServerConcurrencyModelPolicy_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ServerConcurrencyModelPolicy_ptr _duplicate( ServerConcurrencyModelPolicy_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ServerConcurrencyModelPolicy_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::MICOMT::ServerConcurrencyModel model() = 0;

  protected:
    ServerConcurrencyModelPolicy() {};
  private:
    ServerConcurrencyModelPolicy( const ServerConcurrencyModelPolicy& );
    void operator=( const ServerConcurrencyModelPolicy& );
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ServerConcurrencyModelPolicy;


const ::CORBA::PolicyType CLIENT_CONCURRENCY_MODEL_POLICY_TYPE = 1003;

/*
 * Base class and common definitions for local interface ClientConcurrencyModelPolicy
 */

class ClientConcurrencyModelPolicy : 
  virtual public CORBA::Object,
  virtual public ::CORBA::Policy
{
  public:
    virtual ~ClientConcurrencyModelPolicy();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ClientConcurrencyModelPolicy_ptr _ptr_type;
    typedef ClientConcurrencyModelPolicy_var _var_type;
    #endif

    static ClientConcurrencyModelPolicy_ptr _narrow( CORBA::Object_ptr obj );
    static ClientConcurrencyModelPolicy_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ClientConcurrencyModelPolicy_ptr _duplicate( ClientConcurrencyModelPolicy_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ClientConcurrencyModelPolicy_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::MICOMT::ClientConcurrencyModel model() = 0;

  protected:
    ClientConcurrencyModelPolicy() {};
  private:
    ClientConcurrencyModelPolicy( const ClientConcurrencyModelPolicy& );
    void operator=( const ClientConcurrencyModelPolicy& );
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ClientConcurrencyModelPolicy;


const ::CORBA::PolicyType CONNECTION_LIMIT_POLICY_TYPE = 1004;

/*
 * Base class and common definitions for local interface ConnectionLimitPolicy
 */

class ConnectionLimitPolicy : 
  virtual public CORBA::Object,
  virtual public ::CORBA::Policy
{
  public:
    virtual ~ConnectionLimitPolicy();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ConnectionLimitPolicy_ptr _ptr_type;
    typedef ConnectionLimitPolicy_var _var_type;
    #endif

    static ConnectionLimitPolicy_ptr _narrow( CORBA::Object_ptr obj );
    static ConnectionLimitPolicy_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ConnectionLimitPolicy_ptr _duplicate( ConnectionLimitPolicy_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ConnectionLimitPolicy_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual CORBA::ULong limit() = 0;

  protected:
    ConnectionLimitPolicy() {};
  private:
    ConnectionLimitPolicy( const ConnectionLimitPolicy& );
    void operator=( const ConnectionLimitPolicy& );
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ConnectionLimitPolicy;


const ::CORBA::PolicyType REQUEST_LIMIT_POLICY_TYPE = 1005;

/*
 * Base class and common definitions for local interface RequestLimitPolicy
 */

class RequestLimitPolicy : 
  virtual public CORBA::Object,
  virtual public ::CORBA::Policy
{
  public:
    virtual ~RequestLimitPolicy();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef RequestLimitPolicy_ptr _ptr_type;
    typedef RequestLimitPolicy_var _var_type;
    #endif

    static RequestLimitPolicy_ptr _narrow( CORBA::Object_ptr obj );
    static RequestLimitPolicy_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static RequestLimitPolicy_ptr _duplicate( RequestLimitPolicy_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static RequestLimitPolicy_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual CORBA::ULong limit() = 0;

  protected:
    RequestLimitPolicy() {};
  private:
    RequestLimitPolicy( const RequestLimitPolicy& );
    void operator=( const RequestLimitPolicy& );
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_RequestLimitPolicy;


}


#ifndef MICO_CONF_NO_POA



namespace POA_MICOMT
{

}


#endif // MICO_CONF_NO_POA

#endif
