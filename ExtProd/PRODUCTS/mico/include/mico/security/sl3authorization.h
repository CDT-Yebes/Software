/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __SL3AUTHORIZATION_H__
#define __SL3AUTHORIZATION_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace SL3Authorization
{

class TokenProcessor;
typedef TokenProcessor *TokenProcessor_ptr;
typedef TokenProcessor_ptr TokenProcessorRef;
typedef ObjVar< TokenProcessor > TokenProcessor_var;
typedef ObjOut< TokenProcessor > TokenProcessor_out;

}






namespace SL3Authorization
{

struct AuthorizationInfo;
typedef TVarVar< AuthorizationInfo > AuthorizationInfo_var;
typedef TVarOut< AuthorizationInfo > AuthorizationInfo_out;


struct AuthorizationInfo {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef AuthorizationInfo_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  AuthorizationInfo();
  ~AuthorizationInfo();
  AuthorizationInfo( const AuthorizationInfo& s );
  AuthorizationInfo& operator=( const AuthorizationInfo& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  ::SL3PM::Principal_var the_principal;
  ::SL3PM::StatementList the_statements;
  ::SL3PM::ResourceNameList the_resources;
  // we contain a valuetype
  CORBA::Long _count_refs (CORBA::ValueBase::visited * = 0);
  void _release_members ();
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_AuthorizationInfo;

struct InvalidEvidence : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  InvalidEvidence();
  ~InvalidEvidence();
  InvalidEvidence( const InvalidEvidence& s );
  InvalidEvidence& operator=( const InvalidEvidence& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  #ifndef HAVE_EXPLICIT_STRUCT_OPS
  InvalidEvidence();
  #endif //HAVE_EXPLICIT_STRUCT_OPS
  InvalidEvidence( CORBA::ULong _m0 );

  #ifdef HAVE_STD_EH
  InvalidEvidence *operator->() { return this; }
  InvalidEvidence& operator*() { return *this; }
  operator InvalidEvidence*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static InvalidEvidence *_downcast( CORBA::Exception *ex );
  static const InvalidEvidence *_downcast( const CORBA::Exception *ex );
  CORBA::ULong minor;
};

#ifdef HAVE_STD_EH
typedef InvalidEvidence InvalidEvidence_catch;
#else
typedef ExceptVar< InvalidEvidence > InvalidEvidence_var;
typedef TVarOut< InvalidEvidence > InvalidEvidence_out;
typedef InvalidEvidence_var InvalidEvidence_catch;
#endif // HAVE_STD_EH

extern MICO_EXPORT CORBA::TypeCodeConst _tc_InvalidEvidence;

struct InvalidMechanism : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  InvalidMechanism();
  ~InvalidMechanism();
  InvalidMechanism( const InvalidMechanism& s );
  InvalidMechanism& operator=( const InvalidMechanism& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  #ifndef HAVE_EXPLICIT_STRUCT_OPS
  InvalidMechanism();
  #endif //HAVE_EXPLICIT_STRUCT_OPS
  InvalidMechanism( CORBA::ULong _m0 );

  #ifdef HAVE_STD_EH
  InvalidMechanism *operator->() { return this; }
  InvalidMechanism& operator*() { return *this; }
  operator InvalidMechanism*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static InvalidMechanism *_downcast( CORBA::Exception *ex );
  static const InvalidMechanism *_downcast( const CORBA::Exception *ex );
  CORBA::ULong minor;
};

#ifdef HAVE_STD_EH
typedef InvalidMechanism InvalidMechanism_catch;
#else
typedef ExceptVar< InvalidMechanism > InvalidMechanism_var;
typedef TVarOut< InvalidMechanism > InvalidMechanism_out;
typedef InvalidMechanism_var InvalidMechanism_catch;
#endif // HAVE_STD_EH

extern MICO_EXPORT CORBA::TypeCodeConst _tc_InvalidMechanism;


/*
 * Base class and common definitions for local interface TokenProcessor
 */

class TokenProcessor : 
  virtual public CORBA::Object
{
  public:
    virtual ~TokenProcessor();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TokenProcessor_ptr _ptr_type;
    typedef TokenProcessor_var _var_type;
    #endif

    static TokenProcessor_ptr _narrow( CORBA::Object_ptr obj );
    static TokenProcessor_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TokenProcessor_ptr _duplicate( TokenProcessor_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TokenProcessor_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual CORBA::Boolean supports_endorsement_by_client() = 0;
    virtual CORBA::Boolean requires_endorsement_by_client() = 0;
    virtual ::SL3Authorization::AuthorizationInfo* accept_token( ::SL3PM::Principal* transport_principal, const ::SL3PM::StatementList& transport_statements, const ::SL3PM::ResourceNameList& transport_resources, ::SL3PM::SimplePrincipal* client_auth_principal, ::SL3PM::IdentityStatement* client_auth_statement, ::SL3PM::Principal* identity_assert_principal, const ::SL3PM::StatementList& identity_assert_statements, const ::CSI::AuthorizationToken& auth_token ) = 0;
    virtual ::CSI::AuthorizationElementType accept_token_type() = 0;

  protected:
    TokenProcessor() {};
  private:
    TokenProcessor( const TokenProcessor& );
    void operator=( const TokenProcessor& );
};


}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

void operator<<=( CORBA::Any &_a, const ::SL3Authorization::AuthorizationInfo &_s );
void operator<<=( CORBA::Any &_a, ::SL3Authorization::AuthorizationInfo *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::SL3Authorization::AuthorizationInfo &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::SL3Authorization::AuthorizationInfo *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3Authorization_AuthorizationInfo;

void operator<<=( CORBA::Any &a, const ::SL3Authorization::InvalidEvidence &e );
void operator<<=( CORBA::Any &a, ::SL3Authorization::InvalidEvidence *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::SL3Authorization::InvalidEvidence &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::SL3Authorization::InvalidEvidence *&e );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3Authorization_InvalidEvidence;

void operator<<=( CORBA::Any &a, const ::SL3Authorization::InvalidMechanism &e );
void operator<<=( CORBA::Any &a, ::SL3Authorization::InvalidMechanism *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::SL3Authorization::InvalidMechanism &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::SL3Authorization::InvalidMechanism *&e );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3Authorization_InvalidMechanism;

#endif
