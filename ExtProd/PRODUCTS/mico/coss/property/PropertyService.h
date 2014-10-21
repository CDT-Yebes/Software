/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>
#include <mico/throw.h>

#ifndef __PROPERTYSERVICE_H__
#define __PROPERTYSERVICE_H__






namespace PropertyService
{

class PropertyNamesIterator;
typedef PropertyNamesIterator *PropertyNamesIterator_ptr;
typedef PropertyNamesIterator_ptr PropertyNamesIteratorRef;
typedef ObjVar< PropertyNamesIterator > PropertyNamesIterator_var;
typedef ObjOut< PropertyNamesIterator > PropertyNamesIterator_out;

class PropertiesIterator;
typedef PropertiesIterator *PropertiesIterator_ptr;
typedef PropertiesIterator_ptr PropertiesIteratorRef;
typedef ObjVar< PropertiesIterator > PropertiesIterator_var;
typedef ObjOut< PropertiesIterator > PropertiesIterator_out;

class PropertySet;
typedef PropertySet *PropertySet_ptr;
typedef PropertySet_ptr PropertySetRef;
typedef ObjVar< PropertySet > PropertySet_var;
typedef ObjOut< PropertySet > PropertySet_out;

class PropertySetFactory;
typedef PropertySetFactory *PropertySetFactory_ptr;
typedef PropertySetFactory_ptr PropertySetFactoryRef;
typedef ObjVar< PropertySetFactory > PropertySetFactory_var;
typedef ObjOut< PropertySetFactory > PropertySetFactory_out;

class PropertySetDef;
typedef PropertySetDef *PropertySetDef_ptr;
typedef PropertySetDef_ptr PropertySetDefRef;
typedef ObjVar< PropertySetDef > PropertySetDef_var;
typedef ObjOut< PropertySetDef > PropertySetDef_out;

class PropertySetDefFactory;
typedef PropertySetDefFactory *PropertySetDefFactory_ptr;
typedef PropertySetDefFactory_ptr PropertySetDefFactoryRef;
typedef ObjVar< PropertySetDefFactory > PropertySetDefFactory_var;
typedef ObjOut< PropertySetDefFactory > PropertySetDefFactory_out;

}



#include <mico/typecode_seq.h>



