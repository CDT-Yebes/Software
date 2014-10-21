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
namespace SL3PM
{
CORBA::TypeCodeConst _tc_NameType;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_NameComponent;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_NamePath;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_NameValue;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_PrincipalName;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
SL3PM::PrincipalName::PrincipalName()
{
}

SL3PM::PrincipalName::PrincipalName( const PrincipalName& _s )
{
  the_type = ((PrincipalName&)_s).the_type;
  the_name = ((PrincipalName&)_s).the_name;
}

SL3PM::PrincipalName::~PrincipalName()
{
}

SL3PM::PrincipalName&
SL3PM::PrincipalName::operator=( const PrincipalName& _s )
{
  the_type = ((PrincipalName&)_s).the_type;
  the_name = ((PrincipalName&)_s).the_name;
  return *this;
}
#endif

class _Marshaller_SL3PM_PrincipalName : public ::CORBA::StaticTypeInfo {
    typedef SL3PM::PrincipalName _MICO_T;
  public:
    ~_Marshaller_SL3PM_PrincipalName();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_PrincipalName::~_Marshaller_SL3PM_PrincipalName()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_PrincipalName::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_SL3PM_PrincipalName::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_PrincipalName::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_PrincipalName::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->the_type._for_demarshal() ) &&
    CORBA::_stcseq_wstring->demarshal( dc, &((_MICO_T*)v)->the_name ) &&
    dc.struct_end();
}

void _Marshaller_SL3PM_PrincipalName::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->the_type.inout() );
  CORBA::_stcseq_wstring->marshal( ec, &((_MICO_T*)v)->the_name );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_PrincipalName::typecode()
{
  return SL3PM::_tc_PrincipalName;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_PrincipalName;

void operator<<=( CORBA::Any &_a, const SL3PM::PrincipalName &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_PrincipalName, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SL3PM::PrincipalName *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SL3PM::PrincipalName &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_PrincipalName, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SL3PM::PrincipalName *&_s )
{
  return _a.to_static_any (_marshaller_SL3PM_PrincipalName, (void *&)_s);
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_PrincipalNameList;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_PrinAttributeType;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_PrinAttributeValue;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_PrinAttribute;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
SL3PM::PrinAttribute::PrinAttribute()
{
}

SL3PM::PrinAttribute::PrinAttribute( const PrinAttribute& _s )
{
  the_type = ((PrinAttribute&)_s).the_type;
  the_value = ((PrinAttribute&)_s).the_value;
}

SL3PM::PrinAttribute::~PrinAttribute()
{
}

SL3PM::PrinAttribute&
SL3PM::PrinAttribute::operator=( const PrinAttribute& _s )
{
  the_type = ((PrinAttribute&)_s).the_type;
  the_value = ((PrinAttribute&)_s).the_value;
  return *this;
}
#endif

class _Marshaller_SL3PM_PrinAttribute : public ::CORBA::StaticTypeInfo {
    typedef SL3PM::PrinAttribute _MICO_T;
  public:
    ~_Marshaller_SL3PM_PrinAttribute();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_PrinAttribute::~_Marshaller_SL3PM_PrinAttribute()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_PrinAttribute::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_SL3PM_PrinAttribute::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_PrinAttribute::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_PrinAttribute::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->the_type._for_demarshal() ) &&
    CORBA::_stc_wstring->demarshal( dc, &((_MICO_T*)v)->the_value._for_demarshal() ) &&
    dc.struct_end();
}

void _Marshaller_SL3PM_PrinAttribute::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->the_type.inout() );
  CORBA::_stc_wstring->marshal( ec, &((_MICO_T*)v)->the_value.inout() );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_PrinAttribute::typecode()
{
  return SL3PM::_tc_PrinAttribute;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_PrinAttribute;

void operator<<=( CORBA::Any &_a, const SL3PM::PrinAttribute &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_PrinAttribute, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SL3PM::PrinAttribute *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SL3PM::PrinAttribute &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_PrinAttribute, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SL3PM::PrinAttribute *&_s )
{
  return _a.to_static_any (_marshaller_SL3PM_PrinAttribute, (void *&)_s);
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_PrinAttributeList;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_ResourceName;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
SL3PM::ResourceName::ResourceName()
{
}

SL3PM::ResourceName::ResourceName( const ResourceName& _s )
{
  components = ((ResourceName&)_s).components;
}

SL3PM::ResourceName::~ResourceName()
{
}

SL3PM::ResourceName&
SL3PM::ResourceName::operator=( const ResourceName& _s )
{
  components = ((ResourceName&)_s).components;
  return *this;
}
#endif

class _Marshaller_SL3PM_ResourceName : public ::CORBA::StaticTypeInfo {
    typedef SL3PM::ResourceName _MICO_T;
  public:
    ~_Marshaller_SL3PM_ResourceName();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_ResourceName::~_Marshaller_SL3PM_ResourceName()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_ResourceName::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_SL3PM_ResourceName::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_ResourceName::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_ResourceName::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    CORBA::_stcseq_string->demarshal( dc, &((_MICO_T*)v)->components ) &&
    dc.struct_end();
}

void _Marshaller_SL3PM_ResourceName::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  CORBA::_stcseq_string->marshal( ec, &((_MICO_T*)v)->components );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_ResourceName::typecode()
{
  return SL3PM::_tc_ResourceName;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_ResourceName;

void operator<<=( CORBA::Any &_a, const SL3PM::ResourceName &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_ResourceName, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SL3PM::ResourceName *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SL3PM::ResourceName &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_ResourceName, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SL3PM::ResourceName *&_s )
{
  return _a.to_static_any (_marshaller_SL3PM_ResourceName, (void *&)_s);
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_ResourceNameList;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_ScopedPrivileges;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
SL3PM::ScopedPrivileges::ScopedPrivileges()
{
}

SL3PM::ScopedPrivileges::ScopedPrivileges( const ScopedPrivileges& _s )
{
  privilege_authority = ((ScopedPrivileges&)_s).privilege_authority;
  privileges = ((ScopedPrivileges&)_s).privileges;
}

SL3PM::ScopedPrivileges::~ScopedPrivileges()
{
}

SL3PM::ScopedPrivileges&
SL3PM::ScopedPrivileges::operator=( const ScopedPrivileges& _s )
{
  privilege_authority = ((ScopedPrivileges&)_s).privilege_authority;
  privileges = ((ScopedPrivileges&)_s).privileges;
  return *this;
}
#endif

class _Marshaller_SL3PM_ScopedPrivileges : public ::CORBA::StaticTypeInfo {
    typedef SL3PM::ScopedPrivileges _MICO_T;
  public:
    ~_Marshaller_SL3PM_ScopedPrivileges();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_ScopedPrivileges::~_Marshaller_SL3PM_ScopedPrivileges()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_ScopedPrivileges::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_SL3PM_ScopedPrivileges::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_ScopedPrivileges::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_ScopedPrivileges::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    _marshaller_SL3PM_PrincipalName->demarshal( dc, &((_MICO_T*)v)->privilege_authority ) &&
    _marshaller__seq_SL3PM_PrinAttribute->demarshal( dc, &((_MICO_T*)v)->privileges ) &&
    dc.struct_end();
}

void _Marshaller_SL3PM_ScopedPrivileges::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  _marshaller_SL3PM_PrincipalName->marshal( ec, &((_MICO_T*)v)->privilege_authority );
  _marshaller__seq_SL3PM_PrinAttribute->marshal( ec, &((_MICO_T*)v)->privileges );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_ScopedPrivileges::typecode()
{
  return SL3PM::_tc_ScopedPrivileges;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_ScopedPrivileges;

void operator<<=( CORBA::Any &_a, const SL3PM::ScopedPrivileges &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_ScopedPrivileges, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SL3PM::ScopedPrivileges *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SL3PM::ScopedPrivileges &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_ScopedPrivileges, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SL3PM::ScopedPrivileges *&_s )
{
  return _a.to_static_any (_marshaller_SL3PM_ScopedPrivileges, (void *&)_s);
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_ScopedPrivilegesList;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_PrincipalType;
}


// valuetype Principal
SL3PM::Principal::Principal ()
{
}

SL3PM::Principal::~Principal ()
{
}

void *
SL3PM::Principal::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:adiron.com/SL3PM/Principal:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

SL3PM::Principal *
SL3PM::Principal::_downcast (CORBA::ValueBase * vb) 
{
  void * p;
  if (vb && ((p = vb->_narrow_helper ("IDL:adiron.com/SL3PM/Principal:1.0")))) {
    return (SL3PM::Principal *) p;
  }
  return 0;
}

SL3PM::Principal *
SL3PM::Principal::_downcast (CORBA::AbstractBase * vb) 
{
  return _downcast (vb->_to_value());
}

CORBA::ValueDef_ptr
SL3PM::Principal::get_value_def () 
{
  CORBA::ORB_var orb = CORBA::ORB_instance ("mico-local-orb");
  CORBA::Object_var irobj = 
    orb->resolve_initial_references ("InterfaceRepository");
  CORBA::Repository_var ifr = CORBA::Repository::_narrow (irobj);
  if (CORBA::is_nil (ifr)) {
    return CORBA::ValueDef::_nil ();
  }

  CORBA::Contained_var cv = ifr->lookup_id ("IDL:adiron.com/SL3PM/Principal:1.0");
  return CORBA::ValueDef::_narrow (cv);
}

void
SL3PM::Principal::_copy_members (const Principal& other)
{
  the_type (other.the_type());
  the_name (other.the_name());
  with_privileges (other.with_privileges());
}

CORBA::ValueBase *
SL3PM::Principal::_copy_value ()
{
  vector<string> _dummy;
  string _repo_id = "IDL:adiron.com/SL3PM/Principal:1.0";
  Principal * _res = _downcast (_create (_dummy, _repo_id));
  assert (_res != 0);
  _res->_copy_members (*this);
  return _res;
}

void
SL3PM::Principal::_get_marshal_info (vector<string> & repoids, CORBA::Boolean & chunked)
{
  repoids.push_back ("IDL:adiron.com/SL3PM/Principal:1.0");
  chunked = FALSE;
}

void
SL3PM::Principal::_marshal_members (CORBA::DataEncoder &ec)
{
  SL3PM::PrincipalType _the_type = the_type ();
  CORBA::_stc_ulong->marshal (ec, &_the_type);
  SL3PM::PrincipalName& _the_name = the_name ();
  _marshaller_SL3PM_PrincipalName->marshal (ec, &_the_name);
  SL3PM::ScopedPrivilegesList& _with_privileges = with_privileges ();
  _marshaller__seq_SL3PM_ScopedPrivileges->marshal (ec, &_with_privileges);
}

CORBA::Boolean
SL3PM::Principal::_demarshal_members (CORBA::DataDecoder &dc)
{
  SL3PM::PrincipalType _the_type;
  if (!CORBA::_stc_ulong->demarshal (dc, &_the_type)) {
      return FALSE;
  }
  the_type (_the_type);
  SL3PM::PrincipalName _the_name;
  if (!_marshaller_SL3PM_PrincipalName->demarshal (dc, &_the_name)) {
      return FALSE;
  }
  the_name (_the_name);
  SL3PM::ScopedPrivilegesList _with_privileges;
  if (!_marshaller__seq_SL3PM_ScopedPrivileges->demarshal (dc, &_with_privileges)) {
      return FALSE;
  }
  with_privileges (_with_privileges);
  return TRUE;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_Principal;
}

class _Marshaller_SL3PM_Principal : public ::CORBA::StaticTypeInfo {
    typedef SL3PM::Principal* _MICO_T;
  public:
    ~_Marshaller_SL3PM_Principal();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_Principal::~_Marshaller_SL3PM_Principal()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_Principal::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_SL3PM_Principal::assign( StaticValueType d, const StaticValueType s ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)d);
  ::CORBA::add_ref (*(_MICO_T*)s);
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_Principal::free( StaticValueType v ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)v);
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_Principal::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ValueBase* vb = NULL;
  if (!::CORBA::ValueBase::_demarshal (dc, vb, "IDL:adiron.com/SL3PM/Principal:1.0")) {
    return FALSE;
  }
  ::CORBA::remove_ref (*(_MICO_T *)v);
  *(_MICO_T *)v = ::SL3PM::Principal::_downcast (vb);
  if (vb && !*(_MICO_T *)v) {
    ::CORBA::remove_ref (vb);
    return FALSE;
  }
  return TRUE;
}

void _Marshaller_SL3PM_Principal::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ValueBase::_marshal (ec, *(_MICO_T *)v);
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_Principal::typecode()
{
  return SL3PM::_tc_Principal;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_Principal;

void
operator<<=( CORBA::Any &_a, const SL3PM::Principal* _val )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_Principal, &_val);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, SL3PM::Principal** _val_ptr )
{
  CORBA::ValueBase_var _val = *_val_ptr;
  CORBA::StaticAny _sa (_marshaller_SL3PM_Principal, _val_ptr);
  _a.from_static_any (_sa);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, SL3PM::Principal* &_val_ptr )
{
  SL3PM::Principal* *p;
  if (_a.to_static_any (_marshaller_SL3PM_Principal, (void *&)p)) {
    _val_ptr = *p;
    return TRUE;
  }
  return FALSE;
}


// OBV class for valuetype Principal
OBV_SL3PM::Principal::Principal ()
{
}

OBV_SL3PM::Principal::Principal (::SL3PM::PrincipalType _the_type, const ::SL3PM::PrincipalName& _the_name, const ::SL3PM::ScopedPrivilegesList& _with_privileges)
{
  this->the_type(_the_type);
  this->the_name(_the_name);
  this->with_privileges(_with_privileges);
}

OBV_SL3PM::Principal::~Principal ()
{
}

void OBV_SL3PM::Principal::the_type( ::SL3PM::PrincipalType _p )
{
  _m.the_type = _p;
}

::SL3PM::PrincipalType OBV_SL3PM::Principal::the_type() const
{
  return (::SL3PM::PrincipalType)_m.the_type;
}

void OBV_SL3PM::Principal::the_name( const ::SL3PM::PrincipalName& _p )
{
  _m.the_name = _p;
}

const ::SL3PM::PrincipalName& OBV_SL3PM::Principal::the_name() const
{
  return (::SL3PM::PrincipalName&) _m.the_name;
}

::SL3PM::PrincipalName& OBV_SL3PM::Principal::the_name()
{
  return _m.the_name;
}

void OBV_SL3PM::Principal::with_privileges( const ::SL3PM::ScopedPrivilegesList& _p )
{
  _m.with_privileges = _p;
}

const ::SL3PM::ScopedPrivilegesList& OBV_SL3PM::Principal::with_privileges() const
{
  return (::SL3PM::ScopedPrivilegesList&) _m.with_privileges;
}

::SL3PM::ScopedPrivilegesList& OBV_SL3PM::Principal::with_privileges()
{
  return _m.with_privileges;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_PrincipalList;
}


// valuetype SimplePrincipal
SL3PM::SimplePrincipal::SimplePrincipal ()
{
}

SL3PM::SimplePrincipal::~SimplePrincipal ()
{
}

void *
SL3PM::SimplePrincipal::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:adiron.com/SL3PM/SimplePrincipal:1.0") == 0) {
    return (void *) this;
  }
  if ((p = SL3PM::Principal::_narrow_helper (repoid)) != NULL) {
    return p;
  }
  return NULL;
}

SL3PM::SimplePrincipal *
SL3PM::SimplePrincipal::_downcast (CORBA::ValueBase * vb) 
{
  void * p;
  if (vb && ((p = vb->_narrow_helper ("IDL:adiron.com/SL3PM/SimplePrincipal:1.0")))) {
    return (SL3PM::SimplePrincipal *) p;
  }
  return 0;
}

SL3PM::SimplePrincipal *
SL3PM::SimplePrincipal::_downcast (CORBA::AbstractBase * vb) 
{
  return _downcast (vb->_to_value());
}

CORBA::ValueDef_ptr
SL3PM::SimplePrincipal::get_value_def () 
{
  CORBA::ORB_var orb = CORBA::ORB_instance ("mico-local-orb");
  CORBA::Object_var irobj = 
    orb->resolve_initial_references ("InterfaceRepository");
  CORBA::Repository_var ifr = CORBA::Repository::_narrow (irobj);
  if (CORBA::is_nil (ifr)) {
    return CORBA::ValueDef::_nil ();
  }

  CORBA::Contained_var cv = ifr->lookup_id ("IDL:adiron.com/SL3PM/SimplePrincipal:1.0");
  return CORBA::ValueDef::_narrow (cv);
}

void
SL3PM::SimplePrincipal::_copy_members (const SimplePrincipal& other)
{
  authenticated (other.authenticated());
  alternate_names (other.alternate_names());
}

CORBA::ValueBase *
SL3PM::SimplePrincipal::_copy_value ()
{
  vector<string> _dummy;
  string _repo_id = "IDL:adiron.com/SL3PM/SimplePrincipal:1.0";
  SimplePrincipal * _res = _downcast (_create (_dummy, _repo_id));
  assert (_res != 0);
  _res->SL3PM::Principal::_copy_members (*this);
  _res->_copy_members (*this);
  return _res;
}

void
SL3PM::SimplePrincipal::_get_marshal_info (vector<string> & repoids, CORBA::Boolean & chunked)
{
  repoids.push_back ("IDL:adiron.com/SL3PM/SimplePrincipal:1.0");
  SL3PM::Principal::_get_marshal_info (repoids, chunked);
  chunked = TRUE;
}

void
SL3PM::SimplePrincipal::_marshal_members (CORBA::DataEncoder &ec)
{
  SL3PM::Principal::_marshal_members (ec);
  CORBA::Boolean _authenticated = authenticated ();
  CORBA::_stc_boolean->marshal (ec, &_authenticated);
  SL3PM::PrincipalNameList& _alternate_names = alternate_names ();
  _marshaller__seq_SL3PM_PrincipalName->marshal (ec, &_alternate_names);
}

CORBA::Boolean
SL3PM::SimplePrincipal::_demarshal_members (CORBA::DataDecoder &dc)
{
  if (!SL3PM::Principal::_demarshal_members (dc)) {
      return FALSE;
  }
  CORBA::Boolean _authenticated;
  if (!CORBA::_stc_boolean->demarshal (dc, &_authenticated)) {
      return FALSE;
  }
  authenticated (_authenticated);
  SL3PM::PrincipalNameList _alternate_names;
  if (!_marshaller__seq_SL3PM_PrincipalName->demarshal (dc, &_alternate_names)) {
      return FALSE;
  }
  alternate_names (_alternate_names);
  return TRUE;
}

SL3PM::SimplePrincipal_init::SimplePrincipal_init ()
{
}

SL3PM::SimplePrincipal_init::~SimplePrincipal_init ()
{
}

void *
SL3PM::SimplePrincipal_init::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:adiron.com/SL3PM/SimplePrincipal:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

SL3PM::SimplePrincipal_init *
SL3PM::SimplePrincipal_init::_downcast (CORBA::ValueFactory vf) 
{
  void * p;
  if (vf && ((p = vf->_narrow_helper ("IDL:adiron.com/SL3PM/SimplePrincipal:1.0")))) {
    return (SL3PM::SimplePrincipal_init *) p;
  }
  return 0;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_SimplePrincipal;
}

class _Marshaller_SL3PM_SimplePrincipal : public ::CORBA::StaticTypeInfo {
    typedef SL3PM::SimplePrincipal* _MICO_T;
  public:
    ~_Marshaller_SL3PM_SimplePrincipal();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_SimplePrincipal::~_Marshaller_SL3PM_SimplePrincipal()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_SimplePrincipal::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_SL3PM_SimplePrincipal::assign( StaticValueType d, const StaticValueType s ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)d);
  ::CORBA::add_ref (*(_MICO_T*)s);
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_SimplePrincipal::free( StaticValueType v ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)v);
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_SimplePrincipal::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ValueBase* vb = NULL;
  if (!::CORBA::ValueBase::_demarshal (dc, vb, "IDL:adiron.com/SL3PM/SimplePrincipal:1.0")) {
    return FALSE;
  }
  ::CORBA::remove_ref (*(_MICO_T *)v);
  *(_MICO_T *)v = ::SL3PM::SimplePrincipal::_downcast (vb);
  if (vb && !*(_MICO_T *)v) {
    ::CORBA::remove_ref (vb);
    return FALSE;
  }
  return TRUE;
}

void _Marshaller_SL3PM_SimplePrincipal::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ValueBase::_marshal (ec, *(_MICO_T *)v);
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_SimplePrincipal::typecode()
{
  return SL3PM::_tc_SimplePrincipal;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_SimplePrincipal;

void
operator<<=( CORBA::Any &_a, const SL3PM::SimplePrincipal* _val )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_SimplePrincipal, &_val);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, SL3PM::SimplePrincipal** _val_ptr )
{
  CORBA::ValueBase_var _val = *_val_ptr;
  CORBA::StaticAny _sa (_marshaller_SL3PM_SimplePrincipal, _val_ptr);
  _a.from_static_any (_sa);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, SL3PM::SimplePrincipal* &_val_ptr )
{
  SL3PM::SimplePrincipal* *p;
  if (_a.to_static_any (_marshaller_SL3PM_SimplePrincipal, (void *&)p)) {
    _val_ptr = *p;
    return TRUE;
  }
  return FALSE;
}


// OBV class for valuetype SimplePrincipal
OBV_SL3PM::SimplePrincipal::SimplePrincipal ()
{
}

