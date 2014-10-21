/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CosTime.h>


using namespace std;

//--------------------------------------------------------
//  Implementation of stubs
//--------------------------------------------------------

class _Marshaller_CosTime_TimeComparison : public ::CORBA::StaticTypeInfo {
    typedef CosTime::TimeComparison _MICO_T;
  public:
    ~_Marshaller_CosTime_TimeComparison();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosTime_TimeComparison::~_Marshaller_CosTime_TimeComparison()
{
}

::CORBA::StaticValueType _Marshaller_CosTime_TimeComparison::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosTime_TimeComparison::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosTime_TimeComparison::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosTime_TimeComparison::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong ul;
  if( !dc.enumeration( ul ) )
    return FALSE;
  *(_MICO_T*) v = (_MICO_T) ul;
  return TRUE;
}

void _Marshaller_CosTime_TimeComparison::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.enumeration( (::CORBA::ULong) *(_MICO_T *) v );
}

::CORBA::StaticTypeInfo *_marshaller_CosTime_TimeComparison;


class _Marshaller_CosTime_ComparisonType : public ::CORBA::StaticTypeInfo {
    typedef CosTime::ComparisonType _MICO_T;
  public:
    ~_Marshaller_CosTime_ComparisonType();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosTime_ComparisonType::~_Marshaller_CosTime_ComparisonType()
{
}

::CORBA::StaticValueType _Marshaller_CosTime_ComparisonType::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosTime_ComparisonType::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosTime_ComparisonType::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosTime_ComparisonType::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong ul;
  if( !dc.enumeration( ul ) )
    return FALSE;
  *(_MICO_T*) v = (_MICO_T) ul;
  return TRUE;
}

void _Marshaller_CosTime_ComparisonType::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.enumeration( (::CORBA::ULong) *(_MICO_T *) v );
}

::CORBA::StaticTypeInfo *_marshaller_CosTime_ComparisonType;


class _Marshaller_CosTime_OverlapType : public ::CORBA::StaticTypeInfo {
    typedef CosTime::OverlapType _MICO_T;
  public:
    ~_Marshaller_CosTime_OverlapType();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosTime_OverlapType::~_Marshaller_CosTime_OverlapType()
{
}

::CORBA::StaticValueType _Marshaller_CosTime_OverlapType::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosTime_OverlapType::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosTime_OverlapType::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosTime_OverlapType::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong ul;
  if( !dc.enumeration( ul ) )
    return FALSE;
  *(_MICO_T*) v = (_MICO_T) ul;
  return TRUE;
}

void _Marshaller_CosTime_OverlapType::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.enumeration( (::CORBA::ULong) *(_MICO_T *) v );
}

::CORBA::StaticTypeInfo *_marshaller_CosTime_OverlapType;


#ifdef HAVE_EXPLICIT_STRUCT_OPS
CosTime::TimeUnavailable::TimeUnavailable()
{
}

CosTime::TimeUnavailable::TimeUnavailable( const TimeUnavailable& _s )
{
}

CosTime::TimeUnavailable::~TimeUnavailable()
{
}

CosTime::TimeUnavailable&
CosTime::TimeUnavailable::operator=( const TimeUnavailable& _s )
{
  return *this;
}
#endif

class _Marshaller_CosTime_TimeUnavailable : public ::CORBA::StaticTypeInfo {
    typedef ::CosTime::TimeUnavailable _MICO_T;
  public:
    ~_Marshaller_CosTime_TimeUnavailable();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosTime_TimeUnavailable::~_Marshaller_CosTime_TimeUnavailable()
{
}

::CORBA::StaticValueType _Marshaller_CosTime_TimeUnavailable::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosTime_TimeUnavailable::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosTime_TimeUnavailable::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosTime_TimeUnavailable::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_CosTime_TimeUnavailable::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/CosTime/TimeUnavailable:1.0" );
  ec.except_end();
}

::CORBA::StaticTypeInfo *_marshaller_CosTime_TimeUnavailable;

void CosTime::TimeUnavailable::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw TimeUnavailable_var( (CosTime::TimeUnavailable*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *CosTime::TimeUnavailable::_repoid() const
{
  return "IDL:omg.org/CosTime/TimeUnavailable:1.0";
}

void CosTime::TimeUnavailable::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_CosTime_TimeUnavailable->marshal( _en, (void*) this );
}

void CosTime::TimeUnavailable::_encode_any( CORBA::Any & ) const
{
  // use --any to make this work!
  assert(0);
}

CORBA::Exception *CosTime::TimeUnavailable::_clone() const
{
  return new TimeUnavailable( *this );
}

CosTime::TimeUnavailable *CosTime::TimeUnavailable::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosTime/TimeUnavailable:1.0" ) )
    return (TimeUnavailable *) _ex;
  return NULL;
}

