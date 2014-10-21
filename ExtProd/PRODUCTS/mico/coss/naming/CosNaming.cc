/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CosNaming.h>


using namespace std;

//--------------------------------------------------------
//  Implementation of stubs
//--------------------------------------------------------

#ifdef HAVE_EXPLICIT_STRUCT_OPS
CosNaming::NameComponent::NameComponent()
{
}

CosNaming::NameComponent::NameComponent( const NameComponent& _s )
{
  id = ((NameComponent&)_s).id;
  kind = ((NameComponent&)_s).kind;
}

CosNaming::NameComponent::~NameComponent()
{
}

CosNaming::NameComponent&
CosNaming::NameComponent::operator=( const NameComponent& _s )
{
  id = ((NameComponent&)_s).id;
  kind = ((NameComponent&)_s).kind;
  return *this;
}
#endif

class _Marshaller_CosNaming_NameComponent : public ::CORBA::StaticTypeInfo {
    typedef CosNaming::NameComponent _MICO_T;
  public:
    ~_Marshaller_CosNaming_NameComponent();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosNaming_NameComponent::~_Marshaller_CosNaming_NameComponent()
{
}

::CORBA::StaticValueType _Marshaller_CosNaming_NameComponent::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosNaming_NameComponent::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosNaming_NameComponent::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosNaming_NameComponent::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->id._for_demarshal() ) &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->kind._for_demarshal() ) &&
    dc.struct_end();
}

void _Marshaller_CosNaming_NameComponent::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->id.inout() );
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->kind.inout() );
  ec.struct_end();
}

::CORBA::StaticTypeInfo *_marshaller_CosNaming_NameComponent;



class _Marshaller_CosNaming_BindingType : public ::CORBA::StaticTypeInfo {
    typedef CosNaming::BindingType _MICO_T;
  public:
    ~_Marshaller_CosNaming_BindingType();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosNaming_BindingType::~_Marshaller_CosNaming_BindingType()
{
}

::CORBA::StaticValueType _Marshaller_CosNaming_BindingType::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosNaming_BindingType::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosNaming_BindingType::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosNaming_BindingType::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong ul;
  if( !dc.enumeration( ul ) )
    return FALSE;
  *(_MICO_T*) v = (_MICO_T) ul;
  return TRUE;
}

void _Marshaller_CosNaming_BindingType::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.enumeration( (::CORBA::ULong) *(_MICO_T *) v );
}

::CORBA::StaticTypeInfo *_marshaller_CosNaming_BindingType;

#ifdef HAVE_EXPLICIT_STRUCT_OPS
CosNaming::Binding::Binding()
{
}

CosNaming::Binding::Binding( const Binding& _s )
{
  binding_name = ((Binding&)_s).binding_name;
  binding_type = ((Binding&)_s).binding_type;
}

CosNaming::Binding::~Binding()
{
}

CosNaming::Binding&
CosNaming::Binding::operator=( const Binding& _s )
{
  binding_name = ((Binding&)_s).binding_name;
  binding_type = ((Binding&)_s).binding_type;
  return *this;
}
#endif

class _Marshaller_CosNaming_Binding : public ::CORBA::StaticTypeInfo {
    typedef CosNaming::Binding _MICO_T;
  public:
    ~_Marshaller_CosNaming_Binding();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosNaming_Binding::~_Marshaller_CosNaming_Binding()
{
}

::CORBA::StaticValueType _Marshaller_CosNaming_Binding::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosNaming_Binding::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosNaming_Binding::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosNaming_Binding::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    _marshaller__seq_CosNaming_NameComponent->demarshal( dc, &((_MICO_T*)v)->binding_name ) &&
    _marshaller_CosNaming_BindingType->demarshal( dc, &((_MICO_T*)v)->binding_type ) &&
    dc.struct_end();
}

void _Marshaller_CosNaming_Binding::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  _marshaller__seq_CosNaming_NameComponent->marshal( ec, &((_MICO_T*)v)->binding_name );
  _marshaller_CosNaming_BindingType->marshal( ec, &((_MICO_T*)v)->binding_type );
  ec.struct_end();
}

::CORBA::StaticTypeInfo *_marshaller_CosNaming_Binding;



/*
 * Base interface for class BindingIterator
 */

CosNaming::BindingIterator::~BindingIterator()
{
}

void *
CosNaming::BindingIterator::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosNaming/BindingIterator:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

CosNaming::BindingIterator_ptr
CosNaming::BindingIterator::_narrow( CORBA::Object_ptr _obj )
{
  CosNaming::BindingIterator_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosNaming/BindingIterator:1.0" )))
      return _duplicate( (CosNaming::BindingIterator_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosNaming/BindingIterator:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosNaming/BindingIterator:1.0")) {
      _o = new CosNaming::BindingIterator_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosNaming::BindingIterator_ptr
CosNaming::BindingIterator::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosNaming_BindingIterator : public ::CORBA::StaticTypeInfo {
    typedef CosNaming::BindingIterator_ptr _MICO_T;
  public:
    ~_Marshaller_CosNaming_BindingIterator();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosNaming_BindingIterator::~_Marshaller_CosNaming_BindingIterator()
{
}

::CORBA::StaticValueType _Marshaller_CosNaming_BindingIterator::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosNaming_BindingIterator::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosNaming::BindingIterator::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosNaming_BindingIterator::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosNaming_BindingIterator::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosNaming_BindingIterator::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosNaming::BindingIterator::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosNaming_BindingIterator::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosNaming_BindingIterator;


/*
 * Stub interface for class BindingIterator
 */

CosNaming::BindingIterator_stub::~BindingIterator_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosNaming::BindingIterator::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosNaming/BindingIterator:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_CosNaming::BindingIterator *
POA_CosNaming::BindingIterator::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosNaming/BindingIterator:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosNaming::BindingIterator *) p;
  }
  return NULL;
}

CosNaming::BindingIterator_stub_clp::BindingIterator_stub_clp ()
{
}

CosNaming::BindingIterator_stub_clp::BindingIterator_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosNaming::BindingIterator_stub_clp::~BindingIterator_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean CosNaming::BindingIterator_stub::next_one( CosNaming::Binding_out _par_b )
{
  CORBA::StaticAny _sa_b( _marshaller_CosNaming_Binding );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "next_one" );
  __req.add_out_arg( &_sa_b );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  _par_b = (CosNaming::Binding*) _sa_b._retn();
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
CosNaming::BindingIterator_stub_clp::next_one( CosNaming::Binding_out _par_b )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::BindingIterator * _myserv = POA_CosNaming::BindingIterator::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->next_one(_par_b);
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

  return CosNaming::BindingIterator_stub::next_one(_par_b);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean CosNaming::BindingIterator_stub::next_n( CORBA::ULong _par_how_many, CosNaming::BindingList_out _par_bl )
{
  CORBA::StaticAny _sa_how_many( CORBA::_stc_ulong, &_par_how_many );
  CORBA::StaticAny _sa_bl( _marshaller__seq_CosNaming_Binding );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "next_n" );
  __req.add_in_arg( &_sa_how_many );
  __req.add_out_arg( &_sa_bl );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  _par_bl = (CosNaming::BindingList*) _sa_bl._retn();
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
CosNaming::BindingIterator_stub_clp::next_n( CORBA::ULong _par_how_many, CosNaming::BindingList_out _par_bl )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::BindingIterator * _myserv = POA_CosNaming::BindingIterator::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->next_n(_par_how_many, _par_bl);
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

  return CosNaming::BindingIterator_stub::next_n(_par_how_many, _par_bl);
}

