/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CosEventChannelAdmin.h>


using namespace std;

//--------------------------------------------------------
//  Implementation of stubs
//--------------------------------------------------------

#ifdef HAVE_EXPLICIT_STRUCT_OPS
CosEventChannelAdmin::AlreadyConnected::AlreadyConnected()
{
}

CosEventChannelAdmin::AlreadyConnected::AlreadyConnected( const AlreadyConnected& _s )
{
}

CosEventChannelAdmin::AlreadyConnected::~AlreadyConnected()
{
}

CosEventChannelAdmin::AlreadyConnected&
CosEventChannelAdmin::AlreadyConnected::operator=( const AlreadyConnected& _s )
{
  return *this;
}
#endif

class _Marshaller_CosEventChannelAdmin_AlreadyConnected : public ::CORBA::StaticTypeInfo {
    typedef ::CosEventChannelAdmin::AlreadyConnected _MICO_T;
  public:
    ~_Marshaller_CosEventChannelAdmin_AlreadyConnected();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosEventChannelAdmin_AlreadyConnected::~_Marshaller_CosEventChannelAdmin_AlreadyConnected()
{
}

::CORBA::StaticValueType _Marshaller_CosEventChannelAdmin_AlreadyConnected::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosEventChannelAdmin_AlreadyConnected::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosEventChannelAdmin_AlreadyConnected::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosEventChannelAdmin_AlreadyConnected::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_CosEventChannelAdmin_AlreadyConnected::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/CosEventChannelAdmin/AlreadyConnected:1.0" );
  ec.except_end();
}

::CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_AlreadyConnected;

void CosEventChannelAdmin::AlreadyConnected::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw AlreadyConnected_var( (CosEventChannelAdmin::AlreadyConnected*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *CosEventChannelAdmin::AlreadyConnected::_repoid() const
{
  return "IDL:omg.org/CosEventChannelAdmin/AlreadyConnected:1.0";
}

void CosEventChannelAdmin::AlreadyConnected::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_CosEventChannelAdmin_AlreadyConnected->marshal( _en, (void*) this );
}

void CosEventChannelAdmin::AlreadyConnected::_encode_any( CORBA::Any & ) const
{
  // use --any to make this work!
  assert(0);
}

CORBA::Exception *CosEventChannelAdmin::AlreadyConnected::_clone() const
{
  return new AlreadyConnected( *this );
}

CosEventChannelAdmin::AlreadyConnected *CosEventChannelAdmin::AlreadyConnected::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosEventChannelAdmin/AlreadyConnected:1.0" ) )
    return (AlreadyConnected *) _ex;
  return NULL;
}

const CosEventChannelAdmin::AlreadyConnected *CosEventChannelAdmin::AlreadyConnected::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosEventChannelAdmin/AlreadyConnected:1.0" ) )
    return (AlreadyConnected *) _ex;
  return NULL;
}


#ifdef HAVE_EXPLICIT_STRUCT_OPS
CosEventChannelAdmin::TypeError::TypeError()
{
}

CosEventChannelAdmin::TypeError::TypeError( const TypeError& _s )
{
}

CosEventChannelAdmin::TypeError::~TypeError()
{
}

CosEventChannelAdmin::TypeError&
CosEventChannelAdmin::TypeError::operator=( const TypeError& _s )
{
  return *this;
}
#endif

class _Marshaller_CosEventChannelAdmin_TypeError : public ::CORBA::StaticTypeInfo {
    typedef ::CosEventChannelAdmin::TypeError _MICO_T;
  public:
    ~_Marshaller_CosEventChannelAdmin_TypeError();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosEventChannelAdmin_TypeError::~_Marshaller_CosEventChannelAdmin_TypeError()
{
}

::CORBA::StaticValueType _Marshaller_CosEventChannelAdmin_TypeError::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosEventChannelAdmin_TypeError::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosEventChannelAdmin_TypeError::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosEventChannelAdmin_TypeError::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_CosEventChannelAdmin_TypeError::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/CosEventChannelAdmin/TypeError:1.0" );
  ec.except_end();
}

::CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_TypeError;

void CosEventChannelAdmin::TypeError::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw TypeError_var( (CosEventChannelAdmin::TypeError*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *CosEventChannelAdmin::TypeError::_repoid() const
{
  return "IDL:omg.org/CosEventChannelAdmin/TypeError:1.0";
}

void CosEventChannelAdmin::TypeError::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_CosEventChannelAdmin_TypeError->marshal( _en, (void*) this );
}

void CosEventChannelAdmin::TypeError::_encode_any( CORBA::Any & ) const
{
  // use --any to make this work!
  assert(0);
}

CORBA::Exception *CosEventChannelAdmin::TypeError::_clone() const
{
  return new TypeError( *this );
}

CosEventChannelAdmin::TypeError *CosEventChannelAdmin::TypeError::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosEventChannelAdmin/TypeError:1.0" ) )
    return (TypeError *) _ex;
  return NULL;
}

const CosEventChannelAdmin::TypeError *CosEventChannelAdmin::TypeError::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosEventChannelAdmin/TypeError:1.0" ) )
    return (TypeError *) _ex;
  return NULL;
}


/*
 * Base interface for class ProxyPushConsumer
 */

CosEventChannelAdmin::ProxyPushConsumer::~ProxyPushConsumer()
{
}

void *
CosEventChannelAdmin::ProxyPushConsumer::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosEventChannelAdmin/ProxyPushConsumer:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = CosEventComm::PushConsumer::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

CosEventChannelAdmin::ProxyPushConsumer_ptr
CosEventChannelAdmin::ProxyPushConsumer::_narrow( CORBA::Object_ptr _obj )
{
  CosEventChannelAdmin::ProxyPushConsumer_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosEventChannelAdmin/ProxyPushConsumer:1.0" )))
      return _duplicate( (CosEventChannelAdmin::ProxyPushConsumer_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosEventChannelAdmin/ProxyPushConsumer:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosEventChannelAdmin/ProxyPushConsumer:1.0")) {
      _o = new CosEventChannelAdmin::ProxyPushConsumer_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosEventChannelAdmin::ProxyPushConsumer_ptr
CosEventChannelAdmin::ProxyPushConsumer::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosEventChannelAdmin_ProxyPushConsumer : public ::CORBA::StaticTypeInfo {
    typedef CosEventChannelAdmin::ProxyPushConsumer_ptr _MICO_T;
  public:
    ~_Marshaller_CosEventChannelAdmin_ProxyPushConsumer();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosEventChannelAdmin_ProxyPushConsumer::~_Marshaller_CosEventChannelAdmin_ProxyPushConsumer()
{
}

::CORBA::StaticValueType _Marshaller_CosEventChannelAdmin_ProxyPushConsumer::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosEventChannelAdmin_ProxyPushConsumer::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosEventChannelAdmin::ProxyPushConsumer::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosEventChannelAdmin_ProxyPushConsumer::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosEventChannelAdmin_ProxyPushConsumer::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosEventChannelAdmin_ProxyPushConsumer::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosEventChannelAdmin::ProxyPushConsumer::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosEventChannelAdmin_ProxyPushConsumer::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_ProxyPushConsumer;


/*
 * Stub interface for class ProxyPushConsumer
 */

CosEventChannelAdmin::ProxyPushConsumer_stub::~ProxyPushConsumer_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosEventChannelAdmin::ProxyPushConsumer::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:omg.org/CosEventChannelAdmin/ProxyPushConsumer:1.0") == 0) {
    return (void *) this;
  }
  if ((p = POA_CosEventComm::PushConsumer::_narrow_helper (repoid)) != NULL) 
  {
    return p;
  }
  return NULL;
}

POA_CosEventChannelAdmin::ProxyPushConsumer *
POA_CosEventChannelAdmin::ProxyPushConsumer::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosEventChannelAdmin/ProxyPushConsumer:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosEventChannelAdmin::ProxyPushConsumer *) p;
  }
  return NULL;
}

