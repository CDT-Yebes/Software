/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __SL3AQARGS_P_H__
#define __SL3AQARGS_P_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace SL3AQArgs
{

class ArgsHolder;
typedef ArgsHolder *ArgsHolder_ptr;
typedef ArgsHolder_ptr ArgsHolderRef;
typedef ObjVar< ArgsHolder > ArgsHolder_var;
typedef ObjOut< ArgsHolder > ArgsHolder_out;

class CSIv1Support;
typedef CSIv1Support *CSIv1Support_ptr;
typedef CSIv1Support_ptr CSIv1SupportRef;
typedef ObjVar< CSIv1Support > CSIv1Support_var;
typedef ObjOut< CSIv1Support > CSIv1Support_out;

class CSIv2Support;
typedef CSIv2Support *CSIv2Support_ptr;
typedef CSIv2Support_ptr CSIv2SupportRef;
typedef ObjVar< CSIv2Support > CSIv2Support_var;
typedef ObjOut< CSIv2Support > CSIv2Support_out;

class TCPIPInitiatorArgument;
typedef TCPIPInitiatorArgument *TCPIPInitiatorArgument_ptr;
typedef TCPIPInitiatorArgument_ptr TCPIPInitiatorArgumentRef;
typedef ObjVar< TCPIPInitiatorArgument > TCPIPInitiatorArgument_var;
typedef ObjOut< TCPIPInitiatorArgument > TCPIPInitiatorArgument_out;

class TCPIPAcceptorArgument;
typedef TCPIPAcceptorArgument *TCPIPAcceptorArgument_ptr;
typedef TCPIPAcceptorArgument_ptr TCPIPAcceptorArgumentRef;
typedef ObjVar< TCPIPAcceptorArgument > TCPIPAcceptorArgument_var;
typedef ObjOut< TCPIPAcceptorArgument > TCPIPAcceptorArgument_out;

class TLSX509IdentityVerifierInitiatorArgument;
typedef TLSX509IdentityVerifierInitiatorArgument *TLSX509IdentityVerifierInitiatorArgument_ptr;
typedef TLSX509IdentityVerifierInitiatorArgument_ptr TLSX509IdentityVerifierInitiatorArgumentRef;
typedef ObjVar< TLSX509IdentityVerifierInitiatorArgument > TLSX509IdentityVerifierInitiatorArgument_var;
typedef ObjOut< TLSX509IdentityVerifierInitiatorArgument > TLSX509IdentityVerifierInitiatorArgument_out;

class TLSX509IdentityVerifierAcceptorArgument;
typedef TLSX509IdentityVerifierAcceptorArgument *TLSX509IdentityVerifierAcceptorArgument_ptr;
typedef TLSX509IdentityVerifierAcceptorArgument_ptr TLSX509IdentityVerifierAcceptorArgumentRef;
typedef ObjVar< TLSX509IdentityVerifierAcceptorArgument > TLSX509IdentityVerifierAcceptorArgument_var;
typedef ObjOut< TLSX509IdentityVerifierAcceptorArgument > TLSX509IdentityVerifierAcceptorArgument_out;

class OpenSSLInitiatorArgument;
typedef OpenSSLInitiatorArgument *OpenSSLInitiatorArgument_ptr;
typedef OpenSSLInitiatorArgument_ptr OpenSSLInitiatorArgumentRef;
typedef ObjVar< OpenSSLInitiatorArgument > OpenSSLInitiatorArgument_var;
typedef ObjOut< OpenSSLInitiatorArgument > OpenSSLInitiatorArgument_out;

class OpenSSLAcceptorArgument;
typedef OpenSSLAcceptorArgument *OpenSSLAcceptorArgument_ptr;
typedef OpenSSLAcceptorArgument_ptr OpenSSLAcceptorArgumentRef;
typedef ObjVar< OpenSSLAcceptorArgument > OpenSSLAcceptorArgument_var;
typedef ObjOut< OpenSSLAcceptorArgument > OpenSSLAcceptorArgument_out;

class TransportCredentialsArgument;
typedef TransportCredentialsArgument *TransportCredentialsArgument_ptr;
typedef TransportCredentialsArgument_ptr TransportCredentialsArgumentRef;
typedef ObjVar< TransportCredentialsArgument > TransportCredentialsArgument_var;
typedef ObjOut< TransportCredentialsArgument > TransportCredentialsArgument_out;

class DeciderArgument;
typedef DeciderArgument *DeciderArgument_ptr;
typedef DeciderArgument_ptr DeciderArgumentRef;
typedef ObjVar< DeciderArgument > DeciderArgument_var;
typedef ObjOut< DeciderArgument > DeciderArgument_out;

class GeneratorArgument;
typedef GeneratorArgument *GeneratorArgument_ptr;
typedef GeneratorArgument_ptr GeneratorArgumentRef;
typedef ObjVar< GeneratorArgument > GeneratorArgument_var;
typedef ObjOut< GeneratorArgument > GeneratorArgument_out;

class ProcessorArgument;
typedef ProcessorArgument *ProcessorArgument_ptr;
typedef ProcessorArgument_ptr ProcessorArgumentRef;
typedef ObjVar< ProcessorArgument > ProcessorArgument_var;
typedef ObjOut< ProcessorArgument > ProcessorArgument_out;

class QuotingPrincipalArgument;
typedef QuotingPrincipalArgument *QuotingPrincipalArgument_ptr;
typedef QuotingPrincipalArgument_ptr QuotingPrincipalArgumentRef;
typedef ObjVar< QuotingPrincipalArgument > QuotingPrincipalArgument_var;
typedef ObjOut< QuotingPrincipalArgument > QuotingPrincipalArgument_out;

class ATLASArgument;
typedef ATLASArgument *ATLASArgument_ptr;
typedef ATLASArgument_ptr ATLASArgumentRef;
typedef ObjVar< ATLASArgument > ATLASArgument_var;
typedef ObjOut< ATLASArgument > ATLASArgument_out;

class TokenProcessorSeqArgument;
typedef TokenProcessorSeqArgument *TokenProcessorSeqArgument_ptr;
typedef TokenProcessorSeqArgument_ptr TokenProcessorSeqArgumentRef;
typedef ObjVar< TokenProcessorSeqArgument > TokenProcessorSeqArgument_var;
typedef ObjOut< TokenProcessorSeqArgument > TokenProcessorSeqArgument_out;

class IPCInitiatorArgument;
typedef IPCInitiatorArgument *IPCInitiatorArgument_ptr;
typedef IPCInitiatorArgument_ptr IPCInitiatorArgumentRef;
typedef ObjVar< IPCInitiatorArgument > IPCInitiatorArgument_var;
typedef ObjOut< IPCInitiatorArgument > IPCInitiatorArgument_out;

class IPCAcceptorArgument;
typedef IPCAcceptorArgument *IPCAcceptorArgument_ptr;
typedef IPCAcceptorArgument_ptr IPCAcceptorArgumentRef;
typedef ObjVar< IPCAcceptorArgument > IPCAcceptorArgument_var;
typedef ObjOut< IPCAcceptorArgument > IPCAcceptorArgument_out;

class ObserverSeqArgument;
typedef ObserverSeqArgument *ObserverSeqArgument_ptr;
typedef ObserverSeqArgument_ptr ObserverSeqArgumentRef;
typedef ObjVar< ObserverSeqArgument > ObserverSeqArgument_var;
typedef ObjOut< ObserverSeqArgument > ObserverSeqArgument_out;

class IdentityProcessorArgument;
typedef IdentityProcessorArgument *IdentityProcessorArgument_ptr;
typedef IdentityProcessorArgument_ptr IdentityProcessorArgumentRef;
typedef ObjVar< IdentityProcessorArgument > IdentityProcessorArgument_var;
typedef ObjOut< IdentityProcessorArgument > IdentityProcessorArgument_out;

}