namespace PropertyService
{

typedef char* PropertyName;
typedef CORBA::String_var PropertyName_var;
typedef CORBA::String_out PropertyName_out;

extern CORBA::TypeCodeConst _tc_PropertyName;

struct Property;
typedef TVarVar< Property > Property_var;
typedef TVarOut< Property > Property_out;


struct Property {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef Property_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  Property();
  ~Property();
  Property( const Property& s );
  Property& operator=( const Property& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  PropertyName_var property_name;
  CORBA::Any property_value;
};

extern CORBA::TypeCodeConst _tc_Property;

enum PropertyModeType {
  normal = 0,
  read_only,
  fixed_normal,
  fixed_readonly,
  undefined
};

typedef PropertyModeType& PropertyModeType_out;

extern CORBA::TypeCodeConst _tc_PropertyModeType;

struct PropertyDef;
typedef TVarVar< PropertyDef > PropertyDef_var;
typedef TVarOut< PropertyDef > PropertyDef_out;


struct PropertyDef {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef PropertyDef_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  PropertyDef();
  ~PropertyDef();
  PropertyDef( const PropertyDef& s );
  PropertyDef& operator=( const PropertyDef& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  PropertyName_var property_name;
  CORBA::Any property_value;
  PropertyModeType property_mode;
};

extern CORBA::TypeCodeConst _tc_PropertyDef;

struct PropertyMode;
typedef TVarVar< PropertyMode > PropertyMode_var;
typedef TVarOut< PropertyMode > PropertyMode_out;


struct PropertyMode {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef PropertyMode_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  PropertyMode();
  ~PropertyMode();
  PropertyMode( const PropertyMode& s );
  PropertyMode& operator=( const PropertyMode& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  PropertyName_var property_name;
  PropertyModeType property_mode;
};

extern CORBA::TypeCodeConst _tc_PropertyMode;

typedef StringSequenceTmpl<CORBA::String_var> PropertyNames;
typedef TSeqVar< StringSequenceTmpl<CORBA::String_var> > PropertyNames_var;
typedef TSeqOut< StringSequenceTmpl<CORBA::String_var> > PropertyNames_out;

extern CORBA::TypeCodeConst _tc_PropertyNames;

typedef SequenceTmpl< Property,MICO_TID_DEF> Properties;
typedef TSeqVar< SequenceTmpl< Property,MICO_TID_DEF> > Properties_var;
typedef TSeqOut< SequenceTmpl< Property,MICO_TID_DEF> > Properties_out;

extern CORBA::TypeCodeConst _tc_Properties;

typedef SequenceTmpl< PropertyDef,MICO_TID_DEF> PropertyDefs;
typedef TSeqVar< SequenceTmpl< PropertyDef,MICO_TID_DEF> > PropertyDefs_var;
typedef TSeqOut< SequenceTmpl< PropertyDef,MICO_TID_DEF> > PropertyDefs_out;

extern CORBA::TypeCodeConst _tc_PropertyDefs;

typedef SequenceTmpl< PropertyMode,MICO_TID_DEF> PropertyModes;
typedef TSeqVar< SequenceTmpl< PropertyMode,MICO_TID_DEF> > PropertyModes_var;
typedef TSeqOut< SequenceTmpl< PropertyMode,MICO_TID_DEF> > PropertyModes_out;

extern CORBA::TypeCodeConst _tc_PropertyModes;

typedef ::CORBA::TypeCodeSeq PropertyTypes;
typedef TSeqVar< ::CORBA::TypeCodeSeq > PropertyTypes_var;
typedef TSeqOut< ::CORBA::TypeCodeSeq > PropertyTypes_out;

extern CORBA::TypeCodeConst _tc_PropertyTypes;


/*
 * Base class and common definitions for interface PropertyNamesIterator
 */

class PropertyNamesIterator : 
  virtual public CORBA::Object
{
  public:
    virtual ~PropertyNamesIterator();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef PropertyNamesIterator_ptr _ptr_type;
    typedef PropertyNamesIterator_var _var_type;
    #endif

    static PropertyNamesIterator_ptr _narrow( CORBA::Object_ptr obj );
    static PropertyNamesIterator_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static PropertyNamesIterator_ptr _duplicate( PropertyNamesIterator_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static PropertyNamesIterator_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void reset() = 0;
    virtual CORBA::Boolean next_one( CORBA::String_out propery_name ) = 0;
    virtual CORBA::Boolean next_n( CORBA::ULong how_many, ::PropertyService::PropertyNames_out property_names ) = 0;
    virtual void destroy() = 0;

  protected:
    PropertyNamesIterator() {};
  private:
    PropertyNamesIterator( const PropertyNamesIterator& );
    void operator=( const PropertyNamesIterator& );
};

extern CORBA::TypeCodeConst _tc_PropertyNamesIterator;

// Stub for interface PropertyNamesIterator
class PropertyNamesIterator_stub:
  virtual public PropertyNamesIterator
{
  public:
    virtual ~PropertyNamesIterator_stub();
    void reset();
    CORBA::Boolean next_one( CORBA::String_out propery_name );
    CORBA::Boolean next_n( CORBA::ULong how_many, ::PropertyService::PropertyNames_out property_names );
    void destroy();

  private:
    void operator=( const PropertyNamesIterator_stub& );
};

#ifndef MICO_CONF_NO_POA

class PropertyNamesIterator_stub_clp :
  virtual public PropertyNamesIterator_stub,
  virtual public PortableServer::StubBase
{
  public:
    PropertyNamesIterator_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~PropertyNamesIterator_stub_clp ();
    void reset();
    CORBA::Boolean next_one( CORBA::String_out propery_name );
    CORBA::Boolean next_n( CORBA::ULong how_many, ::PropertyService::PropertyNames_out property_names );
    void destroy();

  protected:
    PropertyNamesIterator_stub_clp ();
  private:
    void operator=( const PropertyNamesIterator_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface PropertiesIterator
 */

class PropertiesIterator : 
  virtual public CORBA::Object
{
  public:
    virtual ~PropertiesIterator();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef PropertiesIterator_ptr _ptr_type;
    typedef PropertiesIterator_var _var_type;
    #endif

    static PropertiesIterator_ptr _narrow( CORBA::Object_ptr obj );
    static PropertiesIterator_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static PropertiesIterator_ptr _duplicate( PropertiesIterator_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static PropertiesIterator_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void reset() = 0;
    virtual CORBA::Boolean next_one( ::PropertyService::Property_out aproperty ) = 0;
    virtual CORBA::Boolean next_n( CORBA::ULong how_many, ::PropertyService::Properties_out nproperties ) = 0;
    virtual void destroy() = 0;

  protected:
    PropertiesIterator() {};
  private:
    PropertiesIterator( const PropertiesIterator& );
    void operator=( const PropertiesIterator& );
};

extern CORBA::TypeCodeConst _tc_PropertiesIterator;

// Stub for interface PropertiesIterator
class PropertiesIterator_stub:
  virtual public PropertiesIterator
{
  public:
    virtual ~PropertiesIterator_stub();
    void reset();
    CORBA::Boolean next_one( ::PropertyService::Property_out aproperty );
    CORBA::Boolean next_n( CORBA::ULong how_many, ::PropertyService::Properties_out nproperties );
    void destroy();

  private:
    void operator=( const PropertiesIterator_stub& );
};

#ifndef MICO_CONF_NO_POA

class PropertiesIterator_stub_clp :
  virtual public PropertiesIterator_stub,
  virtual public PortableServer::StubBase
{
  public:
    PropertiesIterator_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~PropertiesIterator_stub_clp ();
    void reset();
    CORBA::Boolean next_one( ::PropertyService::Property_out aproperty );
    CORBA::Boolean next_n( CORBA::ULong how_many, ::PropertyService::Properties_out nproperties );
    void destroy();

  protected:
    PropertiesIterator_stub_clp ();
  private:
    void operator=( const PropertiesIterator_stub_clp & );
};

#endif // MICO_CONF_NO_POA

struct ConstraintNotSupported : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  ConstraintNotSupported();
  ~ConstraintNotSupported();
  ConstraintNotSupported( const ConstraintNotSupported& s );
  ConstraintNotSupported& operator=( const ConstraintNotSupported& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  ConstraintNotSupported *operator->() { return this; }
  ConstraintNotSupported& operator*() { return *this; }
  operator ConstraintNotSupported*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static ConstraintNotSupported *_downcast( CORBA::Exception *ex );
  static const ConstraintNotSupported *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef ConstraintNotSupported ConstraintNotSupported_catch;
#else
typedef ExceptVar< ConstraintNotSupported > ConstraintNotSupported_var;
typedef TVarOut< ConstraintNotSupported > ConstraintNotSupported_out;
typedef ConstraintNotSupported_var ConstraintNotSupported_catch;
#endif // HAVE_STD_EH

extern CORBA::TypeCodeConst _tc_ConstraintNotSupported;

struct PropertyException;
typedef TVarVar< PropertyException > PropertyException_var;
typedef TVarOut< PropertyException > PropertyException_out;


typedef SequenceTmpl< PropertyException,MICO_TID_DEF> PropertyExceptions;
typedef TSeqVar< SequenceTmpl< PropertyException,MICO_TID_DEF> > PropertyExceptions_var;
typedef TSeqOut< SequenceTmpl< PropertyException,MICO_TID_DEF> > PropertyExceptions_out;

extern CORBA::TypeCodeConst _tc_PropertyExceptions;

struct MultipleExceptions : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  MultipleExceptions();
  ~MultipleExceptions();
  MultipleExceptions( const MultipleExceptions& s );
  MultipleExceptions& operator=( const MultipleExceptions& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  #ifndef HAVE_EXPLICIT_STRUCT_OPS
  MultipleExceptions();
  #endif //HAVE_EXPLICIT_STRUCT_OPS
  MultipleExceptions( const ::PropertyService::PropertyExceptions& _m0 );

  #ifdef HAVE_STD_EH
  MultipleExceptions *operator->() { return this; }
  MultipleExceptions& operator*() { return *this; }
  operator MultipleExceptions*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static MultipleExceptions *_downcast( CORBA::Exception *ex );
  static const MultipleExceptions *_downcast( const CORBA::Exception *ex );
  PropertyExceptions exceptions;
};

#ifdef HAVE_STD_EH
typedef MultipleExceptions MultipleExceptions_catch;
#else
typedef ExceptVar< MultipleExceptions > MultipleExceptions_var;
typedef TVarOut< MultipleExceptions > MultipleExceptions_out;
typedef MultipleExceptions_var MultipleExceptions_catch;
#endif // HAVE_STD_EH

extern CORBA::TypeCodeConst _tc_MultipleExceptions;


/*
 * Base class and common definitions for interface PropertySetFactory
 */

class PropertySetFactory : 
  virtual public CORBA::Object
{
  public:
    virtual ~PropertySetFactory();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef PropertySetFactory_ptr _ptr_type;
    typedef PropertySetFactory_var _var_type;
    #endif

    static PropertySetFactory_ptr _narrow( CORBA::Object_ptr obj );
    static PropertySetFactory_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static PropertySetFactory_ptr _duplicate( PropertySetFactory_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static PropertySetFactory_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::PropertyService::PropertySet_ptr create_propertyset() = 0;
    virtual ::PropertyService::PropertySet_ptr create_constrained_propertyset( const ::PropertyService::PropertyTypes& allowed_property_types, const ::PropertyService::Properties& allowed_properties ) = 0;
    virtual ::PropertyService::PropertySet_ptr create_initial_propertyset( const ::PropertyService::Properties& initial_properties ) = 0;

  protected:
    PropertySetFactory() {};
  private:
    PropertySetFactory( const PropertySetFactory& );
    void operator=( const PropertySetFactory& );
};

extern CORBA::TypeCodeConst _tc_PropertySetFactory;

// Stub for interface PropertySetFactory
class PropertySetFactory_stub:
  virtual public PropertySetFactory
{
  public:
    virtual ~PropertySetFactory_stub();
    ::PropertyService::PropertySet_ptr create_propertyset();
    ::PropertyService::PropertySet_ptr create_constrained_propertyset( const ::PropertyService::PropertyTypes& allowed_property_types, const ::PropertyService::Properties& allowed_properties );
    ::PropertyService::PropertySet_ptr create_initial_propertyset( const ::PropertyService::Properties& initial_properties );

  private:
    void operator=( const PropertySetFactory_stub& );
};

#ifndef MICO_CONF_NO_POA

class PropertySetFactory_stub_clp :
  virtual public PropertySetFactory_stub,
  virtual public PortableServer::StubBase
{
  public:
    PropertySetFactory_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~PropertySetFactory_stub_clp ();
    ::PropertyService::PropertySet_ptr create_propertyset();
    ::PropertyService::PropertySet_ptr create_constrained_propertyset( const ::PropertyService::PropertyTypes& allowed_property_types, const ::PropertyService::Properties& allowed_properties );
    ::PropertyService::PropertySet_ptr create_initial_propertyset( const ::PropertyService::Properties& initial_properties );

  protected:
    PropertySetFactory_stub_clp ();
  private:
    void operator=( const PropertySetFactory_stub_clp & );
};

#endif // MICO_CONF_NO_POA

struct InvalidPropertyName : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  InvalidPropertyName();
  ~InvalidPropertyName();
  InvalidPropertyName( const InvalidPropertyName& s );
  InvalidPropertyName& operator=( const InvalidPropertyName& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  InvalidPropertyName *operator->() { return this; }
  InvalidPropertyName& operator*() { return *this; }
  operator InvalidPropertyName*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static InvalidPropertyName *_downcast( CORBA::Exception *ex );
  static const InvalidPropertyName *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef InvalidPropertyName InvalidPropertyName_catch;
#else
typedef ExceptVar< InvalidPropertyName > InvalidPropertyName_var;
typedef TVarOut< InvalidPropertyName > InvalidPropertyName_out;
typedef InvalidPropertyName_var InvalidPropertyName_catch;
#endif // HAVE_STD_EH

extern CORBA::TypeCodeConst _tc_InvalidPropertyName;

struct ConflictingProperty : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  ConflictingProperty();
  ~ConflictingProperty();
  ConflictingProperty( const ConflictingProperty& s );
  ConflictingProperty& operator=( const ConflictingProperty& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  ConflictingProperty *operator->() { return this; }
  ConflictingProperty& operator*() { return *this; }
  operator ConflictingProperty*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static ConflictingProperty *_downcast( CORBA::Exception *ex );
  static const ConflictingProperty *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef ConflictingProperty ConflictingProperty_catch;
#else
typedef ExceptVar< ConflictingProperty > ConflictingProperty_var;
typedef TVarOut< ConflictingProperty > ConflictingProperty_out;
typedef ConflictingProperty_var ConflictingProperty_catch;
#endif // HAVE_STD_EH

extern CORBA::TypeCodeConst _tc_ConflictingProperty;

struct UnsupportedTypeCode : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  UnsupportedTypeCode();
  ~UnsupportedTypeCode();
  UnsupportedTypeCode( const UnsupportedTypeCode& s );
  UnsupportedTypeCode& operator=( const UnsupportedTypeCode& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  UnsupportedTypeCode *operator->() { return this; }
  UnsupportedTypeCode& operator*() { return *this; }
  operator UnsupportedTypeCode*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static UnsupportedTypeCode *_downcast( CORBA::Exception *ex );
  static const UnsupportedTypeCode *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef UnsupportedTypeCode UnsupportedTypeCode_catch;
#else
typedef ExceptVar< UnsupportedTypeCode > UnsupportedTypeCode_var;
typedef TVarOut< UnsupportedTypeCode > UnsupportedTypeCode_out;
typedef UnsupportedTypeCode_var UnsupportedTypeCode_catch;
#endif // HAVE_STD_EH

extern CORBA::TypeCodeConst _tc_UnsupportedTypeCode;

struct UnsupportedProperty : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  UnsupportedProperty();
  ~UnsupportedProperty();
  UnsupportedProperty( const UnsupportedProperty& s );
  UnsupportedProperty& operator=( const UnsupportedProperty& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  UnsupportedProperty *operator->() { return this; }
  UnsupportedProperty& operator*() { return *this; }
  operator UnsupportedProperty*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static UnsupportedProperty *_downcast( CORBA::Exception *ex );
  static const UnsupportedProperty *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef UnsupportedProperty UnsupportedProperty_catch;
#else
typedef ExceptVar< UnsupportedProperty > UnsupportedProperty_var;
typedef TVarOut< UnsupportedProperty > UnsupportedProperty_out;
typedef UnsupportedProperty_var UnsupportedProperty_catch;
#endif // HAVE_STD_EH

extern CORBA::TypeCodeConst _tc_UnsupportedProperty;

struct ReadOnlyProperty : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  ReadOnlyProperty();
  ~ReadOnlyProperty();
  ReadOnlyProperty( const ReadOnlyProperty& s );
  ReadOnlyProperty& operator=( const ReadOnlyProperty& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  ReadOnlyProperty *operator->() { return this; }
  ReadOnlyProperty& operator*() { return *this; }
  operator ReadOnlyProperty*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static ReadOnlyProperty *_downcast( CORBA::Exception *ex );
  static const ReadOnlyProperty *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef ReadOnlyProperty ReadOnlyProperty_catch;
#else
typedef ExceptVar< ReadOnlyProperty > ReadOnlyProperty_var;
typedef TVarOut< ReadOnlyProperty > ReadOnlyProperty_out;
typedef ReadOnlyProperty_var ReadOnlyProperty_catch;
#endif // HAVE_STD_EH

extern CORBA::TypeCodeConst _tc_ReadOnlyProperty;

struct PropertyNotFound : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  PropertyNotFound();
  ~PropertyNotFound();
  PropertyNotFound( const PropertyNotFound& s );
  PropertyNotFound& operator=( const PropertyNotFound& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  PropertyNotFound *operator->() { return this; }
  PropertyNotFound& operator*() { return *this; }
  operator PropertyNotFound*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static PropertyNotFound *_downcast( CORBA::Exception *ex );
  static const PropertyNotFound *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef PropertyNotFound PropertyNotFound_catch;
#else
typedef ExceptVar< PropertyNotFound > PropertyNotFound_var;
typedef TVarOut< PropertyNotFound > PropertyNotFound_out;
typedef PropertyNotFound_var PropertyNotFound_catch;
#endif // HAVE_STD_EH

extern CORBA::TypeCodeConst _tc_PropertyNotFound;

struct FixedProperty : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  FixedProperty();
  ~FixedProperty();
  FixedProperty( const FixedProperty& s );
  FixedProperty& operator=( const FixedProperty& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  FixedProperty *operator->() { return this; }
  FixedProperty& operator*() { return *this; }
  operator FixedProperty*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static FixedProperty *_downcast( CORBA::Exception *ex );
  static const FixedProperty *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef FixedProperty FixedProperty_catch;
#else
typedef ExceptVar< FixedProperty > FixedProperty_var;
typedef TVarOut< FixedProperty > FixedProperty_out;
typedef FixedProperty_var FixedProperty_catch;
#endif // HAVE_STD_EH

extern CORBA::TypeCodeConst _tc_FixedProperty;


/*
 * Base class and common definitions for interface PropertySet
 */

class PropertySet : 
  virtual public CORBA::Object
{
  public:
    virtual ~PropertySet();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef PropertySet_ptr _ptr_type;
    typedef PropertySet_var _var_type;
    #endif

    static PropertySet_ptr _narrow( CORBA::Object_ptr obj );
    static PropertySet_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static PropertySet_ptr _duplicate( PropertySet_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static PropertySet_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void define_property( const char* property_name, const CORBA::Any& property_value ) = 0;
    virtual void define_properties( const ::PropertyService::Properties& nproperties ) = 0;
    virtual CORBA::ULong get_number_of_properties() = 0;
    virtual void get_all_property_names( CORBA::ULong how_many, ::PropertyService::PropertyNames_out property_names, ::PropertyService::PropertyNamesIterator_out rest ) = 0;
    virtual CORBA::Any* get_property_value( const char* property_name ) = 0;
    virtual CORBA::Boolean get_properties( const ::PropertyService::PropertyNames& property_names, ::PropertyService::Properties_out nproperties ) = 0;
    virtual void get_all_properties( CORBA::ULong how_many, ::PropertyService::Properties_out nproperties, ::PropertyService::PropertiesIterator_out rest ) = 0;
    virtual void delete_property( const char* property_name ) = 0;
    virtual void delete_properties( const ::PropertyService::PropertyNames& property_names ) = 0;
    virtual CORBA::Boolean delete_all_properties() = 0;
    virtual CORBA::Boolean is_property_defined( const char* property_name ) = 0;

  protected:
    PropertySet() {};
  private:
    PropertySet( const PropertySet& );
    void operator=( const PropertySet& );
};

extern CORBA::TypeCodeConst _tc_PropertySet;

// Stub for interface PropertySet
class PropertySet_stub:
  virtual public PropertySet
{
  public:
    virtual ~PropertySet_stub();
    void define_property( const char* property_name, const CORBA::Any& property_value );
    void define_properties( const ::PropertyService::Properties& nproperties );
    CORBA::ULong get_number_of_properties();
    void get_all_property_names( CORBA::ULong how_many, ::PropertyService::PropertyNames_out property_names, ::PropertyService::PropertyNamesIterator_out rest );
    CORBA::Any* get_property_value( const char* property_name );
    CORBA::Boolean get_properties( const ::PropertyService::PropertyNames& property_names, ::PropertyService::Properties_out nproperties );
    void get_all_properties( CORBA::ULong how_many, ::PropertyService::Properties_out nproperties, ::PropertyService::PropertiesIterator_out rest );
    void delete_property( const char* property_name );
    void delete_properties( const ::PropertyService::PropertyNames& property_names );
    CORBA::Boolean delete_all_properties();
    CORBA::Boolean is_property_defined( const char* property_name );

  private:
    void operator=( const PropertySet_stub& );
};

#ifndef MICO_CONF_NO_POA

class PropertySet_stub_clp :
  virtual public PropertySet_stub,
  virtual public PortableServer::StubBase
{
  public:
    PropertySet_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~PropertySet_stub_clp ();
    void define_property( const char* property_name, const CORBA::Any& property_value );
    void define_properties( const ::PropertyService::Properties& nproperties );
    CORBA::ULong get_number_of_properties();
    void get_all_property_names( CORBA::ULong how_many, ::PropertyService::PropertyNames_out property_names, ::PropertyService::PropertyNamesIterator_out rest );
    CORBA::Any* get_property_value( const char* property_name );
    CORBA::Boolean get_properties( const ::PropertyService::PropertyNames& property_names, ::PropertyService::Properties_out nproperties );
    void get_all_properties( CORBA::ULong how_many, ::PropertyService::Properties_out nproperties, ::PropertyService::PropertiesIterator_out rest );
    void delete_property( const char* property_name );
    void delete_properties( const ::PropertyService::PropertyNames& property_names );
    CORBA::Boolean delete_all_properties();
    CORBA::Boolean is_property_defined( const char* property_name );

  protected:
    PropertySet_stub_clp ();
  private:
    void operator=( const PropertySet_stub_clp & );
};

#endif // MICO_CONF_NO_POA

struct UnsupportedMode : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  UnsupportedMode();
  ~UnsupportedMode();
  UnsupportedMode( const UnsupportedMode& s );
  UnsupportedMode& operator=( const UnsupportedMode& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  UnsupportedMode *operator->() { return this; }
  UnsupportedMode& operator*() { return *this; }
  operator UnsupportedMode*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static UnsupportedMode *_downcast( CORBA::Exception *ex );
  static const UnsupportedMode *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef UnsupportedMode UnsupportedMode_catch;
#else
typedef ExceptVar< UnsupportedMode > UnsupportedMode_var;
typedef TVarOut< UnsupportedMode > UnsupportedMode_out;
typedef UnsupportedMode_var UnsupportedMode_catch;
#endif // HAVE_STD_EH

extern CORBA::TypeCodeConst _tc_UnsupportedMode;


/*
 * Base class and common definitions for interface PropertySetDef
 */

class PropertySetDef : 
  virtual public ::PropertyService::PropertySet
{
  public:
    virtual ~PropertySetDef();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef PropertySetDef_ptr _ptr_type;
    typedef PropertySetDef_var _var_type;
    #endif

    static PropertySetDef_ptr _narrow( CORBA::Object_ptr obj );
    static PropertySetDef_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static PropertySetDef_ptr _duplicate( PropertySetDef_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static PropertySetDef_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void get_allowed_property_types( ::PropertyService::PropertyTypes_out property_types ) = 0;
    virtual void get_allowed_properties( ::PropertyService::PropertyDefs_out property_defs ) = 0;
    virtual void define_property_with_mode( const char* property_name, const CORBA::Any& property_value, ::PropertyService::PropertyModeType property_mode ) = 0;
    virtual void define_properties_with_modes( const ::PropertyService::PropertyDefs& property_defs ) = 0;
    virtual ::PropertyService::PropertyModeType get_property_mode( const char* property_name ) = 0;
    virtual CORBA::Boolean get_property_modes( const ::PropertyService::PropertyNames& property_names, ::PropertyService::PropertyModes_out property_modes ) = 0;
    virtual void set_property_mode( const char* property_name, ::PropertyService::PropertyModeType property_mode ) = 0;
    virtual void set_property_modes( const ::PropertyService::PropertyModes& property_modes ) = 0;

  protected:
    PropertySetDef() {};
  private:
    PropertySetDef( const PropertySetDef& );
    void operator=( const PropertySetDef& );
};

extern CORBA::TypeCodeConst _tc_PropertySetDef;

// Stub for interface PropertySetDef
class PropertySetDef_stub:
  virtual public PropertySetDef,
  virtual public ::PropertyService::PropertySet_stub
{
  public:
    virtual ~PropertySetDef_stub();
    void get_allowed_property_types( ::PropertyService::PropertyTypes_out property_types );
    void get_allowed_properties( ::PropertyService::PropertyDefs_out property_defs );
    void define_property_with_mode( const char* property_name, const CORBA::Any& property_value, ::PropertyService::PropertyModeType property_mode );
    void define_properties_with_modes( const ::PropertyService::PropertyDefs& property_defs );
    ::PropertyService::PropertyModeType get_property_mode( const char* property_name );
    CORBA::Boolean get_property_modes( const ::PropertyService::PropertyNames& property_names, ::PropertyService::PropertyModes_out property_modes );
    void set_property_mode( const char* property_name, ::PropertyService::PropertyModeType property_mode );
    void set_property_modes( const ::PropertyService::PropertyModes& property_modes );

  private:
    void operator=( const PropertySetDef_stub& );
};

#ifndef MICO_CONF_NO_POA

class PropertySetDef_stub_clp :
  virtual public PropertySetDef_stub,
  virtual public ::PropertyService::PropertySet_stub_clp
{
  public:
    PropertySetDef_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~PropertySetDef_stub_clp ();
    void get_allowed_property_types( ::PropertyService::PropertyTypes_out property_types );
    void get_allowed_properties( ::PropertyService::PropertyDefs_out property_defs );
    void define_property_with_mode( const char* property_name, const CORBA::Any& property_value, ::PropertyService::PropertyModeType property_mode );
    void define_properties_with_modes( const ::PropertyService::PropertyDefs& property_defs );
    ::PropertyService::PropertyModeType get_property_mode( const char* property_name );
    CORBA::Boolean get_property_modes( const ::PropertyService::PropertyNames& property_names, ::PropertyService::PropertyModes_out property_modes );
    void set_property_mode( const char* property_name, ::PropertyService::PropertyModeType property_mode );
    void set_property_modes( const ::PropertyService::PropertyModes& property_modes );

  protected:
    PropertySetDef_stub_clp ();
  private:
    void operator=( const PropertySetDef_stub_clp & );
};

#endif // MICO_CONF_NO_POA

enum ExceptionReason {
  invalid_property_name = 0,
  conflicting_property,
  property_not_found,
  unsupported_type_code,
  unsupported_property,
  unsupported_mode,
  fixed_property,
  read_only_property
};

typedef ExceptionReason& ExceptionReason_out;

extern CORBA::TypeCodeConst _tc_ExceptionReason;

struct PropertyException {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef PropertyException_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  PropertyException();
  ~PropertyException();
  PropertyException( const PropertyException& s );
  PropertyException& operator=( const PropertyException& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  ExceptionReason reason;
  PropertyName_var failing_property_name;
};

extern CORBA::TypeCodeConst _tc_PropertyException;


/*
 * Base class and common definitions for interface PropertySetDefFactory
 */

class PropertySetDefFactory : 
  virtual public CORBA::Object
{
  public:
    virtual ~PropertySetDefFactory();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef PropertySetDefFactory_ptr _ptr_type;
    typedef PropertySetDefFactory_var _var_type;
    #endif

    static PropertySetDefFactory_ptr _narrow( CORBA::Object_ptr obj );
    static PropertySetDefFactory_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static PropertySetDefFactory_ptr _duplicate( PropertySetDefFactory_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static PropertySetDefFactory_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::PropertyService::PropertySetDef_ptr create_propertysetdef() = 0;
    virtual ::PropertyService::PropertySetDef_ptr create_constrained_propertysetdef( const ::PropertyService::PropertyTypes& allowed_property_types, const ::PropertyService::PropertyDefs& allowed_property_defs ) = 0;
    virtual ::PropertyService::PropertySetDef_ptr create_initial_propertysetdef( const ::PropertyService::PropertyDefs& initial_property_defs ) = 0;

  protected:
    PropertySetDefFactory() {};
  private:
    PropertySetDefFactory( const PropertySetDefFactory& );
    void operator=( const PropertySetDefFactory& );
};

extern CORBA::TypeCodeConst _tc_PropertySetDefFactory;

// Stub for interface PropertySetDefFactory
class PropertySetDefFactory_stub:
  virtual public PropertySetDefFactory
{
  public:
    virtual ~PropertySetDefFactory_stub();
    ::PropertyService::PropertySetDef_ptr create_propertysetdef();
    ::PropertyService::PropertySetDef_ptr create_constrained_propertysetdef( const ::PropertyService::PropertyTypes& allowed_property_types, const ::PropertyService::PropertyDefs& allowed_property_defs );
    ::PropertyService::PropertySetDef_ptr create_initial_propertysetdef( const ::PropertyService::PropertyDefs& initial_property_defs );

  private:
    void operator=( const PropertySetDefFactory_stub& );
};

#ifndef MICO_CONF_NO_POA

class PropertySetDefFactory_stub_clp :
  virtual public PropertySetDefFactory_stub,
  virtual public PortableServer::StubBase
{
  public:
    PropertySetDefFactory_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~PropertySetDefFactory_stub_clp ();
    ::PropertyService::PropertySetDef_ptr create_propertysetdef();
    ::PropertyService::PropertySetDef_ptr create_constrained_propertysetdef( const ::PropertyService::PropertyTypes& allowed_property_types, const ::PropertyService::PropertyDefs& allowed_property_defs );
    ::PropertyService::PropertySetDef_ptr create_initial_propertysetdef( const ::PropertyService::PropertyDefs& initial_property_defs );

  protected:
    PropertySetDefFactory_stub_clp ();
  private:
    void operator=( const PropertySetDefFactory_stub_clp & );
};

#endif // MICO_CONF_NO_POA

}


#ifndef MICO_CONF_NO_POA



namespace POA_PropertyService
{

class PropertyNamesIterator : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~PropertyNamesIterator ();
    PropertyService::PropertyNamesIterator_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static PropertyNamesIterator * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual void reset() = 0;
    virtual CORBA::Boolean next_one( CORBA::String_out propery_name ) = 0;
    virtual CORBA::Boolean next_n( CORBA::ULong how_many, ::PropertyService::PropertyNames_out property_names ) = 0;
    virtual void destroy() = 0;

  protected:
    PropertyNamesIterator () {};

  private:
    PropertyNamesIterator (const PropertyNamesIterator &);
    void operator= (const PropertyNamesIterator &);
};

class PropertiesIterator : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~PropertiesIterator ();
    PropertyService::PropertiesIterator_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static PropertiesIterator * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual void reset() = 0;
    virtual CORBA::Boolean next_one( ::PropertyService::Property_out aproperty ) = 0;
    virtual CORBA::Boolean next_n( CORBA::ULong how_many, ::PropertyService::Properties_out nproperties ) = 0;
    virtual void destroy() = 0;

  protected:
    PropertiesIterator () {};

  private:
    PropertiesIterator (const PropertiesIterator &);
    void operator= (const PropertiesIterator &);
};

class PropertySetFactory : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~PropertySetFactory ();
    PropertyService::PropertySetFactory_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static PropertySetFactory * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual ::PropertyService::PropertySet_ptr create_propertyset() = 0;
    virtual ::PropertyService::PropertySet_ptr create_constrained_propertyset( const ::PropertyService::PropertyTypes& allowed_property_types, const ::PropertyService::Properties& allowed_properties ) = 0;
    virtual ::PropertyService::PropertySet_ptr create_initial_propertyset( const ::PropertyService::Properties& initial_properties ) = 0;

  protected:
    PropertySetFactory () {};

  private:
    PropertySetFactory (const PropertySetFactory &);
    void operator= (const PropertySetFactory &);
};

class PropertySet : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~PropertySet ();
    PropertyService::PropertySet_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static PropertySet * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual void define_property( const char* property_name, const CORBA::Any& property_value ) = 0;
    virtual void define_properties( const ::PropertyService::Properties& nproperties ) = 0;
    virtual CORBA::ULong get_number_of_properties() = 0;
    virtual void get_all_property_names( CORBA::ULong how_many, ::PropertyService::PropertyNames_out property_names, ::PropertyService::PropertyNamesIterator_out rest ) = 0;
    virtual CORBA::Any* get_property_value( const char* property_name ) = 0;
    virtual CORBA::Boolean get_properties( const ::PropertyService::PropertyNames& property_names, ::PropertyService::Properties_out nproperties ) = 0;
    virtual void get_all_properties( CORBA::ULong how_many, ::PropertyService::Properties_out nproperties, ::PropertyService::PropertiesIterator_out rest ) = 0;
    virtual void delete_property( const char* property_name ) = 0;
    virtual void delete_properties( const ::PropertyService::PropertyNames& property_names ) = 0;
    virtual CORBA::Boolean delete_all_properties() = 0;
    virtual CORBA::Boolean is_property_defined( const char* property_name ) = 0;

  protected:
    PropertySet () {};

  private:
    PropertySet (const PropertySet &);
    void operator= (const PropertySet &);
};

class PropertySetDef : 
  virtual public POA_PropertyService::PropertySet
{
  public:
    virtual ~PropertySetDef ();
    PropertyService::PropertySetDef_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static PropertySetDef * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual void get_allowed_property_types( ::PropertyService::PropertyTypes_out property_types ) = 0;
    virtual void get_allowed_properties( ::PropertyService::PropertyDefs_out property_defs ) = 0;
    virtual void define_property_with_mode( const char* property_name, const CORBA::Any& property_value, ::PropertyService::PropertyModeType property_mode ) = 0;
    virtual void define_properties_with_modes( const ::PropertyService::PropertyDefs& property_defs ) = 0;
    virtual ::PropertyService::PropertyModeType get_property_mode( const char* property_name ) = 0;
    virtual CORBA::Boolean get_property_modes( const ::PropertyService::PropertyNames& property_names, ::PropertyService::PropertyModes_out property_modes ) = 0;
    virtual void set_property_mode( const char* property_name, ::PropertyService::PropertyModeType property_mode ) = 0;
    virtual void set_property_modes( const ::PropertyService::PropertyModes& property_modes ) = 0;

  protected:
    PropertySetDef () {};

  private:
    PropertySetDef (const PropertySetDef &);
    void operator= (const PropertySetDef &);
};

class PropertySetDefFactory : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~PropertySetDefFactory ();
    PropertyService::PropertySetDefFactory_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static PropertySetDefFactory * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual ::PropertyService::PropertySetDef_ptr create_propertysetdef() = 0;
    virtual ::PropertyService::PropertySetDef_ptr create_constrained_propertysetdef( const ::PropertyService::PropertyTypes& allowed_property_types, const ::PropertyService::PropertyDefs& allowed_property_defs ) = 0;
    virtual ::PropertyService::PropertySetDef_ptr create_initial_propertysetdef( const ::PropertyService::PropertyDefs& initial_property_defs ) = 0;

  protected:
    PropertySetDefFactory () {};

  private:
    PropertySetDefFactory (const PropertySetDefFactory &);
    void operator= (const PropertySetDefFactory &);
};

}


#endif // MICO_CONF_NO_POA

void operator<<=( CORBA::Any &_a, const ::PropertyService::Property &_s );
void operator<<=( CORBA::Any &_a, ::PropertyService::Property *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::PropertyService::Property &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::PropertyService::Property *&_s );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_Property;

void operator<<=( CORBA::Any &a, const ::PropertyService::PropertyModeType &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, ::PropertyService::PropertyModeType &e );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertyModeType;

void operator<<=( CORBA::Any &_a, const ::PropertyService::PropertyDef &_s );
void operator<<=( CORBA::Any &_a, ::PropertyService::PropertyDef *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::PropertyService::PropertyDef &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::PropertyService::PropertyDef *&_s );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertyDef;

void operator<<=( CORBA::Any &_a, const ::PropertyService::PropertyMode &_s );
void operator<<=( CORBA::Any &_a, ::PropertyService::PropertyMode *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::PropertyService::PropertyMode &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::PropertyService::PropertyMode *&_s );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertyMode;

void operator<<=( CORBA::Any &a, const PropertyService::PropertyNamesIterator_ptr obj );
void operator<<=( CORBA::Any &a, PropertyService::PropertyNamesIterator_ptr* obj_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, PropertyService::PropertyNamesIterator_ptr &obj );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertyNamesIterator;

void operator<<=( CORBA::Any &a, const PropertyService::PropertiesIterator_ptr obj );
void operator<<=( CORBA::Any &a, PropertyService::PropertiesIterator_ptr* obj_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, PropertyService::PropertiesIterator_ptr &obj );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertiesIterator;

void operator<<=( CORBA::Any &a, const ::PropertyService::ConstraintNotSupported &e );
void operator<<=( CORBA::Any &a, ::PropertyService::ConstraintNotSupported *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::PropertyService::ConstraintNotSupported &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::PropertyService::ConstraintNotSupported *&e );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_ConstraintNotSupported;

void operator<<=( CORBA::Any &a, const ::PropertyService::MultipleExceptions &e );
void operator<<=( CORBA::Any &a, ::PropertyService::MultipleExceptions *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::PropertyService::MultipleExceptions &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::PropertyService::MultipleExceptions *&e );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_MultipleExceptions;

void operator<<=( CORBA::Any &a, const PropertyService::PropertySetFactory_ptr obj );
void operator<<=( CORBA::Any &a, PropertyService::PropertySetFactory_ptr* obj_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, PropertyService::PropertySetFactory_ptr &obj );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertySetFactory;

void operator<<=( CORBA::Any &a, const ::PropertyService::InvalidPropertyName &e );
void operator<<=( CORBA::Any &a, ::PropertyService::InvalidPropertyName *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::PropertyService::InvalidPropertyName &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::PropertyService::InvalidPropertyName *&e );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_InvalidPropertyName;

void operator<<=( CORBA::Any &a, const ::PropertyService::ConflictingProperty &e );
void operator<<=( CORBA::Any &a, ::PropertyService::ConflictingProperty *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::PropertyService::ConflictingProperty &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::PropertyService::ConflictingProperty *&e );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_ConflictingProperty;

void operator<<=( CORBA::Any &a, const ::PropertyService::UnsupportedTypeCode &e );
void operator<<=( CORBA::Any &a, ::PropertyService::UnsupportedTypeCode *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::PropertyService::UnsupportedTypeCode &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::PropertyService::UnsupportedTypeCode *&e );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_UnsupportedTypeCode;

void operator<<=( CORBA::Any &a, const ::PropertyService::UnsupportedProperty &e );
void operator<<=( CORBA::Any &a, ::PropertyService::UnsupportedProperty *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::PropertyService::UnsupportedProperty &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::PropertyService::UnsupportedProperty *&e );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_UnsupportedProperty;

void operator<<=( CORBA::Any &a, const ::PropertyService::ReadOnlyProperty &e );
void operator<<=( CORBA::Any &a, ::PropertyService::ReadOnlyProperty *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::PropertyService::ReadOnlyProperty &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::PropertyService::ReadOnlyProperty *&e );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_ReadOnlyProperty;

void operator<<=( CORBA::Any &a, const ::PropertyService::PropertyNotFound &e );
void operator<<=( CORBA::Any &a, ::PropertyService::PropertyNotFound *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::PropertyService::PropertyNotFound &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::PropertyService::PropertyNotFound *&e );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertyNotFound;

void operator<<=( CORBA::Any &a, const ::PropertyService::FixedProperty &e );
void operator<<=( CORBA::Any &a, ::PropertyService::FixedProperty *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::PropertyService::FixedProperty &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::PropertyService::FixedProperty *&e );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_FixedProperty;

void operator<<=( CORBA::Any &a, const PropertyService::PropertySet_ptr obj );
void operator<<=( CORBA::Any &a, PropertyService::PropertySet_ptr* obj_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, PropertyService::PropertySet_ptr &obj );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertySet;

void operator<<=( CORBA::Any &a, const ::PropertyService::UnsupportedMode &e );
void operator<<=( CORBA::Any &a, ::PropertyService::UnsupportedMode *e );
CORBA::Boolean operator>>=( const CORBA::Any &a, ::PropertyService::UnsupportedMode &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, const ::PropertyService::UnsupportedMode *&e );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_UnsupportedMode;

void operator<<=( CORBA::Any &a, const PropertyService::PropertySetDef_ptr obj );
void operator<<=( CORBA::Any &a, PropertyService::PropertySetDef_ptr* obj_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, PropertyService::PropertySetDef_ptr &obj );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertySetDef;

void operator<<=( CORBA::Any &a, const ::PropertyService::ExceptionReason &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, ::PropertyService::ExceptionReason &e );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_ExceptionReason;

void operator<<=( CORBA::Any &_a, const ::PropertyService::PropertyException &_s );
void operator<<=( CORBA::Any &_a, ::PropertyService::PropertyException *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, ::PropertyService::PropertyException &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const ::PropertyService::PropertyException *&_s );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertyException;

void operator<<=( CORBA::Any &a, const PropertyService::PropertySetDefFactory_ptr obj );
void operator<<=( CORBA::Any &a, PropertyService::PropertySetDefFactory_ptr* obj_ptr );
CORBA::Boolean operator>>=( const CORBA::Any &a, PropertyService::PropertySetDefFactory_ptr &obj );

extern CORBA::StaticTypeInfo *_marshaller_PropertyService_PropertySetDefFactory;

void operator<<=( CORBA::Any &_a, const StringSequenceTmpl<CORBA::String_var> &_s );
void operator<<=( CORBA::Any &_a, StringSequenceTmpl<CORBA::String_var> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, StringSequenceTmpl<CORBA::String_var> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const StringSequenceTmpl<CORBA::String_var> *&_s );

void operator<<=( CORBA::Any &_a, const SequenceTmpl< PropertyService::Property,MICO_TID_DEF> &_s );
void operator<<=( CORBA::Any &_a, SequenceTmpl< PropertyService::Property,MICO_TID_DEF> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< PropertyService::Property,MICO_TID_DEF> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< PropertyService::Property,MICO_TID_DEF> *&_s );

extern CORBA::StaticTypeInfo *_marshaller__seq_PropertyService_Property;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< PropertyService::PropertyDef,MICO_TID_DEF> &_s );
void operator<<=( CORBA::Any &_a, SequenceTmpl< PropertyService::PropertyDef,MICO_TID_DEF> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< PropertyService::PropertyDef,MICO_TID_DEF> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< PropertyService::PropertyDef,MICO_TID_DEF> *&_s );

extern CORBA::StaticTypeInfo *_marshaller__seq_PropertyService_PropertyDef;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< PropertyService::PropertyMode,MICO_TID_DEF> &_s );
void operator<<=( CORBA::Any &_a, SequenceTmpl< PropertyService::PropertyMode,MICO_TID_DEF> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< PropertyService::PropertyMode,MICO_TID_DEF> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< PropertyService::PropertyMode,MICO_TID_DEF> *&_s );

extern CORBA::StaticTypeInfo *_marshaller__seq_PropertyService_PropertyMode;

void operator<<=( CORBA::Any &_a, const SequenceTmpl< PropertyService::PropertyException,MICO_TID_DEF> &_s );
void operator<<=( CORBA::Any &_a, SequenceTmpl< PropertyService::PropertyException,MICO_TID_DEF> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, SequenceTmpl< PropertyService::PropertyException,MICO_TID_DEF> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const SequenceTmpl< PropertyService::PropertyException,MICO_TID_DEF> *&_s );

extern CORBA::StaticTypeInfo *_marshaller__seq_PropertyService_PropertyException;

#endif