CosEventChannelAdmin::ProxyPushConsumer_stub_clp::ProxyPushConsumer_stub_clp ()
{
}

CosEventChannelAdmin::ProxyPushConsumer_stub_clp::ProxyPushConsumer_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosEventChannelAdmin::ProxyPushConsumer_stub_clp::~ProxyPushConsumer_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

void CosEventChannelAdmin::ProxyPushConsumer_stub::connect_push_supplier( CosEventComm::PushSupplier_ptr _par_push_supplier )
{
  CORBA::StaticAny _sa_push_supplier( _marshaller_CosEventComm_PushSupplier, &_par_push_supplier );
  CORBA::StaticRequest __req( this, "connect_push_supplier" );
  __req.add_in_arg( &_sa_push_supplier );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosEventChannelAdmin_AlreadyConnected, "IDL:omg.org/CosEventChannelAdmin/AlreadyConnected:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosEventChannelAdmin::ProxyPushConsumer_stub_clp::connect_push_supplier( CosEventComm::PushSupplier_ptr _par_push_supplier )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventChannelAdmin::ProxyPushConsumer * _myserv = POA_CosEventChannelAdmin::ProxyPushConsumer::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->connect_push_supplier(_par_push_supplier);
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

  CosEventChannelAdmin::ProxyPushConsumer_stub::connect_push_supplier(_par_push_supplier);
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class ProxyPullSupplier
 */

CosEventChannelAdmin::ProxyPullSupplier::~ProxyPullSupplier()
{
}

void *
CosEventChannelAdmin::ProxyPullSupplier::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosEventChannelAdmin/ProxyPullSupplier:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = CosEventComm::PullSupplier::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

CosEventChannelAdmin::ProxyPullSupplier_ptr
CosEventChannelAdmin::ProxyPullSupplier::_narrow( CORBA::Object_ptr _obj )
{
  CosEventChannelAdmin::ProxyPullSupplier_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosEventChannelAdmin/ProxyPullSupplier:1.0" )))
      return _duplicate( (CosEventChannelAdmin::ProxyPullSupplier_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosEventChannelAdmin/ProxyPullSupplier:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosEventChannelAdmin/ProxyPullSupplier:1.0")) {
      _o = new CosEventChannelAdmin::ProxyPullSupplier_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosEventChannelAdmin::ProxyPullSupplier_ptr
CosEventChannelAdmin::ProxyPullSupplier::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosEventChannelAdmin_ProxyPullSupplier : public ::CORBA::StaticTypeInfo {
    typedef CosEventChannelAdmin::ProxyPullSupplier_ptr _MICO_T;
  public:
    ~_Marshaller_CosEventChannelAdmin_ProxyPullSupplier();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosEventChannelAdmin_ProxyPullSupplier::~_Marshaller_CosEventChannelAdmin_ProxyPullSupplier()
{
}

::CORBA::StaticValueType _Marshaller_CosEventChannelAdmin_ProxyPullSupplier::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosEventChannelAdmin_ProxyPullSupplier::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosEventChannelAdmin::ProxyPullSupplier::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosEventChannelAdmin_ProxyPullSupplier::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosEventChannelAdmin_ProxyPullSupplier::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosEventChannelAdmin_ProxyPullSupplier::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosEventChannelAdmin::ProxyPullSupplier::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosEventChannelAdmin_ProxyPullSupplier::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_ProxyPullSupplier;


/*
 * Stub interface for class ProxyPullSupplier
 */

CosEventChannelAdmin::ProxyPullSupplier_stub::~ProxyPullSupplier_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosEventChannelAdmin::ProxyPullSupplier::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:omg.org/CosEventChannelAdmin/ProxyPullSupplier:1.0") == 0) {
    return (void *) this;
  }
  if ((p = POA_CosEventComm::PullSupplier::_narrow_helper (repoid)) != NULL) 
  {
    return p;
  }
  return NULL;
}

POA_CosEventChannelAdmin::ProxyPullSupplier *
POA_CosEventChannelAdmin::ProxyPullSupplier::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosEventChannelAdmin/ProxyPullSupplier:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosEventChannelAdmin::ProxyPullSupplier *) p;
  }
  return NULL;
}

CosEventChannelAdmin::ProxyPullSupplier_stub_clp::ProxyPullSupplier_stub_clp ()
{
}

CosEventChannelAdmin::ProxyPullSupplier_stub_clp::ProxyPullSupplier_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosEventChannelAdmin::ProxyPullSupplier_stub_clp::~ProxyPullSupplier_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

void CosEventChannelAdmin::ProxyPullSupplier_stub::connect_pull_consumer( CosEventComm::PullConsumer_ptr _par_pull_consumer )
{
  CORBA::StaticAny _sa_pull_consumer( _marshaller_CosEventComm_PullConsumer, &_par_pull_consumer );
  CORBA::StaticRequest __req( this, "connect_pull_consumer" );
  __req.add_in_arg( &_sa_pull_consumer );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosEventChannelAdmin_AlreadyConnected, "IDL:omg.org/CosEventChannelAdmin/AlreadyConnected:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosEventChannelAdmin::ProxyPullSupplier_stub_clp::connect_pull_consumer( CosEventComm::PullConsumer_ptr _par_pull_consumer )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventChannelAdmin::ProxyPullSupplier * _myserv = POA_CosEventChannelAdmin::ProxyPullSupplier::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->connect_pull_consumer(_par_pull_consumer);
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

  CosEventChannelAdmin::ProxyPullSupplier_stub::connect_pull_consumer(_par_pull_consumer);
}

#endif // MICO_CONF_NO_POA

void CosEventChannelAdmin::ProxyPullSupplier_stub::notify( const CORBA::Any& _par_a )
{
  CORBA::StaticAny _sa_a( CORBA::_stc_any, &_par_a );
  CORBA::StaticRequest __req( this, "notify" );
  __req.add_in_arg( &_sa_a );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosEventChannelAdmin::ProxyPullSupplier_stub_clp::notify( const CORBA::Any& _par_a )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventChannelAdmin::ProxyPullSupplier * _myserv = POA_CosEventChannelAdmin::ProxyPullSupplier::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->notify(_par_a);
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

  CosEventChannelAdmin::ProxyPullSupplier_stub::notify(_par_a);
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class ProxyPullConsumer
 */

CosEventChannelAdmin::ProxyPullConsumer::~ProxyPullConsumer()
{
}

void *
CosEventChannelAdmin::ProxyPullConsumer::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosEventChannelAdmin/ProxyPullConsumer:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = CosEventComm::PullConsumer::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

CosEventChannelAdmin::ProxyPullConsumer_ptr
CosEventChannelAdmin::ProxyPullConsumer::_narrow( CORBA::Object_ptr _obj )
{
  CosEventChannelAdmin::ProxyPullConsumer_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosEventChannelAdmin/ProxyPullConsumer:1.0" )))
      return _duplicate( (CosEventChannelAdmin::ProxyPullConsumer_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosEventChannelAdmin/ProxyPullConsumer:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosEventChannelAdmin/ProxyPullConsumer:1.0")) {
      _o = new CosEventChannelAdmin::ProxyPullConsumer_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosEventChannelAdmin::ProxyPullConsumer_ptr
CosEventChannelAdmin::ProxyPullConsumer::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosEventChannelAdmin_ProxyPullConsumer : public ::CORBA::StaticTypeInfo {
    typedef CosEventChannelAdmin::ProxyPullConsumer_ptr _MICO_T;
  public:
    ~_Marshaller_CosEventChannelAdmin_ProxyPullConsumer();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosEventChannelAdmin_ProxyPullConsumer::~_Marshaller_CosEventChannelAdmin_ProxyPullConsumer()
{
}

::CORBA::StaticValueType _Marshaller_CosEventChannelAdmin_ProxyPullConsumer::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosEventChannelAdmin_ProxyPullConsumer::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosEventChannelAdmin::ProxyPullConsumer::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosEventChannelAdmin_ProxyPullConsumer::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosEventChannelAdmin_ProxyPullConsumer::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosEventChannelAdmin_ProxyPullConsumer::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosEventChannelAdmin::ProxyPullConsumer::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosEventChannelAdmin_ProxyPullConsumer::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_ProxyPullConsumer;


/*
 * Stub interface for class ProxyPullConsumer
 */

CosEventChannelAdmin::ProxyPullConsumer_stub::~ProxyPullConsumer_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosEventChannelAdmin::ProxyPullConsumer::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:omg.org/CosEventChannelAdmin/ProxyPullConsumer:1.0") == 0) {
    return (void *) this;
  }
  if ((p = POA_CosEventComm::PullConsumer::_narrow_helper (repoid)) != NULL) 
  {
    return p;
  }
  return NULL;
}

POA_CosEventChannelAdmin::ProxyPullConsumer *
POA_CosEventChannelAdmin::ProxyPullConsumer::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosEventChannelAdmin/ProxyPullConsumer:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosEventChannelAdmin::ProxyPullConsumer *) p;
  }
  return NULL;
}

