/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <PropertyService.h>


using namespace std;

//--------------------------------------------------------
//  Implementation of stubs
//--------------------------------------------------------
namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertyName;
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_Property;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::Property::Property()
{
}

PropertyService::Property::Property( const Property& _s )
{
  property_name = ((Property&)_s).property_name;
  property_value = ((Property&)_s).property_value;
}

PropertyService::Property::~Property()
{
}

PropertyService::Property&
PropertyService::Property::operator=( const Property& _s )
{
  property_name = ((Property&)_s).property_name;
  property_value = ((Property&)_s).property_value;
  return *this;
}
#endif

class _Marshaller_PropertyService_Property : public ::CORBA::StaticTypeInfo {
    typedef PropertyService::Property _MICO_T;
  public:
    ~_Marshaller_PropertyService_Property();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_Property::~_Marshaller_PropertyService_Property()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_Property::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_Property::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_Property::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_Property::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->property_name._for_demarshal() ) &&
    CORBA::_stc_any->demarshal( dc, &((_MICO_T*)v)->property_value ) &&
    dc.struct_end();
}

void _Marshaller_PropertyService_Property::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->property_name.inout() );
  CORBA::_stc_any->marshal( ec, &((_MICO_T*)v)->property_value );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_Property::typecode()
{
  return PropertyService::_tc_Property;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_Property;

void operator<<=( CORBA::Any &_a, const PropertyService::Property &_s )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_Property, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, PropertyService::Property *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::Property &_s )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_Property, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const PropertyService::Property *&_s )
{
  return _a.to_static_any (_marshaller_PropertyService_Property, (void *&)_s);
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertyModeType;
}

void operator<<=( CORBA::Any &_a, const PropertyService::PropertyModeType &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertyModeType, &_e);
  _a.from_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::PropertyModeType &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertyModeType, &_e);
  return _a.to_static_any (_sa);
}

class _Marshaller_PropertyService_PropertyModeType : public ::CORBA::StaticTypeInfo {
    typedef PropertyService::PropertyModeType _MICO_T;
  public:
    ~_Marshaller_PropertyService_PropertyModeType();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_PropertyModeType::~_Marshaller_PropertyService_PropertyModeType()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_PropertyModeType::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_PropertyModeType::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_PropertyModeType::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_PropertyModeType::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong ul;
  if( !dc.enumeration( ul ) )
    return FALSE;
  *(_MICO_T*) v = (_MICO_T) ul;
  return TRUE;
}

void _Marshaller_PropertyService_PropertyModeType::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.enumeration( (::CORBA::ULong) *(_MICO_T *) v );
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_PropertyModeType::typecode()
{
  return PropertyService::_tc_PropertyModeType;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertyModeType;

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertyDef;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::PropertyDef::PropertyDef()
{
}

PropertyService::PropertyDef::PropertyDef( const PropertyDef& _s )
{
  property_name = ((PropertyDef&)_s).property_name;
  property_value = ((PropertyDef&)_s).property_value;
  property_mode = ((PropertyDef&)_s).property_mode;
}

PropertyService::PropertyDef::~PropertyDef()
{
}

PropertyService::PropertyDef&
PropertyService::PropertyDef::operator=( const PropertyDef& _s )
{
  property_name = ((PropertyDef&)_s).property_name;
  property_value = ((PropertyDef&)_s).property_value;
  property_mode = ((PropertyDef&)_s).property_mode;
  return *this;
}
#endif

class _Marshaller_PropertyService_PropertyDef : public ::CORBA::StaticTypeInfo {
    typedef PropertyService::PropertyDef _MICO_T;
  public:
    ~_Marshaller_PropertyService_PropertyDef();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_PropertyDef::~_Marshaller_PropertyService_PropertyDef()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_PropertyDef::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_PropertyDef::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_PropertyDef::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_PropertyDef::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->property_name._for_demarshal() ) &&
    CORBA::_stc_any->demarshal( dc, &((_MICO_T*)v)->property_value ) &&
    _marshaller_PropertyService_PropertyModeType->demarshal( dc, &((_MICO_T*)v)->property_mode ) &&
    dc.struct_end();
}

void _Marshaller_PropertyService_PropertyDef::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->property_name.inout() );
  CORBA::_stc_any->marshal( ec, &((_MICO_T*)v)->property_value );
  _marshaller_PropertyService_PropertyModeType->marshal( ec, &((_MICO_T*)v)->property_mode );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_PropertyDef::typecode()
{
  return PropertyService::_tc_PropertyDef;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertyDef;

void operator<<=( CORBA::Any &_a, const PropertyService::PropertyDef &_s )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertyDef, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, PropertyService::PropertyDef *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::PropertyDef &_s )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertyDef, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const PropertyService::PropertyDef *&_s )
{
  return _a.to_static_any (_marshaller_PropertyService_PropertyDef, (void *&)_s);
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertyMode;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::PropertyMode::PropertyMode()
{
}

PropertyService::PropertyMode::PropertyMode( const PropertyMode& _s )
{
  property_name = ((PropertyMode&)_s).property_name;
  property_mode = ((PropertyMode&)_s).property_mode;
}

PropertyService::PropertyMode::~PropertyMode()
{
}

PropertyService::PropertyMode&
PropertyService::PropertyMode::operator=( const PropertyMode& _s )
{
  property_name = ((PropertyMode&)_s).property_name;
  property_mode = ((PropertyMode&)_s).property_mode;
  return *this;
}
#endif

class _Marshaller_PropertyService_PropertyMode : public ::CORBA::StaticTypeInfo {
    typedef PropertyService::PropertyMode _MICO_T;
  public:
    ~_Marshaller_PropertyService_PropertyMode();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_PropertyMode::~_Marshaller_PropertyService_PropertyMode()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_PropertyMode::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_PropertyMode::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_PropertyMode::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_PropertyMode::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->property_name._for_demarshal() ) &&
    _marshaller_PropertyService_PropertyModeType->demarshal( dc, &((_MICO_T*)v)->property_mode ) &&
    dc.struct_end();
}

void _Marshaller_PropertyService_PropertyMode::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->property_name.inout() );
  _marshaller_PropertyService_PropertyModeType->marshal( ec, &((_MICO_T*)v)->property_mode );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_PropertyMode::typecode()
{
  return PropertyService::_tc_PropertyMode;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertyMode;

void operator<<=( CORBA::Any &_a, const PropertyService::PropertyMode &_s )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertyMode, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, PropertyService::PropertyMode *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::PropertyMode &_s )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertyMode, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const PropertyService::PropertyMode *&_s )
{
  return _a.to_static_any (_marshaller_PropertyService_PropertyMode, (void *&)_s);
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertyNames;
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_Properties;
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertyDefs;
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertyModes;
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertyTypes;
}


/*
 * Base interface for class PropertyNamesIterator
 */

PropertyService::PropertyNamesIterator::~PropertyNamesIterator()
{
}

void *
PropertyService::PropertyNamesIterator::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/PropertyService/PropertyNamesIterator:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

PropertyService::PropertyNamesIterator_ptr
PropertyService::PropertyNamesIterator::_narrow( CORBA::Object_ptr _obj )
{
  PropertyService::PropertyNamesIterator_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/PropertyService/PropertyNamesIterator:1.0" )))
      return _duplicate( (PropertyService::PropertyNamesIterator_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/PropertyService/PropertyNamesIterator:1.0") || _obj->_is_a_remote ("IDL:omg.org/PropertyService/PropertyNamesIterator:1.0")) {
      _o = new PropertyService::PropertyNamesIterator_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

PropertyService::PropertyNamesIterator_ptr
PropertyService::PropertyNamesIterator::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertyNamesIterator;
}
class _Marshaller_PropertyService_PropertyNamesIterator : public ::CORBA::StaticTypeInfo {
    typedef PropertyService::PropertyNamesIterator_ptr _MICO_T;
  public:
    ~_Marshaller_PropertyService_PropertyNamesIterator();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_PropertyNamesIterator::~_Marshaller_PropertyService_PropertyNamesIterator()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_PropertyNamesIterator::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_PropertyService_PropertyNamesIterator::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::PropertyService::PropertyNamesIterator::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_PropertyService_PropertyNamesIterator::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_PropertyService_PropertyNamesIterator::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_PropertyService_PropertyNamesIterator::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::PropertyService::PropertyNamesIterator::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_PropertyService_PropertyNamesIterator::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_PropertyNamesIterator::typecode()
{
  return PropertyService::_tc_PropertyNamesIterator;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertyNamesIterator;

void
operator<<=( CORBA::Any &_a, const PropertyService::PropertyNamesIterator_ptr _obj )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertyNamesIterator, &_obj);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, PropertyService::PropertyNamesIterator_ptr* _obj_ptr )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertyNamesIterator, _obj_ptr);
  _a.from_static_any (_sa);
  CORBA::release (*_obj_ptr);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, PropertyService::PropertyNamesIterator_ptr &_obj )
{
  PropertyService::PropertyNamesIterator_ptr *p;
  if (_a.to_static_any (_marshaller_PropertyService_PropertyNamesIterator, (void *&)p)) {
    _obj = *p;
    return TRUE;
  }
  return FALSE;
}


/*
 * Stub interface for class PropertyNamesIterator
 */

PropertyService::PropertyNamesIterator_stub::~PropertyNamesIterator_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_PropertyService::PropertyNamesIterator::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/PropertyService/PropertyNamesIterator:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_PropertyService::PropertyNamesIterator *
POA_PropertyService::PropertyNamesIterator::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/PropertyService/PropertyNamesIterator:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_PropertyService::PropertyNamesIterator *) p;
  }
  return NULL;
}

PropertyService::PropertyNamesIterator_stub_clp::PropertyNamesIterator_stub_clp ()
{
}

PropertyService::PropertyNamesIterator_stub_clp::PropertyNamesIterator_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

