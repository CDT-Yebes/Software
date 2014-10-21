/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __SECURITYLEVEL3_H__
#define __SECURITYLEVEL3_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace SecurityLevel3
{

class CredsInitiator;
typedef CredsInitiator *CredsInitiator_ptr;
typedef CredsInitiator_ptr CredsInitiatorRef;
typedef ObjVar< CredsInitiator > CredsInitiator_var;
typedef ObjOut< CredsInitiator > CredsInitiator_out;

class CredsAcceptor;
typedef CredsAcceptor *CredsAcceptor_ptr;
typedef CredsAcceptor_ptr CredsAcceptorRef;
typedef ObjVar< CredsAcceptor > CredsAcceptor_var;
typedef ObjOut< CredsAcceptor > CredsAcceptor_out;

class Credentials;
typedef Credentials *Credentials_ptr;
typedef Credentials_ptr CredentialsRef;
typedef ObjVar< Credentials > Credentials_var;
typedef ObjOut< Credentials > Credentials_out;

class OwnCredentials;
typedef OwnCredentials *OwnCredentials_ptr;
typedef OwnCredentials_ptr OwnCredentialsRef;
typedef ObjVar< OwnCredentials > OwnCredentials_var;
typedef ObjOut< OwnCredentials > OwnCredentials_out;

class ClientCredentials;
typedef ClientCredentials *ClientCredentials_ptr;
typedef ClientCredentials_ptr ClientCredentialsRef;
typedef ObjVar< ClientCredentials > ClientCredentials_var;
typedef ObjOut< ClientCredentials > ClientCredentials_out;

class TargetCredentials;
typedef TargetCredentials *TargetCredentials_ptr;
typedef TargetCredentials_ptr TargetCredentialsRef;
typedef ObjVar< TargetCredentials > TargetCredentials_var;
typedef ObjOut< TargetCredentials > TargetCredentials_out;

class ContextEstablishmentPolicy;
typedef ContextEstablishmentPolicy *ContextEstablishmentPolicy_ptr;
typedef ContextEstablishmentPolicy_ptr ContextEstablishmentPolicyRef;
typedef ObjVar< ContextEstablishmentPolicy > ContextEstablishmentPolicy_var;
typedef ObjOut< ContextEstablishmentPolicy > ContextEstablishmentPolicy_out;

class ObjectCredentialsPolicy;
typedef ObjectCredentialsPolicy *ObjectCredentialsPolicy_ptr;
typedef ObjectCredentialsPolicy_ptr ObjectCredentialsPolicyRef;
typedef ObjVar< ObjectCredentialsPolicy > ObjectCredentialsPolicy_var;
typedef ObjOut< ObjectCredentialsPolicy > ObjectCredentialsPolicy_out;

class CredentialsAcquirer;
typedef CredentialsAcquirer *CredentialsAcquirer_ptr;
typedef CredentialsAcquirer_ptr CredentialsAcquirerRef;
typedef ObjVar< CredentialsAcquirer > CredentialsAcquirer_var;
typedef ObjOut< CredentialsAcquirer > CredentialsAcquirer_out;

class CredentialsCurator;
typedef CredentialsCurator *CredentialsCurator_ptr;
typedef CredentialsCurator_ptr CredentialsCuratorRef;
typedef ObjVar< CredentialsCurator > CredentialsCurator_var;
typedef ObjOut< CredentialsCurator > CredentialsCurator_out;

class SecurityManager;
typedef SecurityManager *SecurityManager_ptr;
typedef SecurityManager_ptr SecurityManagerRef;
typedef ObjVar< SecurityManager > SecurityManager_var;
typedef ObjOut< SecurityManager > SecurityManager_out;

class SecurityCurrent;
typedef SecurityCurrent *SecurityCurrent_ptr;
typedef SecurityCurrent_ptr SecurityCurrentRef;
typedef ObjVar< SecurityCurrent > SecurityCurrent_var;
typedef ObjOut< SecurityCurrent > SecurityCurrent_out;

}






