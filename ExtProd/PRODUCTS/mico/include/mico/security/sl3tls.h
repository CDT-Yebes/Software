/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __SL3TLS_H__
#define __SL3TLS_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace SL3TLS
{

class TLSX509IdentityVerifier;
typedef TLSX509IdentityVerifier *TLSX509IdentityVerifier_ptr;
typedef TLSX509IdentityVerifier_ptr TLSX509IdentityVerifierRef;
typedef ObjVar< TLSX509IdentityVerifier > TLSX509IdentityVerifier_var;
typedef ObjOut< TLSX509IdentityVerifier > TLSX509IdentityVerifier_out;

class TLSKeyStoreArgBuilder;
typedef TLSKeyStoreArgBuilder *TLSKeyStoreArgBuilder_ptr;
typedef TLSKeyStoreArgBuilder_ptr TLSKeyStoreArgBuilderRef;
typedef ObjVar< TLSKeyStoreArgBuilder > TLSKeyStoreArgBuilder_var;
typedef ObjOut< TLSKeyStoreArgBuilder > TLSKeyStoreArgBuilder_out;

class TLSX509IdentityProcessor;
typedef TLSX509IdentityProcessor *TLSX509IdentityProcessor_ptr;
typedef TLSX509IdentityProcessor_ptr TLSX509IdentityProcessorRef;
typedef ObjVar< TLSX509IdentityProcessor > TLSX509IdentityProcessor_var;
typedef ObjOut< TLSX509IdentityProcessor > TLSX509IdentityProcessor_out;

class OpenSSLConfigArgBuilder;
typedef OpenSSLConfigArgBuilder *OpenSSLConfigArgBuilder_ptr;
typedef OpenSSLConfigArgBuilder_ptr OpenSSLConfigArgBuilderRef;
typedef ObjVar< OpenSSLConfigArgBuilder > OpenSSLConfigArgBuilder_var;
typedef ObjOut< OpenSSLConfigArgBuilder > OpenSSLConfigArgBuilder_out;

}