OBV_SL3PM::SimplePrincipal::SimplePrincipal (::SL3PM::PrincipalType _the_type, const ::SL3PM::PrincipalName& _the_name, const ::SL3PM::ScopedPrivilegesList& _with_privileges, CORBA::Boolean _authenticated, const ::SL3PM::PrincipalNameList& _alternate_names)
{
  this->the_type(_the_type);
  this->the_name(_the_name);
  this->with_privileges(_with_privileges);
  this->authenticated(_authenticated);
  this->alternate_names(_alternate_names);
}

OBV_SL3PM::SimplePrincipal::~SimplePrincipal ()
{
}

void OBV_SL3PM::SimplePrincipal::authenticated( CORBA::Boolean _p )
{
  _m.authenticated = _p;
}

CORBA::Boolean OBV_SL3PM::SimplePrincipal::authenticated() const
{
  return (CORBA::Boolean)_m.authenticated;
}

void OBV_SL3PM::SimplePrincipal::alternate_names( const ::SL3PM::PrincipalNameList& _p )
{
  _m.alternate_names = _p;
}

const ::SL3PM::PrincipalNameList& OBV_SL3PM::SimplePrincipal::alternate_names() const
{
  return (::SL3PM::PrincipalNameList&) _m.alternate_names;
}

::SL3PM::PrincipalNameList& OBV_SL3PM::SimplePrincipal::alternate_names()
{
  return _m.alternate_names;
}


// valuetype ProxyPrincipal
SL3PM::ProxyPrincipal::ProxyPrincipal ()
{
}

SL3PM::ProxyPrincipal::~ProxyPrincipal ()
{
}

void *
SL3PM::ProxyPrincipal::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:adiron.com/SL3PM/ProxyPrincipal:1.0") == 0) {
    return (void *) this;
  }
  if ((p = SL3PM::Principal::_narrow_helper (repoid)) != NULL) {
    return p;
  }
  return NULL;
}

SL3PM::ProxyPrincipal *
SL3PM::ProxyPrincipal::_downcast (CORBA::ValueBase * vb) 
{
  void * p;
  if (vb && ((p = vb->_narrow_helper ("IDL:adiron.com/SL3PM/ProxyPrincipal:1.0")))) {
    return (SL3PM::ProxyPrincipal *) p;
  }
  return 0;
}

SL3PM::ProxyPrincipal *
SL3PM::ProxyPrincipal::_downcast (CORBA::AbstractBase * vb) 
{
  return _downcast (vb->_to_value());
}

CORBA::ValueDef_ptr
SL3PM::ProxyPrincipal::get_value_def () 
{
  CORBA::ORB_var orb = CORBA::ORB_instance ("mico-local-orb");
  CORBA::Object_var irobj = 
    orb->resolve_initial_references ("InterfaceRepository");
  CORBA::Repository_var ifr = CORBA::Repository::_narrow (irobj);
  if (CORBA::is_nil (ifr)) {
    return CORBA::ValueDef::_nil ();
  }

  CORBA::Contained_var cv = ifr->lookup_id ("IDL:adiron.com/SL3PM/ProxyPrincipal:1.0");
  return CORBA::ValueDef::_narrow (cv);
}

CORBA::ValueBase *
SL3PM::ProxyPrincipal::_copy_value ()
{
  return CORBA::ValueBase::_copy_value();
}

void
SL3PM::ProxyPrincipal::_get_marshal_info (vector<string> & repoids, CORBA::Boolean & chunked)
{
  repoids.push_back ("IDL:adiron.com/SL3PM/ProxyPrincipal:1.0");
  SL3PM::Principal::_get_marshal_info (repoids, chunked);
  chunked = TRUE;
}

void
SL3PM::ProxyPrincipal::_marshal_members (CORBA::DataEncoder &ec)
{
  SL3PM::Principal::_marshal_members (ec);
  SL3PM::Principal* _speaking = speaking ();
  _marshaller_SL3PM_Principal->marshal (ec, &_speaking);
  SL3PM::Principal* _speaks_for = speaks_for ();
  _marshaller_SL3PM_Principal->marshal (ec, &_speaks_for);
}

CORBA::Boolean
SL3PM::ProxyPrincipal::_demarshal_members (CORBA::DataDecoder &dc)
{
  if (!SL3PM::Principal::_demarshal_members (dc)) {
      return FALSE;
  }
  SL3PM::Principal_var _speaking;
  if (!_marshaller_SL3PM_Principal->demarshal (dc, &_speaking._for_demarshal())) {
      return FALSE;
  }
  speaking (_speaking);
  SL3PM::Principal_var _speaks_for;
  if (!_marshaller_SL3PM_Principal->demarshal (dc, &_speaks_for._for_demarshal())) {
      return FALSE;
  }
  speaks_for (_speaks_for);
  return TRUE;
}

CORBA::Long
SL3PM::ProxyPrincipal::_count_refs (CORBA::ValueBase::visited * _seen)
{
  if (_seen) {
    if (_seen->find (this) != _seen->end()) {
      return -1;
    }
  }

  CORBA::Boolean own = FALSE;
  CORBA::Long res = _refcount_value() - 1;

  if (_seen == 0) {
    _seen = new CORBA::ValueBase::visited;
    own = TRUE;
  }
  _seen->insert (this);

  if (speaking()) {
    res += speaking()->_count_refs (_seen);
  }
  if (speaks_for()) {
    res += speaks_for()->_count_refs (_seen);
  }

  if (own) {
    delete _seen;
  }

  return res;
}

void
SL3PM::ProxyPrincipal::_release_members ()
{
  if (_destructing) {
    return;
  }
  _destructing = true;
  if (speaking()) {
    speaking()->_release_members ();
  }
  speaking (0);
  if (speaks_for()) {
    speaks_for()->_release_members ();
  }
  speaks_for (0);
}

SL3PM::ProxyPrincipal_init::ProxyPrincipal_init ()
{
}

SL3PM::ProxyPrincipal_init::~ProxyPrincipal_init ()
{
}

void *
SL3PM::ProxyPrincipal_init::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:adiron.com/SL3PM/ProxyPrincipal:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

SL3PM::ProxyPrincipal_init *
SL3PM::ProxyPrincipal_init::_downcast (CORBA::ValueFactory vf) 
{
  void * p;
  if (vf && ((p = vf->_narrow_helper ("IDL:adiron.com/SL3PM/ProxyPrincipal:1.0")))) {
    return (SL3PM::ProxyPrincipal_init *) p;
  }
  return 0;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_ProxyPrincipal;
}

class _Marshaller_SL3PM_ProxyPrincipal : public ::CORBA::StaticTypeInfo {
    typedef SL3PM::ProxyPrincipal* _MICO_T;
  public:
    ~_Marshaller_SL3PM_ProxyPrincipal();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_ProxyPrincipal::~_Marshaller_SL3PM_ProxyPrincipal()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_ProxyPrincipal::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_SL3PM_ProxyPrincipal::assign( StaticValueType d, const StaticValueType s ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)d);
  ::CORBA::add_ref (*(_MICO_T*)s);
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_ProxyPrincipal::free( StaticValueType v ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)v);
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_ProxyPrincipal::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ValueBase* vb = NULL;
  if (!::CORBA::ValueBase::_demarshal (dc, vb, "IDL:adiron.com/SL3PM/ProxyPrincipal:1.0")) {
    return FALSE;
  }
  ::CORBA::remove_ref (*(_MICO_T *)v);
  *(_MICO_T *)v = ::SL3PM::ProxyPrincipal::_downcast (vb);
  if (vb && !*(_MICO_T *)v) {
    ::CORBA::remove_ref (vb);
    return FALSE;
  }
  return TRUE;
}

void _Marshaller_SL3PM_ProxyPrincipal::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ValueBase::_marshal (ec, *(_MICO_T *)v);
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_ProxyPrincipal::typecode()
{
  return SL3PM::_tc_ProxyPrincipal;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_ProxyPrincipal;

void
operator<<=( CORBA::Any &_a, const SL3PM::ProxyPrincipal* _val )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_ProxyPrincipal, &_val);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, SL3PM::ProxyPrincipal** _val_ptr )
{
  CORBA::ValueBase_var _val = *_val_ptr;
  CORBA::StaticAny _sa (_marshaller_SL3PM_ProxyPrincipal, _val_ptr);
  _a.from_static_any (_sa);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, SL3PM::ProxyPrincipal* &_val_ptr )
{
  SL3PM::ProxyPrincipal* *p;
  if (_a.to_static_any (_marshaller_SL3PM_ProxyPrincipal, (void *&)p)) {
    _val_ptr = *p;
    return TRUE;
  }
  return FALSE;
}


// OBV class for valuetype ProxyPrincipal
OBV_SL3PM::ProxyPrincipal::ProxyPrincipal ()
{
}

OBV_SL3PM::ProxyPrincipal::ProxyPrincipal (::SL3PM::PrincipalType _the_type, const ::SL3PM::PrincipalName& _the_name, const ::SL3PM::ScopedPrivilegesList& _with_privileges, ::SL3PM::Principal* _speaking, ::SL3PM::Principal* _speaks_for)
{
  this->the_type(_the_type);
  this->the_name(_the_name);
  this->with_privileges(_with_privileges);
  this->speaking(_speaking);
  this->speaks_for(_speaks_for);
}

OBV_SL3PM::ProxyPrincipal::~ProxyPrincipal ()
{
}

void OBV_SL3PM::ProxyPrincipal::speaking( ::SL3PM::Principal* _p )
{
  CORBA::add_ref ( _p );
  _m.speaking = _p;
}

::SL3PM::Principal* OBV_SL3PM::ProxyPrincipal::speaking() const
{
  return _m.speaking.in();
}

void OBV_SL3PM::ProxyPrincipal::speaks_for( ::SL3PM::Principal* _p )
{
  CORBA::add_ref ( _p );
  _m.speaks_for = _p;
}

::SL3PM::Principal* OBV_SL3PM::ProxyPrincipal::speaks_for() const
{
  return _m.speaks_for.in();
}


// valuetype QuotingPrincipal
SL3PM::QuotingPrincipal::QuotingPrincipal ()
{
}

SL3PM::QuotingPrincipal::~QuotingPrincipal ()
{
}

void *
SL3PM::QuotingPrincipal::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:adiron.com/SL3PM/QuotingPrincipal:1.0") == 0) {
    return (void *) this;
  }
  if ((p = SL3PM::Principal::_narrow_helper (repoid)) != NULL) {
    return p;
  }
  return NULL;
}

SL3PM::QuotingPrincipal *
SL3PM::QuotingPrincipal::_downcast (CORBA::ValueBase * vb) 
{
  void * p;
  if (vb && ((p = vb->_narrow_helper ("IDL:adiron.com/SL3PM/QuotingPrincipal:1.0")))) {
    return (SL3PM::QuotingPrincipal *) p;
  }
  return 0;
}

SL3PM::QuotingPrincipal *
SL3PM::QuotingPrincipal::_downcast (CORBA::AbstractBase * vb) 
{
  return _downcast (vb->_to_value());
}

CORBA::ValueDef_ptr
SL3PM::QuotingPrincipal::get_value_def () 
{
  CORBA::ORB_var orb = CORBA::ORB_instance ("mico-local-orb");
  CORBA::Object_var irobj = 
    orb->resolve_initial_references ("InterfaceRepository");
  CORBA::Repository_var ifr = CORBA::Repository::_narrow (irobj);
  if (CORBA::is_nil (ifr)) {
    return CORBA::ValueDef::_nil ();
  }

  CORBA::Contained_var cv = ifr->lookup_id ("IDL:adiron.com/SL3PM/QuotingPrincipal:1.0");
  return CORBA::ValueDef::_narrow (cv);
}

CORBA::ValueBase *
SL3PM::QuotingPrincipal::_copy_value ()
{
  return CORBA::ValueBase::_copy_value();
}

void
SL3PM::QuotingPrincipal::_get_marshal_info (vector<string> & repoids, CORBA::Boolean & chunked)
{
  repoids.push_back ("IDL:adiron.com/SL3PM/QuotingPrincipal:1.0");
  SL3PM::Principal::_get_marshal_info (repoids, chunked);
  chunked = TRUE;
}

void
SL3PM::QuotingPrincipal::_marshal_members (CORBA::DataEncoder &ec)
{
  SL3PM::Principal::_marshal_members (ec);
  SL3PM::Principal* _speaking = speaking ();
  _marshaller_SL3PM_Principal->marshal (ec, &_speaking);
  SL3PM::Principal* _quotes_for = quotes_for ();
  _marshaller_SL3PM_Principal->marshal (ec, &_quotes_for);
}

CORBA::Boolean
SL3PM::QuotingPrincipal::_demarshal_members (CORBA::DataDecoder &dc)
{
  if (!SL3PM::Principal::_demarshal_members (dc)) {
      return FALSE;
  }
  SL3PM::Principal_var _speaking;
  if (!_marshaller_SL3PM_Principal->demarshal (dc, &_speaking._for_demarshal())) {
      return FALSE;
  }
  speaking (_speaking);
  SL3PM::Principal_var _quotes_for;
  if (!_marshaller_SL3PM_Principal->demarshal (dc, &_quotes_for._for_demarshal())) {
      return FALSE;
  }
  quotes_for (_quotes_for);
  return TRUE;
}

CORBA::Long
SL3PM::QuotingPrincipal::_count_refs (CORBA::ValueBase::visited * _seen)
{
  if (_seen) {
    if (_seen->find (this) != _seen->end()) {
      return -1;
    }
  }

  CORBA::Boolean own = FALSE;
  CORBA::Long res = _refcount_value() - 1;

  if (_seen == 0) {
    _seen = new CORBA::ValueBase::visited;
    own = TRUE;
  }
  _seen->insert (this);

  if (speaking()) {
    res += speaking()->_count_refs (_seen);
  }
  if (quotes_for()) {
    res += quotes_for()->_count_refs (_seen);
  }

  if (own) {
    delete _seen;
  }

  return res;
}

void
SL3PM::QuotingPrincipal::_release_members ()
{
  if (_destructing) {
    return;
  }
  _destructing = true;
  if (speaking()) {
    speaking()->_release_members ();
  }
  speaking (0);
  if (quotes_for()) {
    quotes_for()->_release_members ();
  }
  quotes_for (0);
}

SL3PM::QuotingPrincipal_init::QuotingPrincipal_init ()
{
}

SL3PM::QuotingPrincipal_init::~QuotingPrincipal_init ()
{
}

void *
SL3PM::QuotingPrincipal_init::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:adiron.com/SL3PM/QuotingPrincipal:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

SL3PM::QuotingPrincipal_init *
SL3PM::QuotingPrincipal_init::_downcast (CORBA::ValueFactory vf) 
{
  void * p;
  if (vf && ((p = vf->_narrow_helper ("IDL:adiron.com/SL3PM/QuotingPrincipal:1.0")))) {
    return (SL3PM::QuotingPrincipal_init *) p;
  }
  return 0;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_QuotingPrincipal;
}

class _Marshaller_SL3PM_QuotingPrincipal : public ::CORBA::StaticTypeInfo {
    typedef SL3PM::QuotingPrincipal* _MICO_T;
  public:
    ~_Marshaller_SL3PM_QuotingPrincipal();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_QuotingPrincipal::~_Marshaller_SL3PM_QuotingPrincipal()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_QuotingPrincipal::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_SL3PM_QuotingPrincipal::assign( StaticValueType d, const StaticValueType s ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)d);
  ::CORBA::add_ref (*(_MICO_T*)s);
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_QuotingPrincipal::free( StaticValueType v ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)v);
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_QuotingPrincipal::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ValueBase* vb = NULL;
  if (!::CORBA::ValueBase::_demarshal (dc, vb, "IDL:adiron.com/SL3PM/QuotingPrincipal:1.0")) {
    return FALSE;
  }
  ::CORBA::remove_ref (*(_MICO_T *)v);
  *(_MICO_T *)v = ::SL3PM::QuotingPrincipal::_downcast (vb);
  if (vb && !*(_MICO_T *)v) {
    ::CORBA::remove_ref (vb);
    return FALSE;
  }
  return TRUE;
}

void _Marshaller_SL3PM_QuotingPrincipal::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ValueBase::_marshal (ec, *(_MICO_T *)v);
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_QuotingPrincipal::typecode()
{
  return SL3PM::_tc_QuotingPrincipal;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_QuotingPrincipal;

void
operator<<=( CORBA::Any &_a, const SL3PM::QuotingPrincipal* _val )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_QuotingPrincipal, &_val);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, SL3PM::QuotingPrincipal** _val_ptr )
{
  CORBA::ValueBase_var _val = *_val_ptr;
  CORBA::StaticAny _sa (_marshaller_SL3PM_QuotingPrincipal, _val_ptr);
  _a.from_static_any (_sa);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, SL3PM::QuotingPrincipal* &_val_ptr )
{
  SL3PM::QuotingPrincipal* *p;
  if (_a.to_static_any (_marshaller_SL3PM_QuotingPrincipal, (void *&)p)) {
    _val_ptr = *p;
    return TRUE;
  }
  return FALSE;
}


// OBV class for valuetype QuotingPrincipal
OBV_SL3PM::QuotingPrincipal::QuotingPrincipal ()
{
}

OBV_SL3PM::QuotingPrincipal::QuotingPrincipal (::SL3PM::PrincipalType _the_type, const ::SL3PM::PrincipalName& _the_name, const ::SL3PM::ScopedPrivilegesList& _with_privileges, ::SL3PM::Principal* _speaking, ::SL3PM::Principal* _quotes_for)
{
  this->the_type(_the_type);
  this->the_name(_the_name);
  this->with_privileges(_with_privileges);
  this->speaking(_speaking);
  this->quotes_for(_quotes_for);
}

OBV_SL3PM::QuotingPrincipal::~QuotingPrincipal ()
{
}

void OBV_SL3PM::QuotingPrincipal::speaking( ::SL3PM::Principal* _p )
{
  CORBA::add_ref ( _p );
  _m.speaking = _p;
}

::SL3PM::Principal* OBV_SL3PM::QuotingPrincipal::speaking() const
{
  return _m.speaking.in();
}

void OBV_SL3PM::QuotingPrincipal::quotes_for( ::SL3PM::Principal* _p )
{
  CORBA::add_ref ( _p );
  _m.quotes_for = _p;
}

