/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CosEventComm.h>


using namespace std;

//--------------------------------------------------------
//  Implementation of stubs
//--------------------------------------------------------

#ifdef HAVE_EXPLICIT_STRUCT_OPS
CosEventComm::Disconnected::Disconnected()
{
}

CosEventComm::Disconnected::Disconnected( const Disconnected& _s )
{
}

CosEventComm::Disconnected::~Disconnected()
{
}

CosEventComm::Disconnected&
CosEventComm::Disconnected::operator=( const Disconnected& _s )
{
  return *this;
}
#endif

class _Marshaller_CosEventComm_Disconnected : public ::CORBA::StaticTypeInfo {
    typedef ::CosEventComm::Disconnected _MICO_T;
  public:
    ~_Marshaller_CosEventComm_Disconnected();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosEventComm_Disconnected::~_Marshaller_CosEventComm_Disconnected()
{
}

::CORBA::StaticValueType _Marshaller_CosEventComm_Disconnected::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosEventComm_Disconnected::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosEventComm_Disconnected::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosEventComm_Disconnected::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_CosEventComm_Disconnected::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/CosEventComm/Disconnected:1.0" );
  ec.except_end();
}

::CORBA::StaticTypeInfo *_marshaller_CosEventComm_Disconnected;

void CosEventComm::Disconnected::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw Disconnected_var( (CosEventComm::Disconnected*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *CosEventComm::Disconnected::_repoid() const
{
  return "IDL:omg.org/CosEventComm/Disconnected:1.0";
}

void CosEventComm::Disconnected::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_CosEventComm_Disconnected->marshal( _en, (void*) this );
}

void CosEventComm::Disconnected::_encode_any( CORBA::Any & ) const
{
  // use --any to make this work!
  assert(0);
}

CORBA::Exception *CosEventComm::Disconnected::_clone() const
{
  return new Disconnected( *this );
}

CosEventComm::Disconnected *CosEventComm::Disconnected::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosEventComm/Disconnected:1.0" ) )
    return (Disconnected *) _ex;
  return NULL;
}

const CosEventComm::Disconnected *CosEventComm::Disconnected::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosEventComm/Disconnected:1.0" ) )
    return (Disconnected *) _ex;
  return NULL;
}


/*
 * Base interface for class PushConsumer
 */

CosEventComm::PushConsumer::~PushConsumer()
{
}

void *
CosEventComm::PushConsumer::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosEventComm/PushConsumer:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

CosEventComm::PushConsumer_ptr
CosEventComm::PushConsumer::_narrow( CORBA::Object_ptr _obj )
{
  CosEventComm::PushConsumer_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosEventComm/PushConsumer:1.0" )))
      return _duplicate( (CosEventComm::PushConsumer_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosEventComm/PushConsumer:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosEventComm/PushConsumer:1.0")) {
      _o = new CosEventComm::PushConsumer_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosEventComm::PushConsumer_ptr
CosEventComm::PushConsumer::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosEventComm_PushConsumer : public ::CORBA::StaticTypeInfo {
    typedef CosEventComm::PushConsumer_ptr _MICO_T;
  public:
    ~_Marshaller_CosEventComm_PushConsumer();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosEventComm_PushConsumer::~_Marshaller_CosEventComm_PushConsumer()
{
}

::CORBA::StaticValueType _Marshaller_CosEventComm_PushConsumer::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosEventComm_PushConsumer::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosEventComm::PushConsumer::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosEventComm_PushConsumer::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosEventComm_PushConsumer::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosEventComm_PushConsumer::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosEventComm::PushConsumer::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosEventComm_PushConsumer::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosEventComm_PushConsumer;


/*
 * Stub interface for class PushConsumer
 */

CosEventComm::PushConsumer_stub::~PushConsumer_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosEventComm::PushConsumer::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventComm/PushConsumer:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_CosEventComm::PushConsumer *
POA_CosEventComm::PushConsumer::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosEventComm/PushConsumer:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosEventComm::PushConsumer *) p;
  }
  return NULL;
}

CosEventComm::PushConsumer_stub_clp::PushConsumer_stub_clp ()
{
}

CosEventComm::PushConsumer_stub_clp::PushConsumer_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosEventComm::PushConsumer_stub_clp::~PushConsumer_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

void CosEventComm::PushConsumer_stub::push( const CORBA::Any& _par_data )
{
  CORBA::StaticAny _sa_data( CORBA::_stc_any, &_par_data );
  CORBA::StaticRequest __req( this, "push" );
  __req.add_in_arg( &_sa_data );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosEventComm_Disconnected, "IDL:omg.org/CosEventComm/Disconnected:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosEventComm::PushConsumer_stub_clp::push( const CORBA::Any& _par_data )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventComm::PushConsumer * _myserv = POA_CosEventComm::PushConsumer::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->push(_par_data);
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
      return;
    }
    _postinvoke ();
  }

  CosEventComm::PushConsumer_stub::push(_par_data);
}