namespace SL3TLS
{


/*
 * Base class and common definitions for local interface TLSX509IdentityVerifier
 */

class TLSX509IdentityVerifier : 
  virtual public CORBA::Object
{
  public:
    virtual ~TLSX509IdentityVerifier();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TLSX509IdentityVerifier_ptr _ptr_type;
    typedef TLSX509IdentityVerifier_var _var_type;
    #endif

    static TLSX509IdentityVerifier_ptr _narrow( CORBA::Object_ptr obj );
    static TLSX509IdentityVerifier_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TLSX509IdentityVerifier_ptr _duplicate( TLSX509IdentityVerifier_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TLSX509IdentityVerifier_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void add_trusted_authority( ::SL3PM::X509IdentityStatement* auth ) = 0;
    virtual CORBA::Boolean is_anonymous_allowed() = 0;
    virtual CORBA::Boolean verify( ::SL3PM::X509IdentityStatement* ident ) = 0;

  protected:
    TLSX509IdentityVerifier() {};
  private:
    TLSX509IdentityVerifier( const TLSX509IdentityVerifier& );
    void operator=( const TLSX509IdentityVerifier& );
};



/*
 * Base class and common definitions for local interface TLSKeyStoreArgBuilder
 */

class TLSKeyStoreArgBuilder : 
  virtual public ::SL3TCPIP::TCPIPArgBuilder
{
  public:
    virtual ~TLSKeyStoreArgBuilder();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TLSKeyStoreArgBuilder_ptr _ptr_type;
    typedef TLSKeyStoreArgBuilder_var _var_type;
    #endif

    static TLSKeyStoreArgBuilder_ptr _narrow( CORBA::Object_ptr obj );
    static TLSKeyStoreArgBuilder_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TLSKeyStoreArgBuilder_ptr _duplicate( TLSKeyStoreArgBuilder_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TLSKeyStoreArgBuilder_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void addTLSX509IdentityVerifier( ::SL3TLS::TLSX509IdentityVerifier_ptr verifier ) = 0;
    virtual void addTLSKeyStoreWithStorePass( const char* keystore, const char* storetype, const char* storepass, const char* keyalias, const char* keypass, const ::CORBA::StringSeq& trusted_cert_names ) = 0;
    virtual void addTLSKeyStoreNoStorePass( const char* keystore, const char* storetype, const char* keyalias, const char* keypass, const ::CORBA::StringSeq& trusted_cert_names ) = 0;
    virtual void addTLSEncodedKeyStoreWithStorePass( const ::CORBA::OctetSeq& keystore, const char* storetype, const char* storepass, const char* keyalias, const char* keypass, const ::CORBA::StringSeq& trusted_cert_names ) = 0;
    virtual void addTLSEncodedKeyStoreNoStorePass( const ::CORBA::OctetSeq& keystore, const char* storetype, const char* keyalias, const char* keypass, const ::CORBA::StringSeq& trusted_cert_names ) = 0;

  protected:
    TLSKeyStoreArgBuilder() {};
  private:
    TLSKeyStoreArgBuilder( const TLSKeyStoreArgBuilder& );
    void operator=( const TLSKeyStoreArgBuilder& );
};



/*
 * Base class and common definitions for local interface TLSX509IdentityProcessor
 */

class TLSX509IdentityProcessor : 
  virtual public CORBA::Object
{
  public:
    virtual ~TLSX509IdentityProcessor();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TLSX509IdentityProcessor_ptr _ptr_type;
    typedef TLSX509IdentityProcessor_var _var_type;
    #endif

    static TLSX509IdentityProcessor_ptr _narrow( CORBA::Object_ptr obj );
    static TLSX509IdentityProcessor_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TLSX509IdentityProcessor_ptr _duplicate( TLSX509IdentityProcessor_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TLSX509IdentityProcessor_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual CORBA::Boolean verify_identity( ::SL3PM::Principal* ident ) = 0;

  protected:
    TLSX509IdentityProcessor() {};
  private:
    TLSX509IdentityProcessor( const TLSX509IdentityProcessor& );
    void operator=( const TLSX509IdentityProcessor& );
};



/*
 * Base class and common definitions for local interface OpenSSLConfigArgBuilder
 */

class OpenSSLConfigArgBuilder : 
  virtual public ::SL3TCPIP::TCPIPArgBuilder
{
  public:
    virtual ~OpenSSLConfigArgBuilder();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef OpenSSLConfigArgBuilder_ptr _ptr_type;
    typedef OpenSSLConfigArgBuilder_var _var_type;
    #endif

    static OpenSSLConfigArgBuilder_ptr _narrow( CORBA::Object_ptr obj );
    static OpenSSLConfigArgBuilder_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static OpenSSLConfigArgBuilder_ptr _duplicate( OpenSSLConfigArgBuilder_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static OpenSSLConfigArgBuilder_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void add_tls_acceptor_options( const char* ca, const char* cert, const char* key ) = 0;
    virtual void add_tls_acceptor_options_with_passphrase( const char* ca, const char* cert, const char* key, const char* passphrase ) = 0;
    virtual void add_tls_initiator_options( const char* ca, const char* cert, const char* key ) = 0;
    virtual void add_tls_initiator_options_with_passphrase( const char* ca, const char* cert, const char* key, const char* passphrase ) = 0;
    virtual void add_tls_anonymous_initiator_options( const char* ca ) = 0;
    virtual void add_initiator_cipher( const char* cipher ) = 0;
    virtual void add_acceptor_cipher( const char* cipher ) = 0;
    virtual void add_initiator_verify_depth( CORBA::Long depth ) = 0;
    virtual void add_acceptor_verify_depth( CORBA::Long depth ) = 0;
    virtual void add_initiator_identity_verifier( ::SL3TLS::TLSX509IdentityVerifier_ptr verifier ) = 0;
    virtual void add_acceptor_identity_verifier( ::SL3TLS::TLSX509IdentityVerifier_ptr verifier ) = 0;

  protected:
    OpenSSLConfigArgBuilder() {};
  private:
    OpenSSLConfigArgBuilder( const OpenSSLConfigArgBuilder& );
    void operator=( const OpenSSLConfigArgBuilder& );
};


}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

#endif