namespace SecurityLevel3
{

const CORBA::ULong ADIRON_VMCID = 168935424UL;
typedef CORBA::ULong InitiatorType;
typedef InitiatorType& InitiatorType_out;
extern MICO_EXPORT CORBA::TypeCodeConst _tc_InitiatorType;

const InitiatorType IT_None = 0;
const InitiatorType IT_Simple = 1;
const InitiatorType IT_Quoting = 2;
const InitiatorType IT_Proxy = 3;

/*
 * Base class and common definitions for local interface CredsInitiator
 */

class CredsInitiator : 
  virtual public CORBA::Object
{
  public:
    virtual ~CredsInitiator();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef CredsInitiator_ptr _ptr_type;
    typedef CredsInitiator_var _var_type;
    #endif

    static CredsInitiator_ptr _narrow( CORBA::Object_ptr obj );
    static CredsInitiator_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static CredsInitiator_ptr _duplicate( CredsInitiator_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static CredsInitiator_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3PM::Principal* the_principal() = 0;
    virtual ::SL3PM::StatementList* supporting_statements() = 0;
    virtual ::SL3PM::ResourceNameList* restricted_resources() = 0;
    virtual ::SL3PM::PrinAttributeList* environmental_attributes() = 0;
    virtual ::SecurityLevel3::InitiatorType initiator_type() = 0;
    virtual CORBA::Boolean supports_embodiment() = 0;
    virtual CORBA::Boolean supports_endorsement() = 0;
    virtual CORBA::Boolean supports_quoting() = 0;
    virtual ::TimeBase::UtcT expiry_time() = 0;

  protected:
    CredsInitiator() {};
  private:
    CredsInitiator( const CredsInitiator& );
    void operator=( const CredsInitiator& );
};



/*
 * Base class and common definitions for local interface CredsAcceptor
 */

class CredsAcceptor : 
  virtual public CORBA::Object
{
  public:
    virtual ~CredsAcceptor();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef CredsAcceptor_ptr _ptr_type;
    typedef CredsAcceptor_var _var_type;
    #endif

    static CredsAcceptor_ptr _narrow( CORBA::Object_ptr obj );
    static CredsAcceptor_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static CredsAcceptor_ptr _duplicate( CredsAcceptor_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static CredsAcceptor_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3PM::Principal* the_principal() = 0;
    virtual ::SL3PM::StatementList* supporting_statements() = 0;
    virtual ::SL3PM::ResourceNameList* restricted_resources() = 0;
    virtual ::SL3PM::PrinAttributeList* environmental_attributes() = 0;
    virtual CORBA::Boolean accepts_endorsement() = 0;
    virtual CORBA::Boolean accepts_quoting() = 0;
    virtual ::TimeBase::UtcT expiry_time() = 0;

  protected:
    CredsAcceptor() {};
  private:
    CredsAcceptor( const CredsAcceptor& );
    void operator=( const CredsAcceptor& );
};



/*
 * Base class and common definitions for local interface Credentials
 */

class Credentials : 
  virtual public CORBA::Object
{
  public:
    virtual ~Credentials();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef Credentials_ptr _ptr_type;
    typedef Credentials_var _var_type;
    #endif

    static Credentials_ptr _narrow( CORBA::Object_ptr obj );
    static Credentials_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static Credentials_ptr _duplicate( Credentials_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static Credentials_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual char* creds_id() = 0;
    virtual ::SL3CM::CredentialsType creds_type() = 0;
    virtual ::SL3CM::CredentialsUsage creds_usage() = 0;
    virtual ::SL3CM::CredentialsState creds_state() = 0;

  protected:
    Credentials() {};
  private:
    Credentials( const Credentials& );
    void operator=( const Credentials& );
};


typedef IfaceSequenceTmpl< Credentials_var,Credentials_ptr> CredentialsList;
typedef TSeqVar< IfaceSequenceTmpl< Credentials_var,Credentials_ptr> > CredentialsList_var;
typedef TSeqOut< IfaceSequenceTmpl< Credentials_var,Credentials_ptr> > CredentialsList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_CredentialsList;


/*
 * Base class and common definitions for local interface OwnCredentials
 */

class OwnCredentials : 
  virtual public ::SecurityLevel3::Credentials
{
  public:
    virtual ~OwnCredentials();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef OwnCredentials_ptr _ptr_type;
    typedef OwnCredentials_var _var_type;
    #endif

    static OwnCredentials_ptr _narrow( CORBA::Object_ptr obj );
    static OwnCredentials_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static OwnCredentials_ptr _duplicate( OwnCredentials_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static OwnCredentials_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SecurityLevel3::CredsInitiator_ptr creds_initiator() = 0;
    virtual ::SecurityLevel3::CredsAcceptor_ptr creds_acceptor() = 0;

    virtual void release_credentials() = 0;

  protected:
    OwnCredentials() {};
  private:
    OwnCredentials( const OwnCredentials& );
    void operator=( const OwnCredentials& );
};


typedef IfaceSequenceTmpl< OwnCredentials_var,OwnCredentials_ptr> OwnCredentialsList;
typedef TSeqVar< IfaceSequenceTmpl< OwnCredentials_var,OwnCredentials_ptr> > OwnCredentialsList_var;
typedef TSeqOut< IfaceSequenceTmpl< OwnCredentials_var,OwnCredentials_ptr> > OwnCredentialsList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_OwnCredentialsList;


/*
 * Base class and common definitions for local interface ClientCredentials
 */

class ClientCredentials : 
  virtual public ::SecurityLevel3::Credentials
{
  public:
    virtual ~ClientCredentials();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ClientCredentials_ptr _ptr_type;
    typedef ClientCredentials_var _var_type;
    #endif

    static ClientCredentials_ptr _narrow( CORBA::Object_ptr obj );
    static ClientCredentials_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ClientCredentials_ptr _duplicate( ClientCredentials_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ClientCredentials_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual char* context_id() = 0;
    virtual ::SL3PM::Principal* client_principal() = 0;
    virtual ::SL3PM::StatementList* client_supporting_statements() = 0;
    virtual ::SL3PM::ResourceNameList* client_restricted_resources() = 0;
    virtual ::SL3PM::Principal* target_principal() = 0;
    virtual ::SL3PM::StatementList* target_supporting_statements() = 0;
    virtual ::SL3PM::ResourceNameList* target_restricted_resources() = 0;
    virtual ::SL3PM::PrinAttributeList* environmental_attributes() = 0;
    virtual ::SecurityLevel3::OwnCredentials_ptr parent_credentials() = 0;
    virtual CORBA::Boolean client_authentication() = 0;
    virtual CORBA::Boolean target_authentication() = 0;
    virtual CORBA::Boolean confidentiality() = 0;
    virtual CORBA::Boolean integrity() = 0;

  protected:
    ClientCredentials() {};
  private:
    ClientCredentials( const ClientCredentials& );
    void operator=( const ClientCredentials& );
};



/*
 * Base class and common definitions for local interface TargetCredentials
 */

class TargetCredentials : 
  virtual public ::SecurityLevel3::Credentials
{
  public:
    virtual ~TargetCredentials();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TargetCredentials_ptr _ptr_type;
    typedef TargetCredentials_var _var_type;
    #endif

    static TargetCredentials_ptr _narrow( CORBA::Object_ptr obj );
    static TargetCredentials_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TargetCredentials_ptr _duplicate( TargetCredentials_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TargetCredentials_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual char* context_id() = 0;
    virtual ::SL3PM::Principal* client_principal() = 0;
    virtual ::SL3PM::StatementList* client_supporting_statements() = 0;
    virtual ::SL3PM::ResourceNameList* client_restricted_resources() = 0;
    virtual ::SL3PM::Principal* target_principal() = 0;
    virtual ::SL3PM::StatementList* target_supporting_statements() = 0;
    virtual ::SL3PM::ResourceNameList* target_restricted_resources() = 0;
    virtual ::SL3PM::PrinAttributeList* environmental_attributes() = 0;
    virtual ::SecurityLevel3::OwnCredentials_ptr parent_credentials() = 0;
    virtual CORBA::Boolean client_authentication() = 0;
    virtual CORBA::Boolean target_authentication() = 0;
    virtual CORBA::Boolean confidentiality() = 0;
    virtual CORBA::Boolean integrity() = 0;
    virtual CORBA::Boolean target_embodied() = 0;
    virtual CORBA::Boolean target_endorsed() = 0;

    virtual void release() = 0;

  protected:
    TargetCredentials() {};
  private:
    TargetCredentials( const TargetCredentials& );
    void operator=( const TargetCredentials& );
};



/*
 * Base class and common definitions for local interface ContextEstablishmentPolicy
 */

class ContextEstablishmentPolicy : 
  virtual public CORBA::Object,
  virtual public ::CORBA::Policy
{
  public:
    virtual ~ContextEstablishmentPolicy();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ContextEstablishmentPolicy_ptr _ptr_type;
    typedef ContextEstablishmentPolicy_var _var_type;
    #endif

    static ContextEstablishmentPolicy_ptr _narrow( CORBA::Object_ptr obj );
    static ContextEstablishmentPolicy_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ContextEstablishmentPolicy_ptr _duplicate( ContextEstablishmentPolicy_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ContextEstablishmentPolicy_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3CM::CredsDirective creds_directive() = 0;
    virtual ::SecurityLevel3::OwnCredentialsList* creds_list() = 0;
    virtual ::SL3CM::FeatureDirective use_client_auth() = 0;
    virtual ::SL3CM::FeatureDirective use_target_auth() = 0;
    virtual ::SL3CM::FeatureDirective use_confidentiality() = 0;
    virtual ::SL3CM::FeatureDirective use_integrity() = 0;

  protected:
    ContextEstablishmentPolicy() {};
  private:
    ContextEstablishmentPolicy( const ContextEstablishmentPolicy& );
    void operator=( const ContextEstablishmentPolicy& );
};


const ::CORBA::PolicyType ContextEstablishmentPolicyType = 168936425;

/*
 * Base class and common definitions for local interface ObjectCredentialsPolicy
 */

class ObjectCredentialsPolicy : 
  virtual public CORBA::Object,
  virtual public ::CORBA::Policy
{
  public:
    virtual ~ObjectCredentialsPolicy();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ObjectCredentialsPolicy_ptr _ptr_type;
    typedef ObjectCredentialsPolicy_var _var_type;
    #endif

    static ObjectCredentialsPolicy_ptr _narrow( CORBA::Object_ptr obj );
    static ObjectCredentialsPolicy_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ObjectCredentialsPolicy_ptr _duplicate( ObjectCredentialsPolicy_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ObjectCredentialsPolicy_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SecurityLevel3::OwnCredentialsList* creds_list() = 0;

  protected:
    ObjectCredentialsPolicy() {};
  private:
    ObjectCredentialsPolicy( const ObjectCredentialsPolicy& );
    void operator=( const ObjectCredentialsPolicy& );
};


const ::CORBA::PolicyType ObjectCredentialsPolicyType = 168936426;

/*
 * Base class and common definitions for local interface CredentialsAcquirer
 */

class CredentialsAcquirer : 
  virtual public CORBA::Object
{
  public:
    virtual ~CredentialsAcquirer();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef CredentialsAcquirer_ptr _ptr_type;
    typedef CredentialsAcquirer_var _var_type;
    #endif

    static CredentialsAcquirer_ptr _narrow( CORBA::Object_ptr obj );
    static CredentialsAcquirer_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static CredentialsAcquirer_ptr _duplicate( CredentialsAcquirer_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static CredentialsAcquirer_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SecurityLevel3::OwnCredentials_ptr get_credentials( CORBA::Boolean on_list ) = 0;
    virtual void destroy() = 0;

  protected:
    CredentialsAcquirer() {};
  private:
    CredentialsAcquirer( const CredentialsAcquirer& );
    void operator=( const CredentialsAcquirer& );
};



/*
 * Base class and common definitions for local interface CredentialsCurator
 */

class CredentialsCurator : 
  virtual public CORBA::Object
{
  public:
    virtual ~CredentialsCurator();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef CredentialsCurator_ptr _ptr_type;
    typedef CredentialsCurator_var _var_type;
    #endif

    static CredentialsCurator_ptr _narrow( CORBA::Object_ptr obj );
    static CredentialsCurator_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static CredentialsCurator_ptr _duplicate( CredentialsCurator_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static CredentialsCurator_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SecurityLevel3::OwnCredentialsList* default_creds_list() = 0;

    virtual ::SecurityLevel3::CredentialsAcquirer_ptr acquire_credentials( ::SL3AQArgs::Argument_ptr acquisition_arguments ) = 0;
    virtual ::SecurityLevel3::OwnCredentials_ptr get_own_credentials( const char* credentials_id ) = 0;
    virtual void release_own_credentials( const char* credentials_id ) = 0;

  protected:
    CredentialsCurator() {};
  private:
    CredentialsCurator( const CredentialsCurator& );
    void operator=( const CredentialsCurator& );
};



/*
 * Base class and common definitions for local interface SecurityManager
 */

class SecurityManager : 
  virtual public CORBA::Object
{
  public:
    virtual ~SecurityManager();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef SecurityManager_ptr _ptr_type;
    typedef SecurityManager_var _var_type;
    #endif

    static SecurityManager_ptr _narrow( CORBA::Object_ptr obj );
    static SecurityManager_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static SecurityManager_ptr _duplicate( SecurityManager_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static SecurityManager_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SecurityLevel3::CredentialsCurator_ptr credentials_curator() = 0;

    virtual ::SecurityLevel3::TargetCredentials_ptr get_target_credentials( CORBA::Object_ptr the_object ) = 0;
    virtual ::SecurityLevel3::ContextEstablishmentPolicy_ptr create_context_estab_policy( ::SL3CM::CredsDirective creds_directive, const ::SecurityLevel3::OwnCredentialsList& creds_list, ::SL3CM::FeatureDirective use_client_auth, ::SL3CM::FeatureDirective use_target_auth, ::SL3CM::FeatureDirective use_confidentiality, ::SL3CM::FeatureDirective use_integrity ) = 0;
    virtual ::SecurityLevel3::ObjectCredentialsPolicy_ptr create_object_creds_policy( const ::SecurityLevel3::OwnCredentialsList& creds_list ) = 0;

  protected:
    SecurityManager() {};
  private:
    SecurityManager( const SecurityManager& );
    void operator=( const SecurityManager& );
};



/*
 * Base class and common definitions for local interface SecurityCurrent
 */

class SecurityCurrent : 
  virtual public CORBA::Object
{
  public:
    virtual ~SecurityCurrent();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef SecurityCurrent_ptr _ptr_type;
    typedef SecurityCurrent_var _var_type;
    #endif

    static SecurityCurrent_ptr _narrow( CORBA::Object_ptr obj );
    static SecurityCurrent_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static SecurityCurrent_ptr _duplicate( SecurityCurrent_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static SecurityCurrent_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SecurityLevel3::ClientCredentials_ptr client_credentials() = 0;

  protected:
    SecurityCurrent() {};
  private:
    SecurityCurrent( const SecurityCurrent& );
    void operator=( const SecurityCurrent& );
};


}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

#endif