#endif // MICO_CONF_NO_POA

void CosNaming::BindingIterator_stub::destroy()
{
  CORBA::StaticRequest __req( this, "destroy" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosNaming::BindingIterator_stub_clp::destroy()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::BindingIterator * _myserv = POA_CosNaming::BindingIterator::_narrow (_serv);
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

  CosNaming::BindingIterator_stub::destroy();
}

#endif // MICO_CONF_NO_POA


class _Marshaller_CosNaming_NamingContext_NotFoundReason : public ::CORBA::StaticTypeInfo {
    typedef CosNaming::NamingContext::NotFoundReason _MICO_T;
  public:
    ~_Marshaller_CosNaming_NamingContext_NotFoundReason();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosNaming_NamingContext_NotFoundReason::~_Marshaller_CosNaming_NamingContext_NotFoundReason()
{
}

::CORBA::StaticValueType _Marshaller_CosNaming_NamingContext_NotFoundReason::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosNaming_NamingContext_NotFoundReason::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosNaming_NamingContext_NotFoundReason::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosNaming_NamingContext_NotFoundReason::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong ul;
  if( !dc.enumeration( ul ) )
    return FALSE;
  *(_MICO_T*) v = (_MICO_T) ul;
  return TRUE;
}

void _Marshaller_CosNaming_NamingContext_NotFoundReason::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.enumeration( (::CORBA::ULong) *(_MICO_T *) v );
}

::CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContext_NotFoundReason;


#ifdef HAVE_EXPLICIT_STRUCT_OPS
CosNaming::NamingContext::NotFound::NotFound()
{
}

CosNaming::NamingContext::NotFound::NotFound( const NotFound& _s )
{
  why = ((NotFound&)_s).why;
  rest_of_name = ((NotFound&)_s).rest_of_name;
}

CosNaming::NamingContext::NotFound::~NotFound()
{
}

CosNaming::NamingContext::NotFound&
CosNaming::NamingContext::NotFound::operator=( const NotFound& _s )
{
  why = ((NotFound&)_s).why;
  rest_of_name = ((NotFound&)_s).rest_of_name;
  return *this;
}
#endif

#ifndef HAVE_EXPLICIT_STRUCT_OPS
CosNaming::NamingContext::NotFound::NotFound()
{
}

#endif

CosNaming::NamingContext::NotFound::NotFound( CosNaming::NamingContext::NotFoundReason _m0, const CosNaming::Name& _m1 )
{
  why = _m0;
  rest_of_name = _m1;
}

class _Marshaller_CosNaming_NamingContext_NotFound : public ::CORBA::StaticTypeInfo {
    typedef ::CosNaming::NamingContext::NotFound _MICO_T;
  public:
    ~_Marshaller_CosNaming_NamingContext_NotFound();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosNaming_NamingContext_NotFound::~_Marshaller_CosNaming_NamingContext_NotFound()
{
}

::CORBA::StaticValueType _Marshaller_CosNaming_NamingContext_NotFound::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosNaming_NamingContext_NotFound::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosNaming_NamingContext_NotFound::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosNaming_NamingContext_NotFound::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    _marshaller_CosNaming_NamingContext_NotFoundReason->demarshal( dc, &((_MICO_T*)v)->why ) &&
    _marshaller__seq_CosNaming_NameComponent->demarshal( dc, &((_MICO_T*)v)->rest_of_name ) &&
    dc.except_end();
}

void _Marshaller_CosNaming_NamingContext_NotFound::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0" );
  _marshaller_CosNaming_NamingContext_NotFoundReason->marshal( ec, &((_MICO_T*)v)->why );
  _marshaller__seq_CosNaming_NameComponent->marshal( ec, &((_MICO_T*)v)->rest_of_name );
  ec.except_end();
}

::CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContext_NotFound;

void CosNaming::NamingContext::NotFound::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw NotFound_var( (CosNaming::NamingContext::NotFound*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *CosNaming::NamingContext::NotFound::_repoid() const
{
  return "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0";
}

void CosNaming::NamingContext::NotFound::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_CosNaming_NamingContext_NotFound->marshal( _en, (void*) this );
}

void CosNaming::NamingContext::NotFound::_encode_any( CORBA::Any & ) const
{
  // use --any to make this work!
  assert(0);
}

CORBA::Exception *CosNaming::NamingContext::NotFound::_clone() const
{
  return new NotFound( *this );
}

CosNaming::NamingContext::NotFound *CosNaming::NamingContext::NotFound::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0" ) )
    return (NotFound *) _ex;
  return NULL;
}

const CosNaming::NamingContext::NotFound *CosNaming::NamingContext::NotFound::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0" ) )
    return (NotFound *) _ex;
  return NULL;
}


#ifdef HAVE_EXPLICIT_STRUCT_OPS
CosNaming::NamingContext::CannotProceed::CannotProceed()
{
}

CosNaming::NamingContext::CannotProceed::CannotProceed( const CannotProceed& _s )
{
  cxt = ((CannotProceed&)_s).cxt;
  rest_of_name = ((CannotProceed&)_s).rest_of_name;
}

