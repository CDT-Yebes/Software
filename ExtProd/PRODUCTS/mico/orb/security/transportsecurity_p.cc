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
namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_ContextEstablisherId;
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_ContextEstablisherIdList;
}


/*
 * Base interface for class ContextEstablisher
 */

TransportSecurity::ContextEstablisher::~ContextEstablisher()
{
}

void *
TransportSecurity::ContextEstablisher::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/ContextEstablisher:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

TransportSecurity::ContextEstablisher_ptr
TransportSecurity::ContextEstablisher::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/ContextEstablisher:1.0" )))
      return _duplicate( (TransportSecurity::ContextEstablisher_ptr) _p );
  }
  return _nil();
}

TransportSecurity::ContextEstablisher_ptr
TransportSecurity::ContextEstablisher::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_ContextEstablisher;
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_ContextEstablisherList;
}


/*
 * Base interface for class InitiatingContext
 */

TransportSecurity::InitiatingContext::~InitiatingContext()
{
}

void *
TransportSecurity::InitiatingContext::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/InitiatingContext:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = TransportSecurity::TargetCredentials::_narrow_helper( _repoid )))
      return _p;
  }
  {
    void *_p;
    if ((_p = SL3OM::CredentialsObserver::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

TransportSecurity::InitiatingContext_ptr
TransportSecurity::InitiatingContext::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/InitiatingContext:1.0" )))
      return _duplicate( (TransportSecurity::InitiatingContext_ptr) _p );
  }
  return _nil();
}

TransportSecurity::InitiatingContext_ptr
TransportSecurity::InitiatingContext::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_InitiatingContext;
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_InitiatingContextList;
}


/*
 * Base interface for class AcceptingContext
 */

TransportSecurity::AcceptingContext::~AcceptingContext()
{
}

void *
TransportSecurity::AcceptingContext::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/AcceptingContext:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = TransportSecurity::ClientCredentials::_narrow_helper( _repoid )))
      return _p;
  }
  {
    void *_p;
    if ((_p = SL3OM::CredentialsObserver::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

TransportSecurity::AcceptingContext_ptr
TransportSecurity::AcceptingContext::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/AcceptingContext:1.0" )))
      return _duplicate( (TransportSecurity::AcceptingContext_ptr) _p );
  }
  return _nil();
}

TransportSecurity::AcceptingContext_ptr
TransportSecurity::AcceptingContext::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_AcceptingContext;
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_AcceptingContextList;
}


/*
 * Base interface for class TransportCredentialsCurator
 */

TransportSecurity::TransportCredentialsCurator::~TransportCredentialsCurator()
{
}

void *
TransportSecurity::TransportCredentialsCurator::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/TransportCredentialsCurator:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = TransportSecurity::CredentialsCurator::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

TransportSecurity::TransportCredentialsCurator_ptr
TransportSecurity::TransportCredentialsCurator::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/TransportCredentialsCurator:1.0" )))
      return _duplicate( (TransportSecurity::TransportCredentialsCurator_ptr) _p );
  }
  return _nil();
}

TransportSecurity::TransportCredentialsCurator_ptr
TransportSecurity::TransportCredentialsCurator::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_TransportCredentialsCurator;
}


/*
 * Base interface for class TransportOwnCredentials
 */

TransportSecurity::TransportOwnCredentials::~TransportOwnCredentials()
{
}

void *
TransportSecurity::TransportOwnCredentials::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/TransportOwnCredentials:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = TransportSecurity::OwnCredentials::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

TransportSecurity::TransportOwnCredentials_ptr
TransportSecurity::TransportOwnCredentials::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/TransportOwnCredentials:1.0" )))
      return _duplicate( (TransportSecurity::TransportOwnCredentials_ptr) _p );
  }
  return _nil();
}

TransportSecurity::TransportOwnCredentials_ptr
TransportSecurity::TransportOwnCredentials::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_TransportOwnCredentials;
}


/*
 * Base interface for class TransportInitiator
 */

TransportSecurity::TransportInitiator::~TransportInitiator()
{
}

void *
TransportSecurity::TransportInitiator::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/TransportInitiator:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = TransportSecurity::CredentialsInitiator::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

TransportSecurity::TransportInitiator_ptr
TransportSecurity::TransportInitiator::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/TransportInitiator:1.0" )))
      return _duplicate( (TransportSecurity::TransportInitiator_ptr) _p );
  }
  return _nil();
}

TransportSecurity::TransportInitiator_ptr
TransportSecurity::TransportInitiator::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_TransportInitiator;
}


