/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __USERPASSWORD_H__
#define __USERPASSWORD_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace UserPassword
{

class PasswordGenerator;
typedef PasswordGenerator *PasswordGenerator_ptr;
typedef PasswordGenerator_ptr PasswordGeneratorRef;
typedef ObjVar< PasswordGenerator > PasswordGenerator_var;
typedef ObjOut< PasswordGenerator > PasswordGenerator_out;

class PasswordProcessor;
typedef PasswordProcessor *PasswordProcessor_ptr;
typedef PasswordProcessor_ptr PasswordProcessorRef;
typedef ObjVar< PasswordProcessor > PasswordProcessor_var;
typedef ObjOut< PasswordProcessor > PasswordProcessor_out;

}






namespace UserPassword
{

typedef CORBA::ULong ErrorCode;
typedef ErrorCode& ErrorCode_out;
extern MICO_EXPORT CORBA::TypeCodeConst _tc_ErrorCode;

const ErrorCode EC_Success = 0;
const ErrorCode EC_Unspecified = 1;
const ErrorCode EC_NoUser = 2;
const ErrorCode EC_BadPassword = 3;
const ErrorCode EC_BadTarget = 4;

/*
 * Base class and common definitions for local interface PasswordGenerator
 */

class PasswordGenerator : 
  virtual public CORBA::Object
{
  public:
    virtual ~PasswordGenerator();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef PasswordGenerator_ptr _ptr_type;
    typedef PasswordGenerator_var _var_type;
    #endif

    static PasswordGenerator_ptr _narrow( CORBA::Object_ptr obj );
    static PasswordGenerator_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static PasswordGenerator_ptr _duplicate( PasswordGenerator_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static PasswordGenerator_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3PM::PrincipalName* client_authentication_principal() = 0;
    virtual ::UserPassword::ErrorCode generate_password( const ::SL3PM::PrincipalName& target, CORBA::WString_out username, CORBA::WString_out password ) = 0;

  protected:
    PasswordGenerator() {};
  private:
    PasswordGenerator( const PasswordGenerator& );
    void operator=( const PasswordGenerator& );
};



/*
 * Base class and common definitions for local interface PasswordProcessor
 */

class PasswordProcessor : 
  virtual public CORBA::Object
{
  public:
    virtual ~PasswordProcessor();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef PasswordProcessor_ptr _ptr_type;
    typedef PasswordProcessor_var _var_type;
    #endif

    static PasswordProcessor_ptr _narrow( CORBA::Object_ptr obj );
    static PasswordProcessor_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static PasswordProcessor_ptr _duplicate( PasswordProcessor_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static PasswordProcessor_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual CORBA::Boolean client_authen_required() = 0;
    virtual ::SL3PM::PrincipalName* password_target() = 0;
    virtual ::UserPassword::ErrorCode verify_password( const CORBA::WChar* username, const CORBA::WChar* password, ::SL3PM::PrincipalName_out principal ) = 0;

  protected:
    PasswordProcessor() {};
  private:
    PasswordProcessor( const PasswordProcessor& );
    void operator=( const PasswordProcessor& );
};


}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

#endif