CosNaming::NamingContext::CannotProceed::~CannotProceed()
{
}

CosNaming::NamingContext::CannotProceed&
CosNaming::NamingContext::CannotProceed::operator=( const CannotProceed& _s )
{
  cxt = ((CannotProceed&)_s).cxt;
  rest_of_name = ((CannotProceed&)_s).rest_of_name;
  return *this;
}
#endif

#ifndef HAVE_EXPLICIT_STRUCT_OPS
CosNaming::NamingContext::CannotProceed::CannotProceed()
{
}

#endif

CosNaming::NamingContext::CannotProceed::CannotProceed( CosNaming::NamingContext_ptr _m0, const CosNaming::Name& _m1 )
{
  cxt = CosNaming::NamingContext::_duplicate( _m0 );
  rest_of_name = _m1;
}

class _Marshaller_CosNaming_NamingContext_CannotProceed : public ::CORBA::StaticTypeInfo {
    typedef ::CosNaming::NamingContext::CannotProceed _MICO_T;
  public:
    ~_Marshaller_CosNaming_NamingContext_CannotProceed();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosNaming_NamingContext_CannotProceed::~_Marshaller_CosNaming_NamingContext_CannotProceed()
{
}

::CORBA::StaticValueType _Marshaller_CosNaming_NamingContext_CannotProceed::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosNaming_NamingContext_CannotProceed::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosNaming_NamingContext_CannotProceed::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosNaming_NamingContext_CannotProceed::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    _marshaller_CosNaming_NamingContext->demarshal( dc, &((_MICO_T*)v)->cxt._for_demarshal() ) &&
    _marshaller__seq_CosNaming_NameComponent->demarshal( dc, &((_MICO_T*)v)->rest_of_name ) &&
    dc.except_end();
}

void _Marshaller_CosNaming_NamingContext_CannotProceed::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0" );
  _marshaller_CosNaming_NamingContext->marshal( ec, &((_MICO_T*)v)->cxt.inout() );
  _marshaller__seq_CosNaming_NameComponent->marshal( ec, &((_MICO_T*)v)->rest_of_name );
  ec.except_end();
}

::CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContext_CannotProceed;

void CosNaming::NamingContext::CannotProceed::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw CannotProceed_var( (CosNaming::NamingContext::CannotProceed*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *CosNaming::NamingContext::CannotProceed::_repoid() const
{
  return "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0";
}

void CosNaming::NamingContext::CannotProceed::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_CosNaming_NamingContext_CannotProceed->marshal( _en, (void*) this );
}

void CosNaming::NamingContext::CannotProceed::_encode_any( CORBA::Any & ) const
{
  // use --any to make this work!
  assert(0);
}

CORBA::Exception *CosNaming::NamingContext::CannotProceed::_clone() const
{
  return new CannotProceed( *this );
}

CosNaming::NamingContext::CannotProceed *CosNaming::NamingContext::CannotProceed::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0" ) )
    return (CannotProceed *) _ex;
  return NULL;
}

const CosNaming::NamingContext::CannotProceed *CosNaming::NamingContext::CannotProceed::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0" ) )
    return (CannotProceed *) _ex;
  return NULL;
}


#ifdef HAVE_EXPLICIT_STRUCT_OPS
CosNaming::NamingContext::InvalidName::InvalidName()
{
}

CosNaming::NamingContext::InvalidName::InvalidName( const InvalidName& _s )
{
}

CosNaming::NamingContext::InvalidName::~InvalidName()
{
}

CosNaming::NamingContext::InvalidName&
CosNaming::NamingContext::InvalidName::operator=( const InvalidName& _s )
{
  return *this;
}
#endif

class _Marshaller_CosNaming_NamingContext_InvalidName : public ::CORBA::StaticTypeInfo {
    typedef ::CosNaming::NamingContext::InvalidName _MICO_T;
  public:
    ~_Marshaller_CosNaming_NamingContext_InvalidName();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosNaming_NamingContext_InvalidName::~_Marshaller_CosNaming_NamingContext_InvalidName()
{
}

::CORBA::StaticValueType _Marshaller_CosNaming_NamingContext_InvalidName::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosNaming_NamingContext_InvalidName::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosNaming_NamingContext_InvalidName::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosNaming_NamingContext_InvalidName::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_CosNaming_NamingContext_InvalidName::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0" );
  ec.except_end();
}

::CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContext_InvalidName;

void CosNaming::NamingContext::InvalidName::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw InvalidName_var( (CosNaming::NamingContext::InvalidName*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *CosNaming::NamingContext::InvalidName::_repoid() const
{
  return "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0";
}

void CosNaming::NamingContext::InvalidName::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_CosNaming_NamingContext_InvalidName->marshal( _en, (void*) this );
}

void CosNaming::NamingContext::InvalidName::_encode_any( CORBA::Any & ) const
{
  // use --any to make this work!
  assert(0);
}

CORBA::Exception *CosNaming::NamingContext::InvalidName::_clone() const
{
  return new InvalidName( *this );
}

CosNaming::NamingContext::InvalidName *CosNaming::NamingContext::InvalidName::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0" ) )
    return (InvalidName *) _ex;
  return NULL;
}

const CosNaming::NamingContext::InvalidName *CosNaming::NamingContext::InvalidName::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0" ) )
    return (InvalidName *) _ex;
  return NULL;
}


#ifdef HAVE_EXPLICIT_STRUCT_OPS
CosNaming::NamingContext::AlreadyBound::AlreadyBound()
{
}

CosNaming::NamingContext::AlreadyBound::AlreadyBound( const AlreadyBound& _s )
{
}

CosNaming::NamingContext::AlreadyBound::~AlreadyBound()
{
}

CosNaming::NamingContext::AlreadyBound&
CosNaming::NamingContext::AlreadyBound::operator=( const AlreadyBound& _s )
{
  return *this;
}
#endif