/*
 * Base interface for class TransportAcceptor
 */

TransportSecurity::TransportAcceptor::~TransportAcceptor()
{
}

void *
TransportSecurity::TransportAcceptor::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/TransportAcceptor:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = TransportSecurity::CredentialsAcceptor::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

TransportSecurity::TransportAcceptor_ptr
TransportSecurity::TransportAcceptor::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/TransportAcceptor:1.0" )))
      return _duplicate( (TransportSecurity::TransportAcceptor_ptr) _p );
  }
  return _nil();
}

TransportSecurity::TransportAcceptor_ptr
TransportSecurity::TransportAcceptor::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_TransportAcceptor;
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_IdentityTokenInfo;
}

#ifdef HAVE_EXPLICIT_STRUCT_OPS
TransportSecurity::IdentityTokenInfo::IdentityTokenInfo()
{
}

TransportSecurity::IdentityTokenInfo::IdentityTokenInfo( const IdentityTokenInfo& _s )
{
  is_absent = ((IdentityTokenInfo&)_s).is_absent;
  is_anonymous = ((IdentityTokenInfo&)_s).is_anonymous;
  the_token = ((IdentityTokenInfo&)_s).the_token;
  the_principal = SL3PM::SimplePrincipal::_narrow ((IdentityTokenInfo&)_s.the_principal->_copy_value());
  the_statement = SL3PM::IdentityStatement::_narrow ((IdentityTokenInfo&)_s.the_statement->_copy_value());
}

TransportSecurity::IdentityTokenInfo::~IdentityTokenInfo()
{
}

TransportSecurity::IdentityTokenInfo&
TransportSecurity::IdentityTokenInfo::operator=( const IdentityTokenInfo& _s )
{
  is_absent = ((IdentityTokenInfo&)_s).is_absent;
  is_anonymous = ((IdentityTokenInfo&)_s).is_anonymous;
  the_token = ((IdentityTokenInfo&)_s).the_token;
  the_principal = SL3PM::SimplePrincipal::_narrow ((IdentityTokenInfo&)_s.the_principal->_copy_value());
  the_statement = SL3PM::IdentityStatement::_narrow ((IdentityTokenInfo&)_s.the_statement->_copy_value());
  return *this;
}
#endif

CORBA::Long
TransportSecurity::IdentityTokenInfo::_count_refs (CORBA::ValueBase::visited * _seen)
{
  CORBA::Long res = 0;
  if (the_principal) {
    res += the_principal->_count_refs (_seen);
  }
  if (the_statement) {
    res += the_statement->_count_refs (_seen);
  }
  return res;
}

void
TransportSecurity::IdentityTokenInfo::_release_members ()
{
  if (the_principal) {
    the_principal->_release_members ();
  }
  the_principal = 0;
  if (the_statement) {
    the_statement->_release_members ();
  }
  the_statement = 0;
}

class _Marshaller_TransportSecurity_IdentityTokenInfo : public ::CORBA::StaticTypeInfo {
    typedef TransportSecurity::IdentityTokenInfo _MICO_T;
  public:
    ~_Marshaller_TransportSecurity_IdentityTokenInfo();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
    ::CORBA::TypeCode_ptr typecode ();
};


_Marshaller_TransportSecurity_IdentityTokenInfo::~_Marshaller_TransportSecurity_IdentityTokenInfo()
{
}

::CORBA::StaticValueType _Marshaller_TransportSecurity_IdentityTokenInfo::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_TransportSecurity_IdentityTokenInfo::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_TransportSecurity_IdentityTokenInfo::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_TransportSecurity_IdentityTokenInfo::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    CORBA::_stc_boolean->demarshal( dc, &((_MICO_T*)v)->is_absent ) &&
    CORBA::_stc_boolean->demarshal( dc, &((_MICO_T*)v)->is_anonymous ) &&
    _marshaller_CSI_IdentityToken->demarshal( dc, &((_MICO_T*)v)->the_token ) &&
    _marshaller_SL3PM_SimplePrincipal->demarshal( dc, &((_MICO_T*)v)->the_principal._for_demarshal() ) &&
    _marshaller_SL3PM_IdentityStatement->demarshal( dc, &((_MICO_T*)v)->the_statement._for_demarshal() ) &&
    dc.struct_end();
}