const CosTime::TimeUnavailable *CosTime::TimeUnavailable::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosTime/TimeUnavailable:1.0" ) )
    return (TimeUnavailable *) _ex;
  return NULL;
}


/*
 * Base interface for class UTO
 */

CosTime::UTO::~UTO()
{
}

void *
CosTime::UTO::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosTime/UTO:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

CosTime::UTO_ptr
CosTime::UTO::_narrow( CORBA::Object_ptr _obj )
{
  CosTime::UTO_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosTime/UTO:1.0" )))
      return _duplicate( (CosTime::UTO_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosTime/UTO:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosTime/UTO:1.0")) {
      _o = new CosTime::UTO_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosTime::UTO_ptr
CosTime::UTO::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosTime_UTO : public ::CORBA::StaticTypeInfo {
    typedef CosTime::UTO_ptr _MICO_T;
  public:
    ~_Marshaller_CosTime_UTO();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosTime_UTO::~_Marshaller_CosTime_UTO()
{
}

::CORBA::StaticValueType _Marshaller_CosTime_UTO::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosTime_UTO::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosTime::UTO::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosTime_UTO::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosTime_UTO::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosTime_UTO::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosTime::UTO::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosTime_UTO::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosTime_UTO;


/*
 * Stub interface for class UTO
 */

CosTime::UTO_stub::~UTO_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosTime::UTO::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosTime/UTO:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_CosTime::UTO *
POA_CosTime::UTO::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosTime/UTO:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosTime::UTO *) p;
  }
  return NULL;
}

CosTime::UTO_stub_clp::UTO_stub_clp ()
{
}

CosTime::UTO_stub_clp::UTO_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosTime::UTO_stub_clp::~UTO_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

TimeBase::TimeT CosTime::UTO_stub::time()
{
  TimeBase::TimeT _res;
  CORBA::StaticAny __res( CORBA::_stc_ulonglong, &_res );

  CORBA::StaticRequest __req( this, "_get_time" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

TimeBase::TimeT
CosTime::UTO_stub_clp::time()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::UTO * _myserv = POA_CosTime::UTO::_narrow (_serv);
    if (_myserv) {
      TimeBase::TimeT __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->time();
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

  return CosTime::UTO_stub::time();
}

#endif // MICO_CONF_NO_POA

TimeBase::InaccuracyT CosTime::UTO_stub::inaccuracy()
{
  TimeBase::InaccuracyT _res;
  CORBA::StaticAny __res( CORBA::_stc_ulonglong, &_res );

  CORBA::StaticRequest __req( this, "_get_inaccuracy" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

TimeBase::InaccuracyT
CosTime::UTO_stub_clp::inaccuracy()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::UTO * _myserv = POA_CosTime::UTO::_narrow (_serv);
    if (_myserv) {
      TimeBase::InaccuracyT __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->inaccuracy();
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

  return CosTime::UTO_stub::inaccuracy();
}

#endif // MICO_CONF_NO_POA

TimeBase::TdfT CosTime::UTO_stub::tdf()
{
  TimeBase::TdfT _res;
  CORBA::StaticAny __res( CORBA::_stc_short, &_res );

  CORBA::StaticRequest __req( this, "_get_tdf" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

TimeBase::TdfT
CosTime::UTO_stub_clp::tdf()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::UTO * _myserv = POA_CosTime::UTO::_narrow (_serv);
    if (_myserv) {
      TimeBase::TdfT __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->tdf();
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

  return CosTime::UTO_stub::tdf();
}

#endif // MICO_CONF_NO_POA

TimeBase::UtcT CosTime::UTO_stub::utc_time()
{
  TimeBase::UtcT _res;
  CORBA::StaticAny __res( _marshaller_TimeBase_UtcT, &_res );

  CORBA::StaticRequest __req( this, "_get_utc_time" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

TimeBase::UtcT
CosTime::UTO_stub_clp::utc_time()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::UTO * _myserv = POA_CosTime::UTO::_narrow (_serv);
    if (_myserv) {
      TimeBase::UtcT __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->utc_time();
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

  return CosTime::UTO_stub::utc_time();
}

#endif // MICO_CONF_NO_POA

CosTime::UTO_ptr CosTime::UTO_stub::absolute_time()
{
  CosTime::UTO_ptr _res = CosTime::UTO::_nil();
  CORBA::StaticAny __res( _marshaller_CosTime_UTO, &_res );

  CORBA::StaticRequest __req( this, "absolute_time" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosTime::UTO_ptr
CosTime::UTO_stub_clp::absolute_time()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::UTO * _myserv = POA_CosTime::UTO::_narrow (_serv);
    if (_myserv) {
      CosTime::UTO_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->absolute_time();
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

  return CosTime::UTO_stub::absolute_time();
}

#endif // MICO_CONF_NO_POA

CosTime::TimeComparison CosTime::UTO_stub::compare_time( CosTime::ComparisonType _par_comparison_type, CosTime::UTO_ptr _par_uto )
{
  CORBA::StaticAny _sa_comparison_type( _marshaller_CosTime_ComparisonType, &_par_comparison_type );
  CORBA::StaticAny _sa_uto( _marshaller_CosTime_UTO, &_par_uto );
  CosTime::TimeComparison _res;
  CORBA::StaticAny __res( _marshaller_CosTime_TimeComparison, &_res );

  CORBA::StaticRequest __req( this, "compare_time" );
  __req.add_in_arg( &_sa_comparison_type );
  __req.add_in_arg( &_sa_uto );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosTime::TimeComparison
CosTime::UTO_stub_clp::compare_time( CosTime::ComparisonType _par_comparison_type, CosTime::UTO_ptr _par_uto )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::UTO * _myserv = POA_CosTime::UTO::_narrow (_serv);
    if (_myserv) {
      CosTime::TimeComparison __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->compare_time(_par_comparison_type, _par_uto);
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

  return CosTime::UTO_stub::compare_time(_par_comparison_type, _par_uto);
}

#endif // MICO_CONF_NO_POA

CosTime::TIO_ptr CosTime::UTO_stub::time_to_interval( CosTime::UTO_ptr _par_uto )
{
  CORBA::StaticAny _sa_uto( _marshaller_CosTime_UTO, &_par_uto );
  CosTime::TIO_ptr _res = CosTime::TIO::_nil();
  CORBA::StaticAny __res( _marshaller_CosTime_TIO, &_res );

  CORBA::StaticRequest __req( this, "time_to_interval" );
  __req.add_in_arg( &_sa_uto );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosTime::TIO_ptr
CosTime::UTO_stub_clp::time_to_interval( CosTime::UTO_ptr _par_uto )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::UTO * _myserv = POA_CosTime::UTO::_narrow (_serv);
    if (_myserv) {
      CosTime::TIO_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->time_to_interval(_par_uto);
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

  return CosTime::UTO_stub::time_to_interval(_par_uto);
}

#endif // MICO_CONF_NO_POA

CosTime::TIO_ptr CosTime::UTO_stub::interval()
{
  CosTime::TIO_ptr _res = CosTime::TIO::_nil();
  CORBA::StaticAny __res( _marshaller_CosTime_TIO, &_res );

  CORBA::StaticRequest __req( this, "interval" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosTime::TIO_ptr
CosTime::UTO_stub_clp::interval()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::UTO * _myserv = POA_CosTime::UTO::_narrow (_serv);
    if (_myserv) {
      CosTime::TIO_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->interval();
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

  return CosTime::UTO_stub::interval();
}

#endif // MICO_CONF_NO_POA

void CosTime::UTO_stub::destroy()
{
  CORBA::StaticRequest __req( this, "destroy" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosTime::UTO_stub_clp::destroy()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::UTO * _myserv = POA_CosTime::UTO::_narrow (_serv);
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

  CosTime::UTO_stub::destroy();
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class TIO
 */

CosTime::TIO::~TIO()
{
}

void *
CosTime::TIO::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosTime/TIO:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

CosTime::TIO_ptr
CosTime::TIO::_narrow( CORBA::Object_ptr _obj )
{
  CosTime::TIO_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosTime/TIO:1.0" )))
      return _duplicate( (CosTime::TIO_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosTime/TIO:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosTime/TIO:1.0")) {
      _o = new CosTime::TIO_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosTime::TIO_ptr
CosTime::TIO::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosTime_TIO : public ::CORBA::StaticTypeInfo {
    typedef CosTime::TIO_ptr _MICO_T;
  public:
    ~_Marshaller_CosTime_TIO();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosTime_TIO::~_Marshaller_CosTime_TIO()
{
}

::CORBA::StaticValueType _Marshaller_CosTime_TIO::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosTime_TIO::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosTime::TIO::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosTime_TIO::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosTime_TIO::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosTime_TIO::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosTime::TIO::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosTime_TIO::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosTime_TIO;


/*
 * Stub interface for class TIO
 */

CosTime::TIO_stub::~TIO_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosTime::TIO::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosTime/TIO:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_CosTime::TIO *
POA_CosTime::TIO::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosTime/TIO:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosTime::TIO *) p;
  }
  return NULL;
}

CosTime::TIO_stub_clp::TIO_stub_clp ()
{
}

CosTime::TIO_stub_clp::TIO_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosTime::TIO_stub_clp::~TIO_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

TimeBase::IntervalT CosTime::TIO_stub::time_interval()
{
  TimeBase::IntervalT _res;
  CORBA::StaticAny __res( _marshaller_TimeBase_IntervalT, &_res );

  CORBA::StaticRequest __req( this, "_get_time_interval" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

TimeBase::IntervalT
CosTime::TIO_stub_clp::time_interval()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::TIO * _myserv = POA_CosTime::TIO::_narrow (_serv);
    if (_myserv) {
      TimeBase::IntervalT __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->time_interval();
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

  return CosTime::TIO_stub::time_interval();
}

#endif // MICO_CONF_NO_POA

CosTime::OverlapType CosTime::TIO_stub::spans( CosTime::UTO_ptr _par_time, CosTime::TIO_out _par_overlap )
{
  CORBA::StaticAny _sa_time( _marshaller_CosTime_UTO, &_par_time );
  CORBA::StaticAny _sa_overlap( _marshaller_CosTime_TIO, &_par_overlap.ptr() );
  CosTime::OverlapType _res;
  CORBA::StaticAny __res( _marshaller_CosTime_OverlapType, &_res );

  CORBA::StaticRequest __req( this, "spans" );
  __req.add_in_arg( &_sa_time );
  __req.add_out_arg( &_sa_overlap );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosTime::OverlapType
CosTime::TIO_stub_clp::spans( CosTime::UTO_ptr _par_time, CosTime::TIO_out _par_overlap )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::TIO * _myserv = POA_CosTime::TIO::_narrow (_serv);
    if (_myserv) {
      CosTime::OverlapType __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->spans(_par_time, _par_overlap);
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

  return CosTime::TIO_stub::spans(_par_time, _par_overlap);
}

#endif // MICO_CONF_NO_POA

CosTime::OverlapType CosTime::TIO_stub::overlaps( CosTime::TIO_ptr _par_interval, CosTime::TIO_out _par_overlap )
{
  CORBA::StaticAny _sa_interval( _marshaller_CosTime_TIO, &_par_interval );
  CORBA::StaticAny _sa_overlap( _marshaller_CosTime_TIO, &_par_overlap.ptr() );
  CosTime::OverlapType _res;
  CORBA::StaticAny __res( _marshaller_CosTime_OverlapType, &_res );

  CORBA::StaticRequest __req( this, "overlaps" );
  __req.add_in_arg( &_sa_interval );
  __req.add_out_arg( &_sa_overlap );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosTime::OverlapType
CosTime::TIO_stub_clp::overlaps( CosTime::TIO_ptr _par_interval, CosTime::TIO_out _par_overlap )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::TIO * _myserv = POA_CosTime::TIO::_narrow (_serv);
    if (_myserv) {
      CosTime::OverlapType __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->overlaps(_par_interval, _par_overlap);
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

  return CosTime::TIO_stub::overlaps(_par_interval, _par_overlap);
}

#endif // MICO_CONF_NO_POA

CosTime::UTO_ptr CosTime::TIO_stub::time()
{
  CosTime::UTO_ptr _res = CosTime::UTO::_nil();
  CORBA::StaticAny __res( _marshaller_CosTime_UTO, &_res );

  CORBA::StaticRequest __req( this, "time" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosTime::UTO_ptr
CosTime::TIO_stub_clp::time()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::TIO * _myserv = POA_CosTime::TIO::_narrow (_serv);
    if (_myserv) {
      CosTime::UTO_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->time();
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

  return CosTime::TIO_stub::time();
}

#endif // MICO_CONF_NO_POA

void CosTime::TIO_stub::destroy()
{
  CORBA::StaticRequest __req( this, "destroy" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosTime::TIO_stub_clp::destroy()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::TIO * _myserv = POA_CosTime::TIO::_narrow (_serv);
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

  CosTime::TIO_stub::destroy();
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class TimeService
 */

CosTime::TimeService::~TimeService()
{
}

void *
CosTime::TimeService::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosTime/TimeService:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

CosTime::TimeService_ptr
CosTime::TimeService::_narrow( CORBA::Object_ptr _obj )
{
  CosTime::TimeService_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosTime/TimeService:1.0" )))
      return _duplicate( (CosTime::TimeService_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosTime/TimeService:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosTime/TimeService:1.0")) {
      _o = new CosTime::TimeService_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosTime::TimeService_ptr
CosTime::TimeService::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosTime_TimeService : public ::CORBA::StaticTypeInfo {
    typedef CosTime::TimeService_ptr _MICO_T;
  public:
    ~_Marshaller_CosTime_TimeService();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosTime_TimeService::~_Marshaller_CosTime_TimeService()
{
}

::CORBA::StaticValueType _Marshaller_CosTime_TimeService::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosTime_TimeService::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosTime::TimeService::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosTime_TimeService::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosTime_TimeService::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosTime_TimeService::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosTime::TimeService::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosTime_TimeService::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosTime_TimeService;


/*
 * Stub interface for class TimeService
 */

CosTime::TimeService_stub::~TimeService_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosTime::TimeService::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosTime/TimeService:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_CosTime::TimeService *
POA_CosTime::TimeService::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosTime/TimeService:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosTime::TimeService *) p;
  }
  return NULL;
}

CosTime::TimeService_stub_clp::TimeService_stub_clp ()
{
}

CosTime::TimeService_stub_clp::TimeService_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosTime::TimeService_stub_clp::~TimeService_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

CosTime::UTO_ptr CosTime::TimeService_stub::universal_time()
{
  CosTime::UTO_ptr _res = CosTime::UTO::_nil();
  CORBA::StaticAny __res( _marshaller_CosTime_UTO, &_res );

  CORBA::StaticRequest __req( this, "universal_time" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosTime_TimeUnavailable, "IDL:omg.org/CosTime/TimeUnavailable:1.0",
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosTime::UTO_ptr
CosTime::TimeService_stub_clp::universal_time()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::TimeService * _myserv = POA_CosTime::TimeService::_narrow (_serv);
    if (_myserv) {
      CosTime::UTO_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->universal_time();
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

  return CosTime::TimeService_stub::universal_time();
}

#endif // MICO_CONF_NO_POA

CosTime::UTO_ptr CosTime::TimeService_stub::secure_universal_time()
{
  CosTime::UTO_ptr _res = CosTime::UTO::_nil();
  CORBA::StaticAny __res( _marshaller_CosTime_UTO, &_res );

  CORBA::StaticRequest __req( this, "secure_universal_time" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosTime_TimeUnavailable, "IDL:omg.org/CosTime/TimeUnavailable:1.0",
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosTime::UTO_ptr
CosTime::TimeService_stub_clp::secure_universal_time()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::TimeService * _myserv = POA_CosTime::TimeService::_narrow (_serv);
    if (_myserv) {
      CosTime::UTO_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->secure_universal_time();
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

  return CosTime::TimeService_stub::secure_universal_time();
}

#endif // MICO_CONF_NO_POA

CosTime::UTO_ptr CosTime::TimeService_stub::new_universal_time( TimeBase::TimeT _par_time, TimeBase::InaccuracyT _par_inaccuracy, TimeBase::TdfT _par_tdf )
{
  CORBA::StaticAny _sa_time( CORBA::_stc_ulonglong, &_par_time );
  CORBA::StaticAny _sa_inaccuracy( CORBA::_stc_ulonglong, &_par_inaccuracy );
  CORBA::StaticAny _sa_tdf( CORBA::_stc_short, &_par_tdf );
  CosTime::UTO_ptr _res = CosTime::UTO::_nil();
  CORBA::StaticAny __res( _marshaller_CosTime_UTO, &_res );

  CORBA::StaticRequest __req( this, "new_universal_time" );
  __req.add_in_arg( &_sa_time );
  __req.add_in_arg( &_sa_inaccuracy );
  __req.add_in_arg( &_sa_tdf );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosTime::UTO_ptr
CosTime::TimeService_stub_clp::new_universal_time( TimeBase::TimeT _par_time, TimeBase::InaccuracyT _par_inaccuracy, TimeBase::TdfT _par_tdf )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::TimeService * _myserv = POA_CosTime::TimeService::_narrow (_serv);
    if (_myserv) {
      CosTime::UTO_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->new_universal_time(_par_time, _par_inaccuracy, _par_tdf);
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

  return CosTime::TimeService_stub::new_universal_time(_par_time, _par_inaccuracy, _par_tdf);
}

#endif // MICO_CONF_NO_POA

CosTime::UTO_ptr CosTime::TimeService_stub::uto_from_utc( const TimeBase::UtcT& _par_utc )
{
  CORBA::StaticAny _sa_utc( _marshaller_TimeBase_UtcT, &_par_utc );
  CosTime::UTO_ptr _res = CosTime::UTO::_nil();
  CORBA::StaticAny __res( _marshaller_CosTime_UTO, &_res );

  CORBA::StaticRequest __req( this, "uto_from_utc" );
  __req.add_in_arg( &_sa_utc );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosTime::UTO_ptr
CosTime::TimeService_stub_clp::uto_from_utc( const TimeBase::UtcT& _par_utc )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::TimeService * _myserv = POA_CosTime::TimeService::_narrow (_serv);
    if (_myserv) {
      CosTime::UTO_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->uto_from_utc(_par_utc);
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

  return CosTime::TimeService_stub::uto_from_utc(_par_utc);
}

#endif // MICO_CONF_NO_POA

CosTime::TIO_ptr CosTime::TimeService_stub::new_interval( TimeBase::TimeT _par_lower, TimeBase::TimeT _par_upper )
{
  CORBA::StaticAny _sa_lower( CORBA::_stc_ulonglong, &_par_lower );
  CORBA::StaticAny _sa_upper( CORBA::_stc_ulonglong, &_par_upper );
  CosTime::TIO_ptr _res = CosTime::TIO::_nil();
  CORBA::StaticAny __res( _marshaller_CosTime_TIO, &_res );

  CORBA::StaticRequest __req( this, "new_interval" );
  __req.add_in_arg( &_sa_lower );
  __req.add_in_arg( &_sa_upper );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosTime::TIO_ptr
CosTime::TimeService_stub_clp::new_interval( TimeBase::TimeT _par_lower, TimeBase::TimeT _par_upper )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosTime::TimeService * _myserv = POA_CosTime::TimeService::_narrow (_serv);
    if (_myserv) {
      CosTime::TIO_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->new_interval(_par_lower, _par_upper);
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

  return CosTime::TimeService_stub::new_interval(_par_lower, _par_upper);
}

#endif // MICO_CONF_NO_POA

struct __tc_init_COSTIME {
  __tc_init_COSTIME()
  {
    _marshaller_CosTime_TimeComparison = new _Marshaller_CosTime_TimeComparison;
    _marshaller_CosTime_ComparisonType = new _Marshaller_CosTime_ComparisonType;
    _marshaller_CosTime_OverlapType = new _Marshaller_CosTime_OverlapType;
    _marshaller_CosTime_TimeUnavailable = new _Marshaller_CosTime_TimeUnavailable;
    _marshaller_CosTime_UTO = new _Marshaller_CosTime_UTO;
    _marshaller_CosTime_TIO = new _Marshaller_CosTime_TIO;
    _marshaller_CosTime_TimeService = new _Marshaller_CosTime_TimeService;
  }

  ~__tc_init_COSTIME()
  {
    delete static_cast<_Marshaller_CosTime_TimeComparison*>(_marshaller_CosTime_TimeComparison);
    delete static_cast<_Marshaller_CosTime_ComparisonType*>(_marshaller_CosTime_ComparisonType);
    delete static_cast<_Marshaller_CosTime_OverlapType*>(_marshaller_CosTime_OverlapType);
    delete static_cast<_Marshaller_CosTime_TimeUnavailable*>(_marshaller_CosTime_TimeUnavailable);
    delete static_cast<_Marshaller_CosTime_UTO*>(_marshaller_CosTime_UTO);
    delete static_cast<_Marshaller_CosTime_TIO*>(_marshaller_CosTime_TIO);
    delete static_cast<_Marshaller_CosTime_TimeService*>(_marshaller_CosTime_TimeService);
  }
};

static __tc_init_COSTIME __init_COSTIME;

//--------------------------------------------------------
//  Implementation of skeletons
//--------------------------------------------------------

// PortableServer Skeleton Class for interface CosTime::UTO
POA_CosTime::UTO::~UTO()
{
}

::CosTime::UTO_ptr
POA_CosTime::UTO::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosTime::UTO::_narrow (obj);
}

CORBA::Boolean
POA_CosTime::UTO::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosTime/UTO:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosTime::UTO::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosTime/UTO:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosTime::UTO::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosTime/UTO:1.0");
}

CORBA::Object_ptr
POA_CosTime::UTO::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosTime::UTO_stub_clp (poa, obj);
}

bool
POA_CosTime::UTO::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    switch (mico_string_hash (__req->op_name(), 13)) {
    case 0:
      if( strcmp( __req->op_name(), "_get_utc_time" ) == 0 ) {
        ::TimeBase::UtcT _res;
        CORBA::StaticAny __res( _marshaller_TimeBase_UtcT, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = utc_time();
        __req->write_results();
        return true;
      }
      break;
    case 2:
      if( strcmp( __req->op_name(), "destroy" ) == 0 ) {

        if( !__req->read_args() )
          return true;

        destroy();
        __req->write_results();
        return true;
      }
      break;
    case 3:
      if( strcmp( __req->op_name(), "time_to_interval" ) == 0 ) {
        ::CosTime::UTO_var _par_uto;
        CORBA::StaticAny _sa_uto( _marshaller_CosTime_UTO, &_par_uto._for_demarshal() );

        ::CosTime::TIO_ptr _res;
        CORBA::StaticAny __res( _marshaller_CosTime_TIO, &_res );
        __req->add_in_arg( &_sa_uto );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = time_to_interval( _par_uto.inout() );
        __req->write_results();
        CORBA::release( _res );
        return true;
      }
      break;
    case 4:
      if( strcmp( __req->op_name(), "_get_tdf" ) == 0 ) {
        ::TimeBase::TdfT _res;
        CORBA::StaticAny __res( CORBA::_stc_short, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = tdf();
        __req->write_results();
        return true;
      }
      break;
    case 5:
      if( strcmp( __req->op_name(), "_get_time" ) == 0 ) {
        ::TimeBase::TimeT _res;
        CORBA::StaticAny __res( CORBA::_stc_ulonglong, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = time();
        __req->write_results();
        return true;
      }
      break;
    case 6:
      if( strcmp( __req->op_name(), "_get_inaccuracy" ) == 0 ) {
        ::TimeBase::InaccuracyT _res;
        CORBA::StaticAny __res( CORBA::_stc_ulonglong, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = inaccuracy();
        __req->write_results();
        return true;
      }
      break;
    case 9:
      if( strcmp( __req->op_name(), "compare_time" ) == 0 ) {
        ::CosTime::ComparisonType _par_comparison_type;
        CORBA::StaticAny _sa_comparison_type( _marshaller_CosTime_ComparisonType, &_par_comparison_type );
        ::CosTime::UTO_var _par_uto;
        CORBA::StaticAny _sa_uto( _marshaller_CosTime_UTO, &_par_uto._for_demarshal() );

        ::CosTime::TimeComparison _res;
        CORBA::StaticAny __res( _marshaller_CosTime_TimeComparison, &_res );
        __req->add_in_arg( &_sa_comparison_type );
        __req->add_in_arg( &_sa_uto );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = compare_time( _par_comparison_type, _par_uto.inout() );
        __req->write_results();
        return true;
      }
      break;
    case 12:
      if( strcmp( __req->op_name(), "absolute_time" ) == 0 ) {
        ::CosTime::UTO_ptr _res;
        CORBA::StaticAny __res( _marshaller_CosTime_UTO, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = absolute_time();
        __req->write_results();
        CORBA::release( _res );
        return true;
      }
      if( strcmp( __req->op_name(), "interval" ) == 0 ) {
        ::CosTime::TIO_ptr _res;
        CORBA::StaticAny __res( _marshaller_CosTime_TIO, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = interval();
        __req->write_results();
        CORBA::release( _res );
        return true;
      }
      break;
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
POA_CosTime::UTO::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface CosTime::TIO
POA_CosTime::TIO::~TIO()
{
}

::CosTime::TIO_ptr
POA_CosTime::TIO::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosTime::TIO::_narrow (obj);
}

CORBA::Boolean
POA_CosTime::TIO::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosTime/TIO:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosTime::TIO::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosTime/TIO:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosTime::TIO::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosTime/TIO:1.0");
}

CORBA::Object_ptr
POA_CosTime::TIO::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosTime::TIO_stub_clp (poa, obj);
}

bool
POA_CosTime::TIO::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    switch (mico_string_hash (__req->op_name(), 7)) {
    case 1:
      if( strcmp( __req->op_name(), "spans" ) == 0 ) {
        ::CosTime::UTO_var _par_time;
        CORBA::StaticAny _sa_time( _marshaller_CosTime_UTO, &_par_time._for_demarshal() );
        ::CosTime::TIO_ptr _par_overlap;
        CORBA::StaticAny _sa_overlap( _marshaller_CosTime_TIO, &_par_overlap );

        ::CosTime::OverlapType _res;
        CORBA::StaticAny __res( _marshaller_CosTime_OverlapType, &_res );
        __req->add_in_arg( &_sa_time );
        __req->add_out_arg( &_sa_overlap );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = spans( _par_time.inout(), _par_overlap );
        __req->write_results();
        CORBA::release( _par_overlap );
        return true;
      }
      if( strcmp( __req->op_name(), "time" ) == 0 ) {
        ::CosTime::UTO_ptr _res;
        CORBA::StaticAny __res( _marshaller_CosTime_UTO, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = time();
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
      break;
    case 4:
      if( strcmp( __req->op_name(), "_get_time_interval" ) == 0 ) {
        ::TimeBase::IntervalT _res;
        CORBA::StaticAny __res( _marshaller_TimeBase_IntervalT, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = time_interval();
        __req->write_results();
        return true;
      }
      break;
    case 5:
      if( strcmp( __req->op_name(), "overlaps" ) == 0 ) {
        ::CosTime::TIO_var _par_interval;
        CORBA::StaticAny _sa_interval( _marshaller_CosTime_TIO, &_par_interval._for_demarshal() );
        ::CosTime::TIO_ptr _par_overlap;
        CORBA::StaticAny _sa_overlap( _marshaller_CosTime_TIO, &_par_overlap );

        ::CosTime::OverlapType _res;
        CORBA::StaticAny __res( _marshaller_CosTime_OverlapType, &_res );
        __req->add_in_arg( &_sa_interval );
        __req->add_out_arg( &_sa_overlap );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = overlaps( _par_interval.inout(), _par_overlap );
        __req->write_results();
        CORBA::release( _par_overlap );
        return true;
      }
      break;
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
POA_CosTime::TIO::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface CosTime::TimeService
POA_CosTime::TimeService::~TimeService()
{
}

::CosTime::TimeService_ptr
POA_CosTime::TimeService::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosTime::TimeService::_narrow (obj);
}

CORBA::Boolean
POA_CosTime::TimeService::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosTime/TimeService:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosTime::TimeService::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosTime/TimeService:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosTime::TimeService::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosTime/TimeService:1.0");
}

CORBA::Object_ptr
POA_CosTime::TimeService::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosTime::TimeService_stub_clp (poa, obj);
}

bool
POA_CosTime::TimeService::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    switch (mico_string_hash (__req->op_name(), 7)) {
    case 2:
      if( strcmp( __req->op_name(), "new_universal_time" ) == 0 ) {
        ::TimeBase::TimeT _par_time;
        CORBA::StaticAny _sa_time( CORBA::_stc_ulonglong, &_par_time );
        ::TimeBase::InaccuracyT _par_inaccuracy;
        CORBA::StaticAny _sa_inaccuracy( CORBA::_stc_ulonglong, &_par_inaccuracy );
        ::TimeBase::TdfT _par_tdf;
        CORBA::StaticAny _sa_tdf( CORBA::_stc_short, &_par_tdf );

        ::CosTime::UTO_ptr _res;
        CORBA::StaticAny __res( _marshaller_CosTime_UTO, &_res );
        __req->add_in_arg( &_sa_time );
        __req->add_in_arg( &_sa_inaccuracy );
        __req->add_in_arg( &_sa_tdf );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = new_universal_time( _par_time, _par_inaccuracy, _par_tdf );
        __req->write_results();
        CORBA::release( _res );
        return true;
      }
      if( strcmp( __req->op_name(), "new_interval" ) == 0 ) {
        ::TimeBase::TimeT _par_lower;
        CORBA::StaticAny _sa_lower( CORBA::_stc_ulonglong, &_par_lower );
        ::TimeBase::TimeT _par_upper;
        CORBA::StaticAny _sa_upper( CORBA::_stc_ulonglong, &_par_upper );

        ::CosTime::TIO_ptr _res;
        CORBA::StaticAny __res( _marshaller_CosTime_TIO, &_res );
        __req->add_in_arg( &_sa_lower );
        __req->add_in_arg( &_sa_upper );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = new_interval( _par_lower, _par_upper );
        __req->write_results();
        CORBA::release( _res );
        return true;
      }
      break;
    case 4:
      if( strcmp( __req->op_name(), "secure_universal_time" ) == 0 ) {
        ::CosTime::UTO_ptr _res;
        CORBA::StaticAny __res( _marshaller_CosTime_UTO, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          _res = secure_universal_time();
        #ifdef HAVE_EXCEPTIONS
        } catch( ::CosTime::TimeUnavailable_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        CORBA::release( _res );
        return true;
      }
      break;
    case 5:
      if( strcmp( __req->op_name(), "uto_from_utc" ) == 0 ) {
        ::TimeBase::UtcT _par_utc;
        CORBA::StaticAny _sa_utc( _marshaller_TimeBase_UtcT, &_par_utc );

        ::CosTime::UTO_ptr _res;
        CORBA::StaticAny __res( _marshaller_CosTime_UTO, &_res );
        __req->add_in_arg( &_sa_utc );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = uto_from_utc( _par_utc );
        __req->write_results();
        CORBA::release( _res );
        return true;
      }
      break;
    case 6:
      if( strcmp( __req->op_name(), "universal_time" ) == 0 ) {
        ::CosTime::UTO_ptr _res;
        CORBA::StaticAny __res( _marshaller_CosTime_UTO, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          _res = universal_time();
        #ifdef HAVE_EXCEPTIONS
        } catch( ::CosTime::TimeUnavailable_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        CORBA::release( _res );
        return true;
      }
      break;
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
POA_CosTime::TimeService::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}

