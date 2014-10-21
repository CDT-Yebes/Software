/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __MESSAGING_H__
#define __MESSAGING_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace Messaging
{

class RelativeRoundtripTimeoutPolicy;
typedef RelativeRoundtripTimeoutPolicy *RelativeRoundtripTimeoutPolicy_ptr;
typedef RelativeRoundtripTimeoutPolicy_ptr RelativeRoundtripTimeoutPolicyRef;
typedef ObjVar< RelativeRoundtripTimeoutPolicy > RelativeRoundtripTimeoutPolicy_var;
typedef ObjOut< RelativeRoundtripTimeoutPolicy > RelativeRoundtripTimeoutPolicy_out;

}






namespace Messaging
{

const ::CORBA::PolicyType RELATIVE_RT_TIMEOUT_POLICY_TYPE = 32;

/*
 * Base class and common definitions for local interface RelativeRoundtripTimeoutPolicy
 */

class RelativeRoundtripTimeoutPolicy : 
  virtual public CORBA::Object,
  virtual public ::CORBA::Policy
{
  public:
    virtual ~RelativeRoundtripTimeoutPolicy();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef RelativeRoundtripTimeoutPolicy_ptr _ptr_type;
    typedef RelativeRoundtripTimeoutPolicy_var _var_type;
    #endif

    static RelativeRoundtripTimeoutPolicy_ptr _narrow( CORBA::Object_ptr obj );
    static RelativeRoundtripTimeoutPolicy_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static RelativeRoundtripTimeoutPolicy_ptr _duplicate( RelativeRoundtripTimeoutPolicy_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static RelativeRoundtripTimeoutPolicy_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::TimeBase::TimeT relative_expiry() = 0;

  protected:
    RelativeRoundtripTimeoutPolicy() {};
  private:
    RelativeRoundtripTimeoutPolicy( const RelativeRoundtripTimeoutPolicy& );
    void operator=( const RelativeRoundtripTimeoutPolicy& );
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_RelativeRoundtripTimeoutPolicy;


}


#ifndef MICO_CONF_NO_POA



namespace POA_Messaging
{

}


#endif // MICO_CONF_NO_POA

#endif