::SL3PM::Principal* OBV_SL3PM::QuotingPrincipal::quotes_for() const
{
  return _m.quotes_for.in();
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_StatementType;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_Encoding;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_EncodingType;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_BadEncoding;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
SL3PM::BadEncoding::BadEncoding()
{
}

SL3PM::BadEncoding::BadEncoding( const BadEncoding& _s )
{
}

SL3PM::BadEncoding::~BadEncoding()
{
}

SL3PM::BadEncoding&
SL3PM::BadEncoding::operator=( const BadEncoding& _s )
{
  return *this;
}
#endif

class _Marshaller_SL3PM_BadEncoding : public ::CORBA::StaticTypeInfo {
    typedef ::SL3PM::BadEncoding _MICO_T;
  public:
    ~_Marshaller_SL3PM_BadEncoding();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_BadEncoding::~_Marshaller_SL3PM_BadEncoding()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_BadEncoding::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_SL3PM_BadEncoding::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_BadEncoding::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_BadEncoding::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_SL3PM_BadEncoding::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:adiron.com/SL3PM/BadEncoding:1.0" );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_BadEncoding::typecode()
{
  return SL3PM::_tc_BadEncoding;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_BadEncoding;

void operator<<=( CORBA::Any &_a, const SL3PM::BadEncoding &_e )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_BadEncoding, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SL3PM::BadEncoding *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SL3PM::BadEncoding &_e )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_BadEncoding, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SL3PM::BadEncoding *&_e )
{
  return _a.to_static_any (_marshaller_SL3PM_BadEncoding, (void *&)_e);
}

void SL3PM::BadEncoding::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw BadEncoding_var( (SL3PM::BadEncoding*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *SL3PM::BadEncoding::_repoid() const
{
  return "IDL:adiron.com/SL3PM/BadEncoding:1.0";
}

void SL3PM::BadEncoding::_encode( CORBA::DataEncoder & ) const
{
  assert(0);
}

void SL3PM::BadEncoding::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *SL3PM::BadEncoding::_clone() const
{
  return new BadEncoding( *this );
}

SL3PM::BadEncoding *SL3PM::BadEncoding::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:adiron.com/SL3PM/BadEncoding:1.0" ) )
    return (BadEncoding *) _ex;
  return NULL;
}

const SL3PM::BadEncoding *SL3PM::BadEncoding::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:adiron.com/SL3PM/BadEncoding:1.0" ) )
    return (BadEncoding *) _ex;
  return NULL;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_BadEncodingType;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
SL3PM::BadEncodingType::BadEncodingType()
{
}

SL3PM::BadEncodingType::BadEncodingType( const BadEncodingType& _s )
{
}

SL3PM::BadEncodingType::~BadEncodingType()
{
}

SL3PM::BadEncodingType&
SL3PM::BadEncodingType::operator=( const BadEncodingType& _s )
{
  return *this;
}
#endif

class _Marshaller_SL3PM_BadEncodingType : public ::CORBA::StaticTypeInfo {
    typedef ::SL3PM::BadEncodingType _MICO_T;
  public:
    ~_Marshaller_SL3PM_BadEncodingType();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_BadEncodingType::~_Marshaller_SL3PM_BadEncodingType()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_BadEncodingType::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_SL3PM_BadEncodingType::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_BadEncodingType::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_BadEncodingType::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    dc.except_end();
}

void _Marshaller_SL3PM_BadEncodingType::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:adiron.com/SL3PM/BadEncodingType:1.0" );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_BadEncodingType::typecode()
{
  return SL3PM::_tc_BadEncodingType;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_BadEncodingType;

void operator<<=( CORBA::Any &_a, const SL3PM::BadEncodingType &_e )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_BadEncodingType, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SL3PM::BadEncodingType *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SL3PM::BadEncodingType &_e )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_BadEncodingType, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SL3PM::BadEncodingType *&_e )
{
  return _a.to_static_any (_marshaller_SL3PM_BadEncodingType, (void *&)_e);
}

void SL3PM::BadEncodingType::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw BadEncodingType_var( (SL3PM::BadEncodingType*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *SL3PM::BadEncodingType::_repoid() const
{
  return "IDL:adiron.com/SL3PM/BadEncodingType:1.0";
}

void SL3PM::BadEncodingType::_encode( CORBA::DataEncoder & ) const
{
  assert(0);
}

void SL3PM::BadEncodingType::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *SL3PM::BadEncodingType::_clone() const
{
  return new BadEncodingType( *this );
}

SL3PM::BadEncodingType *SL3PM::BadEncodingType::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:adiron.com/SL3PM/BadEncodingType:1.0" ) )
    return (BadEncodingType *) _ex;
  return NULL;
}

const SL3PM::BadEncodingType *SL3PM::BadEncodingType::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:adiron.com/SL3PM/BadEncodingType:1.0" ) )
    return (BadEncodingType *) _ex;
  return NULL;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_StatementLayer;
}


// valuetype Statement
SL3PM::Statement::Statement ()
{
}

SL3PM::Statement::~Statement ()
{
}

void *
SL3PM::Statement::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:adiron.com/SL3PM/Statement:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

SL3PM::Statement *
SL3PM::Statement::_downcast (CORBA::ValueBase * vb) 
{
  void * p;
  if (vb && ((p = vb->_narrow_helper ("IDL:adiron.com/SL3PM/Statement:1.0")))) {
    return (SL3PM::Statement *) p;
  }
  return 0;
}

SL3PM::Statement *
SL3PM::Statement::_downcast (CORBA::AbstractBase * vb) 
{
  return _downcast (vb->_to_value());
}

CORBA::ValueDef_ptr
SL3PM::Statement::get_value_def () 
{
  CORBA::ORB_var orb = CORBA::ORB_instance ("mico-local-orb");
  CORBA::Object_var irobj = 
    orb->resolve_initial_references ("InterfaceRepository");
  CORBA::Repository_var ifr = CORBA::Repository::_narrow (irobj);
  if (CORBA::is_nil (ifr)) {
    return CORBA::ValueDef::_nil ();
  }

  CORBA::Contained_var cv = ifr->lookup_id ("IDL:adiron.com/SL3PM/Statement:1.0");
  return CORBA::ValueDef::_narrow (cv);
}

void
SL3PM::Statement::_copy_members (const Statement& other)
{
  the_layer (other.the_layer());
  the_type (other.the_type());
  encoding_type (other.encoding_type());
  the_encoding (other.the_encoding());
}

CORBA::ValueBase *
SL3PM::Statement::_copy_value ()
{
  vector<string> _dummy;
  string _repo_id = "IDL:adiron.com/SL3PM/Statement:1.0";
  Statement * _res = _downcast (_create (_dummy, _repo_id));
  assert (_res != 0);
  _res->_copy_members (*this);
  return _res;
}

void
SL3PM::Statement::_get_marshal_info (vector<string> & repoids, CORBA::Boolean & chunked)
{
  repoids.push_back ("IDL:adiron.com/SL3PM/Statement:1.0");
  chunked = FALSE;
}

void
SL3PM::Statement::_marshal_members (CORBA::DataEncoder &ec)
{
  SL3PM::StatementLayer _the_layer = the_layer ();
  CORBA::_stc_ulong->marshal (ec, &_the_layer);
  SL3PM::StatementType _the_type = the_type ();
  CORBA::_stc_ulong->marshal (ec, &_the_type);
  const char * _encoding_type = encoding_type ();
  CORBA::_stc_string->marshal (ec, &_encoding_type);
  SL3PM::Encoding& _the_encoding = the_encoding ();
  CORBA::_stcseq_octet->marshal (ec, &_the_encoding);
}

CORBA::Boolean
SL3PM::Statement::_demarshal_members (CORBA::DataDecoder &dc)
{
  SL3PM::StatementLayer _the_layer;
  if (!CORBA::_stc_ulong->demarshal (dc, &_the_layer)) {
      return FALSE;
  }
  the_layer (_the_layer);
  SL3PM::StatementType _the_type;
  if (!CORBA::_stc_ulong->demarshal (dc, &_the_type)) {
      return FALSE;
  }
  the_type (_the_type);
  SL3PM::EncodingType_var _encoding_type;
  if (!CORBA::_stc_string->demarshal (dc, &_encoding_type._for_demarshal())) {
      return FALSE;
  }
  encoding_type (_encoding_type);
  SL3PM::Encoding _the_encoding;
  if (!CORBA::_stcseq_octet->demarshal (dc, &_the_encoding)) {
      return FALSE;
  }
  the_encoding (_the_encoding);
  return TRUE;
}

SL3PM::Statement_init::Statement_init ()
{
}

SL3PM::Statement_init::~Statement_init ()
{
}

void *
SL3PM::Statement_init::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:adiron.com/SL3PM/Statement:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

SL3PM::Statement_init *
SL3PM::Statement_init::_downcast (CORBA::ValueFactory vf) 
{
  void * p;
  if (vf && ((p = vf->_narrow_helper ("IDL:adiron.com/SL3PM/Statement:1.0")))) {
    return (SL3PM::Statement_init *) p;
  }
  return 0;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_Statement;
}

class _Marshaller_SL3PM_Statement : public ::CORBA::StaticTypeInfo {
    typedef SL3PM::Statement* _MICO_T;
  public:
    ~_Marshaller_SL3PM_Statement();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_Statement::~_Marshaller_SL3PM_Statement()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_Statement::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_SL3PM_Statement::assign( StaticValueType d, const StaticValueType s ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)d);
  ::CORBA::add_ref (*(_MICO_T*)s);
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_Statement::free( StaticValueType v ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)v);
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_Statement::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ValueBase* vb = NULL;
  if (!::CORBA::ValueBase::_demarshal (dc, vb, "IDL:adiron.com/SL3PM/Statement:1.0")) {
    return FALSE;
  }
  ::CORBA::remove_ref (*(_MICO_T *)v);
  *(_MICO_T *)v = ::SL3PM::Statement::_downcast (vb);
  if (vb && !*(_MICO_T *)v) {
    ::CORBA::remove_ref (vb);
    return FALSE;
  }
  return TRUE;
}

void _Marshaller_SL3PM_Statement::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ValueBase::_marshal (ec, *(_MICO_T *)v);
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_Statement::typecode()
{
  return SL3PM::_tc_Statement;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_Statement;

void
operator<<=( CORBA::Any &_a, const SL3PM::Statement* _val )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_Statement, &_val);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, SL3PM::Statement** _val_ptr )
{
  CORBA::ValueBase_var _val = *_val_ptr;
  CORBA::StaticAny _sa (_marshaller_SL3PM_Statement, _val_ptr);
  _a.from_static_any (_sa);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, SL3PM::Statement* &_val_ptr )
{
  SL3PM::Statement* *p;
  if (_a.to_static_any (_marshaller_SL3PM_Statement, (void *&)p)) {
    _val_ptr = *p;
    return TRUE;
  }
  return FALSE;
}


// OBV class for valuetype Statement
OBV_SL3PM::Statement::Statement ()
{
}

OBV_SL3PM::Statement::Statement (::SL3PM::StatementLayer _the_layer, ::SL3PM::StatementType _the_type, const char* _encoding_type, const ::SL3PM::Encoding& _the_encoding)
{
  this->the_layer(_the_layer);
  this->the_type(_the_type);
  this->encoding_type(_encoding_type);
  this->the_encoding(_the_encoding);
}

OBV_SL3PM::Statement::~Statement ()
{
}

void OBV_SL3PM::Statement::the_layer( ::SL3PM::StatementLayer _p )
{
  _m.the_layer = _p;
}

::SL3PM::StatementLayer OBV_SL3PM::Statement::the_layer() const
{
  return (::SL3PM::StatementLayer)_m.the_layer;
}

void OBV_SL3PM::Statement::the_type( ::SL3PM::StatementType _p )
{
  _m.the_type = _p;
}

::SL3PM::StatementType OBV_SL3PM::Statement::the_type() const
{
  return (::SL3PM::StatementType)_m.the_type;
}

void OBV_SL3PM::Statement::encoding_type( char *_p )
{
  _m.encoding_type = _p;
}

void OBV_SL3PM::Statement::encoding_type( const char *_p )
{
  _m.encoding_type = _p;
}

void OBV_SL3PM::Statement::encoding_type( const CORBA::String_var &_p )
{
  _m.encoding_type = _p;
}

const char *OBV_SL3PM::Statement::encoding_type() const
{
  return _m.encoding_type;
}

void OBV_SL3PM::Statement::the_encoding( const ::SL3PM::Encoding& _p )
{
  _m.the_encoding = _p;
}

const ::SL3PM::Encoding& OBV_SL3PM::Statement::the_encoding() const
{
  return (::SL3PM::Encoding&) _m.the_encoding;
}

::SL3PM::Encoding& OBV_SL3PM::Statement::the_encoding()
{
  return _m.the_encoding;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_StatementList;
}


// valuetype IdentityStatement
SL3PM::IdentityStatement::IdentityStatement ()
{
}

SL3PM::IdentityStatement::~IdentityStatement ()
{
}

void *
SL3PM::IdentityStatement::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:adiron.com/SL3PM/IdentityStatement:1.0") == 0) {
    return (void *) this;
  }
  if ((p = SL3PM::Statement::_narrow_helper (repoid)) != NULL) {
    return p;
  }
  return NULL;
}

SL3PM::IdentityStatement *
SL3PM::IdentityStatement::_downcast (CORBA::ValueBase * vb) 
{
  void * p;
  if (vb && ((p = vb->_narrow_helper ("IDL:adiron.com/SL3PM/IdentityStatement:1.0")))) {
    return (SL3PM::IdentityStatement *) p;
  }
  return 0;
}

SL3PM::IdentityStatement *
SL3PM::IdentityStatement::_downcast (CORBA::AbstractBase * vb) 
{
  return _downcast (vb->_to_value());
}

CORBA::ValueDef_ptr
SL3PM::IdentityStatement::get_value_def () 
{
  CORBA::ORB_var orb = CORBA::ORB_instance ("mico-local-orb");
  CORBA::Object_var irobj = 
    orb->resolve_initial_references ("InterfaceRepository");
  CORBA::Repository_var ifr = CORBA::Repository::_narrow (irobj);
  if (CORBA::is_nil (ifr)) {
    return CORBA::ValueDef::_nil ();
  }

  CORBA::Contained_var cv = ifr->lookup_id ("IDL:adiron.com/SL3PM/IdentityStatement:1.0");
  return CORBA::ValueDef::_narrow (cv);
}

void
SL3PM::IdentityStatement::_copy_members (const IdentityStatement& other)
{
  interpretation_aid (other.interpretation_aid());
}

CORBA::ValueBase *
SL3PM::IdentityStatement::_copy_value ()
{
  vector<string> _dummy;
  string _repo_id = "IDL:adiron.com/SL3PM/IdentityStatement:1.0";
  IdentityStatement * _res = _downcast (_create (_dummy, _repo_id));
  assert (_res != 0);
  _res->SL3PM::Statement::_copy_members (*this);
  _res->_copy_members (*this);
  return _res;
}

void
SL3PM::IdentityStatement::_get_marshal_info (vector<string> & repoids, CORBA::Boolean & chunked)
{
  repoids.push_back ("IDL:adiron.com/SL3PM/IdentityStatement:1.0");
  chunked = FALSE;
}

void
SL3PM::IdentityStatement::_marshal_members (CORBA::DataEncoder &ec)
{
  SL3PM::Statement::_marshal_members (ec);
  const char * _interpretation_aid = interpretation_aid ();
  CORBA::_stc_string->marshal (ec, &_interpretation_aid);
}

CORBA::Boolean
SL3PM::IdentityStatement::_demarshal_members (CORBA::DataDecoder &dc)
{
  if (!SL3PM::Statement::_demarshal_members (dc)) {
      return FALSE;
  }
  CORBA::String_var _interpretation_aid;
  if (!CORBA::_stc_string->demarshal (dc, &_interpretation_aid._for_demarshal())) {
      return FALSE;
  }
  interpretation_aid (_interpretation_aid);
  return TRUE;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_IdentityStatement;
}

class _Marshaller_SL3PM_IdentityStatement : public ::CORBA::StaticTypeInfo {
    typedef SL3PM::IdentityStatement* _MICO_T;
  public:
    ~_Marshaller_SL3PM_IdentityStatement();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_IdentityStatement::~_Marshaller_SL3PM_IdentityStatement()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_IdentityStatement::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_SL3PM_IdentityStatement::assign( StaticValueType d, const StaticValueType s ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)d);
  ::CORBA::add_ref (*(_MICO_T*)s);
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_IdentityStatement::free( StaticValueType v ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)v);
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_IdentityStatement::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ValueBase* vb = NULL;
  if (!::CORBA::ValueBase::_demarshal (dc, vb, "IDL:adiron.com/SL3PM/IdentityStatement:1.0")) {
    return FALSE;
  }
  ::CORBA::remove_ref (*(_MICO_T *)v);
  *(_MICO_T *)v = ::SL3PM::IdentityStatement::_downcast (vb);
  if (vb && !*(_MICO_T *)v) {
    ::CORBA::remove_ref (vb);
    return FALSE;
  }
  return TRUE;
}

void _Marshaller_SL3PM_IdentityStatement::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ValueBase::_marshal (ec, *(_MICO_T *)v);
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_IdentityStatement::typecode()
{
  return SL3PM::_tc_IdentityStatement;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_IdentityStatement;

void
operator<<=( CORBA::Any &_a, const SL3PM::IdentityStatement* _val )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_IdentityStatement, &_val);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, SL3PM::IdentityStatement** _val_ptr )
{
  CORBA::ValueBase_var _val = *_val_ptr;
  CORBA::StaticAny _sa (_marshaller_SL3PM_IdentityStatement, _val_ptr);
  _a.from_static_any (_sa);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, SL3PM::IdentityStatement* &_val_ptr )
{
  SL3PM::IdentityStatement* *p;
  if (_a.to_static_any (_marshaller_SL3PM_IdentityStatement, (void *&)p)) {
    _val_ptr = *p;
    return TRUE;
  }
  return FALSE;
}


// OBV class for valuetype IdentityStatement
OBV_SL3PM::IdentityStatement::IdentityStatement ()
{
}

OBV_SL3PM::IdentityStatement::IdentityStatement (::SL3PM::StatementLayer _the_layer, ::SL3PM::StatementType _the_type, const char* _encoding_type, const ::SL3PM::Encoding& _the_encoding, const char* _interpretation_aid)
{
  this->the_layer(_the_layer);
  this->the_type(_the_type);
  this->encoding_type(_encoding_type);
  this->the_encoding(_the_encoding);
  this->interpretation_aid(_interpretation_aid);
}

OBV_SL3PM::IdentityStatement::~IdentityStatement ()
{
}

void OBV_SL3PM::IdentityStatement::interpretation_aid( char *_p )
{
  _m.interpretation_aid = _p;
}

void OBV_SL3PM::IdentityStatement::interpretation_aid( const char *_p )
{
  _m.interpretation_aid = _p;
}

void OBV_SL3PM::IdentityStatement::interpretation_aid( const CORBA::String_var &_p )
{
  _m.interpretation_aid = _p;
}

const char *OBV_SL3PM::IdentityStatement::interpretation_aid() const
{
  return _m.interpretation_aid;
}


// valuetype PrincipalIdentityStatement
SL3PM::PrincipalIdentityStatement::PrincipalIdentityStatement ()
{
}

SL3PM::PrincipalIdentityStatement::~PrincipalIdentityStatement ()
{
}

void *
SL3PM::PrincipalIdentityStatement::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:adiron.com/SL3PM/PrincipalIdentityStatement:1.0") == 0) {
    return (void *) this;
  }
  if ((p = SL3PM::IdentityStatement::_narrow_helper (repoid)) != NULL) {
    return p;
  }
  return NULL;
}

SL3PM::PrincipalIdentityStatement *
SL3PM::PrincipalIdentityStatement::_downcast (CORBA::ValueBase * vb) 
{
  void * p;
  if (vb && ((p = vb->_narrow_helper ("IDL:adiron.com/SL3PM/PrincipalIdentityStatement:1.0")))) {
    return (SL3PM::PrincipalIdentityStatement *) p;
  }
  return 0;
}

SL3PM::PrincipalIdentityStatement *
SL3PM::PrincipalIdentityStatement::_downcast (CORBA::AbstractBase * vb) 
{
  return _downcast (vb->_to_value());
}

CORBA::ValueDef_ptr
SL3PM::PrincipalIdentityStatement::get_value_def () 
{
  CORBA::ORB_var orb = CORBA::ORB_instance ("mico-local-orb");
  CORBA::Object_var irobj = 
    orb->resolve_initial_references ("InterfaceRepository");
  CORBA::Repository_var ifr = CORBA::Repository::_narrow (irobj);
  if (CORBA::is_nil (ifr)) {
    return CORBA::ValueDef::_nil ();
  }

  CORBA::Contained_var cv = ifr->lookup_id ("IDL:adiron.com/SL3PM/PrincipalIdentityStatement:1.0");
  return CORBA::ValueDef::_narrow (cv);
}

void
SL3PM::PrincipalIdentityStatement::_copy_members (const PrincipalIdentityStatement& other)
{
  SL3PM::Principal_var _the_principal = SL3PM::Principal::_downcast (other.the_principal()->_copy_value());
  the_principal (_the_principal);
}

CORBA::ValueBase *
SL3PM::PrincipalIdentityStatement::_copy_value ()
{
  vector<string> _dummy;
  string _repo_id = "IDL:adiron.com/SL3PM/PrincipalIdentityStatement:1.0";
  PrincipalIdentityStatement * _res = _downcast (_create (_dummy, _repo_id));
  assert (_res != 0);
  _res->SL3PM::IdentityStatement::_copy_members (*this);
  _res->_copy_members (*this);
  return _res;
}

void
SL3PM::PrincipalIdentityStatement::_get_marshal_info (vector<string> & repoids, CORBA::Boolean & chunked)
{
  repoids.push_back ("IDL:adiron.com/SL3PM/PrincipalIdentityStatement:1.0");
  chunked = FALSE;
}

void
SL3PM::PrincipalIdentityStatement::_marshal_members (CORBA::DataEncoder &ec)
{
  SL3PM::IdentityStatement::_marshal_members (ec);
  SL3PM::Principal* _the_principal = the_principal ();
  _marshaller_SL3PM_Principal->marshal (ec, &_the_principal);
}

CORBA::Boolean
SL3PM::PrincipalIdentityStatement::_demarshal_members (CORBA::DataDecoder &dc)
{
  if (!SL3PM::IdentityStatement::_demarshal_members (dc)) {
      return FALSE;
  }
  SL3PM::Principal_var _the_principal;
  if (!_marshaller_SL3PM_Principal->demarshal (dc, &_the_principal._for_demarshal())) {
      return FALSE;
  }
  the_principal (_the_principal);
  return TRUE;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_PrincipalIdentityStatement;
}

class _Marshaller_SL3PM_PrincipalIdentityStatement : public ::CORBA::StaticTypeInfo {
    typedef SL3PM::PrincipalIdentityStatement* _MICO_T;
  public:
    ~_Marshaller_SL3PM_PrincipalIdentityStatement();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_PrincipalIdentityStatement::~_Marshaller_SL3PM_PrincipalIdentityStatement()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_PrincipalIdentityStatement::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_SL3PM_PrincipalIdentityStatement::assign( StaticValueType d, const StaticValueType s ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)d);
  ::CORBA::add_ref (*(_MICO_T*)s);
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_PrincipalIdentityStatement::free( StaticValueType v ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)v);
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_PrincipalIdentityStatement::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ValueBase* vb = NULL;
  if (!::CORBA::ValueBase::_demarshal (dc, vb, "IDL:adiron.com/SL3PM/PrincipalIdentityStatement:1.0")) {
    return FALSE;
  }
  ::CORBA::remove_ref (*(_MICO_T *)v);
  *(_MICO_T *)v = ::SL3PM::PrincipalIdentityStatement::_downcast (vb);
  if (vb && !*(_MICO_T *)v) {
    ::CORBA::remove_ref (vb);
    return FALSE;
  }
  return TRUE;
}

void _Marshaller_SL3PM_PrincipalIdentityStatement::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ValueBase::_marshal (ec, *(_MICO_T *)v);
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_PrincipalIdentityStatement::typecode()
{
  return SL3PM::_tc_PrincipalIdentityStatement;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_PrincipalIdentityStatement;

void
operator<<=( CORBA::Any &_a, const SL3PM::PrincipalIdentityStatement* _val )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_PrincipalIdentityStatement, &_val);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, SL3PM::PrincipalIdentityStatement** _val_ptr )
{
  CORBA::ValueBase_var _val = *_val_ptr;
  CORBA::StaticAny _sa (_marshaller_SL3PM_PrincipalIdentityStatement, _val_ptr);
  _a.from_static_any (_sa);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, SL3PM::PrincipalIdentityStatement* &_val_ptr )
{
  SL3PM::PrincipalIdentityStatement* *p;
  if (_a.to_static_any (_marshaller_SL3PM_PrincipalIdentityStatement, (void *&)p)) {
    _val_ptr = *p;
    return TRUE;
  }
  return FALSE;
}