CosEventChannelAdmin::ProxyPullConsumer_stub_clp::ProxyPullConsumer_stub_clp ()
{
}

CosEventChannelAdmin::ProxyPullConsumer_stub_clp::ProxyPullConsumer_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosEventChannelAdmin::ProxyPullConsumer_stub_clp::~ProxyPullConsumer_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

void CosEventChannelAdmin::ProxyPullConsumer_stub::connect_pull_supplier( CosEventComm::PullSupplier_ptr _par_pull_supplier )
{
  CORBA::StaticAny _sa_pull_supplier( _marshaller_CosEventComm_PullSupplier, &_par_pull_supplier );
  CORBA::StaticRequest __req( this, "connect_pull_supplier" );
  __req.add_in_arg( &_sa_pull_supplier );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosEventChannelAdmin_AlreadyConnected, "IDL:omg.org/CosEventChannelAdmin/AlreadyConnected:1.0",
    _marshaller_CosEventChannelAdmin_TypeError, "IDL:omg.org/CosEventChannelAdmin/TypeError:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosEventChannelAdmin::ProxyPullConsumer_stub_clp::connect_pull_supplier( CosEventComm::PullSupplier_ptr _par_pull_supplier )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventChannelAdmin::ProxyPullConsumer * _myserv = POA_CosEventChannelAdmin::ProxyPullConsumer::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->connect_pull_supplier(_par_pull_supplier);
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

  CosEventChannelAdmin::ProxyPullConsumer_stub::connect_pull_supplier(_par_pull_supplier);
}

#endif // MICO_CONF_NO_POA

