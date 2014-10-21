/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __TRUST_H__
#define __TRUST_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace Trust
{

class LocalTrustInServerDecider;
typedef LocalTrustInServerDecider *LocalTrustInServerDecider_ptr;
typedef LocalTrustInServerDecider_ptr LocalTrustInServerDeciderRef;
typedef ObjVar< LocalTrustInServerDecider > LocalTrustInServerDecider_var;
typedef ObjOut< LocalTrustInServerDecider > LocalTrustInServerDecider_out;

}






namespace Trust
{


/*
 * Base class and common definitions for local interface LocalTrustInServerDecider
 */

class LocalTrustInServerDecider : 
  virtual public CORBA::Object
{
  public:
    virtual ~LocalTrustInServerDecider();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef LocalTrustInServerDecider_ptr _ptr_type;
    typedef LocalTrustInServerDecider_var _var_type;
    #endif

    static LocalTrustInServerDecider_ptr _narrow( CORBA::Object_ptr obj );
    static LocalTrustInServerDecider_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static LocalTrustInServerDecider_ptr _duplicate( LocalTrustInServerDecider_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static LocalTrustInServerDecider_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual CORBA::Boolean is_trusted( ::SL3PM::Principal* server_principal, const ::SL3PM::StatementList& supporting_statements, CORBA::Boolean confidentiality, CORBA::Boolean integrity, ::SL3CM::CredsDirective creds_directive ) = 0;

  protected:
    LocalTrustInServerDecider() {};
  private:
    LocalTrustInServerDecider( const LocalTrustInServerDecider& );
    void operator=( const LocalTrustInServerDecider& );
};


}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

#endif