// OBV class for valuetype PrincipalIdentityStatement
OBV_SL3PM::PrincipalIdentityStatement::PrincipalIdentityStatement ()
{
}

OBV_SL3PM::PrincipalIdentityStatement::PrincipalIdentityStatement (::SL3PM::StatementLayer _the_layer, ::SL3PM::StatementType _the_type, const char* _encoding_type, const ::SL3PM::Encoding& _the_encoding, const char* _interpretation_aid, ::SL3PM::Principal* _the_principal)
{
  this->the_layer(_the_layer);
  this->the_type(_the_type);
  this->encoding_type(_encoding_type);
  this->the_encoding(_the_encoding);
  this->interpretation_aid(_interpretation_aid);
  this->the_principal(_the_principal);
}

OBV_SL3PM::PrincipalIdentityStatement::~PrincipalIdentityStatement ()
{
}

void OBV_SL3PM::PrincipalIdentityStatement::the_principal( ::SL3PM::Principal* _p )
{
  CORBA::add_ref ( _p );
  _m.the_principal = _p;
}

::SL3PM::Principal* OBV_SL3PM::PrincipalIdentityStatement::the_principal() const
{
  return _m.the_principal.in();
}


// valuetype EndorsementStatement
SL3PM::EndorsementStatement::EndorsementStatement ()
{
}

SL3PM::EndorsementStatement::~EndorsementStatement ()
{
}

void *
SL3PM::EndorsementStatement::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:adiron.com/SL3PM/EndorsementStatement:1.0") == 0) {
    return (void *) this;
  }
  if ((p = SL3PM::Statement::_narrow_helper (repoid)) != NULL) {
    return p;
  }
  return NULL;
}

SL3PM::EndorsementStatement *
SL3PM::EndorsementStatement::_downcast (CORBA::ValueBase * vb) 
{
  void * p;
  if (vb && ((p = vb->_narrow_helper ("IDL:adiron.com/SL3PM/EndorsementStatement:1.0")))) {
    return (SL3PM::EndorsementStatement *) p;
  }
  return 0;
}

SL3PM::EndorsementStatement *
SL3PM::EndorsementStatement::_downcast (CORBA::AbstractBase * vb) 
{
  return _downcast (vb->_to_value());
}

CORBA::ValueDef_ptr
SL3PM::EndorsementStatement::get_value_def () 
{
  CORBA::ORB_var orb = CORBA::ORB_instance ("mico-local-orb");
  CORBA::Object_var irobj = 
    orb->resolve_initial_references ("InterfaceRepository");
  CORBA::Repository_var ifr = CORBA::Repository::_narrow (irobj);
  if (CORBA::is_nil (ifr)) {
    return CORBA::ValueDef::_nil ();
  }

  CORBA::Contained_var cv = ifr->lookup_id ("IDL:adiron.com/SL3PM/EndorsementStatement:1.0");
  return CORBA::ValueDef::_narrow (cv);
}

void
SL3PM::EndorsementStatement::_copy_members (const EndorsementStatement& other)
{
  interpretation_aid (other.interpretation_aid());
}

CORBA::ValueBase *
SL3PM::EndorsementStatement::_copy_value ()
{
  vector<string> _dummy;
  string _repo_id = "IDL:adiron.com/SL3PM/EndorsementStatement:1.0";
  EndorsementStatement * _res = _downcast (_create (_dummy, _repo_id));
  assert (_res != 0);
  _res->SL3PM::Statement::_copy_members (*this);
  _res->_copy_members (*this);
  return _res;
}

void
SL3PM::EndorsementStatement::_get_marshal_info (vector<string> & repoids, CORBA::Boolean & chunked)
{
  repoids.push_back ("IDL:adiron.com/SL3PM/EndorsementStatement:1.0");
  chunked = FALSE;
}

void
SL3PM::EndorsementStatement::_marshal_members (CORBA::DataEncoder &ec)
{
  SL3PM::Statement::_marshal_members (ec);
  const char * _interpretation_aid = interpretation_aid ();
  CORBA::_stc_string->marshal (ec, &_interpretation_aid);
}

CORBA::Boolean
SL3PM::EndorsementStatement::_demarshal_members (CORBA::DataDecoder &dc)
{
  if (!SL3PM::Statement::_demarshal_members (dc)) {
      return FALSE;
  }
  CORBA::String_var _interpretation_aid;
  if (!CORBA::_stc_string->demarshal (dc, &_interpretation_aid._for_demarshal())) {
      return FALSE;
  }
  interpretation_aid (_interpretation_aid);
  return TRUE;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_EndorsementStatement;
}

class _Marshaller_SL3PM_EndorsementStatement : public ::CORBA::StaticTypeInfo {
    typedef SL3PM::EndorsementStatement* _MICO_T;
  public:
    ~_Marshaller_SL3PM_EndorsementStatement();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_EndorsementStatement::~_Marshaller_SL3PM_EndorsementStatement()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_EndorsementStatement::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_SL3PM_EndorsementStatement::assign( StaticValueType d, const StaticValueType s ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)d);
  ::CORBA::add_ref (*(_MICO_T*)s);
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_EndorsementStatement::free( StaticValueType v ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)v);
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_EndorsementStatement::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ValueBase* vb = NULL;
  if (!::CORBA::ValueBase::_demarshal (dc, vb, "IDL:adiron.com/SL3PM/EndorsementStatement:1.0")) {
    return FALSE;
  }
  ::CORBA::remove_ref (*(_MICO_T *)v);
  *(_MICO_T *)v = ::SL3PM::EndorsementStatement::_downcast (vb);
  if (vb && !*(_MICO_T *)v) {
    ::CORBA::remove_ref (vb);
    return FALSE;
  }
  return TRUE;
}

void _Marshaller_SL3PM_EndorsementStatement::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ValueBase::_marshal (ec, *(_MICO_T *)v);
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_EndorsementStatement::typecode()
{
  return SL3PM::_tc_EndorsementStatement;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_EndorsementStatement;

void
operator<<=( CORBA::Any &_a, const SL3PM::EndorsementStatement* _val )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_EndorsementStatement, &_val);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, SL3PM::EndorsementStatement** _val_ptr )
{
  CORBA::ValueBase_var _val = *_val_ptr;
  CORBA::StaticAny _sa (_marshaller_SL3PM_EndorsementStatement, _val_ptr);
  _a.from_static_any (_sa);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, SL3PM::EndorsementStatement* &_val_ptr )
{
  SL3PM::EndorsementStatement* *p;
  if (_a.to_static_any (_marshaller_SL3PM_EndorsementStatement, (void *&)p)) {
    _val_ptr = *p;
    return TRUE;
  }
  return FALSE;
}


// OBV class for valuetype EndorsementStatement
OBV_SL3PM::EndorsementStatement::EndorsementStatement ()
{
}

OBV_SL3PM::EndorsementStatement::EndorsementStatement (::SL3PM::StatementLayer _the_layer, ::SL3PM::StatementType _the_type, const char* _encoding_type, const ::SL3PM::Encoding& _the_encoding, const char* _interpretation_aid)
{
  this->the_layer(_the_layer);
  this->the_type(_the_type);
  this->encoding_type(_encoding_type);
  this->the_encoding(_the_encoding);
  this->interpretation_aid(_interpretation_aid);
}

OBV_SL3PM::EndorsementStatement::~EndorsementStatement ()
{
}

void OBV_SL3PM::EndorsementStatement::interpretation_aid( char *_p )
{
  _m.interpretation_aid = _p;
}

void OBV_SL3PM::EndorsementStatement::interpretation_aid( const char *_p )
{
  _m.interpretation_aid = _p;
}

void OBV_SL3PM::EndorsementStatement::interpretation_aid( const CORBA::String_var &_p )
{
  _m.interpretation_aid = _p;
}

const char *OBV_SL3PM::EndorsementStatement::interpretation_aid() const
{
  return _m.interpretation_aid;
}


// valuetype X509IdentityStatement
SL3PM::X509IdentityStatement::X509IdentityStatement ()
{
}

SL3PM::X509IdentityStatement::~X509IdentityStatement ()
{
}

void *
SL3PM::X509IdentityStatement::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:adiron.com/SL3PM/X509IdentityStatement:1.0") == 0) {
    return (void *) this;
  }
  if ((p = SL3PM::PrincipalIdentityStatement::_narrow_helper (repoid)) != NULL) {
    return p;
  }
  return NULL;
}

SL3PM::X509IdentityStatement *
SL3PM::X509IdentityStatement::_downcast (CORBA::ValueBase * vb) 
{
  void * p;
  if (vb && ((p = vb->_narrow_helper ("IDL:adiron.com/SL3PM/X509IdentityStatement:1.0")))) {
    return (SL3PM::X509IdentityStatement *) p;
  }
  return 0;
}

SL3PM::X509IdentityStatement *
SL3PM::X509IdentityStatement::_downcast (CORBA::AbstractBase * vb) 
{
  return _downcast (vb->_to_value());
}

CORBA::ValueDef_ptr
SL3PM::X509IdentityStatement::get_value_def () 
{
  CORBA::ORB_var orb = CORBA::ORB_instance ("mico-local-orb");
  CORBA::Object_var irobj = 
    orb->resolve_initial_references ("InterfaceRepository");
  CORBA::Repository_var ifr = CORBA::Repository::_narrow (irobj);
  if (CORBA::is_nil (ifr)) {
    return CORBA::ValueDef::_nil ();
  }

  CORBA::Contained_var cv = ifr->lookup_id ("IDL:adiron.com/SL3PM/X509IdentityStatement:1.0");
  return CORBA::ValueDef::_narrow (cv);
}

void
SL3PM::X509IdentityStatement::_copy_members (const X509IdentityStatement& other)
{
}

CORBA::ValueBase *
SL3PM::X509IdentityStatement::_copy_value ()
{
  vector<string> _dummy;
  string _repo_id = "IDL:adiron.com/SL3PM/X509IdentityStatement:1.0";
  X509IdentityStatement * _res = _downcast (_create (_dummy, _repo_id));
  assert (_res != 0);
  _res->SL3PM::PrincipalIdentityStatement::_copy_members (*this);
  _res->_copy_members (*this);
  return _res;
}

void
SL3PM::X509IdentityStatement::_get_marshal_info (vector<string> & repoids, CORBA::Boolean & chunked)
{
  repoids.push_back ("IDL:adiron.com/SL3PM/X509IdentityStatement:1.0");
  chunked = FALSE;
}

void
SL3PM::X509IdentityStatement::_marshal_members (CORBA::DataEncoder &ec)
{
  SL3PM::PrincipalIdentityStatement::_marshal_members (ec);
}

CORBA::Boolean
SL3PM::X509IdentityStatement::_demarshal_members (CORBA::DataDecoder &dc)
{
  if (!SL3PM::PrincipalIdentityStatement::_demarshal_members (dc)) {
      return FALSE;
  }
  return TRUE;
}

SL3PM::X509IdentityStatement_init::X509IdentityStatement_init ()
{
}

SL3PM::X509IdentityStatement_init::~X509IdentityStatement_init ()
{
}

void *
SL3PM::X509IdentityStatement_init::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:adiron.com/SL3PM/X509IdentityStatement:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

SL3PM::X509IdentityStatement_init *
SL3PM::X509IdentityStatement_init::_downcast (CORBA::ValueFactory vf) 
{
  void * p;
  if (vf && ((p = vf->_narrow_helper ("IDL:adiron.com/SL3PM/X509IdentityStatement:1.0")))) {
    return (SL3PM::X509IdentityStatement_init *) p;
  }
  return 0;
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_X509IdentityStatement;
}

class _Marshaller_SL3PM_X509IdentityStatement : public ::CORBA::StaticTypeInfo {
    typedef SL3PM::X509IdentityStatement* _MICO_T;
  public:
    ~_Marshaller_SL3PM_X509IdentityStatement();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3PM_X509IdentityStatement::~_Marshaller_SL3PM_X509IdentityStatement()
{
}

::CORBA::StaticValueType _Marshaller_SL3PM_X509IdentityStatement::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_SL3PM_X509IdentityStatement::assign( StaticValueType d, const StaticValueType s ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)d);
  ::CORBA::add_ref (*(_MICO_T*)s);
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3PM_X509IdentityStatement::free( StaticValueType v ) const
{
  ::CORBA::remove_ref (*(_MICO_T*)v);
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3PM_X509IdentityStatement::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ValueBase* vb = NULL;
  if (!::CORBA::ValueBase::_demarshal (dc, vb, "IDL:adiron.com/SL3PM/X509IdentityStatement:1.0")) {
    return FALSE;
  }
  ::CORBA::remove_ref (*(_MICO_T *)v);
  *(_MICO_T *)v = ::SL3PM::X509IdentityStatement::_downcast (vb);
  if (vb && !*(_MICO_T *)v) {
    ::CORBA::remove_ref (vb);
    return FALSE;
  }
  return TRUE;
}

void _Marshaller_SL3PM_X509IdentityStatement::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ValueBase::_marshal (ec, *(_MICO_T *)v);
}

::CORBA::TypeCode_ptr _Marshaller_SL3PM_X509IdentityStatement::typecode()
{
  return SL3PM::_tc_X509IdentityStatement;
}

::CORBA::StaticTypeInfo *_marshaller_SL3PM_X509IdentityStatement;

void
operator<<=( CORBA::Any &_a, const SL3PM::X509IdentityStatement* _val )
{
  CORBA::StaticAny _sa (_marshaller_SL3PM_X509IdentityStatement, &_val);
  _a.from_static_any (_sa);
}

void
operator<<=( CORBA::Any &_a, SL3PM::X509IdentityStatement** _val_ptr )
{
  CORBA::ValueBase_var _val = *_val_ptr;
  CORBA::StaticAny _sa (_marshaller_SL3PM_X509IdentityStatement, _val_ptr);
  _a.from_static_any (_sa);
}

CORBA::Boolean
operator>>=( const CORBA::Any &_a, SL3PM::X509IdentityStatement* &_val_ptr )
{
  SL3PM::X509IdentityStatement* *p;
  if (_a.to_static_any (_marshaller_SL3PM_X509IdentityStatement, (void *&)p)) {
    _val_ptr = *p;
    return TRUE;
  }
  return FALSE;
}


// OBV class for valuetype X509IdentityStatement
OBV_SL3PM::X509IdentityStatement::X509IdentityStatement ()
{
}

OBV_SL3PM::X509IdentityStatement::X509IdentityStatement (::SL3PM::StatementLayer _the_layer, ::SL3PM::StatementType _the_type, const char* _encoding_type, const ::SL3PM::Encoding& _the_encoding, const char* _interpretation_aid, ::SL3PM::Principal* _the_principal)
{
  this->the_layer(_the_layer);
  this->the_type(_the_type);
  this->encoding_type(_encoding_type);
  this->the_encoding(_the_encoding);
  this->interpretation_aid(_interpretation_aid);
  this->the_principal(_the_principal);
}

OBV_SL3PM::X509IdentityStatement::~X509IdentityStatement ()
{
}

namespace SL3PM
{
CORBA::TypeCodeConst _tc_X509IdentityStatementList;
}

class _Marshaller__seq_SL3PM_PrincipalName : public ::CORBA::StaticTypeInfo {
    typedef SequenceTmpl< SL3PM::PrincipalName,MICO_TID_DEF> _MICO_T;
    static ::CORBA::TypeCode_ptr _tc;
  public:
    ~_Marshaller__seq_SL3PM_PrincipalName();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller__seq_SL3PM_PrincipalName::~_Marshaller__seq_SL3PM_PrincipalName()
{
  if (_tc)
    delete _tc;
}

::CORBA::StaticValueType _Marshaller__seq_SL3PM_PrincipalName::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_SL3PM_PrincipalName::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_SL3PM_PrincipalName::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_SL3PM_PrincipalName::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_SL3PM_PrincipalName->demarshal( dc, &(*(_MICO_T*)v)[i] ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_SL3PM_PrincipalName::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_SL3PM_PrincipalName->marshal( ec, &(*(_MICO_T*)v)[i] );
  ec.seq_end();
}

::CORBA::TypeCode_ptr _Marshaller__seq_SL3PM_PrincipalName::typecode()
{
  if (!_tc)
    _tc = (new ::CORBA::TypeCode (
    "0100000013000000b0010000010000000f000000a0010000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970"
    "616c4e616d653a312e3000000e0000005072696e636970616c4e616d6500"
    "000002000000090000007468655f74797065000000001500000044000000"
    "010000002200000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d65547970653a312e30000000090000004e616d655479706500000000"
    "1200000000000000090000007468655f6e616d650000000015000000e400"
    "0000010000002300000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f4e616d6556616c75653a312e3000000a0000004e616d6556616c756500"
    "000015000000a0000000010000002200000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f4e616d65506174683a312e30000000090000004e61"
    "6d655061746800000000130000005c00000001000000150000004c000000"
    "010000002700000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d65436f6d706f6e656e743a312e3000000e0000004e616d65436f6d70"
    "6f6e656e740000001b000000000000000000000000000000"))->mk_constant();
  return _tc;
}

::CORBA::TypeCode_ptr _Marshaller__seq_SL3PM_PrincipalName::_tc = 0;
::CORBA::StaticTypeInfo *_marshaller__seq_SL3PM_PrincipalName;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< SL3PM::PrincipalName,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_SL3PM_PrincipalName, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SequenceTmpl< SL3PM::PrincipalName,MICO_TID_DEF> *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< SL3PM::PrincipalName,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_SL3PM_PrincipalName, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< SL3PM::PrincipalName,MICO_TID_DEF> *&_s )
{
  return _a.to_static_any (_marshaller__seq_SL3PM_PrincipalName, (void *&)_s);
}


class _Marshaller__seq_SL3PM_PrinAttribute : public ::CORBA::StaticTypeInfo {
    typedef SequenceTmpl< SL3PM::PrinAttribute,MICO_TID_DEF> _MICO_T;
    static ::CORBA::TypeCode_ptr _tc;
  public:
    ~_Marshaller__seq_SL3PM_PrinAttribute();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller__seq_SL3PM_PrinAttribute::~_Marshaller__seq_SL3PM_PrinAttribute()
{
  if (_tc)
    delete _tc;
}

::CORBA::StaticValueType _Marshaller__seq_SL3PM_PrinAttribute::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_SL3PM_PrinAttribute::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_SL3PM_PrinAttribute::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_SL3PM_PrinAttribute::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_SL3PM_PrinAttribute->demarshal( dc, &(*(_MICO_T*)v)[i] ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_SL3PM_PrinAttribute::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_SL3PM_PrinAttribute->marshal( ec, &(*(_MICO_T*)v)[i] );
  ec.seq_end();
}

::CORBA::TypeCode_ptr _Marshaller__seq_SL3PM_PrinAttribute::typecode()
{
  if (!_tc)
    _tc = (new ::CORBA::TypeCode (
    "010000001300000030010000010000000f00000020010000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e417474"
    "7269627574653a312e3000000e0000005072696e41747472696275746500"
    "000002000000090000007468655f74797065000000001500000054000000"
    "010000002b00000049444c3a616469726f6e2e636f6d2f534c33504d2f50"
    "72696e417474726962757465547970653a312e300000120000005072696e"
    "4174747269627574655479706500000012000000000000000a0000007468"
    "655f76616c75650000001500000054000000010000002c00000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e417474726962757465"
    "56616c75653a312e3000130000005072696e41747472696275746556616c"
    "756500001b0000000000000000000000"))->mk_constant();
  return _tc;
}

::CORBA::TypeCode_ptr _Marshaller__seq_SL3PM_PrinAttribute::_tc = 0;
::CORBA::StaticTypeInfo *_marshaller__seq_SL3PM_PrinAttribute;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< SL3PM::PrinAttribute,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_SL3PM_PrinAttribute, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SequenceTmpl< SL3PM::PrinAttribute,MICO_TID_DEF> *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< SL3PM::PrinAttribute,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_SL3PM_PrinAttribute, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< SL3PM::PrinAttribute,MICO_TID_DEF> *&_s )
{
  return _a.to_static_any (_marshaller__seq_SL3PM_PrinAttribute, (void *&)_s);
}


class _Marshaller__seq_SL3PM_ResourceName : public ::CORBA::StaticTypeInfo {
    typedef SequenceTmpl< SL3PM::ResourceName,MICO_TID_DEF> _MICO_T;
    static ::CORBA::TypeCode_ptr _tc;
  public:
    ~_Marshaller__seq_SL3PM_ResourceName();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller__seq_SL3PM_ResourceName::~_Marshaller__seq_SL3PM_ResourceName()
{
  if (_tc)
    delete _tc;
}

::CORBA::StaticValueType _Marshaller__seq_SL3PM_ResourceName::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_SL3PM_ResourceName::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_SL3PM_ResourceName::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_SL3PM_ResourceName::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_SL3PM_ResourceName->demarshal( dc, &(*(_MICO_T*)v)[i] ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_SL3PM_ResourceName::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_SL3PM_ResourceName->marshal( ec, &(*(_MICO_T*)v)[i] );
  ec.seq_end();
}

::CORBA::TypeCode_ptr _Marshaller__seq_SL3PM_ResourceName::typecode()
{
  if (!_tc)
    _tc = (new ::CORBA::TypeCode (
    "010000001300000080000000010000000f00000070000000010000002600"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5265736f757263"
    "654e616d653a312e300000000d0000005265736f757263654e616d650000"
    "0000010000000b000000636f6d706f6e656e747300001300000010000000"
    "0100000012000000000000000000000000000000"))->mk_constant();
  return _tc;
}

::CORBA::TypeCode_ptr _Marshaller__seq_SL3PM_ResourceName::_tc = 0;
::CORBA::StaticTypeInfo *_marshaller__seq_SL3PM_ResourceName;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< SL3PM::ResourceName,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_SL3PM_ResourceName, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SequenceTmpl< SL3PM::ResourceName,MICO_TID_DEF> *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< SL3PM::ResourceName,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_SL3PM_ResourceName, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< SL3PM::ResourceName,MICO_TID_DEF> *&_s )
{
  return _a.to_static_any (_marshaller__seq_SL3PM_ResourceName, (void *&)_s);
}


