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
namespace SL3Authorization
{
CORBA::TypeCodeConst _tc_AuthorizationInfo;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
SL3Authorization::AuthorizationInfo::AuthorizationInfo()
{
}

SL3Authorization::AuthorizationInfo::AuthorizationInfo( const AuthorizationInfo& _s )
{
  the_principal = SL3PM::Principal::_narrow ((AuthorizationInfo&)_s.the_principal->_copy_value());
  the_statements = ((AuthorizationInfo&)_s).the_statements;
  the_resources = ((AuthorizationInfo&)_s).the_resources;
}

SL3Authorization::AuthorizationInfo::~AuthorizationInfo()
{
}

SL3Authorization::AuthorizationInfo&
SL3Authorization::AuthorizationInfo::operator=( const AuthorizationInfo& _s )
{
  the_principal = SL3PM::Principal::_narrow ((AuthorizationInfo&)_s.the_principal->_copy_value());
  the_statements = ((AuthorizationInfo&)_s).the_statements;
  the_resources = ((AuthorizationInfo&)_s).the_resources;
  return *this;
}
#endif

CORBA::Long
SL3Authorization::AuthorizationInfo::_count_refs (CORBA::ValueBase::visited * _seen)
{
  CORBA::Long res = 0;
  if (the_principal) {
    res += the_principal->_count_refs (_seen);
  }
  {
    for (CORBA::ULong i0=0; i0<the_statements.length(); i0++) {
      if (the_statements[i0]) {
        res += the_statements[i0]->_count_refs (_seen);
      }
    }
  }
  return res;
}

void
SL3Authorization::AuthorizationInfo::_release_members ()
{
  if (the_principal) {
    the_principal->_release_members ();
  }
  the_principal = 0;
  {
    for (CORBA::ULong i0=0; i0<the_statements.length(); i0++) {
      if (the_statements[i0]) {
        the_statements[i0]->_release_members ();
      }
      the_statements[i0] = 0;
    }
  }
}

class _Marshaller_SL3Authorization_AuthorizationInfo : public ::CORBA::StaticTypeInfo {
    typedef SL3Authorization::AuthorizationInfo _MICO_T;
  public:
    ~_Marshaller_SL3Authorization_AuthorizationInfo();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3Authorization_AuthorizationInfo::~_Marshaller_SL3Authorization_AuthorizationInfo()
{
}

::CORBA::StaticValueType _Marshaller_SL3Authorization_AuthorizationInfo::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_SL3Authorization_AuthorizationInfo::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3Authorization_AuthorizationInfo::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3Authorization_AuthorizationInfo::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    _marshaller_SL3PM_Principal->demarshal( dc, &((_MICO_T*)v)->the_principal._for_demarshal() ) &&
    _marshaller__seq_SL3PM_Statement->demarshal( dc, &((_MICO_T*)v)->the_statements ) &&
    _marshaller__seq_SL3PM_ResourceName->demarshal( dc, &((_MICO_T*)v)->the_resources ) &&
    dc.struct_end();
}

void _Marshaller_SL3Authorization_AuthorizationInfo::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  _marshaller_SL3PM_Principal->marshal( ec, &((_MICO_T*)v)->the_principal.inout() );
  _marshaller__seq_SL3PM_Statement->marshal( ec, &((_MICO_T*)v)->the_statements );
  _marshaller__seq_SL3PM_ResourceName->marshal( ec, &((_MICO_T*)v)->the_resources );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_SL3Authorization_AuthorizationInfo::typecode()
{
  return SL3Authorization::_tc_AuthorizationInfo;
}

::CORBA::StaticTypeInfo *_marshaller_SL3Authorization_AuthorizationInfo;

void operator<<=( CORBA::Any &_a, const SL3Authorization::AuthorizationInfo &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3Authorization_AuthorizationInfo, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SL3Authorization::AuthorizationInfo *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SL3Authorization::AuthorizationInfo &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3Authorization_AuthorizationInfo, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SL3Authorization::AuthorizationInfo *&_s )
{
  return _a.to_static_any (_marshaller_SL3Authorization_AuthorizationInfo, (void *&)_s);
}

namespace SL3Authorization
{
CORBA::TypeCodeConst _tc_InvalidEvidence;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
SL3Authorization::InvalidEvidence::InvalidEvidence()
{
}

SL3Authorization::InvalidEvidence::InvalidEvidence( const InvalidEvidence& _s )
{
  minor = ((InvalidEvidence&)_s).minor;
}

SL3Authorization::InvalidEvidence::~InvalidEvidence()
{
}

SL3Authorization::InvalidEvidence&
SL3Authorization::InvalidEvidence::operator=( const InvalidEvidence& _s )
{
  minor = ((InvalidEvidence&)_s).minor;
  return *this;
}
#endif

#ifndef HAVE_EXPLICIT_STRUCT_OPS
SL3Authorization::InvalidEvidence::InvalidEvidence()
{
}

#endif

SL3Authorization::InvalidEvidence::InvalidEvidence( CORBA::ULong _m0 )
{
  minor = _m0;
}

class _Marshaller_SL3Authorization_InvalidEvidence : public ::CORBA::StaticTypeInfo {
    typedef ::SL3Authorization::InvalidEvidence _MICO_T;
  public:
    ~_Marshaller_SL3Authorization_InvalidEvidence();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3Authorization_InvalidEvidence::~_Marshaller_SL3Authorization_InvalidEvidence()
{
}

::CORBA::StaticValueType _Marshaller_SL3Authorization_InvalidEvidence::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_SL3Authorization_InvalidEvidence::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3Authorization_InvalidEvidence::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3Authorization_InvalidEvidence::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    CORBA::_stc_ulong->demarshal( dc, &((_MICO_T*)v)->minor ) &&
    dc.except_end();
}

void _Marshaller_SL3Authorization_InvalidEvidence::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:adiron.com/SL3Authorization/InvalidEvidence:1.0" );
  CORBA::_stc_ulong->marshal( ec, &((_MICO_T*)v)->minor );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_SL3Authorization_InvalidEvidence::typecode()
{
  return SL3Authorization::_tc_InvalidEvidence;
}

::CORBA::StaticTypeInfo *_marshaller_SL3Authorization_InvalidEvidence;

void operator<<=( CORBA::Any &_a, const SL3Authorization::InvalidEvidence &_e )
{
  CORBA::StaticAny _sa (_marshaller_SL3Authorization_InvalidEvidence, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SL3Authorization::InvalidEvidence *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SL3Authorization::InvalidEvidence &_e )
{
  CORBA::StaticAny _sa (_marshaller_SL3Authorization_InvalidEvidence, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SL3Authorization::InvalidEvidence *&_e )
{
  return _a.to_static_any (_marshaller_SL3Authorization_InvalidEvidence, (void *&)_e);
}

void SL3Authorization::InvalidEvidence::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw InvalidEvidence_var( (SL3Authorization::InvalidEvidence*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *SL3Authorization::InvalidEvidence::_repoid() const
{
  return "IDL:adiron.com/SL3Authorization/InvalidEvidence:1.0";
}

void SL3Authorization::InvalidEvidence::_encode( CORBA::DataEncoder & ) const
{
  assert(0);
}

void SL3Authorization::InvalidEvidence::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *SL3Authorization::InvalidEvidence::_clone() const
{
  return new InvalidEvidence( *this );
}

SL3Authorization::InvalidEvidence *SL3Authorization::InvalidEvidence::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:adiron.com/SL3Authorization/InvalidEvidence:1.0" ) )
    return (InvalidEvidence *) _ex;
  return NULL;
}

const SL3Authorization::InvalidEvidence *SL3Authorization::InvalidEvidence::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:adiron.com/SL3Authorization/InvalidEvidence:1.0" ) )
    return (InvalidEvidence *) _ex;
  return NULL;
}

namespace SL3Authorization
{
CORBA::TypeCodeConst _tc_InvalidMechanism;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
SL3Authorization::InvalidMechanism::InvalidMechanism()
{
}

SL3Authorization::InvalidMechanism::InvalidMechanism( const InvalidMechanism& _s )
{
  minor = ((InvalidMechanism&)_s).minor;
}

SL3Authorization::InvalidMechanism::~InvalidMechanism()
{
}

SL3Authorization::InvalidMechanism&
SL3Authorization::InvalidMechanism::operator=( const InvalidMechanism& _s )
{
  minor = ((InvalidMechanism&)_s).minor;
  return *this;
}
#endif

#ifndef HAVE_EXPLICIT_STRUCT_OPS
SL3Authorization::InvalidMechanism::InvalidMechanism()
{
}

#endif

SL3Authorization::InvalidMechanism::InvalidMechanism( CORBA::ULong _m0 )
{
  minor = _m0;
}

class _Marshaller_SL3Authorization_InvalidMechanism : public ::CORBA::StaticTypeInfo {
    typedef ::SL3Authorization::InvalidMechanism _MICO_T;
  public:
    ~_Marshaller_SL3Authorization_InvalidMechanism();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3Authorization_InvalidMechanism::~_Marshaller_SL3Authorization_InvalidMechanism()
{
}

::CORBA::StaticValueType _Marshaller_SL3Authorization_InvalidMechanism::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_SL3Authorization_InvalidMechanism::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3Authorization_InvalidMechanism::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3Authorization_InvalidMechanism::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  string repoid;
  return
    dc.except_begin( repoid ) &&
    CORBA::_stc_ulong->demarshal( dc, &((_MICO_T*)v)->minor ) &&
    dc.except_end();
}

void _Marshaller_SL3Authorization_InvalidMechanism::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.except_begin( "IDL:adiron.com/SL3Authorization/InvalidMechanism:1.0" );
  CORBA::_stc_ulong->marshal( ec, &((_MICO_T*)v)->minor );
  ec.except_end();
}

::CORBA::TypeCode_ptr _Marshaller_SL3Authorization_InvalidMechanism::typecode()
{
  return SL3Authorization::_tc_InvalidMechanism;
}

::CORBA::StaticTypeInfo *_marshaller_SL3Authorization_InvalidMechanism;

void operator<<=( CORBA::Any &_a, const SL3Authorization::InvalidMechanism &_e )
{
  CORBA::StaticAny _sa (_marshaller_SL3Authorization_InvalidMechanism, &_e);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SL3Authorization::InvalidMechanism *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SL3Authorization::InvalidMechanism &_e )
{
  CORBA::StaticAny _sa (_marshaller_SL3Authorization_InvalidMechanism, &_e);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SL3Authorization::InvalidMechanism *&_e )
{
  return _a.to_static_any (_marshaller_SL3Authorization_InvalidMechanism, (void *&)_e);
}

void SL3Authorization::InvalidMechanism::_throwit() const
{
  #ifdef HAVE_EXCEPTIONS
  #ifdef HAVE_STD_EH
  throw *this;
  #else
  throw InvalidMechanism_var( (SL3Authorization::InvalidMechanism*)_clone() );
  #endif
  #else
  CORBA::Exception::_throw_failed( _clone() );
  #endif
}

const char *SL3Authorization::InvalidMechanism::_repoid() const
{
  return "IDL:adiron.com/SL3Authorization/InvalidMechanism:1.0";
}

void SL3Authorization::InvalidMechanism::_encode( CORBA::DataEncoder & ) const
{
  assert(0);
}

void SL3Authorization::InvalidMechanism::_encode_any( CORBA::Any &_a ) const
{
  _a <<= *this;
}

CORBA::Exception *SL3Authorization::InvalidMechanism::_clone() const
{
  return new InvalidMechanism( *this );
}

SL3Authorization::InvalidMechanism *SL3Authorization::InvalidMechanism::_downcast( CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:adiron.com/SL3Authorization/InvalidMechanism:1.0" ) )
    return (InvalidMechanism *) _ex;
  return NULL;
}

const SL3Authorization::InvalidMechanism *SL3Authorization::InvalidMechanism::_downcast( const CORBA::Exception *_ex )
{
  if( _ex && !strcmp( _ex->_repoid(), "IDL:adiron.com/SL3Authorization/InvalidMechanism:1.0" ) )
    return (InvalidMechanism *) _ex;
  return NULL;
}


/*
 * Base interface for class TokenProcessor
 */

SL3Authorization::TokenProcessor::~TokenProcessor()
{
}

void *
SL3Authorization::TokenProcessor::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/SL3Authorization/TokenProcessor:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

SL3Authorization::TokenProcessor_ptr
SL3Authorization::TokenProcessor::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/SL3Authorization/TokenProcessor:1.0" )))
      return _duplicate( (SL3Authorization::TokenProcessor_ptr) _p );
  }
  return _nil();
}

SL3Authorization::TokenProcessor_ptr
SL3Authorization::TokenProcessor::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3Authorization
{
CORBA::TypeCodeConst _tc_TokenProcessor;
}

struct __tc_init_SL3AUTHORIZATION {
  __tc_init_SL3AUTHORIZATION()
  {
    SL3Authorization::_tc_AuthorizationInfo = 
    "010000000f000000640a0000010000003600000049444c3a616469726f6e"
    "2e636f6d2f534c33417574686f72697a6174696f6e2f417574686f72697a"
    "6174696f6e496e666f3a312e3000000012000000417574686f72697a6174"
    "696f6e496e666f000000030000000e0000007468655f7072696e63697061"
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
    "756500001b000000000000000000000000000000010000000f0000007468"
    "655f73746174656d656e7473000015000000440200000100000027000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f53746174656d656e74"
    "4c6973743a312e3000000e00000053746174656d656e744c697374000000"
    "13000000f8010000010000001d000000e601000001000000230000004944"
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
    "00000000130000000c000000010000000a00000000000000000000000000"
    "00000e0000007468655f7265736f757263657300000015000000d4000000"
    "010000002a00000049444c3a616469726f6e2e636f6d2f534c33504d2f52"
    "65736f757263654e616d654c6973743a312e30000000110000005265736f"
    "757263654e616d654c697374000000001300000080000000010000000f00"
    "000070000000010000002600000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f5265736f757263654e616d653a312e300000000d0000005265"
    "736f757263654e616d6500000000010000000b000000636f6d706f6e656e"
    "747300001300000010000000010000001200000000000000000000000000"
    "0000";
    _marshaller_SL3Authorization_AuthorizationInfo = new _Marshaller_SL3Authorization_AuthorizationInfo;
    SL3Authorization::_tc_InvalidEvidence = 
    "010000001600000064000000010000003400000049444c3a616469726f6e"
    "2e636f6d2f534c33417574686f72697a6174696f6e2f496e76616c696445"
    "766964656e63653a312e300010000000496e76616c696445766964656e63"
    "650001000000060000006d696e6f7200000005000000";
    _marshaller_SL3Authorization_InvalidEvidence = new _Marshaller_SL3Authorization_InvalidEvidence;
    SL3Authorization::_tc_InvalidMechanism = 
    "01000000160000006c000000010000003500000049444c3a616469726f6e"
    "2e636f6d2f534c33417574686f72697a6174696f6e2f496e76616c69644d"
    "656368616e69736d3a312e300000000011000000496e76616c69644d6563"
    "68616e69736d0000000001000000060000006d696e6f7200000005000000"
    ;
    _marshaller_SL3Authorization_InvalidMechanism = new _Marshaller_SL3Authorization_InvalidMechanism;
    SL3Authorization::_tc_TokenProcessor = 
    "010000000e0000004f000000010000003300000049444c3a616469726f6e"
    "2e636f6d2f534c33417574686f72697a6174696f6e2f546f6b656e50726f"
    "636573736f723a312e3000000f000000546f6b656e50726f636573736f72"
    "00";
  }

  ~__tc_init_SL3AUTHORIZATION()
  {
    delete static_cast<_Marshaller_SL3Authorization_AuthorizationInfo*>(_marshaller_SL3Authorization_AuthorizationInfo);
    delete static_cast<_Marshaller_SL3Authorization_InvalidEvidence*>(_marshaller_SL3Authorization_InvalidEvidence);
    delete static_cast<_Marshaller_SL3Authorization_InvalidMechanism*>(_marshaller_SL3Authorization_InvalidMechanism);
  }
};

static __tc_init_SL3AUTHORIZATION __init_SL3AUTHORIZATION;

