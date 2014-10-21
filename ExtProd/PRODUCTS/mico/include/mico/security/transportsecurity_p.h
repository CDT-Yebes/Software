/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __TRANSPORTSECURITY_P_H__
#define __TRANSPORTSECURITY_P_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace TransportSecurity
{

class InitiatingContext;
typedef InitiatingContext *InitiatingContext_ptr;
typedef InitiatingContext_ptr InitiatingContextRef;
typedef ObjVar< InitiatingContext > InitiatingContext_var;
typedef ObjOut< InitiatingContext > InitiatingContext_out;

class ContextEstablisher;
typedef ContextEstablisher *ContextEstablisher_ptr;
typedef ContextEstablisher_ptr ContextEstablisherRef;
typedef ObjVar< ContextEstablisher > ContextEstablisher_var;
typedef ObjOut< ContextEstablisher > ContextEstablisher_out;

class IdentityTokenGenerator;
typedef IdentityTokenGenerator *IdentityTokenGenerator_ptr;
typedef IdentityTokenGenerator_ptr IdentityTokenGeneratorRef;
typedef ObjVar< IdentityTokenGenerator > IdentityTokenGenerator_var;
typedef ObjOut< IdentityTokenGenerator > IdentityTokenGenerator_out;

class AcceptingContext;
typedef AcceptingContext *AcceptingContext_ptr;
typedef AcceptingContext_ptr AcceptingContextRef;
typedef ObjVar< AcceptingContext > AcceptingContext_var;
typedef ObjOut< AcceptingContext > AcceptingContext_out;

class TransportCredentialsCurator;
typedef TransportCredentialsCurator *TransportCredentialsCurator_ptr;
typedef TransportCredentialsCurator_ptr TransportCredentialsCuratorRef;
typedef ObjVar< TransportCredentialsCurator > TransportCredentialsCurator_var;
typedef ObjOut< TransportCredentialsCurator > TransportCredentialsCurator_out;

class TransportOwnCredentials;
typedef TransportOwnCredentials *TransportOwnCredentials_ptr;
typedef TransportOwnCredentials_ptr TransportOwnCredentialsRef;
typedef ObjVar< TransportOwnCredentials > TransportOwnCredentials_var;
typedef ObjOut< TransportOwnCredentials > TransportOwnCredentials_out;

class TransportInitiator;
typedef TransportInitiator *TransportInitiator_ptr;
typedef TransportInitiator_ptr TransportInitiatorRef;
typedef ObjVar< TransportInitiator > TransportInitiator_var;
typedef ObjOut< TransportInitiator > TransportInitiator_out;

class TransportAcceptor;
typedef TransportAcceptor *TransportAcceptor_ptr;
typedef TransportAcceptor_ptr TransportAcceptorRef;
typedef ObjVar< TransportAcceptor > TransportAcceptor_var;
typedef ObjOut< TransportAcceptor > TransportAcceptor_out;

class CredentialsAcquirerFactory;
typedef CredentialsAcquirerFactory *CredentialsAcquirerFactory_ptr;
typedef CredentialsAcquirerFactory_ptr CredentialsAcquirerFactoryRef;
typedef ObjVar< CredentialsAcquirerFactory > CredentialsAcquirerFactory_var;
typedef ObjOut< CredentialsAcquirerFactory > CredentialsAcquirerFactory_out;

}