class _Marshaller__seq_SL3PM_ScopedPrivileges : public ::CORBA::StaticTypeInfo {
    typedef SequenceTmpl< SL3PM::ScopedPrivileges,MICO_TID_DEF> _MICO_T;
    static ::CORBA::TypeCode_ptr _tc;
  public:
    ~_Marshaller__seq_SL3PM_ScopedPrivileges();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller__seq_SL3PM_ScopedPrivileges::~_Marshaller__seq_SL3PM_ScopedPrivileges()
{
  if (_tc)
    delete _tc;
}

::CORBA::StaticValueType _Marshaller__seq_SL3PM_ScopedPrivileges::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_SL3PM_ScopedPrivileges::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_SL3PM_ScopedPrivileges::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_SL3PM_ScopedPrivileges::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_SL3PM_ScopedPrivileges->demarshal( dc, &(*(_MICO_T*)v)[i] ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_SL3PM_ScopedPrivileges::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_SL3PM_ScopedPrivileges->marshal( ec, &(*(_MICO_T*)v)[i] );
  ec.seq_end();
}

::CORBA::TypeCode_ptr _Marshaller__seq_SL3PM_ScopedPrivileges::typecode()
{
  if (!_tc)
    _tc = (new ::CORBA::TypeCode (
    "0100000013000000bc030000010000000f000000ac030000010000002a00"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f53636f70656450"
    "726976696c656765733a312e300000001100000053636f70656450726976"
    "696c6567657300000000020000001400000070726976696c6567655f6175"
    "74686f72697479000f000000a0010000010000002700000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f5072696e636970616c4e616d653a31"
    "2e3000000e0000005072696e636970616c4e616d65000000020000000900"
    "00007468655f747970650000000015000000440000000100000022000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65547970653a"
    "312e30000000090000004e616d6554797065000000001200000000000000"
    "090000007468655f6e616d650000000015000000e4000000010000002300"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d6556616c"
    "75653a312e3000000a0000004e616d6556616c756500000015000000a000"
    "0000010000002200000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f4e616d65506174683a312e30000000090000004e616d65506174680000"
    "0000130000005c00000001000000150000004c0000000100000027000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65436f6d706f"
    "6e656e743a312e3000000e0000004e616d65436f6d706f6e656e74000000"
    "1b00000000000000000000000b00000070726976696c6567657300001500"
    "000084010000010000002b00000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f5072696e4174747269627574654c6973743a312e3000001200"
    "00005072696e4174747269627574654c6973740000001300000030010000"
    "010000000f00000020010000010000002700000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e4174747269627574653a312e300000"
    "0e0000005072696e41747472696275746500000002000000090000007468"
    "655f74797065000000001500000054000000010000002b00000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e417474726962757465"
    "547970653a312e300000120000005072696e417474726962757465547970"
    "6500000012000000000000000a0000007468655f76616c75650000001500"
    "000054000000010000002c00000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f5072696e41747472696275746556616c75653a312e30001300"
    "00005072696e41747472696275746556616c756500001b00000000000000"
    "0000000000000000"))->mk_constant();
  return _tc;
}

::CORBA::TypeCode_ptr _Marshaller__seq_SL3PM_ScopedPrivileges::_tc = 0;
::CORBA::StaticTypeInfo *_marshaller__seq_SL3PM_ScopedPrivileges;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< SL3PM::ScopedPrivileges,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_SL3PM_ScopedPrivileges, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SequenceTmpl< SL3PM::ScopedPrivileges,MICO_TID_DEF> *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< SL3PM::ScopedPrivileges,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_SL3PM_ScopedPrivileges, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< SL3PM::ScopedPrivileges,MICO_TID_DEF> *&_s )
{
  return _a.to_static_any (_marshaller__seq_SL3PM_ScopedPrivileges, (void *&)_s);
}


class _Marshaller__seq_SL3PM_Principal : public ::CORBA::StaticTypeInfo {
    typedef SequenceTmpl< SL3PM::Principal_var,MICO_TID_DEF> _MICO_T;
    static ::CORBA::TypeCode_ptr _tc;
  public:
    ~_Marshaller__seq_SL3PM_Principal();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller__seq_SL3PM_Principal::~_Marshaller__seq_SL3PM_Principal()
{
  if (_tc)
    delete _tc;
}

::CORBA::StaticValueType _Marshaller__seq_SL3PM_Principal::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_SL3PM_Principal::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_SL3PM_Principal::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_SL3PM_Principal::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_SL3PM_Principal->demarshal( dc, &(*(_MICO_T*)v)[i]._for_demarshal() ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_SL3PM_Principal::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_SL3PM_Principal->marshal( ec, &(*(_MICO_T*)v)[i].inout() );
  ec.seq_end();
}

::CORBA::TypeCode_ptr _Marshaller__seq_SL3PM_Principal::typecode()
{
  if (!_tc)
    _tc = (new ::CORBA::TypeCode (
    "0100000013000000ac060000010000001d0000009a060000010000002300"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970"
    "616c3a312e3000000a0000005072696e636970616c000000000000000300"
    "0000090000007468655f7479706500000000150000004800000001000000"
    "2700000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e63"
    "6970616c547970653a312e3000000e0000005072696e636970616c547970"
    "650000000500000001000000090000007468655f6e616d65000000000f00"
    "0000a0010000010000002700000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f5072696e636970616c4e616d653a312e3000000e0000005072"
    "696e636970616c4e616d6500000002000000090000007468655f74797065"
    "000000001500000044000000010000002200000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f4e616d65547970653a312e3000000009000000"
    "4e616d6554797065000000001200000000000000090000007468655f6e61"
    "6d650000000015000000e4000000010000002300000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f4e616d6556616c75653a312e3000000a00"
    "00004e616d6556616c756500000015000000a00000000100000022000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65506174683a"
    "312e30000000090000004e616d655061746800000000130000005c000000"
    "01000000150000004c000000010000002700000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f4e616d65436f6d706f6e656e743a312e300000"
    "0e0000004e616d65436f6d706f6e656e740000001b000000000000000000"
    "00000100000010000000776974685f70726976696c656765730015000000"
    "18040000010000002e00000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f53636f70656450726976696c656765734c6973743a312e30000000"
    "1500000053636f70656450726976696c656765734c697374000000001300"
    "0000bc030000010000000f000000ac030000010000002a00000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f53636f70656450726976696c65"
    "6765733a312e300000001100000053636f70656450726976696c65676573"
    "00000000020000001400000070726976696c6567655f617574686f726974"
    "79000f000000a0010000010000002700000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f5072696e636970616c4e616d653a312e3000000e00"
    "00005072696e636970616c4e616d6500000002000000090000007468655f"
    "74797065000000001500000044000000010000002200000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f4e616d65547970653a312e30000000"
    "090000004e616d6554797065000000001200000000000000090000007468"
    "655f6e616d650000000015000000e4000000010000002300000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f4e616d6556616c75653a312e30"
    "00000a0000004e616d6556616c756500000015000000a000000001000000"
    "2200000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d6550"
    "6174683a312e30000000090000004e616d65506174680000000013000000"
    "5c00000001000000150000004c000000010000002700000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f4e616d65436f6d706f6e656e743a31"
    "2e3000000e0000004e616d65436f6d706f6e656e740000001b0000000000"
    "0000000000000b00000070726976696c6567657300001500000084010000"
    "010000002b00000049444c3a616469726f6e2e636f6d2f534c33504d2f50"
    "72696e4174747269627574654c6973743a312e300000120000005072696e"
    "4174747269627574654c6973740000001300000030010000010000000f00"
    "000020010000010000002700000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f5072696e4174747269627574653a312e3000000e0000005072"
    "696e41747472696275746500000002000000090000007468655f74797065"
    "000000001500000054000000010000002b00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e417474726962757465547970653a31"
    "2e300000120000005072696e417474726962757465547970650000001200"
    "0000000000000a0000007468655f76616c75650000001500000054000000"
    "010000002c00000049444c3a616469726f6e2e636f6d2f534c33504d2f50"
    "72696e41747472696275746556616c75653a312e3000130000005072696e"
    "41747472696275746556616c756500001b00000000000000000000000000"
    "00000100000000000000"))->mk_constant();
  return _tc;
}

::CORBA::TypeCode_ptr _Marshaller__seq_SL3PM_Principal::_tc = 0;
::CORBA::StaticTypeInfo *_marshaller__seq_SL3PM_Principal;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< SL3PM::Principal_var,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_SL3PM_Principal, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SequenceTmpl< SL3PM::Principal_var,MICO_TID_DEF> *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< SL3PM::Principal_var,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_SL3PM_Principal, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< SL3PM::Principal_var,MICO_TID_DEF> *&_s )
{
  return _a.to_static_any (_marshaller__seq_SL3PM_Principal, (void *&)_s);
}


class _Marshaller__seq_SL3PM_Statement : public ::CORBA::StaticTypeInfo {
    typedef SequenceTmpl< SL3PM::Statement_var,MICO_TID_DEF> _MICO_T;
    static ::CORBA::TypeCode_ptr _tc;
  public:
    ~_Marshaller__seq_SL3PM_Statement();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller__seq_SL3PM_Statement::~_Marshaller__seq_SL3PM_Statement()
{
  if (_tc)
    delete _tc;
}

::CORBA::StaticValueType _Marshaller__seq_SL3PM_Statement::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_SL3PM_Statement::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_SL3PM_Statement::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_SL3PM_Statement::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_SL3PM_Statement->demarshal( dc, &(*(_MICO_T*)v)[i]._for_demarshal() ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_SL3PM_Statement::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_SL3PM_Statement->marshal( ec, &(*(_MICO_T*)v)[i].inout() );
  ec.seq_end();
}

::CORBA::TypeCode_ptr _Marshaller__seq_SL3PM_Statement::typecode()
{
  if (!_tc)
    _tc = (new ::CORBA::TypeCode (
    "0100000013000000f8010000010000001d000000e6010000010000002300"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f53746174656d65"
    "6e743a312e3000000a00000053746174656d656e74000000000000000400"
    "00000a0000007468655f6c61796572000000150000004800000001000000"
    "2800000049444c3a616469726f6e2e636f6d2f534c33504d2f5374617465"
    "6d656e744c617965723a312e30000f00000053746174656d656e744c6179"
    "657200000500000001000000090000007468655f74797065000000001500"
    "000048000000010000002700000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f53746174656d656e74547970653a312e3000000e0000005374"
    "6174656d656e745479706500000005000000010000000e000000656e636f"
    "64696e675f74797065000000150000004c00000001000000260000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f456e636f64696e67547970"
    "653a312e300000000d000000456e636f64696e6754797065000000001200"
    "000000000000000000000d0000007468655f656e636f64696e6700000000"
    "1500000050000000010000002200000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f456e636f64696e673a312e3000000009000000456e636f"
    "64696e6700000000130000000c000000010000000a000000000000000000"
    "000000000000"))->mk_constant();
  return _tc;
}

::CORBA::TypeCode_ptr _Marshaller__seq_SL3PM_Statement::_tc = 0;
::CORBA::StaticTypeInfo *_marshaller__seq_SL3PM_Statement;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< SL3PM::Statement_var,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_SL3PM_Statement, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SequenceTmpl< SL3PM::Statement_var,MICO_TID_DEF> *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< SL3PM::Statement_var,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_SL3PM_Statement, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< SL3PM::Statement_var,MICO_TID_DEF> *&_s )
{
  return _a.to_static_any (_marshaller__seq_SL3PM_Statement, (void *&)_s);
}


