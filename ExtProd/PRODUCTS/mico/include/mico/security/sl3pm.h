/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __SL3PM_H__
#define __SL3PM_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32






namespace SL3PM
{

typedef char* NameType;
typedef CORBA::String_var NameType_var;
typedef CORBA::String_out NameType_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_NameType;

typedef CORBA::WChar* NameComponent;
typedef CORBA::WString_var NameComponent_var;
typedef CORBA::WString_out NameComponent_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_NameComponent;

typedef WStringSequenceTmpl<CORBA::WString_var> NamePath;
typedef TSeqVar< WStringSequenceTmpl<CORBA::WString_var> > NamePath_var;
typedef TSeqOut< WStringSequenceTmpl<CORBA::WString_var> > NamePath_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_NamePath;

typedef NamePath NameValue;
typedef TSeqVar< NamePath > NameValue_var;
typedef TSeqOut< NamePath > NameValue_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_NameValue;

struct PrincipalName;
typedef TVarVar< PrincipalName > PrincipalName_var;
typedef TVarOut< PrincipalName > PrincipalName_out;


struct PrincipalName {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef PrincipalName_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  PrincipalName();
  ~PrincipalName();
  PrincipalName( const PrincipalName& s );
  PrincipalName& operator=( const PrincipalName& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  NameType_var the_type;
  NameValue the_name;
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_PrincipalName;

typedef SequenceTmpl< PrincipalName,MICO_TID_DEF> PrincipalNameList;
typedef TSeqVar< SequenceTmpl< PrincipalName,MICO_TID_DEF> > PrincipalNameList_var;
typedef TSeqOut< SequenceTmpl< PrincipalName,MICO_TID_DEF> > PrincipalNameList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_PrincipalNameList;

typedef char* PrinAttributeType;
typedef CORBA::String_var PrinAttributeType_var;
typedef CORBA::String_out PrinAttributeType_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_PrinAttributeType;

typedef CORBA::WChar* PrinAttributeValue;
typedef CORBA::WString_var PrinAttributeValue_var;
typedef CORBA::WString_out PrinAttributeValue_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_PrinAttributeValue;

struct PrinAttribute;
typedef TVarVar< PrinAttribute > PrinAttribute_var;
typedef TVarOut< PrinAttribute > PrinAttribute_out;


struct PrinAttribute {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef PrinAttribute_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  PrinAttribute();
  ~PrinAttribute();
  PrinAttribute( const PrinAttribute& s );
  PrinAttribute& operator=( const PrinAttribute& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  PrinAttributeType_var the_type;
  PrinAttributeValue_var the_value;
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_PrinAttribute;

typedef SequenceTmpl< PrinAttribute,MICO_TID_DEF> PrinAttributeList;
typedef TSeqVar< SequenceTmpl< PrinAttribute,MICO_TID_DEF> > PrinAttributeList_var;
typedef TSeqOut< SequenceTmpl< PrinAttribute,MICO_TID_DEF> > PrinAttributeList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_PrinAttributeList;

struct ResourceName;
typedef TVarVar< ResourceName > ResourceName_var;
typedef TVarOut< ResourceName > ResourceName_out;


struct ResourceName {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef ResourceName_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  ResourceName();
  ~ResourceName();
  ResourceName( const ResourceName& s );
  ResourceName& operator=( const ResourceName& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  typedef StringSequenceTmpl<CORBA::String_var> _components_seq;
  _components_seq components;
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ResourceName;

typedef SequenceTmpl< ResourceName,MICO_TID_DEF> ResourceNameList;
typedef TSeqVar< SequenceTmpl< ResourceName,MICO_TID_DEF> > ResourceNameList_var;
typedef TSeqOut< SequenceTmpl< ResourceName,MICO_TID_DEF> > ResourceNameList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ResourceNameList;

const char* const NT_KerberosName = "oid:1.2.840.113554.1.2.2.1";
const char* const NT_X509DirectoryNamePath = "SL3:X509DirectoryPathName";
const char* const NT_Anonymous = "SL3:anonymous";
const char* const NT_StringName = "oid:2.23.130.1.2.1";
struct ScopedPrivileges;
typedef TVarVar< ScopedPrivileges > ScopedPrivileges_var;
typedef TVarOut< ScopedPrivileges > ScopedPrivileges_out;


struct ScopedPrivileges {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef ScopedPrivileges_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  ScopedPrivileges();
  ~ScopedPrivileges();
  ScopedPrivileges( const ScopedPrivileges& s );
  ScopedPrivileges& operator=( const ScopedPrivileges& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  PrincipalName privilege_authority;
  PrinAttributeList privileges;
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ScopedPrivileges;

typedef SequenceTmpl< ScopedPrivileges,MICO_TID_DEF> ScopedPrivilegesList;
typedef TSeqVar< SequenceTmpl< ScopedPrivileges,MICO_TID_DEF> > ScopedPrivilegesList_var;
typedef TSeqOut< SequenceTmpl< ScopedPrivileges,MICO_TID_DEF> > ScopedPrivilegesList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ScopedPrivilegesList;

typedef CORBA::ULong PrincipalType;
typedef PrincipalType& PrincipalType_out;
extern MICO_EXPORT CORBA::TypeCodeConst _tc_PrincipalType;

const PrincipalType PT_Simple = 0;
const PrincipalType PT_Quoting = 1;
const PrincipalType PT_Proxy = 2;
class Principal;
typedef Principal *Principal_ptr;
typedef Principal_ptr PrincipalRef;
typedef ValueVar< Principal > Principal_var;
typedef ValueOut< Principal > Principal_out;


// Common definitions for valuetype Principal
class Principal : 
  virtual public CORBA::ValueBase
{
  public:
    static Principal* _downcast (CORBA::ValueBase *);
    static Principal* _downcast (CORBA::AbstractBase *);

    virtual void the_type( ::SL3PM::PrincipalType _p ) = 0;
    virtual ::SL3PM::PrincipalType the_type() const = 0;

    virtual void the_name( const ::SL3PM::PrincipalName& _p ) = 0;
    virtual const ::SL3PM::PrincipalName& the_name() const = 0;
    virtual ::SL3PM::PrincipalName& the_name() = 0;

    virtual void with_privileges( const ::SL3PM::ScopedPrivilegesList& _p ) = 0;
    virtual const ::SL3PM::ScopedPrivilegesList& with_privileges() const = 0;
    virtual ::SL3PM::ScopedPrivilegesList& with_privileges() = 0;


  public:
    CORBA::ValueBase * _copy_value ();
    CORBA::ValueDef_ptr get_value_def ();
    virtual void * _narrow_helper (const char *);
    void _get_marshal_info (std::vector<std::string> &, CORBA::Boolean &);
    void _marshal_members (CORBA::DataEncoder &);
    CORBA::Boolean _demarshal_members (CORBA::DataDecoder &);

  protected:
    Principal ();
    virtual ~Principal ();
    void _copy_members (const Principal&);

  private:
    Principal (const Principal &);
    void operator= (const Principal &);
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_Principal;

typedef SequenceTmpl< Principal_var,MICO_TID_DEF> PrincipalList;
typedef TSeqVar< SequenceTmpl< Principal_var,MICO_TID_DEF> > PrincipalList_var;
typedef TSeqOut< SequenceTmpl< Principal_var,MICO_TID_DEF> > PrincipalList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_PrincipalList;

class SimplePrincipal;
typedef SimplePrincipal *SimplePrincipal_ptr;
typedef SimplePrincipal_ptr SimplePrincipalRef;
typedef ValueVar< SimplePrincipal > SimplePrincipal_var;
typedef ValueOut< SimplePrincipal > SimplePrincipal_out;


// Common definitions for valuetype SimplePrincipal
class SimplePrincipal : 
  virtual public ::SL3PM::Principal
{
  public:
    static SimplePrincipal* _downcast (CORBA::ValueBase *);
    static SimplePrincipal* _downcast (CORBA::AbstractBase *);

    virtual void authenticated( CORBA::Boolean _p ) = 0;
    virtual CORBA::Boolean authenticated() const = 0;

    virtual void alternate_names( const ::SL3PM::PrincipalNameList& _p ) = 0;
    virtual const ::SL3PM::PrincipalNameList& alternate_names() const = 0;
    virtual ::SL3PM::PrincipalNameList& alternate_names() = 0;


  public:
    CORBA::ValueBase * _copy_value ();
    CORBA::ValueDef_ptr get_value_def ();
    virtual void * _narrow_helper (const char *);
    void _get_marshal_info (std::vector<std::string> &, CORBA::Boolean &);
    void _marshal_members (CORBA::DataEncoder &);
    CORBA::Boolean _demarshal_members (CORBA::DataDecoder &);

  protected:
    SimplePrincipal ();
    virtual ~SimplePrincipal ();
    void _copy_members (const SimplePrincipal&);

  private:
    SimplePrincipal (const SimplePrincipal &);
    void operator= (const SimplePrincipal &);
};

class SimplePrincipal_init : public CORBA::ValueFactoryBase
{
  public:
    virtual ~SimplePrincipal_init ();
    static SimplePrincipal_init * _downcast (CORBA::ValueFactory);
    void * _narrow_helper (const char *);

    virtual SimplePrincipal * create (const PrincipalName& the_name, const ScopedPrivilegesList& with_privileges, const PrincipalNameList& alternate_names) = 0;

  protected:
    SimplePrincipal_init ();
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_SimplePrincipal;

class ProxyPrincipal;
typedef ProxyPrincipal *ProxyPrincipal_ptr;
typedef ProxyPrincipal_ptr ProxyPrincipalRef;
typedef ValueVar< ProxyPrincipal > ProxyPrincipal_var;
typedef ValueOut< ProxyPrincipal > ProxyPrincipal_out;


// Common definitions for valuetype ProxyPrincipal
class ProxyPrincipal : 
  virtual public ::SL3PM::Principal
{
  public:
    static ProxyPrincipal* _downcast (CORBA::ValueBase *);
    static ProxyPrincipal* _downcast (CORBA::AbstractBase *);

    virtual void speaking( ::SL3PM::Principal* _p ) = 0;
    virtual ::SL3PM::Principal* speaking() const = 0;

    virtual void speaks_for( ::SL3PM::Principal* _p ) = 0;
    virtual ::SL3PM::Principal* speaks_for() const = 0;


  public:
    CORBA::ValueBase * _copy_value ();
    CORBA::ValueDef_ptr get_value_def ();
    virtual void * _narrow_helper (const char *);
    void _get_marshal_info (std::vector<std::string> &, CORBA::Boolean &);
    void _marshal_members (CORBA::DataEncoder &);
    CORBA::Boolean _demarshal_members (CORBA::DataDecoder &);
    CORBA::Long _count_refs (CORBA::ValueBase::visited * = 0);
    void _release_members ();

  protected:
    ProxyPrincipal ();
    virtual ~ProxyPrincipal ();

  private:
    ProxyPrincipal (const ProxyPrincipal &);
    void operator= (const ProxyPrincipal &);
};

class ProxyPrincipal_init : public CORBA::ValueFactoryBase
{
  public:
    virtual ~ProxyPrincipal_init ();
    static ProxyPrincipal_init * _downcast (CORBA::ValueFactory);
    void * _narrow_helper (const char *);

    virtual ProxyPrincipal * create (Principal* speaking, Principal* speaks_for) = 0;

  protected:
    ProxyPrincipal_init ();
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ProxyPrincipal;

class QuotingPrincipal;
typedef QuotingPrincipal *QuotingPrincipal_ptr;
typedef QuotingPrincipal_ptr QuotingPrincipalRef;
typedef ValueVar< QuotingPrincipal > QuotingPrincipal_var;
typedef ValueOut< QuotingPrincipal > QuotingPrincipal_out;


// Common definitions for valuetype QuotingPrincipal
class QuotingPrincipal : 
  virtual public ::SL3PM::Principal
{
  public:
    static QuotingPrincipal* _downcast (CORBA::ValueBase *);
    static QuotingPrincipal* _downcast (CORBA::AbstractBase *);

    virtual void speaking( ::SL3PM::Principal* _p ) = 0;
    virtual ::SL3PM::Principal* speaking() const = 0;

    virtual void quotes_for( ::SL3PM::Principal* _p ) = 0;
    virtual ::SL3PM::Principal* quotes_for() const = 0;


  public:
    CORBA::ValueBase * _copy_value ();
    CORBA::ValueDef_ptr get_value_def ();
    virtual void * _narrow_helper (const char *);
    void _get_marshal_info (std::vector<std::string> &, CORBA::Boolean &);
    void _marshal_members (CORBA::DataEncoder &);
    CORBA::Boolean _demarshal_members (CORBA::DataDecoder &);
    CORBA::Long _count_refs (CORBA::ValueBase::visited * = 0);
    void _release_members ();

  protected:
    QuotingPrincipal ();
    virtual ~QuotingPrincipal ();

  private:
    QuotingPrincipal (const QuotingPrincipal &);
    void operator= (const QuotingPrincipal &);
};

class QuotingPrincipal_init : public CORBA::ValueFactoryBase
{
  public:
    virtual ~QuotingPrincipal_init ();
    static QuotingPrincipal_init * _downcast (CORBA::ValueFactory);
    void * _narrow_helper (const char *);

    virtual QuotingPrincipal * create (Principal* speaking, Principal* quotes_for) = 0;

  protected:
    QuotingPrincipal_init ();
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_QuotingPrincipal;

typedef CORBA::ULong StatementType;
typedef StatementType& StatementType_out;
extern MICO_EXPORT CORBA::TypeCodeConst _tc_StatementType;

const StatementType ST_IdentityStatement = 1;
const StatementType ST_EndorsementStatement = 2;
typedef SequenceTmpl< CORBA::Octet,MICO_TID_OCTET> Encoding;
typedef TSeqVar< SequenceTmpl< CORBA::Octet,MICO_TID_OCTET> > Encoding_var;
typedef TSeqOut< SequenceTmpl< CORBA::Octet,MICO_TID_OCTET> > Encoding_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_Encoding;

typedef char* EncodingType;
typedef CORBA::String_var EncodingType_var;
typedef CORBA::String_out EncodingType_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_EncodingType;

const char* const ET_NoEncoding = "NoEncoding";
const char* const ET_Unknown = "Unknown";
struct BadEncoding : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  BadEncoding();
  ~BadEncoding();
  BadEncoding( const BadEncoding& s );
  BadEncoding& operator=( const BadEncoding& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  BadEncoding *operator->() { return this; }
  BadEncoding& operator*() { return *this; }
  operator BadEncoding*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static BadEncoding *_downcast( CORBA::Exception *ex );
  static const BadEncoding *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef BadEncoding BadEncoding_catch;
#else
typedef ExceptVar< BadEncoding > BadEncoding_var;
typedef TVarOut< BadEncoding > BadEncoding_out;
typedef BadEncoding_var BadEncoding_catch;
#endif // HAVE_STD_EH

extern MICO_EXPORT CORBA::TypeCodeConst _tc_BadEncoding;

struct BadEncodingType : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  BadEncodingType();
  ~BadEncodingType();
  BadEncodingType( const BadEncodingType& s );
  BadEncodingType& operator=( const BadEncodingType& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  BadEncodingType *operator->() { return this; }
  BadEncodingType& operator*() { return *this; }
  operator BadEncodingType*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static BadEncodingType *_downcast( CORBA::Exception *ex );
  static const BadEncodingType *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef BadEncodingType BadEncodingType_catch;
#else
typedef ExceptVar< BadEncodingType > BadEncodingType_var;
typedef TVarOut< BadEncodingType > BadEncodingType_out;
typedef BadEncodingType_var BadEncodingType_catch;
#endif // HAVE_STD_EH

extern MICO_EXPORT CORBA::TypeCodeConst _tc_BadEncodingType;

typedef CORBA::ULong StatementLayer;
typedef StatementLayer& StatementLayer_out;
extern MICO_EXPORT CORBA::TypeCodeConst _tc_StatementLayer;

const StatementLayer SL_Unknown = 0;
const StatementLayer SL_Transport = 1;
const StatementLayer SL_CSIAuthorization = 2;
const StatementLayer SL_CSIClientAuth = 3;
const StatementLayer SL_CSIIdentity = 4;
const StatementLayer SL_UserDefined = 5;
class Statement;
typedef Statement *Statement_ptr;
typedef Statement_ptr StatementRef;
typedef ValueVar< Statement > Statement_var;
typedef ValueOut< Statement > Statement_out;


// Common definitions for valuetype Statement
class Statement : 
  virtual public CORBA::ValueBase
{
  public:
    static Statement* _downcast (CORBA::ValueBase *);
    static Statement* _downcast (CORBA::AbstractBase *);

    virtual char* get_encoding_type() = 0;
    virtual ::SL3PM::Encoding* get_encoding( const char* encoding_type ) = 0;

    virtual void the_layer( ::SL3PM::StatementLayer _p ) = 0;
    virtual ::SL3PM::StatementLayer the_layer() const = 0;

    virtual void the_type( ::SL3PM::StatementType _p ) = 0;
    virtual ::SL3PM::StatementType the_type() const = 0;

  protected:
    virtual void encoding_type( char *_p ) = 0;
    virtual void encoding_type( const char *_p ) = 0;
    virtual void encoding_type( const CORBA::String_var &_p ) = 0;
    virtual const char *encoding_type() const = 0;

    virtual void the_encoding( const ::SL3PM::Encoding& _p ) = 0;
    virtual const ::SL3PM::Encoding& the_encoding() const = 0;
    virtual ::SL3PM::Encoding& the_encoding() = 0;


  public:
    CORBA::ValueBase * _copy_value ();
    CORBA::ValueDef_ptr get_value_def ();
    virtual void * _narrow_helper (const char *);
    void _get_marshal_info (std::vector<std::string> &, CORBA::Boolean &);
    void _marshal_members (CORBA::DataEncoder &);
    CORBA::Boolean _demarshal_members (CORBA::DataDecoder &);

  protected:
    Statement ();
    virtual ~Statement ();
    void _copy_members (const Statement&);

  private:
    Statement (const Statement &);
    void operator= (const Statement &);
};

class Statement_init : public CORBA::ValueFactoryBase
{
  public:
    virtual ~Statement_init ();
    static Statement_init * _downcast (CORBA::ValueFactory);
    void * _narrow_helper (const char *);

    virtual Statement * create (const char* encoding_type, const Encoding& the_encoding) = 0;

  protected:
    Statement_init ();
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_Statement;

typedef SequenceTmpl< Statement_var,MICO_TID_DEF> StatementList;
typedef TSeqVar< SequenceTmpl< Statement_var,MICO_TID_DEF> > StatementList_var;
typedef TSeqOut< SequenceTmpl< Statement_var,MICO_TID_DEF> > StatementList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_StatementList;

class IdentityStatement;
typedef IdentityStatement *IdentityStatement_ptr;
typedef IdentityStatement_ptr IdentityStatementRef;
typedef ValueVar< IdentityStatement > IdentityStatement_var;
typedef ValueOut< IdentityStatement > IdentityStatement_out;


// Common definitions for valuetype IdentityStatement
class IdentityStatement : 
  virtual public ::SL3PM::Statement
{
  public:
    static IdentityStatement* _downcast (CORBA::ValueBase *);
    static IdentityStatement* _downcast (CORBA::AbstractBase *);

    virtual void interpretation_aid( char *_p ) = 0;
    virtual void interpretation_aid( const char *_p ) = 0;
    virtual void interpretation_aid( const CORBA::String_var &_p ) = 0;
    virtual const char *interpretation_aid() const = 0;


  public:
    CORBA::ValueBase * _copy_value ();
    CORBA::ValueDef_ptr get_value_def ();
    virtual void * _narrow_helper (const char *);
    void _get_marshal_info (std::vector<std::string> &, CORBA::Boolean &);
    void _marshal_members (CORBA::DataEncoder &);
    CORBA::Boolean _demarshal_members (CORBA::DataDecoder &);

  protected:
    IdentityStatement ();
    virtual ~IdentityStatement ();
    void _copy_members (const IdentityStatement&);

  private:
    IdentityStatement (const IdentityStatement &);
    void operator= (const IdentityStatement &);
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_IdentityStatement;

class PrincipalIdentityStatement;
typedef PrincipalIdentityStatement *PrincipalIdentityStatement_ptr;
typedef PrincipalIdentityStatement_ptr PrincipalIdentityStatementRef;
typedef ValueVar< PrincipalIdentityStatement > PrincipalIdentityStatement_var;
typedef ValueOut< PrincipalIdentityStatement > PrincipalIdentityStatement_out;


// Common definitions for valuetype PrincipalIdentityStatement
class PrincipalIdentityStatement : 
  virtual public ::SL3PM::IdentityStatement
{
  public:
    static PrincipalIdentityStatement* _downcast (CORBA::ValueBase *);
    static PrincipalIdentityStatement* _downcast (CORBA::AbstractBase *);

    virtual void the_principal( ::SL3PM::Principal* _p ) = 0;
    virtual ::SL3PM::Principal* the_principal() const = 0;


  public:
    CORBA::ValueBase * _copy_value ();
    CORBA::ValueDef_ptr get_value_def ();
    virtual void * _narrow_helper (const char *);
    void _get_marshal_info (std::vector<std::string> &, CORBA::Boolean &);
    void _marshal_members (CORBA::DataEncoder &);
    CORBA::Boolean _demarshal_members (CORBA::DataDecoder &);

  protected:
    PrincipalIdentityStatement ();
    virtual ~PrincipalIdentityStatement ();
    void _copy_members (const PrincipalIdentityStatement&);

  private:
    PrincipalIdentityStatement (const PrincipalIdentityStatement &);
    void operator= (const PrincipalIdentityStatement &);
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_PrincipalIdentityStatement;

class EndorsementStatement;
typedef EndorsementStatement *EndorsementStatement_ptr;
typedef EndorsementStatement_ptr EndorsementStatementRef;
typedef ValueVar< EndorsementStatement > EndorsementStatement_var;
typedef ValueOut< EndorsementStatement > EndorsementStatement_out;


// Common definitions for valuetype EndorsementStatement
class EndorsementStatement : 
  virtual public ::SL3PM::Statement
{
  public:
    static EndorsementStatement* _downcast (CORBA::ValueBase *);
    static EndorsementStatement* _downcast (CORBA::AbstractBase *);

    virtual void interpretation_aid( char *_p ) = 0;
    virtual void interpretation_aid( const char *_p ) = 0;
    virtual void interpretation_aid( const CORBA::String_var &_p ) = 0;
    virtual const char *interpretation_aid() const = 0;


  public:
    CORBA::ValueBase * _copy_value ();
    CORBA::ValueDef_ptr get_value_def ();
    virtual void * _narrow_helper (const char *);
    void _get_marshal_info (std::vector<std::string> &, CORBA::Boolean &);
    void _marshal_members (CORBA::DataEncoder &);
    CORBA::Boolean _demarshal_members (CORBA::DataDecoder &);

  protected:
    EndorsementStatement ();
    virtual ~EndorsementStatement ();
    void _copy_members (const EndorsementStatement&);

  private:
    EndorsementStatement (const EndorsementStatement &);
    void operator= (const EndorsementStatement &);
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_EndorsementStatement;

class X509IdentityStatement;
typedef X509IdentityStatement *X509IdentityStatement_ptr;
typedef X509IdentityStatement_ptr X509IdentityStatementRef;
typedef ValueVar< X509IdentityStatement > X509IdentityStatement_var;
typedef ValueOut< X509IdentityStatement > X509IdentityStatement_out;


// Common definitions for valuetype X509IdentityStatement
class X509IdentityStatement : 
  virtual public ::SL3PM::PrincipalIdentityStatement
{
  public:
    static X509IdentityStatement* _downcast (CORBA::ValueBase *);
    static X509IdentityStatement* _downcast (CORBA::AbstractBase *);

  public:
    CORBA::ValueBase * _copy_value ();
    CORBA::ValueDef_ptr get_value_def ();
    virtual void * _narrow_helper (const char *);
    void _get_marshal_info (std::vector<std::string> &, CORBA::Boolean &);
    void _marshal_members (CORBA::DataEncoder &);
    CORBA::Boolean _demarshal_members (CORBA::DataDecoder &);

  protected:
    X509IdentityStatement ();
    virtual ~X509IdentityStatement ();
    void _copy_members (const X509IdentityStatement&);

  private:
    X509IdentityStatement (const X509IdentityStatement &);
    void operator= (const X509IdentityStatement &);
};

class X509IdentityStatement_init : public CORBA::ValueFactoryBase
{
  public:
    virtual ~X509IdentityStatement_init ();
    static X509IdentityStatement_init * _downcast (CORBA::ValueFactory);
    void * _narrow_helper (const char *);

    virtual X509IdentityStatement * create (const char* encoding_type, const Encoding& the_encoding) = 0;

  protected:
    X509IdentityStatement_init ();
};

extern MICO_EXPORT CORBA::TypeCodeConst _tc_X509IdentityStatement;

typedef SequenceTmpl< X509IdentityStatement_var,MICO_TID_DEF> X509IdentityStatementList;
typedef TSeqVar< SequenceTmpl< X509IdentityStatement_var,MICO_TID_DEF> > X509IdentityStatementList_var;
typedef TSeqOut< SequenceTmpl< X509IdentityStatement_var,MICO_TID_DEF> > X509IdentityStatementList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_X509IdentityStatementList;

}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA



namespace OBV_SL3PM
{


// OBV class for valuetype Principal
class Principal : virtual public SL3PM::Principal
{
  public:
    Principal ();
    Principal (::SL3PM::PrincipalType _the_type, const ::SL3PM::PrincipalName& _the_name, const ::SL3PM::ScopedPrivilegesList& _with_privileges);
    virtual ~Principal();

  public:
    void the_type( ::SL3PM::PrincipalType _p );
    ::SL3PM::PrincipalType the_type() const;

    void the_name( const ::SL3PM::PrincipalName& _p );
    const ::SL3PM::PrincipalName& the_name() const;
    ::SL3PM::PrincipalName& the_name();

    void with_privileges( const ::SL3PM::ScopedPrivilegesList& _p );
    const ::SL3PM::ScopedPrivilegesList& with_privileges() const;
    ::SL3PM::ScopedPrivilegesList& with_privileges();


  private:
    struct _M {
      ::SL3PM::PrincipalType the_type;
      ::SL3PM::PrincipalName the_name;
      ::SL3PM::ScopedPrivilegesList with_privileges;
    } _m;
};


// OBV class for valuetype SimplePrincipal
class SimplePrincipal :
  virtual public SL3PM::SimplePrincipal,
  virtual public OBV_SL3PM::Principal
{
  public:
    SimplePrincipal ();
    SimplePrincipal (::SL3PM::PrincipalType _the_type, const ::SL3PM::PrincipalName& _the_name, const ::SL3PM::ScopedPrivilegesList& _with_privileges, CORBA::Boolean _authenticated, const ::SL3PM::PrincipalNameList& _alternate_names);
    virtual ~SimplePrincipal();

  public:
    void authenticated( CORBA::Boolean _p );
    CORBA::Boolean authenticated() const;

    void alternate_names( const ::SL3PM::PrincipalNameList& _p );
    const ::SL3PM::PrincipalNameList& alternate_names() const;
    ::SL3PM::PrincipalNameList& alternate_names();


  private:
    struct _M {
      CORBA::Boolean authenticated;
      ::SL3PM::PrincipalNameList alternate_names;
    } _m;
};


// OBV class for valuetype ProxyPrincipal
class ProxyPrincipal :
  virtual public SL3PM::ProxyPrincipal,
  virtual public OBV_SL3PM::Principal
{
  public:
    ProxyPrincipal ();
    ProxyPrincipal (::SL3PM::PrincipalType _the_type, const ::SL3PM::PrincipalName& _the_name, const ::SL3PM::ScopedPrivilegesList& _with_privileges, ::SL3PM::Principal* _speaking, ::SL3PM::Principal* _speaks_for);
    virtual ~ProxyPrincipal();

  public:
    void speaking( ::SL3PM::Principal* _p );
    ::SL3PM::Principal* speaking() const;

    void speaks_for( ::SL3PM::Principal* _p );
    ::SL3PM::Principal* speaks_for() const;


  private:
    struct _M {
      ::SL3PM::Principal_var speaking;
      ::SL3PM::Principal_var speaks_for;
    } _m;
};


// OBV class for valuetype QuotingPrincipal
class QuotingPrincipal :
  virtual public SL3PM::QuotingPrincipal,
  virtual public OBV_SL3PM::Principal
{
  public:
    QuotingPrincipal ();
    QuotingPrincipal (::SL3PM::PrincipalType _the_type, const ::SL3PM::PrincipalName& _the_name, const ::SL3PM::ScopedPrivilegesList& _with_privileges, ::SL3PM::Principal* _speaking, ::SL3PM::Principal* _quotes_for);
    virtual ~QuotingPrincipal();

  public:
    void speaking( ::SL3PM::Principal* _p );
    ::SL3PM::Principal* speaking() const;

    void quotes_for( ::SL3PM::Principal* _p );
    ::SL3PM::Principal* quotes_for() const;


  private:
    struct _M {
      ::SL3PM::Principal_var speaking;
      ::SL3PM::Principal_var quotes_for;
    } _m;
};


// OBV class for valuetype Statement
class Statement : virtual public SL3PM::Statement
{
  protected:
    Statement ();
    Statement (::SL3PM::StatementLayer _the_layer, ::SL3PM::StatementType _the_type, const char* _encoding_type, const ::SL3PM::Encoding& _the_encoding);
    virtual ~Statement();

  public:
    void the_layer( ::SL3PM::StatementLayer _p );
    ::SL3PM::StatementLayer the_layer() const;

    void the_type( ::SL3PM::StatementType _p );
    ::SL3PM::StatementType the_type() const;

  protected:
    void encoding_type( char *_p );
    void encoding_type( const char *_p );
    void encoding_type( const CORBA::String_var &_p );
    const char *encoding_type() const;

    void the_encoding( const ::SL3PM::Encoding& _p );
    const ::SL3PM::Encoding& the_encoding() const;
    ::SL3PM::Encoding& the_encoding();


  private:
    struct _M {
      ::SL3PM::StatementLayer the_layer;
      ::SL3PM::StatementType the_type;
      ::SL3PM::EncodingType_var encoding_type;
      ::SL3PM::Encoding the_encoding;
    } _m;
};


// OBV class for valuetype IdentityStatement
class IdentityStatement :
  virtual public SL3PM::IdentityStatement,
  virtual public OBV_SL3PM::Statement
{
  protected:
    IdentityStatement ();
    IdentityStatement (::SL3PM::StatementLayer _the_layer, ::SL3PM::StatementType _the_type, const char* _encoding_type, const ::SL3PM::Encoding& _the_encoding, const char* _interpretation_aid);
    virtual ~IdentityStatement();

  public:
    void interpretation_aid( char *_p );
    void interpretation_aid( const char *_p );
    void interpretation_aid( const CORBA::String_var &_p );
    const char *interpretation_aid() const;


  private:
    struct _M {
      CORBA::String_var interpretation_aid;
    } _m;
};


// OBV class for valuetype PrincipalIdentityStatement
class PrincipalIdentityStatement :
  virtual public SL3PM::PrincipalIdentityStatement,
  virtual public OBV_SL3PM::IdentityStatement
{
  protected:
    PrincipalIdentityStatement ();
    PrincipalIdentityStatement (::SL3PM::StatementLayer _the_layer, ::SL3PM::StatementType _the_type, const char* _encoding_type, const ::SL3PM::Encoding& _the_encoding, const char* _interpretation_aid, ::SL3PM::Principal* _the_principal);
    virtual ~PrincipalIdentityStatement();

  public:
    void the_principal( ::SL3PM::Principal* _p );
    ::SL3PM::Principal* the_principal() const;


  private:
    struct _M {
      ::SL3PM::Principal_var the_principal;
    } _m;
};


// OBV class for valuetype EndorsementStatement
class EndorsementStatement :
  virtual public SL3PM::EndorsementStatement,
  virtual public OBV_SL3PM::Statement
{
  protected:
    EndorsementStatement ();
    EndorsementStatement (::SL3PM::StatementLayer _the_layer, ::SL3PM::StatementType _the_type, const char* _encoding_type, const ::SL3PM::Encoding& _the_encoding, const char* _interpretation_aid);
    virtual ~EndorsementStatement();

  public:
    void interpretation_aid( char *_p );
    void interpretation_aid( const char *_p );
    void interpretation_aid( const CORBA::String_var &_p );
    const char *interpretation_aid() const;


  private:
    struct _M {
      CORBA::String_var interpretation_aid;
    } _m;
};


// OBV class for valuetype X509IdentityStatement
class X509IdentityStatement :
  virtual public SL3PM::X509IdentityStatement,
  virtual public OBV_SL3PM::PrincipalIdentityStatement
{
  protected:
    X509IdentityStatement ();
    X509IdentityStatement (::SL3PM::StatementLayer _the_layer, ::SL3PM::StatementType _the_type, const char* _encoding_type, const ::SL3PM::Encoding& _the_encoding, const char* _interpretation_aid, ::SL3PM::Principal* _the_principal);
    virtual ~X509IdentityStatement();


  private:
    struct _M {
    } _m;
};

}


void operator<<=( CORBA::Any &_a, const ::SL3PM::PrincipalName &_s );
void operator<<=( CORBA::Any &_a, ::SL3PM::PrincipalName *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::SL3PM::PrincipalName &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::SL3PM::PrincipalName *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_PrincipalName;

void operator<<=( CORBA::Any &_a, const ::SL3PM::PrinAttribute &_s );
void operator<<=( CORBA::Any &_a, ::SL3PM::PrinAttribute *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::SL3PM::PrinAttribute &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::SL3PM::PrinAttribute *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_PrinAttribute;

void operator<<=( CORBA::Any &_a, const ::SL3PM::ResourceName &_s );
void operator<<=( CORBA::Any &_a, ::SL3PM::ResourceName *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::SL3PM::ResourceName &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::SL3PM::ResourceName *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_ResourceName;

void operator<<=( CORBA::Any &_a, const ::SL3PM::ScopedPrivileges &_s );
void operator<<=( CORBA::Any &_a, ::SL3PM::ScopedPrivileges *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::SL3PM::ScopedPrivileges &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::SL3PM::ScopedPrivileges *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_ScopedPrivileges;

void operator<<=( CORBA::Any &a, const SL3PM::Principal* val );
void operator<<=( CORBA::Any &a, SL3PM::Principal** val_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, SL3PM::Principal* & val_ptr );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_Principal;

void operator<<=( CORBA::Any &a, const SL3PM::SimplePrincipal* val );
void operator<<=( CORBA::Any &a, SL3PM::SimplePrincipal** val_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, SL3PM::SimplePrincipal* & val_ptr );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_SimplePrincipal;

void operator<<=( CORBA::Any &a, const SL3PM::ProxyPrincipal* val );
void operator<<=( CORBA::Any &a, SL3PM::ProxyPrincipal** val_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, SL3PM::ProxyPrincipal* & val_ptr );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_ProxyPrincipal;

void operator<<=( CORBA::Any &a, const SL3PM::QuotingPrincipal* val );
void operator<<=( CORBA::Any &a, SL3PM::QuotingPrincipal** val_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, SL3PM::QuotingPrincipal* & val_ptr );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_QuotingPrincipal;

void operator<<=( CORBA::Any &a, const ::SL3PM::BadEncoding &e );
void operator<<=( CORBA::Any &a, ::SL3PM::BadEncoding *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::SL3PM::BadEncoding &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::SL3PM::BadEncoding *&e );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_BadEncoding;

void operator<<=( CORBA::Any &a, const ::SL3PM::BadEncodingType &e );
void operator<<=( CORBA::Any &a, ::SL3PM::BadEncodingType *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::SL3PM::BadEncodingType &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::SL3PM::BadEncodingType *&e );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_BadEncodingType;

void operator<<=( CORBA::Any &a, const SL3PM::Statement* val );
void operator<<=( CORBA::Any &a, SL3PM::Statement** val_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, SL3PM::Statement* & val_ptr );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_Statement;

void operator<<=( CORBA::Any &a, const SL3PM::IdentityStatement* val );
void operator<<=( CORBA::Any &a, SL3PM::IdentityStatement** val_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, SL3PM::IdentityStatement* & val_ptr );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_IdentityStatement;

void operator<<=( CORBA::Any &a, const SL3PM::PrincipalIdentityStatement* val );
void operator<<=( CORBA::Any &a, SL3PM::PrincipalIdentityStatement** val_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, SL3PM::PrincipalIdentityStatement* & val_ptr );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_PrincipalIdentityStatement;

void operator<<=( CORBA::Any &a, const SL3PM::EndorsementStatement* val );
void operator<<=( CORBA::Any &a, SL3PM::EndorsementStatement** val_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, SL3PM::EndorsementStatement* & val_ptr );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_EndorsementStatement;

void operator<<=( CORBA::Any &a, const SL3PM::X509IdentityStatement* val );
void operator<<=( CORBA::Any &a, SL3PM::X509IdentityStatement** val_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, SL3PM::X509IdentityStatement* & val_ptr );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_SL3PM_X509IdentityStatement;

void operator<<=( CORBA::Any &_a, const WStringSequenceTmpl<CORBA::WString_var> &_s );
void operator<<=( CORBA::Any &_a, WStringSequenceTmpl<CORBA::WString_var> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, WStringSequenceTmpl<CORBA::WString_var> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const WStringSequenceTmpl<CORBA::WString_var> *&_s );

void operator<<=( CORBA::Any &_a, const SequenceTmpl< SL3PM::PrincipalName,MICO_TID_DEF> &_s );
void operator<<=( CORBA::Any &_a, SequenceTmpl< SL3PM::PrincipalName,MICO_TID_DEF> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< SL3PM::PrincipalName,MICO_TID_DEF> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< SL3PM::PrincipalName,MICO_TID_DEF> *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller__seq_SL3PM_PrincipalName;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< SL3PM::PrinAttribute,MICO_TID_DEF> &_s );
void operator<<=( CORBA::Any &_a, SequenceTmpl< SL3PM::PrinAttribute,MICO_TID_DEF> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< SL3PM::PrinAttribute,MICO_TID_DEF> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< SL3PM::PrinAttribute,MICO_TID_DEF> *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller__seq_SL3PM_PrinAttribute;

void operator<<=( CORBA::Any &_a, const StringSequenceTmpl<CORBA::String_var> &_s );
void operator<<=( CORBA::Any &_a, StringSequenceTmpl<CORBA::String_var> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, StringSequenceTmpl<CORBA::String_var> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const StringSequenceTmpl<CORBA::String_var> *&_s );

void operator<<=( CORBA::Any &_a, const SequenceTmpl< SL3PM::ResourceName,MICO_TID_DEF> &_s );
void operator<<=( CORBA::Any &_a, SequenceTmpl< SL3PM::ResourceName,MICO_TID_DEF> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< SL3PM::ResourceName,MICO_TID_DEF> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< SL3PM::ResourceName,MICO_TID_DEF> *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller__seq_SL3PM_ResourceName;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< SL3PM::ScopedPrivileges,MICO_TID_DEF> &_s );
void operator<<=( CORBA::Any &_a, SequenceTmpl< SL3PM::ScopedPrivileges,MICO_TID_DEF> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< SL3PM::ScopedPrivileges,MICO_TID_DEF> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< SL3PM::ScopedPrivileges,MICO_TID_DEF> *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller__seq_SL3PM_ScopedPrivileges;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< SL3PM::Principal_var,MICO_TID_DEF> &_s );
void operator<<=( CORBA::Any &_a, SequenceTmpl< SL3PM::Principal_var,MICO_TID_DEF> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< SL3PM::Principal_var,MICO_TID_DEF> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< SL3PM::Principal_var,MICO_TID_DEF> *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller__seq_SL3PM_Principal;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< CORBA::Octet,MICO_TID_OCTET> &_s );
void operator<<=( CORBA::Any &_a, SequenceTmpl< CORBA::Octet,MICO_TID_OCTET> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< CORBA::Octet,MICO_TID_OCTET> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< CORBA::Octet,MICO_TID_OCTET> *&_s );

void operator<<=( CORBA::Any &_a, const SequenceTmpl< SL3PM::Statement_var,MICO_TID_DEF> &_s );
void operator<<=( CORBA::Any &_a, SequenceTmpl< SL3PM::Statement_var,MICO_TID_DEF> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< SL3PM::Statement_var,MICO_TID_DEF> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< SL3PM::Statement_var,MICO_TID_DEF> *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller__seq_SL3PM_Statement;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< SL3PM::X509IdentityStatement_var,MICO_TID_DEF> &_s );
void operator<<=( CORBA::Any &_a, SequenceTmpl< SL3PM::X509IdentityStatement_var,MICO_TID_DEF> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< SL3PM::X509IdentityStatement_var,MICO_TID_DEF> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< SL3PM::X509IdentityStatement_var,MICO_TID_DEF> *&_s );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller__seq_SL3PM_X509IdentityStatement;

#endif