class _Marshaller_CosNaming_NamingContext_AlreadyBound : public ::CORBA::StaticTypeInfo {
    typedef ::CosNaming::NamingContext::AlreadyBound _MICO_T;
  public:
    ~_Marshaller_CosNaming_NamingContext_AlreadyBound();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosNaming_NamingContext_AlreadyBound::~_Marshaller_CosNaming_NamingContext_AlreadyBound()
{
}

::CORBA::StaticValueType _Marshaller_CosNaming_NamingContext_AlreadyBound::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosNaming_NamingContext_AlreadyBound::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosNaming_NamingContext_AlreadyBound::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosNaming_NamingContext_AlreadyBound::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_CosNaming_NamingContext_AlreadyBound::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/CosNaming/NamingContext/AlreadyBound:1.0" );
  ec.except_end();
}

::CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContext_AlreadyBound;

void CosNaming::NamingContext::AlreadyBound::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw AlreadyBound_var( (CosNaming::NamingContext::AlreadyBound*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *CosNaming::NamingContext::AlreadyBound::_repoid() const
{
  return "IDL:omg.org/CosNaming/NamingContext/AlreadyBound:1.0";
}

void CosNaming::NamingContext::AlreadyBound::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_CosNaming_NamingContext_AlreadyBound->marshal( _en, (void*) this );
}

void CosNaming::NamingContext::AlreadyBound::_encode_any( CORBA::Any & ) const
{
  // use --any to make this work!
  assert(0);
}

CORBA::Exception *CosNaming::NamingContext::AlreadyBound::_clone() const
{
  return new AlreadyBound( *this );
}

CosNaming::NamingContext::AlreadyBound *CosNaming::NamingContext::AlreadyBound::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosNaming/NamingContext/AlreadyBound:1.0" ) )
    return (AlreadyBound *) _ex;
  return NULL;
}

const CosNaming::NamingContext::AlreadyBound *CosNaming::NamingContext::AlreadyBound::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosNaming/NamingContext/AlreadyBound:1.0" ) )
    return (AlreadyBound *) _ex;
  return NULL;
}


#ifdef HAVE_EXPLICIT_STRUCT_OPS
CosNaming::NamingContext::NotEmpty::NotEmpty()
{
}

CosNaming::NamingContext::NotEmpty::NotEmpty( const NotEmpty& _s )
{
}

CosNaming::NamingContext::NotEmpty::~NotEmpty()
{
}

CosNaming::NamingContext::NotEmpty&
CosNaming::NamingContext::NotEmpty::operator=( const NotEmpty& _s )
{
  return *this;
}
#endif

class _Marshaller_CosNaming_NamingContext_NotEmpty : public ::CORBA::StaticTypeInfo {
    typedef ::CosNaming::NamingContext::NotEmpty _MICO_T;
  public:
    ~_Marshaller_CosNaming_NamingContext_NotEmpty();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosNaming_NamingContext_NotEmpty::~_Marshaller_CosNaming_NamingContext_NotEmpty()
{
}

::CORBA::StaticValueType _Marshaller_CosNaming_NamingContext_NotEmpty::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosNaming_NamingContext_NotEmpty::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosNaming_NamingContext_NotEmpty::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosNaming_NamingContext_NotEmpty::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_CosNaming_NamingContext_NotEmpty::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/CosNaming/NamingContext/NotEmpty:1.0" );
  ec.except_end();
}

::CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContext_NotEmpty;

void CosNaming::NamingContext::NotEmpty::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw NotEmpty_var( (CosNaming::NamingContext::NotEmpty*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *CosNaming::NamingContext::NotEmpty::_repoid() const
{
  return "IDL:omg.org/CosNaming/NamingContext/NotEmpty:1.0";
}

void CosNaming::NamingContext::NotEmpty::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_CosNaming_NamingContext_NotEmpty->marshal( _en, (void*) this );
}

void CosNaming::NamingContext::NotEmpty::_encode_any( CORBA::Any & ) const
{
  // use --any to make this work!
  assert(0);
}

CORBA::Exception *CosNaming::NamingContext::NotEmpty::_clone() const
{
  return new NotEmpty( *this );
}

CosNaming::NamingContext::NotEmpty *CosNaming::NamingContext::NotEmpty::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosNaming/NamingContext/NotEmpty:1.0" ) )
    return (NotEmpty *) _ex;
  return NULL;
}

const CosNaming::NamingContext::NotEmpty *CosNaming::NamingContext::NotEmpty::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosNaming/NamingContext/NotEmpty:1.0" ) )
    return (NotEmpty *) _ex;
  return NULL;
}


/*
 * Base interface for class NamingContext
 */

CosNaming::NamingContext::~NamingContext()
{
}

void *
CosNaming::NamingContext::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosNaming/NamingContext:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

CosNaming::NamingContext_ptr
CosNaming::NamingContext::_narrow( CORBA::Object_ptr _obj )
{
  CosNaming::NamingContext_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosNaming/NamingContext:1.0" )))
      return _duplicate( (CosNaming::NamingContext_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosNaming/NamingContext:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosNaming/NamingContext:1.0")) {
      _o = new CosNaming::NamingContext_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosNaming::NamingContext_ptr
CosNaming::NamingContext::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosNaming_NamingContext : public ::CORBA::StaticTypeInfo {
    typedef CosNaming::NamingContext_ptr _MICO_T;
  public:
    ~_Marshaller_CosNaming_NamingContext();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosNaming_NamingContext::~_Marshaller_CosNaming_NamingContext()
{
}

::CORBA::StaticValueType _Marshaller_CosNaming_NamingContext::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosNaming_NamingContext::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosNaming::NamingContext::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosNaming_NamingContext::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosNaming_NamingContext::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosNaming_NamingContext::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosNaming::NamingContext::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosNaming_NamingContext::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContext;


/*
 * Stub interface for class NamingContext
 */

CosNaming::NamingContext_stub::~NamingContext_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosNaming::NamingContext::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosNaming/NamingContext:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_CosNaming::NamingContext *
POA_CosNaming::NamingContext::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosNaming/NamingContext:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosNaming::NamingContext *) p;
  }
  return NULL;
}

CosNaming::NamingContext_stub_clp::NamingContext_stub_clp ()
{
}

CosNaming::NamingContext_stub_clp::NamingContext_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosNaming::NamingContext_stub_clp::~NamingContext_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

void CosNaming::NamingContext_stub::bind( const CosNaming::Name& _par_n, CORBA::Object_ptr _par_obj )
{
  CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );
  CORBA::StaticAny _sa_obj( CORBA::_stc_Object, &_par_obj );
  CORBA::StaticRequest __req( this, "bind" );
  __req.add_in_arg( &_sa_n );
  __req.add_in_arg( &_sa_obj );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosNaming_NamingContext_NotFound, "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0",
    _marshaller_CosNaming_NamingContext_CannotProceed, "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0",
    _marshaller_CosNaming_NamingContext_InvalidName, "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0",
    _marshaller_CosNaming_NamingContext_AlreadyBound, "IDL:omg.org/CosNaming/NamingContext/AlreadyBound:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosNaming::NamingContext_stub_clp::bind( const CosNaming::Name& _par_n, CORBA::Object_ptr _par_obj )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::NamingContext * _myserv = POA_CosNaming::NamingContext::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->bind(_par_n, _par_obj);
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

  CosNaming::NamingContext_stub::bind(_par_n, _par_obj);
}