namespace TransportSecurity
{

typedef char* ContextEstablisherId;
typedef CORBA::String_var ContextEstablisherId_var;
typedef CORBA::String_out ContextEstablisherId_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ContextEstablisherId;

typedef StringSequenceTmpl<CORBA::String_var> ContextEstablisherIdList;
typedef TSeqVar< StringSequenceTmpl<CORBA::String_var> > ContextEstablisherIdList_var;
typedef TSeqOut< StringSequenceTmpl<CORBA::String_var> > ContextEstablisherIdList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ContextEstablisherIdList;


/*
 * Base class and common definitions for local interface ContextEstablisher
 */

class ContextEstablisher : 
  virtual public CORBA::Object
{
  public:
    virtual ~ContextEstablisher();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ContextEstablisher_ptr _ptr_type;
    typedef ContextEstablisher_var _var_type;
    #endif

    static ContextEstablisher_ptr _narrow( CORBA::Object_ptr obj );
    static ContextEstablisher_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ContextEstablisher_ptr _duplicate( ContextEstablisher_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ContextEstablisher_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual char* establisher_id() = 0;
    virtual ::TimeBase::UtcT expiry_time() = 0;
    virtual ::TransportSecurity::OwnCredentials_ptr parent_credentials() = 0;
    virtual char* remote_host() = 0;
    virtual CORBA::ULong remote_port() = 0;
    virtual ::IOP::TaggedComponentSeq* transport_components() = 0;

    virtual CORBA::Boolean establish_context( ::TransportSecurity::InitiatingContext_out initiating_context ) = 0;
    virtual CORBA::Boolean establish_context_timeout( CORBA::ULong timeout, ::TransportSecurity::InitiatingContext_out initiating_context ) = 0;
    virtual CORBA::Boolean establish_alt_context( ::SL3CM::CredsDirective creds_directive, ::TransportSecurity::InitiatingContext_out initiating_context ) = 0;
    virtual CORBA::Boolean establish_alt_context_timeout( ::SL3CM::CredsDirective creds_directive, CORBA::ULong timeout, ::TransportSecurity::InitiatingContext_out initiating_context ) = 0;
    virtual CORBA::Boolean is_usable( const char* host, CORBA::ULong port, ::SL3CM::CredsDirective creds_directive, ::SL3CM::FeatureDirective client_authentication, ::SL3CM::FeatureDirective target_authentication, ::SL3CM::FeatureDirective confidentiality, ::SL3CM::FeatureDirective integrity, ::TransportSecurity::CSIVersion csi_version, const ::IOP::TaggedComponentSeq& transport_components ) = 0;
    virtual CORBA::Boolean equivalent( ::TransportSecurity::ContextEstablisher_ptr estab ) = 0;

  protected:
    ContextEstablisher() {};
  private:
    ContextEstablisher( const ContextEstablisher& );
    void operator=( const ContextEstablisher& );
};


typedef IfaceSequenceTmpl< ContextEstablisher_var,ContextEstablisher_ptr> ContextEstablisherList;
typedef TSeqVar< IfaceSequenceTmpl< ContextEstablisher_var,ContextEstablisher_ptr> > ContextEstablisherList_var;
typedef TSeqOut< IfaceSequenceTmpl< ContextEstablisher_var,ContextEstablisher_ptr> > ContextEstablisherList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ContextEstablisherList;


/*
 * Base class and common definitions for local interface InitiatingContext
 */

class InitiatingContext : 
  virtual public ::TransportSecurity::TargetCredentials,
  virtual public ::SL3OM::CredentialsObserver
{
  public:
    virtual ~InitiatingContext();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef InitiatingContext_ptr _ptr_type;
    typedef InitiatingContext_var _var_type;
    #endif

    static InitiatingContext_ptr _narrow( CORBA::Object_ptr obj );
    static InitiatingContext_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static InitiatingContext_ptr _duplicate( InitiatingContext_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static InitiatingContext_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual CORBA::Boolean is_usable( const char* host, CORBA::ULong port, ::SL3CM::CredsDirective creds_directive, ::SL3CM::FeatureDirective client_authentication, ::SL3CM::FeatureDirective target_authentication, ::SL3CM::FeatureDirective confidentiality, ::SL3CM::FeatureDirective integrity, ::TransportSecurity::CSIVersion csi_version, const ::IOP::TaggedComponentSeq& transport_components ) = 0;
    virtual void shutdown() = 0;

  protected:
    InitiatingContext() {};
  private:
    InitiatingContext( const InitiatingContext& );
    void operator=( const InitiatingContext& );
};


typedef IfaceSequenceTmpl< InitiatingContext_var,InitiatingContext_ptr> InitiatingContextList;
typedef TSeqVar< IfaceSequenceTmpl< InitiatingContext_var,InitiatingContext_ptr> > InitiatingContextList_var;
typedef TSeqOut< IfaceSequenceTmpl< InitiatingContext_var,InitiatingContext_ptr> > InitiatingContextList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_InitiatingContextList;


/*
 * Base class and common definitions for local interface AcceptingContext
 */

class AcceptingContext : 
  virtual public ::TransportSecurity::ClientCredentials,
  virtual public ::SL3OM::CredentialsObserver
{
  public:
    virtual ~AcceptingContext();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef AcceptingContext_ptr _ptr_type;
    typedef AcceptingContext_var _var_type;
    #endif

    static AcceptingContext_ptr _narrow( CORBA::Object_ptr obj );
    static AcceptingContext_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static AcceptingContext_ptr _duplicate( AcceptingContext_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static AcceptingContext_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::TransportSecurity::IdentityTokenGenerator_ptr create_client_identity_token_generator() = 0;

  protected:
    AcceptingContext() {};
  private:
    AcceptingContext( const AcceptingContext& );
    void operator=( const AcceptingContext& );
};


typedef IfaceSequenceTmpl< AcceptingContext_var,AcceptingContext_ptr> AcceptingContextList;
typedef TSeqVar< IfaceSequenceTmpl< AcceptingContext_var,AcceptingContext_ptr> > AcceptingContextList_var;
typedef TSeqOut< IfaceSequenceTmpl< AcceptingContext_var,AcceptingContext_ptr> > AcceptingContextList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_AcceptingContextList;


/*
 * Base class and common definitions for local interface TransportCredentialsCurator
 */

class TransportCredentialsCurator : 
  virtual public ::TransportSecurity::CredentialsCurator
{
  public:
    virtual ~TransportCredentialsCurator();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TransportCredentialsCurator_ptr _ptr_type;
    typedef TransportCredentialsCurator_var _var_type;
    #endif

    static TransportCredentialsCurator_ptr _narrow( CORBA::Object_ptr obj );
    static TransportCredentialsCurator_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TransportCredentialsCurator_ptr _duplicate( TransportCredentialsCurator_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TransportCredentialsCurator_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void enable_transport_acceptors() = 0;

  protected:
    TransportCredentialsCurator() {};
  private:
    TransportCredentialsCurator( const TransportCredentialsCurator& );
    void operator=( const TransportCredentialsCurator& );
};



/*
 * Base class and common definitions for local interface TransportOwnCredentials
 */

class TransportOwnCredentials : 
  virtual public ::TransportSecurity::OwnCredentials
{
  public:
    virtual ~TransportOwnCredentials();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TransportOwnCredentials_ptr _ptr_type;
    typedef TransportOwnCredentials_var _var_type;
    #endif

    static TransportOwnCredentials_ptr _narrow( CORBA::Object_ptr obj );
    static TransportOwnCredentials_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TransportOwnCredentials_ptr _duplicate( TransportOwnCredentials_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TransportOwnCredentials_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

  protected:
    TransportOwnCredentials() {};
  private:
    TransportOwnCredentials( const TransportOwnCredentials& );
    void operator=( const TransportOwnCredentials& );
};



/*
 * Base class and common definitions for local interface TransportInitiator
 */

class TransportInitiator : 
  virtual public ::TransportSecurity::CredentialsInitiator
{
  public:
    virtual ~TransportInitiator();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TransportInitiator_ptr _ptr_type;
    typedef TransportInitiator_var _var_type;
    #endif

    static TransportInitiator_ptr _narrow( CORBA::Object_ptr obj );
    static TransportInitiator_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TransportInitiator_ptr _duplicate( TransportInitiator_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TransportInitiator_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::TransportSecurity::ContextEstablisherList* context_establishers() = 0;
    virtual char* host() = 0;
    virtual CORBA::ULong low_port() = 0;
    virtual CORBA::ULong high_port() = 0;

    virtual void increment_work() = 0;
    virtual void decrement_work() = 0;
    virtual CORBA::Boolean supports_invoc_options( ::CSIIOP::AssociationOptions invocation_options_supported, ::CSIIOP::AssociationOptions invocation_options_required ) = 0;
    virtual CORBA::Boolean supports_csi_version( ::TransportSecurity::CSIVersion csi_version ) = 0;
    virtual CORBA::Boolean is_usable( const char* host, CORBA::ULong port, ::SL3CM::CredsDirective creds_directive, ::SL3CM::FeatureDirective client_authentication, ::SL3CM::FeatureDirective target_authentication, ::SL3CM::FeatureDirective confidentiality, ::SL3CM::FeatureDirective integrity, ::TransportSecurity::CSIVersion csi_version, const ::IOP::TaggedComponentSeq& transport_components ) = 0;
    virtual ::TransportSecurity::ContextEstablisherList* create_context_establishers( const char* host, CORBA::ULong port, ::SL3CM::CredsDirective creds_directive, ::SL3CM::FeatureDirective client_authentication, ::SL3CM::FeatureDirective target_authentication, ::SL3CM::FeatureDirective confidentiality, ::SL3CM::FeatureDirective integrity, ::TransportSecurity::CSIVersion csi_version, const ::IOP::TaggedComponentSeq& transport_components ) = 0;
    virtual ::TransportSecurity::ContextEstablisher_ptr get_context_establisher( const char* id ) = 0;

  protected:
    TransportInitiator() {};
  private:
    TransportInitiator( const TransportInitiator& );
    void operator=( const TransportInitiator& );
};



/*
 * Base class and common definitions for local interface TransportAcceptor
 */

class TransportAcceptor : 
  virtual public ::TransportSecurity::CredentialsAcceptor
{
  public:
    virtual ~TransportAcceptor();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TransportAcceptor_ptr _ptr_type;
    typedef TransportAcceptor_var _var_type;
    #endif

    static TransportAcceptor_ptr _narrow( CORBA::Object_ptr obj );
    static TransportAcceptor_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TransportAcceptor_ptr _duplicate( TransportAcceptor_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TransportAcceptor_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::CORBA::StringSeq* hosts() = 0;
    virtual CORBA::ULong port() = 0;
    virtual ::CSIIOP::AssociationOptions options_required() = 0;
    virtual ::CSIIOP::AssociationOptions options_supported() = 0;

    virtual void increment_work() = 0;
    virtual void decrement_work() = 0;
    virtual ::IOP::TaggedComponentSeq* transport_components( ::TransportSecurity::CSIVersion csi_version ) = 0;
    virtual CORBA::Boolean transport_matches( const char* host, CORBA::ULong port, const ::IOP::TaggedComponentSeq& transport_components ) = 0;
    virtual ::TransportSecurity::AcceptingContext_ptr accept( CORBA::Boolean block ) = 0;
    virtual void shutdown() = 0;
    virtual void enable() = 0;

  protected:
    TransportAcceptor() {};
  private:
    TransportAcceptor( const TransportAcceptor& );
    void operator=( const TransportAcceptor& );
};


struct IdentityTokenInfo;
typedef TVarVar< IdentityTokenInfo > IdentityTokenInfo_var;
typedef TVarOut< IdentityTokenInfo > IdentityTokenInfo_out;


struct IdentityTokenInfo {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef IdentityTokenInfo_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  IdentityTokenInfo();
  ~IdentityTokenInfo();
  IdentityTokenInfo( const IdentityTokenInfo& s );
  IdentityTokenInfo& operator=( const IdentityTokenInfo& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  CORBA::Boolean is_absent;
  CORBA::Boolean is_anonymous;
  ::CSI::IdentityToken the_token;
  ::SL3PM::SimplePrincipal_var the_principal;
  ::SL3PM::IdentityStatement_var the_statement;
  // we contain a valuetype
  CORBA::Long _count_refs (CORBA::ValueBase::visited * = 0);
  void _release_members ();
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_IdentityTokenInfo;


/*
 * Base class and common definitions for local interface IdentityTokenGenerator
 */

class IdentityTokenGenerator : 
  virtual public CORBA::Object
{
  public:
    virtual ~IdentityTokenGenerator();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef IdentityTokenGenerator_ptr _ptr_type;
    typedef IdentityTokenGenerator_var _var_type;
    #endif

    static IdentityTokenGenerator_ptr _narrow( CORBA::Object_ptr obj );
    static IdentityTokenGenerator_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static IdentityTokenGenerator_ptr _duplicate( IdentityTokenGenerator_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static IdentityTokenGenerator_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3PM::SimplePrincipal* the_principal() = 0;
    virtual ::SL3PM::IdentityStatement* the_statement() = 0;
    virtual CORBA::Boolean generate_identity( ::CSI::IdentityTokenType id_token_types, const ::CSI::OIDList& gss_naming_mechs, ::TransportSecurity::IdentityTokenInfo_out identity_token_info ) = 0;
    virtual void destroy() = 0;

  protected:
    IdentityTokenGenerator() {};
  private:
    IdentityTokenGenerator( const IdentityTokenGenerator& );
    void operator=( const IdentityTokenGenerator& );
};



/*
 * Base class and common definitions for local interface CredentialsAcquirerFactory
 */

class CredentialsAcquirerFactory : 
  virtual public CORBA::Object
{
  public:
    virtual ~CredentialsAcquirerFactory();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef CredentialsAcquirerFactory_ptr _ptr_type;
    typedef CredentialsAcquirerFactory_var _var_type;
    #endif

    static CredentialsAcquirerFactory_ptr _narrow( CORBA::Object_ptr obj );
    static CredentialsAcquirerFactory_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static CredentialsAcquirerFactory_ptr _duplicate( CredentialsAcquirerFactory_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static CredentialsAcquirerFactory_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::TransportSecurity::CredentialsAcquirer_ptr create( ::SL3AQArgs::Argument_ptr value ) = 0;
    virtual CORBA::Boolean supports_all_args( ::SL3AQArgs::Argument_ptr value ) = 0;

  protected:
    CredentialsAcquirerFactory() {};
  private:
    CredentialsAcquirerFactory( const CredentialsAcquirerFactory& );
    void operator=( const CredentialsAcquirerFactory& );
};


}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

void operator<<=( CORBA::Any &_a, const ::TransportSecurity::IdentityTokenInfo &_s );
void operator<<=( CORBA::Any &_a, ::TransportSecurity::IdentityTokenInfo *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::TransportSecurity::IdentityTokenInfo &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::TransportSecurity::IdentityTokenInfo *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_TransportSecurity_IdentityTokenInfo;

#endif