#endif // MICO_CONF_NO_POA

void CosEventComm::PushConsumer_stub::disconnect_push_consumer()
{
  CORBA::StaticRequest __req( this, "disconnect_push_consumer" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosEventComm::PushConsumer_stub_clp::disconnect_push_consumer()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventComm::PushConsumer * _myserv = POA_CosEventComm::PushConsumer::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->disconnect_push_consumer();
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
      return;
    }
    _postinvoke ();
  }

  CosEventComm::PushConsumer_stub::disconnect_push_consumer();
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class PushSupplier
 */

CosEventComm::PushSupplier::~PushSupplier()
{
}

void *
CosEventComm::PushSupplier::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosEventComm/PushSupplier:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

CosEventComm::PushSupplier_ptr
CosEventComm::PushSupplier::_narrow( CORBA::Object_ptr _obj )
{
  CosEventComm::PushSupplier_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosEventComm/PushSupplier:1.0" )))
      return _duplicate( (CosEventComm::PushSupplier_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosEventComm/PushSupplier:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosEventComm/PushSupplier:1.0")) {
      _o = new CosEventComm::PushSupplier_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosEventComm::PushSupplier_ptr
CosEventComm::PushSupplier::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosEventComm_PushSupplier : public ::CORBA::StaticTypeInfo {
    typedef CosEventComm::PushSupplier_ptr _MICO_T;
  public:
    ~_Marshaller_CosEventComm_PushSupplier();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosEventComm_PushSupplier::~_Marshaller_CosEventComm_PushSupplier()
{
}

::CORBA::StaticValueType _Marshaller_CosEventComm_PushSupplier::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosEventComm_PushSupplier::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosEventComm::PushSupplier::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosEventComm_PushSupplier::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosEventComm_PushSupplier::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosEventComm_PushSupplier::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosEventComm::PushSupplier::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosEventComm_PushSupplier::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosEventComm_PushSupplier;


/*
 * Stub interface for class PushSupplier
 */

CosEventComm::PushSupplier_stub::~PushSupplier_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosEventComm::PushSupplier::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventComm/PushSupplier:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_CosEventComm::PushSupplier *
POA_CosEventComm::PushSupplier::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosEventComm/PushSupplier:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosEventComm::PushSupplier *) p;
  }
  return NULL;
}

CosEventComm::PushSupplier_stub_clp::PushSupplier_stub_clp ()
{
}

CosEventComm::PushSupplier_stub_clp::PushSupplier_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosEventComm::PushSupplier_stub_clp::~PushSupplier_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

void CosEventComm::PushSupplier_stub::disconnect_push_supplier()
{
  CORBA::StaticRequest __req( this, "disconnect_push_supplier" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosEventComm::PushSupplier_stub_clp::disconnect_push_supplier()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventComm::PushSupplier * _myserv = POA_CosEventComm::PushSupplier::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->disconnect_push_supplier();
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
      return;
    }
    _postinvoke ();
  }

  CosEventComm::PushSupplier_stub::disconnect_push_supplier();
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class PullSupplier
 */

CosEventComm::PullSupplier::~PullSupplier()
{
}

void *
CosEventComm::PullSupplier::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosEventComm/PullSupplier:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

CosEventComm::PullSupplier_ptr
CosEventComm::PullSupplier::_narrow( CORBA::Object_ptr _obj )
{
  CosEventComm::PullSupplier_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosEventComm/PullSupplier:1.0" )))
      return _duplicate( (CosEventComm::PullSupplier_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosEventComm/PullSupplier:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosEventComm/PullSupplier:1.0")) {
      _o = new CosEventComm::PullSupplier_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosEventComm::PullSupplier_ptr
CosEventComm::PullSupplier::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosEventComm_PullSupplier : public ::CORBA::StaticTypeInfo {
    typedef CosEventComm::PullSupplier_ptr _MICO_T;
  public:
    ~_Marshaller_CosEventComm_PullSupplier();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosEventComm_PullSupplier::~_Marshaller_CosEventComm_PullSupplier()
{
}

::CORBA::StaticValueType _Marshaller_CosEventComm_PullSupplier::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosEventComm_PullSupplier::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosEventComm::PullSupplier::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosEventComm_PullSupplier::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosEventComm_PullSupplier::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosEventComm_PullSupplier::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosEventComm::PullSupplier::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosEventComm_PullSupplier::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosEventComm_PullSupplier;


/*
 * Stub interface for class PullSupplier
 */

CosEventComm::PullSupplier_stub::~PullSupplier_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosEventComm::PullSupplier::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventComm/PullSupplier:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_CosEventComm::PullSupplier *
POA_CosEventComm::PullSupplier::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosEventComm/PullSupplier:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosEventComm::PullSupplier *) p;
  }
  return NULL;
}

CosEventComm::PullSupplier_stub_clp::PullSupplier_stub_clp ()
{
}

CosEventComm::PullSupplier_stub_clp::PullSupplier_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosEventComm::PullSupplier_stub_clp::~PullSupplier_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

CORBA::Any* CosEventComm::PullSupplier_stub::pull()
{
  CORBA::StaticAny __res( CORBA::_stc_any );

  CORBA::StaticRequest __req( this, "pull" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosEventComm_Disconnected, "IDL:omg.org/CosEventComm/Disconnected:1.0",
    0);
  return (CORBA::Any*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

CORBA::Any*
CosEventComm::PullSupplier_stub_clp::pull()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventComm::PullSupplier * _myserv = POA_CosEventComm::PullSupplier::_narrow (_serv);
    if (_myserv) {
      CORBA::Any* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->pull();
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

  return CosEventComm::PullSupplier_stub::pull();
}

#endif // MICO_CONF_NO_POA

CORBA::Any* CosEventComm::PullSupplier_stub::try_pull( CORBA::Boolean_out _par_has_event )
{
  CORBA::StaticAny _sa_has_event( CORBA::_stc_boolean, &_par_has_event );
  CORBA::StaticAny __res( CORBA::_stc_any );

  CORBA::StaticRequest __req( this, "try_pull" );
  __req.add_out_arg( &_sa_has_event );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosEventComm_Disconnected, "IDL:omg.org/CosEventComm/Disconnected:1.0",
    0);
  return (CORBA::Any*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

CORBA::Any*
CosEventComm::PullSupplier_stub_clp::try_pull( CORBA::Boolean_out _par_has_event )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventComm::PullSupplier * _myserv = POA_CosEventComm::PullSupplier::_narrow (_serv);
    if (_myserv) {
      CORBA::Any* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->try_pull(_par_has_event);
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

  return CosEventComm::PullSupplier_stub::try_pull(_par_has_event);
}

#endif // MICO_CONF_NO_POA

void CosEventComm::PullSupplier_stub::disconnect_pull_supplier()
{
  CORBA::StaticRequest __req( this, "disconnect_pull_supplier" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosEventComm::PullSupplier_stub_clp::disconnect_pull_supplier()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventComm::PullSupplier * _myserv = POA_CosEventComm::PullSupplier::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->disconnect_pull_supplier();
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
      return;
    }
    _postinvoke ();
  }

  CosEventComm::PullSupplier_stub::disconnect_pull_supplier();
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class PullConsumer
 */

CosEventComm::PullConsumer::~PullConsumer()
{
}

void *
CosEventComm::PullConsumer::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosEventComm/PullConsumer:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

CosEventComm::PullConsumer_ptr
CosEventComm::PullConsumer::_narrow( CORBA::Object_ptr _obj )
{
  CosEventComm::PullConsumer_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosEventComm/PullConsumer:1.0" )))
      return _duplicate( (CosEventComm::PullConsumer_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosEventComm/PullConsumer:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosEventComm/PullConsumer:1.0")) {
      _o = new CosEventComm::PullConsumer_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosEventComm::PullConsumer_ptr
CosEventComm::PullConsumer::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosEventComm_PullConsumer : public ::CORBA::StaticTypeInfo {
    typedef CosEventComm::PullConsumer_ptr _MICO_T;
  public:
    ~_Marshaller_CosEventComm_PullConsumer();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosEventComm_PullConsumer::~_Marshaller_CosEventComm_PullConsumer()
{
}

::CORBA::StaticValueType _Marshaller_CosEventComm_PullConsumer::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosEventComm_PullConsumer::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosEventComm::PullConsumer::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosEventComm_PullConsumer::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosEventComm_PullConsumer::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosEventComm_PullConsumer::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosEventComm::PullConsumer::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosEventComm_PullConsumer::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosEventComm_PullConsumer;


/*
 * Stub interface for class PullConsumer
 */

CosEventComm::PullConsumer_stub::~PullConsumer_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosEventComm::PullConsumer::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventComm/PullConsumer:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_CosEventComm::PullConsumer *
POA_CosEventComm::PullConsumer::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosEventComm/PullConsumer:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosEventComm::PullConsumer *) p;
  }
  return NULL;
}

CosEventComm::PullConsumer_stub_clp::PullConsumer_stub_clp ()
{
}

CosEventComm::PullConsumer_stub_clp::PullConsumer_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosEventComm::PullConsumer_stub_clp::~PullConsumer_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

void CosEventComm::PullConsumer_stub::disconnect_pull_consumer()
{
  CORBA::StaticRequest __req( this, "disconnect_pull_consumer" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosEventComm::PullConsumer_stub_clp::disconnect_pull_consumer()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventComm::PullConsumer * _myserv = POA_CosEventComm::PullConsumer::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->disconnect_pull_consumer();
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
      return;
    }
    _postinvoke ();
  }

  CosEventComm::PullConsumer_stub::disconnect_pull_consumer();
}

#endif // MICO_CONF_NO_POA

struct __tc_init_COSEVENTCOMM {
  __tc_init_COSEVENTCOMM()
  {
    _marshaller_CosEventComm_Disconnected = new _Marshaller_CosEventComm_Disconnected;
    _marshaller_CosEventComm_PushConsumer = new _Marshaller_CosEventComm_PushConsumer;
    _marshaller_CosEventComm_PushSupplier = new _Marshaller_CosEventComm_PushSupplier;
    _marshaller_CosEventComm_PullSupplier = new _Marshaller_CosEventComm_PullSupplier;
    _marshaller_CosEventComm_PullConsumer = new _Marshaller_CosEventComm_PullConsumer;
  }

  ~__tc_init_COSEVENTCOMM()
  {
    delete static_cast<_Marshaller_CosEventComm_Disconnected*>(_marshaller_CosEventComm_Disconnected);
    delete static_cast<_Marshaller_CosEventComm_PushConsumer*>(_marshaller_CosEventComm_PushConsumer);
    delete static_cast<_Marshaller_CosEventComm_PushSupplier*>(_marshaller_CosEventComm_PushSupplier);
    delete static_cast<_Marshaller_CosEventComm_PullSupplier*>(_marshaller_CosEventComm_PullSupplier);
    delete static_cast<_Marshaller_CosEventComm_PullConsumer*>(_marshaller_CosEventComm_PullConsumer);
  }
};

static __tc_init_COSEVENTCOMM __init_COSEVENTCOMM;

//--------------------------------------------------------
//  Implementation of skeletons
//--------------------------------------------------------

// PortableServer Skeleton Class for interface CosEventComm::PushConsumer
POA_CosEventComm::PushConsumer::~PushConsumer()
{
}

::CosEventComm::PushConsumer_ptr
POA_CosEventComm::PushConsumer::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosEventComm::PushConsumer::_narrow (obj);
}

CORBA::Boolean
POA_CosEventComm::PushConsumer::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventComm/PushConsumer:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosEventComm::PushConsumer::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosEventComm/PushConsumer:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosEventComm::PushConsumer::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosEventComm/PushConsumer:1.0");
}

CORBA::Object_ptr
POA_CosEventComm::PushConsumer::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosEventComm::PushConsumer_stub_clp (poa, obj);
}

bool
POA_CosEventComm::PushConsumer::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "push" ) == 0 ) {
      CORBA::Any _par_data;
      CORBA::StaticAny _sa_data( CORBA::_stc_any, &_par_data );

      __req->add_in_arg( &_sa_data );

      if( !__req->read_args() )
        return true;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        push( _par_data );
      #ifdef HAVE_EXCEPTIONS
      } catch( ::CosEventComm::Disconnected_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      }
      #endif
      __req->write_results();
      return true;
    }
    if( strcmp( __req->op_name(), "disconnect_push_consumer" ) == 0 ) {

      if( !__req->read_args() )
        return true;

      disconnect_push_consumer();
      __req->write_results();
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
POA_CosEventComm::PushConsumer::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface CosEventComm::PushSupplier
POA_CosEventComm::PushSupplier::~PushSupplier()
{
}

::CosEventComm::PushSupplier_ptr
POA_CosEventComm::PushSupplier::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosEventComm::PushSupplier::_narrow (obj);
}