#endif // MICO_CONF_NO_POA

void CosNaming::NamingContext_stub::rebind( const CosNaming::Name& _par_n, CORBA::Object_ptr _par_obj )
{
  CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );
  CORBA::StaticAny _sa_obj( CORBA::_stc_Object, &_par_obj );
  CORBA::StaticRequest __req( this, "rebind" );
  __req.add_in_arg( &_sa_n );
  __req.add_in_arg( &_sa_obj );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosNaming_NamingContext_NotFound, "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0",
    _marshaller_CosNaming_NamingContext_CannotProceed, "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0",
    _marshaller_CosNaming_NamingContext_InvalidName, "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosNaming::NamingContext_stub_clp::rebind( const CosNaming::Name& _par_n, CORBA::Object_ptr _par_obj )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::NamingContext * _myserv = POA_CosNaming::NamingContext::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->rebind(_par_n, _par_obj);
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

  CosNaming::NamingContext_stub::rebind(_par_n, _par_obj);
}

#endif // MICO_CONF_NO_POA

void CosNaming::NamingContext_stub::bind_context( const CosNaming::Name& _par_n, CosNaming::NamingContext_ptr _par_nc )
{
  CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );
  CORBA::StaticAny _sa_nc( _marshaller_CosNaming_NamingContext, &_par_nc );
  CORBA::StaticRequest __req( this, "bind_context" );
  __req.add_in_arg( &_sa_n );
  __req.add_in_arg( &_sa_nc );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosNaming_NamingContext_NotFound, "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0",
    _marshaller_CosNaming_NamingContext_CannotProceed, "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0",
    _marshaller_CosNaming_NamingContext_InvalidName, "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0",
    _marshaller_CosNaming_NamingContext_AlreadyBound, "IDL:omg.org/CosNaming/NamingContext/AlreadyBound:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosNaming::NamingContext_stub_clp::bind_context( const CosNaming::Name& _par_n, CosNaming::NamingContext_ptr _par_nc )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::NamingContext * _myserv = POA_CosNaming::NamingContext::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->bind_context(_par_n, _par_nc);
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

  CosNaming::NamingContext_stub::bind_context(_par_n, _par_nc);
}

#endif // MICO_CONF_NO_POA

void CosNaming::NamingContext_stub::rebind_context( const CosNaming::Name& _par_n, CosNaming::NamingContext_ptr _par_nc )
{
  CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );
  CORBA::StaticAny _sa_nc( _marshaller_CosNaming_NamingContext, &_par_nc );
  CORBA::StaticRequest __req( this, "rebind_context" );
  __req.add_in_arg( &_sa_n );
  __req.add_in_arg( &_sa_nc );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosNaming_NamingContext_NotFound, "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0",
    _marshaller_CosNaming_NamingContext_CannotProceed, "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0",
    _marshaller_CosNaming_NamingContext_InvalidName, "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosNaming::NamingContext_stub_clp::rebind_context( const CosNaming::Name& _par_n, CosNaming::NamingContext_ptr _par_nc )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::NamingContext * _myserv = POA_CosNaming::NamingContext::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->rebind_context(_par_n, _par_nc);
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

  CosNaming::NamingContext_stub::rebind_context(_par_n, _par_nc);
}

#endif // MICO_CONF_NO_POA

CORBA::Object_ptr CosNaming::NamingContext_stub::resolve( const CosNaming::Name& _par_n )
{
  CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );
  CORBA::Object_ptr _res = CORBA::Object::_nil();
  CORBA::StaticAny __res( CORBA::_stc_Object, &_res );

  CORBA::StaticRequest __req( this, "resolve" );
  __req.add_in_arg( &_sa_n );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosNaming_NamingContext_NotFound, "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0",
    _marshaller_CosNaming_NamingContext_CannotProceed, "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0",
    _marshaller_CosNaming_NamingContext_InvalidName, "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0",
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Object_ptr
CosNaming::NamingContext_stub_clp::resolve( const CosNaming::Name& _par_n )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::NamingContext * _myserv = POA_CosNaming::NamingContext::_narrow (_serv);
    if (_myserv) {
      CORBA::Object_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->resolve(_par_n);
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

  return CosNaming::NamingContext_stub::resolve(_par_n);
}

#endif // MICO_CONF_NO_POA

void CosNaming::NamingContext_stub::unbind( const CosNaming::Name& _par_n )
{
  CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );
  CORBA::StaticRequest __req( this, "unbind" );
  __req.add_in_arg( &_sa_n );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosNaming_NamingContext_NotFound, "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0",
    _marshaller_CosNaming_NamingContext_CannotProceed, "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0",
    _marshaller_CosNaming_NamingContext_InvalidName, "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosNaming::NamingContext_stub_clp::unbind( const CosNaming::Name& _par_n )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::NamingContext * _myserv = POA_CosNaming::NamingContext::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->unbind(_par_n);
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

  CosNaming::NamingContext_stub::unbind(_par_n);
}

#endif // MICO_CONF_NO_POA

