/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __SL3CSI_H__
#define __SL3CSI_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace SL3CSI
{

class CSIArgBuilder;
typedef CSIArgBuilder *CSIArgBuilder_ptr;
typedef CSIArgBuilder_ptr CSIArgBuilderRef;
typedef ObjVar< CSIArgBuilder > CSIArgBuilder_var;
typedef ObjOut< CSIArgBuilder > CSIArgBuilder_out;

}






namespace SL3CSI
{


/*
 * Base class and common definitions for local interface CSIArgBuilder
 */

class CSIArgBuilder : 
  virtual public ::SL3AQArgs::ArgBuilder
{
  public:
    virtual ~CSIArgBuilder();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef CSIArgBuilder_ptr _ptr_type;
    typedef CSIArgBuilder_var _var_type;
    #endif

    static CSIArgBuilder_ptr _narrow( CORBA::Object_ptr obj );
    static CSIArgBuilder_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static CSIArgBuilder_ptr _duplicate( CSIArgBuilder_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static CSIArgBuilder_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void add_password_generator( ::UserPassword::PasswordGenerator_ptr generator ) = 0;
    virtual void add_password_processor( ::UserPassword::PasswordProcessor_ptr processor ) = 0;
    virtual void add_named_quoted_principal( const ::SL3PM::PrincipalName& principal_name ) = 0;
    virtual void add_encoded_quoted_principal( ::SL3PM::IdentityStatement* identity ) = 0;
    virtual void add_trust_in_server_decider( ::Trust::LocalTrustInServerDecider_ptr trust_decider ) = 0;
    virtual void add_transport_credentials( ::TransportSecurity::OwnCredentials_ptr credentials ) = 0;
    virtual void add_credentials_observer( ::SL3OM::CredentialsObserver_ptr observer ) = 0;
    virtual void add_client_credentials_observer( ::SL3OM::ClientCredentialsObserver_ptr observer ) = 0;
    virtual void add_target_credentials_observer( ::SL3OM::TargetCredentialsObserver_ptr observer ) = 0;
    virtual void add_ATLAS_object( const ::ATLAS::ATLASCacheId& cache_id, ::ATLAS::AuthTokenDispenser_ptr token_dispenser, ::SL3Authorization::TokenProcessor_ptr token_processor ) = 0;
    virtual void add_token_processor( ::SL3Authorization::TokenProcessor_ptr token_processor ) = 0;
    virtual void add_identity_processor( ::SL3TLS::TLSX509IdentityProcessor_ptr processor ) = 0;

  protected:
    CSIArgBuilder() {};
  private:
    CSIArgBuilder( const CSIArgBuilder& );
    void operator=( const CSIArgBuilder& );
};


}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

#endif