CORBA::Boolean
POA_CosEventComm::PushSupplier::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventComm/PushSupplier:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosEventComm::PushSupplier::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosEventComm/PushSupplier:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosEventComm::PushSupplier::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosEventComm/PushSupplier:1.0");
}

CORBA::Object_ptr
POA_CosEventComm::PushSupplier::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosEventComm::PushSupplier_stub_clp (poa, obj);
}

bool
POA_CosEventComm::PushSupplier::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "disconnect_push_supplier" ) == 0 ) {

      if( !__req->read_args() )
        return true;

      disconnect_push_supplier();
      __req->write_results();
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
POA_CosEventComm::PushSupplier::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface CosEventComm::PullSupplier
POA_CosEventComm::PullSupplier::~PullSupplier()
{
}

::CosEventComm::PullSupplier_ptr
POA_CosEventComm::PullSupplier::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosEventComm::PullSupplier::_narrow (obj);
}

CORBA::Boolean
POA_CosEventComm::PullSupplier::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventComm/PullSupplier:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosEventComm::PullSupplier::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosEventComm/PullSupplier:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosEventComm::PullSupplier::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosEventComm/PullSupplier:1.0");
}

CORBA::Object_ptr
POA_CosEventComm::PullSupplier::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosEventComm::PullSupplier_stub_clp (poa, obj);
}