void CosEventChannelAdmin::ProxyPullConsumer_stub::listen()
{
  CORBA::StaticRequest __req( this, "listen" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosEventChannelAdmin::ProxyPullConsumer_stub_clp::listen()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventChannelAdmin::ProxyPullConsumer * _myserv = POA_CosEventChannelAdmin::ProxyPullConsumer::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->listen();
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

  CosEventChannelAdmin::ProxyPullConsumer_stub::listen();
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class ProxyPushSupplier
 */

CosEventChannelAdmin::ProxyPushSupplier::~ProxyPushSupplier()
{
}

void *
CosEventChannelAdmin::ProxyPushSupplier::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosEventChannelAdmin/ProxyPushSupplier:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = CosEventComm::PushSupplier::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

CosEventChannelAdmin::ProxyPushSupplier_ptr
CosEventChannelAdmin::ProxyPushSupplier::_narrow( CORBA::Object_ptr _obj )
{
  CosEventChannelAdmin::ProxyPushSupplier_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosEventChannelAdmin/ProxyPushSupplier:1.0" )))
      return _duplicate( (CosEventChannelAdmin::ProxyPushSupplier_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosEventChannelAdmin/ProxyPushSupplier:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosEventChannelAdmin/ProxyPushSupplier:1.0")) {
      _o = new CosEventChannelAdmin::ProxyPushSupplier_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosEventChannelAdmin::ProxyPushSupplier_ptr
CosEventChannelAdmin::ProxyPushSupplier::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosEventChannelAdmin_ProxyPushSupplier : public ::CORBA::StaticTypeInfo {
    typedef CosEventChannelAdmin::ProxyPushSupplier_ptr _MICO_T;
  public:
    ~_Marshaller_CosEventChannelAdmin_ProxyPushSupplier();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosEventChannelAdmin_ProxyPushSupplier::~_Marshaller_CosEventChannelAdmin_ProxyPushSupplier()
{
}

::CORBA::StaticValueType _Marshaller_CosEventChannelAdmin_ProxyPushSupplier::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosEventChannelAdmin_ProxyPushSupplier::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosEventChannelAdmin::ProxyPushSupplier::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosEventChannelAdmin_ProxyPushSupplier::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosEventChannelAdmin_ProxyPushSupplier::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosEventChannelAdmin_ProxyPushSupplier::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosEventChannelAdmin::ProxyPushSupplier::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosEventChannelAdmin_ProxyPushSupplier::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_ProxyPushSupplier;


/*
 * Stub interface for class ProxyPushSupplier
 */

CosEventChannelAdmin::ProxyPushSupplier_stub::~ProxyPushSupplier_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosEventChannelAdmin::ProxyPushSupplier::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:omg.org/CosEventChannelAdmin/ProxyPushSupplier:1.0") == 0) {
    return (void *) this;
  }
  if ((p = POA_CosEventComm::PushSupplier::_narrow_helper (repoid)) != NULL) 
  {
    return p;
  }
  return NULL;
}

POA_CosEventChannelAdmin::ProxyPushSupplier *
POA_CosEventChannelAdmin::ProxyPushSupplier::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosEventChannelAdmin/ProxyPushSupplier:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosEventChannelAdmin::ProxyPushSupplier *) p;
  }
  return NULL;
}

CosEventChannelAdmin::ProxyPushSupplier_stub_clp::ProxyPushSupplier_stub_clp ()
{
}

CosEventChannelAdmin::ProxyPushSupplier_stub_clp::ProxyPushSupplier_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosEventChannelAdmin::ProxyPushSupplier_stub_clp::~ProxyPushSupplier_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

void CosEventChannelAdmin::ProxyPushSupplier_stub::connect_push_consumer( CosEventComm::PushConsumer_ptr _par_push_consumer )
{
  CORBA::StaticAny _sa_push_consumer( _marshaller_CosEventComm_PushConsumer, &_par_push_consumer );
  CORBA::StaticRequest __req( this, "connect_push_consumer" );
  __req.add_in_arg( &_sa_push_consumer );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosEventChannelAdmin_AlreadyConnected, "IDL:omg.org/CosEventChannelAdmin/AlreadyConnected:1.0",
    _marshaller_CosEventChannelAdmin_TypeError, "IDL:omg.org/CosEventChannelAdmin/TypeError:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosEventChannelAdmin::ProxyPushSupplier_stub_clp::connect_push_consumer( CosEventComm::PushConsumer_ptr _par_push_consumer )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventChannelAdmin::ProxyPushSupplier * _myserv = POA_CosEventChannelAdmin::ProxyPushSupplier::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->connect_push_consumer(_par_push_consumer);
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

  CosEventChannelAdmin::ProxyPushSupplier_stub::connect_push_consumer(_par_push_consumer);
}

#endif // MICO_CONF_NO_POA

void CosEventChannelAdmin::ProxyPushSupplier_stub::notify( const CORBA::Any& _par_a )
{
  CORBA::StaticAny _sa_a( CORBA::_stc_any, &_par_a );
  CORBA::StaticRequest __req( this, "notify" );
  __req.add_in_arg( &_sa_a );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosEventChannelAdmin::ProxyPushSupplier_stub_clp::notify( const CORBA::Any& _par_a )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventChannelAdmin::ProxyPushSupplier * _myserv = POA_CosEventChannelAdmin::ProxyPushSupplier::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->notify(_par_a);
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

  CosEventChannelAdmin::ProxyPushSupplier_stub::notify(_par_a);
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class ConsumerAdmin
 */

CosEventChannelAdmin::ConsumerAdmin::~ConsumerAdmin()
{
}

void *
CosEventChannelAdmin::ConsumerAdmin::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosEventChannelAdmin/ConsumerAdmin:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

CosEventChannelAdmin::ConsumerAdmin_ptr
CosEventChannelAdmin::ConsumerAdmin::_narrow( CORBA::Object_ptr _obj )
{
  CosEventChannelAdmin::ConsumerAdmin_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosEventChannelAdmin/ConsumerAdmin:1.0" )))
      return _duplicate( (CosEventChannelAdmin::ConsumerAdmin_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosEventChannelAdmin/ConsumerAdmin:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosEventChannelAdmin/ConsumerAdmin:1.0")) {
      _o = new CosEventChannelAdmin::ConsumerAdmin_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosEventChannelAdmin::ConsumerAdmin_ptr
CosEventChannelAdmin::ConsumerAdmin::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosEventChannelAdmin_ConsumerAdmin : public ::CORBA::StaticTypeInfo {
    typedef CosEventChannelAdmin::ConsumerAdmin_ptr _MICO_T;
  public:
    ~_Marshaller_CosEventChannelAdmin_ConsumerAdmin();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosEventChannelAdmin_ConsumerAdmin::~_Marshaller_CosEventChannelAdmin_ConsumerAdmin()
{
}

::CORBA::StaticValueType _Marshaller_CosEventChannelAdmin_ConsumerAdmin::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosEventChannelAdmin_ConsumerAdmin::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosEventChannelAdmin::ConsumerAdmin::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosEventChannelAdmin_ConsumerAdmin::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosEventChannelAdmin_ConsumerAdmin::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosEventChannelAdmin_ConsumerAdmin::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosEventChannelAdmin::ConsumerAdmin::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosEventChannelAdmin_ConsumerAdmin::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_ConsumerAdmin;


/*
 * Stub interface for class ConsumerAdmin
 */

CosEventChannelAdmin::ConsumerAdmin_stub::~ConsumerAdmin_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosEventChannelAdmin::ConsumerAdmin::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventChannelAdmin/ConsumerAdmin:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_CosEventChannelAdmin::ConsumerAdmin *
POA_CosEventChannelAdmin::ConsumerAdmin::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosEventChannelAdmin/ConsumerAdmin:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosEventChannelAdmin::ConsumerAdmin *) p;
  }
  return NULL;
}

CosEventChannelAdmin::ConsumerAdmin_stub_clp::ConsumerAdmin_stub_clp ()
{
}

CosEventChannelAdmin::ConsumerAdmin_stub_clp::ConsumerAdmin_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosEventChannelAdmin::ConsumerAdmin_stub_clp::~ConsumerAdmin_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

CosEventChannelAdmin::ProxyPushSupplier_ptr CosEventChannelAdmin::ConsumerAdmin_stub::obtain_push_supplier()
{
  CosEventChannelAdmin::ProxyPushSupplier_ptr _res = CosEventChannelAdmin::ProxyPushSupplier::_nil();
  CORBA::StaticAny __res( _marshaller_CosEventChannelAdmin_ProxyPushSupplier, &_res );

  CORBA::StaticRequest __req( this, "obtain_push_supplier" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosEventChannelAdmin::ProxyPushSupplier_ptr
CosEventChannelAdmin::ConsumerAdmin_stub_clp::obtain_push_supplier()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventChannelAdmin::ConsumerAdmin * _myserv = POA_CosEventChannelAdmin::ConsumerAdmin::_narrow (_serv);
    if (_myserv) {
      CosEventChannelAdmin::ProxyPushSupplier_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->obtain_push_supplier();
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

  return CosEventChannelAdmin::ConsumerAdmin_stub::obtain_push_supplier();
}

#endif // MICO_CONF_NO_POA

CosEventChannelAdmin::ProxyPullSupplier_ptr CosEventChannelAdmin::ConsumerAdmin_stub::obtain_pull_supplier()
{
  CosEventChannelAdmin::ProxyPullSupplier_ptr _res = CosEventChannelAdmin::ProxyPullSupplier::_nil();
  CORBA::StaticAny __res( _marshaller_CosEventChannelAdmin_ProxyPullSupplier, &_res );

  CORBA::StaticRequest __req( this, "obtain_pull_supplier" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosEventChannelAdmin::ProxyPullSupplier_ptr
CosEventChannelAdmin::ConsumerAdmin_stub_clp::obtain_pull_supplier()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventChannelAdmin::ConsumerAdmin * _myserv = POA_CosEventChannelAdmin::ConsumerAdmin::_narrow (_serv);
    if (_myserv) {
      CosEventChannelAdmin::ProxyPullSupplier_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->obtain_pull_supplier();
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

  return CosEventChannelAdmin::ConsumerAdmin_stub::obtain_pull_supplier();
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class SupplierAdmin
 */

CosEventChannelAdmin::SupplierAdmin::~SupplierAdmin()
{
}

void *
CosEventChannelAdmin::SupplierAdmin::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosEventChannelAdmin/SupplierAdmin:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

CosEventChannelAdmin::SupplierAdmin_ptr
CosEventChannelAdmin::SupplierAdmin::_narrow( CORBA::Object_ptr _obj )
{
  CosEventChannelAdmin::SupplierAdmin_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosEventChannelAdmin/SupplierAdmin:1.0" )))
      return _duplicate( (CosEventChannelAdmin::SupplierAdmin_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosEventChannelAdmin/SupplierAdmin:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosEventChannelAdmin/SupplierAdmin:1.0")) {
      _o = new CosEventChannelAdmin::SupplierAdmin_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosEventChannelAdmin::SupplierAdmin_ptr
CosEventChannelAdmin::SupplierAdmin::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosEventChannelAdmin_SupplierAdmin : public ::CORBA::StaticTypeInfo {
    typedef CosEventChannelAdmin::SupplierAdmin_ptr _MICO_T;
  public:
    ~_Marshaller_CosEventChannelAdmin_SupplierAdmin();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosEventChannelAdmin_SupplierAdmin::~_Marshaller_CosEventChannelAdmin_SupplierAdmin()
{
}

::CORBA::StaticValueType _Marshaller_CosEventChannelAdmin_SupplierAdmin::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosEventChannelAdmin_SupplierAdmin::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosEventChannelAdmin::SupplierAdmin::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosEventChannelAdmin_SupplierAdmin::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosEventChannelAdmin_SupplierAdmin::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosEventChannelAdmin_SupplierAdmin::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosEventChannelAdmin::SupplierAdmin::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosEventChannelAdmin_SupplierAdmin::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_SupplierAdmin;


/*
 * Stub interface for class SupplierAdmin
 */

CosEventChannelAdmin::SupplierAdmin_stub::~SupplierAdmin_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosEventChannelAdmin::SupplierAdmin::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventChannelAdmin/SupplierAdmin:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_CosEventChannelAdmin::SupplierAdmin *
POA_CosEventChannelAdmin::SupplierAdmin::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosEventChannelAdmin/SupplierAdmin:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosEventChannelAdmin::SupplierAdmin *) p;
  }
  return NULL;
}

CosEventChannelAdmin::SupplierAdmin_stub_clp::SupplierAdmin_stub_clp ()
{
}

CosEventChannelAdmin::SupplierAdmin_stub_clp::SupplierAdmin_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosEventChannelAdmin::SupplierAdmin_stub_clp::~SupplierAdmin_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

CosEventChannelAdmin::ProxyPushConsumer_ptr CosEventChannelAdmin::SupplierAdmin_stub::obtain_push_consumer()
{
  CosEventChannelAdmin::ProxyPushConsumer_ptr _res = CosEventChannelAdmin::ProxyPushConsumer::_nil();
  CORBA::StaticAny __res( _marshaller_CosEventChannelAdmin_ProxyPushConsumer, &_res );

  CORBA::StaticRequest __req( this, "obtain_push_consumer" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosEventChannelAdmin::ProxyPushConsumer_ptr
CosEventChannelAdmin::SupplierAdmin_stub_clp::obtain_push_consumer()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventChannelAdmin::SupplierAdmin * _myserv = POA_CosEventChannelAdmin::SupplierAdmin::_narrow (_serv);
    if (_myserv) {
      CosEventChannelAdmin::ProxyPushConsumer_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->obtain_push_consumer();
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

  return CosEventChannelAdmin::SupplierAdmin_stub::obtain_push_consumer();
}

#endif // MICO_CONF_NO_POA

CosEventChannelAdmin::ProxyPullConsumer_ptr CosEventChannelAdmin::SupplierAdmin_stub::obtain_pull_consumer()
{
  CosEventChannelAdmin::ProxyPullConsumer_ptr _res = CosEventChannelAdmin::ProxyPullConsumer::_nil();
  CORBA::StaticAny __res( _marshaller_CosEventChannelAdmin_ProxyPullConsumer, &_res );

  CORBA::StaticRequest __req( this, "obtain_pull_consumer" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosEventChannelAdmin::ProxyPullConsumer_ptr
CosEventChannelAdmin::SupplierAdmin_stub_clp::obtain_pull_consumer()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventChannelAdmin::SupplierAdmin * _myserv = POA_CosEventChannelAdmin::SupplierAdmin::_narrow (_serv);
    if (_myserv) {
      CosEventChannelAdmin::ProxyPullConsumer_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->obtain_pull_consumer();
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

  return CosEventChannelAdmin::SupplierAdmin_stub::obtain_pull_consumer();
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class EventChannel
 */

CosEventChannelAdmin::EventChannel::~EventChannel()
{
}

void *
CosEventChannelAdmin::EventChannel::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosEventChannelAdmin/EventChannel:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

CosEventChannelAdmin::EventChannel_ptr
CosEventChannelAdmin::EventChannel::_narrow( CORBA::Object_ptr _obj )
{
  CosEventChannelAdmin::EventChannel_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosEventChannelAdmin/EventChannel:1.0" )))
      return _duplicate( (CosEventChannelAdmin::EventChannel_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosEventChannelAdmin/EventChannel:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosEventChannelAdmin/EventChannel:1.0")) {
      _o = new CosEventChannelAdmin::EventChannel_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosEventChannelAdmin::EventChannel_ptr
CosEventChannelAdmin::EventChannel::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosEventChannelAdmin_EventChannel : public ::CORBA::StaticTypeInfo {
    typedef CosEventChannelAdmin::EventChannel_ptr _MICO_T;
  public:
    ~_Marshaller_CosEventChannelAdmin_EventChannel();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosEventChannelAdmin_EventChannel::~_Marshaller_CosEventChannelAdmin_EventChannel()
{
}

::CORBA::StaticValueType _Marshaller_CosEventChannelAdmin_EventChannel::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosEventChannelAdmin_EventChannel::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosEventChannelAdmin::EventChannel::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosEventChannelAdmin_EventChannel::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosEventChannelAdmin_EventChannel::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosEventChannelAdmin_EventChannel::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosEventChannelAdmin::EventChannel::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosEventChannelAdmin_EventChannel::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_EventChannel;


/*
 * Stub interface for class EventChannel
 */

CosEventChannelAdmin::EventChannel_stub::~EventChannel_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosEventChannelAdmin::EventChannel::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventChannelAdmin/EventChannel:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_CosEventChannelAdmin::EventChannel *
POA_CosEventChannelAdmin::EventChannel::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosEventChannelAdmin/EventChannel:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosEventChannelAdmin::EventChannel *) p;
  }
  return NULL;
}

CosEventChannelAdmin::EventChannel_stub_clp::EventChannel_stub_clp ()
{
}

CosEventChannelAdmin::EventChannel_stub_clp::EventChannel_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosEventChannelAdmin::EventChannel_stub_clp::~EventChannel_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

CosEventChannelAdmin::ConsumerAdmin_ptr CosEventChannelAdmin::EventChannel_stub::for_consumers()
{
  CosEventChannelAdmin::ConsumerAdmin_ptr _res = CosEventChannelAdmin::ConsumerAdmin::_nil();
  CORBA::StaticAny __res( _marshaller_CosEventChannelAdmin_ConsumerAdmin, &_res );

  CORBA::StaticRequest __req( this, "for_consumers" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosEventChannelAdmin::ConsumerAdmin_ptr
CosEventChannelAdmin::EventChannel_stub_clp::for_consumers()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventChannelAdmin::EventChannel * _myserv = POA_CosEventChannelAdmin::EventChannel::_narrow (_serv);
    if (_myserv) {
      CosEventChannelAdmin::ConsumerAdmin_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->for_consumers();
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

  return CosEventChannelAdmin::EventChannel_stub::for_consumers();
}

#endif // MICO_CONF_NO_POA

CosEventChannelAdmin::SupplierAdmin_ptr CosEventChannelAdmin::EventChannel_stub::for_suppliers()
{
  CosEventChannelAdmin::SupplierAdmin_ptr _res = CosEventChannelAdmin::SupplierAdmin::_nil();
  CORBA::StaticAny __res( _marshaller_CosEventChannelAdmin_SupplierAdmin, &_res );

  CORBA::StaticRequest __req( this, "for_suppliers" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosEventChannelAdmin::SupplierAdmin_ptr
CosEventChannelAdmin::EventChannel_stub_clp::for_suppliers()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventChannelAdmin::EventChannel * _myserv = POA_CosEventChannelAdmin::EventChannel::_narrow (_serv);
    if (_myserv) {
      CosEventChannelAdmin::SupplierAdmin_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->for_suppliers();
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

  return CosEventChannelAdmin::EventChannel_stub::for_suppliers();
}

#endif // MICO_CONF_NO_POA

void CosEventChannelAdmin::EventChannel_stub::destroy()
{
  CORBA::StaticRequest __req( this, "destroy" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosEventChannelAdmin::EventChannel_stub_clp::destroy()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosEventChannelAdmin::EventChannel * _myserv = POA_CosEventChannelAdmin::EventChannel::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->destroy();
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

  CosEventChannelAdmin::EventChannel_stub::destroy();
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class EventChannelFactory
 */

SimpleEventChannelAdmin::EventChannelFactory::~EventChannelFactory()
{
}

void *
SimpleEventChannelAdmin::EventChannelFactory::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/SimpleEventChannelAdmin/EventChannelFactory:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SimpleEventChannelAdmin::EventChannelFactory_ptr
SimpleEventChannelAdmin::EventChannelFactory::_narrow( CORBA::Object_ptr _obj )
{
  SimpleEventChannelAdmin::EventChannelFactory_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/SimpleEventChannelAdmin/EventChannelFactory:1.0" )))
      return _duplicate( (SimpleEventChannelAdmin::EventChannelFactory_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/SimpleEventChannelAdmin/EventChannelFactory:1.0") || _obj->_is_a_remote ("IDL:omg.org/SimpleEventChannelAdmin/EventChannelFactory:1.0")) {
      _o = new SimpleEventChannelAdmin::EventChannelFactory_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

SimpleEventChannelAdmin::EventChannelFactory_ptr
SimpleEventChannelAdmin::EventChannelFactory::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_SimpleEventChannelAdmin_EventChannelFactory : public ::CORBA::StaticTypeInfo {
    typedef SimpleEventChannelAdmin::EventChannelFactory_ptr _MICO_T;
  public:
    ~_Marshaller_SimpleEventChannelAdmin_EventChannelFactory();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_SimpleEventChannelAdmin_EventChannelFactory::~_Marshaller_SimpleEventChannelAdmin_EventChannelFactory()
{
}

::CORBA::StaticValueType _Marshaller_SimpleEventChannelAdmin_EventChannelFactory::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_SimpleEventChannelAdmin_EventChannelFactory::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::SimpleEventChannelAdmin::EventChannelFactory::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_SimpleEventChannelAdmin_EventChannelFactory::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_SimpleEventChannelAdmin_EventChannelFactory::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_SimpleEventChannelAdmin_EventChannelFactory::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::SimpleEventChannelAdmin::EventChannelFactory::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_SimpleEventChannelAdmin_EventChannelFactory::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_SimpleEventChannelAdmin_EventChannelFactory;


/*
 * Stub interface for class EventChannelFactory
 */

SimpleEventChannelAdmin::EventChannelFactory_stub::~EventChannelFactory_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_SimpleEventChannelAdmin::EventChannelFactory::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/SimpleEventChannelAdmin/EventChannelFactory:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_SimpleEventChannelAdmin::EventChannelFactory *
POA_SimpleEventChannelAdmin::EventChannelFactory::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/SimpleEventChannelAdmin/EventChannelFactory:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_SimpleEventChannelAdmin::EventChannelFactory *) p;
  }
  return NULL;
}

SimpleEventChannelAdmin::EventChannelFactory_stub_clp::EventChannelFactory_stub_clp ()
{
}

SimpleEventChannelAdmin::EventChannelFactory_stub_clp::EventChannelFactory_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

SimpleEventChannelAdmin::EventChannelFactory_stub_clp::~EventChannelFactory_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

CosEventChannelAdmin::EventChannel_ptr SimpleEventChannelAdmin::EventChannelFactory_stub::create_eventchannel()
{
  CosEventChannelAdmin::EventChannel_ptr _res = CosEventChannelAdmin::EventChannel::_nil();
  CORBA::StaticAny __res( _marshaller_CosEventChannelAdmin_EventChannel, &_res );

  CORBA::StaticRequest __req( this, "create_eventchannel" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosEventChannelAdmin::EventChannel_ptr
SimpleEventChannelAdmin::EventChannelFactory_stub_clp::create_eventchannel()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_SimpleEventChannelAdmin::EventChannelFactory * _myserv = POA_SimpleEventChannelAdmin::EventChannelFactory::_narrow (_serv);
    if (_myserv) {
      CosEventChannelAdmin::EventChannel_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->create_eventchannel();
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

  return SimpleEventChannelAdmin::EventChannelFactory_stub::create_eventchannel();
}

#endif // MICO_CONF_NO_POA

struct __tc_init_COSEVENTCHANNELADMIN {
  __tc_init_COSEVENTCHANNELADMIN()
  {
    _marshaller_CosEventChannelAdmin_AlreadyConnected = new _Marshaller_CosEventChannelAdmin_AlreadyConnected;
    _marshaller_CosEventChannelAdmin_TypeError = new _Marshaller_CosEventChannelAdmin_TypeError;
    _marshaller_CosEventChannelAdmin_ProxyPushConsumer = new _Marshaller_CosEventChannelAdmin_ProxyPushConsumer;
    _marshaller_CosEventChannelAdmin_ProxyPullSupplier = new _Marshaller_CosEventChannelAdmin_ProxyPullSupplier;
    _marshaller_CosEventChannelAdmin_ProxyPullConsumer = new _Marshaller_CosEventChannelAdmin_ProxyPullConsumer;
    _marshaller_CosEventChannelAdmin_ProxyPushSupplier = new _Marshaller_CosEventChannelAdmin_ProxyPushSupplier;
    _marshaller_CosEventChannelAdmin_ConsumerAdmin = new _Marshaller_CosEventChannelAdmin_ConsumerAdmin;
    _marshaller_CosEventChannelAdmin_SupplierAdmin = new _Marshaller_CosEventChannelAdmin_SupplierAdmin;
    _marshaller_CosEventChannelAdmin_EventChannel = new _Marshaller_CosEventChannelAdmin_EventChannel;
    _marshaller_SimpleEventChannelAdmin_EventChannelFactory = new _Marshaller_SimpleEventChannelAdmin_EventChannelFactory;
  }

  ~__tc_init_COSEVENTCHANNELADMIN()
  {
    delete static_cast<_Marshaller_CosEventChannelAdmin_AlreadyConnected*>(_marshaller_CosEventChannelAdmin_AlreadyConnected);
    delete static_cast<_Marshaller_CosEventChannelAdmin_TypeError*>(_marshaller_CosEventChannelAdmin_TypeError);
    delete static_cast<_Marshaller_CosEventChannelAdmin_ProxyPushConsumer*>(_marshaller_CosEventChannelAdmin_ProxyPushConsumer);
    delete static_cast<_Marshaller_CosEventChannelAdmin_ProxyPullSupplier*>(_marshaller_CosEventChannelAdmin_ProxyPullSupplier);
    delete static_cast<_Marshaller_CosEventChannelAdmin_ProxyPullConsumer*>(_marshaller_CosEventChannelAdmin_ProxyPullConsumer);
    delete static_cast<_Marshaller_CosEventChannelAdmin_ProxyPushSupplier*>(_marshaller_CosEventChannelAdmin_ProxyPushSupplier);
    delete static_cast<_Marshaller_CosEventChannelAdmin_ConsumerAdmin*>(_marshaller_CosEventChannelAdmin_ConsumerAdmin);
    delete static_cast<_Marshaller_CosEventChannelAdmin_SupplierAdmin*>(_marshaller_CosEventChannelAdmin_SupplierAdmin);
    delete static_cast<_Marshaller_CosEventChannelAdmin_EventChannel*>(_marshaller_CosEventChannelAdmin_EventChannel);
    delete static_cast<_Marshaller_SimpleEventChannelAdmin_EventChannelFactory*>(_marshaller_SimpleEventChannelAdmin_EventChannelFactory);
  }
};

static __tc_init_COSEVENTCHANNELADMIN __init_COSEVENTCHANNELADMIN;

//--------------------------------------------------------
//  Implementation of skeletons
//--------------------------------------------------------

// PortableServer Skeleton Class for interface CosEventChannelAdmin::ProxyPushConsumer
POA_CosEventChannelAdmin::ProxyPushConsumer::~ProxyPushConsumer()
{
}

::CosEventChannelAdmin::ProxyPushConsumer_ptr
POA_CosEventChannelAdmin::ProxyPushConsumer::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosEventChannelAdmin::ProxyPushConsumer::_narrow (obj);
}

CORBA::Boolean
POA_CosEventChannelAdmin::ProxyPushConsumer::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventChannelAdmin/ProxyPushConsumer:1.0") == 0) {
    return TRUE;
  }
  if (POA_CosEventComm::PushConsumer::_is_a (repoid)) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosEventChannelAdmin::ProxyPushConsumer::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosEventChannelAdmin/ProxyPushConsumer:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosEventChannelAdmin::ProxyPushConsumer::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosEventChannelAdmin/ProxyPushConsumer:1.0");
}

CORBA::Object_ptr
POA_CosEventChannelAdmin::ProxyPushConsumer::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosEventChannelAdmin::ProxyPushConsumer_stub_clp (poa, obj);
}

bool
POA_CosEventChannelAdmin::ProxyPushConsumer::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "connect_push_supplier" ) == 0 ) {
      ::CosEventComm::PushSupplier_var _par_push_supplier;
      CORBA::StaticAny _sa_push_supplier( _marshaller_CosEventComm_PushSupplier, &_par_push_supplier._for_demarshal() );

      __req->add_in_arg( &_sa_push_supplier );

      if( !__req->read_args() )
        return true;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        connect_push_supplier( _par_push_supplier.inout() );
      #ifdef HAVE_EXCEPTIONS
      } catch( ::CosEventChannelAdmin::AlreadyConnected_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      }
      #endif
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

  if (POA_CosEventComm::PushConsumer::dispatch (__req)) {
    return true;
  }

  return false;
}

void
POA_CosEventChannelAdmin::ProxyPushConsumer::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface CosEventChannelAdmin::ProxyPullSupplier
POA_CosEventChannelAdmin::ProxyPullSupplier::~ProxyPullSupplier()
{
}

::CosEventChannelAdmin::ProxyPullSupplier_ptr
POA_CosEventChannelAdmin::ProxyPullSupplier::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosEventChannelAdmin::ProxyPullSupplier::_narrow (obj);
}

CORBA::Boolean
POA_CosEventChannelAdmin::ProxyPullSupplier::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventChannelAdmin/ProxyPullSupplier:1.0") == 0) {
    return TRUE;
  }
  if (POA_CosEventComm::PullSupplier::_is_a (repoid)) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosEventChannelAdmin::ProxyPullSupplier::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosEventChannelAdmin/ProxyPullSupplier:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosEventChannelAdmin::ProxyPullSupplier::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosEventChannelAdmin/ProxyPullSupplier:1.0");
}

CORBA::Object_ptr
POA_CosEventChannelAdmin::ProxyPullSupplier::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosEventChannelAdmin::ProxyPullSupplier_stub_clp (poa, obj);
}

bool
POA_CosEventChannelAdmin::ProxyPullSupplier::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "connect_pull_consumer" ) == 0 ) {
      ::CosEventComm::PullConsumer_var _par_pull_consumer;
      CORBA::StaticAny _sa_pull_consumer( _marshaller_CosEventComm_PullConsumer, &_par_pull_consumer._for_demarshal() );

      __req->add_in_arg( &_sa_pull_consumer );

      if( !__req->read_args() )
        return true;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        connect_pull_consumer( _par_pull_consumer.inout() );
      #ifdef HAVE_EXCEPTIONS
      } catch( ::CosEventChannelAdmin::AlreadyConnected_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      }
      #endif
      __req->write_results();
      return true;
    }
    if( strcmp( __req->op_name(), "notify" ) == 0 ) {
      CORBA::Any _par_a;
      CORBA::StaticAny _sa_a( CORBA::_stc_any, &_par_a );

      __req->add_in_arg( &_sa_a );

      if( !__req->read_args() )
        return true;

      notify( _par_a );
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

  if (POA_CosEventComm::PullSupplier::dispatch (__req)) {
    return true;
  }

  return false;
}

void
POA_CosEventChannelAdmin::ProxyPullSupplier::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface CosEventChannelAdmin::ProxyPullConsumer
POA_CosEventChannelAdmin::ProxyPullConsumer::~ProxyPullConsumer()
{
}

::CosEventChannelAdmin::ProxyPullConsumer_ptr
POA_CosEventChannelAdmin::ProxyPullConsumer::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosEventChannelAdmin::ProxyPullConsumer::_narrow (obj);
}

CORBA::Boolean
POA_CosEventChannelAdmin::ProxyPullConsumer::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventChannelAdmin/ProxyPullConsumer:1.0") == 0) {
    return TRUE;
  }
  if (POA_CosEventComm::PullConsumer::_is_a (repoid)) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosEventChannelAdmin::ProxyPullConsumer::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosEventChannelAdmin/ProxyPullConsumer:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosEventChannelAdmin::ProxyPullConsumer::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosEventChannelAdmin/ProxyPullConsumer:1.0");
}

CORBA::Object_ptr
POA_CosEventChannelAdmin::ProxyPullConsumer::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosEventChannelAdmin::ProxyPullConsumer_stub_clp (poa, obj);
}

bool
POA_CosEventChannelAdmin::ProxyPullConsumer::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "connect_pull_supplier" ) == 0 ) {
      ::CosEventComm::PullSupplier_var _par_pull_supplier;
      CORBA::StaticAny _sa_pull_supplier( _marshaller_CosEventComm_PullSupplier, &_par_pull_supplier._for_demarshal() );

      __req->add_in_arg( &_sa_pull_supplier );

      if( !__req->read_args() )
        return true;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        connect_pull_supplier( _par_pull_supplier.inout() );
      #ifdef HAVE_EXCEPTIONS
      } catch( ::CosEventChannelAdmin::AlreadyConnected_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      } catch( ::CosEventChannelAdmin::TypeError_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      }
      #endif
      __req->write_results();
      return true;
    }
    if( strcmp( __req->op_name(), "listen" ) == 0 ) {

      if( !__req->read_args() )
        return true;

      listen();
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

  if (POA_CosEventComm::PullConsumer::dispatch (__req)) {
    return true;
  }

  return false;
}

void
POA_CosEventChannelAdmin::ProxyPullConsumer::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface CosEventChannelAdmin::ProxyPushSupplier
POA_CosEventChannelAdmin::ProxyPushSupplier::~ProxyPushSupplier()
{
}

::CosEventChannelAdmin::ProxyPushSupplier_ptr
POA_CosEventChannelAdmin::ProxyPushSupplier::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosEventChannelAdmin::ProxyPushSupplier::_narrow (obj);
}

CORBA::Boolean
POA_CosEventChannelAdmin::ProxyPushSupplier::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventChannelAdmin/ProxyPushSupplier:1.0") == 0) {
    return TRUE;
  }
  if (POA_CosEventComm::PushSupplier::_is_a (repoid)) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosEventChannelAdmin::ProxyPushSupplier::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosEventChannelAdmin/ProxyPushSupplier:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosEventChannelAdmin::ProxyPushSupplier::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosEventChannelAdmin/ProxyPushSupplier:1.0");
}

