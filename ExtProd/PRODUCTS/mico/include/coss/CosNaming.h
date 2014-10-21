/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>
#include <mico/throw.h>

#ifndef __COSNAMING_H__
#define __COSNAMING_H__






namespace CosNaming
{

class BindingIterator;
typedef BindingIterator *BindingIterator_ptr;
typedef BindingIterator_ptr BindingIteratorRef;
typedef ObjVar< BindingIterator > BindingIterator_var;
typedef ObjOut< BindingIterator > BindingIterator_out;

class NamingContext;
typedef NamingContext *NamingContext_ptr;
typedef NamingContext_ptr NamingContextRef;
typedef ObjVar< NamingContext > NamingContext_var;
typedef ObjOut< NamingContext > NamingContext_out;

class NamingContextExt;
typedef NamingContextExt *NamingContextExt_ptr;
typedef NamingContextExt_ptr NamingContextExtRef;
typedef ObjVar< NamingContextExt > NamingContextExt_var;
typedef ObjOut< NamingContextExt > NamingContextExt_out;

}






namespace CosNaming
{

typedef char* Istring;
typedef CORBA::String_var Istring_var;
typedef CORBA::String_out Istring_out;

struct NameComponent;
typedef TVarVar< NameComponent > NameComponent_var;
typedef TVarOut< NameComponent > NameComponent_out;


struct NameComponent {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef NameComponent_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  NameComponent();
  ~NameComponent();
  NameComponent( const NameComponent& s );
  NameComponent& operator=( const NameComponent& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  Istring_var id;
  Istring_var kind;
};

typedef SequenceTmpl< NameComponent,MICO_TID_DEF> Name;
typedef TSeqVar< SequenceTmpl< NameComponent,MICO_TID_DEF> > Name_var;
typedef TSeqOut< SequenceTmpl< NameComponent,MICO_TID_DEF> > Name_out;

enum BindingType {
  nobject = 0,
  ncontext
};

typedef BindingType& BindingType_out;

struct Binding;
typedef TVarVar< Binding > Binding_var;
typedef TVarOut< Binding > Binding_out;


struct Binding {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef Binding_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  Binding();
  ~Binding();
  Binding( const Binding& s );
  Binding& operator=( const Binding& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  Name binding_name;
  BindingType binding_type;
};

typedef SequenceTmpl< Binding,MICO_TID_DEF> BindingList;
typedef TSeqVar< SequenceTmpl< Binding,MICO_TID_DEF> > BindingList_var;
typedef TSeqOut< SequenceTmpl< Binding,MICO_TID_DEF> > BindingList_out;


/*
 * Base class and common definitions for interface BindingIterator
 */

class BindingIterator : 
  virtual public CORBA::Object
{
  public:
    virtual ~BindingIterator();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef BindingIterator_ptr _ptr_type;
    typedef BindingIterator_var _var_type;
    #endif

    static BindingIterator_ptr _narrow( CORBA::Object_ptr obj );
    static BindingIterator_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static BindingIterator_ptr _duplicate( BindingIterator_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static BindingIterator_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual CORBA::Boolean next_one( ::CosNaming::Binding_out b ) = 0;
    virtual CORBA::Boolean next_n( CORBA::ULong how_many, ::CosNaming::BindingList_out bl ) = 0;
    virtual void destroy() = 0;

  protected:
    BindingIterator() {};
  private:
    BindingIterator( const BindingIterator& );
    void operator=( const BindingIterator& );
};

// Stub for interface BindingIterator
class BindingIterator_stub:
  virtual public BindingIterator
{
  public:
    virtual ~BindingIterator_stub();
    CORBA::Boolean next_one( ::CosNaming::Binding_out b );
    CORBA::Boolean next_n( CORBA::ULong how_many, ::CosNaming::BindingList_out bl );
    void destroy();

  private:
    void operator=( const BindingIterator_stub& );
};

#ifndef MICO_CONF_NO_POA

class BindingIterator_stub_clp :
  virtual public BindingIterator_stub,
  virtual public PortableServer::StubBase
{
  public:
    BindingIterator_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~BindingIterator_stub_clp ();
    CORBA::Boolean next_one( ::CosNaming::Binding_out b );
    CORBA::Boolean next_n( CORBA::ULong how_many, ::CosNaming::BindingList_out bl );
    void destroy();

  protected:
    BindingIterator_stub_clp ();
  private:
    void operator=( const BindingIterator_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface NamingContext
 */

class NamingContext : 
  virtual public CORBA::Object
{
  public:
    virtual ~NamingContext();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef NamingContext_ptr _ptr_type;
    typedef NamingContext_var _var_type;
    #endif

    static NamingContext_ptr _narrow( CORBA::Object_ptr obj );
    static NamingContext_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static NamingContext_ptr _duplicate( NamingContext_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static NamingContext_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    enum NotFoundReason {
      missing_node = 0,
      not_context,
      not_object
    };

    typedef NotFoundReason& NotFoundReason_out;

    struct NotFound : public CORBA::UserException {
      #ifdef HAVE_EXPLICIT_STRUCT_OPS
      NotFound();
      ~NotFound();
      NotFound( const NotFound& s );
      NotFound& operator=( const NotFound& s );
      #endif //HAVE_EXPLICIT_STRUCT_OPS

      #ifndef HAVE_EXPLICIT_STRUCT_OPS
      NotFound();
      #endif //HAVE_EXPLICIT_STRUCT_OPS
      NotFound( ::CosNaming::NamingContext::NotFoundReason _m0, const ::CosNaming::Name& _m1 );

      #ifdef HAVE_STD_EH
      NotFound *operator->() { return this; }
      NotFound& operator*() { return *this; }
      operator NotFound*() { return this; }
      #endif // HAVE_STD_EH

      void _throwit() const;
      const char *_repoid() const;
      void _encode( CORBA::DataEncoder &en ) const;
      void _encode_any( CORBA::Any &a ) const;
      CORBA::Exception *_clone() const;
      static NotFound *_downcast( CORBA::Exception *ex );
      static const NotFound *_downcast( const CORBA::Exception *ex );
      NotFoundReason why;
      Name rest_of_name;
    };

    #ifdef HAVE_STD_EH
    typedef NotFound NotFound_catch;
    #else
    typedef ExceptVar< NotFound > NotFound_var;
    typedef TVarOut< NotFound > NotFound_out;
    typedef NotFound_var NotFound_catch;
    #endif // HAVE_STD_EH

    struct CannotProceed : public CORBA::UserException {
      #ifdef HAVE_EXPLICIT_STRUCT_OPS
      CannotProceed();
      ~CannotProceed();
      CannotProceed( const CannotProceed& s );
      CannotProceed& operator=( const CannotProceed& s );
      #endif //HAVE_EXPLICIT_STRUCT_OPS

      #ifndef HAVE_EXPLICIT_STRUCT_OPS
      CannotProceed();
      #endif //HAVE_EXPLICIT_STRUCT_OPS
      CannotProceed( ::CosNaming::NamingContext_ptr _m0, const ::CosNaming::Name& _m1 );

      #ifdef HAVE_STD_EH
      CannotProceed *operator->() { return this; }
      CannotProceed& operator*() { return *this; }
      operator CannotProceed*() { return this; }
      #endif // HAVE_STD_EH

      void _throwit() const;
      const char *_repoid() const;
      void _encode( CORBA::DataEncoder &en ) const;
      void _encode_any( CORBA::Any &a ) const;
      CORBA::Exception *_clone() const;
      static CannotProceed *_downcast( CORBA::Exception *ex );
      static const CannotProceed *_downcast( const CORBA::Exception *ex );
      NamingContext_var cxt;
      Name rest_of_name;
    };

    #ifdef HAVE_STD_EH
    typedef CannotProceed CannotProceed_catch;
    #else
    typedef ExceptVar< CannotProceed > CannotProceed_var;
    typedef TVarOut< CannotProceed > CannotProceed_out;
    typedef CannotProceed_var CannotProceed_catch;
    #endif // HAVE_STD_EH

    struct InvalidName : public CORBA::UserException {
      #ifdef HAVE_EXPLICIT_STRUCT_OPS
      InvalidName();
      ~InvalidName();
      InvalidName( const InvalidName& s );
      InvalidName& operator=( const InvalidName& s );
      #endif //HAVE_EXPLICIT_STRUCT_OPS


      #ifdef HAVE_STD_EH
      InvalidName *operator->() { return this; }
      InvalidName& operator*() { return *this; }
      operator InvalidName*() { return this; }
      #endif // HAVE_STD_EH

      void _throwit() const;
      const char *_repoid() const;
      void _encode( CORBA::DataEncoder &en ) const;
      void _encode_any( CORBA::Any &a ) const;
      CORBA::Exception *_clone() const;
      static InvalidName *_downcast( CORBA::Exception *ex );
      static const InvalidName *_downcast( const CORBA::Exception *ex );
    };

    #ifdef HAVE_STD_EH
    typedef InvalidName InvalidName_catch;
    #else
    typedef ExceptVar< InvalidName > InvalidName_var;
    typedef TVarOut< InvalidName > InvalidName_out;
    typedef InvalidName_var InvalidName_catch;
    #endif // HAVE_STD_EH

    struct AlreadyBound : public CORBA::UserException {
      #ifdef HAVE_EXPLICIT_STRUCT_OPS
      AlreadyBound();
      ~AlreadyBound();
      AlreadyBound( const AlreadyBound& s );
      AlreadyBound& operator=( const AlreadyBound& s );
      #endif //HAVE_EXPLICIT_STRUCT_OPS


      #ifdef HAVE_STD_EH
      AlreadyBound *operator->() { return this; }
      AlreadyBound& operator*() { return *this; }
      operator AlreadyBound*() { return this; }
      #endif // HAVE_STD_EH

      void _throwit() const;
      const char *_repoid() const;
      void _encode( CORBA::DataEncoder &en ) const;
      void _encode_any( CORBA::Any &a ) const;
      CORBA::Exception *_clone() const;
      static AlreadyBound *_downcast( CORBA::Exception *ex );
      static const AlreadyBound *_downcast( const CORBA::Exception *ex );
    };

    #ifdef HAVE_STD_EH
    typedef AlreadyBound AlreadyBound_catch;
    #else
    typedef ExceptVar< AlreadyBound > AlreadyBound_var;
    typedef TVarOut< AlreadyBound > AlreadyBound_out;
    typedef AlreadyBound_var AlreadyBound_catch;
    #endif // HAVE_STD_EH

    struct NotEmpty : public CORBA::UserException {
      #ifdef HAVE_EXPLICIT_STRUCT_OPS
      NotEmpty();
      ~NotEmpty();
      NotEmpty( const NotEmpty& s );
      NotEmpty& operator=( const NotEmpty& s );
      #endif //HAVE_EXPLICIT_STRUCT_OPS


      #ifdef HAVE_STD_EH
      NotEmpty *operator->() { return this; }
      NotEmpty& operator*() { return *this; }
      operator NotEmpty*() { return this; }
      #endif // HAVE_STD_EH

      void _throwit() const;
      const char *_repoid() const;
      void _encode( CORBA::DataEncoder &en ) const;
      void _encode_any( CORBA::Any &a ) const;
      CORBA::Exception *_clone() const;
      static NotEmpty *_downcast( CORBA::Exception *ex );
      static const NotEmpty *_downcast( const CORBA::Exception *ex );
    };

    #ifdef HAVE_STD_EH
    typedef NotEmpty NotEmpty_catch;
    #else
    typedef ExceptVar< NotEmpty > NotEmpty_var;
    typedef TVarOut< NotEmpty > NotEmpty_out;
    typedef NotEmpty_var NotEmpty_catch;
    #endif // HAVE_STD_EH

    virtual void bind( const ::CosNaming::Name& n, CORBA::Object_ptr obj ) = 0;
    virtual void rebind( const ::CosNaming::Name& n, CORBA::Object_ptr obj ) = 0;
    virtual void bind_context( const ::CosNaming::Name& n, ::CosNaming::NamingContext_ptr nc ) = 0;
    virtual void rebind_context( const ::CosNaming::Name& n, ::CosNaming::NamingContext_ptr nc ) = 0;
    virtual CORBA::Object_ptr resolve( const ::CosNaming::Name& n ) = 0;
    virtual void unbind( const ::CosNaming::Name& n ) = 0;
    virtual ::CosNaming::NamingContext_ptr new_context() = 0;
    virtual ::CosNaming::NamingContext_ptr bind_new_context( const ::CosNaming::Name& n ) = 0;
    virtual void destroy() = 0;
    virtual void list( CORBA::ULong how_many, ::CosNaming::BindingList_out bl, ::CosNaming::BindingIterator_out bi ) = 0;

  protected:
    NamingContext() {};
  private:
    NamingContext( const NamingContext& );
    void operator=( const NamingContext& );
};

// Stub for interface NamingContext
class NamingContext_stub:
  virtual public NamingContext
{
  public:
    virtual ~NamingContext_stub();
    void bind( const ::CosNaming::Name& n, CORBA::Object_ptr obj );
    void rebind( const ::CosNaming::Name& n, CORBA::Object_ptr obj );
    void bind_context( const ::CosNaming::Name& n, ::CosNaming::NamingContext_ptr nc );
    void rebind_context( const ::CosNaming::Name& n, ::CosNaming::NamingContext_ptr nc );
    CORBA::Object_ptr resolve( const ::CosNaming::Name& n );
    void unbind( const ::CosNaming::Name& n );
    ::CosNaming::NamingContext_ptr new_context();
    ::CosNaming::NamingContext_ptr bind_new_context( const ::CosNaming::Name& n );
    void destroy();
    void list( CORBA::ULong how_many, ::CosNaming::BindingList_out bl, ::CosNaming::BindingIterator_out bi );

  private:
    void operator=( const NamingContext_stub& );
};

#ifndef MICO_CONF_NO_POA

class NamingContext_stub_clp :
  virtual public NamingContext_stub,
  virtual public PortableServer::StubBase
{
  public:
    NamingContext_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~NamingContext_stub_clp ();
    void bind( const ::CosNaming::Name& n, CORBA::Object_ptr obj );
    void rebind( const ::CosNaming::Name& n, CORBA::Object_ptr obj );
    void bind_context( const ::CosNaming::Name& n, ::CosNaming::NamingContext_ptr nc );
    void rebind_context( const ::CosNaming::Name& n, ::CosNaming::NamingContext_ptr nc );
    CORBA::Object_ptr resolve( const ::CosNaming::Name& n );
    void unbind( const ::CosNaming::Name& n );
    ::CosNaming::NamingContext_ptr new_context();
    ::CosNaming::NamingContext_ptr bind_new_context( const ::CosNaming::Name& n );
    void destroy();
    void list( CORBA::ULong how_many, ::CosNaming::BindingList_out bl, ::CosNaming::BindingIterator_out bi );

  protected:
    NamingContext_stub_clp ();
  private:
    void operator=( const NamingContext_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface NamingContextExt
 */

class NamingContextExt : 
  virtual public ::CosNaming::NamingContext
{
  public:
    virtual ~NamingContextExt();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef NamingContextExt_ptr _ptr_type;
    typedef NamingContextExt_var _var_type;
    #endif

    static NamingContextExt_ptr _narrow( CORBA::Object_ptr obj );
    static NamingContextExt_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static NamingContextExt_ptr _duplicate( NamingContextExt_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static NamingContextExt_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    typedef char* StringName;
    typedef CORBA::String_var StringName_var;
    typedef CORBA::String_out StringName_out;

    typedef char* Address;
    typedef CORBA::String_var Address_var;
    typedef CORBA::String_out Address_out;

    typedef char* URLString;
    typedef CORBA::String_var URLString_var;
    typedef CORBA::String_out URLString_out;

    struct InvalidAddress : public CORBA::UserException {
      #ifdef HAVE_EXPLICIT_STRUCT_OPS
      InvalidAddress();
      ~InvalidAddress();
      InvalidAddress( const InvalidAddress& s );
      InvalidAddress& operator=( const InvalidAddress& s );
      #endif //HAVE_EXPLICIT_STRUCT_OPS


      #ifdef HAVE_STD_EH
      InvalidAddress *operator->() { return this; }
      InvalidAddress& operator*() { return *this; }
      operator InvalidAddress*() { return this; }
      #endif // HAVE_STD_EH

      void _throwit() const;
      const char *_repoid() const;
      void _encode( CORBA::DataEncoder &en ) const;
      void _encode_any( CORBA::Any &a ) const;
      CORBA::Exception *_clone() const;
      static InvalidAddress *_downcast( CORBA::Exception *ex );
      static const InvalidAddress *_downcast( const CORBA::Exception *ex );
    };

    #ifdef HAVE_STD_EH
    typedef InvalidAddress InvalidAddress_catch;
    #else
    typedef ExceptVar< InvalidAddress > InvalidAddress_var;
    typedef TVarOut< InvalidAddress > InvalidAddress_out;
    typedef InvalidAddress_var InvalidAddress_catch;
    #endif // HAVE_STD_EH

    virtual char* to_string( const ::CosNaming::Name& n ) = 0;
    virtual ::CosNaming::Name* to_name( const char* sn ) = 0;
    virtual char* to_url( const char* addr, const char* sn ) = 0;
    virtual CORBA::Object_ptr resolve_str( const char* n ) = 0;

  protected:
    NamingContextExt() {};
  private:
    NamingContextExt( const NamingContextExt& );
    void operator=( const NamingContextExt& );
};

// Stub for interface NamingContextExt
class NamingContextExt_stub:
  virtual public NamingContextExt,
  virtual public ::CosNaming::NamingContext_stub
{
  public:
    virtual ~NamingContextExt_stub();
    char* to_string( const ::CosNaming::Name& n );
    ::CosNaming::Name* to_name( const char* sn );
    char* to_url( const char* addr, const char* sn );
    CORBA::Object_ptr resolve_str( const char* n );

  private:
    void operator=( const NamingContextExt_stub& );
};

#ifndef MICO_CONF_NO_POA

class NamingContextExt_stub_clp :
  virtual public NamingContextExt_stub,
  virtual public ::CosNaming::NamingContext_stub_clp
{
  public:
    NamingContextExt_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~NamingContextExt_stub_clp ();
    char* to_string( const ::CosNaming::Name& n );
    ::CosNaming::Name* to_name( const char* sn );
    char* to_url( const char* addr, const char* sn );
    CORBA::Object_ptr resolve_str( const char* n );

  protected:
    NamingContextExt_stub_clp ();
  private:
    void operator=( const NamingContextExt_stub_clp & );
};

#endif // MICO_CONF_NO_POA

}


#ifndef MICO_CONF_NO_POA



namespace POA_CosNaming
{

class BindingIterator : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~BindingIterator ();
    CosNaming::BindingIterator_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static BindingIterator * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual CORBA::Boolean next_one( ::CosNaming::Binding_out b ) = 0;
    virtual CORBA::Boolean next_n( CORBA::ULong how_many, ::CosNaming::BindingList_out bl ) = 0;
    virtual void destroy() = 0;

  protected:
    BindingIterator () {};

  private:
    BindingIterator (const BindingIterator &);
    void operator= (const BindingIterator &);
};

class NamingContext : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~NamingContext ();
    CosNaming::NamingContext_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static NamingContext * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual void bind( const ::CosNaming::Name& n, CORBA::Object_ptr obj ) = 0;
    virtual void rebind( const ::CosNaming::Name& n, CORBA::Object_ptr obj ) = 0;
    virtual void bind_context( const ::CosNaming::Name& n, ::CosNaming::NamingContext_ptr nc ) = 0;
    virtual void rebind_context( const ::CosNaming::Name& n, ::CosNaming::NamingContext_ptr nc ) = 0;
    virtual CORBA::Object_ptr resolve( const ::CosNaming::Name& n ) = 0;
    virtual void unbind( const ::CosNaming::Name& n ) = 0;
    virtual ::CosNaming::NamingContext_ptr new_context() = 0;
    virtual ::CosNaming::NamingContext_ptr bind_new_context( const ::CosNaming::Name& n ) = 0;
    virtual void destroy() = 0;
    virtual void list( CORBA::ULong how_many, ::CosNaming::BindingList_out bl, ::CosNaming::BindingIterator_out bi ) = 0;

  protected:
    NamingContext () {};

  private:
    NamingContext (const NamingContext &);
    void operator= (const NamingContext &);
};

class NamingContextExt : 
  virtual public POA_CosNaming::NamingContext
{
  public:
    virtual ~NamingContextExt ();
    CosNaming::NamingContextExt_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static NamingContextExt * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual char* to_string( const ::CosNaming::Name& n ) = 0;
    virtual ::CosNaming::Name* to_name( const char* sn ) = 0;
    virtual char* to_url( const char* addr, const char* sn ) = 0;
    virtual CORBA::Object_ptr resolve_str( const char* n ) = 0;

  protected:
    NamingContextExt () {};

  private:
    NamingContextExt (const NamingContextExt &);
    void operator= (const NamingContextExt &);
};

}


#endif // MICO_CONF_NO_POA

extern CORBA::StaticTypeInfo *_marshaller_CosNaming_NameComponent;

extern CORBA::StaticTypeInfo *_marshaller_CosNaming_BindingType;

extern CORBA::StaticTypeInfo *_marshaller_CosNaming_Binding;

extern CORBA::StaticTypeInfo *_marshaller_CosNaming_BindingIterator;

extern CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContext_NotFoundReason;

extern CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContext_NotFound;

extern CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContext_CannotProceed;

extern CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContext_InvalidName;

extern CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContext_AlreadyBound;

extern CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContext_NotEmpty;

extern CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContext;

extern CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContextExt_InvalidAddress;

extern CORBA::StaticTypeInfo *_marshaller_CosNaming_NamingContextExt;

extern CORBA::StaticTypeInfo *_marshaller__seq_CosNaming_NameComponent;

extern CORBA::StaticTypeInfo *_marshaller__seq_CosNaming_Binding;

#endif