void _Marshaller_TransportSecurity_IdentityTokenInfo::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  CORBA::_stc_boolean->marshal( ec, &((_MICO_T*)v)->is_absent );
  CORBA::_stc_boolean->marshal( ec, &((_MICO_T*)v)->is_anonymous );
  _marshaller_CSI_IdentityToken->marshal( ec, &((_MICO_T*)v)->the_token );
  _marshaller_SL3PM_SimplePrincipal->marshal( ec, &((_MICO_T*)v)->the_principal.inout() );
  _marshaller_SL3PM_IdentityStatement->marshal( ec, &((_MICO_T*)v)->the_statement.inout() );
  ec.struct_end();
}

::CORBA::TypeCode_ptr _Marshaller_TransportSecurity_IdentityTokenInfo::typecode()
{
  return TransportSecurity::_tc_IdentityTokenInfo;
}

::CORBA::StaticTypeInfo *_marshaller_TransportSecurity_IdentityTokenInfo;

void operator<<=( CORBA::Any &_a, const TransportSecurity::IdentityTokenInfo &_s )
{
  CORBA::StaticAny _sa (_marshaller_TransportSecurity_IdentityTokenInfo, &_s);
  _a.from_static_any (_sa);
}

void operator<<=( CORBA::Any &_a, TransportSecurity::IdentityTokenInfo *_s )
{
  _a <<= *_s;
  delete _s;
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, TransportSecurity::IdentityTokenInfo &_s )
{
  CORBA::StaticAny _sa (_marshaller_TransportSecurity_IdentityTokenInfo, &_s);
  return _a.to_static_any (_sa);
}

CORBA::Boolean operator>>=( const CORBA::Any &_a, const TransportSecurity::IdentityTokenInfo *&_s )
{
  return _a.to_static_any (_marshaller_TransportSecurity_IdentityTokenInfo, (void *&)_s);
}


/*
 * Base interface for class IdentityTokenGenerator
 */

TransportSecurity::IdentityTokenGenerator::~IdentityTokenGenerator()
{
}

void *
TransportSecurity::IdentityTokenGenerator::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/IdentityTokenGenerator:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

TransportSecurity::IdentityTokenGenerator_ptr
TransportSecurity::IdentityTokenGenerator::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/IdentityTokenGenerator:1.0" )))
      return _duplicate( (TransportSecurity::IdentityTokenGenerator_ptr) _p );
  }
  return _nil();
}

TransportSecurity::IdentityTokenGenerator_ptr
TransportSecurity::IdentityTokenGenerator::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_IdentityTokenGenerator;
}


/*
 * Base interface for class CredentialsAcquirerFactory
 */

TransportSecurity::CredentialsAcquirerFactory::~CredentialsAcquirerFactory()
{
}

void *
TransportSecurity::CredentialsAcquirerFactory::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:adiron.com/TransportSecurity/CredentialsAcquirerFactory:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

TransportSecurity::CredentialsAcquirerFactory_ptr
TransportSecurity::CredentialsAcquirerFactory::_narrow( CORBA::Object_ptr _obj )
{
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:adiron.com/TransportSecurity/CredentialsAcquirerFactory:1.0" )))
      return _duplicate( (TransportSecurity::CredentialsAcquirerFactory_ptr) _p );
  }
  return _nil();
}

TransportSecurity::CredentialsAcquirerFactory_ptr
TransportSecurity::CredentialsAcquirerFactory::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

namespace TransportSecurity
{
CORBA::TypeCodeConst _tc_CredentialsAcquirerFactory;
}