namespace SL3AQArgs
{

const char* const ArgsHolderType = "ArgsHolder";

/*
 * Base class and common definitions for local interface ArgsHolder
 */

class ArgsHolder : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~ArgsHolder();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ArgsHolder_ptr _ptr_type;
    typedef ArgsHolder_var _var_type;
    #endif

    static ArgsHolder_ptr _narrow( CORBA::Object_ptr obj );
    static ArgsHolder_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ArgsHolder_ptr _duplicate( ArgsHolder_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ArgsHolder_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3CM::CredentialsUsage usage() = 0;
    virtual ::SL3AQArgs::ArgumentSeq* args() = 0;

  protected:
    ArgsHolder() {};
  private:
    ArgsHolder( const ArgsHolder& );
    void operator=( const ArgsHolder& );
};


const char* const CSIv1SupportType = "CSIv1Support";

/*
 * Base class and common definitions for local interface CSIv1Support
 */

class CSIv1Support : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~CSIv1Support();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef CSIv1Support_ptr _ptr_type;
    typedef CSIv1Support_var _var_type;
    #endif

    static CSIv1Support_ptr _narrow( CORBA::Object_ptr obj );
    static CSIv1Support_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static CSIv1Support_ptr _duplicate( CSIv1Support_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static CSIv1Support_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual CORBA::Boolean support() = 0;

  protected:
    CSIv1Support() {};
  private:
    CSIv1Support( const CSIv1Support& );
    void operator=( const CSIv1Support& );
};


const char* const CSIv2SupportType = "CSIv2Support";

/*
 * Base class and common definitions for local interface CSIv2Support
 */

class CSIv2Support : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~CSIv2Support();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef CSIv2Support_ptr _ptr_type;
    typedef CSIv2Support_var _var_type;
    #endif