CosNaming::NamingContext_ptr CosNaming::NamingContext_stub::new_context()
{
  CosNaming::NamingContext_ptr _res = CosNaming::NamingContext::_nil();
  CORBA::StaticAny __res( _marshaller_CosNaming_NamingContext, &_res );

  CORBA::StaticRequest __req( this, "new_context" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosNaming::NamingContext_ptr
CosNaming::NamingContext_stub_clp::new_context()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::NamingContext * _myserv = POA_CosNaming::NamingContext::_narrow (_serv);
    if (_myserv) {
      CosNaming::NamingContext_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->new_context();
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

  return CosNaming::NamingContext_stub::new_context();
}

#endif // MICO_CONF_NO_POA

CosNaming::NamingContext_ptr CosNaming::NamingContext_stub::bind_new_context( const CosNaming::Name& _par_n )
{
  CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );
  CosNaming::NamingContext_ptr _res = CosNaming::NamingContext::_nil();
  CORBA::StaticAny __res( _marshaller_CosNaming_NamingContext, &_res );

  CORBA::StaticRequest __req( this, "bind_new_context" );
  __req.add_in_arg( &_sa_n );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosNaming_NamingContext_NotFound, "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0",
    _marshaller_CosNaming_NamingContext_AlreadyBound, "IDL:omg.org/CosNaming/NamingContext/AlreadyBound:1.0",
    _marshaller_CosNaming_NamingContext_CannotProceed, "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0",
    _marshaller_CosNaming_NamingContext_InvalidName, "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0",
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CosNaming::NamingContext_ptr
CosNaming::NamingContext_stub_clp::bind_new_context( const CosNaming::Name& _par_n )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::NamingContext * _myserv = POA_CosNaming::NamingContext::_narrow (_serv);
    if (_myserv) {
      CosNaming::NamingContext_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->bind_new_context(_par_n);
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

  return CosNaming::NamingContext_stub::bind_new_context(_par_n);
}

#endif // MICO_CONF_NO_POA

void CosNaming::NamingContext_stub::destroy()
{
  CORBA::StaticRequest __req( this, "destroy" );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosNaming_NamingContext_NotEmpty, "IDL:omg.org/CosNaming/NamingContext/NotEmpty:1.0",
    0);
}


#ifndef MICO_CONF_NO_POA

void
CosNaming::NamingContext_stub_clp::destroy()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::NamingContext * _myserv = POA_CosNaming::NamingContext::_narrow (_serv);
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

  CosNaming::NamingContext_stub::destroy();
}

#endif // MICO_CONF_NO_POA

void CosNaming::NamingContext_stub::list( CORBA::ULong _par_how_many, CosNaming::BindingList_out _par_bl, CosNaming::BindingIterator_out _par_bi )
{
  CORBA::StaticAny _sa_how_many( CORBA::_stc_ulong, &_par_how_many );
  CORBA::StaticAny _sa_bl( _marshaller__seq_CosNaming_Binding );
  CORBA::StaticAny _sa_bi( _marshaller_CosNaming_BindingIterator, &_par_bi.ptr() );
  CORBA::StaticRequest __req( this, "list" );
  __req.add_in_arg( &_sa_how_many );
  __req.add_out_arg( &_sa_bl );
  __req.add_out_arg( &_sa_bi );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  _par_bl = (CosNaming::BindingList*) _sa_bl._retn();
}


#ifndef MICO_CONF_NO_POA

void
CosNaming::NamingContext_stub_clp::list( CORBA::ULong _par_how_many, CosNaming::BindingList_out _par_bl, CosNaming::BindingIterator_out _par_bi )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::NamingContext * _myserv = POA_CosNaming::NamingContext::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->list(_par_how_many, _par_bl, _par_bi);
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

  CosNaming::NamingContext_stub::list(_par_how_many, _par_bl, _par_bi);
}

#endif // MICO_CONF_NO_POA





#ifdef HAVE_EXPLICIT_STRUCT_OPS
CosNaming::NamingContextExt::InvalidAddress::InvalidAddress()
{
}

CosNaming::NamingContextExt::InvalidAddress::InvalidAddress( const InvalidAddress& _s )
{
}

CosNaming::NamingContextExt::InvalidAddress::~InvalidAddress()
{
}

CosNaming::NamingContextExt::InvalidAddress&
CosNaming::NamingContextExt::InvalidAddress::operator=( const InvalidAddress& _s )
{
  return *this;
}
#endif

class _Marshaller_CosNaming_NamingContextExt_InvalidAddress : public ::CORBA::StaticTypeInfo {
    typedef ::CosNaming::NamingContextExt::InvalidAddress _MICO_T;
  public:
    ~_Marshaller_CosNaming_NamingContextExt_InvalidAddress();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosNaming_NamingContextExt_InvalidAddress::~_Marshaller_CosNaming_NamingContextExt_InvalidAddress()
{
}

::CORBA::StaticValueType _Marshaller_CosNaming_NamingContextExt_InvalidAddress::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_CosNaming_NamingContextExt_InvalidAddress::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_CosNaming_NamingContextExt_InvalidAddress::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_CosNaming_NamingContextExt_InvalidAddress::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_CosNaming_NamingContextExt_InvalidAddress::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:omg.org/CosNaming/NamingContextExt/InvalidAddress:1.0" );
  ec.except_end();
}

::CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContextExt_InvalidAddress;

void CosNaming::NamingContextExt::InvalidAddress::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw InvalidAddress_var( (CosNaming::NamingContextExt::InvalidAddress*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *CosNaming::NamingContextExt::InvalidAddress::_repoid() const
{
  return "IDL:omg.org/CosNaming/NamingContextExt/InvalidAddress:1.0";
}

void CosNaming::NamingContextExt::InvalidAddress::_encode( CORBA::DataEncoder &_en ) const
{
  _marshaller_CosNaming_NamingContextExt_InvalidAddress->marshal( _en, (void*) this );
}

void CosNaming::NamingContextExt::InvalidAddress::_encode_any( CORBA::Any & ) const
{
  // use --any to make this work!
  assert(0);
}

CORBA::Exception *CosNaming::NamingContextExt::InvalidAddress::_clone() const
{
  return new InvalidAddress( *this );
}

CosNaming::NamingContextExt::InvalidAddress *CosNaming::NamingContextExt::InvalidAddress::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosNaming/NamingContextExt/InvalidAddress:1.0" ) )
    return (InvalidAddress *) _ex;
  return NULL;
}

const CosNaming::NamingContextExt::InvalidAddress *CosNaming::NamingContextExt::InvalidAddress::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:omg.org/CosNaming/NamingContextExt/InvalidAddress:1.0" ) )
    return (InvalidAddress *) _ex;
  return NULL;
}


/*
 * Base interface for class NamingContextExt
 */

CosNaming::NamingContextExt::~NamingContextExt()
{
}