bool
POA_CosEventComm::PullSupplier::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "pull" ) == 0 ) {
      CORBA::Any* _res;
      CORBA::StaticAny __res( CORBA::_stc_any );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _res = pull();
        __res.value( CORBA::_stc_any, _res );
      #ifdef HAVE_EXCEPTIONS
      } catch( ::CosEventComm::Disconnected_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      }
      #endif
      __req->write_results();
      delete _res;
      return true;
    }
    if( strcmp( __req->op_name(), "try_pull" ) == 0 ) {
      CORBA::Boolean _par_has_event;
      CORBA::StaticAny _sa_has_event( CORBA::_stc_boolean, &_par_has_event );

      CORBA::Any* _res;
      CORBA::StaticAny __res( CORBA::_stc_any );
      __req->add_out_arg( &_sa_has_event );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _res = try_pull( _par_has_event );
        __res.value( CORBA::_stc_any, _res );
      #ifdef HAVE_EXCEPTIONS
      } catch( ::CosEventComm::Disconnected_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      }
      #endif
      __req->write_results();
      delete _res;
      return true;
    }
    if( strcmp( __req->op_name(), "disconnect_pull_supplier" ) == 0 ) {

      if( !__req->read_args() )
        return true;

      disconnect_pull_supplier();
      __req->write_results();
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
POA_CosEventComm::PullSupplier::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface CosEventComm::PullConsumer
POA_CosEventComm::PullConsumer::~PullConsumer()
{
}

::CosEventComm::PullConsumer_ptr
POA_CosEventComm::PullConsumer::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosEventComm::PullConsumer::_narrow (obj);
}

CORBA::Boolean
POA_CosEventComm::PullConsumer::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventComm/PullConsumer:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosEventComm::PullConsumer::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosEventComm/PullConsumer:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosEventComm::PullConsumer::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosEventComm/PullConsumer:1.0");
}

CORBA::Object_ptr
POA_CosEventComm::PullConsumer::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosEventComm::PullConsumer_stub_clp (poa, obj);
}

bool
POA_CosEventComm::PullConsumer::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "disconnect_pull_consumer" ) == 0 ) {

      if( !__req->read_args() )
        return true;

      disconnect_pull_consumer();
      __req->write_results();
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
POA_CosEventComm::PullConsumer::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}

