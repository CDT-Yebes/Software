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

/*
 * Base interface for class ArgsHolder
 */

SL3AQArgs::ArgsHolder::~ArgsHolder()
{
}

void *
SL3AQArgs::ArgsHolder::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/ArgsHolder:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::ArgsHolder_ptr
SL3AQArgs::ArgsHolder::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/ArgsHolder:1.0" )))
      return _duplicate( (SL3AQArgs::ArgsHolder_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::ArgsHolder_ptr
SL3AQArgs::ArgsHolder::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_ArgsHolder;
}


/*
 * Base interface for class CSIv1Support
 */

SL3AQArgs::CSIv1Support::~CSIv1Support()
{
}

void *
SL3AQArgs::CSIv1Support::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/CSIv1Support:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::CSIv1Support_ptr
SL3AQArgs::CSIv1Support::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/CSIv1Support:1.0" )))
      return _duplicate( (SL3AQArgs::CSIv1Support_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::CSIv1Support_ptr
SL3AQArgs::CSIv1Support::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_CSIv1Support;
}


/*
 * Base interface for class CSIv2Support
 */

SL3AQArgs::CSIv2Support::~CSIv2Support()
{
}

void *
SL3AQArgs::CSIv2Support::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/CSIv2Support:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::CSIv2Support_ptr
SL3AQArgs::CSIv2Support::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/CSIv2Support:1.0" )))
      return _duplicate( (SL3AQArgs::CSIv2Support_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::CSIv2Support_ptr
SL3AQArgs::CSIv2Support::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_CSIv2Support;
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_TCPIPInitiatorOptions;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
SL3AQArgs::TCPIPInitiatorOptions::TCPIPInitiatorOptions()
{
}

SL3AQArgs::TCPIPInitiatorOptions::TCPIPInitiatorOptions( const TCPIPInitiatorOptions& _s )
{
  bind = ((TCPIPInitiatorOptions&)_s).bind;
  low_port = ((TCPIPInitiatorOptions&)_s).low_port;
  high_port = ((TCPIPInitiatorOptions&)_s).high_port;
  timeout = ((TCPIPInitiatorOptions&)_s).timeout;
}

SL3AQArgs::TCPIPInitiatorOptions::~TCPIPInitiatorOptions()
{
}

SL3AQArgs::TCPIPInitiatorOptions&
SL3AQArgs::TCPIPInitiatorOptions::operator=( const TCPIPInitiatorOptions& _s )
{
  bind = ((TCPIPInitiatorOptions&)_s).bind;
  low_port = ((TCPIPInitiatorOptions&)_s).low_port;
  high_port = ((TCPIPInitiatorOptions&)_s).high_port;
  timeout = ((TCPIPInitiatorOptions&)_s).timeout;
  return *this;
}
#endif

class _Marshaller_SL3AQArgs_TCPIPInitiatorOptions : public ::CORBA::StaticTypeInfo {
    typedef SL3AQArgs::TCPIPInitiatorOptions _MICO_T;
  public:
    ~_Marshaller_SL3AQArgs_TCPIPInitiatorOptions();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3AQArgs_TCPIPInitiatorOptions::~_Marshaller_SL3AQArgs_TCPIPInitiatorOptions()
{
}

::CORBA::StaticValueType _Marshaller_SL3AQArgs_TCPIPInitiatorOptions::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_SL3AQArgs_TCPIPInitiatorOptions::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3AQArgs_TCPIPInitiatorOptions::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3AQArgs_TCPIPInitiatorOptions::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->bind._for_demarshal() ) &&
    CORBA::_stc_long->demarshal( dc, &((_MICO_T*)v)->low_port ) &&
    CORBA::_stc_long->demarshal( dc, &((_MICO_T*)v)->high_port ) &&
    CORBA::_stc_long->demarshal( dc, &((_MICO_T*)v)->timeout ) &&
    dc.struct_end();
}

void _Marshaller_SL3AQArgs_TCPIPInitiatorOptions::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->bind.inout() );
  CORBA::_stc_long->marshal( ec, &((_MICO_T*)v)->low_port );
  CORBA::_stc_long->marshal( ec, &((_MICO_T*)v)->high_port );
  CORBA::_stc_long->marshal( ec, &((_MICO_T*)v)->timeout );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_SL3AQArgs_TCPIPInitiatorOptions::typecode()
{
  return SL3AQArgs::_tc_TCPIPInitiatorOptions;
}

::CORBA::StaticTypeInfo *_marshaller_SL3AQArgs_TCPIPInitiatorOptions;

void operator<<=( CORBA::Any &_a, const SL3AQArgs::TCPIPInitiatorOptions &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3AQArgs_TCPIPInitiatorOptions, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SL3AQArgs::TCPIPInitiatorOptions *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SL3AQArgs::TCPIPInitiatorOptions &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3AQArgs_TCPIPInitiatorOptions, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SL3AQArgs::TCPIPInitiatorOptions *&_s )
{
  return _a.to_static_any (_marshaller_SL3AQArgs_TCPIPInitiatorOptions, (void *&)_s);
}


/*
 * Base interface for class TCPIPInitiatorArgument
 */

SL3AQArgs::TCPIPInitiatorArgument::~TCPIPInitiatorArgument()
{
}

void *
SL3AQArgs::TCPIPInitiatorArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/TCPIPInitiatorArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::TCPIPInitiatorArgument_ptr
SL3AQArgs::TCPIPInitiatorArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/TCPIPInitiatorArgument:1.0" )))
      return _duplicate( (SL3AQArgs::TCPIPInitiatorArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::TCPIPInitiatorArgument_ptr
SL3AQArgs::TCPIPInitiatorArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_TCPIPInitiatorArgument;
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_TCPIPAcceptorOptions;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
SL3AQArgs::TCPIPAcceptorOptions::TCPIPAcceptorOptions()
{
}

SL3AQArgs::TCPIPAcceptorOptions::TCPIPAcceptorOptions( const TCPIPAcceptorOptions& _s )
{
  hosts = ((TCPIPAcceptorOptions&)_s).hosts;
  bind = ((TCPIPAcceptorOptions&)_s).bind;
  low_port = ((TCPIPAcceptorOptions&)_s).low_port;
  high_port = ((TCPIPAcceptorOptions&)_s).high_port;
  backlog = ((TCPIPAcceptorOptions&)_s).backlog;
  numeric = ((TCPIPAcceptorOptions&)_s).numeric;
}

SL3AQArgs::TCPIPAcceptorOptions::~TCPIPAcceptorOptions()
{
}

SL3AQArgs::TCPIPAcceptorOptions&
SL3AQArgs::TCPIPAcceptorOptions::operator=( const TCPIPAcceptorOptions& _s )
{
  hosts = ((TCPIPAcceptorOptions&)_s).hosts;
  bind = ((TCPIPAcceptorOptions&)_s).bind;
  low_port = ((TCPIPAcceptorOptions&)_s).low_port;
  high_port = ((TCPIPAcceptorOptions&)_s).high_port;
  backlog = ((TCPIPAcceptorOptions&)_s).backlog;
  numeric = ((TCPIPAcceptorOptions&)_s).numeric;
  return *this;
}
#endif

class _Marshaller_SL3AQArgs_TCPIPAcceptorOptions : public ::CORBA::StaticTypeInfo {
    typedef SL3AQArgs::TCPIPAcceptorOptions _MICO_T;
  public:
    ~_Marshaller_SL3AQArgs_TCPIPAcceptorOptions();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3AQArgs_TCPIPAcceptorOptions::~_Marshaller_SL3AQArgs_TCPIPAcceptorOptions()
{
}

::CORBA::StaticValueType _Marshaller_SL3AQArgs_TCPIPAcceptorOptions::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_SL3AQArgs_TCPIPAcceptorOptions::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3AQArgs_TCPIPAcceptorOptions::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3AQArgs_TCPIPAcceptorOptions::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    CORBA::_stcseq_string->demarshal( dc, &((_MICO_T*)v)->hosts ) &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->bind._for_demarshal() ) &&
    CORBA::_stc_long->demarshal( dc, &((_MICO_T*)v)->low_port ) &&
    CORBA::_stc_long->demarshal( dc, &((_MICO_T*)v)->high_port ) &&
    CORBA::_stc_long->demarshal( dc, &((_MICO_T*)v)->backlog ) &&
    CORBA::_stc_boolean->demarshal( dc, &((_MICO_T*)v)->numeric ) &&
    dc.struct_end();
}

void _Marshaller_SL3AQArgs_TCPIPAcceptorOptions::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  CORBA::_stcseq_string->marshal( ec, &((_MICO_T*)v)->hosts );
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->bind.inout() );
  CORBA::_stc_long->marshal( ec, &((_MICO_T*)v)->low_port );
  CORBA::_stc_long->marshal( ec, &((_MICO_T*)v)->high_port );
  CORBA::_stc_long->marshal( ec, &((_MICO_T*)v)->backlog );
  CORBA::_stc_boolean->marshal( ec, &((_MICO_T*)v)->numeric );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_SL3AQArgs_TCPIPAcceptorOptions::typecode()
{
  return SL3AQArgs::_tc_TCPIPAcceptorOptions;
}

::CORBA::StaticTypeInfo *_marshaller_SL3AQArgs_TCPIPAcceptorOptions;

void operator<<=( CORBA::Any &_a, const SL3AQArgs::TCPIPAcceptorOptions &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3AQArgs_TCPIPAcceptorOptions, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SL3AQArgs::TCPIPAcceptorOptions *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SL3AQArgs::TCPIPAcceptorOptions &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3AQArgs_TCPIPAcceptorOptions, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SL3AQArgs::TCPIPAcceptorOptions *&_s )
{
  return _a.to_static_any (_marshaller_SL3AQArgs_TCPIPAcceptorOptions, (void *&)_s);
}


/*
 * Base interface for class TCPIPAcceptorArgument
 */

SL3AQArgs::TCPIPAcceptorArgument::~TCPIPAcceptorArgument()
{
}

void *
SL3AQArgs::TCPIPAcceptorArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/TCPIPAcceptorArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::TCPIPAcceptorArgument_ptr
SL3AQArgs::TCPIPAcceptorArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/TCPIPAcceptorArgument:1.0" )))
      return _duplicate( (SL3AQArgs::TCPIPAcceptorArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::TCPIPAcceptorArgument_ptr
SL3AQArgs::TCPIPAcceptorArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_TCPIPAcceptorArgument;
}


/*
 * Base interface for class TLSX509IdentityVerifierInitiatorArgument
 */

SL3AQArgs::TLSX509IdentityVerifierInitiatorArgument::~TLSX509IdentityVerifierInitiatorArgument()
{
}

void *
SL3AQArgs::TLSX509IdentityVerifierInitiatorArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/TLSX509IdentityVerifierInitiatorArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::TLSX509IdentityVerifierInitiatorArgument_ptr
SL3AQArgs::TLSX509IdentityVerifierInitiatorArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/TLSX509IdentityVerifierInitiatorArgument:1.0" )))
      return _duplicate( (SL3AQArgs::TLSX509IdentityVerifierInitiatorArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::TLSX509IdentityVerifierInitiatorArgument_ptr
SL3AQArgs::TLSX509IdentityVerifierInitiatorArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_TLSX509IdentityVerifierInitiatorArgument;
}


/*
 * Base interface for class TLSX509IdentityVerifierAcceptorArgument
 */

SL3AQArgs::TLSX509IdentityVerifierAcceptorArgument::~TLSX509IdentityVerifierAcceptorArgument()
{
}

void *
SL3AQArgs::TLSX509IdentityVerifierAcceptorArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/TLSX509IdentityVerifierAcceptorArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::TLSX509IdentityVerifierAcceptorArgument_ptr
SL3AQArgs::TLSX509IdentityVerifierAcceptorArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/TLSX509IdentityVerifierAcceptorArgument:1.0" )))
      return _duplicate( (SL3AQArgs::TLSX509IdentityVerifierAcceptorArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::TLSX509IdentityVerifierAcceptorArgument_ptr
SL3AQArgs::TLSX509IdentityVerifierAcceptorArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_TLSX509IdentityVerifierAcceptorArgument;
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_OpenSSLConfig;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
SL3AQArgs::OpenSSLConfig::OpenSSLConfig()
{
}

SL3AQArgs::OpenSSLConfig::OpenSSLConfig( const OpenSSLConfig& _s )
{
  cert_file = ((OpenSSLConfig&)_s).cert_file;
  key_file = ((OpenSSLConfig&)_s).key_file;
  ca_file = ((OpenSSLConfig&)_s).ca_file;
  ca_path = ((OpenSSLConfig&)_s).ca_path;
  cipher = ((OpenSSLConfig&)_s).cipher;
  use_passphrase = ((OpenSSLConfig&)_s).use_passphrase;
  passphrase = ((OpenSSLConfig&)_s).passphrase;
  verify_depth = ((OpenSSLConfig&)_s).verify_depth;
}

SL3AQArgs::OpenSSLConfig::~OpenSSLConfig()
{
}

SL3AQArgs::OpenSSLConfig&
SL3AQArgs::OpenSSLConfig::operator=( const OpenSSLConfig& _s )
{
  cert_file = ((OpenSSLConfig&)_s).cert_file;
  key_file = ((OpenSSLConfig&)_s).key_file;
  ca_file = ((OpenSSLConfig&)_s).ca_file;
  ca_path = ((OpenSSLConfig&)_s).ca_path;
  cipher = ((OpenSSLConfig&)_s).cipher;
  use_passphrase = ((OpenSSLConfig&)_s).use_passphrase;
  passphrase = ((OpenSSLConfig&)_s).passphrase;
  verify_depth = ((OpenSSLConfig&)_s).verify_depth;
  return *this;
}
#endif

class _Marshaller_SL3AQArgs_OpenSSLConfig : public ::CORBA::StaticTypeInfo {
    typedef SL3AQArgs::OpenSSLConfig _MICO_T;
  public:
    ~_Marshaller_SL3AQArgs_OpenSSLConfig();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_SL3AQArgs_OpenSSLConfig::~_Marshaller_SL3AQArgs_OpenSSLConfig()
{
}

::CORBA::StaticValueType _Marshaller_SL3AQArgs_OpenSSLConfig::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_SL3AQArgs_OpenSSLConfig::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_SL3AQArgs_OpenSSLConfig::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_SL3AQArgs_OpenSSLConfig::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->cert_file._for_demarshal() ) &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->key_file._for_demarshal() ) &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->ca_file._for_demarshal() ) &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->ca_path._for_demarshal() ) &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->cipher._for_demarshal() ) &&
    CORBA::_stc_boolean->demarshal( dc, &((_MICO_T*)v)->use_passphrase ) &&
    CORBA::_stc_string->demarshal( dc, &((_MICO_T*)v)->passphrase._for_demarshal() ) &&
    CORBA::_stc_long->demarshal( dc, &((_MICO_T*)v)->verify_depth ) &&
    dc.struct_end();
}

void _Marshaller_SL3AQArgs_OpenSSLConfig::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->cert_file.inout() );
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->key_file.inout() );
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->ca_file.inout() );
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->ca_path.inout() );
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->cipher.inout() );
  CORBA::_stc_boolean->marshal( ec, &((_MICO_T*)v)->use_passphrase );
  CORBA::_stc_string->marshal( ec, &((_MICO_T*)v)->passphrase.inout() );
  CORBA::_stc_long->marshal( ec, &((_MICO_T*)v)->verify_depth );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_SL3AQArgs_OpenSSLConfig::typecode()
{
  return SL3AQArgs::_tc_OpenSSLConfig;
}