class _Marshaller__seq_SL3PM_X509IdentityStatement : public ::CORBA::StaticTypeInfo {
    typedef SequenceTmpl< SL3PM::X509IdentityStatement_var,MICO_TID_DEF> _MICO_T;
    static ::CORBA::TypeCode_ptr _tc;
  public:
    ~_Marshaller__seq_SL3PM_X509IdentityStatement();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller__seq_SL3PM_X509IdentityStatement::~_Marshaller__seq_SL3PM_X509IdentityStatement()
{
  if (_tc)
    delete _tc;
}

::CORBA::StaticValueType _Marshaller__seq_SL3PM_X509IdentityStatement::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_SL3PM_X509IdentityStatement::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_SL3PM_X509IdentityStatement::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_SL3PM_X509IdentityStatement::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_SL3PM_X509IdentityStatement->demarshal( dc, &(*(_MICO_T*)v)[i]._for_demarshal() ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_SL3PM_X509IdentityStatement::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_SL3PM_X509IdentityStatement->marshal( ec, &(*(_MICO_T*)v)[i].inout() );
  ec.seq_end();
}

::CORBA::TypeCode_ptr _Marshaller__seq_SL3PM_X509IdentityStatement::typecode()
{
  if (!_tc)
    _tc = (new ::CORBA::TypeCode (
    "0100000013000000f8090000010000001d000000e8090000010000002f00"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f58353039496465"
    "6e7469747953746174656d656e743a312e30000016000000583530394964"
    "656e7469747953746174656d656e740000001d0000008809000001000000"
    "3400000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e63"
    "6970616c4964656e7469747953746174656d656e743a312e30001b000000"
    "5072696e636970616c4964656e7469747953746174656d656e7400000000"
    "00001d00000062020000010000002b00000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f4964656e7469747953746174656d656e743a312e30"
    "0000120000004964656e7469747953746174656d656e740000001d000000"
    "e6010000010000002300000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f53746174656d656e743a312e3000000a00000053746174656d656e"
    "7400000000000000040000000a0000007468655f6c617965720000001500"
    "000048000000010000002800000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f53746174656d656e744c617965723a312e30000f0000005374"
    "6174656d656e744c6179657200000500000001000000090000007468655f"
    "74797065000000001500000048000000010000002700000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f53746174656d656e74547970653a31"
    "2e3000000e00000053746174656d656e7454797065000000050000000100"
    "00000e000000656e636f64696e675f74797065000000150000004c000000"
    "010000002600000049444c3a616469726f6e2e636f6d2f534c33504d2f45"
    "6e636f64696e67547970653a312e300000000d000000456e636f64696e67"
    "54797065000000001200000000000000000000000d0000007468655f656e"
    "636f64696e67000000001500000050000000010000002200000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f456e636f64696e673a312e3000"
    "000009000000456e636f64696e6700000000130000000c00000001000000"
    "0a00000000000000000000000100000013000000696e7465727072657461"
    "74696f6e5f6169640000120000000000000001000000010000000e000000"
    "7468655f7072696e636970616c0000001d0000009a060000010000002300"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970"
    "616c3a312e3000000a0000005072696e636970616c000000000000000300"
    "0000090000007468655f7479706500000000150000004800000001000000"
    "2700000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e63"
    "6970616c547970653a312e3000000e0000005072696e636970616c547970"
    "650000000500000001000000090000007468655f6e616d65000000000f00"
    "0000a0010000010000002700000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f5072696e636970616c4e616d653a312e3000000e0000005072"
    "696e636970616c4e616d6500000002000000090000007468655f74797065"
    "000000001500000044000000010000002200000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f4e616d65547970653a312e3000000009000000"
    "4e616d6554797065000000001200000000000000090000007468655f6e61"
    "6d650000000015000000e4000000010000002300000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f4e616d6556616c75653a312e3000000a00"
    "00004e616d6556616c756500000015000000a00000000100000022000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65506174683a"
    "312e30000000090000004e616d655061746800000000130000005c000000"
    "01000000150000004c000000010000002700000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f4e616d65436f6d706f6e656e743a312e300000"
    "0e0000004e616d65436f6d706f6e656e740000001b000000000000000000"
    "00000100000010000000776974685f70726976696c656765730015000000"
    "18040000010000002e00000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f53636f70656450726976696c656765734c6973743a312e30000000"
    "1500000053636f70656450726976696c656765734c697374000000001300"
    "0000bc030000010000000f000000ac030000010000002a00000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f53636f70656450726976696c65"
    "6765733a312e300000001100000053636f70656450726976696c65676573"
    "00000000020000001400000070726976696c6567655f617574686f726974"
    "79000f000000a0010000010000002700000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f5072696e636970616c4e616d653a312e3000000e00"
    "00005072696e636970616c4e616d6500000002000000090000007468655f"
    "74797065000000001500000044000000010000002200000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f4e616d65547970653a312e30000000"
    "090000004e616d6554797065000000001200000000000000090000007468"
    "655f6e616d650000000015000000e4000000010000002300000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f4e616d6556616c75653a312e30"
    "00000a0000004e616d6556616c756500000015000000a000000001000000"
    "2200000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d6550"
    "6174683a312e30000000090000004e616d65506174680000000013000000"
    "5c00000001000000150000004c000000010000002700000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f4e616d65436f6d706f6e656e743a31"
    "2e3000000e0000004e616d65436f6d706f6e656e740000001b0000000000"
    "0000000000000b00000070726976696c6567657300001500000084010000"
    "010000002b00000049444c3a616469726f6e2e636f6d2f534c33504d2f50"
    "72696e4174747269627574654c6973743a312e300000120000005072696e"
    "4174747269627574654c6973740000001300000030010000010000000f00"
    "000020010000010000002700000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f5072696e4174747269627574653a312e3000000e0000005072"
    "696e41747472696275746500000002000000090000007468655f74797065"
    "000000001500000054000000010000002b00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e417474726962757465547970653a31"
    "2e300000120000005072696e417474726962757465547970650000001200"
    "0000000000000a0000007468655f76616c75650000001500000054000000"
    "010000002c00000049444c3a616469726f6e2e636f6d2f534c33504d2f50"
    "72696e41747472696275746556616c75653a312e3000130000005072696e"
    "41747472696275746556616c756500001b00000000000000000000000000"
    "0000010001000000000000000000"))->mk_constant();
  return _tc;
}

::CORBA::TypeCode_ptr _Marshaller__seq_SL3PM_X509IdentityStatement::_tc = 0;
::CORBA::StaticTypeInfo *_marshaller__seq_SL3PM_X509IdentityStatement;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< SL3PM::X509IdentityStatement_var,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_SL3PM_X509IdentityStatement, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SequenceTmpl< SL3PM::X509IdentityStatement_var,MICO_TID_DEF> *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< SL3PM::X509IdentityStatement_var,MICO_TID_DEF> &_s )
{
  CORBA::StaticAny _sa (_marshaller__seq_SL3PM_X509IdentityStatement, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< SL3PM::X509IdentityStatement_var,MICO_TID_DEF> *&_s )
{
  return _a.to_static_any (_marshaller__seq_SL3PM_X509IdentityStatement, (void *&)_s);
}


struct __tc_init_SL3PM {
  __tc_init_SL3PM()
  {
    SL3PM::_tc_NameType = 
    "010000001500000044000000010000002200000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f4e616d65547970653a312e3000000009000000"
    "4e616d6554797065000000001200000000000000";
    SL3PM::_tc_NameComponent = 
    "01000000150000004c000000010000002700000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f4e616d65436f6d706f6e656e743a312e300000"
    "0e0000004e616d65436f6d706f6e656e740000001b00000000000000";
    SL3PM::_tc_NamePath = 
    "0100000015000000a0000000010000002200000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f4e616d65506174683a312e3000000009000000"
    "4e616d655061746800000000130000005c00000001000000150000004c00"
    "0000010000002700000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f4e616d65436f6d706f6e656e743a312e3000000e0000004e616d65436f"
    "6d706f6e656e740000001b0000000000000000000000";
    SL3PM::_tc_NameValue = 
    "0100000015000000e4000000010000002300000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f4e616d6556616c75653a312e3000000a000000"
    "4e616d6556616c756500000015000000a000000001000000220000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f4e616d65506174683a312e"
    "30000000090000004e616d655061746800000000130000005c0000000100"
    "0000150000004c000000010000002700000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f4e616d65436f6d706f6e656e743a312e3000000e00"
    "00004e616d65436f6d706f6e656e740000001b0000000000000000000000"
    ;
    SL3PM::_tc_PrincipalName = 
    "010000000f000000a0010000010000002700000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e636970616c4e616d653a312e300000"
    "0e0000005072696e636970616c4e616d6500000002000000090000007468"
    "655f74797065000000001500000044000000010000002200000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f4e616d65547970653a312e3000"
    "0000090000004e616d655479706500000000120000000000000009000000"
    "7468655f6e616d650000000015000000e400000001000000230000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f4e616d6556616c75653a31"
    "2e3000000a0000004e616d6556616c756500000015000000a00000000100"
    "00002200000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d"
    "65506174683a312e30000000090000004e616d6550617468000000001300"
    "00005c00000001000000150000004c000000010000002700000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f4e616d65436f6d706f6e656e74"
    "3a312e3000000e0000004e616d65436f6d706f6e656e740000001b000000"
    "0000000000000000";
    _marshaller_SL3PM_PrincipalName = new _Marshaller_SL3PM_PrincipalName;
    SL3PM::_tc_PrincipalNameList = 
    "010000001500000004020000010000002b00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e636970616c4e616d654c6973743a31"
    "2e300000120000005072696e636970616c4e616d654c6973740000001300"
    "0000b0010000010000000f000000a0010000010000002700000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e636970616c4e616d65"
    "3a312e3000000e0000005072696e636970616c4e616d6500000002000000"
    "090000007468655f74797065000000001500000044000000010000002200"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65547970"
    "653a312e30000000090000004e616d655479706500000000120000000000"
    "0000090000007468655f6e616d650000000015000000e400000001000000"
    "2300000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d6556"
    "616c75653a312e3000000a0000004e616d6556616c756500000015000000"
    "a0000000010000002200000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d65506174683a312e30000000090000004e616d6550617468"
    "00000000130000005c00000001000000150000004c000000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65436f6d"
    "706f6e656e743a312e3000000e0000004e616d65436f6d706f6e656e7400"
    "00001b000000000000000000000000000000";
    SL3PM::_tc_PrinAttributeType = 
    "010000001500000054000000010000002b00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e417474726962757465547970653a31"
    "2e300000120000005072696e417474726962757465547970650000001200"
    "000000000000";
    SL3PM::_tc_PrinAttributeValue = 
    "010000001500000054000000010000002c00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e41747472696275746556616c75653a"
    "312e3000130000005072696e41747472696275746556616c756500001b00"
    "000000000000";
    SL3PM::_tc_PrinAttribute = 
    "010000000f00000020010000010000002700000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e4174747269627574653a312e300000"
    "0e0000005072696e41747472696275746500000002000000090000007468"
    "655f74797065000000001500000054000000010000002b00000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e417474726962757465"
    "547970653a312e300000120000005072696e417474726962757465547970"
    "6500000012000000000000000a0000007468655f76616c75650000001500"
    "000054000000010000002c00000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f5072696e41747472696275746556616c75653a312e30001300"
    "00005072696e41747472696275746556616c756500001b00000000000000"
    ;
    _marshaller_SL3PM_PrinAttribute = new _Marshaller_SL3PM_PrinAttribute;
    SL3PM::_tc_PrinAttributeList = 
    "010000001500000084010000010000002b00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e4174747269627574654c6973743a31"
    "2e300000120000005072696e4174747269627574654c6973740000001300"
    "000030010000010000000f00000020010000010000002700000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e417474726962757465"
    "3a312e3000000e0000005072696e41747472696275746500000002000000"
    "090000007468655f74797065000000001500000054000000010000002b00"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e417474"
    "726962757465547970653a312e300000120000005072696e417474726962"
    "7574655479706500000012000000000000000a0000007468655f76616c75"
    "650000001500000054000000010000002c00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e41747472696275746556616c75653a"
    "312e3000130000005072696e41747472696275746556616c756500001b00"
    "00000000000000000000";
    SL3PM::_tc_ResourceName = 
    "010000000f00000070000000010000002600000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5265736f757263654e616d653a312e30000000"
    "0d0000005265736f757263654e616d6500000000010000000b000000636f"
    "6d706f6e656e747300001300000010000000010000001200000000000000"
    "00000000";
    _marshaller_SL3PM_ResourceName = new _Marshaller_SL3PM_ResourceName;
    SL3PM::_tc_ResourceNameList = 
    "0100000015000000d4000000010000002a00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5265736f757263654e616d654c6973743a312e"
    "30000000110000005265736f757263654e616d654c697374000000001300"
    "000080000000010000000f00000070000000010000002600000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5265736f757263654e616d653a"
    "312e300000000d0000005265736f757263654e616d650000000001000000"
    "0b000000636f6d706f6e656e747300001300000010000000010000001200"
    "0000000000000000000000000000";
    SL3PM::_tc_ScopedPrivileges = 
    "010000000f000000ac030000010000002a00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f53636f70656450726976696c656765733a312e"
    "300000001100000053636f70656450726976696c65676573000000000200"
    "00001400000070726976696c6567655f617574686f72697479000f000000"
    "a0010000010000002700000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f5072696e636970616c4e616d653a312e3000000e0000005072696e"
    "636970616c4e616d6500000002000000090000007468655f747970650000"
    "00001500000044000000010000002200000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f4e616d65547970653a312e30000000090000004e61"
    "6d6554797065000000001200000000000000090000007468655f6e616d65"
    "0000000015000000e4000000010000002300000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f4e616d6556616c75653a312e3000000a000000"
    "4e616d6556616c756500000015000000a000000001000000220000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f4e616d65506174683a312e"
    "30000000090000004e616d655061746800000000130000005c0000000100"
    "0000150000004c000000010000002700000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f4e616d65436f6d706f6e656e743a312e3000000e00"
    "00004e616d65436f6d706f6e656e740000001b0000000000000000000000"
    "0b00000070726976696c6567657300001500000084010000010000002b00"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e417474"
    "7269627574654c6973743a312e300000120000005072696e417474726962"
    "7574654c6973740000001300000030010000010000000f00000020010000"
    "010000002700000049444c3a616469726f6e2e636f6d2f534c33504d2f50"
    "72696e4174747269627574653a312e3000000e0000005072696e41747472"
    "696275746500000002000000090000007468655f74797065000000001500"
    "000054000000010000002b00000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f5072696e417474726962757465547970653a312e3000001200"
    "00005072696e417474726962757465547970650000001200000000000000"
    "0a0000007468655f76616c75650000001500000054000000010000002c00"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e417474"
    "72696275746556616c75653a312e3000130000005072696e417474726962"
    "75746556616c756500001b0000000000000000000000";
    _marshaller_SL3PM_ScopedPrivileges = new _Marshaller_SL3PM_ScopedPrivileges;
    SL3PM::_tc_ScopedPrivilegesList = 
    "010000001500000018040000010000002e00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f53636f70656450726976696c656765734c6973"
    "743a312e300000001500000053636f70656450726976696c656765734c69"
    "73740000000013000000bc030000010000000f000000ac03000001000000"
    "2a00000049444c3a616469726f6e2e636f6d2f534c33504d2f53636f7065"
    "6450726976696c656765733a312e300000001100000053636f7065645072"
    "6976696c6567657300000000020000001400000070726976696c6567655f"
    "617574686f72697479000f000000a0010000010000002700000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e636970616c4e616d65"
    "3a312e3000000e0000005072696e636970616c4e616d6500000002000000"
    "090000007468655f74797065000000001500000044000000010000002200"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65547970"
    "653a312e30000000090000004e616d655479706500000000120000000000"
    "0000090000007468655f6e616d650000000015000000e400000001000000"
    "2300000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d6556"
    "616c75653a312e3000000a0000004e616d6556616c756500000015000000"
    "a0000000010000002200000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d65506174683a312e30000000090000004e616d6550617468"
    "00000000130000005c00000001000000150000004c000000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65436f6d"
    "706f6e656e743a312e3000000e0000004e616d65436f6d706f6e656e7400"
    "00001b00000000000000000000000b00000070726976696c656765730000"
    "1500000084010000010000002b00000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f5072696e4174747269627574654c6973743a312e300000"
    "120000005072696e4174747269627574654c697374000000130000003001"
    "0000010000000f00000020010000010000002700000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f5072696e4174747269627574653a312e30"
    "00000e0000005072696e4174747269627574650000000200000009000000"
    "7468655f74797065000000001500000054000000010000002b0000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f5072696e41747472696275"
    "7465547970653a312e300000120000005072696e41747472696275746554"
    "79706500000012000000000000000a0000007468655f76616c7565000000"
    "1500000054000000010000002c00000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f5072696e41747472696275746556616c75653a312e3000"
    "130000005072696e41747472696275746556616c756500001b0000000000"
    "00000000000000000000";
    SL3PM::_tc_PrincipalType = 
    "010000001500000048000000010000002700000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e636970616c547970653a312e300000"
    "0e0000005072696e636970616c5479706500000005000000";
    SL3PM::_tc_Principal = 
    "010000001d0000009a060000010000002300000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e636970616c3a312e3000000a000000"
    "5072696e636970616c0000000000000003000000090000007468655f7479"
    "7065000000001500000048000000010000002700000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f5072696e636970616c547970653a312e30"
    "00000e0000005072696e636970616c547970650000000500000001000000"
    "090000007468655f6e616d65000000000f000000a0010000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970"
    "616c4e616d653a312e3000000e0000005072696e636970616c4e616d6500"
    "000002000000090000007468655f74797065000000001500000044000000"
    "010000002200000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d65547970653a312e30000000090000004e616d655479706500000000"
    "1200000000000000090000007468655f6e616d650000000015000000e400"
    "0000010000002300000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f4e616d6556616c75653a312e3000000a0000004e616d6556616c756500"
    "000015000000a0000000010000002200000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f4e616d65506174683a312e30000000090000004e61"
    "6d655061746800000000130000005c00000001000000150000004c000000"
    "010000002700000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d65436f6d706f6e656e743a312e3000000e0000004e616d65436f6d70"
    "6f6e656e740000001b000000000000000000000001000000100000007769"
    "74685f70726976696c65676573001500000018040000010000002e000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f53636f706564507269"
    "76696c656765734c6973743a312e300000001500000053636f7065645072"
    "6976696c656765734c6973740000000013000000bc030000010000000f00"
    "0000ac030000010000002a00000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f53636f70656450726976696c656765733a312e300000001100"
    "000053636f70656450726976696c65676573000000000200000014000000"
    "70726976696c6567655f617574686f72697479000f000000a00100000100"
    "00002700000049444c3a616469726f6e2e636f6d2f534c33504d2f507269"
    "6e636970616c4e616d653a312e3000000e0000005072696e636970616c4e"
    "616d6500000002000000090000007468655f747970650000000015000000"
    "44000000010000002200000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d65547970653a312e30000000090000004e616d6554797065"
    "000000001200000000000000090000007468655f6e616d65000000001500"
    "0000e4000000010000002300000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f4e616d6556616c75653a312e3000000a0000004e616d655661"
    "6c756500000015000000a0000000010000002200000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f4e616d65506174683a312e300000000900"
    "00004e616d655061746800000000130000005c0000000100000015000000"
    "4c000000010000002700000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d65436f6d706f6e656e743a312e3000000e0000004e616d65"
    "436f6d706f6e656e740000001b00000000000000000000000b0000007072"
    "6976696c6567657300001500000084010000010000002b00000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e417474726962757465"
    "4c6973743a312e300000120000005072696e4174747269627574654c6973"
    "740000001300000030010000010000000f00000020010000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e417474"
    "7269627574653a312e3000000e0000005072696e41747472696275746500"
    "000002000000090000007468655f74797065000000001500000054000000"
    "010000002b00000049444c3a616469726f6e2e636f6d2f534c33504d2f50"
    "72696e417474726962757465547970653a312e300000120000005072696e"
    "4174747269627574655479706500000012000000000000000a0000007468"
    "655f76616c75650000001500000054000000010000002c00000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e417474726962757465"
    "56616c75653a312e3000130000005072696e41747472696275746556616c"
    "756500001b0000000000000000000000000000000100";
    _marshaller_SL3PM_Principal = new _Marshaller_SL3PM_Principal;
    SL3PM::_tc_PrincipalList = 
    "0100000015000000f8060000010000002700000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e636970616c4c6973743a312e300000"
    "0e0000005072696e636970616c4c69737400000013000000ac0600000100"
    "00001d0000009a060000010000002300000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f5072696e636970616c3a312e3000000a0000005072"
    "696e636970616c0000000000000003000000090000007468655f74797065"
    "000000001500000048000000010000002700000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e636970616c547970653a312e300000"
    "0e0000005072696e636970616c5479706500000005000000010000000900"
    "00007468655f6e616d65000000000f000000a00100000100000027000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970616c"
    "4e616d653a312e3000000e0000005072696e636970616c4e616d65000000"
    "02000000090000007468655f747970650000000015000000440000000100"
    "00002200000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d"
    "65547970653a312e30000000090000004e616d6554797065000000001200"
    "000000000000090000007468655f6e616d650000000015000000e4000000"
    "010000002300000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d6556616c75653a312e3000000a0000004e616d6556616c7565000000"
    "15000000a0000000010000002200000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f4e616d65506174683a312e30000000090000004e616d65"
    "5061746800000000130000005c00000001000000150000004c0000000100"
    "00002700000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d"
    "65436f6d706f6e656e743a312e3000000e0000004e616d65436f6d706f6e"
    "656e740000001b0000000000000000000000010000001000000077697468"
    "5f70726976696c65676573001500000018040000010000002e0000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f53636f7065645072697669"
    "6c656765734c6973743a312e300000001500000053636f70656450726976"
    "696c656765734c6973740000000013000000bc030000010000000f000000"
    "ac030000010000002a00000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f53636f70656450726976696c656765733a312e3000000011000000"
    "53636f70656450726976696c656765730000000002000000140000007072"
    "6976696c6567655f617574686f72697479000f000000a001000001000000"
    "2700000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e63"
    "6970616c4e616d653a312e3000000e0000005072696e636970616c4e616d"
    "6500000002000000090000007468655f7479706500000000150000004400"
    "0000010000002200000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f4e616d65547970653a312e30000000090000004e616d65547970650000"
    "00001200000000000000090000007468655f6e616d650000000015000000"
    "e4000000010000002300000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d6556616c75653a312e3000000a0000004e616d6556616c75"
    "6500000015000000a0000000010000002200000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f4e616d65506174683a312e3000000009000000"
    "4e616d655061746800000000130000005c00000001000000150000004c00"
    "0000010000002700000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f4e616d65436f6d706f6e656e743a312e3000000e0000004e616d65436f"
    "6d706f6e656e740000001b00000000000000000000000b00000070726976"
    "696c6567657300001500000084010000010000002b00000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f5072696e4174747269627574654c69"
    "73743a312e300000120000005072696e4174747269627574654c69737400"
    "00001300000030010000010000000f000000200100000100000027000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f5072696e4174747269"
    "627574653a312e3000000e0000005072696e417474726962757465000000"
    "02000000090000007468655f747970650000000015000000540000000100"
    "00002b00000049444c3a616469726f6e2e636f6d2f534c33504d2f507269"
    "6e417474726962757465547970653a312e300000120000005072696e4174"
    "747269627574655479706500000012000000000000000a0000007468655f"
    "76616c75650000001500000054000000010000002c00000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f5072696e4174747269627574655661"
    "6c75653a312e3000130000005072696e41747472696275746556616c7565"
    "00001b0000000000000000000000000000000100000000000000";
    SL3PM::_tc_SimplePrincipal = 
    "010000001d00000032090000010000002900000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f53696d706c655072696e636970616c3a312e30"
    "000000001000000053696d706c655072696e636970616c00030000001d00"
    "00009a060000010000002300000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f5072696e636970616c3a312e3000000a0000005072696e6369"
    "70616c0000000000000003000000090000007468655f7479706500000000"
    "1500000048000000010000002700000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f5072696e636970616c547970653a312e3000000e000000"
    "5072696e636970616c547970650000000500000001000000090000007468"
    "655f6e616d65000000000f000000a0010000010000002700000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e636970616c4e616d65"
    "3a312e3000000e0000005072696e636970616c4e616d6500000002000000"
    "090000007468655f74797065000000001500000044000000010000002200"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65547970"
    "653a312e30000000090000004e616d655479706500000000120000000000"
    "0000090000007468655f6e616d650000000015000000e400000001000000"
    "2300000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d6556"
    "616c75653a312e3000000a0000004e616d6556616c756500000015000000"
    "a0000000010000002200000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d65506174683a312e30000000090000004e616d6550617468"
    "00000000130000005c00000001000000150000004c000000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65436f6d"
    "706f6e656e743a312e3000000e0000004e616d65436f6d706f6e656e7400"
    "00001b00000000000000000000000100000010000000776974685f707269"
    "76696c65676573001500000018040000010000002e00000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f53636f70656450726976696c656765"
    "734c6973743a312e300000001500000053636f70656450726976696c6567"
    "65734c6973740000000013000000bc030000010000000f000000ac030000"
    "010000002a00000049444c3a616469726f6e2e636f6d2f534c33504d2f53"
    "636f70656450726976696c656765733a312e300000001100000053636f70"
    "656450726976696c6567657300000000020000001400000070726976696c"
    "6567655f617574686f72697479000f000000a00100000100000027000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970616c"
    "4e616d653a312e3000000e0000005072696e636970616c4e616d65000000"
    "02000000090000007468655f747970650000000015000000440000000100"
    "00002200000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d"
    "65547970653a312e30000000090000004e616d6554797065000000001200"
    "000000000000090000007468655f6e616d650000000015000000e4000000"
    "010000002300000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d6556616c75653a312e3000000a0000004e616d6556616c7565000000"
    "15000000a0000000010000002200000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f4e616d65506174683a312e30000000090000004e616d65"
    "5061746800000000130000005c00000001000000150000004c0000000100"
    "00002700000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d"
    "65436f6d706f6e656e743a312e3000000e0000004e616d65436f6d706f6e"
    "656e740000001b00000000000000000000000b00000070726976696c6567"
    "657300001500000084010000010000002b00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e4174747269627574654c6973743a31"
    "2e300000120000005072696e4174747269627574654c6973740000001300"
    "000030010000010000000f00000020010000010000002700000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e417474726962757465"
    "3a312e3000000e0000005072696e41747472696275746500000002000000"
    "090000007468655f74797065000000001500000054000000010000002b00"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e417474"
    "726962757465547970653a312e300000120000005072696e417474726962"
    "7574655479706500000012000000000000000a0000007468655f76616c75"
    "650000001500000054000000010000002c00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e41747472696275746556616c75653a"
    "312e3000130000005072696e41747472696275746556616c756500001b00"
    "000000000000000000000000000001000000020000000e00000061757468"
    "656e74696361746564000000080000000100000010000000616c7465726e"
    "6174655f6e616d6573001500000004020000010000002b00000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e636970616c4e616d65"
    "4c6973743a312e300000120000005072696e636970616c4e616d654c6973"
    "7400000013000000b0010000010000000f000000a0010000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970"
    "616c4e616d653a312e3000000e0000005072696e636970616c4e616d6500"
    "000002000000090000007468655f74797065000000001500000044000000"
    "010000002200000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d65547970653a312e30000000090000004e616d655479706500000000"
    "1200000000000000090000007468655f6e616d650000000015000000e400"
    "0000010000002300000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f4e616d6556616c75653a312e3000000a0000004e616d6556616c756500"
    "000015000000a0000000010000002200000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f4e616d65506174683a312e30000000090000004e61"
    "6d655061746800000000130000005c00000001000000150000004c000000"
    "010000002700000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d65436f6d706f6e656e743a312e3000000e0000004e616d65436f6d70"
    "6f6e656e740000001b0000000000000000000000000000000100";
    _marshaller_SL3PM_SimplePrincipal = new _Marshaller_SL3PM_SimplePrincipal;
    SL3PM::_tc_ProxyPrincipal = 
    "010000001d00000058140000010000002800000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f50726f78795072696e636970616c3a312e3000"
    "0f00000050726f78795072696e636970616c0000030000001d0000009a06"
    "0000010000002300000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f5072696e636970616c3a312e3000000a0000005072696e636970616c00"
    "00000000000003000000090000007468655f747970650000000015000000"
    "48000000010000002700000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f5072696e636970616c547970653a312e3000000e0000005072696e"
    "636970616c547970650000000500000001000000090000007468655f6e61"
    "6d65000000000f000000a0010000010000002700000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f5072696e636970616c4e616d653a312e30"
    "00000e0000005072696e636970616c4e616d650000000200000009000000"
    "7468655f7479706500000000150000004400000001000000220000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f4e616d65547970653a312e"
    "30000000090000004e616d65547970650000000012000000000000000900"
    "00007468655f6e616d650000000015000000e40000000100000023000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f4e616d6556616c7565"
    "3a312e3000000a0000004e616d6556616c756500000015000000a0000000"
    "010000002200000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d65506174683a312e30000000090000004e616d655061746800000000"
    "130000005c00000001000000150000004c00000001000000270000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f4e616d65436f6d706f6e65"
    "6e743a312e3000000e0000004e616d65436f6d706f6e656e740000001b00"
    "000000000000000000000100000010000000776974685f70726976696c65"
    "676573001500000018040000010000002e00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f53636f70656450726976696c656765734c6973"
    "743a312e300000001500000053636f70656450726976696c656765734c69"
    "73740000000013000000bc030000010000000f000000ac03000001000000"
    "2a00000049444c3a616469726f6e2e636f6d2f534c33504d2f53636f7065"
    "6450726976696c656765733a312e300000001100000053636f7065645072"
    "6976696c6567657300000000020000001400000070726976696c6567655f"
    "617574686f72697479000f000000a0010000010000002700000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e636970616c4e616d65"
    "3a312e3000000e0000005072696e636970616c4e616d6500000002000000"
    "090000007468655f74797065000000001500000044000000010000002200"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65547970"
    "653a312e30000000090000004e616d655479706500000000120000000000"
    "0000090000007468655f6e616d650000000015000000e400000001000000"
    "2300000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d6556"
    "616c75653a312e3000000a0000004e616d6556616c756500000015000000"
    "a0000000010000002200000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d65506174683a312e30000000090000004e616d6550617468"
    "00000000130000005c00000001000000150000004c000000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65436f6d"
    "706f6e656e743a312e3000000e0000004e616d65436f6d706f6e656e7400"
    "00001b00000000000000000000000b00000070726976696c656765730000"
    "1500000084010000010000002b00000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f5072696e4174747269627574654c6973743a312e300000"
    "120000005072696e4174747269627574654c697374000000130000003001"
    "0000010000000f00000020010000010000002700000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f5072696e4174747269627574653a312e30"
    "00000e0000005072696e4174747269627574650000000200000009000000"
    "7468655f74797065000000001500000054000000010000002b0000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f5072696e41747472696275"
    "7465547970653a312e300000120000005072696e41747472696275746554"
    "79706500000012000000000000000a0000007468655f76616c7565000000"
    "1500000054000000010000002c00000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f5072696e41747472696275746556616c75653a312e3000"
    "130000005072696e41747472696275746556616c756500001b0000000000"
    "00000000000000000000010000000200000009000000737065616b696e67"
    "000000001d0000009a060000010000002300000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e636970616c3a312e3000000a000000"
    "5072696e636970616c0000000000000003000000090000007468655f7479"
    "7065000000001500000048000000010000002700000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f5072696e636970616c547970653a312e30"
    "00000e0000005072696e636970616c547970650000000500000001000000"
    "090000007468655f6e616d65000000000f000000a0010000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970"
    "616c4e616d653a312e3000000e0000005072696e636970616c4e616d6500"
    "000002000000090000007468655f74797065000000001500000044000000"
    "010000002200000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d65547970653a312e30000000090000004e616d655479706500000000"
    "1200000000000000090000007468655f6e616d650000000015000000e400"
    "0000010000002300000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f4e616d6556616c75653a312e3000000a0000004e616d6556616c756500"
    "000015000000a0000000010000002200000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f4e616d65506174683a312e30000000090000004e61"
    "6d655061746800000000130000005c00000001000000150000004c000000"
    "010000002700000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d65436f6d706f6e656e743a312e3000000e0000004e616d65436f6d70"
    "6f6e656e740000001b000000000000000000000001000000100000007769"
    "74685f70726976696c65676573001500000018040000010000002e000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f53636f706564507269"
    "76696c656765734c6973743a312e300000001500000053636f7065645072"
    "6976696c656765734c6973740000000013000000bc030000010000000f00"
    "0000ac030000010000002a00000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f53636f70656450726976696c656765733a312e300000001100"
    "000053636f70656450726976696c65676573000000000200000014000000"
    "70726976696c6567655f617574686f72697479000f000000a00100000100"
    "00002700000049444c3a616469726f6e2e636f6d2f534c33504d2f507269"
    "6e636970616c4e616d653a312e3000000e0000005072696e636970616c4e"
    "616d6500000002000000090000007468655f747970650000000015000000"
    "44000000010000002200000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d65547970653a312e30000000090000004e616d6554797065"
    "000000001200000000000000090000007468655f6e616d65000000001500"
    "0000e4000000010000002300000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f4e616d6556616c75653a312e3000000a0000004e616d655661"
    "6c756500000015000000a0000000010000002200000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f4e616d65506174683a312e300000000900"
    "00004e616d655061746800000000130000005c0000000100000015000000"
    "4c000000010000002700000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d65436f6d706f6e656e743a312e3000000e0000004e616d65"
    "436f6d706f6e656e740000001b00000000000000000000000b0000007072"
    "6976696c6567657300001500000084010000010000002b00000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e417474726962757465"
    "4c6973743a312e300000120000005072696e4174747269627574654c6973"
    "740000001300000030010000010000000f00000020010000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e417474"
    "7269627574653a312e3000000e0000005072696e41747472696275746500"
    "000002000000090000007468655f74797065000000001500000054000000"
    "010000002b00000049444c3a616469726f6e2e636f6d2f534c33504d2f50"
    "72696e417474726962757465547970653a312e300000120000005072696e"
    "4174747269627574655479706500000012000000000000000a0000007468"
    "655f76616c75650000001500000054000000010000002c00000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e417474726962757465"
    "56616c75653a312e3000130000005072696e41747472696275746556616c"
    "756500001b000000000000000000000000000000010001000b0000007370"
    "65616b735f666f7200001d0000009a060000010000002300000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e636970616c3a312e30"
    "00000a0000005072696e636970616c000000000000000300000009000000"
    "7468655f7479706500000000150000004800000001000000270000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970616c5479"
    "70653a312e3000000e0000005072696e636970616c547970650000000500"
    "000001000000090000007468655f6e616d65000000000f000000a0010000"
    "010000002700000049444c3a616469726f6e2e636f6d2f534c33504d2f50"
    "72696e636970616c4e616d653a312e3000000e0000005072696e63697061"
    "6c4e616d6500000002000000090000007468655f74797065000000001500"
    "000044000000010000002200000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f4e616d65547970653a312e30000000090000004e616d655479"
    "7065000000001200000000000000090000007468655f6e616d6500000000"
    "15000000e4000000010000002300000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f4e616d6556616c75653a312e3000000a0000004e616d65"
    "56616c756500000015000000a0000000010000002200000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f4e616d65506174683a312e30000000"
    "090000004e616d655061746800000000130000005c000000010000001500"
    "00004c000000010000002700000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f4e616d65436f6d706f6e656e743a312e3000000e0000004e61"
    "6d65436f6d706f6e656e740000001b000000000000000000000001000000"
    "10000000776974685f70726976696c656765730015000000180400000100"
    "00002e00000049444c3a616469726f6e2e636f6d2f534c33504d2f53636f"
    "70656450726976696c656765734c6973743a312e30000000150000005363"
    "6f70656450726976696c656765734c6973740000000013000000bc030000"
    "010000000f000000ac030000010000002a00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f53636f70656450726976696c656765733a312e"
    "300000001100000053636f70656450726976696c65676573000000000200"
    "00001400000070726976696c6567655f617574686f72697479000f000000"
    "a0010000010000002700000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f5072696e636970616c4e616d653a312e3000000e0000005072696e"
    "636970616c4e616d6500000002000000090000007468655f747970650000"
    "00001500000044000000010000002200000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f4e616d65547970653a312e30000000090000004e61"
    "6d6554797065000000001200000000000000090000007468655f6e616d65"
    "0000000015000000e4000000010000002300000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f4e616d6556616c75653a312e3000000a000000"
    "4e616d6556616c756500000015000000a000000001000000220000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f4e616d65506174683a312e"
    "30000000090000004e616d655061746800000000130000005c0000000100"
    "0000150000004c000000010000002700000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f4e616d65436f6d706f6e656e743a312e3000000e00"
    "00004e616d65436f6d706f6e656e740000001b0000000000000000000000"
    "0b00000070726976696c6567657300001500000084010000010000002b00"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e417474"
    "7269627574654c6973743a312e300000120000005072696e417474726962"
    "7574654c6973740000001300000030010000010000000f00000020010000"
    "010000002700000049444c3a616469726f6e2e636f6d2f534c33504d2f50"
    "72696e4174747269627574653a312e3000000e0000005072696e41747472"
    "696275746500000002000000090000007468655f74797065000000001500"
    "000054000000010000002b00000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f5072696e417474726962757465547970653a312e3000001200"
    "00005072696e417474726962757465547970650000001200000000000000"
    "0a0000007468655f76616c75650000001500000054000000010000002c00"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e417474"
    "72696275746556616c75653a312e3000130000005072696e417474726962"
    "75746556616c756500001b00000000000000000000000000000001000100"
    ;
    _marshaller_SL3PM_ProxyPrincipal = new _Marshaller_SL3PM_ProxyPrincipal;
    SL3PM::_tc_QuotingPrincipal = 
    "010000001d0000005c140000010000002a00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f51756f74696e675072696e636970616c3a312e"
    "300000001100000051756f74696e675072696e636970616c000003001d00"
    "00009a060000010000002300000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f5072696e636970616c3a312e3000000a0000005072696e6369"
    "70616c0000000000000003000000090000007468655f7479706500000000"
    "1500000048000000010000002700000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f5072696e636970616c547970653a312e3000000e000000"
    "5072696e636970616c547970650000000500000001000000090000007468"
    "655f6e616d65000000000f000000a0010000010000002700000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e636970616c4e616d65"
    "3a312e3000000e0000005072696e636970616c4e616d6500000002000000"
    "090000007468655f74797065000000001500000044000000010000002200"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65547970"
    "653a312e30000000090000004e616d655479706500000000120000000000"
    "0000090000007468655f6e616d650000000015000000e400000001000000"
    "2300000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d6556"
    "616c75653a312e3000000a0000004e616d6556616c756500000015000000"
    "a0000000010000002200000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d65506174683a312e30000000090000004e616d6550617468"
    "00000000130000005c00000001000000150000004c000000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65436f6d"
    "706f6e656e743a312e3000000e0000004e616d65436f6d706f6e656e7400"
    "00001b00000000000000000000000100000010000000776974685f707269"
    "76696c65676573001500000018040000010000002e00000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f53636f70656450726976696c656765"
    "734c6973743a312e300000001500000053636f70656450726976696c6567"
    "65734c6973740000000013000000bc030000010000000f000000ac030000"
    "010000002a00000049444c3a616469726f6e2e636f6d2f534c33504d2f53"
    "636f70656450726976696c656765733a312e300000001100000053636f70"
    "656450726976696c6567657300000000020000001400000070726976696c"
    "6567655f617574686f72697479000f000000a00100000100000027000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970616c"
    "4e616d653a312e3000000e0000005072696e636970616c4e616d65000000"
    "02000000090000007468655f747970650000000015000000440000000100"
    "00002200000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d"
    "65547970653a312e30000000090000004e616d6554797065000000001200"
    "000000000000090000007468655f6e616d650000000015000000e4000000"
    "010000002300000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d6556616c75653a312e3000000a0000004e616d6556616c7565000000"
    "15000000a0000000010000002200000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f4e616d65506174683a312e30000000090000004e616d65"
    "5061746800000000130000005c00000001000000150000004c0000000100"
    "00002700000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d"
    "65436f6d706f6e656e743a312e3000000e0000004e616d65436f6d706f6e"
    "656e740000001b00000000000000000000000b00000070726976696c6567"
    "657300001500000084010000010000002b00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e4174747269627574654c6973743a31"
    "2e300000120000005072696e4174747269627574654c6973740000001300"
    "000030010000010000000f00000020010000010000002700000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e417474726962757465"
    "3a312e3000000e0000005072696e41747472696275746500000002000000"
    "090000007468655f74797065000000001500000054000000010000002b00"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e417474"
    "726962757465547970653a312e300000120000005072696e417474726962"
    "7574655479706500000012000000000000000a0000007468655f76616c75"
    "650000001500000054000000010000002c00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e41747472696275746556616c75653a"
    "312e3000130000005072696e41747472696275746556616c756500001b00"
    "000000000000000000000000000001000000020000000900000073706561"
    "6b696e67000000001d0000009a060000010000002300000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f5072696e636970616c3a312e300000"
    "0a0000005072696e636970616c0000000000000003000000090000007468"
    "655f74797065000000001500000048000000010000002700000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e636970616c54797065"
    "3a312e3000000e0000005072696e636970616c5479706500000005000000"
    "01000000090000007468655f6e616d65000000000f000000a00100000100"
    "00002700000049444c3a616469726f6e2e636f6d2f534c33504d2f507269"
    "6e636970616c4e616d653a312e3000000e0000005072696e636970616c4e"
    "616d6500000002000000090000007468655f747970650000000015000000"
    "44000000010000002200000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d65547970653a312e30000000090000004e616d6554797065"
    "000000001200000000000000090000007468655f6e616d65000000001500"
    "0000e4000000010000002300000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f4e616d6556616c75653a312e3000000a0000004e616d655661"
    "6c756500000015000000a0000000010000002200000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f4e616d65506174683a312e300000000900"
    "00004e616d655061746800000000130000005c0000000100000015000000"
    "4c000000010000002700000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d65436f6d706f6e656e743a312e3000000e0000004e616d65"
    "436f6d706f6e656e740000001b0000000000000000000000010000001000"
    "0000776974685f70726976696c6567657300150000001804000001000000"
    "2e00000049444c3a616469726f6e2e636f6d2f534c33504d2f53636f7065"
    "6450726976696c656765734c6973743a312e300000001500000053636f70"
    "656450726976696c656765734c6973740000000013000000bc0300000100"
    "00000f000000ac030000010000002a00000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f53636f70656450726976696c656765733a312e3000"
    "00001100000053636f70656450726976696c656765730000000002000000"
    "1400000070726976696c6567655f617574686f72697479000f000000a001"
    "0000010000002700000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f5072696e636970616c4e616d653a312e3000000e0000005072696e6369"
    "70616c4e616d6500000002000000090000007468655f7479706500000000"
    "1500000044000000010000002200000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f4e616d65547970653a312e30000000090000004e616d65"
    "54797065000000001200000000000000090000007468655f6e616d650000"
    "000015000000e4000000010000002300000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f4e616d6556616c75653a312e3000000a0000004e61"
    "6d6556616c756500000015000000a0000000010000002200000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f4e616d65506174683a312e3000"
    "0000090000004e616d655061746800000000130000005c00000001000000"
    "150000004c000000010000002700000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f4e616d65436f6d706f6e656e743a312e3000000e000000"
    "4e616d65436f6d706f6e656e740000001b00000000000000000000000b00"
    "000070726976696c6567657300001500000084010000010000002b000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f5072696e4174747269"
    "627574654c6973743a312e300000120000005072696e4174747269627574"
    "654c6973740000001300000030010000010000000f000000200100000100"
    "00002700000049444c3a616469726f6e2e636f6d2f534c33504d2f507269"
    "6e4174747269627574653a312e3000000e0000005072696e417474726962"
    "75746500000002000000090000007468655f747970650000000015000000"
    "54000000010000002b00000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f5072696e417474726962757465547970653a312e30000012000000"
    "5072696e4174747269627574655479706500000012000000000000000a00"
    "00007468655f76616c75650000001500000054000000010000002c000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f5072696e4174747269"
    "6275746556616c75653a312e3000130000005072696e4174747269627574"
    "6556616c756500001b000000000000000000000000000000010001000b00"
    "000071756f7465735f666f7200001d0000009a0600000100000023000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970616c"
    "3a312e3000000a0000005072696e636970616c0000000000000003000000"
    "090000007468655f74797065000000001500000048000000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970"
    "616c547970653a312e3000000e0000005072696e636970616c5479706500"
    "00000500000001000000090000007468655f6e616d65000000000f000000"
    "a0010000010000002700000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f5072696e636970616c4e616d653a312e3000000e0000005072696e"
    "636970616c4e616d6500000002000000090000007468655f747970650000"
    "00001500000044000000010000002200000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f4e616d65547970653a312e30000000090000004e61"
    "6d6554797065000000001200000000000000090000007468655f6e616d65"
    "0000000015000000e4000000010000002300000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f4e616d6556616c75653a312e3000000a000000"
    "4e616d6556616c756500000015000000a000000001000000220000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f4e616d65506174683a312e"
    "30000000090000004e616d655061746800000000130000005c0000000100"
    "0000150000004c000000010000002700000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f4e616d65436f6d706f6e656e743a312e3000000e00"
    "00004e616d65436f6d706f6e656e740000001b0000000000000000000000"
    "0100000010000000776974685f70726976696c6567657300150000001804"
    "0000010000002e00000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f53636f70656450726976696c656765734c6973743a312e300000001500"
    "000053636f70656450726976696c656765734c6973740000000013000000"
    "bc030000010000000f000000ac030000010000002a00000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f53636f70656450726976696c656765"
    "733a312e300000001100000053636f70656450726976696c656765730000"
    "0000020000001400000070726976696c6567655f617574686f7269747900"
    "0f000000a0010000010000002700000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f5072696e636970616c4e616d653a312e3000000e000000"
    "5072696e636970616c4e616d6500000002000000090000007468655f7479"
    "7065000000001500000044000000010000002200000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f4e616d65547970653a312e300000000900"
    "00004e616d6554797065000000001200000000000000090000007468655f"
    "6e616d650000000015000000e4000000010000002300000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f4e616d6556616c75653a312e300000"
    "0a0000004e616d6556616c756500000015000000a0000000010000002200"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65506174"
    "683a312e30000000090000004e616d655061746800000000130000005c00"
    "000001000000150000004c000000010000002700000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f4e616d65436f6d706f6e656e743a312e30"
    "00000e0000004e616d65436f6d706f6e656e740000001b00000000000000"
    "000000000b00000070726976696c65676573000015000000840100000100"
    "00002b00000049444c3a616469726f6e2e636f6d2f534c33504d2f507269"
    "6e4174747269627574654c6973743a312e300000120000005072696e4174"
    "747269627574654c6973740000001300000030010000010000000f000000"
    "20010000010000002700000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f5072696e4174747269627574653a312e3000000e0000005072696e"
    "41747472696275746500000002000000090000007468655f747970650000"
    "00001500000054000000010000002b00000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f5072696e417474726962757465547970653a312e30"
    "0000120000005072696e4174747269627574655479706500000012000000"
    "000000000a0000007468655f76616c756500000015000000540000000100"
    "00002c00000049444c3a616469726f6e2e636f6d2f534c33504d2f507269"
    "6e41747472696275746556616c75653a312e3000130000005072696e4174"
    "7472696275746556616c756500001b000000000000000000000000000000"
    "01000100";
    _marshaller_SL3PM_QuotingPrincipal = new _Marshaller_SL3PM_QuotingPrincipal;
    SL3PM::_tc_StatementType = 
    "010000001500000048000000010000002700000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f53746174656d656e74547970653a312e300000"
    "0e00000053746174656d656e745479706500000005000000";
    SL3PM::_tc_Encoding = 
    "010000001500000050000000010000002200000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f456e636f64696e673a312e3000000009000000"
    "456e636f64696e6700000000130000000c000000010000000a0000000000"
    "0000";
    SL3PM::_tc_EncodingType = 
    "01000000150000004c000000010000002600000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f456e636f64696e67547970653a312e30000000"
    "0d000000456e636f64696e6754797065000000001200000000000000";
    SL3PM::_tc_BadEncoding = 
    "010000001600000044000000010000002500000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f426164456e636f64696e673a312e3000000000"
    "0c000000426164456e636f64696e670000000000";
    _marshaller_SL3PM_BadEncoding = new _Marshaller_SL3PM_BadEncoding;
    SL3PM::_tc_BadEncodingType = 
    "01000000160000004c000000010000002900000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f426164456e636f64696e67547970653a312e30"
    "0000000010000000426164456e636f64696e67547970650000000000";
    _marshaller_SL3PM_BadEncodingType = new _Marshaller_SL3PM_BadEncodingType;
    SL3PM::_tc_StatementLayer = 
    "010000001500000048000000010000002800000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f53746174656d656e744c617965723a312e3000"
    "0f00000053746174656d656e744c61796572000005000000";
    SL3PM::_tc_Statement = 
    "010000001d000000e6010000010000002300000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f53746174656d656e743a312e3000000a000000"
    "53746174656d656e7400000000000000040000000a0000007468655f6c61"
    "7965720000001500000048000000010000002800000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f53746174656d656e744c617965723a312e"
    "30000f00000053746174656d656e744c6179657200000500000001000000"
    "090000007468655f74797065000000001500000048000000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f53746174656d65"
    "6e74547970653a312e3000000e00000053746174656d656e745479706500"
    "000005000000010000000e000000656e636f64696e675f74797065000000"
    "150000004c000000010000002600000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f456e636f64696e67547970653a312e300000000d000000"
    "456e636f64696e6754797065000000001200000000000000000000000d00"
    "00007468655f656e636f64696e6700000000150000005000000001000000"
    "2200000049444c3a616469726f6e2e636f6d2f534c33504d2f456e636f64"
    "696e673a312e3000000009000000456e636f64696e670000000013000000"
    "0c000000010000000a000000000000000000";
    _marshaller_SL3PM_Statement = new _Marshaller_SL3PM_Statement;
    SL3PM::_tc_StatementList = 
    "010000001500000044020000010000002700000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f53746174656d656e744c6973743a312e300000"
    "0e00000053746174656d656e744c69737400000013000000f80100000100"
    "00001d000000e6010000010000002300000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f53746174656d656e743a312e3000000a0000005374"
    "6174656d656e7400000000000000040000000a0000007468655f6c617965"
    "720000001500000048000000010000002800000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f53746174656d656e744c617965723a312e3000"
    "0f00000053746174656d656e744c61796572000005000000010000000900"
    "00007468655f747970650000000015000000480000000100000027000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f53746174656d656e74"
    "547970653a312e3000000e00000053746174656d656e7454797065000000"
    "05000000010000000e000000656e636f64696e675f747970650000001500"
    "00004c000000010000002600000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f456e636f64696e67547970653a312e300000000d000000456e"
    "636f64696e6754797065000000001200000000000000000000000d000000"
    "7468655f656e636f64696e67000000001500000050000000010000002200"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f456e636f64696e"
    "673a312e3000000009000000456e636f64696e6700000000130000000c00"
    "0000010000000a000000000000000000000000000000";
    SL3PM::_tc_IdentityStatement = 
    "010000001d00000062020000010000002b00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f4964656e7469747953746174656d656e743a31"
    "2e300000120000004964656e7469747953746174656d656e740000001d00"
    "0000e6010000010000002300000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f53746174656d656e743a312e3000000a00000053746174656d"
    "656e7400000000000000040000000a0000007468655f6c61796572000000"
    "1500000048000000010000002800000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f53746174656d656e744c617965723a312e30000f000000"
    "53746174656d656e744c6179657200000500000001000000090000007468"
    "655f74797065000000001500000048000000010000002700000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f53746174656d656e7454797065"
    "3a312e3000000e00000053746174656d656e745479706500000005000000"
    "010000000e000000656e636f64696e675f74797065000000150000004c00"
    "0000010000002600000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f456e636f64696e67547970653a312e300000000d000000456e636f6469"
    "6e6754797065000000001200000000000000000000000d0000007468655f"
    "656e636f64696e6700000000150000005000000001000000220000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f456e636f64696e673a312e"
    "3000000009000000456e636f64696e6700000000130000000c0000000100"
    "00000a00000000000000000000000100000013000000696e746572707265"
    "746174696f6e5f616964000012000000000000000100";
    _marshaller_SL3PM_IdentityStatement = new _Marshaller_SL3PM_IdentityStatement;
    SL3PM::_tc_PrincipalIdentityStatement = 
    "010000001d00000088090000010000003400000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e636970616c4964656e746974795374"
    "6174656d656e743a312e30001b0000005072696e636970616c4964656e74"
    "69747953746174656d656e740000000000001d0000006202000001000000"
    "2b00000049444c3a616469726f6e2e636f6d2f534c33504d2f4964656e74"
    "69747953746174656d656e743a312e300000120000004964656e74697479"
    "53746174656d656e740000001d000000e601000001000000230000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f53746174656d656e743a31"
    "2e3000000a00000053746174656d656e7400000000000000040000000a00"
    "00007468655f6c6179657200000015000000480000000100000028000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f53746174656d656e74"
    "4c617965723a312e30000f00000053746174656d656e744c617965720000"
    "0500000001000000090000007468655f7479706500000000150000004800"
    "0000010000002700000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f53746174656d656e74547970653a312e3000000e00000053746174656d"
    "656e745479706500000005000000010000000e000000656e636f64696e67"
    "5f74797065000000150000004c000000010000002600000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f456e636f64696e67547970653a312e"
    "300000000d000000456e636f64696e675479706500000000120000000000"
    "0000000000000d0000007468655f656e636f64696e670000000015000000"
    "50000000010000002200000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f456e636f64696e673a312e3000000009000000456e636f64696e67"
    "00000000130000000c000000010000000a00000000000000000000000100"
    "000013000000696e746572707265746174696f6e5f616964000012000000"
    "0000000001000000010000000e0000007468655f7072696e636970616c00"
    "00001d0000009a060000010000002300000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f5072696e636970616c3a312e3000000a0000005072"
    "696e636970616c0000000000000003000000090000007468655f74797065"
    "000000001500000048000000010000002700000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e636970616c547970653a312e300000"
    "0e0000005072696e636970616c5479706500000005000000010000000900"
    "00007468655f6e616d65000000000f000000a00100000100000027000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970616c"
    "4e616d653a312e3000000e0000005072696e636970616c4e616d65000000"
    "02000000090000007468655f747970650000000015000000440000000100"
    "00002200000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d"
    "65547970653a312e30000000090000004e616d6554797065000000001200"
    "000000000000090000007468655f6e616d650000000015000000e4000000"
    "010000002300000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d6556616c75653a312e3000000a0000004e616d6556616c7565000000"
    "15000000a0000000010000002200000049444c3a616469726f6e2e636f6d"
    "2f534c33504d2f4e616d65506174683a312e30000000090000004e616d65"
    "5061746800000000130000005c00000001000000150000004c0000000100"
    "00002700000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d"
    "65436f6d706f6e656e743a312e3000000e0000004e616d65436f6d706f6e"
    "656e740000001b0000000000000000000000010000001000000077697468"
    "5f70726976696c65676573001500000018040000010000002e0000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f53636f7065645072697669"
    "6c656765734c6973743a312e300000001500000053636f70656450726976"
    "696c656765734c6973740000000013000000bc030000010000000f000000"
    "ac030000010000002a00000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f53636f70656450726976696c656765733a312e3000000011000000"
    "53636f70656450726976696c656765730000000002000000140000007072"
    "6976696c6567655f617574686f72697479000f000000a001000001000000"
    "2700000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e63"
    "6970616c4e616d653a312e3000000e0000005072696e636970616c4e616d"
    "6500000002000000090000007468655f7479706500000000150000004400"
    "0000010000002200000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f4e616d65547970653a312e30000000090000004e616d65547970650000"
    "00001200000000000000090000007468655f6e616d650000000015000000"
    "e4000000010000002300000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d6556616c75653a312e3000000a0000004e616d6556616c75"
    "6500000015000000a0000000010000002200000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f4e616d65506174683a312e3000000009000000"
    "4e616d655061746800000000130000005c00000001000000150000004c00"
    "0000010000002700000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f4e616d65436f6d706f6e656e743a312e3000000e0000004e616d65436f"
    "6d706f6e656e740000001b00000000000000000000000b00000070726976"
    "696c6567657300001500000084010000010000002b00000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f5072696e4174747269627574654c69"
    "73743a312e300000120000005072696e4174747269627574654c69737400"
    "00001300000030010000010000000f000000200100000100000027000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f5072696e4174747269"
    "627574653a312e3000000e0000005072696e417474726962757465000000"
    "02000000090000007468655f747970650000000015000000540000000100"
    "00002b00000049444c3a616469726f6e2e636f6d2f534c33504d2f507269"
    "6e417474726962757465547970653a312e300000120000005072696e4174"
    "747269627574655479706500000012000000000000000a0000007468655f"
    "76616c75650000001500000054000000010000002c00000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f5072696e4174747269627574655661"
    "6c75653a312e3000130000005072696e41747472696275746556616c7565"
    "00001b00000000000000000000000000000001000100";
    _marshaller_SL3PM_PrincipalIdentityStatement = new _Marshaller_SL3PM_PrincipalIdentityStatement;
    SL3PM::_tc_EndorsementStatement = 
    "010000001d0000006a020000010000002e00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f456e646f7273656d656e7453746174656d656e"
    "743a312e3000000015000000456e646f7273656d656e7453746174656d65"
    "6e74000000001d000000e6010000010000002300000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f53746174656d656e743a312e3000000a00"
    "000053746174656d656e7400000000000000040000000a0000007468655f"
    "6c617965720000001500000048000000010000002800000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f53746174656d656e744c617965723a"
    "312e30000f00000053746174656d656e744c617965720000050000000100"
    "0000090000007468655f7479706500000000150000004800000001000000"
    "2700000049444c3a616469726f6e2e636f6d2f534c33504d2f5374617465"
    "6d656e74547970653a312e3000000e00000053746174656d656e74547970"
    "6500000005000000010000000e000000656e636f64696e675f7479706500"
    "0000150000004c000000010000002600000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f456e636f64696e67547970653a312e300000000d00"
    "0000456e636f64696e675479706500000000120000000000000000000000"
    "0d0000007468655f656e636f64696e670000000015000000500000000100"
    "00002200000049444c3a616469726f6e2e636f6d2f534c33504d2f456e63"
    "6f64696e673a312e3000000009000000456e636f64696e67000000001300"
    "00000c000000010000000a00000000000000000000000100000013000000"
    "696e746572707265746174696f6e5f616964000012000000000000000100"
    ;
    _marshaller_SL3PM_EndorsementStatement = new _Marshaller_SL3PM_EndorsementStatement;
    SL3PM::_tc_X509IdentityStatement = 
    "010000001d000000e8090000010000002f00000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f583530394964656e7469747953746174656d65"
    "6e743a312e30000016000000583530394964656e7469747953746174656d"
    "656e740000001d00000088090000010000003400000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f5072696e636970616c4964656e74697479"
    "53746174656d656e743a312e30001b0000005072696e636970616c496465"
    "6e7469747953746174656d656e740000000000001d000000620200000100"
    "00002b00000049444c3a616469726f6e2e636f6d2f534c33504d2f496465"
    "6e7469747953746174656d656e743a312e300000120000004964656e7469"
    "747953746174656d656e740000001d000000e60100000100000023000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f53746174656d656e74"
    "3a312e3000000a00000053746174656d656e740000000000000004000000"
    "0a0000007468655f6c617965720000001500000048000000010000002800"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f53746174656d65"
    "6e744c617965723a312e30000f00000053746174656d656e744c61796572"
    "00000500000001000000090000007468655f747970650000000015000000"
    "48000000010000002700000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f53746174656d656e74547970653a312e3000000e00000053746174"
    "656d656e745479706500000005000000010000000e000000656e636f6469"
    "6e675f74797065000000150000004c000000010000002600000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f456e636f64696e67547970653a"
    "312e300000000d000000456e636f64696e67547970650000000012000000"
    "00000000000000000d0000007468655f656e636f64696e67000000001500"
    "000050000000010000002200000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f456e636f64696e673a312e3000000009000000456e636f6469"
    "6e6700000000130000000c000000010000000a0000000000000000000000"
    "0100000013000000696e746572707265746174696f6e5f61696400001200"
    "00000000000001000000010000000e0000007468655f7072696e63697061"
    "6c0000001d0000009a060000010000002300000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f5072696e636970616c3a312e3000000a000000"
    "5072696e636970616c0000000000000003000000090000007468655f7479"
    "7065000000001500000048000000010000002700000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f5072696e636970616c547970653a312e30"
    "00000e0000005072696e636970616c547970650000000500000001000000"
    "090000007468655f6e616d65000000000f000000a0010000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970"
    "616c4e616d653a312e3000000e0000005072696e636970616c4e616d6500"
    "000002000000090000007468655f74797065000000001500000044000000"
    "010000002200000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d65547970653a312e30000000090000004e616d655479706500000000"
    "1200000000000000090000007468655f6e616d650000000015000000e400"
    "0000010000002300000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f4e616d6556616c75653a312e3000000a0000004e616d6556616c756500"
    "000015000000a0000000010000002200000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f4e616d65506174683a312e30000000090000004e61"
    "6d655061746800000000130000005c00000001000000150000004c000000"
    "010000002700000049444c3a616469726f6e2e636f6d2f534c33504d2f4e"
    "616d65436f6d706f6e656e743a312e3000000e0000004e616d65436f6d70"
    "6f6e656e740000001b000000000000000000000001000000100000007769"
    "74685f70726976696c65676573001500000018040000010000002e000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f53636f706564507269"
    "76696c656765734c6973743a312e300000001500000053636f7065645072"
    "6976696c656765734c6973740000000013000000bc030000010000000f00"
    "0000ac030000010000002a00000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f53636f70656450726976696c656765733a312e300000001100"
    "000053636f70656450726976696c65676573000000000200000014000000"
    "70726976696c6567655f617574686f72697479000f000000a00100000100"
    "00002700000049444c3a616469726f6e2e636f6d2f534c33504d2f507269"
    "6e636970616c4e616d653a312e3000000e0000005072696e636970616c4e"
    "616d6500000002000000090000007468655f747970650000000015000000"
    "44000000010000002200000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d65547970653a312e30000000090000004e616d6554797065"
    "000000001200000000000000090000007468655f6e616d65000000001500"
    "0000e4000000010000002300000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f4e616d6556616c75653a312e3000000a0000004e616d655661"
    "6c756500000015000000a0000000010000002200000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f4e616d65506174683a312e300000000900"
    "00004e616d655061746800000000130000005c0000000100000015000000"
    "4c000000010000002700000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f4e616d65436f6d706f6e656e743a312e3000000e0000004e616d65"
    "436f6d706f6e656e740000001b00000000000000000000000b0000007072"
    "6976696c6567657300001500000084010000010000002b00000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e417474726962757465"
    "4c6973743a312e300000120000005072696e4174747269627574654c6973"
    "740000001300000030010000010000000f00000020010000010000002700"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f5072696e417474"
    "7269627574653a312e3000000e0000005072696e41747472696275746500"
    "000002000000090000007468655f74797065000000001500000054000000"
    "010000002b00000049444c3a616469726f6e2e636f6d2f534c33504d2f50"
    "72696e417474726962757465547970653a312e300000120000005072696e"
    "4174747269627574655479706500000012000000000000000a0000007468"
    "655f76616c75650000001500000054000000010000002c00000049444c3a"
    "616469726f6e2e636f6d2f534c33504d2f5072696e417474726962757465"
    "56616c75653a312e3000130000005072696e41747472696275746556616c"
    "756500001b0000000000000000000000000000000100010000000000";
    _marshaller_SL3PM_X509IdentityStatement = new _Marshaller_SL3PM_X509IdentityStatement;
    SL3PM::_tc_X509IdentityStatementList = 
    "01000000150000005c0a0000010000003300000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f583530394964656e7469747953746174656d65"
    "6e744c6973743a312e3000001a000000583530394964656e746974795374"
    "6174656d656e744c69737400000013000000f8090000010000001d000000"
    "e8090000010000002f00000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f583530394964656e7469747953746174656d656e743a312e300000"
    "16000000583530394964656e7469747953746174656d656e740000001d00"
    "000088090000010000003400000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f5072696e636970616c4964656e7469747953746174656d656e"
    "743a312e30001b0000005072696e636970616c4964656e74697479537461"
    "74656d656e740000000000001d00000062020000010000002b0000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f4964656e74697479537461"
    "74656d656e743a312e300000120000004964656e7469747953746174656d"
    "656e740000001d000000e6010000010000002300000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f53746174656d656e743a312e3000000a00"
    "000053746174656d656e7400000000000000040000000a0000007468655f"
    "6c617965720000001500000048000000010000002800000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f53746174656d656e744c617965723a"
    "312e30000f00000053746174656d656e744c617965720000050000000100"
    "0000090000007468655f7479706500000000150000004800000001000000"
    "2700000049444c3a616469726f6e2e636f6d2f534c33504d2f5374617465"
    "6d656e74547970653a312e3000000e00000053746174656d656e74547970"
    "6500000005000000010000000e000000656e636f64696e675f7479706500"
    "0000150000004c000000010000002600000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f456e636f64696e67547970653a312e300000000d00"
    "0000456e636f64696e675479706500000000120000000000000000000000"
    "0d0000007468655f656e636f64696e670000000015000000500000000100"
    "00002200000049444c3a616469726f6e2e636f6d2f534c33504d2f456e63"
    "6f64696e673a312e3000000009000000456e636f64696e67000000001300"
    "00000c000000010000000a00000000000000000000000100000013000000"
    "696e746572707265746174696f6e5f616964000012000000000000000100"
    "0000010000000e0000007468655f7072696e636970616c0000001d000000"
    "9a060000010000002300000049444c3a616469726f6e2e636f6d2f534c33"
    "504d2f5072696e636970616c3a312e3000000a0000005072696e63697061"
    "6c0000000000000003000000090000007468655f74797065000000001500"
    "000048000000010000002700000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f5072696e636970616c547970653a312e3000000e0000005072"
    "696e636970616c547970650000000500000001000000090000007468655f"
    "6e616d65000000000f000000a0010000010000002700000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f5072696e636970616c4e616d653a31"
    "2e3000000e0000005072696e636970616c4e616d65000000020000000900"
    "00007468655f747970650000000015000000440000000100000022000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65547970653a"
    "312e30000000090000004e616d6554797065000000001200000000000000"
    "090000007468655f6e616d650000000015000000e4000000010000002300"
    "000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d6556616c"
    "75653a312e3000000a0000004e616d6556616c756500000015000000a000"
    "0000010000002200000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f4e616d65506174683a312e30000000090000004e616d65506174680000"
    "0000130000005c00000001000000150000004c0000000100000027000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f4e616d65436f6d706f"
    "6e656e743a312e3000000e0000004e616d65436f6d706f6e656e74000000"
    "1b00000000000000000000000100000010000000776974685f7072697669"
    "6c65676573001500000018040000010000002e00000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f53636f70656450726976696c656765734c"
    "6973743a312e300000001500000053636f70656450726976696c65676573"
    "4c6973740000000013000000bc030000010000000f000000ac0300000100"
    "00002a00000049444c3a616469726f6e2e636f6d2f534c33504d2f53636f"
    "70656450726976696c656765733a312e300000001100000053636f706564"
    "50726976696c6567657300000000020000001400000070726976696c6567"
    "655f617574686f72697479000f000000a001000001000000270000004944"
    "4c3a616469726f6e2e636f6d2f534c33504d2f5072696e636970616c4e61"
    "6d653a312e3000000e0000005072696e636970616c4e616d650000000200"
    "0000090000007468655f7479706500000000150000004400000001000000"
    "2200000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d6554"
    "7970653a312e30000000090000004e616d65547970650000000012000000"
    "00000000090000007468655f6e616d650000000015000000e40000000100"
    "00002300000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d"
    "6556616c75653a312e3000000a0000004e616d6556616c75650000001500"
    "0000a0000000010000002200000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f4e616d65506174683a312e30000000090000004e616d655061"
    "746800000000130000005c00000001000000150000004c00000001000000"
    "2700000049444c3a616469726f6e2e636f6d2f534c33504d2f4e616d6543"
    "6f6d706f6e656e743a312e3000000e0000004e616d65436f6d706f6e656e"
    "740000001b00000000000000000000000b00000070726976696c65676573"
    "00001500000084010000010000002b00000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f5072696e4174747269627574654c6973743a312e30"
    "0000120000005072696e4174747269627574654c69737400000013000000"
    "30010000010000000f00000020010000010000002700000049444c3a6164"
    "69726f6e2e636f6d2f534c33504d2f5072696e4174747269627574653a31"
    "2e3000000e0000005072696e417474726962757465000000020000000900"
    "00007468655f74797065000000001500000054000000010000002b000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f5072696e4174747269"
    "62757465547970653a312e300000120000005072696e4174747269627574"
    "655479706500000012000000000000000a0000007468655f76616c756500"
    "00001500000054000000010000002c00000049444c3a616469726f6e2e63"
    "6f6d2f534c33504d2f5072696e41747472696275746556616c75653a312e"
    "3000130000005072696e41747472696275746556616c756500001b000000"
    "000000000000000000000000010001000000000000000000";
    _marshaller__seq_SL3PM_PrincipalName = new _Marshaller__seq_SL3PM_PrincipalName;
    _marshaller__seq_SL3PM_PrinAttribute = new _Marshaller__seq_SL3PM_PrinAttribute;
    _marshaller__seq_SL3PM_ResourceName = new _Marshaller__seq_SL3PM_ResourceName;
    _marshaller__seq_SL3PM_ScopedPrivileges = new _Marshaller__seq_SL3PM_ScopedPrivileges;
    _marshaller__seq_SL3PM_Principal = new _Marshaller__seq_SL3PM_Principal;
    _marshaller__seq_SL3PM_Statement = new _Marshaller__seq_SL3PM_Statement;
    _marshaller__seq_SL3PM_X509IdentityStatement = new _Marshaller__seq_SL3PM_X509IdentityStatement;
  }

  ~__tc_init_SL3PM()
  {
    delete static_cast<_Marshaller_SL3PM_PrincipalName*>(_marshaller_SL3PM_PrincipalName);
    delete static_cast<_Marshaller_SL3PM_PrinAttribute*>(_marshaller_SL3PM_PrinAttribute);
    delete static_cast<_Marshaller_SL3PM_ResourceName*>(_marshaller_SL3PM_ResourceName);
    delete static_cast<_Marshaller_SL3PM_ScopedPrivileges*>(_marshaller_SL3PM_ScopedPrivileges);
    delete static_cast<_Marshaller_SL3PM_Principal*>(_marshaller_SL3PM_Principal);
    delete static_cast<_Marshaller_SL3PM_SimplePrincipal*>(_marshaller_SL3PM_SimplePrincipal);
    delete static_cast<_Marshaller_SL3PM_ProxyPrincipal*>(_marshaller_SL3PM_ProxyPrincipal);
    delete static_cast<_Marshaller_SL3PM_QuotingPrincipal*>(_marshaller_SL3PM_QuotingPrincipal);
    delete static_cast<_Marshaller_SL3PM_BadEncoding*>(_marshaller_SL3PM_BadEncoding);
    delete static_cast<_Marshaller_SL3PM_BadEncodingType*>(_marshaller_SL3PM_BadEncodingType);
    delete static_cast<_Marshaller_SL3PM_Statement*>(_marshaller_SL3PM_Statement);
    delete static_cast<_Marshaller_SL3PM_IdentityStatement*>(_marshaller_SL3PM_IdentityStatement);
    delete static_cast<_Marshaller_SL3PM_PrincipalIdentityStatement*>(_marshaller_SL3PM_PrincipalIdentityStatement);
    delete static_cast<_Marshaller_SL3PM_EndorsementStatement*>(_marshaller_SL3PM_EndorsementStatement);
    delete static_cast<_Marshaller_SL3PM_X509IdentityStatement*>(_marshaller_SL3PM_X509IdentityStatement);
    delete static_cast<_Marshaller__seq_SL3PM_PrincipalName*>(_marshaller__seq_SL3PM_PrincipalName);
    delete static_cast<_Marshaller__seq_SL3PM_PrinAttribute*>(_marshaller__seq_SL3PM_PrinAttribute);
    delete static_cast<_Marshaller__seq_SL3PM_ResourceName*>(_marshaller__seq_SL3PM_ResourceName);
    delete static_cast<_Marshaller__seq_SL3PM_ScopedPrivileges*>(_marshaller__seq_SL3PM_ScopedPrivileges);
    delete static_cast<_Marshaller__seq_SL3PM_Principal*>(_marshaller__seq_SL3PM_Principal);
    delete static_cast<_Marshaller__seq_SL3PM_Statement*>(_marshaller__seq_SL3PM_Statement);
    delete static_cast<_Marshaller__seq_SL3PM_X509IdentityStatement*>(_marshaller__seq_SL3PM_X509IdentityStatement);
  }
};

static __tc_init_SL3PM __init_SL3PM;