struct __tc_init_TRANSPORTSECURITY_P {
  __tc_init_TRANSPORTSECURITY_P()
  {
    TransportSecurity::_tc_ContextEstablisherId = 
    "010000001500000068000000010000003a00000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f436f6e74657874"
    "45737461626c697368657249643a312e3000000015000000436f6e746578"
    "7445737461626c69736865724964000000001200000000000000";
    TransportSecurity::_tc_ContextEstablisherIdList = 
    "0100000015000000e8000000010000003e00000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f436f6e74657874"
    "45737461626c697368657249644c6973743a312e3000000019000000436f"
    "6e7465787445737461626c697368657249644c6973740000000013000000"
    "78000000010000001500000068000000010000003a00000049444c3a6164"
    "69726f6e2e636f6d2f5472616e73706f727453656375726974792f436f6e"
    "7465787445737461626c697368657249643a312e3000000015000000436f"
    "6e7465787445737461626c69736865724964000000001200000000000000"
    "00000000";
    TransportSecurity::_tc_ContextEstablisher = 
    "010000000e00000057000000010000003800000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f436f6e74657874"
    "45737461626c69736865723a312e300013000000436f6e74657874457374"
    "61626c697368657200";
    TransportSecurity::_tc_ContextEstablisherList = 
    "0100000015000000d0000000010000003c00000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f436f6e74657874"
    "45737461626c69736865724c6973743a312e300017000000436f6e746578"
    "7445737461626c69736865724c6973740000130000006800000001000000"
    "0e00000057000000010000003800000049444c3a616469726f6e2e636f6d"
    "2f5472616e73706f727453656375726974792f436f6e7465787445737461"
    "626c69736865723a312e300013000000436f6e7465787445737461626c69"
    "73686572000000000000";
    TransportSecurity::_tc_InitiatingContext = 
    "010000000e00000056000000010000003700000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f496e6974696174"
    "696e67436f6e746578743a312e30000012000000496e6974696174696e67"
    "436f6e7465787400";
    TransportSecurity::_tc_InitiatingContextList = 
    "0100000015000000d0000000010000003b00000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f496e6974696174"
    "696e67436f6e746578744c6973743a312e30000016000000496e69746961"
    "74696e67436f6e746578744c697374000000130000006800000001000000"
    "0e00000056000000010000003700000049444c3a616469726f6e2e636f6d"
    "2f5472616e73706f727453656375726974792f496e6974696174696e6743"
    "6f6e746578743a312e30000012000000496e6974696174696e67436f6e74"
    "65787400000000000000";
    TransportSecurity::_tc_AcceptingContext = 
    "010000000e00000055000000010000003600000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f41636365707469"
    "6e67436f6e746578743a312e3000000011000000416363657074696e6743"
    "6f6e7465787400";
    TransportSecurity::_tc_AcceptingContextList = 
    "0100000015000000d0000000010000003a00000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f41636365707469"
    "6e67436f6e746578744c6973743a312e3000000015000000416363657074"
    "696e67436f6e746578744c69737400000000130000006800000001000000"
    "0e00000055000000010000003600000049444c3a616469726f6e2e636f6d"
    "2f5472616e73706f727453656375726974792f416363657074696e67436f"
    "6e746578743a312e3000000011000000416363657074696e67436f6e7465"
    "78740000000000000000";
    TransportSecurity::_tc_TransportCredentialsCurator = 
    "010000000e0000006c000000010000004100000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f5472616e73706f"
    "727443726564656e7469616c7343757261746f723a312e30000000001c00"
    "00005472616e73706f727443726564656e7469616c7343757261746f7200"
    ;
    TransportSecurity::_tc_TransportOwnCredentials = 
    "010000000e00000064000000010000003d00000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f5472616e73706f"
    "72744f776e43726564656e7469616c733a312e3000000000180000005472"
    "616e73706f72744f776e43726564656e7469616c7300";
    TransportSecurity::_tc_TransportInitiator = 
    "010000000e00000057000000010000003800000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f5472616e73706f"
    "7274496e69746961746f723a312e3000130000005472616e73706f727449"
    "6e69746961746f7200";
    TransportSecurity::_tc_TransportAcceptor = 
    "010000000e00000056000000010000003700000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f5472616e73706f"
    "72744163636570746f723a312e300000120000005472616e73706f727441"
    "63636570746f7200";
    TransportSecurity::_tc_IdentityTokenInfo = 
    "010000000f000000220f0000010000003700000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f4964656e746974"
    "79546f6b656e496e666f3a312e300000120000004964656e74697479546f"
    "6b656e496e666f000000050000000a00000069735f616273656e74000000"
    "080000000d00000069735f616e6f6e796d6f757300000000080000000a00"
    "00007468655f746f6b656e00000010000000b40200000100000022000000"
    "49444c3a6f6d672e6f72672f4353492f4964656e74697479546f6b656e3a"
    "312e300000000e0000004964656e74697479546f6b656e00000015000000"
    "4c000000010000002600000049444c3a6f6d672e6f72672f4353492f4964"
    "656e74697479546f6b656e547970653a312e30000000120000004964656e"
    "74697479546f6b656e547970650000000500000005000000060000000000"
    "000007000000616273656e74000008000000010000000a000000616e6f6e"
    "796d6f757300000008000000020000000f0000007072696e636970616c5f"
    "6e616d650000150000005c000000010000002800000049444c3a6f6d672e"
    "6f72672f4353492f4753535f4e545f4578706f727465644e616d653a312e"
    "3000140000004753535f4e545f4578706f727465644e616d650013000000"
    "0c000000010000000a000000000000000400000012000000636572746966"
    "69636174655f636861696e00000015000000640000000100000029000000"
    "49444c3a6f6d672e6f72672f4353492f5835303943657274696669636174"
    "65436861696e3a312e300000000015000000583530394365727469666963"
    "617465436861696e00000000130000000c000000010000000a0000000000"
    "00000800000003000000646e00001500000064000000010000002a000000"
    "49444c3a6f6d672e6f72672f4353492f5835303144697374696e67756973"
    "6865644e616d653a312e30000000160000005835303144697374696e6775"
    "69736865644e616d65000000130000000c000000010000000a0000000000"
    "0000000000000300000069640000150000005c0000000100000026000000"
    "49444c3a6f6d672e6f72672f4353492f4964656e74697479457874656e73"
    "696f6e3a312e30000000120000004964656e74697479457874656e73696f"
    "6e000000130000000c000000010000000a000000000000000e0000007468"
    "655f7072696e636970616c0000001d000000320900000100000029000000"
    "49444c3a616469726f6e2e636f6d2f534c33504d2f53696d706c65507269"
    "6e636970616c3a312e30000000001000000053696d706c655072696e6369"
    "70616c00030000001d0000009a060000010000002300000049444c3a6164"
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
    "6556616c756500001b000000000000000000000000000000010000000200"
    "00000e00000061757468656e746963617465640000000800000001000000"
    "10000000616c7465726e6174655f6e616d65730015000000040200000100"
    "00002b00000049444c3a616469726f6e2e636f6d2f534c33504d2f507269"
    "6e636970616c4e616d654c6973743a312e300000120000005072696e6369"
    "70616c4e616d654c69737400000013000000b0010000010000000f000000"
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
    "00000000010000000e0000007468655f73746174656d656e740000001d00"
    "000062020000010000002b00000049444c3a616469726f6e2e636f6d2f53"
    "4c33504d2f4964656e7469747953746174656d656e743a312e3000001200"
    "00004964656e7469747953746174656d656e740000001d000000e6010000"
    "010000002300000049444c3a616469726f6e2e636f6d2f534c33504d2f53"
    "746174656d656e743a312e3000000a00000053746174656d656e74000000"
    "00000000040000000a0000007468655f6c61796572000000150000004800"
    "0000010000002800000049444c3a616469726f6e2e636f6d2f534c33504d"
    "2f53746174656d656e744c617965723a312e30000f00000053746174656d"
    "656e744c6179657200000500000001000000090000007468655f74797065"
    "000000001500000048000000010000002700000049444c3a616469726f6e"
    "2e636f6d2f534c33504d2f53746174656d656e74547970653a312e300000"
    "0e00000053746174656d656e745479706500000005000000010000000e00"
    "0000656e636f64696e675f74797065000000150000004c00000001000000"
    "2600000049444c3a616469726f6e2e636f6d2f534c33504d2f456e636f64"
    "696e67547970653a312e300000000d000000456e636f64696e6754797065"
    "000000001200000000000000000000000d0000007468655f656e636f6469"
    "6e67000000001500000050000000010000002200000049444c3a61646972"
    "6f6e2e636f6d2f534c33504d2f456e636f64696e673a312e300000000900"
    "0000456e636f64696e6700000000130000000c000000010000000a000000"
    "00000000000000000100000013000000696e746572707265746174696f6e"
    "5f616964000012000000000000000100";
    _marshaller_TransportSecurity_IdentityTokenInfo = new _Marshaller_TransportSecurity_IdentityTokenInfo;
    TransportSecurity::_tc_IdentityTokenGenerator = 
    "010000000e0000005f000000010000003c00000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f4964656e746974"
    "79546f6b656e47656e657261746f723a312e3000170000004964656e7469"
    "7479546f6b656e47656e657261746f7200";
    TransportSecurity::_tc_CredentialsAcquirerFactory = 
    "010000000e00000067000000010000004000000049444c3a616469726f6e"
    "2e636f6d2f5472616e73706f727453656375726974792f43726564656e74"
    "69616c734163717569726572466163746f72793a312e30001b0000004372"
    "6564656e7469616c734163717569726572466163746f727900";
  }

  ~__tc_init_TRANSPORTSECURITY_P()
  {
    delete static_cast<_Marshaller_TransportSecurity_IdentityTokenInfo*>(_marshaller_TransportSecurity_IdentityTokenInfo);
  }
};

static __tc_init_TRANSPORTSECURITY_P __init_TRANSPORTSECURITY_P;

