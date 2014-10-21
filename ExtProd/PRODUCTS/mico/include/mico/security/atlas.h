/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __ATLAS_H__
#define __ATLAS_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace ATLAS
{

class AuthTokenDispenser;
typedef AuthTokenDispenser *AuthTokenDispenser_ptr;
typedef AuthTokenDispenser_ptr AuthTokenDispenserRef;
typedef ObjVar< AuthTokenDispenser > AuthTokenDispenser_var;
typedef ObjOut< AuthTokenDispenser > AuthTokenDispenser_out;

}






namespace ATLAS
{

typedef BoundedSequenceTmpl< ::TimeBase::UtcT,MICO_TID_DEF,1> ExpiryTime;
typedef TSeqVar< BoundedSequenceTmpl< ::TimeBase::UtcT,MICO_TID_DEF,1> > ExpiryTime_var;
typedef TSeqOut< BoundedSequenceTmpl< ::TimeBase::UtcT,MICO_TID_DEF,1> > ExpiryTime_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ExpiryTime;

typedef BoundedSequenceTmpl< ::CSI::IdentityToken,MICO_TID_DEF,1> IdTokenOption;
typedef TSeqVar< BoundedSequenceTmpl< ::CSI::IdentityToken,MICO_TID_DEF,1> > IdTokenOption_var;
typedef TSeqOut< BoundedSequenceTmpl< ::CSI::IdentityToken,MICO_TID_DEF,1> > IdTokenOption_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_IdTokenOption;

struct AuthTokenData;
typedef TVarVar< AuthTokenData > AuthTokenData_var;
typedef TVarOut< AuthTokenData > AuthTokenData_out;


struct AuthTokenData {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef AuthTokenData_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  AuthTokenData();
  ~AuthTokenData();
  AuthTokenData( const AuthTokenData& s );
  AuthTokenData& operator=( const AuthTokenData& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  IdTokenOption ident_token;
  ::CSI::AuthorizationToken auth_token;
  ExpiryTime expiry_time;
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_AuthTokenData;

struct IllegalTokenRequest : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  IllegalTokenRequest();
  ~IllegalTokenRequest();
  IllegalTokenRequest( const IllegalTokenRequest& s );
  IllegalTokenRequest& operator=( const IllegalTokenRequest& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  #ifndef HAVE_EXPLICIT_STRUCT_OPS
  IllegalTokenRequest();
  #endif //HAVE_EXPLICIT_STRUCT_OPS
  IllegalTokenRequest( CORBA::ULong _m0, const char* _m1 );

  #ifdef HAVE_STD_EH
  IllegalTokenRequest *operator->() { return this; }
  IllegalTokenRequest& operator*() { return *this; }
  operator IllegalTokenRequest*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static IllegalTokenRequest *_downcast( CORBA::Exception *ex );
  static const IllegalTokenRequest *_downcast( const CORBA::Exception *ex );
  CORBA::ULong the_errnum;
  CORBA::String_var the_reason;
};

#ifdef HAVE_STD_EH
typedef IllegalTokenRequest IllegalTokenRequest_catch;
#else
typedef ExceptVar< IllegalTokenRequest > IllegalTokenRequest_var;
typedef TVarOut< IllegalTokenRequest > IllegalTokenRequest_out;
typedef IllegalTokenRequest_var IllegalTokenRequest_catch;
#endif // HAVE_STD_EH

extern MICO_EXPORT CORBA::TypeCodeConst _tc_IllegalTokenRequest;

struct TokenOkay : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  TokenOkay();
  ~TokenOkay();
  TokenOkay( const TokenOkay& s );
  TokenOkay& operator=( const TokenOkay& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  TokenOkay *operator->() { return this; }
  TokenOkay& operator*() { return *this; }
  operator TokenOkay*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static TokenOkay *_downcast( CORBA::Exception *ex );
  static const TokenOkay *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef TokenOkay TokenOkay_catch;
#else
typedef ExceptVar< TokenOkay > TokenOkay_var;
typedef TVarOut< TokenOkay > TokenOkay_out;
typedef TokenOkay_var TokenOkay_catch;
#endif // HAVE_STD_EH

extern MICO_EXPORT CORBA::TypeCodeConst _tc_TokenOkay;


/*
 * Base class and common definitions for interface AuthTokenDispenser
 */

class AuthTokenDispenser : 
  virtual public CORBA::Object
{
  public:
    virtual ~AuthTokenDispenser();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef AuthTokenDispenser_ptr _ptr_type;
    typedef AuthTokenDispenser_var _var_type;
    #endif

    static AuthTokenDispenser_ptr _narrow( CORBA::Object_ptr obj );
    static AuthTokenDispenser_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static AuthTokenDispenser_ptr _duplicate( AuthTokenDispenser_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static AuthTokenDispenser_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::ATLAS::AuthTokenData* get_my_authorization_token() = 0;
    virtual ::ATLAS::AuthTokenData* translate_authorization_token( const ::CSI::IdentityToken& the_subject, const ::CSI::AuthorizationToken& the_token ) = 0;

  protected:
    AuthTokenDispenser() {};
  private:
    AuthTokenDispenser( const AuthTokenDispenser& );
    void operator=( const AuthTokenDispenser& );
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_AuthTokenDispenser;

// Stub for interface AuthTokenDispenser
class AuthTokenDispenser_stub:
  virtual public AuthTokenDispenser
{
  public:
    virtual ~AuthTokenDispenser_stub();
    ::ATLAS::AuthTokenData* get_my_authorization_token();
    ::ATLAS::AuthTokenData* translate_authorization_token( const ::CSI::IdentityToken& the_subject, const ::CSI::AuthorizationToken& the_token );

  private:
    void operator=( const AuthTokenDispenser_stub& );
};

#ifndef MICO_CONF_NO_POA

class AuthTokenDispenser_stub_clp :
  virtual public AuthTokenDispenser_stub,
  virtual public PortableServer::StubBase
{
  public:
    AuthTokenDispenser_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~AuthTokenDispenser_stub_clp ();
    ::ATLAS::AuthTokenData* get_my_authorization_token();
    ::ATLAS::AuthTokenData* translate_authorization_token( const ::CSI::IdentityToken& the_subject, const ::CSI::AuthorizationToken& the_token );

  protected:
    AuthTokenDispenser_stub_clp ();
  private:
    void operator=( const AuthTokenDispenser_stub_clp & );
};

#endif // MICO_CONF_NO_POA

typedef SequenceTmpl< CORBA::Octet,MICO_TID_OCTET> UTF8String;
typedef TSeqVar< SequenceTmpl< CORBA::Octet,MICO_TID_OCTET> > UTF8String_var;
typedef TSeqOut< SequenceTmpl< CORBA::Octet,MICO_TID_OCTET> > UTF8String_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_UTF8String;

typedef CORBA::ULong ATLASLocatorType;
typedef ATLASLocatorType& ATLASLocatorType_out;
extern MICO_EXPORT CORBA::TypeCodeConst _tc_ATLASLocatorType;

const ATLASLocatorType ATLASCosNaming = 1;
const ATLASLocatorType ATLASURL = 2;
const ATLASLocatorType ATLASObject = 3;
class ATLASLocator;
typedef TVarVar< ATLASLocator > ATLASLocator_var;
typedef TVarOut< ATLASLocator > ATLASLocator_out;


class ATLASLocator {
  public:
    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ATLASLocator_var _var_type;
    #endif
    ATLASLocatorType _discriminator;

    struct __m {
      AuthTokenDispenser_var the_dispenser;
    } _m;

  public:
    #ifdef HAVE_EXPLICIT_STRUCT_OPS
    ATLASLocator();
    ~ATLASLocator();
    ATLASLocator( const ATLASLocator& s );
    ATLASLocator& operator=( const ATLASLocator& s );
    #endif //HAVE_EXPLICIT_STRUCT_OPS


    void _d( ATLASLocatorType _p );
    ATLASLocatorType _d() const;

    void the_dispenser( AuthTokenDispenser_ptr _p );
    AuthTokenDispenser_ptr the_dispenser() const;

    void _default();

};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ATLASLocator;

typedef SequenceTmpl< CORBA::Octet,MICO_TID_OCTET> ATLASCacheId;
typedef TSeqVar< SequenceTmpl< CORBA::Octet,MICO_TID_OCTET> > ATLASCacheId_var;
typedef TSeqOut< SequenceTmpl< CORBA::Octet,MICO_TID_OCTET> > ATLASCacheId_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ATLASCacheId;

struct ATLASProfile;
typedef TVarVar< ATLASProfile > ATLASProfile_var;
typedef TVarOut< ATLASProfile > ATLASProfile_out;


struct ATLASProfile {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef ATLASProfile_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  ATLASProfile();
  ~ATLASProfile();
  ATLASProfile( const ATLASProfile& s );
  ATLASProfile& operator=( const ATLASProfile& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  ATLASLocator the_locator;
  ATLASCacheId the_cache_id;
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ATLASProfile;

const ::CSIIOP::ServiceConfigurationSyntax SCS_ATLAS = 3;
}


#ifndef MICO_CONF_NO_POA



namespace POA_ATLAS
{

class AuthTokenDispenser : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~AuthTokenDispenser ();
    ATLAS::AuthTokenDispenser_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static AuthTokenDispenser * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual ::ATLAS::AuthTokenData* get_my_authorization_token() = 0;
    virtual ::ATLAS::AuthTokenData* translate_authorization_token( const ::CSI::IdentityToken& the_subject, const ::CSI::AuthorizationToken& the_token ) = 0;

  protected:
    AuthTokenDispenser () {};

  private:
    AuthTokenDispenser (const AuthTokenDispenser &);
    void operator= (const AuthTokenDispenser &);
};

}


#endif // MICO_CONF_NO_POA

void operator<<=( CORBA::Any &_a, const ::ATLAS::AuthTokenData &_s );
void operator<<=( CORBA::Any &_a, ::ATLAS::AuthTokenData *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::ATLAS::AuthTokenData &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::ATLAS::AuthTokenData *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_ATLAS_AuthTokenData;

void operator<<=( CORBA::Any &a, const ::ATLAS::IllegalTokenRequest &e );
void operator<<=( CORBA::Any &a, ::ATLAS::IllegalTokenRequest *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::ATLAS::IllegalTokenRequest &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::ATLAS::IllegalTokenRequest *&e );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_ATLAS_IllegalTokenRequest;

void operator<<=( CORBA::Any &a, const ::ATLAS::TokenOkay &e );
void operator<<=( CORBA::Any &a, ::ATLAS::TokenOkay *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::ATLAS::TokenOkay &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::ATLAS::TokenOkay *&e );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_ATLAS_TokenOkay;

void operator<<=( CORBA::Any &a, const ATLAS::AuthTokenDispenser_ptr obj );
void operator<<=( CORBA::Any &a, ATLAS::AuthTokenDispenser_ptr* obj_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, ATLAS::AuthTokenDispenser_ptr &obj );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_ATLAS_AuthTokenDispenser;

void operator<<=( CORBA::Any &_a, const ::ATLAS::ATLASLocator &_u );
void operator<<=( CORBA::Any &_a, ::ATLAS::ATLASLocator *_u );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::ATLAS::ATLASLocator &_u );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::ATLAS::ATLASLocator *&_u );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_ATLAS_ATLASLocator;

void operator<<=( CORBA::Any &_a, const ::ATLAS::ATLASProfile &_s );
void operator<<=( CORBA::Any &_a, ::ATLAS::ATLASProfile *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::ATLAS::ATLASProfile &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::ATLAS::ATLASProfile *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_ATLAS_ATLASProfile;

void operator<<=( CORBA::Any &_a, const BoundedSequenceTmpl< TimeBase::UtcT,MICO_TID_DEF,1> &_s );
void operator<<=( CORBA::Any &_a, BoundedSequenceTmpl< TimeBase::UtcT,MICO_TID_DEF,1> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, BoundedSequenceTmpl< TimeBase::UtcT,MICO_TID_DEF,1> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const BoundedSequenceTmpl< TimeBase::UtcT,MICO_TID_DEF,1> *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller__seq_1b_TimeBase_UtcT;

void operator<<=( CORBA::Any &_a, const BoundedSequenceTmpl< CSI::IdentityToken,MICO_TID_DEF,1> &_s );
void operator<<=( CORBA::Any &_a, BoundedSequenceTmpl< CSI::IdentityToken,MICO_TID_DEF,1> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, BoundedSequenceTmpl< CSI::IdentityToken,MICO_TID_DEF,1> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const BoundedSequenceTmpl< CSI::IdentityToken,MICO_TID_DEF,1> *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller__seq_1b_CSI_IdentityToken;

#endif