void *
CosNaming::NamingContextExt::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:omg.org/CosNaming/NamingContextExt:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = CosNaming::NamingContext::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

CosNaming::NamingContextExt_ptr
CosNaming::NamingContextExt::_narrow( CORBA::Object_ptr _obj )
{
  CosNaming::NamingContextExt_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:omg.org/CosNaming/NamingContextExt:1.0" )))
      return _duplicate( (CosNaming::NamingContextExt_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:omg.org/CosNaming/NamingContextExt:1.0") || _obj->_is_a_remote ("IDL:omg.org/CosNaming/NamingContextExt:1.0")) {
      _o = new CosNaming::NamingContextExt_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

CosNaming::NamingContextExt_ptr
CosNaming::NamingContextExt::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_CosNaming_NamingContextExt : public ::CORBA::StaticTypeInfo {
    typedef CosNaming::NamingContextExt_ptr _MICO_T;
  public:
    ~_Marshaller_CosNaming_NamingContextExt();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_CosNaming_NamingContextExt::~_Marshaller_CosNaming_NamingContextExt()
{
}

::CORBA::StaticValueType _Marshaller_CosNaming_NamingContextExt::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_CosNaming_NamingContextExt::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::CosNaming::NamingContextExt::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_CosNaming_NamingContextExt::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_CosNaming_NamingContextExt::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_CosNaming_NamingContextExt::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::CosNaming::NamingContextExt::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_CosNaming_NamingContextExt::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContextExt;


/*
 * Stub interface for class NamingContextExt
 */

CosNaming::NamingContextExt_stub::~NamingContextExt_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_CosNaming::NamingContextExt::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:omg.org/CosNaming/NamingContextExt:1.0") == 0) {
    return (void *) this;
  }
  if ((p = POA_CosNaming::NamingContext::_narrow_helper (repoid)) != NULL) 
  {
    return p;
  }
  return NULL;
}

POA_CosNaming::NamingContextExt *
POA_CosNaming::NamingContextExt::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:omg.org/CosNaming/NamingContextExt:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_CosNaming::NamingContextExt *) p;
  }
  return NULL;
}

CosNaming::NamingContextExt_stub_clp::NamingContextExt_stub_clp ()
{
}

CosNaming::NamingContextExt_stub_clp::NamingContextExt_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

CosNaming::NamingContextExt_stub_clp::~NamingContextExt_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

char* CosNaming::NamingContextExt_stub::to_string( const CosNaming::Name& _par_n )
{
  CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );
  CosNaming::NamingContextExt::StringName _res = NULL;
  CORBA::StaticAny __res( CORBA::_stc_string, &_res );

  CORBA::StaticRequest __req( this, "to_string" );
  __req.add_in_arg( &_sa_n );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosNaming_NamingContext_InvalidName, "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0",
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

char*
CosNaming::NamingContextExt_stub_clp::to_string( const CosNaming::Name& _par_n )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::NamingContextExt * _myserv = POA_CosNaming::NamingContextExt::_narrow (_serv);
    if (_myserv) {
      CosNaming::NamingContextExt::StringName __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->to_string(_par_n);
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

  return CosNaming::NamingContextExt_stub::to_string(_par_n);
}

#endif // MICO_CONF_NO_POA

