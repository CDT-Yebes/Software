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
namespace ATLAS
{
CORBA::TypeCodeConst _tc_ExpiryTime;
}

namespace ATLAS
{
CORBA::TypeCodeConst _tc_IdTokenOption;
}

namespace ATLAS
{
CORBA::TypeCodeConst _tc_AuthTokenData;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
ATLAS::AuthTokenData::AuthTokenData()
{
}

ATLAS::AuthTokenData::AuthTokenData( const AuthTokenData& _s )
{
  ident_token = ((AuthTokenData&)_s).ident_token;
  auth_token = ((AuthTokenData&)_s).auth_token;
  expiry_time = ((AuthTokenData&)_s).expiry_time;
}

ATLAS::AuthTokenData::~AuthTokenData()
{
}

ATLAS::AuthTokenData&
ATLAS::AuthTokenData::operator=( const AuthTokenData& _s )
{
  ident_token = ((AuthTokenData&)_s).ident_token;
  auth_token = ((AuthTokenData&)_s).auth_token;
  expiry_time = ((AuthTokenData&)_s).expiry_time;
  return *this;
}
#endif

class _Marshaller_ATLAS_AuthTokenData : public ::CORBA::StaticTypeInfo {
    typedef ATLAS::AuthTokenData _MICO_T;
  public:
    ~_Marshaller_ATLAS_AuthTokenData();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_ATLAS_AuthTokenData::~_Marshaller_ATLAS_AuthTokenData()
{
}

::CORBA::StaticValueType _Marshaller_ATLAS_AuthTokenData::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_ATLAS_AuthTokenData::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_ATLAS_AuthTokenData::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_ATLAS_AuthTokenData::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    _marshaller__seq_1b_CSI_IdentityToken->demarshal( dc, &((_MICO_T*)v)->ident_token ) &&
    _marshaller__seq_CSI_AuthorizationElement->demarshal( dc, &((_MICO_T*)v)->auth_token ) &&
    _marshaller__seq_1b_TimeBase_UtcT->demarshal( dc, &((_MICO_T*)v)->expiry_time ) &&
    dc.struct_end();
}

void _Marshaller_ATLAS_AuthTokenData::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  _marshaller__seq_1b_CSI_IdentityToken->marshal( ec, &((_MICO_T*)v)->ident_token );
  _marshaller__seq_CSI_AuthorizationElement->marshal( ec, &((_MICO_T*)v)->auth_token );
  _marshaller__seq_1b_TimeBase_UtcT->marshal( ec, &((_MICO_T*)v)->expiry_time );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_ATLAS_AuthTokenData::typecode()
{
  return ATLAS::_tc_AuthTokenData;
}

::CORBA::StaticTypeInfo *_marshaller_ATLAS_AuthTokenData;

void operator<<=( CORBA::Any &_a, const ATLAS::AuthTokenData &_s )
{
  CORBA::StaticAny _sa (_marshaller_ATLAS_AuthTokenData, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, ATLAS::AuthTokenData *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, ATLAS::AuthTokenData &_s )
{
  CORBA::StaticAny _sa (_marshaller_ATLAS_AuthTokenData, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const ATLAS::AuthTokenData *&_s )
{
  return _a.to_static_any (_marshaller_ATLAS_AuthTokenData, (void *&)_s);
}

namespace ATLAS
{
CORBA::TypeCodeConst _tc_IllegalTokenRequest;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
ATLAS::IllegalTokenRequest::IllegalTokenRequest()
{
}

ATLAS::IllegalTokenRequest::IllegalTokenRequest( const IllegalTokenRequest& _s )
{
  the_errnum = ((IllegalTokenRequest&)_s).the_errnum;
  the_reason = ((IllegalTokenRequest&)_s).the_reason;
}

ATLAS::IllegalTokenRequest::~IllegalTokenRequest()
{
}

ATLAS::IllegalTokenRequest&
ATLAS::IllegalTokenRequest::operator=( const IllegalTokenRequest& _s )
{
  the_errnum = ((IllegalTokenRequest&)_s).the_errnum;
  the_reason = ((IllegalTokenRequest&)_s).the_reason;
  return *this;
}
#endif

#ifndef HAVE_EXPLICIT_STRUCT_OPS
ATLAS::IllegalTokenRequest::IllegalTokenRequest()
{
}

#endif

ATLAS::IllegalTokenRequest::IllegalTokenRequest( CORBA::ULong _m0, const char* _m1 )
{
  the_errnum = _m0;
  the_reason = _m1;
}

class _Marshaller_ATLAS_IllegalTokenRequest : public ::CORBA::StaticTypeInfo {
    typedef ::ATLAS::IllegalTokenRequest _MICO_T;
  public:
    ~_Marshaller_ATLAS_IllegalTokenRequest();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_ATLAS_IllegalTokenRequest::~_Marshaller_ATLAS_IllegalTokenRequest()
{
}

::CORBA::StaticValueType _Marshaller_ATLAS_IllegalTokenRequest::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_ATLAS_IllegalTokenRequest::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_ATLAS_IllegalTokenRequest::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_ATLAS_IllegalTokenRequest::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    CORBA::_stc_ulong->demarshal( dc, &((_MICO_T*)v)->the_errnum ) &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->the_reason._for_demarshal() ) &&
    dc.except_end();
}

void _Marshaller_ATLAS_IllegalTokenRequest::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/ATLAS/IllegalTokenRequest:1.0" );
  CORBA::_stc_ulong->marshal( ec, &((_MICO_T*)v)->the_errnum );
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->the_reason.inout() );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_ATLAS_IllegalTokenRequest::typecode()
{
  return ATLAS::_tc_IllegalTokenRequest;
}

::CORBA::StaticTypeInfo *_marshaller_ATLAS_IllegalTokenRequest;

void operator<<=( CORBA::Any &_a, const ATLAS::IllegalTokenRequest &_e )
{
  CORBA::StaticAny _sa (_marshaller_ATLAS_IllegalTokenRequest, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, ATLAS::IllegalTokenRequest *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, ATLAS::IllegalTokenRequest &_e )
{
  CORBA::StaticAny _sa (_marshaller_ATLAS_IllegalTokenRequest, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const ATLAS::IllegalTokenRequest *&_e )
{
  return _a.to_static_any (_marshaller_ATLAS_IllegalTokenRequest, (void *&)_e);
}

void ATLAS::IllegalTokenRequest::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw IllegalTokenRequest_var( (ATLAS::IllegalTokenRequest*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *ATLAS::IllegalTokenRequest::_repoid() const
{
  return "IDL:omg.org/ATLAS/IllegalTokenRequest:1.0";
}

void ATLAS::IllegalTokenRequest::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_ATLAS_IllegalTokenRequest->marshal( _en, (void*) this );
}

void ATLAS::IllegalTokenRequest::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *ATLAS::IllegalTokenRequest::_clone() const
{
  return new IllegalTokenRequest( *this );
}

ATLAS::IllegalTokenRequest *ATLAS::IllegalTokenRequest::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/ATLAS/IllegalTokenRequest:1.0" ) )
    return (IllegalTokenRequest *) _ex;
  return NULL;
}

const ATLAS::IllegalTokenRequest *ATLAS::IllegalTokenRequest::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/ATLAS/IllegalTokenRequest:1.0" ) )
    return (IllegalTokenRequest *) _ex;
  return NULL;
}

namespace ATLAS
{
CORBA::TypeCodeConst _tc_TokenOkay;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
ATLAS::TokenOkay::TokenOkay()
{
}

ATLAS::TokenOkay::TokenOkay( const TokenOkay& _s )
{
}

ATLAS::TokenOkay::~TokenOkay()
{
}

ATLAS::TokenOkay&
ATLAS::TokenOkay::operator=( const TokenOkay& _s )
{
  return *this;
}
#endif

class _Marshaller_ATLAS_TokenOkay : public ::CORBA::StaticTypeInfo {
    typedef ::ATLAS::TokenOkay _MICO_T;
  public:
    ~_Marshaller_ATLAS_TokenOkay();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_ATLAS_TokenOkay::~_Marshaller_ATLAS_TokenOkay()
{
}

::CORBA::StaticValueType _Marshaller_ATLAS_TokenOkay::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_ATLAS_TokenOkay::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_ATLAS_TokenOkay::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_ATLAS_TokenOkay::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_ATLAS_TokenOkay::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/ATLAS/TokenOkay:1.0" );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_ATLAS_TokenOkay::typecode()
{
  return ATLAS::_tc_TokenOkay;
}

::CORBA::StaticTypeInfo *_marshaller_ATLAS_TokenOkay;

void operator<<=( CORBA::Any &_a, const ATLAS::TokenOkay &_e )
{
  CORBA::StaticAny _sa (_marshaller_ATLAS_TokenOkay, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, ATLAS::TokenOkay *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, ATLAS::TokenOkay &_e )
{
  CORBA::StaticAny _sa (_marshaller_ATLAS_TokenOkay, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const ATLAS::TokenOkay *&_e )
{
  return _a.to_static_any (_marshaller_ATLAS_TokenOkay, (void *&)_e);
}

void ATLAS::TokenOkay::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw TokenOkay_var( (ATLAS::TokenOkay*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *ATLAS::TokenOkay::_repoid() const
{
  return "IDL:omg.org/ATLAS/TokenOkay:1.0";
}

void ATLAS::TokenOkay::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_ATLAS_TokenOkay->marshal( _en, (void*) this );
}

void ATLAS::TokenOkay::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *ATLAS::TokenOkay::_clone() const
{
  return new TokenOkay( *this );
}

ATLAS::TokenOkay *ATLAS::TokenOkay::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/ATLAS/TokenOkay:1.0" ) )
    return (TokenOkay *) _ex;
  return NULL;
}

const ATLAS::TokenOkay *ATLAS::TokenOkay::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/ATLAS/TokenOkay:1.0" ) )
    return (TokenOkay *) _ex;
  return NULL;
}


/*
 * Base interface for class AuthTokenDispenser
 */

ATLAS::AuthTokenDispenser::~AuthTokenDispenser()
{
}

void *
ATLAS::AuthTokenDispenser::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/ATLAS/AuthTokenDispenser:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

ATLAS::AuthTokenDispenser_ptr
ATLAS::AuthTokenDispenser::_narrow( CORBA::Object_ptr _obj )
{
  ATLAS::AuthTokenDispenser_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/ATLAS/AuthTokenDispenser:1.0" )))
      return _duplicate( (ATLAS::AuthTokenDispenser_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/ATLAS/AuthTokenDispenser:1.0") || _obj->_is_a_remote ("IDL:omg.org/ATLAS/AuthTokenDispenser:1.0")) {
      _o = new ATLAS::AuthTokenDispenser_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

ATLAS::AuthTokenDispenser_ptr
ATLAS::AuthTokenDispenser::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace ATLAS
{
CORBA::TypeCodeConst _tc_AuthTokenDispenser;
}
class _Marshaller_ATLAS_AuthTokenDispenser : public ::CORBA::StaticTypeInfo {
    typedef ATLAS::AuthTokenDispenser_ptr _MICO_T;
  public:
    ~_Marshaller_ATLAS_AuthTokenDispenser();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_ATLAS_AuthTokenDispenser::~_Marshaller_ATLAS_AuthTokenDispenser()
{
}

::CORBA::StaticValueType _Marshaller_ATLAS_AuthTokenDispenser::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_ATLAS_AuthTokenDispenser::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::ATLAS::AuthTokenDispenser::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_ATLAS_AuthTokenDispenser::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_ATLAS_AuthTokenDispenser::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_ATLAS_AuthTokenDispenser::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::ATLAS::AuthTokenDispenser::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_ATLAS_AuthTokenDispenser::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::TypeCode_ptr _Marshaller_ATLAS_AuthTokenDispenser::typecode()
{
  return ATLAS::_tc_AuthTokenDispenser;
}

::CORBA::StaticTypeInfo *_marshaller_ATLAS_AuthTokenDispenser;

void
operator<<=( CORBA::Any &_a, const ATLAS::AuthTokenDispenser_ptr _obj )
{
  CORBA::StaticAny _sa (_marshaller_ATLAS_AuthTokenDispenser, &_obj);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, ATLAS::AuthTokenDispenser_ptr* _obj_ptr )
{
  CORBA::StaticAny _sa (_marshaller_ATLAS_AuthTokenDispenser, _obj_ptr);
  _a.from_static_any (_sa);
  CORBA::release (*_obj_ptr);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, ATLAS::AuthTokenDispenser_ptr &_obj )
{
  ATLAS::AuthTokenDispenser_ptr *p;
  if (_a.to_static_any (_marshaller_ATLAS_AuthTokenDispenser, (void *&)p)) {
    _obj = *p;
    return TRUE;
  }
  return FALSE;
}


/*
 * Stub interface for class AuthTokenDispenser
 */

ATLAS::AuthTokenDispenser_stub::~AuthTokenDispenser_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_ATLAS::AuthTokenDispenser::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/ATLAS/AuthTokenDispenser:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_ATLAS::AuthTokenDispenser *
POA_ATLAS::AuthTokenDispenser::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/ATLAS/AuthTokenDispenser:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_ATLAS::AuthTokenDispenser *) p;
  }
  return NULL;
}

ATLAS::AuthTokenDispenser_stub_clp::AuthTokenDispenser_stub_clp ()
{
}

ATLAS::AuthTokenDispenser_stub_clp::AuthTokenDispenser_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

ATLAS::AuthTokenDispenser_stub_clp::~AuthTokenDispenser_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

ATLAS::AuthTokenData* ATLAS::AuthTokenDispenser_stub::get_my_authorization_token()
{
  CORBA::StaticAny __res( _marshaller_ATLAS_AuthTokenData );

  CORBA::StaticRequest __req( this, "get_my_authorization_token" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_ATLAS_IllegalTokenRequest, "IDL:omg.org/ATLAS/IllegalTokenRequest:1.0",
    0);
  return (ATLAS::AuthTokenData*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

ATLAS::AuthTokenData*
ATLAS::AuthTokenDispenser_stub_clp::get_my_authorization_token()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ATLAS::AuthTokenDispenser * _myserv = POA_ATLAS::AuthTokenDispenser::_narrow (_serv);
    if (_myserv) {
      ATLAS::AuthTokenData* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->get_my_authorization_token();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ATLAS::AuthTokenDispenser_stub::get_my_authorization_token();
}

#endif // MICO_CONF_NO_POA

ATLAS::AuthTokenData* ATLAS::AuthTokenDispenser_stub::translate_authorization_token( const CSI::IdentityToken& _par_the_subject, const CSI::AuthorizationToken& _par_the_token )
{
  CORBA::StaticAny _sa_the_subject( _marshaller_CSI_IdentityToken, &_par_the_subject );
  CORBA::StaticAny _sa_the_token( _marshaller__seq_CSI_AuthorizationElement, &_par_the_token );
  CORBA::StaticAny __res( _marshaller_ATLAS_AuthTokenData );

  CORBA::StaticRequest __req( this, "translate_authorization_token" );
  __req.add_in_arg( &_sa_the_subject );
  __req.add_in_arg( &_sa_the_token );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_ATLAS_IllegalTokenRequest, "IDL:omg.org/ATLAS/IllegalTokenRequest:1.0",
    _marshaller_ATLAS_TokenOkay, "IDL:omg.org/ATLAS/TokenOkay:1.0",
    0);
  return (ATLAS::AuthTokenData*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

ATLAS::AuthTokenData*
ATLAS::AuthTokenDispenser_stub_clp::translate_authorization_token( const CSI::IdentityToken& _par_the_subject, const CSI::AuthorizationToken& _par_the_token )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ATLAS::AuthTokenDispenser * _myserv = POA_ATLAS::AuthTokenDispenser::_narrow (_serv);
    if (_myserv) {
      ATLAS::AuthTokenData* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->translate_authorization_token(_par_the_subject, _par_the_token);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ATLAS::AuthTokenDispenser_stub::translate_authorization_token(_par_the_subject, _par_the_token);
}

#endif // MICO_CONF_NO_POA

namespace ATLAS
{
CORBA::TypeCodeConst _tc_UTF8String;
}

namespace ATLAS
{
CORBA::TypeCodeConst _tc_ATLASLocatorType;
}

namespace ATLAS
{
CORBA::TypeCodeConst _tc_ATLASLocator;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
ATLAS::ATLASLocator::ATLASLocator()
{
}

ATLAS::ATLASLocator::ATLASLocator( const ATLASLocator&_u )
{
  _discriminator = _u._discriminator;
  _m.the_dispenser = ((ATLASLocator&)_u)._m.the_dispenser;
}

ATLAS::ATLASLocator::~ATLASLocator()
{
}

ATLAS::ATLASLocator&
ATLAS::ATLASLocator::operator=( const ATLASLocator&_u )
{
  _discriminator = _u._discriminator;
  _m.the_dispenser = ((ATLASLocator&)_u)._m.the_dispenser;
  return *this;
}
#endif

void ATLAS::ATLASLocator::_d( ATLAS::ATLASLocatorType _p )
{
  _discriminator = _p;
}

ATLAS::ATLASLocatorType ATLAS::ATLASLocator::_d() const
{
  return _discriminator;
}

void ATLAS::ATLASLocator::the_dispenser( ATLAS::AuthTokenDispenser_ptr _p )
{
  _discriminator = 3;
  _m.the_dispenser = ::ATLAS::AuthTokenDispenser::_duplicate( _p );
}

ATLAS::AuthTokenDispenser_ptr ATLAS::ATLASLocator::the_dispenser() const
{
  return _m.the_dispenser.in();
}

void ATLAS::ATLASLocator::_default()
{
  _discriminator = 0;
}

class _Marshaller_ATLAS_ATLASLocator : public ::CORBA::StaticTypeInfo {
    typedef ATLAS::ATLASLocator _MICO_T;
  public:
    ~_Marshaller_ATLAS_ATLASLocator();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_ATLAS_ATLASLocator::~_Marshaller_ATLAS_ATLASLocator()
{
}

::CORBA::StaticValueType _Marshaller_ATLAS_ATLASLocator::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_ATLAS_ATLASLocator::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_ATLAS_ATLASLocator::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_ATLAS_ATLASLocator::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  if( !dc.union_begin() )
    return FALSE;
  if( !CORBA::_stc_ulong->demarshal( dc, &((_MICO_T *) v)->_discriminator ) )
    return FALSE;
  switch( ((_MICO_T *) v)->_discriminator ) {
    case 3:
      if( !_marshaller_ATLAS_AuthTokenDispenser->demarshal( dc, &((_MICO_T *) v)->_m.the_dispenser._for_demarshal() ) )
        return FALSE;
      break;
  }
  return dc.union_end();
}

void _Marshaller_ATLAS_ATLASLocator::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.union_begin();
  CORBA::_stc_ulong->marshal( ec, &((_MICO_T *) v)->_discriminator );
  switch( ((_MICO_T *) v)->_discriminator ) {
    case 3:
      _marshaller_ATLAS_AuthTokenDispenser->marshal( ec, &((_MICO_T *) v)->_m.the_dispenser.inout() );
      break;
  }
  ec.union_end();
}

::CORBA::TypeCode_ptr _Marshaller_ATLAS_ATLASLocator::typecode()
{
  return ATLAS::_tc_ATLASLocator;
}

::CORBA::StaticTypeInfo *_marshaller_ATLAS_ATLASLocator;

void operator<<=( CORBA::Any &_a, const ATLAS::ATLASLocator &_u )
{
  CORBA::StaticAny _sa (_marshaller_ATLAS_ATLASLocator, &_u);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, ATLAS::ATLASLocator *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, ATLAS::ATLASLocator &_u )
{
  CORBA::StaticAny _sa (_marshaller_ATLAS_ATLASLocator, &_u);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const ATLAS::ATLASLocator *&_u )
{
  return _a.to_static_any (_marshaller_ATLAS_ATLASLocator, (void *&)_u);
}

namespace ATLAS
{
CORBA::TypeCodeConst _tc_ATLASCacheId;
}

namespace ATLAS
{
CORBA::TypeCodeConst _tc_ATLASProfile;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
ATLAS::ATLASProfile::ATLASProfile()
{
}

ATLAS::ATLASProfile::ATLASProfile( const ATLASProfile& _s )
{
  the_locator = ((ATLASProfile&)_s).the_locator;
  the_cache_id = ((ATLASProfile&)_s).the_cache_id;
}

ATLAS::ATLASProfile::~ATLASProfile()
{
}

ATLAS::ATLASProfile&
ATLAS::ATLASProfile::operator=( const ATLASProfile& _s )
{
  the_locator = ((ATLASProfile&)_s).the_locator;
  the_cache_id = ((ATLASProfile&)_s).the_cache_id;
  return *this;
}
#endif

class _Marshaller_ATLAS_ATLASProfile : public ::CORBA::StaticTypeInfo {
    typedef ATLAS::ATLASProfile _MICO_T;
  public:
    ~_Marshaller_ATLAS_ATLASProfile();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_ATLAS_ATLASProfile::~_Marshaller_ATLAS_ATLASProfile()
{
}

::CORBA::StaticValueType _Marshaller_ATLAS_ATLASProfile::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_ATLAS_ATLASProfile::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_ATLAS_ATLASProfile::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_ATLAS_ATLASProfile::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    _marshaller_ATLAS_ATLASLocator->demarshal( dc, &((_MICO_T*)v)->the_locator ) &&
    CORBA::_stcseq_octet->demarshal( dc, &((_MICO_T*)v)->the_cache_id ) &&
    dc.struct_end();
}

void _Marshaller_ATLAS_ATLASProfile::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  _marshaller_ATLAS_ATLASLocator->marshal( ec, &((_MICO_T*)v)->the_locator );
  CORBA::_stcseq_octet->marshal( ec, &((_MICO_T*)v)->the_cache_id );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_ATLAS_ATLASProfile::typecode()
{
  return ATLAS::_tc_ATLASProfile;
}

::CORBA::StaticTypeInfo *_marshaller_ATLAS_ATLASProfile;

void operator<<=( CORBA::Any &_a, const ATLAS::ATLASProfile &_s )
{
  CORBA::StaticAny _sa (_marshaller_ATLAS_ATLASProfile, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, ATLAS::ATLASProfile *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, ATLAS::ATLASProfile &_s )
{
  CORBA::StaticAny _sa (_marshaller_ATLAS_ATLASProfile, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const ATLAS::ATLASProfile *&_s )
{
  return _a.to_static_any (_marshaller_ATLAS_ATLASProfile, (void *&)_s);
}

class _Marshaller__seq_1b_TimeBase_UtcT : public ::CORBA::StaticTypeInfo {
    typedef BoundedSequenceTmpl< TimeBase::UtcT,MICO_TID_DEF,1> _MICO_T;
    static ::CORBA::TypeCode_ptr _tc;
  public:
    ~_Marshaller__seq_1b_TimeBase_UtcT();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller__seq_1b_TimeBase_UtcT::~_Marshaller__seq_1b_TimeBase_UtcT()
{
  if (_tc)
    delete _tc;
}

::CORBA::StaticValueType _Marshaller__seq_1b_TimeBase_UtcT::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_1b_TimeBase_UtcT::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_1b_TimeBase_UtcT::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_1b_TimeBase_UtcT::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_TimeBase_UtcT->demarshal( dc, &(*(_MICO_T*)v)[i] ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_1b_TimeBase_UtcT::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_TimeBase_UtcT->marshal( ec, &(*(_MICO_T*)v)[i] );
  ec.seq_end();
}

::CORBA::TypeCode_ptr _Marshaller__seq_1b_TimeBase_UtcT::typecode()
{
  if (!_tc)
    _tc = (new ::CORBA::TypeCode (
    "0100000013000000fc000000010000000f000000ec000000010000001e00"
    "000049444c3a6f6d672e6f72672f54696d65426173652f557463543a312e"
    "30000000050000005574635400000000040000000500000074696d650000"
    "00001500000038000000010000001f00000049444c3a6f6d672e6f72672f"
    "54696d65426173652f54696d65543a312e3000000600000054696d655400"
    "00001800000008000000696e6163636c6f000500000008000000696e6163"
    "636869000400000004000000746466001500000038000000010000001e00"
    "000049444c3a6f6d672e6f72672f54696d65426173652f546466543a312e"
    "300000000500000054646654000000000200000001000000"))->mk_constant();
  return _tc;
}

::CORBA::TypeCode_ptr _Marshaller__seq_1b_TimeBase_UtcT::_tc = 0;
::CORBA::StaticTypeInfo *_marshaller__seq_1b_TimeBase_UtcT;

void operator<<=( CORBA::Any &_a, const BoundedSequenceTmpl< TimeBase::UtcT,MICO_TID_DEF,1> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_1b_TimeBase_UtcT, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, BoundedSequenceTmpl< TimeBase::UtcT,MICO_TID_DEF,1> *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, BoundedSequenceTmpl< TimeBase::UtcT,MICO_TID_DEF,1> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_1b_TimeBase_UtcT, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const BoundedSequenceTmpl< TimeBase::UtcT,MICO_TID_DEF,1> *&_s )
{
  return _a.to_static_any (_marshaller__seq_1b_TimeBase_UtcT, (void *&)_s);
}


class _Marshaller__seq_1b_CSI_IdentityToken : public ::CORBA::StaticTypeInfo {
    typedef BoundedSequenceTmpl< CSI::IdentityToken,MICO_TID_DEF,1> _MICO_T;
    static ::CORBA::TypeCode_ptr _tc;
  public:
    ~_Marshaller__seq_1b_CSI_IdentityToken();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller__seq_1b_CSI_IdentityToken::~_Marshaller__seq_1b_CSI_IdentityToken()
{
  if (_tc)
    delete _tc;
}

::CORBA::StaticValueType _Marshaller__seq_1b_CSI_IdentityToken::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_1b_CSI_IdentityToken::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_1b_CSI_IdentityToken::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_1b_CSI_IdentityToken::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_CSI_IdentityToken->demarshal( dc, &(*(_MICO_T*)v)[i] ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_1b_CSI_IdentityToken::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_CSI_IdentityToken->marshal( ec, &(*(_MICO_T*)v)[i] );
  ec.seq_end();
}

::CORBA::TypeCode_ptr _Marshaller__seq_1b_CSI_IdentityToken::typecode()
{
  if (!_tc)
    _tc = (new ::CORBA::TypeCode (
    "0100000013000000c40200000100000010000000b4020000010000002200"
    "000049444c3a6f6d672e6f72672f4353492f4964656e74697479546f6b65"
    "6e3a312e300000000e0000004964656e74697479546f6b656e0000001500"
    "00004c000000010000002600000049444c3a6f6d672e6f72672f4353492f"
    "4964656e74697479546f6b656e547970653a312e30000000120000004964"
    "656e74697479546f6b656e54797065000000050000000500000006000000"
    "0000000007000000616273656e74000008000000010000000a000000616e"
    "6f6e796d6f757300000008000000020000000f0000007072696e63697061"
    "6c5f6e616d650000150000005c000000010000002800000049444c3a6f6d"
    "672e6f72672f4353492f4753535f4e545f4578706f727465644e616d653a"
    "312e3000140000004753535f4e545f4578706f727465644e616d65001300"
    "00000c000000010000000a00000000000000040000001200000063657274"
    "696669636174655f636861696e0000001500000064000000010000002900"
    "000049444c3a6f6d672e6f72672f4353492f583530394365727469666963"
    "617465436861696e3a312e30000000001500000058353039436572746966"
    "6963617465436861696e00000000130000000c000000010000000a000000"
    "000000000800000003000000646e00001500000064000000010000002a00"
    "000049444c3a6f6d672e6f72672f4353492f5835303144697374696e6775"
    "69736865644e616d653a312e30000000160000005835303144697374696e"
    "677569736865644e616d65000000130000000c000000010000000a000000"
    "00000000000000000300000069640000150000005c000000010000002600"
    "000049444c3a6f6d672e6f72672f4353492f4964656e7469747945787465"
    "6e73696f6e3a312e30000000120000004964656e74697479457874656e73"
    "696f6e000000130000000c000000010000000a0000000000000001000000"
    ))->mk_constant();
  return _tc;
}

::CORBA::TypeCode_ptr _Marshaller__seq_1b_CSI_IdentityToken::_tc = 0;
::CORBA::StaticTypeInfo *_marshaller__seq_1b_CSI_IdentityToken;

void operator<<=( CORBA::Any &_a, const BoundedSequenceTmpl< CSI::IdentityToken,MICO_TID_DEF,1> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_1b_CSI_IdentityToken, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, BoundedSequenceTmpl< CSI::IdentityToken,MICO_TID_DEF,1> *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, BoundedSequenceTmpl< CSI::IdentityToken,MICO_TID_DEF,1> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_1b_CSI_IdentityToken, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const BoundedSequenceTmpl< CSI::IdentityToken,MICO_TID_DEF,1> *&_s )
{
  return _a.to_static_any (_marshaller__seq_1b_CSI_IdentityToken, (void *&)_s);
}


struct __tc_init_ATLAS {
  __tc_init_ATLAS()
  {
    ATLAS::_tc_ExpiryTime = 
    "010000001500000040010000010000002100000049444c3a6f6d672e6f72"
    "672f41544c41532f45787069727954696d653a312e30000000000b000000"
    "45787069727954696d65000013000000fc000000010000000f000000ec00"
    "0000010000001e00000049444c3a6f6d672e6f72672f54696d6542617365"
    "2f557463543a312e30000000050000005574635400000000040000000500"
    "000074696d65000000001500000038000000010000001f00000049444c3a"
    "6f6d672e6f72672f54696d65426173652f54696d65543a312e3000000600"
    "000054696d65540000001800000008000000696e6163636c6f0005000000"
    "08000000696e616363686900040000000400000074646600150000003800"
    "0000010000001e00000049444c3a6f6d672e6f72672f54696d6542617365"
    "2f546466543a312e30000000050000005464665400000000020000000100"
    "0000";
    ATLAS::_tc_IdTokenOption = 
    "01000000150000000c030000010000002400000049444c3a6f6d672e6f72"
    "672f41544c41532f4964546f6b656e4f7074696f6e3a312e30000e000000"
    "4964546f6b656e4f7074696f6e00000013000000c4020000010000001000"
    "0000b4020000010000002200000049444c3a6f6d672e6f72672f4353492f"
    "4964656e74697479546f6b656e3a312e300000000e0000004964656e7469"
    "7479546f6b656e000000150000004c000000010000002600000049444c3a"
    "6f6d672e6f72672f4353492f4964656e74697479546f6b656e547970653a"
    "312e30000000120000004964656e74697479546f6b656e54797065000000"
    "0500000005000000060000000000000007000000616273656e7400000800"
    "0000010000000a000000616e6f6e796d6f75730000000800000002000000"
    "0f0000007072696e636970616c5f6e616d650000150000005c0000000100"
    "00002800000049444c3a6f6d672e6f72672f4353492f4753535f4e545f45"
    "78706f727465644e616d653a312e3000140000004753535f4e545f457870"
    "6f727465644e616d6500130000000c000000010000000a00000000000000"
    "040000001200000063657274696669636174655f636861696e0000001500"
    "000064000000010000002900000049444c3a6f6d672e6f72672f4353492f"
    "583530394365727469666963617465436861696e3a312e30000000001500"
    "0000583530394365727469666963617465436861696e0000000013000000"
    "0c000000010000000a000000000000000800000003000000646e00001500"
    "000064000000010000002a00000049444c3a6f6d672e6f72672f4353492f"
    "5835303144697374696e677569736865644e616d653a312e300000001600"
    "00005835303144697374696e677569736865644e616d6500000013000000"
    "0c000000010000000a000000000000000000000003000000696400001500"
    "00005c000000010000002600000049444c3a6f6d672e6f72672f4353492f"
    "4964656e74697479457874656e73696f6e3a312e30000000120000004964"
    "656e74697479457874656e73696f6e000000130000000c00000001000000"
    "0a0000000000000001000000";
    ATLAS::_tc_AuthTokenData = 
    "010000000f0000008c060000010000002400000049444c3a6f6d672e6f72"
    "672f41544c41532f41757468546f6b656e446174613a312e30000e000000"
    "41757468546f6b656e44617461000000030000000c0000006964656e745f"
    "746f6b656e00150000000c030000010000002400000049444c3a6f6d672e"
    "6f72672f41544c41532f4964546f6b656e4f7074696f6e3a312e30000e00"
    "00004964546f6b656e4f7074696f6e00000013000000c402000001000000"
    "10000000b4020000010000002200000049444c3a6f6d672e6f72672f4353"
    "492f4964656e74697479546f6b656e3a312e300000000e0000004964656e"
    "74697479546f6b656e000000150000004c00000001000000260000004944"
    "4c3a6f6d672e6f72672f4353492f4964656e74697479546f6b656e547970"
    "653a312e30000000120000004964656e74697479546f6b656e5479706500"
    "00000500000005000000060000000000000007000000616273656e740000"
    "08000000010000000a000000616e6f6e796d6f7573000000080000000200"
    "00000f0000007072696e636970616c5f6e616d650000150000005c000000"
    "010000002800000049444c3a6f6d672e6f72672f4353492f4753535f4e54"
    "5f4578706f727465644e616d653a312e3000140000004753535f4e545f45"
    "78706f727465644e616d6500130000000c000000010000000a0000000000"
    "0000040000001200000063657274696669636174655f636861696e000000"
    "1500000064000000010000002900000049444c3a6f6d672e6f72672f4353"
    "492f583530394365727469666963617465436861696e3a312e3000000000"
    "15000000583530394365727469666963617465436861696e000000001300"
    "00000c000000010000000a000000000000000800000003000000646e0000"
    "1500000064000000010000002a00000049444c3a6f6d672e6f72672f4353"
    "492f5835303144697374696e677569736865644e616d653a312e30000000"
    "160000005835303144697374696e677569736865644e616d650000001300"
    "00000c000000010000000a00000000000000000000000300000069640000"
    "150000005c000000010000002600000049444c3a6f6d672e6f72672f4353"
    "492f4964656e74697479457874656e73696f6e3a312e3000000012000000"
    "4964656e74697479457874656e73696f6e000000130000000c0000000100"
    "00000a00000000000000010000000b000000617574685f746f6b656e0000"
    "15000000b4010000010000002700000049444c3a6f6d672e6f72672f4353"
    "492f417574686f72697a6174696f6e546f6b656e3a312e30000013000000"
    "417574686f72697a6174696f6e546f6b656e000013000000640100000100"
    "00000f00000054010000010000002900000049444c3a6f6d672e6f72672f"
    "4353492f417574686f72697a6174696f6e456c656d656e743a312e300000"
    "000015000000417574686f72697a6174696f6e456c656d656e7400000000"
    "02000000090000007468655f7479706500000000150000005c0000000100"
    "00002d00000049444c3a6f6d672e6f72672f4353492f417574686f72697a"
    "6174696f6e456c656d656e74547970653a312e3000000000190000004175"
    "74686f72697a6174696f6e456c656d656e74547970650000000005000000"
    "0c0000007468655f656c656d656e74001500000074000000010000003100"
    "000049444c3a6f6d672e6f72672f4353492f417574686f72697a6174696f"
    "6e456c656d656e74436f6e74656e74733a312e30000000001d0000004175"
    "74686f72697a6174696f6e456c656d656e74436f6e74656e747300000000"
    "130000000c000000010000000a00000000000000000000000c0000006578"
    "706972795f74696d65001500000040010000010000002100000049444c3a"
    "6f6d672e6f72672f41544c41532f45787069727954696d653a312e300000"
    "00000b00000045787069727954696d65000013000000fc00000001000000"
    "0f000000ec000000010000001e00000049444c3a6f6d672e6f72672f5469"
    "6d65426173652f557463543a312e30000000050000005574635400000000"
    "040000000500000074696d65000000001500000038000000010000001f00"
    "000049444c3a6f6d672e6f72672f54696d65426173652f54696d65543a31"
    "2e3000000600000054696d65540000001800000008000000696e6163636c"
    "6f000500000008000000696e616363686900040000000400000074646600"
    "1500000038000000010000001e00000049444c3a6f6d672e6f72672f5469"
    "6d65426173652f546466543a312e30000000050000005464665400000000"
    "0200000001000000";
    _marshaller_ATLAS_AuthTokenData = new _Marshaller_ATLAS_AuthTokenData;
    ATLAS::_tc_IllegalTokenRequest = 
    "01000000160000007c000000010000002a00000049444c3a6f6d672e6f72"
    "672f41544c41532f496c6c6567616c546f6b656e526571756573743a312e"
    "3000000014000000496c6c6567616c546f6b656e52657175657374000200"
    "00000b0000007468655f6572726e756d0000050000000b0000007468655f"
    "726561736f6e00001200000000000000";
    _marshaller_ATLAS_IllegalTokenRequest = new _Marshaller_ATLAS_IllegalTokenRequest;
    ATLAS::_tc_TokenOkay = 
    "01000000160000003c000000010000002000000049444c3a6f6d672e6f72"
    "672f41544c41532f546f6b656e4f6b61793a312e30000a000000546f6b65"
    "6e4f6b617900000000000000";
    _marshaller_ATLAS_TokenOkay = new _Marshaller_ATLAS_TokenOkay;
    ATLAS::_tc_AuthTokenDispenser = 
    "010000000e0000004b000000010000002900000049444c3a6f6d672e6f72"
    "672f41544c41532f41757468546f6b656e44697370656e7365723a312e30"
    "000000001300000041757468546f6b656e44697370656e73657200";
    _marshaller_ATLAS_AuthTokenDispenser = new _Marshaller_ATLAS_AuthTokenDispenser;
    ATLAS::_tc_UTF8String = 
    "010000001500000050000000010000002100000049444c3a6f6d672e6f72"
    "672f41544c41532f55544638537472696e673a312e30000000000b000000"
    "55544638537472696e670000130000000c000000010000000a0000000000"
    "0000";
    ATLAS::_tc_ATLASLocatorType = 
    "01000000150000004c000000010000002700000049444c3a6f6d672e6f72"
    "672f41544c41532f41544c41534c6f6361746f72547970653a312e300000"
    "1100000041544c41534c6f6361746f72547970650000000005000000";
    ATLAS::_tc_ATLASLocator = 
    "010000001000000007010000010000002300000049444c3a6f6d672e6f72"
    "672f41544c41532f41544c41534c6f6361746f723a312e3000000d000000"
    "41544c41534c6f6361746f7200000000150000004c000000010000002700"
    "000049444c3a6f6d672e6f72672f41544c41532f41544c41534c6f636174"
    "6f72547970653a312e3000001100000041544c41534c6f6361746f725479"
    "70650000000005000000ffffffff01000000030000000e0000007468655f"
    "64697370656e7365720000000e0000004b00000001000000290000004944"
    "4c3a6f6d672e6f72672f41544c41532f41757468546f6b656e4469737065"
    "6e7365723a312e30000000001300000041757468546f6b656e4469737065"
    "6e73657200";
    _marshaller_ATLAS_ATLASLocator = new _Marshaller_ATLAS_ATLASLocator;
    ATLAS::_tc_ATLASCacheId = 
    "010000001500000054000000010000002300000049444c3a6f6d672e6f72"
    "672f41544c41532f41544c4153436163686549643a312e3000000d000000"
    "41544c41534361636865496400000000130000000c000000010000000a00"
    "000000000000";
    ATLAS::_tc_ATLASProfile = 
    "010000000f000000d4010000010000002300000049444c3a6f6d672e6f72"
    "672f41544c41532f41544c415350726f66696c653a312e3000000d000000"
    "41544c415350726f66696c6500000000020000000c0000007468655f6c6f"
    "6361746f72001000000007010000010000002300000049444c3a6f6d672e"
    "6f72672f41544c41532f41544c41534c6f6361746f723a312e3000000d00"
    "000041544c41534c6f6361746f7200000000150000004c00000001000000"
    "2700000049444c3a6f6d672e6f72672f41544c41532f41544c41534c6f63"
    "61746f72547970653a312e3000001100000041544c41534c6f6361746f72"
    "547970650000000005000000ffffffff01000000030000000e0000007468"
    "655f64697370656e7365720000000e0000004b0000000100000029000000"
    "49444c3a6f6d672e6f72672f41544c41532f41757468546f6b656e446973"
    "70656e7365723a312e30000000001300000041757468546f6b656e446973"
    "70656e73657200000d0000007468655f63616368655f6964000000001500"
    "000054000000010000002300000049444c3a6f6d672e6f72672f41544c41"
    "532f41544c4153436163686549643a312e3000000d00000041544c415343"
    "61636865496400000000130000000c000000010000000a00000000000000"
    ;
    _marshaller_ATLAS_ATLASProfile = new _Marshaller_ATLAS_ATLASProfile;
    _marshaller__seq_1b_TimeBase_UtcT = new _Marshaller__seq_1b_TimeBase_UtcT;
    _marshaller__seq_1b_CSI_IdentityToken = new _Marshaller__seq_1b_CSI_IdentityToken;
  }

  ~__tc_init_ATLAS()
  {
    delete static_cast<_Marshaller_ATLAS_AuthTokenData*>(_marshaller_ATLAS_AuthTokenData);
    delete static_cast<_Marshaller_ATLAS_IllegalTokenRequest*>(_marshaller_ATLAS_IllegalTokenRequest);
    delete static_cast<_Marshaller_ATLAS_TokenOkay*>(_marshaller_ATLAS_TokenOkay);
    delete static_cast<_Marshaller_ATLAS_AuthTokenDispenser*>(_marshaller_ATLAS_AuthTokenDispenser);
    delete static_cast<_Marshaller_ATLAS_ATLASLocator*>(_marshaller_ATLAS_ATLASLocator);
    delete static_cast<_Marshaller_ATLAS_ATLASProfile*>(_marshaller_ATLAS_ATLASProfile);
    delete static_cast<_Marshaller__seq_1b_TimeBase_UtcT*>(_marshaller__seq_1b_TimeBase_UtcT);
    delete static_cast<_Marshaller__seq_1b_CSI_IdentityToken*>(_marshaller__seq_1b_CSI_IdentityToken);
  }
};

static __tc_init_ATLAS __init_ATLAS;

//--------------------------------------------------------
//  Implementation of skeletons
//--------------------------------------------------------

// PortableServer Skeleton Class for interface ATLAS::AuthTokenDispenser
POA_ATLAS::AuthTokenDispenser::~AuthTokenDispenser()
{
}

::ATLAS::AuthTokenDispenser_ptr
POA_ATLAS::AuthTokenDispenser::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::ATLAS::AuthTokenDispenser::_narrow (obj);
}

CORBA::Boolean
POA_ATLAS::AuthTokenDispenser::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/ATLAS/AuthTokenDispenser:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_ATLAS::AuthTokenDispenser::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/ATLAS/AuthTokenDispenser:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_ATLAS::AuthTokenDispenser::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/ATLAS/AuthTokenDispenser:1.0");
}

CORBA::Object_ptr
POA_ATLAS::AuthTokenDispenser::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::ATLAS::AuthTokenDispenser_stub_clp (poa, obj);
}

bool
POA_ATLAS::AuthTokenDispenser::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "get_my_authorization_token" ) == 0 ) {
      ::ATLAS::AuthTokenData* _res;
      CORBA::StaticAny __res( _marshaller_ATLAS_AuthTokenData );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _res = get_my_authorization_token();
        __res.value( _marshaller_ATLAS_AuthTokenData, _res );
      #ifdef HAVE_EXCEPTIONS
      } catch( ::ATLAS::IllegalTokenRequest_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      }
      #endif
      __req->write_results();
      delete _res;
      return true;
    }
    if( strcmp( __req->op_name(), "translate_authorization_token" ) == 0 ) {
      ::CSI::IdentityToken _par_the_subject;
      CORBA::StaticAny _sa_the_subject( _marshaller_CSI_IdentityToken, &_par_the_subject );
      ::CSI::AuthorizationToken _par_the_token;
      CORBA::StaticAny _sa_the_token( _marshaller__seq_CSI_AuthorizationElement, &_par_the_token );

      ::ATLAS::AuthTokenData* _res;
      CORBA::StaticAny __res( _marshaller_ATLAS_AuthTokenData );
      __req->add_in_arg( &_sa_the_subject );
      __req->add_in_arg( &_sa_the_token );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _res = translate_authorization_token( _par_the_subject, _par_the_token );
        __res.value( _marshaller_ATLAS_AuthTokenData, _res );
      #ifdef HAVE_EXCEPTIONS
      } catch( ::ATLAS::IllegalTokenRequest_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      } catch( ::ATLAS::TokenOkay_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      }
      #endif
      __req->write_results();
      delete _res;
      return true;
    }
  #ifdef HAVE_EXCEPTIONS
  } catch( CORBA::SystemException_catch &_ex ) {
    __req->set_exception( _ex->_clone() );
    __req->write_results();
    return true;
  } catch( ... ) {
    CORBA::UNKNOWN _ex (CORBA::OMGVMCID | 1, CORBA::COMPLETED_MAYBE);
    __req->set_exception (_ex->_clone());
    __req->write_results ();
    return true;
  }
  #endif

  return false;
}

void
POA_ATLAS::AuthTokenDispenser::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}