PropertyService::PropertyNamesIterator_stub_clp::~PropertyNamesIterator_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertyNamesIterator_stub::reset()
{
  CORBA::StaticRequest __req( this, "reset" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertyNamesIterator_stub_clp::reset()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertyNamesIterator * _myserv = POA_PropertyService::PropertyNamesIterator::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->reset();
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

  PropertyService::PropertyNamesIterator_stub::reset();
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean PropertyService::PropertyNamesIterator_stub::next_one( CORBA::String_out _par_propery_name )
{
  CORBA::StaticAny _sa_propery_name( CORBA::_stc_string, &_par_propery_name.ptr() );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "next_one" );
  __req.add_out_arg( &_sa_propery_name );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
PropertyService::PropertyNamesIterator_stub_clp::next_one( CORBA::String_out _par_propery_name )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertyNamesIterator * _myserv = POA_PropertyService::PropertyNamesIterator::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->next_one(_par_propery_name);
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

  return PropertyService::PropertyNamesIterator_stub::next_one(_par_propery_name);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean PropertyService::PropertyNamesIterator_stub::next_n( CORBA::ULong _par_how_many, PropertyService::PropertyNames_out _par_property_names )
{
  CORBA::StaticAny _sa_how_many( CORBA::_stc_ulong, &_par_how_many );
  CORBA::StaticAny _sa_property_names( CORBA::_stcseq_string );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "next_n" );
  __req.add_in_arg( &_sa_how_many );
  __req.add_out_arg( &_sa_property_names );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  _par_property_names = (PropertyService::PropertyNames*) _sa_property_names._retn();
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
PropertyService::PropertyNamesIterator_stub_clp::next_n( CORBA::ULong _par_how_many, PropertyService::PropertyNames_out _par_property_names )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertyNamesIterator * _myserv = POA_PropertyService::PropertyNamesIterator::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->next_n(_par_how_many, _par_property_names);
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

  return PropertyService::PropertyNamesIterator_stub::next_n(_par_how_many, _par_property_names);
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertyNamesIterator_stub::destroy()
{
  CORBA::StaticRequest __req( this, "destroy" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertyNamesIterator_stub_clp::destroy()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertyNamesIterator * _myserv = POA_PropertyService::PropertyNamesIterator::_narrow (_serv);
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

  PropertyService::PropertyNamesIterator_stub::destroy();
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class PropertiesIterator
 */

PropertyService::PropertiesIterator::~PropertiesIterator()
{
}

void *
PropertyService::PropertiesIterator::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/PropertyService/PropertiesIterator:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

PropertyService::PropertiesIterator_ptr
PropertyService::PropertiesIterator::_narrow( CORBA::Object_ptr _obj )
{
  PropertyService::PropertiesIterator_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/PropertyService/PropertiesIterator:1.0" )))
      return _duplicate( (PropertyService::PropertiesIterator_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/PropertyService/PropertiesIterator:1.0") || _obj->_is_a_remote ("IDL:omg.org/PropertyService/PropertiesIterator:1.0")) {
      _o = new PropertyService::PropertiesIterator_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

PropertyService::PropertiesIterator_ptr
PropertyService::PropertiesIterator::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertiesIterator;
}
class _Marshaller_PropertyService_PropertiesIterator : public ::CORBA::StaticTypeInfo {
    typedef PropertyService::PropertiesIterator_ptr _MICO_T;
  public:
    ~_Marshaller_PropertyService_PropertiesIterator();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_PropertiesIterator::~_Marshaller_PropertyService_PropertiesIterator()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_PropertiesIterator::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_PropertyService_PropertiesIterator::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::PropertyService::PropertiesIterator::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_PropertyService_PropertiesIterator::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_PropertyService_PropertiesIterator::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_PropertyService_PropertiesIterator::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::PropertyService::PropertiesIterator::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_PropertyService_PropertiesIterator::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_PropertiesIterator::typecode()
{
  return PropertyService::_tc_PropertiesIterator;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertiesIterator;

void
operator<<=( CORBA::Any &_a, const PropertyService::PropertiesIterator_ptr _obj )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertiesIterator, &_obj);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, PropertyService::PropertiesIterator_ptr* _obj_ptr )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertiesIterator, _obj_ptr);
  _a.from_static_any (_sa);
  CORBA::release (*_obj_ptr);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, PropertyService::PropertiesIterator_ptr &_obj )
{
  PropertyService::PropertiesIterator_ptr *p;
  if (_a.to_static_any (_marshaller_PropertyService_PropertiesIterator, (void *&)p)) {
    _obj = *p;
    return TRUE;
  }
  return FALSE;
}


/*
 * Stub interface for class PropertiesIterator
 */

PropertyService::PropertiesIterator_stub::~PropertiesIterator_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_PropertyService::PropertiesIterator::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/PropertyService/PropertiesIterator:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_PropertyService::PropertiesIterator *
POA_PropertyService::PropertiesIterator::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/PropertyService/PropertiesIterator:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_PropertyService::PropertiesIterator *) p;
  }
  return NULL;
}

PropertyService::PropertiesIterator_stub_clp::PropertiesIterator_stub_clp ()
{
}

PropertyService::PropertiesIterator_stub_clp::PropertiesIterator_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

PropertyService::PropertiesIterator_stub_clp::~PropertiesIterator_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertiesIterator_stub::reset()
{
  CORBA::StaticRequest __req( this, "reset" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertiesIterator_stub_clp::reset()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertiesIterator * _myserv = POA_PropertyService::PropertiesIterator::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->reset();
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

  PropertyService::PropertiesIterator_stub::reset();
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean PropertyService::PropertiesIterator_stub::next_one( PropertyService::Property_out _par_aproperty )
{
  CORBA::StaticAny _sa_aproperty( _marshaller_PropertyService_Property );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "next_one" );
  __req.add_out_arg( &_sa_aproperty );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  _par_aproperty = (PropertyService::Property*) _sa_aproperty._retn();
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
PropertyService::PropertiesIterator_stub_clp::next_one( PropertyService::Property_out _par_aproperty )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertiesIterator * _myserv = POA_PropertyService::PropertiesIterator::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->next_one(_par_aproperty);
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

  return PropertyService::PropertiesIterator_stub::next_one(_par_aproperty);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean PropertyService::PropertiesIterator_stub::next_n( CORBA::ULong _par_how_many, PropertyService::Properties_out _par_nproperties )
{
  CORBA::StaticAny _sa_how_many( CORBA::_stc_ulong, &_par_how_many );
  CORBA::StaticAny _sa_nproperties( _marshaller__seq_PropertyService_Property );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "next_n" );
  __req.add_in_arg( &_sa_how_many );
  __req.add_out_arg( &_sa_nproperties );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  _par_nproperties = (PropertyService::Properties*) _sa_nproperties._retn();
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
PropertyService::PropertiesIterator_stub_clp::next_n( CORBA::ULong _par_how_many, PropertyService::Properties_out _par_nproperties )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertiesIterator * _myserv = POA_PropertyService::PropertiesIterator::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->next_n(_par_how_many, _par_nproperties);
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

  return PropertyService::PropertiesIterator_stub::next_n(_par_how_many, _par_nproperties);
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertiesIterator_stub::destroy()
{
  CORBA::StaticRequest __req( this, "destroy" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertiesIterator_stub_clp::destroy()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertiesIterator * _myserv = POA_PropertyService::PropertiesIterator::_narrow (_serv);
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

  PropertyService::PropertiesIterator_stub::destroy();
}

#endif // MICO_CONF_NO_POA

namespace PropertyService
{
CORBA::TypeCodeConst _tc_ConstraintNotSupported;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::ConstraintNotSupported::ConstraintNotSupported()
{
}

PropertyService::ConstraintNotSupported::ConstraintNotSupported( const ConstraintNotSupported& _s )
{
}

PropertyService::ConstraintNotSupported::~ConstraintNotSupported()
{
}

PropertyService::ConstraintNotSupported&
PropertyService::ConstraintNotSupported::operator=( const ConstraintNotSupported& _s )
{
  return *this;
}
#endif

class _Marshaller_PropertyService_ConstraintNotSupported : public ::CORBA::StaticTypeInfo {
    typedef ::PropertyService::ConstraintNotSupported _MICO_T;
  public:
    ~_Marshaller_PropertyService_ConstraintNotSupported();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_ConstraintNotSupported::~_Marshaller_PropertyService_ConstraintNotSupported()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_ConstraintNotSupported::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_ConstraintNotSupported::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_ConstraintNotSupported::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_ConstraintNotSupported::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_PropertyService_ConstraintNotSupported::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/PropertyService/ConstraintNotSupported:1.0" );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_ConstraintNotSupported::typecode()
{
  return PropertyService::_tc_ConstraintNotSupported;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_ConstraintNotSupported;

void operator<<=( CORBA::Any &_a, const PropertyService::ConstraintNotSupported &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_ConstraintNotSupported, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, PropertyService::ConstraintNotSupported *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::ConstraintNotSupported &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_ConstraintNotSupported, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const PropertyService::ConstraintNotSupported *&_e )
{
  return _a.to_static_any (_marshaller_PropertyService_ConstraintNotSupported, (void *&)_e);
}

void PropertyService::ConstraintNotSupported::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw ConstraintNotSupported_var( (PropertyService::ConstraintNotSupported*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *PropertyService::ConstraintNotSupported::_repoid() const
{
  return "IDL:omg.org/PropertyService/ConstraintNotSupported:1.0";
}

void PropertyService::ConstraintNotSupported::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_PropertyService_ConstraintNotSupported->marshal( _en, (void*) this );
}

void PropertyService::ConstraintNotSupported::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *PropertyService::ConstraintNotSupported::_clone() const
{
  return new ConstraintNotSupported( *this );
}

PropertyService::ConstraintNotSupported *PropertyService::ConstraintNotSupported::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/ConstraintNotSupported:1.0" ) )
    return (ConstraintNotSupported *) _ex;
  return NULL;
}

const PropertyService::ConstraintNotSupported *PropertyService::ConstraintNotSupported::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/ConstraintNotSupported:1.0" ) )
    return (ConstraintNotSupported *) _ex;
  return NULL;
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertyExceptions;
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_MultipleExceptions;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::MultipleExceptions::MultipleExceptions()
{
}

PropertyService::MultipleExceptions::MultipleExceptions( const MultipleExceptions& _s )
{
  exceptions = ((MultipleExceptions&)_s).exceptions;
}

PropertyService::MultipleExceptions::~MultipleExceptions()
{
}

PropertyService::MultipleExceptions&
PropertyService::MultipleExceptions::operator=( const MultipleExceptions& _s )
{
  exceptions = ((MultipleExceptions&)_s).exceptions;
  return *this;
}
#endif

#ifndef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::MultipleExceptions::MultipleExceptions()
{
}

#endif

PropertyService::MultipleExceptions::MultipleExceptions( const PropertyService::PropertyExceptions& _m0 )
{
  exceptions = _m0;
}

class _Marshaller_PropertyService_MultipleExceptions : public ::CORBA::StaticTypeInfo {
    typedef ::PropertyService::MultipleExceptions _MICO_T;
  public:
    ~_Marshaller_PropertyService_MultipleExceptions();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_MultipleExceptions::~_Marshaller_PropertyService_MultipleExceptions()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_MultipleExceptions::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_MultipleExceptions::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_MultipleExceptions::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_MultipleExceptions::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    _marshaller__seq_PropertyService_PropertyException->demarshal( dc, &((_MICO_T*)v)->exceptions ) &&
    dc.except_end();
}

void _Marshaller_PropertyService_MultipleExceptions::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/PropertyService/MultipleExceptions:1.0" );
  _marshaller__seq_PropertyService_PropertyException->marshal( ec, &((_MICO_T*)v)->exceptions );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_MultipleExceptions::typecode()
{
  return PropertyService::_tc_MultipleExceptions;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_MultipleExceptions;

void operator<<=( CORBA::Any &_a, const PropertyService::MultipleExceptions &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_MultipleExceptions, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, PropertyService::MultipleExceptions *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::MultipleExceptions &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_MultipleExceptions, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const PropertyService::MultipleExceptions *&_e )
{
  return _a.to_static_any (_marshaller_PropertyService_MultipleExceptions, (void *&)_e);
}

void PropertyService::MultipleExceptions::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw MultipleExceptions_var( (PropertyService::MultipleExceptions*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *PropertyService::MultipleExceptions::_repoid() const
{
  return "IDL:omg.org/PropertyService/MultipleExceptions:1.0";
}

void PropertyService::MultipleExceptions::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_PropertyService_MultipleExceptions->marshal( _en, (void*) this );
}

void PropertyService::MultipleExceptions::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *PropertyService::MultipleExceptions::_clone() const
{
  return new MultipleExceptions( *this );
}

PropertyService::MultipleExceptions *PropertyService::MultipleExceptions::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/MultipleExceptions:1.0" ) )
    return (MultipleExceptions *) _ex;
  return NULL;
}

const PropertyService::MultipleExceptions *PropertyService::MultipleExceptions::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/MultipleExceptions:1.0" ) )
    return (MultipleExceptions *) _ex;
  return NULL;
}


/*
 * Base interface for class PropertySetFactory
 */

PropertyService::PropertySetFactory::~PropertySetFactory()
{
}

void *
PropertyService::PropertySetFactory::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/PropertyService/PropertySetFactory:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

PropertyService::PropertySetFactory_ptr
PropertyService::PropertySetFactory::_narrow( CORBA::Object_ptr _obj )
{
  PropertyService::PropertySetFactory_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/PropertyService/PropertySetFactory:1.0" )))
      return _duplicate( (PropertyService::PropertySetFactory_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/PropertyService/PropertySetFactory:1.0") || _obj->_is_a_remote ("IDL:omg.org/PropertyService/PropertySetFactory:1.0")) {
      _o = new PropertyService::PropertySetFactory_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

PropertyService::PropertySetFactory_ptr
PropertyService::PropertySetFactory::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertySetFactory;
}
class _Marshaller_PropertyService_PropertySetFactory : public ::CORBA::StaticTypeInfo {
    typedef PropertyService::PropertySetFactory_ptr _MICO_T;
  public:
    ~_Marshaller_PropertyService_PropertySetFactory();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_PropertySetFactory::~_Marshaller_PropertyService_PropertySetFactory()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_PropertySetFactory::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_PropertyService_PropertySetFactory::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::PropertyService::PropertySetFactory::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_PropertyService_PropertySetFactory::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_PropertyService_PropertySetFactory::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_PropertyService_PropertySetFactory::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::PropertyService::PropertySetFactory::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_PropertyService_PropertySetFactory::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_PropertySetFactory::typecode()
{
  return PropertyService::_tc_PropertySetFactory;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertySetFactory;

void
operator<<=( CORBA::Any &_a, const PropertyService::PropertySetFactory_ptr _obj )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertySetFactory, &_obj);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, PropertyService::PropertySetFactory_ptr* _obj_ptr )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertySetFactory, _obj_ptr);
  _a.from_static_any (_sa);
  CORBA::release (*_obj_ptr);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, PropertyService::PropertySetFactory_ptr &_obj )
{
  PropertyService::PropertySetFactory_ptr *p;
  if (_a.to_static_any (_marshaller_PropertyService_PropertySetFactory, (void *&)p)) {
    _obj = *p;
    return TRUE;
  }
  return FALSE;
}


/*
 * Stub interface for class PropertySetFactory
 */

PropertyService::PropertySetFactory_stub::~PropertySetFactory_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_PropertyService::PropertySetFactory::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/PropertyService/PropertySetFactory:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_PropertyService::PropertySetFactory *
POA_PropertyService::PropertySetFactory::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/PropertyService/PropertySetFactory:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_PropertyService::PropertySetFactory *) p;
  }
  return NULL;
}

PropertyService::PropertySetFactory_stub_clp::PropertySetFactory_stub_clp ()
{
}

PropertyService::PropertySetFactory_stub_clp::PropertySetFactory_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

PropertyService::PropertySetFactory_stub_clp::~PropertySetFactory_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

PropertyService::PropertySet_ptr PropertyService::PropertySetFactory_stub::create_propertyset()
{
  PropertyService::PropertySet_ptr _res = PropertyService::PropertySet::_nil();
  CORBA::StaticAny __res( _marshaller_PropertyService_PropertySet, &_res );

  CORBA::StaticRequest __req( this, "create_propertyset" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

PropertyService::PropertySet_ptr
PropertyService::PropertySetFactory_stub_clp::create_propertyset()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySetFactory * _myserv = POA_PropertyService::PropertySetFactory::_narrow (_serv);
    if (_myserv) {
      PropertyService::PropertySet_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->create_propertyset();
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

  return PropertyService::PropertySetFactory_stub::create_propertyset();
}

#endif // MICO_CONF_NO_POA

PropertyService::PropertySet_ptr PropertyService::PropertySetFactory_stub::create_constrained_propertyset( const PropertyService::PropertyTypes& _par_allowed_property_types, const PropertyService::Properties& _par_allowed_properties )
{
  CORBA::StaticAny _sa_allowed_property_types( _marshaller__seq_TypeCode, &_par_allowed_property_types );
  CORBA::StaticAny _sa_allowed_properties( _marshaller__seq_PropertyService_Property, &_par_allowed_properties );
  PropertyService::PropertySet_ptr _res = PropertyService::PropertySet::_nil();
  CORBA::StaticAny __res( _marshaller_PropertyService_PropertySet, &_res );

  CORBA::StaticRequest __req( this, "create_constrained_propertyset" );
  __req.add_in_arg( &_sa_allowed_property_types );
  __req.add_in_arg( &_sa_allowed_properties );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_ConstraintNotSupported, "IDL:omg.org/PropertyService/ConstraintNotSupported:1.0",
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

PropertyService::PropertySet_ptr
PropertyService::PropertySetFactory_stub_clp::create_constrained_propertyset( const PropertyService::PropertyTypes& _par_allowed_property_types, const PropertyService::Properties& _par_allowed_properties )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySetFactory * _myserv = POA_PropertyService::PropertySetFactory::_narrow (_serv);
    if (_myserv) {
      PropertyService::PropertySet_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->create_constrained_propertyset(_par_allowed_property_types, _par_allowed_properties);
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

  return PropertyService::PropertySetFactory_stub::create_constrained_propertyset(_par_allowed_property_types, _par_allowed_properties);
}

#endif // MICO_CONF_NO_POA

PropertyService::PropertySet_ptr PropertyService::PropertySetFactory_stub::create_initial_propertyset( const PropertyService::Properties& _par_initial_properties )
{
  CORBA::StaticAny _sa_initial_properties( _marshaller__seq_PropertyService_Property, &_par_initial_properties );
  PropertyService::PropertySet_ptr _res = PropertyService::PropertySet::_nil();
  CORBA::StaticAny __res( _marshaller_PropertyService_PropertySet, &_res );

  CORBA::StaticRequest __req( this, "create_initial_propertyset" );
  __req.add_in_arg( &_sa_initial_properties );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_MultipleExceptions, "IDL:omg.org/PropertyService/MultipleExceptions:1.0",
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

PropertyService::PropertySet_ptr
PropertyService::PropertySetFactory_stub_clp::create_initial_propertyset( const PropertyService::Properties& _par_initial_properties )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySetFactory * _myserv = POA_PropertyService::PropertySetFactory::_narrow (_serv);
    if (_myserv) {
      PropertyService::PropertySet_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->create_initial_propertyset(_par_initial_properties);
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

  return PropertyService::PropertySetFactory_stub::create_initial_propertyset(_par_initial_properties);
}

#endif // MICO_CONF_NO_POA

namespace PropertyService
{
CORBA::TypeCodeConst _tc_InvalidPropertyName;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::InvalidPropertyName::InvalidPropertyName()
{
}

PropertyService::InvalidPropertyName::InvalidPropertyName( const InvalidPropertyName& _s )
{
}

PropertyService::InvalidPropertyName::~InvalidPropertyName()
{
}

PropertyService::InvalidPropertyName&
PropertyService::InvalidPropertyName::operator=( const InvalidPropertyName& _s )
{
  return *this;
}
#endif

class _Marshaller_PropertyService_InvalidPropertyName : public ::CORBA::StaticTypeInfo {
    typedef ::PropertyService::InvalidPropertyName _MICO_T;
  public:
    ~_Marshaller_PropertyService_InvalidPropertyName();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_InvalidPropertyName::~_Marshaller_PropertyService_InvalidPropertyName()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_InvalidPropertyName::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_InvalidPropertyName::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_InvalidPropertyName::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_InvalidPropertyName::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_PropertyService_InvalidPropertyName::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/PropertyService/InvalidPropertyName:1.0" );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_InvalidPropertyName::typecode()
{
  return PropertyService::_tc_InvalidPropertyName;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_InvalidPropertyName;

void operator<<=( CORBA::Any &_a, const PropertyService::InvalidPropertyName &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_InvalidPropertyName, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, PropertyService::InvalidPropertyName *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::InvalidPropertyName &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_InvalidPropertyName, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const PropertyService::InvalidPropertyName *&_e )
{
  return _a.to_static_any (_marshaller_PropertyService_InvalidPropertyName, (void *&)_e);
}

void PropertyService::InvalidPropertyName::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw InvalidPropertyName_var( (PropertyService::InvalidPropertyName*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *PropertyService::InvalidPropertyName::_repoid() const
{
  return "IDL:omg.org/PropertyService/InvalidPropertyName:1.0";
}

void PropertyService::InvalidPropertyName::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_PropertyService_InvalidPropertyName->marshal( _en, (void*) this );
}

void PropertyService::InvalidPropertyName::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *PropertyService::InvalidPropertyName::_clone() const
{
  return new InvalidPropertyName( *this );
}

PropertyService::InvalidPropertyName *PropertyService::InvalidPropertyName::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/InvalidPropertyName:1.0" ) )
    return (InvalidPropertyName *) _ex;
  return NULL;
}

const PropertyService::InvalidPropertyName *PropertyService::InvalidPropertyName::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/InvalidPropertyName:1.0" ) )
    return (InvalidPropertyName *) _ex;
  return NULL;
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_ConflictingProperty;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::ConflictingProperty::ConflictingProperty()
{
}

PropertyService::ConflictingProperty::ConflictingProperty( const ConflictingProperty& _s )
{
}

PropertyService::ConflictingProperty::~ConflictingProperty()
{
}

PropertyService::ConflictingProperty&
PropertyService::ConflictingProperty::operator=( const ConflictingProperty& _s )
{
  return *this;
}
#endif

class _Marshaller_PropertyService_ConflictingProperty : public ::CORBA::StaticTypeInfo {
    typedef ::PropertyService::ConflictingProperty _MICO_T;
  public:
    ~_Marshaller_PropertyService_ConflictingProperty();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_ConflictingProperty::~_Marshaller_PropertyService_ConflictingProperty()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_ConflictingProperty::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_ConflictingProperty::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_ConflictingProperty::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_ConflictingProperty::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_PropertyService_ConflictingProperty::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/PropertyService/ConflictingProperty:1.0" );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_ConflictingProperty::typecode()
{
  return PropertyService::_tc_ConflictingProperty;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_ConflictingProperty;

void operator<<=( CORBA::Any &_a, const PropertyService::ConflictingProperty &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_ConflictingProperty, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, PropertyService::ConflictingProperty *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::ConflictingProperty &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_ConflictingProperty, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const PropertyService::ConflictingProperty *&_e )
{
  return _a.to_static_any (_marshaller_PropertyService_ConflictingProperty, (void *&)_e);
}

void PropertyService::ConflictingProperty::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw ConflictingProperty_var( (PropertyService::ConflictingProperty*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *PropertyService::ConflictingProperty::_repoid() const
{
  return "IDL:omg.org/PropertyService/ConflictingProperty:1.0";
}

void PropertyService::ConflictingProperty::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_PropertyService_ConflictingProperty->marshal( _en, (void*) this );
}

void PropertyService::ConflictingProperty::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *PropertyService::ConflictingProperty::_clone() const
{
  return new ConflictingProperty( *this );
}

PropertyService::ConflictingProperty *PropertyService::ConflictingProperty::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/ConflictingProperty:1.0" ) )
    return (ConflictingProperty *) _ex;
  return NULL;
}

const PropertyService::ConflictingProperty *PropertyService::ConflictingProperty::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/ConflictingProperty:1.0" ) )
    return (ConflictingProperty *) _ex;
  return NULL;
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_UnsupportedTypeCode;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::UnsupportedTypeCode::UnsupportedTypeCode()
{
}

PropertyService::UnsupportedTypeCode::UnsupportedTypeCode( const UnsupportedTypeCode& _s )
{
}

PropertyService::UnsupportedTypeCode::~UnsupportedTypeCode()
{
}

PropertyService::UnsupportedTypeCode&
PropertyService::UnsupportedTypeCode::operator=( const UnsupportedTypeCode& _s )
{
  return *this;
}
#endif

class _Marshaller_PropertyService_UnsupportedTypeCode : public ::CORBA::StaticTypeInfo {
    typedef ::PropertyService::UnsupportedTypeCode _MICO_T;
  public:
    ~_Marshaller_PropertyService_UnsupportedTypeCode();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_UnsupportedTypeCode::~_Marshaller_PropertyService_UnsupportedTypeCode()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_UnsupportedTypeCode::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_UnsupportedTypeCode::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_UnsupportedTypeCode::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_UnsupportedTypeCode::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_PropertyService_UnsupportedTypeCode::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/PropertyService/UnsupportedTypeCode:1.0" );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_UnsupportedTypeCode::typecode()
{
  return PropertyService::_tc_UnsupportedTypeCode;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_UnsupportedTypeCode;

void operator<<=( CORBA::Any &_a, const PropertyService::UnsupportedTypeCode &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_UnsupportedTypeCode, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, PropertyService::UnsupportedTypeCode *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::UnsupportedTypeCode &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_UnsupportedTypeCode, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const PropertyService::UnsupportedTypeCode *&_e )
{
  return _a.to_static_any (_marshaller_PropertyService_UnsupportedTypeCode, (void *&)_e);
}

void PropertyService::UnsupportedTypeCode::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw UnsupportedTypeCode_var( (PropertyService::UnsupportedTypeCode*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *PropertyService::UnsupportedTypeCode::_repoid() const
{
  return "IDL:omg.org/PropertyService/UnsupportedTypeCode:1.0";
}

void PropertyService::UnsupportedTypeCode::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_PropertyService_UnsupportedTypeCode->marshal( _en, (void*) this );
}

void PropertyService::UnsupportedTypeCode::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *PropertyService::UnsupportedTypeCode::_clone() const
{
  return new UnsupportedTypeCode( *this );
}

PropertyService::UnsupportedTypeCode *PropertyService::UnsupportedTypeCode::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/UnsupportedTypeCode:1.0" ) )
    return (UnsupportedTypeCode *) _ex;
  return NULL;
}

const PropertyService::UnsupportedTypeCode *PropertyService::UnsupportedTypeCode::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/UnsupportedTypeCode:1.0" ) )
    return (UnsupportedTypeCode *) _ex;
  return NULL;
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_UnsupportedProperty;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::UnsupportedProperty::UnsupportedProperty()
{
}

PropertyService::UnsupportedProperty::UnsupportedProperty( const UnsupportedProperty& _s )
{
}

PropertyService::UnsupportedProperty::~UnsupportedProperty()
{
}

PropertyService::UnsupportedProperty&
PropertyService::UnsupportedProperty::operator=( const UnsupportedProperty& _s )
{
  return *this;
}
#endif

class _Marshaller_PropertyService_UnsupportedProperty : public ::CORBA::StaticTypeInfo {
    typedef ::PropertyService::UnsupportedProperty _MICO_T;
  public:
    ~_Marshaller_PropertyService_UnsupportedProperty();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_UnsupportedProperty::~_Marshaller_PropertyService_UnsupportedProperty()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_UnsupportedProperty::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_UnsupportedProperty::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_UnsupportedProperty::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_UnsupportedProperty::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_PropertyService_UnsupportedProperty::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/PropertyService/UnsupportedProperty:1.0" );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_UnsupportedProperty::typecode()
{
  return PropertyService::_tc_UnsupportedProperty;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_UnsupportedProperty;

void operator<<=( CORBA::Any &_a, const PropertyService::UnsupportedProperty &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_UnsupportedProperty, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, PropertyService::UnsupportedProperty *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::UnsupportedProperty &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_UnsupportedProperty, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const PropertyService::UnsupportedProperty *&_e )
{
  return _a.to_static_any (_marshaller_PropertyService_UnsupportedProperty, (void *&)_e);
}

void PropertyService::UnsupportedProperty::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw UnsupportedProperty_var( (PropertyService::UnsupportedProperty*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *PropertyService::UnsupportedProperty::_repoid() const
{
  return "IDL:omg.org/PropertyService/UnsupportedProperty:1.0";
}

void PropertyService::UnsupportedProperty::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_PropertyService_UnsupportedProperty->marshal( _en, (void*) this );
}

void PropertyService::UnsupportedProperty::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *PropertyService::UnsupportedProperty::_clone() const
{
  return new UnsupportedProperty( *this );
}

PropertyService::UnsupportedProperty *PropertyService::UnsupportedProperty::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/UnsupportedProperty:1.0" ) )
    return (UnsupportedProperty *) _ex;
  return NULL;
}

const PropertyService::UnsupportedProperty *PropertyService::UnsupportedProperty::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/UnsupportedProperty:1.0" ) )
    return (UnsupportedProperty *) _ex;
  return NULL;
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_ReadOnlyProperty;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::ReadOnlyProperty::ReadOnlyProperty()
{
}

PropertyService::ReadOnlyProperty::ReadOnlyProperty( const ReadOnlyProperty& _s )
{
}

PropertyService::ReadOnlyProperty::~ReadOnlyProperty()
{
}

PropertyService::ReadOnlyProperty&
PropertyService::ReadOnlyProperty::operator=( const ReadOnlyProperty& _s )
{
  return *this;
}
#endif

class _Marshaller_PropertyService_ReadOnlyProperty : public ::CORBA::StaticTypeInfo {
    typedef ::PropertyService::ReadOnlyProperty _MICO_T;
  public:
    ~_Marshaller_PropertyService_ReadOnlyProperty();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_ReadOnlyProperty::~_Marshaller_PropertyService_ReadOnlyProperty()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_ReadOnlyProperty::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_ReadOnlyProperty::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_ReadOnlyProperty::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_ReadOnlyProperty::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_PropertyService_ReadOnlyProperty::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/PropertyService/ReadOnlyProperty:1.0" );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_ReadOnlyProperty::typecode()
{
  return PropertyService::_tc_ReadOnlyProperty;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_ReadOnlyProperty;

void operator<<=( CORBA::Any &_a, const PropertyService::ReadOnlyProperty &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_ReadOnlyProperty, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, PropertyService::ReadOnlyProperty *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::ReadOnlyProperty &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_ReadOnlyProperty, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const PropertyService::ReadOnlyProperty *&_e )
{
  return _a.to_static_any (_marshaller_PropertyService_ReadOnlyProperty, (void *&)_e);
}

void PropertyService::ReadOnlyProperty::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw ReadOnlyProperty_var( (PropertyService::ReadOnlyProperty*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *PropertyService::ReadOnlyProperty::_repoid() const
{
  return "IDL:omg.org/PropertyService/ReadOnlyProperty:1.0";
}

void PropertyService::ReadOnlyProperty::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_PropertyService_ReadOnlyProperty->marshal( _en, (void*) this );
}

void PropertyService::ReadOnlyProperty::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *PropertyService::ReadOnlyProperty::_clone() const
{
  return new ReadOnlyProperty( *this );
}

PropertyService::ReadOnlyProperty *PropertyService::ReadOnlyProperty::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/ReadOnlyProperty:1.0" ) )
    return (ReadOnlyProperty *) _ex;
  return NULL;
}

const PropertyService::ReadOnlyProperty *PropertyService::ReadOnlyProperty::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/ReadOnlyProperty:1.0" ) )
    return (ReadOnlyProperty *) _ex;
  return NULL;
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertyNotFound;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::PropertyNotFound::PropertyNotFound()
{
}

PropertyService::PropertyNotFound::PropertyNotFound( const PropertyNotFound& _s )
{
}

PropertyService::PropertyNotFound::~PropertyNotFound()
{
}

PropertyService::PropertyNotFound&
PropertyService::PropertyNotFound::operator=( const PropertyNotFound& _s )
{
  return *this;
}
#endif

class _Marshaller_PropertyService_PropertyNotFound : public ::CORBA::StaticTypeInfo {
    typedef ::PropertyService::PropertyNotFound _MICO_T;
  public:
    ~_Marshaller_PropertyService_PropertyNotFound();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_PropertyNotFound::~_Marshaller_PropertyService_PropertyNotFound()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_PropertyNotFound::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_PropertyNotFound::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_PropertyNotFound::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_PropertyNotFound::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_PropertyService_PropertyNotFound::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/PropertyService/PropertyNotFound:1.0" );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_PropertyNotFound::typecode()
{
  return PropertyService::_tc_PropertyNotFound;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertyNotFound;

void operator<<=( CORBA::Any &_a, const PropertyService::PropertyNotFound &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertyNotFound, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, PropertyService::PropertyNotFound *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::PropertyNotFound &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertyNotFound, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const PropertyService::PropertyNotFound *&_e )
{
  return _a.to_static_any (_marshaller_PropertyService_PropertyNotFound, (void *&)_e);
}

void PropertyService::PropertyNotFound::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw PropertyNotFound_var( (PropertyService::PropertyNotFound*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *PropertyService::PropertyNotFound::_repoid() const
{
  return "IDL:omg.org/PropertyService/PropertyNotFound:1.0";
}

void PropertyService::PropertyNotFound::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_PropertyService_PropertyNotFound->marshal( _en, (void*) this );
}

void PropertyService::PropertyNotFound::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *PropertyService::PropertyNotFound::_clone() const
{
  return new PropertyNotFound( *this );
}

PropertyService::PropertyNotFound *PropertyService::PropertyNotFound::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/PropertyNotFound:1.0" ) )
    return (PropertyNotFound *) _ex;
  return NULL;
}

const PropertyService::PropertyNotFound *PropertyService::PropertyNotFound::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/PropertyNotFound:1.0" ) )
    return (PropertyNotFound *) _ex;
  return NULL;
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_FixedProperty;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::FixedProperty::FixedProperty()
{
}

PropertyService::FixedProperty::FixedProperty( const FixedProperty& _s )
{
}

PropertyService::FixedProperty::~FixedProperty()
{
}

PropertyService::FixedProperty&
PropertyService::FixedProperty::operator=( const FixedProperty& _s )
{
  return *this;
}
#endif

class _Marshaller_PropertyService_FixedProperty : public ::CORBA::StaticTypeInfo {
    typedef ::PropertyService::FixedProperty _MICO_T;
  public:
    ~_Marshaller_PropertyService_FixedProperty();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_FixedProperty::~_Marshaller_PropertyService_FixedProperty()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_FixedProperty::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_FixedProperty::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_FixedProperty::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_FixedProperty::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_PropertyService_FixedProperty::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/PropertyService/FixedProperty:1.0" );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_FixedProperty::typecode()
{
  return PropertyService::_tc_FixedProperty;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_FixedProperty;

void operator<<=( CORBA::Any &_a, const PropertyService::FixedProperty &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_FixedProperty, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, PropertyService::FixedProperty *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::FixedProperty &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_FixedProperty, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const PropertyService::FixedProperty *&_e )
{
  return _a.to_static_any (_marshaller_PropertyService_FixedProperty, (void *&)_e);
}

void PropertyService::FixedProperty::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw FixedProperty_var( (PropertyService::FixedProperty*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *PropertyService::FixedProperty::_repoid() const
{
  return "IDL:omg.org/PropertyService/FixedProperty:1.0";
}

void PropertyService::FixedProperty::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_PropertyService_FixedProperty->marshal( _en, (void*) this );
}

void PropertyService::FixedProperty::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *PropertyService::FixedProperty::_clone() const
{
  return new FixedProperty( *this );
}

PropertyService::FixedProperty *PropertyService::FixedProperty::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/FixedProperty:1.0" ) )
    return (FixedProperty *) _ex;
  return NULL;
}

const PropertyService::FixedProperty *PropertyService::FixedProperty::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/FixedProperty:1.0" ) )
    return (FixedProperty *) _ex;
  return NULL;
}


/*
 * Base interface for class PropertySet
 */

PropertyService::PropertySet::~PropertySet()
{
}

void *
PropertyService::PropertySet::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/PropertyService/PropertySet:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

PropertyService::PropertySet_ptr
PropertyService::PropertySet::_narrow( CORBA::Object_ptr _obj )
{
  PropertyService::PropertySet_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/PropertyService/PropertySet:1.0" )))
      return _duplicate( (PropertyService::PropertySet_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/PropertyService/PropertySet:1.0") || _obj->_is_a_remote ("IDL:omg.org/PropertyService/PropertySet:1.0")) {
      _o = new PropertyService::PropertySet_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

PropertyService::PropertySet_ptr
PropertyService::PropertySet::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertySet;
}
class _Marshaller_PropertyService_PropertySet : public ::CORBA::StaticTypeInfo {
    typedef PropertyService::PropertySet_ptr _MICO_T;
  public:
    ~_Marshaller_PropertyService_PropertySet();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_PropertySet::~_Marshaller_PropertyService_PropertySet()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_PropertySet::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_PropertyService_PropertySet::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::PropertyService::PropertySet::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_PropertyService_PropertySet::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_PropertyService_PropertySet::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_PropertyService_PropertySet::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::PropertyService::PropertySet::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_PropertyService_PropertySet::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_PropertySet::typecode()
{
  return PropertyService::_tc_PropertySet;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertySet;

void
operator<<=( CORBA::Any &_a, const PropertyService::PropertySet_ptr _obj )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertySet, &_obj);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, PropertyService::PropertySet_ptr* _obj_ptr )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertySet, _obj_ptr);
  _a.from_static_any (_sa);
  CORBA::release (*_obj_ptr);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, PropertyService::PropertySet_ptr &_obj )
{
  PropertyService::PropertySet_ptr *p;
  if (_a.to_static_any (_marshaller_PropertyService_PropertySet, (void *&)p)) {
    _obj = *p;
    return TRUE;
  }
  return FALSE;
}


/*
 * Stub interface for class PropertySet
 */

PropertyService::PropertySet_stub::~PropertySet_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_PropertyService::PropertySet::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/PropertyService/PropertySet:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_PropertyService::PropertySet *
POA_PropertyService::PropertySet::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/PropertyService/PropertySet:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_PropertyService::PropertySet *) p;
  }
  return NULL;
}

PropertyService::PropertySet_stub_clp::PropertySet_stub_clp ()
{
}

PropertyService::PropertySet_stub_clp::PropertySet_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

PropertyService::PropertySet_stub_clp::~PropertySet_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertySet_stub::define_property( const char* _par_property_name, const CORBA::Any& _par_property_value )
{
  CORBA::StaticAny _sa_property_name( CORBA::_stc_string, &_par_property_name );
  CORBA::StaticAny _sa_property_value( CORBA::_stc_any, &_par_property_value );
  CORBA::StaticRequest __req( this, "define_property" );
  __req.add_in_arg( &_sa_property_name );
  __req.add_in_arg( &_sa_property_value );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_InvalidPropertyName, "IDL:omg.org/PropertyService/InvalidPropertyName:1.0",
    _marshaller_PropertyService_ConflictingProperty, "IDL:omg.org/PropertyService/ConflictingProperty:1.0",
    _marshaller_PropertyService_UnsupportedTypeCode, "IDL:omg.org/PropertyService/UnsupportedTypeCode:1.0",
    _marshaller_PropertyService_UnsupportedProperty, "IDL:omg.org/PropertyService/UnsupportedProperty:1.0",
    _marshaller_PropertyService_ReadOnlyProperty, "IDL:omg.org/PropertyService/ReadOnlyProperty:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertySet_stub_clp::define_property( const char* _par_property_name, const CORBA::Any& _par_property_value )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySet * _myserv = POA_PropertyService::PropertySet::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->define_property(_par_property_name, _par_property_value);
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

  PropertyService::PropertySet_stub::define_property(_par_property_name, _par_property_value);
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertySet_stub::define_properties( const PropertyService::Properties& _par_nproperties )
{
  CORBA::StaticAny _sa_nproperties( _marshaller__seq_PropertyService_Property, &_par_nproperties );
  CORBA::StaticRequest __req( this, "define_properties" );
  __req.add_in_arg( &_sa_nproperties );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_MultipleExceptions, "IDL:omg.org/PropertyService/MultipleExceptions:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertySet_stub_clp::define_properties( const PropertyService::Properties& _par_nproperties )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySet * _myserv = POA_PropertyService::PropertySet::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->define_properties(_par_nproperties);
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

  PropertyService::PropertySet_stub::define_properties(_par_nproperties);
}

#endif // MICO_CONF_NO_POA

CORBA::ULong PropertyService::PropertySet_stub::get_number_of_properties()
{
  CORBA::ULong _res;
  CORBA::StaticAny __res( CORBA::_stc_ulong, &_res );

  CORBA::StaticRequest __req( this, "get_number_of_properties" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::ULong
PropertyService::PropertySet_stub_clp::get_number_of_properties()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySet * _myserv = POA_PropertyService::PropertySet::_narrow (_serv);
    if (_myserv) {
      CORBA::ULong __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->get_number_of_properties();
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

  return PropertyService::PropertySet_stub::get_number_of_properties();
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertySet_stub::get_all_property_names( CORBA::ULong _par_how_many, PropertyService::PropertyNames_out _par_property_names, PropertyService::PropertyNamesIterator_out _par_rest )
{
  CORBA::StaticAny _sa_how_many( CORBA::_stc_ulong, &_par_how_many );
  CORBA::StaticAny _sa_property_names( CORBA::_stcseq_string );
  CORBA::StaticAny _sa_rest( _marshaller_PropertyService_PropertyNamesIterator, &_par_rest.ptr() );
  CORBA::StaticRequest __req( this, "get_all_property_names" );
  __req.add_in_arg( &_sa_how_many );
  __req.add_out_arg( &_sa_property_names );
  __req.add_out_arg( &_sa_rest );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  _par_property_names = (PropertyService::PropertyNames*) _sa_property_names._retn();
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertySet_stub_clp::get_all_property_names( CORBA::ULong _par_how_many, PropertyService::PropertyNames_out _par_property_names, PropertyService::PropertyNamesIterator_out _par_rest )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySet * _myserv = POA_PropertyService::PropertySet::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->get_all_property_names(_par_how_many, _par_property_names, _par_rest);
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

  PropertyService::PropertySet_stub::get_all_property_names(_par_how_many, _par_property_names, _par_rest);
}

#endif // MICO_CONF_NO_POA

CORBA::Any* PropertyService::PropertySet_stub::get_property_value( const char* _par_property_name )
{
  CORBA::StaticAny _sa_property_name( CORBA::_stc_string, &_par_property_name );
  CORBA::StaticAny __res( CORBA::_stc_any );

  CORBA::StaticRequest __req( this, "get_property_value" );
  __req.add_in_arg( &_sa_property_name );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_InvalidPropertyName, "IDL:omg.org/PropertyService/InvalidPropertyName:1.0",
    _marshaller_PropertyService_PropertyNotFound, "IDL:omg.org/PropertyService/PropertyNotFound:1.0",
    0);
  return (CORBA::Any*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

CORBA::Any*
PropertyService::PropertySet_stub_clp::get_property_value( const char* _par_property_name )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySet * _myserv = POA_PropertyService::PropertySet::_narrow (_serv);
    if (_myserv) {
      CORBA::Any* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->get_property_value(_par_property_name);
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

  return PropertyService::PropertySet_stub::get_property_value(_par_property_name);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean PropertyService::PropertySet_stub::get_properties( const PropertyService::PropertyNames& _par_property_names, PropertyService::Properties_out _par_nproperties )
{
  CORBA::StaticAny _sa_property_names( CORBA::_stcseq_string, &_par_property_names );
  CORBA::StaticAny _sa_nproperties( _marshaller__seq_PropertyService_Property );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "get_properties" );
  __req.add_in_arg( &_sa_property_names );
  __req.add_out_arg( &_sa_nproperties );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  _par_nproperties = (PropertyService::Properties*) _sa_nproperties._retn();
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
PropertyService::PropertySet_stub_clp::get_properties( const PropertyService::PropertyNames& _par_property_names, PropertyService::Properties_out _par_nproperties )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySet * _myserv = POA_PropertyService::PropertySet::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->get_properties(_par_property_names, _par_nproperties);
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

  return PropertyService::PropertySet_stub::get_properties(_par_property_names, _par_nproperties);
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertySet_stub::get_all_properties( CORBA::ULong _par_how_many, PropertyService::Properties_out _par_nproperties, PropertyService::PropertiesIterator_out _par_rest )
{
  CORBA::StaticAny _sa_how_many( CORBA::_stc_ulong, &_par_how_many );
  CORBA::StaticAny _sa_nproperties( _marshaller__seq_PropertyService_Property );
  CORBA::StaticAny _sa_rest( _marshaller_PropertyService_PropertiesIterator, &_par_rest.ptr() );
  CORBA::StaticRequest __req( this, "get_all_properties" );
  __req.add_in_arg( &_sa_how_many );
  __req.add_out_arg( &_sa_nproperties );
  __req.add_out_arg( &_sa_rest );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  _par_nproperties = (PropertyService::Properties*) _sa_nproperties._retn();
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertySet_stub_clp::get_all_properties( CORBA::ULong _par_how_many, PropertyService::Properties_out _par_nproperties, PropertyService::PropertiesIterator_out _par_rest )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySet * _myserv = POA_PropertyService::PropertySet::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->get_all_properties(_par_how_many, _par_nproperties, _par_rest);
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

  PropertyService::PropertySet_stub::get_all_properties(_par_how_many, _par_nproperties, _par_rest);
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertySet_stub::delete_property( const char* _par_property_name )
{
  CORBA::StaticAny _sa_property_name( CORBA::_stc_string, &_par_property_name );
  CORBA::StaticRequest __req( this, "delete_property" );
  __req.add_in_arg( &_sa_property_name );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_InvalidPropertyName, "IDL:omg.org/PropertyService/InvalidPropertyName:1.0",
    _marshaller_PropertyService_PropertyNotFound, "IDL:omg.org/PropertyService/PropertyNotFound:1.0",
    _marshaller_PropertyService_FixedProperty, "IDL:omg.org/PropertyService/FixedProperty:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertySet_stub_clp::delete_property( const char* _par_property_name )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySet * _myserv = POA_PropertyService::PropertySet::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->delete_property(_par_property_name);
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

  PropertyService::PropertySet_stub::delete_property(_par_property_name);
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertySet_stub::delete_properties( const PropertyService::PropertyNames& _par_property_names )
{
  CORBA::StaticAny _sa_property_names( CORBA::_stcseq_string, &_par_property_names );
  CORBA::StaticRequest __req( this, "delete_properties" );
  __req.add_in_arg( &_sa_property_names );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_MultipleExceptions, "IDL:omg.org/PropertyService/MultipleExceptions:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertySet_stub_clp::delete_properties( const PropertyService::PropertyNames& _par_property_names )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySet * _myserv = POA_PropertyService::PropertySet::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->delete_properties(_par_property_names);
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

  PropertyService::PropertySet_stub::delete_properties(_par_property_names);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean PropertyService::PropertySet_stub::delete_all_properties()
{
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "delete_all_properties" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
PropertyService::PropertySet_stub_clp::delete_all_properties()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySet * _myserv = POA_PropertyService::PropertySet::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->delete_all_properties();
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

  return PropertyService::PropertySet_stub::delete_all_properties();
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean PropertyService::PropertySet_stub::is_property_defined( const char* _par_property_name )
{
  CORBA::StaticAny _sa_property_name( CORBA::_stc_string, &_par_property_name );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "is_property_defined" );
  __req.add_in_arg( &_sa_property_name );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_InvalidPropertyName, "IDL:omg.org/PropertyService/InvalidPropertyName:1.0",
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
PropertyService::PropertySet_stub_clp::is_property_defined( const char* _par_property_name )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySet * _myserv = POA_PropertyService::PropertySet::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->is_property_defined(_par_property_name);
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

  return PropertyService::PropertySet_stub::is_property_defined(_par_property_name);
}

#endif // MICO_CONF_NO_POA

namespace PropertyService
{
CORBA::TypeCodeConst _tc_UnsupportedMode;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::UnsupportedMode::UnsupportedMode()
{
}

PropertyService::UnsupportedMode::UnsupportedMode( const UnsupportedMode& _s )
{
}

PropertyService::UnsupportedMode::~UnsupportedMode()
{
}

PropertyService::UnsupportedMode&
PropertyService::UnsupportedMode::operator=( const UnsupportedMode& _s )
{
  return *this;
}
#endif

class _Marshaller_PropertyService_UnsupportedMode : public ::CORBA::StaticTypeInfo {
    typedef ::PropertyService::UnsupportedMode _MICO_T;
  public:
    ~_Marshaller_PropertyService_UnsupportedMode();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_UnsupportedMode::~_Marshaller_PropertyService_UnsupportedMode()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_UnsupportedMode::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_UnsupportedMode::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_UnsupportedMode::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_UnsupportedMode::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_PropertyService_UnsupportedMode::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/PropertyService/UnsupportedMode:1.0" );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_UnsupportedMode::typecode()
{
  return PropertyService::_tc_UnsupportedMode;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_UnsupportedMode;

void operator<<=( CORBA::Any &_a, const PropertyService::UnsupportedMode &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_UnsupportedMode, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, PropertyService::UnsupportedMode *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::UnsupportedMode &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_UnsupportedMode, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const PropertyService::UnsupportedMode *&_e )
{
  return _a.to_static_any (_marshaller_PropertyService_UnsupportedMode, (void *&)_e);
}

void PropertyService::UnsupportedMode::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw UnsupportedMode_var( (PropertyService::UnsupportedMode*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *PropertyService::UnsupportedMode::_repoid() const
{
  return "IDL:omg.org/PropertyService/UnsupportedMode:1.0";
}

void PropertyService::UnsupportedMode::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_PropertyService_UnsupportedMode->marshal( _en, (void*) this );
}

void PropertyService::UnsupportedMode::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *PropertyService::UnsupportedMode::_clone() const
{
  return new UnsupportedMode( *this );
}

PropertyService::UnsupportedMode *PropertyService::UnsupportedMode::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/UnsupportedMode:1.0" ) )
    return (UnsupportedMode *) _ex;
  return NULL;
}

const PropertyService::UnsupportedMode *PropertyService::UnsupportedMode::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/PropertyService/UnsupportedMode:1.0" ) )
    return (UnsupportedMode *) _ex;
  return NULL;
}


/*
 * Base interface for class PropertySetDef
 */

PropertyService::PropertySetDef::~PropertySetDef()
{
}

void *
PropertyService::PropertySetDef::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/PropertyService/PropertySetDef:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = PropertyService::PropertySet::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

PropertyService::PropertySetDef_ptr
PropertyService::PropertySetDef::_narrow( CORBA::Object_ptr _obj )
{
  PropertyService::PropertySetDef_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/PropertyService/PropertySetDef:1.0" )))
      return _duplicate( (PropertyService::PropertySetDef_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/PropertyService/PropertySetDef:1.0") || _obj->_is_a_remote ("IDL:omg.org/PropertyService/PropertySetDef:1.0")) {
      _o = new PropertyService::PropertySetDef_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

PropertyService::PropertySetDef_ptr
PropertyService::PropertySetDef::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertySetDef;
}
class _Marshaller_PropertyService_PropertySetDef : public ::CORBA::StaticTypeInfo {
    typedef PropertyService::PropertySetDef_ptr _MICO_T;
  public:
    ~_Marshaller_PropertyService_PropertySetDef();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_PropertySetDef::~_Marshaller_PropertyService_PropertySetDef()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_PropertySetDef::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_PropertyService_PropertySetDef::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::PropertyService::PropertySetDef::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_PropertyService_PropertySetDef::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_PropertyService_PropertySetDef::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_PropertyService_PropertySetDef::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::PropertyService::PropertySetDef::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_PropertyService_PropertySetDef::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_PropertySetDef::typecode()
{
  return PropertyService::_tc_PropertySetDef;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertySetDef;

void
operator<<=( CORBA::Any &_a, const PropertyService::PropertySetDef_ptr _obj )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertySetDef, &_obj);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, PropertyService::PropertySetDef_ptr* _obj_ptr )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertySetDef, _obj_ptr);
  _a.from_static_any (_sa);
  CORBA::release (*_obj_ptr);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, PropertyService::PropertySetDef_ptr &_obj )
{
  PropertyService::PropertySetDef_ptr *p;
  if (_a.to_static_any (_marshaller_PropertyService_PropertySetDef, (void *&)p)) {
    _obj = *p;
    return TRUE;
  }
  return FALSE;
}


/*
 * Stub interface for class PropertySetDef
 */

PropertyService::PropertySetDef_stub::~PropertySetDef_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_PropertyService::PropertySetDef::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:omg.org/PropertyService/PropertySetDef:1.0") == 0) {
    return (void *) this;
  }
  if ((p = POA_PropertyService::PropertySet::_narrow_helper (repoid)) != NULL) 
  {
    return p;
  }
  return NULL;
}

POA_PropertyService::PropertySetDef *
POA_PropertyService::PropertySetDef::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/PropertyService/PropertySetDef:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_PropertyService::PropertySetDef *) p;
  }
  return NULL;
}

PropertyService::PropertySetDef_stub_clp::PropertySetDef_stub_clp ()
{
}

PropertyService::PropertySetDef_stub_clp::PropertySetDef_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

PropertyService::PropertySetDef_stub_clp::~PropertySetDef_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertySetDef_stub::get_allowed_property_types( PropertyService::PropertyTypes_out _par_property_types )
{
  CORBA::StaticAny _sa_property_types( _marshaller__seq_TypeCode );
  CORBA::StaticRequest __req( this, "get_allowed_property_types" );
  __req.add_out_arg( &_sa_property_types );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  _par_property_types = (PropertyService::PropertyTypes*) _sa_property_types._retn();
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertySetDef_stub_clp::get_allowed_property_types( PropertyService::PropertyTypes_out _par_property_types )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySetDef * _myserv = POA_PropertyService::PropertySetDef::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->get_allowed_property_types(_par_property_types);
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

  PropertyService::PropertySetDef_stub::get_allowed_property_types(_par_property_types);
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertySetDef_stub::get_allowed_properties( PropertyService::PropertyDefs_out _par_property_defs )
{
  CORBA::StaticAny _sa_property_defs( _marshaller__seq_PropertyService_PropertyDef );
  CORBA::StaticRequest __req( this, "get_allowed_properties" );
  __req.add_out_arg( &_sa_property_defs );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  _par_property_defs = (PropertyService::PropertyDefs*) _sa_property_defs._retn();
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertySetDef_stub_clp::get_allowed_properties( PropertyService::PropertyDefs_out _par_property_defs )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySetDef * _myserv = POA_PropertyService::PropertySetDef::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->get_allowed_properties(_par_property_defs);
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

  PropertyService::PropertySetDef_stub::get_allowed_properties(_par_property_defs);
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertySetDef_stub::define_property_with_mode( const char* _par_property_name, const CORBA::Any& _par_property_value, PropertyService::PropertyModeType _par_property_mode )
{
  CORBA::StaticAny _sa_property_name( CORBA::_stc_string, &_par_property_name );
  CORBA::StaticAny _sa_property_value( CORBA::_stc_any, &_par_property_value );
  CORBA::StaticAny _sa_property_mode( _marshaller_PropertyService_PropertyModeType, &_par_property_mode );
  CORBA::StaticRequest __req( this, "define_property_with_mode" );
  __req.add_in_arg( &_sa_property_name );
  __req.add_in_arg( &_sa_property_value );
  __req.add_in_arg( &_sa_property_mode );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_InvalidPropertyName, "IDL:omg.org/PropertyService/InvalidPropertyName:1.0",
    _marshaller_PropertyService_ConflictingProperty, "IDL:omg.org/PropertyService/ConflictingProperty:1.0",
    _marshaller_PropertyService_UnsupportedTypeCode, "IDL:omg.org/PropertyService/UnsupportedTypeCode:1.0",
    _marshaller_PropertyService_UnsupportedProperty, "IDL:omg.org/PropertyService/UnsupportedProperty:1.0",
    _marshaller_PropertyService_UnsupportedMode, "IDL:omg.org/PropertyService/UnsupportedMode:1.0",
    _marshaller_PropertyService_ReadOnlyProperty, "IDL:omg.org/PropertyService/ReadOnlyProperty:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertySetDef_stub_clp::define_property_with_mode( const char* _par_property_name, const CORBA::Any& _par_property_value, PropertyService::PropertyModeType _par_property_mode )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySetDef * _myserv = POA_PropertyService::PropertySetDef::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->define_property_with_mode(_par_property_name, _par_property_value, _par_property_mode);
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

  PropertyService::PropertySetDef_stub::define_property_with_mode(_par_property_name, _par_property_value, _par_property_mode);
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertySetDef_stub::define_properties_with_modes( const PropertyService::PropertyDefs& _par_property_defs )
{
  CORBA::StaticAny _sa_property_defs( _marshaller__seq_PropertyService_PropertyDef, &_par_property_defs );
  CORBA::StaticRequest __req( this, "define_properties_with_modes" );
  __req.add_in_arg( &_sa_property_defs );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_MultipleExceptions, "IDL:omg.org/PropertyService/MultipleExceptions:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertySetDef_stub_clp::define_properties_with_modes( const PropertyService::PropertyDefs& _par_property_defs )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySetDef * _myserv = POA_PropertyService::PropertySetDef::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->define_properties_with_modes(_par_property_defs);
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

  PropertyService::PropertySetDef_stub::define_properties_with_modes(_par_property_defs);
}

#endif // MICO_CONF_NO_POA

PropertyService::PropertyModeType PropertyService::PropertySetDef_stub::get_property_mode( const char* _par_property_name )
{
  CORBA::StaticAny _sa_property_name( CORBA::_stc_string, &_par_property_name );
  PropertyService::PropertyModeType _res;
  CORBA::StaticAny __res( _marshaller_PropertyService_PropertyModeType, &_res );

  CORBA::StaticRequest __req( this, "get_property_mode" );
  __req.add_in_arg( &_sa_property_name );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_PropertyNotFound, "IDL:omg.org/PropertyService/PropertyNotFound:1.0",
    _marshaller_PropertyService_InvalidPropertyName, "IDL:omg.org/PropertyService/InvalidPropertyName:1.0",
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

PropertyService::PropertyModeType
PropertyService::PropertySetDef_stub_clp::get_property_mode( const char* _par_property_name )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySetDef * _myserv = POA_PropertyService::PropertySetDef::_narrow (_serv);
    if (_myserv) {
      PropertyService::PropertyModeType __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->get_property_mode(_par_property_name);
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

  return PropertyService::PropertySetDef_stub::get_property_mode(_par_property_name);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean PropertyService::PropertySetDef_stub::get_property_modes( const PropertyService::PropertyNames& _par_property_names, PropertyService::PropertyModes_out _par_property_modes )
{
  CORBA::StaticAny _sa_property_names( CORBA::_stcseq_string, &_par_property_names );
  CORBA::StaticAny _sa_property_modes( _marshaller__seq_PropertyService_PropertyMode );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "get_property_modes" );
  __req.add_in_arg( &_sa_property_names );
  __req.add_out_arg( &_sa_property_modes );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  _par_property_modes = (PropertyService::PropertyModes*) _sa_property_modes._retn();
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
PropertyService::PropertySetDef_stub_clp::get_property_modes( const PropertyService::PropertyNames& _par_property_names, PropertyService::PropertyModes_out _par_property_modes )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySetDef * _myserv = POA_PropertyService::PropertySetDef::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->get_property_modes(_par_property_names, _par_property_modes);
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

  return PropertyService::PropertySetDef_stub::get_property_modes(_par_property_names, _par_property_modes);
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertySetDef_stub::set_property_mode( const char* _par_property_name, PropertyService::PropertyModeType _par_property_mode )
{
  CORBA::StaticAny _sa_property_name( CORBA::_stc_string, &_par_property_name );
  CORBA::StaticAny _sa_property_mode( _marshaller_PropertyService_PropertyModeType, &_par_property_mode );
  CORBA::StaticRequest __req( this, "set_property_mode" );
  __req.add_in_arg( &_sa_property_name );
  __req.add_in_arg( &_sa_property_mode );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_InvalidPropertyName, "IDL:omg.org/PropertyService/InvalidPropertyName:1.0",
    _marshaller_PropertyService_PropertyNotFound, "IDL:omg.org/PropertyService/PropertyNotFound:1.0",
    _marshaller_PropertyService_UnsupportedMode, "IDL:omg.org/PropertyService/UnsupportedMode:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertySetDef_stub_clp::set_property_mode( const char* _par_property_name, PropertyService::PropertyModeType _par_property_mode )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySetDef * _myserv = POA_PropertyService::PropertySetDef::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->set_property_mode(_par_property_name, _par_property_mode);
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

  PropertyService::PropertySetDef_stub::set_property_mode(_par_property_name, _par_property_mode);
}

#endif // MICO_CONF_NO_POA

void PropertyService::PropertySetDef_stub::set_property_modes( const PropertyService::PropertyModes& _par_property_modes )
{
  CORBA::StaticAny _sa_property_modes( _marshaller__seq_PropertyService_PropertyMode, &_par_property_modes );
  CORBA::StaticRequest __req( this, "set_property_modes" );
  __req.add_in_arg( &_sa_property_modes );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_MultipleExceptions, "IDL:omg.org/PropertyService/MultipleExceptions:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
PropertyService::PropertySetDef_stub_clp::set_property_modes( const PropertyService::PropertyModes& _par_property_modes )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySetDef * _myserv = POA_PropertyService::PropertySetDef::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->set_property_modes(_par_property_modes);
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

  PropertyService::PropertySetDef_stub::set_property_modes(_par_property_modes);
}

#endif // MICO_CONF_NO_POA

namespace PropertyService
{
CORBA::TypeCodeConst _tc_ExceptionReason;
}

void operator<<=( CORBA::Any &_a, const PropertyService::ExceptionReason &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_ExceptionReason, &_e);
  _a.from_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::ExceptionReason &_e )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_ExceptionReason, &_e);
  return _a.to_static_any (_sa);
}

class _Marshaller_PropertyService_ExceptionReason : public ::CORBA::StaticTypeInfo {
    typedef PropertyService::ExceptionReason _MICO_T;
  public:
    ~_Marshaller_PropertyService_ExceptionReason();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_ExceptionReason::~_Marshaller_PropertyService_ExceptionReason()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_ExceptionReason::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_ExceptionReason::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_ExceptionReason::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_ExceptionReason::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong ul;
  if( !dc.enumeration( ul ) )
    return FALSE;
  *(_MICO_T*) v = (_MICO_T) ul;
  return TRUE;
}

void _Marshaller_PropertyService_ExceptionReason::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.enumeration( (::CORBA::ULong) *(_MICO_T *) v );
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_ExceptionReason::typecode()
{
  return PropertyService::_tc_ExceptionReason;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_ExceptionReason;

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertyException;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
PropertyService::PropertyException::PropertyException()
{
}

PropertyService::PropertyException::PropertyException( const PropertyException& _s )
{
  reason = ((PropertyException&)_s).reason;
  failing_property_name = ((PropertyException&)_s).failing_property_name;
}

PropertyService::PropertyException::~PropertyException()
{
}

PropertyService::PropertyException&
PropertyService::PropertyException::operator=( const PropertyException& _s )
{
  reason = ((PropertyException&)_s).reason;
  failing_property_name = ((PropertyException&)_s).failing_property_name;
  return *this;
}
#endif

class _Marshaller_PropertyService_PropertyException : public ::CORBA::StaticTypeInfo {
    typedef PropertyService::PropertyException _MICO_T;
  public:
    ~_Marshaller_PropertyService_PropertyException();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_PropertyException::~_Marshaller_PropertyService_PropertyException()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_PropertyException::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_PropertyService_PropertyException::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_PropertyService_PropertyException::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_PropertyService_PropertyException::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    _marshaller_PropertyService_ExceptionReason->demarshal( dc, &((_MICO_T*)v)->reason ) &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->failing_property_name._for_demarshal() ) &&
    dc.struct_end();
}

void _Marshaller_PropertyService_PropertyException::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  _marshaller_PropertyService_ExceptionReason->marshal( ec, &((_MICO_T*)v)->reason );
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->failing_property_name.inout() );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_PropertyException::typecode()
{
  return PropertyService::_tc_PropertyException;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertyException;

void operator<<=( CORBA::Any &_a, const PropertyService::PropertyException &_s )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertyException, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, PropertyService::PropertyException *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, PropertyService::PropertyException &_s )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertyException, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const PropertyService::PropertyException *&_s )
{
  return _a.to_static_any (_marshaller_PropertyService_PropertyException, (void *&)_s);
}


/*
 * Base interface for class PropertySetDefFactory
 */

PropertyService::PropertySetDefFactory::~PropertySetDefFactory()
{
}

void *
PropertyService::PropertySetDefFactory::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/PropertyService/PropertySetDefFactory:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

PropertyService::PropertySetDefFactory_ptr
PropertyService::PropertySetDefFactory::_narrow( CORBA::Object_ptr _obj )
{
  PropertyService::PropertySetDefFactory_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/PropertyService/PropertySetDefFactory:1.0" )))
      return _duplicate( (PropertyService::PropertySetDefFactory_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/PropertyService/PropertySetDefFactory:1.0") || _obj->_is_a_remote ("IDL:omg.org/PropertyService/PropertySetDefFactory:1.0")) {
      _o = new PropertyService::PropertySetDefFactory_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

PropertyService::PropertySetDefFactory_ptr
PropertyService::PropertySetDefFactory::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace PropertyService
{
CORBA::TypeCodeConst _tc_PropertySetDefFactory;
}
class _Marshaller_PropertyService_PropertySetDefFactory : public ::CORBA::StaticTypeInfo {
    typedef PropertyService::PropertySetDefFactory_ptr _MICO_T;
  public:
    ~_Marshaller_PropertyService_PropertySetDefFactory();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_PropertyService_PropertySetDefFactory::~_Marshaller_PropertyService_PropertySetDefFactory()
{
}

::CORBA::StaticValueType _Marshaller_PropertyService_PropertySetDefFactory::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_PropertyService_PropertySetDefFactory::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::PropertyService::PropertySetDefFactory::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_PropertyService_PropertySetDefFactory::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_PropertyService_PropertySetDefFactory::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_PropertyService_PropertySetDefFactory::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::PropertyService::PropertySetDefFactory::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_PropertyService_PropertySetDefFactory::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::TypeCode_ptr _Marshaller_PropertyService_PropertySetDefFactory::typecode()
{
  return PropertyService::_tc_PropertySetDefFactory;
}

::CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertySetDefFactory;

void
operator<<=( CORBA::Any &_a, const PropertyService::PropertySetDefFactory_ptr _obj )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertySetDefFactory, &_obj);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, PropertyService::PropertySetDefFactory_ptr* _obj_ptr )
{
  CORBA::StaticAny _sa (_marshaller_PropertyService_PropertySetDefFactory, _obj_ptr);
  _a.from_static_any (_sa);
  CORBA::release (*_obj_ptr);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, PropertyService::PropertySetDefFactory_ptr &_obj )
{
  PropertyService::PropertySetDefFactory_ptr *p;
  if (_a.to_static_any (_marshaller_PropertyService_PropertySetDefFactory, (void *&)p)) {
    _obj = *p;
    return TRUE;
  }
  return FALSE;
}


/*
 * Stub interface for class PropertySetDefFactory
 */

PropertyService::PropertySetDefFactory_stub::~PropertySetDefFactory_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_PropertyService::PropertySetDefFactory::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/PropertyService/PropertySetDefFactory:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_PropertyService::PropertySetDefFactory *
POA_PropertyService::PropertySetDefFactory::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/PropertyService/PropertySetDefFactory:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_PropertyService::PropertySetDefFactory *) p;
  }
  return NULL;
}

PropertyService::PropertySetDefFactory_stub_clp::PropertySetDefFactory_stub_clp ()
{
}

PropertyService::PropertySetDefFactory_stub_clp::PropertySetDefFactory_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

PropertyService::PropertySetDefFactory_stub_clp::~PropertySetDefFactory_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

PropertyService::PropertySetDef_ptr PropertyService::PropertySetDefFactory_stub::create_propertysetdef()
{
  PropertyService::PropertySetDef_ptr _res = PropertyService::PropertySetDef::_nil();
  CORBA::StaticAny __res( _marshaller_PropertyService_PropertySetDef, &_res );

  CORBA::StaticRequest __req( this, "create_propertysetdef" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

PropertyService::PropertySetDef_ptr
PropertyService::PropertySetDefFactory_stub_clp::create_propertysetdef()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySetDefFactory * _myserv = POA_PropertyService::PropertySetDefFactory::_narrow (_serv);
    if (_myserv) {
      PropertyService::PropertySetDef_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->create_propertysetdef();
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

  return PropertyService::PropertySetDefFactory_stub::create_propertysetdef();
}

#endif // MICO_CONF_NO_POA

PropertyService::PropertySetDef_ptr PropertyService::PropertySetDefFactory_stub::create_constrained_propertysetdef( const PropertyService::PropertyTypes& _par_allowed_property_types, const PropertyService::PropertyDefs& _par_allowed_property_defs )
{
  CORBA::StaticAny _sa_allowed_property_types( _marshaller__seq_TypeCode, &_par_allowed_property_types );
  CORBA::StaticAny _sa_allowed_property_defs( _marshaller__seq_PropertyService_PropertyDef, &_par_allowed_property_defs );
  PropertyService::PropertySetDef_ptr _res = PropertyService::PropertySetDef::_nil();
  CORBA::StaticAny __res( _marshaller_PropertyService_PropertySetDef, &_res );

  CORBA::StaticRequest __req( this, "create_constrained_propertysetdef" );
  __req.add_in_arg( &_sa_allowed_property_types );
  __req.add_in_arg( &_sa_allowed_property_defs );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_ConstraintNotSupported, "IDL:omg.org/PropertyService/ConstraintNotSupported:1.0",
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

PropertyService::PropertySetDef_ptr
PropertyService::PropertySetDefFactory_stub_clp::create_constrained_propertysetdef( const PropertyService::PropertyTypes& _par_allowed_property_types, const PropertyService::PropertyDefs& _par_allowed_property_defs )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySetDefFactory * _myserv = POA_PropertyService::PropertySetDefFactory::_narrow (_serv);
    if (_myserv) {
      PropertyService::PropertySetDef_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->create_constrained_propertysetdef(_par_allowed_property_types, _par_allowed_property_defs);
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

  return PropertyService::PropertySetDefFactory_stub::create_constrained_propertysetdef(_par_allowed_property_types, _par_allowed_property_defs);
}

#endif // MICO_CONF_NO_POA

PropertyService::PropertySetDef_ptr PropertyService::PropertySetDefFactory_stub::create_initial_propertysetdef( const PropertyService::PropertyDefs& _par_initial_property_defs )
{
  CORBA::StaticAny _sa_initial_property_defs( _marshaller__seq_PropertyService_PropertyDef, &_par_initial_property_defs );
  PropertyService::PropertySetDef_ptr _res = PropertyService::PropertySetDef::_nil();
  CORBA::StaticAny __res( _marshaller_PropertyService_PropertySetDef, &_res );

  CORBA::StaticRequest __req( this, "create_initial_propertysetdef" );
  __req.add_in_arg( &_sa_initial_property_defs );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_PropertyService_MultipleExceptions, "IDL:omg.org/PropertyService/MultipleExceptions:1.0",
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

PropertyService::PropertySetDef_ptr
PropertyService::PropertySetDefFactory_stub_clp::create_initial_propertysetdef( const PropertyService::PropertyDefs& _par_initial_property_defs )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_PropertyService::PropertySetDefFactory * _myserv = POA_PropertyService::PropertySetDefFactory::_narrow (_serv);
    if (_myserv) {
      PropertyService::PropertySetDef_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->create_initial_propertysetdef(_par_initial_property_defs);
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

  return PropertyService::PropertySetDefFactory_stub::create_initial_propertysetdef(_par_initial_property_defs);
}

#endif // MICO_CONF_NO_POA

class _Marshaller__seq_PropertyService_Property : public ::CORBA::StaticTypeInfo {
    typedef SequenceTmpl< PropertyService::Property,MICO_TID_DEF> _MICO_T;
    static ::CORBA::TypeCode_ptr _tc;
  public:
    ~_Marshaller__seq_PropertyService_Property();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller__seq_PropertyService_Property::~_Marshaller__seq_PropertyService_Property()
{
  if (_tc)
    delete _tc;
}

::CORBA::StaticValueType _Marshaller__seq_PropertyService_Property::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_PropertyService_Property::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_PropertyService_Property::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_PropertyService_Property::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_PropertyService_Property->demarshal( dc, &(*(_MICO_T*)v)[i] ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_PropertyService_Property::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_PropertyService_Property->marshal( ec, &(*(_MICO_T*)v)[i] );
  ec.seq_end();
}

::CORBA::TypeCode_ptr _Marshaller__seq_PropertyService_Property::typecode()
{
  if (!_tc)
    _tc = (new ::CORBA::TypeCode (
    "0100000013000000e0000000010000000f000000d0000000010000002900"
    "000049444c3a6f6d672e6f72672f50726f7065727479536572766963652f"
    "50726f70657274793a312e30000000000900000050726f70657274790000"
    "0000020000000e00000070726f70657274795f6e616d6500000015000000"
    "54000000010000002d00000049444c3a6f6d672e6f72672f50726f706572"
    "7479536572766963652f50726f70657274794e616d653a312e3000000000"
    "0d00000050726f70657274794e616d650000000012000000000000000f00"
    "000070726f70657274795f76616c756500000b00000000000000"))->mk_constant();
  return _tc;
}

::CORBA::TypeCode_ptr _Marshaller__seq_PropertyService_Property::_tc = 0;
::CORBA::StaticTypeInfo *_marshaller__seq_PropertyService_Property;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< PropertyService::Property,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_PropertyService_Property, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SequenceTmpl< PropertyService::Property,MICO_TID_DEF> *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< PropertyService::Property,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_PropertyService_Property, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< PropertyService::Property,MICO_TID_DEF> *&_s )
{
  return _a.to_static_any (_marshaller__seq_PropertyService_Property, (void *&)_s);
}


class _Marshaller__seq_PropertyService_PropertyDef : public ::CORBA::StaticTypeInfo {
    typedef SequenceTmpl< PropertyService::PropertyDef,MICO_TID_DEF> _MICO_T;
    static ::CORBA::TypeCode_ptr _tc;
  public:
    ~_Marshaller__seq_PropertyService_PropertyDef();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller__seq_PropertyService_PropertyDef::~_Marshaller__seq_PropertyService_PropertyDef()
{
  if (_tc)
    delete _tc;
}

::CORBA::StaticValueType _Marshaller__seq_PropertyService_PropertyDef::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_PropertyService_PropertyDef::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_PropertyService_PropertyDef::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_PropertyService_PropertyDef::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_PropertyService_PropertyDef->demarshal( dc, &(*(_MICO_T*)v)[i] ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_PropertyService_PropertyDef::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_PropertyService_PropertyDef->marshal( ec, &(*(_MICO_T*)v)[i] );
  ec.seq_end();
}

::CORBA::TypeCode_ptr _Marshaller__seq_PropertyService_PropertyDef::typecode()
{
  if (!_tc)
    _tc = (new ::CORBA::TypeCode (
    "0100000013000000a8010000010000000f00000096010000010000002c00"
    "000049444c3a6f6d672e6f72672f50726f7065727479536572766963652f"
    "50726f70657274794465663a312e30000c00000050726f70657274794465"
    "6600030000000e00000070726f70657274795f6e616d6500000015000000"
    "54000000010000002d00000049444c3a6f6d672e6f72672f50726f706572"
    "7479536572766963652f50726f70657274794e616d653a312e3000000000"
    "0d00000050726f70657274794e616d650000000012000000000000000f00"
    "000070726f70657274795f76616c756500000b0000000e00000070726f70"
    "657274795f6d6f646500000011000000aa00000001000000310000004944"
    "4c3a6f6d672e6f72672f50726f7065727479536572766963652f50726f70"
    "657274794d6f6465547970653a312e30000000001100000050726f706572"
    "74794d6f6465547970650000000005000000070000006e6f726d616c0000"
    "0a000000726561645f6f6e6c790000000d00000066697865645f6e6f726d"
    "616c000000000f00000066697865645f726561646f6e6c7900000a000000"
    "756e646566696e656400000000000000"))->mk_constant();
  return _tc;
}

::CORBA::TypeCode_ptr _Marshaller__seq_PropertyService_PropertyDef::_tc = 0;
::CORBA::StaticTypeInfo *_marshaller__seq_PropertyService_PropertyDef;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< PropertyService::PropertyDef,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_PropertyService_PropertyDef, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SequenceTmpl< PropertyService::PropertyDef,MICO_TID_DEF> *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< PropertyService::PropertyDef,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_PropertyService_PropertyDef, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< PropertyService::PropertyDef,MICO_TID_DEF> *&_s )
{
  return _a.to_static_any (_marshaller__seq_PropertyService_PropertyDef, (void *&)_s);
}


class _Marshaller__seq_PropertyService_PropertyMode : public ::CORBA::StaticTypeInfo {
    typedef SequenceTmpl< PropertyService::PropertyMode,MICO_TID_DEF> _MICO_T;
    static ::CORBA::TypeCode_ptr _tc;
  public:
    ~_Marshaller__seq_PropertyService_PropertyMode();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller__seq_PropertyService_PropertyMode::~_Marshaller__seq_PropertyService_PropertyMode()
{
  if (_tc)
    delete _tc;
}

::CORBA::StaticValueType _Marshaller__seq_PropertyService_PropertyMode::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_PropertyService_PropertyMode::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_PropertyService_PropertyMode::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_PropertyService_PropertyMode::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_PropertyService_PropertyMode->demarshal( dc, &(*(_MICO_T*)v)[i] ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_PropertyService_PropertyMode::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_PropertyService_PropertyMode->marshal( ec, &(*(_MICO_T*)v)[i] );
  ec.seq_end();
}

::CORBA::TypeCode_ptr _Marshaller__seq_PropertyService_PropertyMode::typecode()
{
  if (!_tc)
    _tc = (new ::CORBA::TypeCode (
    "010000001300000098010000010000000f00000086010000010000002d00"
    "000049444c3a6f6d672e6f72672f50726f7065727479536572766963652f"
    "50726f70657274794d6f64653a312e30000000000d00000050726f706572"
    "74794d6f646500000000020000000e00000070726f70657274795f6e616d"
    "650000001500000054000000010000002d00000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f70657274794e616d65"
    "3a312e30000000000d00000050726f70657274794e616d65000000001200"
    "0000000000000e00000070726f70657274795f6d6f646500000011000000"
    "aa000000010000003100000049444c3a6f6d672e6f72672f50726f706572"
    "7479536572766963652f50726f70657274794d6f6465547970653a312e30"
    "000000001100000050726f70657274794d6f646554797065000000000500"
    "0000070000006e6f726d616c00000a000000726561645f6f6e6c79000000"
    "0d00000066697865645f6e6f726d616c000000000f00000066697865645f"
    "726561646f6e6c7900000a000000756e646566696e656400000000000000"
    ))->mk_constant();
  return _tc;
}

::CORBA::TypeCode_ptr _Marshaller__seq_PropertyService_PropertyMode::_tc = 0;
::CORBA::StaticTypeInfo *_marshaller__seq_PropertyService_PropertyMode;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< PropertyService::PropertyMode,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_PropertyService_PropertyMode, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SequenceTmpl< PropertyService::PropertyMode,MICO_TID_DEF> *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< PropertyService::PropertyMode,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_PropertyService_PropertyMode, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< PropertyService::PropertyMode,MICO_TID_DEF> *&_s )
{
  return _a.to_static_any (_marshaller__seq_PropertyService_PropertyMode, (void *&)_s);
}


class _Marshaller__seq_PropertyService_PropertyException : public ::CORBA::StaticTypeInfo {
    typedef SequenceTmpl< PropertyService::PropertyException,MICO_TID_DEF> _MICO_T;
    static ::CORBA::TypeCode_ptr _tc;
  public:
    ~_Marshaller__seq_PropertyService_PropertyException();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller__seq_PropertyService_PropertyException::~_Marshaller__seq_PropertyService_PropertyException()
{
  if (_tc)
    delete _tc;
}

::CORBA::StaticValueType _Marshaller__seq_PropertyService_PropertyException::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_PropertyService_PropertyException::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_PropertyService_PropertyException::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_PropertyService_PropertyException::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_PropertyService_PropertyException->demarshal( dc, &(*(_MICO_T*)v)[i] ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_PropertyService_PropertyException::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_PropertyService_PropertyException->marshal( ec, &(*(_MICO_T*)v)[i] );
  ec.seq_end();
}

::CORBA::TypeCode_ptr _Marshaller__seq_PropertyService_PropertyException::typecode()
{
  if (!_tc)
    _tc = (new ::CORBA::TypeCode (
    "010000001300000010020000010000000f00000000020000010000003200"
    "000049444c3a6f6d672e6f72672f50726f7065727479536572766963652f"
    "50726f7065727479457863657074696f6e3a312e30000000120000005072"
    "6f7065727479457863657074696f6e000000020000000700000072656173"
    "6f6e0000110000001b010000010000003000000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f457863657074696f6e526561"
    "736f6e3a312e300010000000457863657074696f6e526561736f6e000800"
    "000016000000696e76616c69645f70726f70657274795f6e616d65000000"
    "15000000636f6e666c696374696e675f70726f7065727479000000001300"
    "000070726f70657274795f6e6f745f666f756e64000016000000756e7375"
    "70706f727465645f747970655f636f646500000015000000756e73757070"
    "6f727465645f70726f70657274790000000011000000756e737570706f72"
    "7465645f6d6f6465000000000f00000066697865645f70726f7065727479"
    "000013000000726561645f6f6e6c795f70726f7065727479000016000000"
    "6661696c696e675f70726f70657274795f6e616d65000000150000005400"
    "0000010000002d00000049444c3a6f6d672e6f72672f50726f7065727479"
    "536572766963652f50726f70657274794e616d653a312e30000000000d00"
    "000050726f70657274794e616d6500000000120000000000000000000000"
    ))->mk_constant();
  return _tc;
}

::CORBA::TypeCode_ptr _Marshaller__seq_PropertyService_PropertyException::_tc = 0;
::CORBA::StaticTypeInfo *_marshaller__seq_PropertyService_PropertyException;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< PropertyService::PropertyException,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_PropertyService_PropertyException, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SequenceTmpl< PropertyService::PropertyException,MICO_TID_DEF> *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< PropertyService::PropertyException,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_PropertyService_PropertyException, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< PropertyService::PropertyException,MICO_TID_DEF> *&_s )
{
  return _a.to_static_any (_marshaller__seq_PropertyService_PropertyException, (void *&)_s);
}


struct __tc_init_PROPERTYSERVICE {
  __tc_init_PROPERTYSERVICE()
  {
    PropertyService::_tc_PropertyName = 
    "010000001500000054000000010000002d00000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f70657274794e616d65"
    "3a312e30000000000d00000050726f70657274794e616d65000000001200"
    "000000000000";
    PropertyService::_tc_Property = 
    "010000000f000000d0000000010000002900000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f70657274793a312e30"
    "000000000900000050726f706572747900000000020000000e0000007072"
    "6f70657274795f6e616d650000001500000054000000010000002d000000"
    "49444c3a6f6d672e6f72672f50726f7065727479536572766963652f5072"
    "6f70657274794e616d653a312e30000000000d00000050726f7065727479"
    "4e616d650000000012000000000000000f00000070726f70657274795f76"
    "616c756500000b000000";
    _marshaller_PropertyService_Property = new _Marshaller_PropertyService_Property;
    PropertyService::_tc_PropertyModeType = 
    "0100000011000000aa000000010000003100000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f70657274794d6f6465"
    "547970653a312e30000000001100000050726f70657274794d6f64655479"
    "70650000000005000000070000006e6f726d616c00000a00000072656164"
    "5f6f6e6c790000000d00000066697865645f6e6f726d616c000000000f00"
    "000066697865645f726561646f6e6c7900000a000000756e646566696e65"
    "6400";
    _marshaller_PropertyService_PropertyModeType = new _Marshaller_PropertyService_PropertyModeType;
    PropertyService::_tc_PropertyDef = 
    "010000000f00000096010000010000002c00000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f70657274794465663a"
    "312e30000c00000050726f706572747944656600030000000e0000007072"
    "6f70657274795f6e616d650000001500000054000000010000002d000000"
    "49444c3a6f6d672e6f72672f50726f7065727479536572766963652f5072"
    "6f70657274794e616d653a312e30000000000d00000050726f7065727479"
    "4e616d650000000012000000000000000f00000070726f70657274795f76"
    "616c756500000b0000000e00000070726f70657274795f6d6f6465000000"
    "11000000aa000000010000003100000049444c3a6f6d672e6f72672f5072"
    "6f7065727479536572766963652f50726f70657274794d6f646554797065"
    "3a312e30000000001100000050726f70657274794d6f6465547970650000"
    "000005000000070000006e6f726d616c00000a000000726561645f6f6e6c"
    "790000000d00000066697865645f6e6f726d616c000000000f0000006669"
    "7865645f726561646f6e6c7900000a000000756e646566696e656400";
    _marshaller_PropertyService_PropertyDef = new _Marshaller_PropertyService_PropertyDef;
    PropertyService::_tc_PropertyMode = 
    "010000000f00000086010000010000002d00000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f70657274794d6f6465"
    "3a312e30000000000d00000050726f70657274794d6f6465000000000200"
    "00000e00000070726f70657274795f6e616d650000001500000054000000"
    "010000002d00000049444c3a6f6d672e6f72672f50726f70657274795365"
    "72766963652f50726f70657274794e616d653a312e30000000000d000000"
    "50726f70657274794e616d650000000012000000000000000e0000007072"
    "6f70657274795f6d6f646500000011000000aa0000000100000031000000"
    "49444c3a6f6d672e6f72672f50726f7065727479536572766963652f5072"
    "6f70657274794d6f6465547970653a312e30000000001100000050726f70"
    "657274794d6f6465547970650000000005000000070000006e6f726d616c"
    "00000a000000726561645f6f6e6c790000000d00000066697865645f6e6f"
    "726d616c000000000f00000066697865645f726561646f6e6c7900000a00"
    "0000756e646566696e656400";
    _marshaller_PropertyService_PropertyMode = new _Marshaller_PropertyService_PropertyMode;
    PropertyService::_tc_PropertyNames = 
    "0100000015000000b8000000010000002e00000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f70657274794e616d65"
    "733a312e300000000e00000050726f70657274794e616d65730000001300"
    "000064000000010000001500000054000000010000002d00000049444c3a"
    "6f6d672e6f72672f50726f7065727479536572766963652f50726f706572"
    "74794e616d653a312e30000000000d00000050726f70657274794e616d65"
    "00000000120000000000000000000000";
    PropertyService::_tc_Properties = 
    "01000000150000002c010000010000002b00000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f706572746965733a31"
    "2e3000000b00000050726f70657274696573000013000000e00000000100"
    "00000f000000d0000000010000002900000049444c3a6f6d672e6f72672f"
    "50726f7065727479536572766963652f50726f70657274793a312e300000"
    "00000900000050726f706572747900000000020000000e00000070726f70"
    "657274795f6e616d650000001500000054000000010000002d0000004944"
    "4c3a6f6d672e6f72672f50726f7065727479536572766963652f50726f70"
    "657274794e616d653a312e30000000000d00000050726f70657274794e61"
    "6d650000000012000000000000000f00000070726f70657274795f76616c"
    "756500000b00000000000000";
    PropertyService::_tc_PropertyDefs = 
    "0100000015000000fc010000010000002d00000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f706572747944656673"
    "3a312e30000000000d00000050726f706572747944656673000000001300"
    "0000a8010000010000000f00000096010000010000002c00000049444c3a"
    "6f6d672e6f72672f50726f7065727479536572766963652f50726f706572"
    "74794465663a312e30000c00000050726f70657274794465660003000000"
    "0e00000070726f70657274795f6e616d6500000015000000540000000100"
    "00002d00000049444c3a6f6d672e6f72672f50726f706572747953657276"
    "6963652f50726f70657274794e616d653a312e30000000000d0000005072"
    "6f70657274794e616d650000000012000000000000000f00000070726f70"
    "657274795f76616c756500000b0000000e00000070726f70657274795f6d"
    "6f646500000011000000aa000000010000003100000049444c3a6f6d672e"
    "6f72672f50726f7065727479536572766963652f50726f70657274794d6f"
    "6465547970653a312e30000000001100000050726f70657274794d6f6465"
    "547970650000000005000000070000006e6f726d616c00000a0000007265"
    "61645f6f6e6c790000000d00000066697865645f6e6f726d616c00000000"
    "0f00000066697865645f726561646f6e6c7900000a000000756e64656669"
    "6e656400000000000000";
    PropertyService::_tc_PropertyModes = 
    "0100000015000000ec010000010000002e00000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f70657274794d6f6465"
    "733a312e300000000e00000050726f70657274794d6f6465730000001300"
    "000098010000010000000f00000086010000010000002d00000049444c3a"
    "6f6d672e6f72672f50726f7065727479536572766963652f50726f706572"
    "74794d6f64653a312e30000000000d00000050726f70657274794d6f6465"
    "00000000020000000e00000070726f70657274795f6e616d650000001500"
    "000054000000010000002d00000049444c3a6f6d672e6f72672f50726f70"
    "65727479536572766963652f50726f70657274794e616d653a312e300000"
    "00000d00000050726f70657274794e616d65000000001200000000000000"
    "0e00000070726f70657274795f6d6f646500000011000000aa0000000100"
    "00003100000049444c3a6f6d672e6f72672f50726f706572747953657276"
    "6963652f50726f70657274794d6f6465547970653a312e30000000001100"
    "000050726f70657274794d6f646554797065000000000500000007000000"
    "6e6f726d616c00000a000000726561645f6f6e6c790000000d0000006669"
    "7865645f6e6f726d616c000000000f00000066697865645f726561646f6e"
    "6c7900000a000000756e646566696e656400000000000000";
    PropertyService::_tc_PropertyTypes = 
    "0100000015000000a4000000010000002e00000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f706572747954797065"
    "733a312e300000000e00000050726f706572747954797065730000001500"
    "000050000000010000002200000049444c3a6f6d672e6f72672f434f5242"
    "412f54797065436f64655365713a312e300000000c00000054797065436f"
    "646553657100130000000c000000010000000c00000000000000";
    PropertyService::_tc_PropertyNamesIterator = 
    "010000000e0000005a000000010000003600000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f70657274794e616d65"
    "734974657261746f723a312e300000001600000050726f70657274794e61"
    "6d65734974657261746f7200";
    _marshaller_PropertyService_PropertyNamesIterator = new _Marshaller_PropertyService_PropertyNamesIterator;
    PropertyService::_tc_PropertiesIterator = 
    "010000000e00000053000000010000003300000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f706572746965734974"
    "657261746f723a312e3000001300000050726f7065727469657349746572"
    "61746f7200";
    _marshaller_PropertyService_PropertiesIterator = new _Marshaller_PropertyService_PropertiesIterator;
    PropertyService::_tc_ConstraintNotSupported = 
    "010000001600000060000000010000003700000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f436f6e73747261696e744e6f"
    "74537570706f727465643a312e30000017000000436f6e73747261696e74"
    "4e6f74537570706f72746564000000000000";
    _marshaller_PropertyService_ConstraintNotSupported = new _Marshaller_PropertyService_ConstraintNotSupported;
    PropertyService::_tc_PropertyExceptions = 
    "01000000150000006c020000010000003300000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f706572747945786365"
    "7074696f6e733a312e3000001300000050726f7065727479457863657074"
    "696f6e7300001300000010020000010000000f0000000002000001000000"
    "3200000049444c3a6f6d672e6f72672f50726f7065727479536572766963"
    "652f50726f7065727479457863657074696f6e3a312e3000000012000000"
    "50726f7065727479457863657074696f6e00000002000000070000007265"
    "61736f6e0000110000001b010000010000003000000049444c3a6f6d672e"
    "6f72672f50726f7065727479536572766963652f457863657074696f6e52"
    "6561736f6e3a312e300010000000457863657074696f6e526561736f6e00"
    "0800000016000000696e76616c69645f70726f70657274795f6e616d6500"
    "000015000000636f6e666c696374696e675f70726f706572747900000000"
    "1300000070726f70657274795f6e6f745f666f756e64000016000000756e"
    "737570706f727465645f747970655f636f646500000015000000756e7375"
    "70706f727465645f70726f70657274790000000011000000756e73757070"
    "6f727465645f6d6f6465000000000f00000066697865645f70726f706572"
    "7479000013000000726561645f6f6e6c795f70726f706572747900001600"
    "00006661696c696e675f70726f70657274795f6e616d6500000015000000"
    "54000000010000002d00000049444c3a6f6d672e6f72672f50726f706572"
    "7479536572766963652f50726f70657274794e616d653a312e3000000000"
    "0d00000050726f70657274794e616d650000000012000000000000000000"
    "0000";
    PropertyService::_tc_MultipleExceptions = 
    "0100000016000000dc020000010000003300000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f4d756c7469706c6545786365"
    "7074696f6e733a312e300000130000004d756c7469706c65457863657074"
    "696f6e730000010000000b000000657863657074696f6e73000015000000"
    "6c020000010000003300000049444c3a6f6d672e6f72672f50726f706572"
    "7479536572766963652f50726f7065727479457863657074696f6e733a31"
    "2e3000001300000050726f7065727479457863657074696f6e7300001300"
    "000010020000010000000f00000000020000010000003200000049444c3a"
    "6f6d672e6f72672f50726f7065727479536572766963652f50726f706572"
    "7479457863657074696f6e3a312e300000001200000050726f7065727479"
    "457863657074696f6e0000000200000007000000726561736f6e00001100"
    "00001b010000010000003000000049444c3a6f6d672e6f72672f50726f70"
    "65727479536572766963652f457863657074696f6e526561736f6e3a312e"
    "300010000000457863657074696f6e526561736f6e000800000016000000"
    "696e76616c69645f70726f70657274795f6e616d6500000015000000636f"
    "6e666c696374696e675f70726f7065727479000000001300000070726f70"
    "657274795f6e6f745f666f756e64000016000000756e737570706f727465"
    "645f747970655f636f646500000015000000756e737570706f727465645f"
    "70726f70657274790000000011000000756e737570706f727465645f6d6f"
    "6465000000000f00000066697865645f70726f7065727479000013000000"
    "726561645f6f6e6c795f70726f70657274790000160000006661696c696e"
    "675f70726f70657274795f6e616d65000000150000005400000001000000"
    "2d00000049444c3a6f6d672e6f72672f50726f7065727479536572766963"
    "652f50726f70657274794e616d653a312e30000000000d00000050726f70"
    "657274794e616d6500000000120000000000000000000000";
    _marshaller_PropertyService_MultipleExceptions = new _Marshaller_PropertyService_MultipleExceptions;
    PropertyService::_tc_PropertySetFactory = 
    "010000000e00000053000000010000003300000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f706572747953657446"
    "6163746f72793a312e3000001300000050726f7065727479536574466163"
    "746f727900";
    _marshaller_PropertyService_PropertySetFactory = new _Marshaller_PropertyService_PropertySetFactory;
    PropertyService::_tc_InvalidPropertyName = 
    "010000001600000058000000010000003400000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f496e76616c696450726f7065"
    "7274794e616d653a312e300014000000496e76616c696450726f70657274"
    "794e616d650000000000";
    _marshaller_PropertyService_InvalidPropertyName = new _Marshaller_PropertyService_InvalidPropertyName;
    PropertyService::_tc_ConflictingProperty = 
    "010000001600000058000000010000003400000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f436f6e666c696374696e6750"
    "726f70657274793a312e300014000000436f6e666c696374696e6750726f"
    "70657274790000000000";
    _marshaller_PropertyService_ConflictingProperty = new _Marshaller_PropertyService_ConflictingProperty;
    PropertyService::_tc_UnsupportedTypeCode = 
    "010000001600000058000000010000003400000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f556e737570706f7274656454"
    "797065436f64653a312e300014000000556e737570706f72746564547970"
    "65436f64650000000000";
    _marshaller_PropertyService_UnsupportedTypeCode = new _Marshaller_PropertyService_UnsupportedTypeCode;
    PropertyService::_tc_UnsupportedProperty = 
    "010000001600000058000000010000003400000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f556e737570706f7274656450"
    "726f70657274793a312e300014000000556e737570706f7274656450726f"
    "70657274790000000000";
    _marshaller_PropertyService_UnsupportedProperty = new _Marshaller_PropertyService_UnsupportedProperty;
    PropertyService::_tc_ReadOnlyProperty = 
    "010000001600000058000000010000003100000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f526561644f6e6c7950726f70"
    "657274793a312e300000000011000000526561644f6e6c7950726f706572"
    "74790000000000000000";
    _marshaller_PropertyService_ReadOnlyProperty = new _Marshaller_PropertyService_ReadOnlyProperty;
    PropertyService::_tc_PropertyNotFound = 
    "010000001600000058000000010000003100000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f70657274794e6f7446"
    "6f756e643a312e30000000001100000050726f70657274794e6f74466f75"
    "6e640000000000000000";
    _marshaller_PropertyService_PropertyNotFound = new _Marshaller_PropertyService_PropertyNotFound;
    PropertyService::_tc_FixedProperty = 
    "010000001600000050000000010000002e00000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f466978656450726f70657274"
    "793a312e300000000e000000466978656450726f70657274790000000000"
    "0000";
    _marshaller_PropertyService_FixedProperty = new _Marshaller_PropertyService_FixedProperty;
    PropertyService::_tc_PropertySet = 
    "010000000e00000044000000010000002c00000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f70657274795365743a"
    "312e30000c00000050726f706572747953657400";
    _marshaller_PropertyService_PropertySet = new _Marshaller_PropertyService_PropertySet;
    PropertyService::_tc_UnsupportedMode = 
    "010000001600000050000000010000003000000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f556e737570706f727465644d"
    "6f64653a312e300010000000556e737570706f727465644d6f6465000000"
    "0000";
    _marshaller_PropertyService_UnsupportedMode = new _Marshaller_PropertyService_UnsupportedMode;
    PropertyService::_tc_PropertySetDef = 
    "010000000e0000004b000000010000002f00000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f706572747953657444"
    "65663a312e3000000f00000050726f706572747953657444656600";
    _marshaller_PropertyService_PropertySetDef = new _Marshaller_PropertyService_PropertySetDef;
    PropertyService::_tc_ExceptionReason = 
    "01000000110000001b010000010000003000000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f457863657074696f6e526561"
    "736f6e3a312e300010000000457863657074696f6e526561736f6e000800"
    "000016000000696e76616c69645f70726f70657274795f6e616d65000000"
    "15000000636f6e666c696374696e675f70726f7065727479000000001300"
    "000070726f70657274795f6e6f745f666f756e64000016000000756e7375"
    "70706f727465645f747970655f636f646500000015000000756e73757070"
    "6f727465645f70726f70657274790000000011000000756e737570706f72"
    "7465645f6d6f6465000000000f00000066697865645f70726f7065727479"
    "000013000000726561645f6f6e6c795f70726f706572747900";
    _marshaller_PropertyService_ExceptionReason = new _Marshaller_PropertyService_ExceptionReason;
    PropertyService::_tc_PropertyException = 
    "010000000f00000000020000010000003200000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f706572747945786365"
    "7074696f6e3a312e300000001200000050726f7065727479457863657074"
    "696f6e0000000200000007000000726561736f6e0000110000001b010000"
    "010000003000000049444c3a6f6d672e6f72672f50726f70657274795365"
    "72766963652f457863657074696f6e526561736f6e3a312e300010000000"
    "457863657074696f6e526561736f6e000800000016000000696e76616c69"
    "645f70726f70657274795f6e616d6500000015000000636f6e666c696374"
    "696e675f70726f7065727479000000001300000070726f70657274795f6e"
    "6f745f666f756e64000016000000756e737570706f727465645f74797065"
    "5f636f646500000015000000756e737570706f727465645f70726f706572"
    "74790000000011000000756e737570706f727465645f6d6f646500000000"
    "0f00000066697865645f70726f7065727479000013000000726561645f6f"
    "6e6c795f70726f70657274790000160000006661696c696e675f70726f70"
    "657274795f6e616d650000001500000054000000010000002d0000004944"
    "4c3a6f6d672e6f72672f50726f7065727479536572766963652f50726f70"
    "657274794e616d653a312e30000000000d00000050726f70657274794e61"
    "6d65000000001200000000000000";
    _marshaller_PropertyService_PropertyException = new _Marshaller_PropertyService_PropertyException;
    PropertyService::_tc_PropertySetDefFactory = 
    "010000000e0000005a000000010000003600000049444c3a6f6d672e6f72"
    "672f50726f7065727479536572766963652f50726f706572747953657444"
    "6566466163746f72793a312e300000001600000050726f70657274795365"
    "74446566466163746f727900";
    _marshaller_PropertyService_PropertySetDefFactory = new _Marshaller_PropertyService_PropertySetDefFactory;
    _marshaller__seq_PropertyService_Property = new _Marshaller__seq_PropertyService_Property;
    _marshaller__seq_PropertyService_PropertyDef = new _Marshaller__seq_PropertyService_PropertyDef;
    _marshaller__seq_PropertyService_PropertyMode = new _Marshaller__seq_PropertyService_PropertyMode;
    _marshaller__seq_PropertyService_PropertyException = new _Marshaller__seq_PropertyService_PropertyException;
  }

  ~__tc_init_PROPERTYSERVICE()
  {
    delete static_cast<_Marshaller_PropertyService_Property*>(_marshaller_PropertyService_Property);
    delete static_cast<_Marshaller_PropertyService_PropertyModeType*>(_marshaller_PropertyService_PropertyModeType);
    delete static_cast<_Marshaller_PropertyService_PropertyDef*>(_marshaller_PropertyService_PropertyDef);
    delete static_cast<_Marshaller_PropertyService_PropertyMode*>(_marshaller_PropertyService_PropertyMode);
    delete static_cast<_Marshaller_PropertyService_PropertyNamesIterator*>(_marshaller_PropertyService_PropertyNamesIterator);
    delete static_cast<_Marshaller_PropertyService_PropertiesIterator*>(_marshaller_PropertyService_PropertiesIterator);
    delete static_cast<_Marshaller_PropertyService_ConstraintNotSupported*>(_marshaller_PropertyService_ConstraintNotSupported);
    delete static_cast<_Marshaller_PropertyService_MultipleExceptions*>(_marshaller_PropertyService_MultipleExceptions);
    delete static_cast<_Marshaller_PropertyService_PropertySetFactory*>(_marshaller_PropertyService_PropertySetFactory);
    delete static_cast<_Marshaller_PropertyService_InvalidPropertyName*>(_marshaller_PropertyService_InvalidPropertyName);
    delete static_cast<_Marshaller_PropertyService_ConflictingProperty*>(_marshaller_PropertyService_ConflictingProperty);
    delete static_cast<_Marshaller_PropertyService_UnsupportedTypeCode*>(_marshaller_PropertyService_UnsupportedTypeCode);
    delete static_cast<_Marshaller_PropertyService_UnsupportedProperty*>(_marshaller_PropertyService_UnsupportedProperty);
    delete static_cast<_Marshaller_PropertyService_ReadOnlyProperty*>(_marshaller_PropertyService_ReadOnlyProperty);
    delete static_cast<_Marshaller_PropertyService_PropertyNotFound*>(_marshaller_PropertyService_PropertyNotFound);
    delete static_cast<_Marshaller_PropertyService_FixedProperty*>(_marshaller_PropertyService_FixedProperty);
    delete static_cast<_Marshaller_PropertyService_PropertySet*>(_marshaller_PropertyService_PropertySet);
    delete static_cast<_Marshaller_PropertyService_UnsupportedMode*>(_marshaller_PropertyService_UnsupportedMode);
    delete static_cast<_Marshaller_PropertyService_PropertySetDef*>(_marshaller_PropertyService_PropertySetDef);
    delete static_cast<_Marshaller_PropertyService_ExceptionReason*>(_marshaller_PropertyService_ExceptionReason);
    delete static_cast<_Marshaller_PropertyService_PropertyException*>(_marshaller_PropertyService_PropertyException);
    delete static_cast<_Marshaller_PropertyService_PropertySetDefFactory*>(_marshaller_PropertyService_PropertySetDefFactory);
    delete static_cast<_Marshaller__seq_PropertyService_Property*>(_marshaller__seq_PropertyService_Property);
    delete static_cast<_Marshaller__seq_PropertyService_PropertyDef*>(_marshaller__seq_PropertyService_PropertyDef);
    delete static_cast<_Marshaller__seq_PropertyService_PropertyMode*>(_marshaller__seq_PropertyService_PropertyMode);
    delete static_cast<_Marshaller__seq_PropertyService_PropertyException*>(_marshaller__seq_PropertyService_PropertyException);
  }
};

static __tc_init_PROPERTYSERVICE __init_PROPERTYSERVICE;

//--------------------------------------------------------
//  Implementation of skeletons
//--------------------------------------------------------

// PortableServer Skeleton Class for interface PropertyService::PropertyNamesIterator
POA_PropertyService::PropertyNamesIterator::~PropertyNamesIterator()
{
}

::PropertyService::PropertyNamesIterator_ptr
POA_PropertyService::PropertyNamesIterator::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::PropertyService::PropertyNamesIterator::_narrow (obj);
}

CORBA::Boolean
POA_PropertyService::PropertyNamesIterator::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/PropertyService/PropertyNamesIterator:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_PropertyService::PropertyNamesIterator::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/PropertyService/PropertyNamesIterator:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_PropertyService::PropertyNamesIterator::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/PropertyService/PropertyNamesIterator:1.0");
}

CORBA::Object_ptr
POA_PropertyService::PropertyNamesIterator::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::PropertyService::PropertyNamesIterator_stub_clp (poa, obj);
}

bool
POA_PropertyService::PropertyNamesIterator::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    switch (mico_string_hash (__req->op_name(), 7)) {
    case 0:
      if( strcmp( __req->op_name(), "next_n" ) == 0 ) {
        CORBA::ULong _par_how_many;
        CORBA::StaticAny _sa_how_many( CORBA::_stc_ulong, &_par_how_many );
        ::PropertyService::PropertyNames* _par_property_names;
        CORBA::StaticAny _sa_property_names( CORBA::_stcseq_string );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_how_many );
        __req->add_out_arg( &_sa_property_names );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = next_n( _par_how_many, _par_property_names );
        _sa_property_names.value( CORBA::_stcseq_string, _par_property_names );
        __req->write_results();
        delete _par_property_names;
        return true;
      }
      break;
    case 1:
      if( strcmp( __req->op_name(), "reset" ) == 0 ) {

        if( !__req->read_args() )
          return true;

        reset();
        __req->write_results();
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
    case 3:
      if( strcmp( __req->op_name(), "next_one" ) == 0 ) {
        ::PropertyService::PropertyName _par_propery_name;
        CORBA::StaticAny _sa_propery_name( CORBA::_stc_string, &_par_propery_name );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_out_arg( &_sa_propery_name );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = next_one( _par_propery_name );
        __req->write_results();
        CORBA::string_free( _par_propery_name );
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
POA_PropertyService::PropertyNamesIterator::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface PropertyService::PropertiesIterator
POA_PropertyService::PropertiesIterator::~PropertiesIterator()
{
}

::PropertyService::PropertiesIterator_ptr
POA_PropertyService::PropertiesIterator::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::PropertyService::PropertiesIterator::_narrow (obj);
}

CORBA::Boolean
POA_PropertyService::PropertiesIterator::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/PropertyService/PropertiesIterator:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_PropertyService::PropertiesIterator::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/PropertyService/PropertiesIterator:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_PropertyService::PropertiesIterator::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/PropertyService/PropertiesIterator:1.0");
}

CORBA::Object_ptr
POA_PropertyService::PropertiesIterator::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::PropertyService::PropertiesIterator_stub_clp (poa, obj);
}

bool
POA_PropertyService::PropertiesIterator::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    switch (mico_string_hash (__req->op_name(), 7)) {
    case 0:
      if( strcmp( __req->op_name(), "next_n" ) == 0 ) {
        CORBA::ULong _par_how_many;
        CORBA::StaticAny _sa_how_many( CORBA::_stc_ulong, &_par_how_many );
        ::PropertyService::Properties* _par_nproperties;
        CORBA::StaticAny _sa_nproperties( _marshaller__seq_PropertyService_Property );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_how_many );
        __req->add_out_arg( &_sa_nproperties );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = next_n( _par_how_many, _par_nproperties );
        _sa_nproperties.value( _marshaller__seq_PropertyService_Property, _par_nproperties );
        __req->write_results();
        delete _par_nproperties;
        return true;
      }
      break;
    case 1:
      if( strcmp( __req->op_name(), "reset" ) == 0 ) {

        if( !__req->read_args() )
          return true;

        reset();
        __req->write_results();
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
    case 3:
      if( strcmp( __req->op_name(), "next_one" ) == 0 ) {
        ::PropertyService::Property* _par_aproperty;
        CORBA::StaticAny _sa_aproperty( _marshaller_PropertyService_Property );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_out_arg( &_sa_aproperty );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = next_one( _par_aproperty );
        _sa_aproperty.value( _marshaller_PropertyService_Property, _par_aproperty );
        __req->write_results();
        delete _par_aproperty;
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
POA_PropertyService::PropertiesIterator::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface PropertyService::PropertySetFactory
POA_PropertyService::PropertySetFactory::~PropertySetFactory()
{
}

::PropertyService::PropertySetFactory_ptr
POA_PropertyService::PropertySetFactory::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::PropertyService::PropertySetFactory::_narrow (obj);
}

CORBA::Boolean
POA_PropertyService::PropertySetFactory::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/PropertyService/PropertySetFactory:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_PropertyService::PropertySetFactory::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/PropertyService/PropertySetFactory:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_PropertyService::PropertySetFactory::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/PropertyService/PropertySetFactory:1.0");
}

CORBA::Object_ptr
POA_PropertyService::PropertySetFactory::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::PropertyService::PropertySetFactory_stub_clp (poa, obj);
}

bool
POA_PropertyService::PropertySetFactory::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "create_propertyset" ) == 0 ) {
      ::PropertyService::PropertySet_ptr _res;
      CORBA::StaticAny __res( _marshaller_PropertyService_PropertySet, &_res );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = create_propertyset();
      __req->write_results();
      CORBA::release( _res );
      return true;
    }
    if( strcmp( __req->op_name(), "create_constrained_propertyset" ) == 0 ) {
      ::PropertyService::PropertyTypes _par_allowed_property_types;
      CORBA::StaticAny _sa_allowed_property_types( _marshaller__seq_TypeCode, &_par_allowed_property_types );
      ::PropertyService::Properties _par_allowed_properties;
      CORBA::StaticAny _sa_allowed_properties( _marshaller__seq_PropertyService_Property, &_par_allowed_properties );

      ::PropertyService::PropertySet_ptr _res;
      CORBA::StaticAny __res( _marshaller_PropertyService_PropertySet, &_res );
      __req->add_in_arg( &_sa_allowed_property_types );
      __req->add_in_arg( &_sa_allowed_properties );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _res = create_constrained_propertyset( _par_allowed_property_types, _par_allowed_properties );
      #ifdef HAVE_EXCEPTIONS
      } catch( ::PropertyService::ConstraintNotSupported_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      }
      #endif
      __req->write_results();
      CORBA::release( _res );
      return true;
    }
    if( strcmp( __req->op_name(), "create_initial_propertyset" ) == 0 ) {
      ::PropertyService::Properties _par_initial_properties;
      CORBA::StaticAny _sa_initial_properties( _marshaller__seq_PropertyService_Property, &_par_initial_properties );

      ::PropertyService::PropertySet_ptr _res;
      CORBA::StaticAny __res( _marshaller_PropertyService_PropertySet, &_res );
      __req->add_in_arg( &_sa_initial_properties );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _res = create_initial_propertyset( _par_initial_properties );
      #ifdef HAVE_EXCEPTIONS
      } catch( ::PropertyService::MultipleExceptions_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      }
      #endif
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
POA_PropertyService::PropertySetFactory::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface PropertyService::PropertySet
POA_PropertyService::PropertySet::~PropertySet()
{
}

::PropertyService::PropertySet_ptr
POA_PropertyService::PropertySet::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::PropertyService::PropertySet::_narrow (obj);
}

CORBA::Boolean
POA_PropertyService::PropertySet::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/PropertyService/PropertySet:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_PropertyService::PropertySet::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/PropertyService/PropertySet:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_PropertyService::PropertySet::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/PropertyService/PropertySet:1.0");
}

CORBA::Object_ptr
POA_PropertyService::PropertySet::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::PropertyService::PropertySet_stub_clp (poa, obj);
}

bool
POA_PropertyService::PropertySet::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    switch (mico_string_hash (__req->op_name(), 17)) {
    case 0:
      if( strcmp( __req->op_name(), "get_all_properties" ) == 0 ) {
        CORBA::ULong _par_how_many;
        CORBA::StaticAny _sa_how_many( CORBA::_stc_ulong, &_par_how_many );
        ::PropertyService::Properties* _par_nproperties;
        CORBA::StaticAny _sa_nproperties( _marshaller__seq_PropertyService_Property );
        ::PropertyService::PropertiesIterator_ptr _par_rest;
        CORBA::StaticAny _sa_rest( _marshaller_PropertyService_PropertiesIterator, &_par_rest );

        __req->add_in_arg( &_sa_how_many );
        __req->add_out_arg( &_sa_nproperties );
        __req->add_out_arg( &_sa_rest );

        if( !__req->read_args() )
          return true;

        get_all_properties( _par_how_many, _par_nproperties, _par_rest );
        _sa_nproperties.value( _marshaller__seq_PropertyService_Property, _par_nproperties );
        __req->write_results();
        delete _par_nproperties;
        CORBA::release( _par_rest );
        return true;
      }
      break;
    case 2:
      if( strcmp( __req->op_name(), "define_properties" ) == 0 ) {
        ::PropertyService::Properties _par_nproperties;
        CORBA::StaticAny _sa_nproperties( _marshaller__seq_PropertyService_Property, &_par_nproperties );

        __req->add_in_arg( &_sa_nproperties );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          define_properties( _par_nproperties );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::PropertyService::MultipleExceptions_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "get_properties" ) == 0 ) {
        ::PropertyService::PropertyNames _par_property_names;
        CORBA::StaticAny _sa_property_names( CORBA::_stcseq_string, &_par_property_names );
        ::PropertyService::Properties* _par_nproperties;
        CORBA::StaticAny _sa_nproperties( _marshaller__seq_PropertyService_Property );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_property_names );
        __req->add_out_arg( &_sa_nproperties );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = get_properties( _par_property_names, _par_nproperties );
        _sa_nproperties.value( _marshaller__seq_PropertyService_Property, _par_nproperties );
        __req->write_results();
        delete _par_nproperties;
        return true;
      }
      break;
    case 3:
      if( strcmp( __req->op_name(), "get_property_value" ) == 0 ) {
        ::PropertyService::PropertyName_var _par_property_name;
        CORBA::StaticAny _sa_property_name( CORBA::_stc_string, &_par_property_name._for_demarshal() );

        CORBA::Any* _res;
        CORBA::StaticAny __res( CORBA::_stc_any );
        __req->add_in_arg( &_sa_property_name );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          _res = get_property_value( _par_property_name.inout() );
          __res.value( CORBA::_stc_any, _res );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::PropertyService::InvalidPropertyName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::PropertyNotFound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        delete _res;
        return true;
      }
      break;
    case 8:
      if( strcmp( __req->op_name(), "define_property" ) == 0 ) {
        ::PropertyService::PropertyName_var _par_property_name;
        CORBA::StaticAny _sa_property_name( CORBA::_stc_string, &_par_property_name._for_demarshal() );
        CORBA::Any _par_property_value;
        CORBA::StaticAny _sa_property_value( CORBA::_stc_any, &_par_property_value );

        __req->add_in_arg( &_sa_property_name );
        __req->add_in_arg( &_sa_property_value );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          define_property( _par_property_name.inout(), _par_property_value );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::PropertyService::InvalidPropertyName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::ConflictingProperty_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::UnsupportedTypeCode_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::UnsupportedProperty_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::ReadOnlyProperty_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      break;
    case 9:
      if( strcmp( __req->op_name(), "delete_property" ) == 0 ) {
        ::PropertyService::PropertyName_var _par_property_name;
        CORBA::StaticAny _sa_property_name( CORBA::_stc_string, &_par_property_name._for_demarshal() );

        __req->add_in_arg( &_sa_property_name );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          delete_property( _par_property_name.inout() );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::PropertyService::InvalidPropertyName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::PropertyNotFound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::FixedProperty_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      break;
    case 14:
      if( strcmp( __req->op_name(), "delete_all_properties" ) == 0 ) {
        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = delete_all_properties();
        __req->write_results();
        return true;
      }
      break;
    case 15:
      if( strcmp( __req->op_name(), "is_property_defined" ) == 0 ) {
        ::PropertyService::PropertyName_var _par_property_name;
        CORBA::StaticAny _sa_property_name( CORBA::_stc_string, &_par_property_name._for_demarshal() );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_property_name );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          _res = is_property_defined( _par_property_name.inout() );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::PropertyService::InvalidPropertyName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      break;
    case 16:
      if( strcmp( __req->op_name(), "get_number_of_properties" ) == 0 ) {
        CORBA::ULong _res;
        CORBA::StaticAny __res( CORBA::_stc_ulong, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = get_number_of_properties();
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "get_all_property_names" ) == 0 ) {
        CORBA::ULong _par_how_many;
        CORBA::StaticAny _sa_how_many( CORBA::_stc_ulong, &_par_how_many );
        ::PropertyService::PropertyNames* _par_property_names;
        CORBA::StaticAny _sa_property_names( CORBA::_stcseq_string );
        ::PropertyService::PropertyNamesIterator_ptr _par_rest;
        CORBA::StaticAny _sa_rest( _marshaller_PropertyService_PropertyNamesIterator, &_par_rest );

        __req->add_in_arg( &_sa_how_many );
        __req->add_out_arg( &_sa_property_names );
        __req->add_out_arg( &_sa_rest );

        if( !__req->read_args() )
          return true;

        get_all_property_names( _par_how_many, _par_property_names, _par_rest );
        _sa_property_names.value( CORBA::_stcseq_string, _par_property_names );
        __req->write_results();
        delete _par_property_names;
        CORBA::release( _par_rest );
        return true;
      }
      if( strcmp( __req->op_name(), "delete_properties" ) == 0 ) {
        ::PropertyService::PropertyNames _par_property_names;
        CORBA::StaticAny _sa_property_names( CORBA::_stcseq_string, &_par_property_names );

        __req->add_in_arg( &_sa_property_names );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          delete_properties( _par_property_names );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::PropertyService::MultipleExceptions_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
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
POA_PropertyService::PropertySet::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface PropertyService::PropertySetDef
POA_PropertyService::PropertySetDef::~PropertySetDef()
{
}

::PropertyService::PropertySetDef_ptr
POA_PropertyService::PropertySetDef::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::PropertyService::PropertySetDef::_narrow (obj);
}

CORBA::Boolean
POA_PropertyService::PropertySetDef::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/PropertyService/PropertySetDef:1.0") == 0) {
    return TRUE;
  }
  if (POA_PropertyService::PropertySet::_is_a (repoid)) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_PropertyService::PropertySetDef::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/PropertyService/PropertySetDef:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_PropertyService::PropertySetDef::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/PropertyService/PropertySetDef:1.0");
}

CORBA::Object_ptr
POA_PropertyService::PropertySetDef::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::PropertyService::PropertySetDef_stub_clp (poa, obj);
}

bool
POA_PropertyService::PropertySetDef::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    switch (mico_string_hash (__req->op_name(), 13)) {
    case 1:
      if( strcmp( __req->op_name(), "define_properties_with_modes" ) == 0 ) {
        ::PropertyService::PropertyDefs _par_property_defs;
        CORBA::StaticAny _sa_property_defs( _marshaller__seq_PropertyService_PropertyDef, &_par_property_defs );

        __req->add_in_arg( &_sa_property_defs );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          define_properties_with_modes( _par_property_defs );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::PropertyService::MultipleExceptions_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      break;
    case 2:
      if( strcmp( __req->op_name(), "get_property_mode" ) == 0 ) {
        ::PropertyService::PropertyName_var _par_property_name;
        CORBA::StaticAny _sa_property_name( CORBA::_stc_string, &_par_property_name._for_demarshal() );

        ::PropertyService::PropertyModeType _res;
        CORBA::StaticAny __res( _marshaller_PropertyService_PropertyModeType, &_res );
        __req->add_in_arg( &_sa_property_name );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          _res = get_property_mode( _par_property_name.inout() );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::PropertyService::PropertyNotFound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::InvalidPropertyName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      break;
    case 5:
      if( strcmp( __req->op_name(), "define_property_with_mode" ) == 0 ) {
        ::PropertyService::PropertyName_var _par_property_name;
        CORBA::StaticAny _sa_property_name( CORBA::_stc_string, &_par_property_name._for_demarshal() );
        CORBA::Any _par_property_value;
        CORBA::StaticAny _sa_property_value( CORBA::_stc_any, &_par_property_value );
        ::PropertyService::PropertyModeType _par_property_mode;
        CORBA::StaticAny _sa_property_mode( _marshaller_PropertyService_PropertyModeType, &_par_property_mode );

        __req->add_in_arg( &_sa_property_name );
        __req->add_in_arg( &_sa_property_value );
        __req->add_in_arg( &_sa_property_mode );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          define_property_with_mode( _par_property_name.inout(), _par_property_value, _par_property_mode );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::PropertyService::InvalidPropertyName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::ConflictingProperty_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::UnsupportedTypeCode_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::UnsupportedProperty_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::UnsupportedMode_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::ReadOnlyProperty_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      break;
    case 6:
      if( strcmp( __req->op_name(), "set_property_modes" ) == 0 ) {
        ::PropertyService::PropertyModes _par_property_modes;
        CORBA::StaticAny _sa_property_modes( _marshaller__seq_PropertyService_PropertyMode, &_par_property_modes );

        __req->add_in_arg( &_sa_property_modes );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          set_property_modes( _par_property_modes );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::PropertyService::MultipleExceptions_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      break;
    case 7:
      if( strcmp( __req->op_name(), "get_allowed_property_types" ) == 0 ) {
        ::PropertyService::PropertyTypes* _par_property_types;
        CORBA::StaticAny _sa_property_types( _marshaller__seq_TypeCode );

        __req->add_out_arg( &_sa_property_types );

        if( !__req->read_args() )
          return true;

        get_allowed_property_types( _par_property_types );
        _sa_property_types.value( _marshaller__seq_TypeCode, _par_property_types );
        __req->write_results();
        delete _par_property_types;
        return true;
      }
      if( strcmp( __req->op_name(), "set_property_mode" ) == 0 ) {
        ::PropertyService::PropertyName_var _par_property_name;
        CORBA::StaticAny _sa_property_name( CORBA::_stc_string, &_par_property_name._for_demarshal() );
        ::PropertyService::PropertyModeType _par_property_mode;
        CORBA::StaticAny _sa_property_mode( _marshaller_PropertyService_PropertyModeType, &_par_property_mode );

        __req->add_in_arg( &_sa_property_name );
        __req->add_in_arg( &_sa_property_mode );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          set_property_mode( _par_property_name.inout(), _par_property_mode );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::PropertyService::InvalidPropertyName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::PropertyNotFound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::PropertyService::UnsupportedMode_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      break;
    case 10:
      if( strcmp( __req->op_name(), "get_property_modes" ) == 0 ) {
        ::PropertyService::PropertyNames _par_property_names;
        CORBA::StaticAny _sa_property_names( CORBA::_stcseq_string, &_par_property_names );
        ::PropertyService::PropertyModes* _par_property_modes;
        CORBA::StaticAny _sa_property_modes( _marshaller__seq_PropertyService_PropertyMode );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_property_names );
        __req->add_out_arg( &_sa_property_modes );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = get_property_modes( _par_property_names, _par_property_modes );
        _sa_property_modes.value( _marshaller__seq_PropertyService_PropertyMode, _par_property_modes );
        __req->write_results();
        delete _par_property_modes;
        return true;
      }
      break;
    case 12:
      if( strcmp( __req->op_name(), "get_allowed_properties" ) == 0 ) {
        ::PropertyService::PropertyDefs* _par_property_defs;
        CORBA::StaticAny _sa_property_defs( _marshaller__seq_PropertyService_PropertyDef );

        __req->add_out_arg( &_sa_property_defs );

        if( !__req->read_args() )
          return true;

        get_allowed_properties( _par_property_defs );
        _sa_property_defs.value( _marshaller__seq_PropertyService_PropertyDef, _par_property_defs );
        __req->write_results();
        delete _par_property_defs;
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

  if (POA_PropertyService::PropertySet::dispatch (__req)) {
    return true;
  }

  return false;
}

void
POA_PropertyService::PropertySetDef::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface PropertyService::PropertySetDefFactory
POA_PropertyService::PropertySetDefFactory::~PropertySetDefFactory()
{
}

::PropertyService::PropertySetDefFactory_ptr
POA_PropertyService::PropertySetDefFactory::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::PropertyService::PropertySetDefFactory::_narrow (obj);
}

CORBA::Boolean
POA_PropertyService::PropertySetDefFactory::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/PropertyService/PropertySetDefFactory:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_PropertyService::PropertySetDefFactory::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/PropertyService/PropertySetDefFactory:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_PropertyService::PropertySetDefFactory::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/PropertyService/PropertySetDefFactory:1.0");
}

CORBA::Object_ptr
POA_PropertyService::PropertySetDefFactory::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::PropertyService::PropertySetDefFactory_stub_clp (poa, obj);
}

bool
POA_PropertyService::PropertySetDefFactory::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "create_propertysetdef" ) == 0 ) {
      ::PropertyService::PropertySetDef_ptr _res;
      CORBA::StaticAny __res( _marshaller_PropertyService_PropertySetDef, &_res );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = create_propertysetdef();
      __req->write_results();
      CORBA::release( _res );
      return true;
    }
    if( strcmp( __req->op_name(), "create_constrained_propertysetdef" ) == 0 ) {
      ::PropertyService::PropertyTypes _par_allowed_property_types;
      CORBA::StaticAny _sa_allowed_property_types( _marshaller__seq_TypeCode, &_par_allowed_property_types );
      ::PropertyService::PropertyDefs _par_allowed_property_defs;
      CORBA::StaticAny _sa_allowed_property_defs( _marshaller__seq_PropertyService_PropertyDef, &_par_allowed_property_defs );

      ::PropertyService::PropertySetDef_ptr _res;
      CORBA::StaticAny __res( _marshaller_PropertyService_PropertySetDef, &_res );
      __req->add_in_arg( &_sa_allowed_property_types );
      __req->add_in_arg( &_sa_allowed_property_defs );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _res = create_constrained_propertysetdef( _par_allowed_property_types, _par_allowed_property_defs );
      #ifdef HAVE_EXCEPTIONS
      } catch( ::PropertyService::ConstraintNotSupported_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      }
      #endif
      __req->write_results();
      CORBA::release( _res );
      return true;
    }
    if( strcmp( __req->op_name(), "create_initial_propertysetdef" ) == 0 ) {
      ::PropertyService::PropertyDefs _par_initial_property_defs;
      CORBA::StaticAny _sa_initial_property_defs( _marshaller__seq_PropertyService_PropertyDef, &_par_initial_property_defs );

      ::PropertyService::PropertySetDef_ptr _res;
      CORBA::StaticAny __res( _marshaller_PropertyService_PropertySetDef, &_res );
      __req->add_in_arg( &_sa_initial_property_defs );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _res = create_initial_propertysetdef( _par_initial_property_defs );
      #ifdef HAVE_EXCEPTIONS
      } catch( ::PropertyService::MultipleExceptions_catch &_ex ) {
        __req->set_exception( _ex->_clone() );
        __req->write_results();
        return true;
      }
      #endif
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
POA_PropertyService::PropertySetDefFactory::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}