CosNaming::Name* CosNaming::NamingContextExt_stub::to_name( const char* _par_sn )
{
  CORBA::StaticAny _sa_sn( CORBA::_stc_string, &_par_sn );
  CORBA::StaticAny __res( _marshaller__seq_CosNaming_NameComponent );

  CORBA::StaticRequest __req( this, "to_name" );
  __req.add_in_arg( &_sa_sn );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosNaming_NamingContext_InvalidName, "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0",
    0);
  return (CosNaming::Name*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

CosNaming::Name*
CosNaming::NamingContextExt_stub_clp::to_name( const char* _par_sn )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::NamingContextExt * _myserv = POA_CosNaming::NamingContextExt::_narrow (_serv);
    if (_myserv) {
      CosNaming::Name* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->to_name(_par_sn);
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

  return CosNaming::NamingContextExt_stub::to_name(_par_sn);
}

#endif // MICO_CONF_NO_POA

char* CosNaming::NamingContextExt_stub::to_url( const char* _par_addr, const char* _par_sn )
{
  CORBA::StaticAny _sa_addr( CORBA::_stc_string, &_par_addr );
  CORBA::StaticAny _sa_sn( CORBA::_stc_string, &_par_sn );
  CosNaming::NamingContextExt::URLString _res = NULL;
  CORBA::StaticAny __res( CORBA::_stc_string, &_res );

  CORBA::StaticRequest __req( this, "to_url" );
  __req.add_in_arg( &_sa_addr );
  __req.add_in_arg( &_sa_sn );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosNaming_NamingContextExt_InvalidAddress, "IDL:omg.org/CosNaming/NamingContextExt/InvalidAddress:1.0",
    _marshaller_CosNaming_NamingContext_InvalidName, "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0",
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

char*
CosNaming::NamingContextExt_stub_clp::to_url( const char* _par_addr, const char* _par_sn )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::NamingContextExt * _myserv = POA_CosNaming::NamingContextExt::_narrow (_serv);
    if (_myserv) {
      CosNaming::NamingContextExt::URLString __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->to_url(_par_addr, _par_sn);
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

  return CosNaming::NamingContextExt_stub::to_url(_par_addr, _par_sn);
}

#endif // MICO_CONF_NO_POA

CORBA::Object_ptr CosNaming::NamingContextExt_stub::resolve_str( const char* _par_n )
{
  CORBA::StaticAny _sa_n( CORBA::_stc_string, &_par_n );
  CORBA::Object_ptr _res = CORBA::Object::_nil();
  CORBA::StaticAny __res( CORBA::_stc_Object, &_res );

  CORBA::StaticRequest __req( this, "resolve_str" );
  __req.add_in_arg( &_sa_n );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    _marshaller_CosNaming_NamingContext_NotFound, "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0",
    _marshaller_CosNaming_NamingContext_CannotProceed, "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0",
    _marshaller_CosNaming_NamingContext_InvalidName, "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0",
    _marshaller_CosNaming_NamingContext_AlreadyBound, "IDL:omg.org/CosNaming/NamingContext/AlreadyBound:1.0",
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Object_ptr
CosNaming::NamingContextExt_stub_clp::resolve_str( const char* _par_n )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_CosNaming::NamingContextExt * _myserv = POA_CosNaming::NamingContextExt::_narrow (_serv);
    if (_myserv) {
      CORBA::Object_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->resolve_str(_par_n);
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

  return CosNaming::NamingContextExt_stub::resolve_str(_par_n);
}

#endif // MICO_CONF_NO_POA

class _Marshaller__seq_CosNaming_NameComponent : public ::CORBA::StaticTypeInfo {
    typedef SequenceTmpl< CosNaming::NameComponent,MICO_TID_DEF> _MICO_T;
  public:
    ~_Marshaller__seq_CosNaming_NameComponent();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller__seq_CosNaming_NameComponent::~_Marshaller__seq_CosNaming_NameComponent()
{
}

::CORBA::StaticValueType _Marshaller__seq_CosNaming_NameComponent::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_CosNaming_NameComponent::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_CosNaming_NameComponent::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_CosNaming_NameComponent::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_CosNaming_NameComponent->demarshal( dc, &(*(_MICO_T*)v)[i] ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_CosNaming_NameComponent::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_CosNaming_NameComponent->marshal( ec, &(*(_MICO_T*)v)[i] );
  ec.seq_end();
}

::CORBA::StaticTypeInfo *_marshaller__seq_CosNaming_NameComponent;

class _Marshaller__seq_CosNaming_Binding : public ::CORBA::StaticTypeInfo {
    typedef SequenceTmpl< CosNaming::Binding,MICO_TID_DEF> _MICO_T;
  public:
    ~_Marshaller__seq_CosNaming_Binding();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller__seq_CosNaming_Binding::~_Marshaller__seq_CosNaming_Binding()
{
}

::CORBA::StaticValueType _Marshaller__seq_CosNaming_Binding::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_CosNaming_Binding::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_CosNaming_Binding::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_CosNaming_Binding::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_CosNaming_Binding->demarshal( dc, &(*(_MICO_T*)v)[i] ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_CosNaming_Binding::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_CosNaming_Binding->marshal( ec, &(*(_MICO_T*)v)[i] );
  ec.seq_end();
}

::CORBA::StaticTypeInfo *_marshaller__seq_CosNaming_Binding;

struct __tc_init_COSNAMING {
  __tc_init_COSNAMING()
  {
    _marshaller_CosNaming_NameComponent = new _Marshaller_CosNaming_NameComponent;
    _marshaller_CosNaming_BindingType = new _Marshaller_CosNaming_BindingType;
    _marshaller_CosNaming_Binding = new _Marshaller_CosNaming_Binding;
    _marshaller_CosNaming_BindingIterator = new _Marshaller_CosNaming_BindingIterator;
    _marshaller_CosNaming_NamingContext_NotFoundReason = new _Marshaller_CosNaming_NamingContext_NotFoundReason;
    _marshaller_CosNaming_NamingContext_NotFound = new _Marshaller_CosNaming_NamingContext_NotFound;
    _marshaller_CosNaming_NamingContext_CannotProceed = new _Marshaller_CosNaming_NamingContext_CannotProceed;
    _marshaller_CosNaming_NamingContext_InvalidName = new _Marshaller_CosNaming_NamingContext_InvalidName;
    _marshaller_CosNaming_NamingContext_AlreadyBound = new _Marshaller_CosNaming_NamingContext_AlreadyBound;
    _marshaller_CosNaming_NamingContext_NotEmpty = new _Marshaller_CosNaming_NamingContext_NotEmpty;
    _marshaller_CosNaming_NamingContext = new _Marshaller_CosNaming_NamingContext;
    _marshaller_CosNaming_NamingContextExt_InvalidAddress = new _Marshaller_CosNaming_NamingContextExt_InvalidAddress;
    _marshaller_CosNaming_NamingContextExt = new _Marshaller_CosNaming_NamingContextExt;
    _marshaller__seq_CosNaming_NameComponent = new _Marshaller__seq_CosNaming_NameComponent;
    _marshaller__seq_CosNaming_Binding = new _Marshaller__seq_CosNaming_Binding;
  }

  ~__tc_init_COSNAMING()
  {
    delete static_cast<_Marshaller_CosNaming_NameComponent*>(_marshaller_CosNaming_NameComponent);
    delete static_cast<_Marshaller_CosNaming_BindingType*>(_marshaller_CosNaming_BindingType);
    delete static_cast<_Marshaller_CosNaming_Binding*>(_marshaller_CosNaming_Binding);
    delete static_cast<_Marshaller_CosNaming_BindingIterator*>(_marshaller_CosNaming_BindingIterator);
    delete static_cast<_Marshaller_CosNaming_NamingContext_NotFoundReason*>(_marshaller_CosNaming_NamingContext_NotFoundReason);
    delete static_cast<_Marshaller_CosNaming_NamingContext_NotFound*>(_marshaller_CosNaming_NamingContext_NotFound);
    delete static_cast<_Marshaller_CosNaming_NamingContext_CannotProceed*>(_marshaller_CosNaming_NamingContext_CannotProceed);
    delete static_cast<_Marshaller_CosNaming_NamingContext_InvalidName*>(_marshaller_CosNaming_NamingContext_InvalidName);
    delete static_cast<_Marshaller_CosNaming_NamingContext_AlreadyBound*>(_marshaller_CosNaming_NamingContext_AlreadyBound);
    delete static_cast<_Marshaller_CosNaming_NamingContext_NotEmpty*>(_marshaller_CosNaming_NamingContext_NotEmpty);
    delete static_cast<_Marshaller_CosNaming_NamingContext*>(_marshaller_CosNaming_NamingContext);
    delete static_cast<_Marshaller_CosNaming_NamingContextExt_InvalidAddress*>(_marshaller_CosNaming_NamingContextExt_InvalidAddress);
    delete static_cast<_Marshaller_CosNaming_NamingContextExt*>(_marshaller_CosNaming_NamingContextExt);
    delete static_cast<_Marshaller__seq_CosNaming_NameComponent*>(_marshaller__seq_CosNaming_NameComponent);
    delete static_cast<_Marshaller__seq_CosNaming_Binding*>(_marshaller__seq_CosNaming_Binding);
  }
};

static __tc_init_COSNAMING __init_COSNAMING;