CORBA::Object_ptr
POA_CosEventChannelAdmin::ProxyPushSupplier::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosEventChannelAdmin::ProxyPushSupplier_stub_clp (poa, obj);
}

bool
POA_CosEventChannelAdmin::ProxyPushSupplier::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "connect_push_consumer" ) == 0 ) {
      ::CosEventComm::PushConsumer_var _par_push_consumer;
      CORBA::StaticAny _sa_push_consumer( _marshaller_CosEventComm_PushConsumer, &_par_push_consumer._for_demarshal() );

      __req->add_in_arg( &_sa_push_consumer );

      if( !__req->read_args() )
        return true;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        connect_push_consumer( _par_push_consumer.inout() );
      #ifdef HAVE_EXCEPTIONS
      } catch( ::CosEventChannelAdmin::AlreadyConnected_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      } catch( ::CosEventChannelAdmin::TypeError_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      }
      #endif
      __req->write_results();
      return true;
    }
    if( strcmp( __req->op_name(), "notify" ) == 0 ) {
      CORBA::Any _par_a;
      CORBA::StaticAny _sa_a( CORBA::_stc_any, &_par_a );

      __req->add_in_arg( &_sa_a );

      if( !__req->read_args() )
        return true;

      notify( _par_a );
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

  if (POA_CosEventComm::PushSupplier::dispatch (__req)) {
    return true;
  }

  return false;
}