::CORBA::StaticTypeInfo *_marshaller_SL3AQArgs_OpenSSLConfig;

void operator<<=( CORBA::Any &_a, const SL3AQArgs::OpenSSLConfig &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3AQArgs_OpenSSLConfig, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, SL3AQArgs::OpenSSLConfig *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, SL3AQArgs::OpenSSLConfig &_s )
{
  CORBA::StaticAny _sa (_marshaller_SL3AQArgs_OpenSSLConfig, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const SL3AQArgs::OpenSSLConfig *&_s )
{
  return _a.to_static_any (_marshaller_SL3AQArgs_OpenSSLConfig, (void *&)_s);
}


/*
 * Base interface for class OpenSSLInitiatorArgument
 */

SL3AQArgs::OpenSSLInitiatorArgument::~OpenSSLInitiatorArgument()
{
}

void *
SL3AQArgs::OpenSSLInitiatorArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/OpenSSLInitiatorArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::OpenSSLInitiatorArgument_ptr
SL3AQArgs::OpenSSLInitiatorArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/OpenSSLInitiatorArgument:1.0" )))
      return _duplicate( (SL3AQArgs::OpenSSLInitiatorArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::OpenSSLInitiatorArgument_ptr
SL3AQArgs::OpenSSLInitiatorArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_OpenSSLInitiatorArgument;
}


/*
 * Base interface for class OpenSSLAcceptorArgument
 */

SL3AQArgs::OpenSSLAcceptorArgument::~OpenSSLAcceptorArgument()
{
}

void *
SL3AQArgs::OpenSSLAcceptorArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/OpenSSLAcceptorArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::OpenSSLAcceptorArgument_ptr
SL3AQArgs::OpenSSLAcceptorArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/OpenSSLAcceptorArgument:1.0" )))
      return _duplicate( (SL3AQArgs::OpenSSLAcceptorArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::OpenSSLAcceptorArgument_ptr
SL3AQArgs::OpenSSLAcceptorArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_OpenSSLAcceptorArgument;
}


/*
 * Base interface for class TransportCredentialsArgument
 */

SL3AQArgs::TransportCredentialsArgument::~TransportCredentialsArgument()
{
}

void *
SL3AQArgs::TransportCredentialsArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/TransportCredentialsArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::TransportCredentialsArgument_ptr
SL3AQArgs::TransportCredentialsArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/TransportCredentialsArgument:1.0" )))
      return _duplicate( (SL3AQArgs::TransportCredentialsArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::TransportCredentialsArgument_ptr
SL3AQArgs::TransportCredentialsArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_TransportCredentialsArgument;
}


/*
 * Base interface for class DeciderArgument
 */

SL3AQArgs::DeciderArgument::~DeciderArgument()
{
}

void *
SL3AQArgs::DeciderArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/DeciderArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::DeciderArgument_ptr
SL3AQArgs::DeciderArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/DeciderArgument:1.0" )))
      return _duplicate( (SL3AQArgs::DeciderArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::DeciderArgument_ptr
SL3AQArgs::DeciderArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_DeciderArgument;
}


/*
 * Base interface for class GeneratorArgument
 */

SL3AQArgs::GeneratorArgument::~GeneratorArgument()
{
}

void *
SL3AQArgs::GeneratorArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/GeneratorArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::GeneratorArgument_ptr
SL3AQArgs::GeneratorArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/GeneratorArgument:1.0" )))
      return _duplicate( (SL3AQArgs::GeneratorArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::GeneratorArgument_ptr
SL3AQArgs::GeneratorArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_GeneratorArgument;
}


/*
 * Base interface for class ProcessorArgument
 */

SL3AQArgs::ProcessorArgument::~ProcessorArgument()
{
}

void *
SL3AQArgs::ProcessorArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/ProcessorArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::ProcessorArgument_ptr
SL3AQArgs::ProcessorArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/ProcessorArgument:1.0" )))
      return _duplicate( (SL3AQArgs::ProcessorArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::ProcessorArgument_ptr
SL3AQArgs::ProcessorArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_ProcessorArgument;
}


/*
 * Base interface for class QuotingPrincipalArgument
 */

SL3AQArgs::QuotingPrincipalArgument::~QuotingPrincipalArgument()
{
}

void *
SL3AQArgs::QuotingPrincipalArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/QuotingPrincipalArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::QuotingPrincipalArgument_ptr
SL3AQArgs::QuotingPrincipalArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/QuotingPrincipalArgument:1.0" )))
      return _duplicate( (SL3AQArgs::QuotingPrincipalArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::QuotingPrincipalArgument_ptr
SL3AQArgs::QuotingPrincipalArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_QuotingPrincipalArgument;
}


/*
 * Base interface for class ATLASArgument
 */

SL3AQArgs::ATLASArgument::~ATLASArgument()
{
}

void *
SL3AQArgs::ATLASArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/ATLASArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::ATLASArgument_ptr
SL3AQArgs::ATLASArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/ATLASArgument:1.0" )))
      return _duplicate( (SL3AQArgs::ATLASArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::ATLASArgument_ptr
SL3AQArgs::ATLASArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_ATLASArgument;
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_TokenProcessorSeq;
}


/*
 * Base interface for class TokenProcessorSeqArgument
 */

SL3AQArgs::TokenProcessorSeqArgument::~TokenProcessorSeqArgument()
{
}

void *
SL3AQArgs::TokenProcessorSeqArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/TokenProcessorSeqArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::TokenProcessorSeqArgument_ptr
SL3AQArgs::TokenProcessorSeqArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/TokenProcessorSeqArgument:1.0" )))
      return _duplicate( (SL3AQArgs::TokenProcessorSeqArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::TokenProcessorSeqArgument_ptr
SL3AQArgs::TokenProcessorSeqArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_TokenProcessorSeqArgument;
}


/*
 * Base interface for class IPCInitiatorArgument
 */

SL3AQArgs::IPCInitiatorArgument::~IPCInitiatorArgument()
{
}

void *
SL3AQArgs::IPCInitiatorArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/IPCInitiatorArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::IPCInitiatorArgument_ptr
SL3AQArgs::IPCInitiatorArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/IPCInitiatorArgument:1.0" )))
      return _duplicate( (SL3AQArgs::IPCInitiatorArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::IPCInitiatorArgument_ptr
SL3AQArgs::IPCInitiatorArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_IPCInitiatorArgument;
}


/*
 * Base interface for class IPCAcceptorArgument
 */

SL3AQArgs::IPCAcceptorArgument::~IPCAcceptorArgument()
{
}

void *
SL3AQArgs::IPCAcceptorArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/IPCAcceptorArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::IPCAcceptorArgument_ptr
SL3AQArgs::IPCAcceptorArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/IPCAcceptorArgument:1.0" )))
      return _duplicate( (SL3AQArgs::IPCAcceptorArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::IPCAcceptorArgument_ptr
SL3AQArgs::IPCAcceptorArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_IPCAcceptorArgument;
}


/*
 * Base interface for class ObserverSeqArgument
 */

SL3AQArgs::ObserverSeqArgument::~ObserverSeqArgument()
{
}

void *
SL3AQArgs::ObserverSeqArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/ObserverSeqArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::ObserverSeqArgument_ptr
SL3AQArgs::ObserverSeqArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/ObserverSeqArgument:1.0" )))
      return _duplicate( (SL3AQArgs::ObserverSeqArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::ObserverSeqArgument_ptr
SL3AQArgs::ObserverSeqArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_ObserverSeqArgument;
}


/*
 * Base interface for class IdentityProcessorArgument
 */

SL3AQArgs::IdentityProcessorArgument::~IdentityProcessorArgument()
{
}

void *
SL3AQArgs::IdentityProcessorArgument::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:SL3AQArgs/IdentityProcessorArgument:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = SL3AQArgs::Argument::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

SL3AQArgs::IdentityProcessorArgument_ptr
SL3AQArgs::IdentityProcessorArgument::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:SL3AQArgs/IdentityProcessorArgument:1.0" )))
      return _duplicate( (SL3AQArgs::IdentityProcessorArgument_ptr) _p );
  }
  return _nil();
}

SL3AQArgs::IdentityProcessorArgument_ptr
SL3AQArgs::IdentityProcessorArgument::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace SL3AQArgs
{
CORBA::TypeCodeConst _tc_IdentityProcessorArgument;
}

struct __tc_init_SL3AQARGS_P {
  __tc_init_SL3AQARGS_P()
  {
    SL3AQArgs::_tc_ArgsHolder = 
    "010000000e00000037000000010000001d00000049444c3a534c33415141"
    "7267732f41726773486f6c6465723a312e30000000000b00000041726773"
    "486f6c64657200";
    SL3AQArgs::_tc_CSIv1Support = 
    "010000000e00000039000000010000001f00000049444c3a534c33415141"
    "7267732f4353497631537570706f72743a312e3000000d00000043534976"
    "31537570706f727400";
    SL3AQArgs::_tc_CSIv2Support = 
    "010000000e00000039000000010000001f00000049444c3a534c33415141"
    "7267732f4353497632537570706f72743a312e3000000d00000043534976"
    "32537570706f727400";
    SL3AQArgs::_tc_TCPIPInitiatorOptions = 
    "010000000f0000009c000000010000002800000049444c3a534c33415141"
    "7267732f5443504950496e69746961746f724f7074696f6e733a312e3000"
    "160000005443504950496e69746961746f724f7074696f6e730000000400"
    "00000500000062696e64000000001200000000000000090000006c6f775f"
    "706f727400000000030000000a000000686967685f706f72740000000300"
    "00000800000074696d656f75740003000000";
    _marshaller_SL3AQArgs_TCPIPInitiatorOptions = new _Marshaller_SL3AQArgs_TCPIPInitiatorOptions;
    SL3AQArgs::_tc_TCPIPInitiatorArgument = 
    "010000000e0000004f000000010000002900000049444c3a534c33415141"
    "7267732f5443504950496e69746961746f72417267756d656e743a312e30"
    "00000000170000005443504950496e69746961746f72417267756d656e74"
    "00";
    SL3AQArgs::_tc_TCPIPAcceptorOptions = 
    "010000000f00000010010000010000002700000049444c3a534c33415141"
    "7267732f54435049504163636570746f724f7074696f6e733a312e300000"
    "1500000054435049504163636570746f724f7074696f6e73000000000600"
    "000006000000686f73747300000015000000500000000100000020000000"
    "49444c3a6f6d672e6f72672f434f5242412f537472696e675365713a312e"
    "30000a000000537472696e67536571000000130000001000000001000000"
    "1200000000000000000000000500000062696e6400000000120000000000"
    "0000090000006c6f775f706f727400000000030000000a00000068696768"
    "5f706f727400000003000000080000006261636b6c6f6700030000000800"
    "00006e756d657269630008000000";
    _marshaller_SL3AQArgs_TCPIPAcceptorOptions = new _Marshaller_SL3AQArgs_TCPIPAcceptorOptions;
    SL3AQArgs::_tc_TCPIPAcceptorArgument = 
    "010000000e0000004a000000010000002800000049444c3a534c33415141"
    "7267732f54435049504163636570746f72417267756d656e743a312e3000"
    "1600000054435049504163636570746f72417267756d656e7400";
    SL3AQArgs::_tc_TLSX509IdentityVerifierInitiatorArgument = 
    "010000000e00000071000000010000003b00000049444c3a534c33415141"
    "7267732f544c53583530394964656e746974795665726966696572496e69"
    "746961746f72417267756d656e743a312e30000029000000544c53583530"
    "394964656e746974795665726966696572496e69746961746f7241726775"
    "6d656e7400";
    SL3AQArgs::_tc_TLSX509IdentityVerifierAcceptorArgument = 
    "010000000e00000070000000010000003a00000049444c3a534c33415141"
    "7267732f544c53583530394964656e746974795665726966696572416363"
    "6570746f72417267756d656e743a312e3000000028000000544c53583530"
    "394964656e7469747956657269666965724163636570746f72417267756d"
    "656e7400";
    SL3AQArgs::_tc_OpenSSLConfig = 
    "010000000f000000f4000000010000002000000049444c3a534c33415141"
    "7267732f4f70656e53534c436f6e6669673a312e30000e0000004f70656e"
    "53534c436f6e666967000000080000000a000000636572745f66696c6500"
    "00001200000000000000090000006b65795f66696c650000000012000000"
    "000000000800000063615f66696c65001200000000000000080000006361"
    "5f7061746800120000000000000007000000636970686572000012000000"
    "000000000f0000007573655f706173737068726173650000080000000b00"
    "000070617373706872617365000012000000000000000d00000076657269"
    "66795f64657074680000000003000000";
    _marshaller_SL3AQArgs_OpenSSLConfig = new _Marshaller_SL3AQArgs_OpenSSLConfig;
    SL3AQArgs::_tc_OpenSSLInitiatorArgument = 
    "010000000e00000051000000010000002b00000049444c3a534c33415141"
    "7267732f4f70656e53534c496e69746961746f72417267756d656e743a31"
    "2e300000190000004f70656e53534c496e69746961746f72417267756d65"
    "6e7400";
    SL3AQArgs::_tc_OpenSSLAcceptorArgument = 
    "010000000e00000050000000010000002a00000049444c3a534c33415141"
    "7267732f4f70656e53534c4163636570746f72417267756d656e743a312e"
    "30000000180000004f70656e53534c4163636570746f72417267756d656e"
    "7400";
    SL3AQArgs::_tc_TransportCredentialsArgument = 
    "010000000e00000059000000010000002f00000049444c3a534c33415141"
    "7267732f5472616e73706f727443726564656e7469616c73417267756d65"
    "6e743a312e3000001d0000005472616e73706f727443726564656e746961"
    "6c73417267756d656e7400";
    SL3AQArgs::_tc_DeciderArgument = 
    "010000000e00000040000000010000002200000049444c3a534c33415141"
    "7267732f44656369646572417267756d656e743a312e3000000010000000"
    "44656369646572417267756d656e7400";
    SL3AQArgs::_tc_GeneratorArgument = 
    "010000000e00000042000000010000002400000049444c3a534c33415141"
    "7267732f47656e657261746f72417267756d656e743a312e300012000000"
    "47656e657261746f72417267756d656e7400";
    SL3AQArgs::_tc_ProcessorArgument = 
    "010000000e00000042000000010000002400000049444c3a534c33415141"
    "7267732f50726f636573736f72417267756d656e743a312e300012000000"
    "50726f636573736f72417267756d656e7400";
    SL3AQArgs::_tc_QuotingPrincipalArgument = 
    "010000000e00000051000000010000002b00000049444c3a534c33415141"
    "7267732f51756f74696e675072696e636970616c417267756d656e743a31"
    "2e3000001900000051756f74696e675072696e636970616c417267756d65"
    "6e7400";
    SL3AQArgs::_tc_ATLASArgument = 
    "010000000e0000003a000000010000002000000049444c3a534c33415141"
    "7267732f41544c4153417267756d656e743a312e30000e00000041544c41"
    "53417267756d656e7400";
    SL3AQArgs::_tc_TokenProcessorSeq = 
    "0100000015000000ac000000010000002400000049444c3a534c33415141"
    "7267732f546f6b656e50726f636573736f725365713a312e300012000000"
    "546f6b656e50726f636573736f7253657100000013000000600000000100"
    "00000e0000004f000000010000003300000049444c3a616469726f6e2e63"
    "6f6d2f534c33417574686f72697a6174696f6e2f546f6b656e50726f6365"
    "73736f723a312e3000000f000000546f6b656e50726f636573736f720000"
    "00000000";
    SL3AQArgs::_tc_TokenProcessorSeqArgument = 
    "010000000e00000052000000010000002c00000049444c3a534c33415141"
    "7267732f546f6b656e50726f636573736f72536571417267756d656e743a"
    "312e30001a000000546f6b656e50726f636573736f72536571417267756d"
    "656e7400";
    SL3AQArgs::_tc_IPCInitiatorArgument = 
    "010000000e00000049000000010000002700000049444c3a534c33415141"
    "7267732f495043496e69746961746f72417267756d656e743a312e300000"
    "15000000495043496e69746961746f72417267756d656e7400";
    SL3AQArgs::_tc_IPCAcceptorArgument = 
    "010000000e00000048000000010000002600000049444c3a534c33415141"
    "7267732f4950434163636570746f72417267756d656e743a312e30000000"
    "140000004950434163636570746f72417267756d656e7400";
    SL3AQArgs::_tc_ObserverSeqArgument = 
    "010000000e00000048000000010000002600000049444c3a534c33415141"
    "7267732f4f62736572766572536571417267756d656e743a312e30000000"
    "140000004f62736572766572536571417267756d656e7400";
    SL3AQArgs::_tc_IdentityProcessorArgument = 
    "010000000e00000052000000010000002c00000049444c3a534c33415141"
    "7267732f4964656e7469747950726f636573736f72417267756d656e743a"
    "312e30001a0000004964656e7469747950726f636573736f72417267756d"
    "656e7400";
  }

  ~__tc_init_SL3AQARGS_P()
  {
    delete static_cast<_Marshaller_SL3AQArgs_TCPIPInitiatorOptions*>(_marshaller_SL3AQArgs_TCPIPInitiatorOptions);
    delete static_cast<_Marshaller_SL3AQArgs_TCPIPAcceptorOptions*>(_marshaller_SL3AQArgs_TCPIPAcceptorOptions);
    delete static_cast<_Marshaller_SL3AQArgs_OpenSSLConfig*>(_marshaller_SL3AQArgs_OpenSSLConfig);
  }
};

static __tc_init_SL3AQARGS_P __init_SL3AQARGS_P;