    static CSIv2Support_ptr _narrow( CORBA::Object_ptr obj );
    static CSIv2Support_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static CSIv2Support_ptr _duplicate( CSIv2Support_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static CSIv2Support_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual CORBA::Boolean support() = 0;

  protected:
    CSIv2Support() {};
  private:
    CSIv2Support( const CSIv2Support& );
    void operator=( const CSIv2Support& );
};


struct TCPIPInitiatorOptions;
typedef TVarVar< TCPIPInitiatorOptions > TCPIPInitiatorOptions_var;
typedef TVarOut< TCPIPInitiatorOptions > TCPIPInitiatorOptions_out;


struct TCPIPInitiatorOptions {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef TCPIPInitiatorOptions_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  TCPIPInitiatorOptions();
  ~TCPIPInitiatorOptions();
  TCPIPInitiatorOptions( const TCPIPInitiatorOptions& s );
  TCPIPInitiatorOptions& operator=( const TCPIPInitiatorOptions& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  CORBA::String_var bind;
  CORBA::Long low_port;
  CORBA::Long high_port;
  CORBA::Long timeout;
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_TCPIPInitiatorOptions;

const char* const TCPIPInitiatorArgumentType = "TCPIPInitiatorArgument";

/*
 * Base class and common definitions for local interface TCPIPInitiatorArgument
 */

class TCPIPInitiatorArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~TCPIPInitiatorArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TCPIPInitiatorArgument_ptr _ptr_type;
    typedef TCPIPInitiatorArgument_var _var_type;
    #endif

    static TCPIPInitiatorArgument_ptr _narrow( CORBA::Object_ptr obj );
    static TCPIPInitiatorArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TCPIPInitiatorArgument_ptr _duplicate( TCPIPInitiatorArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TCPIPInitiatorArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3AQArgs::TCPIPInitiatorOptions* options() = 0;

  protected:
    TCPIPInitiatorArgument() {};
  private:
    TCPIPInitiatorArgument( const TCPIPInitiatorArgument& );
    void operator=( const TCPIPInitiatorArgument& );
};


struct TCPIPAcceptorOptions;
typedef TVarVar< TCPIPAcceptorOptions > TCPIPAcceptorOptions_var;
typedef TVarOut< TCPIPAcceptorOptions > TCPIPAcceptorOptions_out;


struct TCPIPAcceptorOptions {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef TCPIPAcceptorOptions_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  TCPIPAcceptorOptions();
  ~TCPIPAcceptorOptions();
  TCPIPAcceptorOptions( const TCPIPAcceptorOptions& s );
  TCPIPAcceptorOptions& operator=( const TCPIPAcceptorOptions& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  ::CORBA::StringSeq hosts;
  CORBA::String_var bind;
  CORBA::Long low_port;
  CORBA::Long high_port;
  CORBA::Long backlog;
  CORBA::Boolean numeric;
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_TCPIPAcceptorOptions;

const char* const TCPIPAcceptorArgumentType = "TCPIPAcceptorArgument";

/*
 * Base class and common definitions for local interface TCPIPAcceptorArgument
 */

class TCPIPAcceptorArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~TCPIPAcceptorArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TCPIPAcceptorArgument_ptr _ptr_type;
    typedef TCPIPAcceptorArgument_var _var_type;
    #endif

    static TCPIPAcceptorArgument_ptr _narrow( CORBA::Object_ptr obj );
    static TCPIPAcceptorArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TCPIPAcceptorArgument_ptr _duplicate( TCPIPAcceptorArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TCPIPAcceptorArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3AQArgs::TCPIPAcceptorOptions* options() = 0;

  protected:
    TCPIPAcceptorArgument() {};
  private:
    TCPIPAcceptorArgument( const TCPIPAcceptorArgument& );
    void operator=( const TCPIPAcceptorArgument& );
};


const char* const TLSX509IdentityVerifierInitiatorArgumentType = "TLSX509IdentityVerifierInitiatorArgument";

/*
 * Base class and common definitions for local interface TLSX509IdentityVerifierInitiatorArgument
 */

class TLSX509IdentityVerifierInitiatorArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~TLSX509IdentityVerifierInitiatorArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TLSX509IdentityVerifierInitiatorArgument_ptr _ptr_type;
    typedef TLSX509IdentityVerifierInitiatorArgument_var _var_type;
    #endif

    static TLSX509IdentityVerifierInitiatorArgument_ptr _narrow( CORBA::Object_ptr obj );
    static TLSX509IdentityVerifierInitiatorArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TLSX509IdentityVerifierInitiatorArgument_ptr _duplicate( TLSX509IdentityVerifierInitiatorArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TLSX509IdentityVerifierInitiatorArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3TLS::TLSX509IdentityVerifier_ptr verifier() = 0;

  protected:
    TLSX509IdentityVerifierInitiatorArgument() {};
  private:
    TLSX509IdentityVerifierInitiatorArgument( const TLSX509IdentityVerifierInitiatorArgument& );
    void operator=( const TLSX509IdentityVerifierInitiatorArgument& );
};


const char* const TLSX509IdentityVerifierAcceptorArgumentType = "TLSX509IdentityVerifierAcceptorArgument";

/*
 * Base class and common definitions for local interface TLSX509IdentityVerifierAcceptorArgument
 */

class TLSX509IdentityVerifierAcceptorArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~TLSX509IdentityVerifierAcceptorArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TLSX509IdentityVerifierAcceptorArgument_ptr _ptr_type;
    typedef TLSX509IdentityVerifierAcceptorArgument_var _var_type;
    #endif

    static TLSX509IdentityVerifierAcceptorArgument_ptr _narrow( CORBA::Object_ptr obj );
    static TLSX509IdentityVerifierAcceptorArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TLSX509IdentityVerifierAcceptorArgument_ptr _duplicate( TLSX509IdentityVerifierAcceptorArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TLSX509IdentityVerifierAcceptorArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3TLS::TLSX509IdentityVerifier_ptr verifier() = 0;

  protected:
    TLSX509IdentityVerifierAcceptorArgument() {};
  private:
    TLSX509IdentityVerifierAcceptorArgument( const TLSX509IdentityVerifierAcceptorArgument& );
    void operator=( const TLSX509IdentityVerifierAcceptorArgument& );
};


struct OpenSSLConfig;
typedef TVarVar< OpenSSLConfig > OpenSSLConfig_var;
typedef TVarOut< OpenSSLConfig > OpenSSLConfig_out;


struct OpenSSLConfig {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef OpenSSLConfig_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  OpenSSLConfig();
  ~OpenSSLConfig();
  OpenSSLConfig( const OpenSSLConfig& s );
  OpenSSLConfig& operator=( const OpenSSLConfig& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  CORBA::String_var cert_file;
  CORBA::String_var key_file;
  CORBA::String_var ca_file;
  CORBA::String_var ca_path;
  CORBA::String_var cipher;
  CORBA::Boolean use_passphrase;
  CORBA::String_var passphrase;
  CORBA::Long verify_depth;
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_OpenSSLConfig;

const char* const OpenSSLInitiatorArgumentType = "OpenSSLInitiatorArgument";

/*
 * Base class and common definitions for local interface OpenSSLInitiatorArgument
 */

class OpenSSLInitiatorArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~OpenSSLInitiatorArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef OpenSSLInitiatorArgument_ptr _ptr_type;
    typedef OpenSSLInitiatorArgument_var _var_type;
    #endif

    static OpenSSLInitiatorArgument_ptr _narrow( CORBA::Object_ptr obj );
    static OpenSSLInitiatorArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static OpenSSLInitiatorArgument_ptr _duplicate( OpenSSLInitiatorArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static OpenSSLInitiatorArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3AQArgs::OpenSSLConfig* config() = 0;

  protected:
    OpenSSLInitiatorArgument() {};
  private:
    OpenSSLInitiatorArgument( const OpenSSLInitiatorArgument& );
    void operator=( const OpenSSLInitiatorArgument& );
};


const char* const OpenSSLAcceptorArgumentType = "OpenSSLAcceptorArgument";

/*
 * Base class and common definitions for local interface OpenSSLAcceptorArgument
 */

class OpenSSLAcceptorArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~OpenSSLAcceptorArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef OpenSSLAcceptorArgument_ptr _ptr_type;
    typedef OpenSSLAcceptorArgument_var _var_type;
    #endif

    static OpenSSLAcceptorArgument_ptr _narrow( CORBA::Object_ptr obj );
    static OpenSSLAcceptorArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static OpenSSLAcceptorArgument_ptr _duplicate( OpenSSLAcceptorArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static OpenSSLAcceptorArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3AQArgs::OpenSSLConfig* config() = 0;

  protected:
    OpenSSLAcceptorArgument() {};
  private:
    OpenSSLAcceptorArgument( const OpenSSLAcceptorArgument& );
    void operator=( const OpenSSLAcceptorArgument& );
};


const char* const TransportCredentialsArgumentType = "TransportCredentialsArgument";

/*
 * Base class and common definitions for local interface TransportCredentialsArgument
 */

class TransportCredentialsArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~TransportCredentialsArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TransportCredentialsArgument_ptr _ptr_type;
    typedef TransportCredentialsArgument_var _var_type;
    #endif

    static TransportCredentialsArgument_ptr _narrow( CORBA::Object_ptr obj );
    static TransportCredentialsArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TransportCredentialsArgument_ptr _duplicate( TransportCredentialsArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TransportCredentialsArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::TransportSecurity::OwnCredentials_ptr creds() = 0;

  protected:
    TransportCredentialsArgument() {};
  private:
    TransportCredentialsArgument( const TransportCredentialsArgument& );
    void operator=( const TransportCredentialsArgument& );
};


const char* const DeciderArgumentType = "LocalTrustInServerDeciderArgument";

/*
 * Base class and common definitions for local interface DeciderArgument
 */

class DeciderArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~DeciderArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef DeciderArgument_ptr _ptr_type;
    typedef DeciderArgument_var _var_type;
    #endif

    static DeciderArgument_ptr _narrow( CORBA::Object_ptr obj );
    static DeciderArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static DeciderArgument_ptr _duplicate( DeciderArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static DeciderArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::Trust::LocalTrustInServerDecider_ptr decider() = 0;

  protected:
    DeciderArgument() {};
  private:
    DeciderArgument( const DeciderArgument& );
    void operator=( const DeciderArgument& );
};


const char* const GeneratorArgumentType = "UserPasswordGenerator";

/*
 * Base class and common definitions for local interface GeneratorArgument
 */

class GeneratorArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~GeneratorArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef GeneratorArgument_ptr _ptr_type;
    typedef GeneratorArgument_var _var_type;
    #endif

    static GeneratorArgument_ptr _narrow( CORBA::Object_ptr obj );
    static GeneratorArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static GeneratorArgument_ptr _duplicate( GeneratorArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static GeneratorArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::UserPassword::PasswordGenerator_ptr generator() = 0;

  protected:
    GeneratorArgument() {};
  private:
    GeneratorArgument( const GeneratorArgument& );
    void operator=( const GeneratorArgument& );
};


const char* const ProcessorArgumentType = "UserPasswordProcessor";

/*
 * Base class and common definitions for local interface ProcessorArgument
 */

class ProcessorArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~ProcessorArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ProcessorArgument_ptr _ptr_type;
    typedef ProcessorArgument_var _var_type;
    #endif

    static ProcessorArgument_ptr _narrow( CORBA::Object_ptr obj );
    static ProcessorArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ProcessorArgument_ptr _duplicate( ProcessorArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ProcessorArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::UserPassword::PasswordProcessor_ptr processor() = 0;

  protected:
    ProcessorArgument() {};
  private:
    ProcessorArgument( const ProcessorArgument& );
    void operator=( const ProcessorArgument& );
};


const char* const QuotingPrincipalArgumentType = "QuotingPrincipal";

/*
 * Base class and common definitions for local interface QuotingPrincipalArgument
 */

class QuotingPrincipalArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~QuotingPrincipalArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef QuotingPrincipalArgument_ptr _ptr_type;
    typedef QuotingPrincipalArgument_var _var_type;
    #endif

    static QuotingPrincipalArgument_ptr _narrow( CORBA::Object_ptr obj );
    static QuotingPrincipalArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static QuotingPrincipalArgument_ptr _duplicate( QuotingPrincipalArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static QuotingPrincipalArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3PM::QuotingPrincipal* principal() = 0;

  protected:
    QuotingPrincipalArgument() {};
  private:
    QuotingPrincipalArgument( const QuotingPrincipalArgument& );
    void operator=( const QuotingPrincipalArgument& );
};


const char* const ATLASArgumentType = "ATLAS";

/*
 * Base class and common definitions for local interface ATLASArgument
 */

class ATLASArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~ATLASArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ATLASArgument_ptr _ptr_type;
    typedef ATLASArgument_var _var_type;
    #endif

    static ATLASArgument_ptr _narrow( CORBA::Object_ptr obj );
    static ATLASArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ATLASArgument_ptr _duplicate( ATLASArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ATLASArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::ATLAS::ATLASCacheId* cache_id() = 0;
    virtual ::ATLAS::AuthTokenDispenser_ptr token_dispenser() = 0;
    virtual ::SL3Authorization::TokenProcessor_ptr token_processor() = 0;

  protected:
    ATLASArgument() {};
  private:
    ATLASArgument( const ATLASArgument& );
    void operator=( const ATLASArgument& );
};


typedef IfaceSequenceTmpl< ::SL3Authorization::TokenProcessor_var,::SL3Authorization::TokenProcessor_ptr> TokenProcessorSeq;
typedef TSeqVar< IfaceSequenceTmpl< ::SL3Authorization::TokenProcessor_var,::SL3Authorization::TokenProcessor_ptr> > TokenProcessorSeq_var;
typedef TSeqOut< IfaceSequenceTmpl< ::SL3Authorization::TokenProcessor_var,::SL3Authorization::TokenProcessor_ptr> > TokenProcessorSeq_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_TokenProcessorSeq;

const char* const TokenProcessorSeqArgumentType = "TokenProcessorSeq";

/*
 * Base class and common definitions for local interface TokenProcessorSeqArgument
 */

class TokenProcessorSeqArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~TokenProcessorSeqArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TokenProcessorSeqArgument_ptr _ptr_type;
    typedef TokenProcessorSeqArgument_var _var_type;
    #endif

    static TokenProcessorSeqArgument_ptr _narrow( CORBA::Object_ptr obj );
    static TokenProcessorSeqArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TokenProcessorSeqArgument_ptr _duplicate( TokenProcessorSeqArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TokenProcessorSeqArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3AQArgs::TokenProcessorSeq* tpseq() = 0;

  protected:
    TokenProcessorSeqArgument() {};
  private:
    TokenProcessorSeqArgument( const TokenProcessorSeqArgument& );
    void operator=( const TokenProcessorSeqArgument& );
};


const char* const IPCInitiatorArgumentType = "IPCInitiator";

/*
 * Base class and common definitions for local interface IPCInitiatorArgument
 */

class IPCInitiatorArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~IPCInitiatorArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef IPCInitiatorArgument_ptr _ptr_type;
    typedef IPCInitiatorArgument_var _var_type;
    #endif

    static IPCInitiatorArgument_ptr _narrow( CORBA::Object_ptr obj );
    static IPCInitiatorArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static IPCInitiatorArgument_ptr _duplicate( IPCInitiatorArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static IPCInitiatorArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

  protected:
    IPCInitiatorArgument() {};
  private:
    IPCInitiatorArgument( const IPCInitiatorArgument& );
    void operator=( const IPCInitiatorArgument& );
};


const char* const IPCAcceptorArgumentType = "IPCAcceptor";

/*
 * Base class and common definitions for local interface IPCAcceptorArgument
 */

class IPCAcceptorArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~IPCAcceptorArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef IPCAcceptorArgument_ptr _ptr_type;
    typedef IPCAcceptorArgument_var _var_type;
    #endif

    static IPCAcceptorArgument_ptr _narrow( CORBA::Object_ptr obj );
    static IPCAcceptorArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static IPCAcceptorArgument_ptr _duplicate( IPCAcceptorArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static IPCAcceptorArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

  protected:
    IPCAcceptorArgument() {};
  private:
    IPCAcceptorArgument( const IPCAcceptorArgument& );
    void operator=( const IPCAcceptorArgument& );
};


const char* const ObserverSeqArgumentType = "ObserverSeq";

/*
 * Base class and common definitions for local interface ObserverSeqArgument
 */

class ObserverSeqArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~ObserverSeqArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ObserverSeqArgument_ptr _ptr_type;
    typedef ObserverSeqArgument_var _var_type;
    #endif

    static ObserverSeqArgument_ptr _narrow( CORBA::Object_ptr obj );
    static ObserverSeqArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ObserverSeqArgument_ptr _duplicate( ObserverSeqArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ObserverSeqArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3OM::ObserverSeq* observers() = 0;

  protected:
    ObserverSeqArgument() {};
  private:
    ObserverSeqArgument( const ObserverSeqArgument& );
    void operator=( const ObserverSeqArgument& );
};


const char* const IdentityProcessorArgumentType = "TLSX509IdentityProcessor";

/*
 * Base class and common definitions for local interface IdentityProcessorArgument
 */

class IdentityProcessorArgument : 
  virtual public ::SL3AQArgs::Argument
{
  public:
    virtual ~IdentityProcessorArgument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef IdentityProcessorArgument_ptr _ptr_type;
    typedef IdentityProcessorArgument_var _var_type;
    #endif

    static IdentityProcessorArgument_ptr _narrow( CORBA::Object_ptr obj );
    static IdentityProcessorArgument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static IdentityProcessorArgument_ptr _duplicate( IdentityProcessorArgument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static IdentityProcessorArgument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3TLS::TLSX509IdentityProcessor_ptr processor() = 0;

  protected:
    IdentityProcessorArgument() {};
  private:
    IdentityProcessorArgument( const IdentityProcessorArgument& );
    void operator=( const IdentityProcessorArgument& );
};


}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

void operator<<=( CORBA::Any &_a, const ::SL3AQArgs::TCPIPInitiatorOptions &_s );
void operator<<=( CORBA::Any &_a, ::SL3AQArgs::TCPIPInitiatorOptions *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::SL3AQArgs::TCPIPInitiatorOptions &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::SL3AQArgs::TCPIPInitiatorOptions *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3AQArgs_TCPIPInitiatorOptions;

void operator<<=( CORBA::Any &_a, const ::SL3AQArgs::TCPIPAcceptorOptions &_s );
void operator<<=( CORBA::Any &_a, ::SL3AQArgs::TCPIPAcceptorOptions *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::SL3AQArgs::TCPIPAcceptorOptions &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::SL3AQArgs::TCPIPAcceptorOptions *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3AQArgs_TCPIPAcceptorOptions;

void operator<<=( CORBA::Any &_a, const ::SL3AQArgs::OpenSSLConfig &_s );
void operator<<=( CORBA::Any &_a, ::SL3AQArgs::OpenSSLConfig *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::SL3AQArgs::OpenSSLConfig &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::SL3AQArgs::OpenSSLConfig *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3AQArgs_OpenSSLConfig;

#endif