void
POA_CosEventChannelAdmin::ProxyPushSupplier::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface CosEventChannelAdmin::ConsumerAdmin
POA_CosEventChannelAdmin::ConsumerAdmin::~ConsumerAdmin()
{
}

::CosEventChannelAdmin::ConsumerAdmin_ptr
POA_CosEventChannelAdmin::ConsumerAdmin::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosEventChannelAdmin::ConsumerAdmin::_narrow (obj);
}

CORBA::Boolean
POA_CosEventChannelAdmin::ConsumerAdmin::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventChannelAdmin/ConsumerAdmin:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosEventChannelAdmin::ConsumerAdmin::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosEventChannelAdmin/ConsumerAdmin:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosEventChannelAdmin::ConsumerAdmin::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosEventChannelAdmin/ConsumerAdmin:1.0");
}

CORBA::Object_ptr
POA_CosEventChannelAdmin::ConsumerAdmin::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosEventChannelAdmin::ConsumerAdmin_stub_clp (poa, obj);
}

bool
POA_CosEventChannelAdmin::ConsumerAdmin::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "obtain_push_supplier" ) == 0 ) {
      ::CosEventChannelAdmin::ProxyPushSupplier_ptr _res;
      CORBA::StaticAny __res( _marshaller_CosEventChannelAdmin_ProxyPushSupplier, &_res );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = obtain_push_supplier();
      __req->write_results();
      CORBA::release( _res );
      return true;
    }
    if( strcmp( __req->op_name(), "obtain_pull_supplier" ) == 0 ) {
      ::CosEventChannelAdmin::ProxyPullSupplier_ptr _res;
      CORBA::StaticAny __res( _marshaller_CosEventChannelAdmin_ProxyPullSupplier, &_res );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = obtain_pull_supplier();
      __req->write_results();
      CORBA::release( _res );
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
POA_CosEventChannelAdmin::ConsumerAdmin::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface CosEventChannelAdmin::SupplierAdmin
POA_CosEventChannelAdmin::SupplierAdmin::~SupplierAdmin()
{
}

::CosEventChannelAdmin::SupplierAdmin_ptr
POA_CosEventChannelAdmin::SupplierAdmin::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosEventChannelAdmin::SupplierAdmin::_narrow (obj);
}

