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
namespace MICOMT
{
CORBA::TypeCodeConst _tc_ServerConcurrencyModel;
}

void operator<<=( CORBA::Any &_a, const MICOMT::ServerConcurrencyModel &_e )
{
  CORBA::StaticAny _sa (_marshaller_MICOMT_ServerConcurrencyModel, &_e);
  _a.from_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, MICOMT::ServerConcurrencyModel &_e )
{
  CORBA::StaticAny _sa (_marshaller_MICOMT_ServerConcurrencyModel, &_e);
  return _a.to_static_any (_sa);
}

class _Marshaller_MICOMT_ServerConcurrencyModel : public ::CORBA::StaticTypeInfo {
    typedef MICOMT::ServerConcurrencyModel _MICO_T;
  public:
    ~_Marshaller_MICOMT_ServerConcurrencyModel();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_MICOMT_ServerConcurrencyModel::~_Marshaller_MICOMT_ServerConcurrencyModel()
{
}

::CORBA::StaticValueType _Marshaller_MICOMT_ServerConcurrencyModel::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_MICOMT_ServerConcurrencyModel::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_MICOMT_ServerConcurrencyModel::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_MICOMT_ServerConcurrencyModel::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong ul;
  if( !dc.enumeration( ul ) )
    return FALSE;
  *(_MICO_T*) v = (_MICO_T) ul;
  return TRUE;
}

void _Marshaller_MICOMT_ServerConcurrencyModel::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.enumeration( (::CORBA::ULong) *(_MICO_T *) v );
}

::CORBA::TypeCode_ptr _Marshaller_MICOMT_ServerConcurrencyModel::typecode()
{
  return MICOMT::_tc_ServerConcurrencyModel;
}

::CORBA::StaticTypeInfo *_marshaller_MICOMT_ServerConcurrencyModel;

namespace MICOMT
{
CORBA::TypeCodeConst _tc_ClientConcurrencyModel;
}

void operator<<=( CORBA::Any &_a, const MICOMT::ClientConcurrencyModel &_e )
{
  CORBA::StaticAny _sa (_marshaller_MICOMT_ClientConcurrencyModel, &_e);
  _a.from_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, MICOMT::ClientConcurrencyModel &_e )
{
  CORBA::StaticAny _sa (_marshaller_MICOMT_ClientConcurrencyModel, &_e);
  return _a.to_static_any (_sa);
}

class _Marshaller_MICOMT_ClientConcurrencyModel : public ::CORBA::StaticTypeInfo {
    typedef MICOMT::ClientConcurrencyModel _MICO_T;
  public:
    ~_Marshaller_MICOMT_ClientConcurrencyModel();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_MICOMT_ClientConcurrencyModel::~_Marshaller_MICOMT_ClientConcurrencyModel()
{
}

::CORBA::StaticValueType _Marshaller_MICOMT_ClientConcurrencyModel::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_MICOMT_ClientConcurrencyModel::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_MICOMT_ClientConcurrencyModel::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_MICOMT_ClientConcurrencyModel::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong ul;
  if( !dc.enumeration( ul ) )
    return FALSE;
  *(_MICO_T*) v = (_MICO_T) ul;
  return TRUE;
}

void _Marshaller_MICOMT_ClientConcurrencyModel::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.enumeration( (::CORBA::ULong) *(_MICO_T *) v );
}

::CORBA::TypeCode_ptr _Marshaller_MICOMT_ClientConcurrencyModel::typecode()
{
  return MICOMT::_tc_ClientConcurrencyModel;
}

::CORBA::StaticTypeInfo *_marshaller_MICOMT_ClientConcurrencyModel;

struct __tc_init_MTTYPES {
  __tc_init_MTTYPES()
  {
    MICOMT::_tc_ServerConcurrencyModel = 
    "01000000110000007a000000010000002600000049444c3a4d49434f4d54"
    "2f536572766572436f6e63757272656e63794d6f64656c3a312e30000000"
    "17000000536572766572436f6e63757272656e63794d6f64656c00000200"
    "00000c0000005448524541445f504f4f4c00160000005448524541445f50"
    "45525f434f4e4e454354494f4e00";
    _marshaller_MICOMT_ServerConcurrencyModel = new _Marshaller_MICOMT_ServerConcurrencyModel;
    MICOMT::_tc_ClientConcurrencyModel = 
    "010000001100000086000000010000002600000049444c3a4d49434f4d54"
    "2f436c69656e74436f6e63757272656e63794d6f64656c3a312e30000000"
    "17000000436c69656e74436f6e63757272656e63794d6f64656c00000300"
    "000009000000524541435449564500000000090000005448524541444544"
    "0000000012000000424c4f434b494e475f544852454144454400";
    _marshaller_MICOMT_ClientConcurrencyModel = new _Marshaller_MICOMT_ClientConcurrencyModel;
  }

  ~__tc_init_MTTYPES()
  {
    delete static_cast<_Marshaller_MICOMT_ServerConcurrencyModel*>(_marshaller_MICOMT_ServerConcurrencyModel);
    delete static_cast<_Marshaller_MICOMT_ClientConcurrencyModel*>(_marshaller_MICOMT_ClientConcurrencyModel);
  }
};

static __tc_init_MTTYPES __init_MTTYPES;

//--------------------------------------------------------
//  Implementation of skeletons
//--------------------------------------------------------