CORBA::Boolean
POA_CosEventChannelAdmin::SupplierAdmin::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventChannelAdmin/SupplierAdmin:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosEventChannelAdmin::SupplierAdmin::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosEventChannelAdmin/SupplierAdmin:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosEventChannelAdmin::SupplierAdmin::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosEventChannelAdmin/SupplierAdmin:1.0");
}

CORBA::Object_ptr
POA_CosEventChannelAdmin::SupplierAdmin::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosEventChannelAdmin::SupplierAdmin_stub_clp (poa, obj);
}

bool
POA_CosEventChannelAdmin::SupplierAdmin::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "obtain_push_consumer" ) == 0 ) {
      ::CosEventChannelAdmin::ProxyPushConsumer_ptr _res;
      CORBA::StaticAny __res( _marshaller_CosEventChannelAdmin_ProxyPushConsumer, &_res );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = obtain_push_consumer();
      __req->write_results();
      CORBA::release( _res );
      return true;
    }
    if( strcmp( __req->op_name(), "obtain_pull_consumer" ) == 0 ) {
      ::CosEventChannelAdmin::ProxyPullConsumer_ptr _res;
      CORBA::StaticAny __res( _marshaller_CosEventChannelAdmin_ProxyPullConsumer, &_res );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = obtain_pull_consumer();
      __req->write_results();
      CORBA::release( _res );
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
POA_CosEventChannelAdmin::SupplierAdmin::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface CosEventChannelAdmin::EventChannel
POA_CosEventChannelAdmin::EventChannel::~EventChannel()
{
}

::CosEventChannelAdmin::EventChannel_ptr
POA_CosEventChannelAdmin::EventChannel::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosEventChannelAdmin::EventChannel::_narrow (obj);
}

CORBA::Boolean
POA_CosEventChannelAdmin::EventChannel::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosEventChannelAdmin/EventChannel:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosEventChannelAdmin::EventChannel::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosEventChannelAdmin/EventChannel:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosEventChannelAdmin::EventChannel::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosEventChannelAdmin/EventChannel:1.0");
}

CORBA::Object_ptr
POA_CosEventChannelAdmin::EventChannel::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosEventChannelAdmin::EventChannel_stub_clp (poa, obj);
}

bool
POA_CosEventChannelAdmin::EventChannel::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "for_consumers" ) == 0 ) {
      ::CosEventChannelAdmin::ConsumerAdmin_ptr _res;
      CORBA::StaticAny __res( _marshaller_CosEventChannelAdmin_ConsumerAdmin, &_res );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = for_consumers();
      __req->write_results();
      CORBA::release( _res );
      return true;
    }
    if( strcmp( __req->op_name(), "for_suppliers" ) == 0 ) {
      ::CosEventChannelAdmin::SupplierAdmin_ptr _res;
      CORBA::StaticAny __res( _marshaller_CosEventChannelAdmin_SupplierAdmin, &_res );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = for_suppliers();
      __req->write_results();
      CORBA::release( _res );
      return true;
    }
    if( strcmp( __req->op_name(), "destroy" ) == 0 ) {

      if( !__req->read_args() )
        return true;

      destroy();
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
POA_CosEventChannelAdmin::EventChannel::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface SimpleEventChannelAdmin::EventChannelFactory
POA_SimpleEventChannelAdmin::EventChannelFactory::~EventChannelFactory()
{
}

::SimpleEventChannelAdmin::EventChannelFactory_ptr
POA_SimpleEventChannelAdmin::EventChannelFactory::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::SimpleEventChannelAdmin::EventChannelFactory::_narrow (obj);
}

CORBA::Boolean
POA_SimpleEventChannelAdmin::EventChannelFactory::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/SimpleEventChannelAdmin/EventChannelFactory:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_SimpleEventChannelAdmin::EventChannelFactory::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/SimpleEventChannelAdmin/EventChannelFactory:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_SimpleEventChannelAdmin::EventChannelFactory::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/SimpleEventChannelAdmin/EventChannelFactory:1.0");
}

CORBA::Object_ptr
POA_SimpleEventChannelAdmin::EventChannelFactory::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::SimpleEventChannelAdmin::EventChannelFactory_stub_clp (poa, obj);
}

bool
POA_SimpleEventChannelAdmin::EventChannelFactory::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "create_eventchannel" ) == 0 ) {
      ::CosEventChannelAdmin::EventChannel_ptr _res;
      CORBA::StaticAny __res( _marshaller_CosEventChannelAdmin_EventChannel, &_res );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = create_eventchannel();
      __req->write_results();
      CORBA::release( _res );
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
POA_SimpleEventChannelAdmin::EventChannelFactory::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}

