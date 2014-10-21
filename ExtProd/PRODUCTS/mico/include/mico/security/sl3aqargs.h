/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __SL3AQARGS_H__
#define __SL3AQARGS_H__


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

class Argument;
typedef Argument *Argument_ptr;
typedef Argument_ptr ArgumentRef;
typedef ObjVar< Argument > Argument_var;
typedef ObjOut< Argument > Argument_out;

class ArgBuilder;
typedef ArgBuilder *ArgBuilder_ptr;
typedef ArgBuilder_ptr ArgBuilderRef;
typedef ObjVar< ArgBuilder > ArgBuilder_var;
typedef ObjOut< ArgBuilder > ArgBuilder_out;

class ArgBuilderFactory;
typedef ArgBuilderFactory *ArgBuilderFactory_ptr;
typedef ArgBuilderFactory_ptr ArgBuilderFactoryRef;
typedef ObjVar< ArgBuilderFactory > ArgBuilderFactory_var;
typedef ObjOut< ArgBuilderFactory > ArgBuilderFactory_out;

}






namespace SL3AQArgs
{


/*
 * Base class and common definitions for local interface Argument
 */

class Argument : 
  virtual public CORBA::Object
{
  public:
    virtual ~Argument();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef Argument_ptr _ptr_type;
    typedef Argument_var _var_type;
    #endif

    static Argument_ptr _narrow( CORBA::Object_ptr obj );
    static Argument_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static Argument_ptr _duplicate( Argument_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static Argument_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual char* type() = 0;

  protected:
    Argument() {};
  private:
    Argument( const Argument& );
    void operator=( const Argument& );
};


typedef IfaceSequenceTmpl< Argument_var,Argument_ptr> ArgumentSeq;
typedef TSeqVar< IfaceSequenceTmpl< Argument_var,Argument_ptr> > ArgumentSeq_var;
typedef TSeqOut< IfaceSequenceTmpl< Argument_var,Argument_ptr> > ArgumentSeq_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ArgumentSeq;


/*
 * Base class and common definitions for local interface ArgBuilder
 */

class ArgBuilder : 
  virtual public CORBA::Object
{
  public:
    virtual ~ArgBuilder();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ArgBuilder_ptr _ptr_type;
    typedef ArgBuilder_var _var_type;
    #endif

    static ArgBuilder_ptr _narrow( CORBA::Object_ptr obj );
    static ArgBuilder_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ArgBuilder_ptr _duplicate( ArgBuilder_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ArgBuilder_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void add_arg( ::SL3AQArgs::Argument_ptr arg ) = 0;
    virtual void add_args( const ::SL3AQArgs::ArgumentSeq& args ) = 0;
    virtual ::SL3AQArgs::Argument_ptr reap_args() = 0;
    virtual void destroy() = 0;

  protected:
    ArgBuilder() {};
  private:
    ArgBuilder( const ArgBuilder& );
    void operator=( const ArgBuilder& );
};



/*
 * Base class and common definitions for local interface ArgBuilderFactory
 */

class ArgBuilderFactory : 
  virtual public CORBA::Object
{
  public:
    virtual ~ArgBuilderFactory();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ArgBuilderFactory_ptr _ptr_type;
    typedef ArgBuilderFactory_var _var_type;
    #endif

    static ArgBuilderFactory_ptr _narrow( CORBA::Object_ptr obj );
    static ArgBuilderFactory_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ArgBuilderFactory_ptr _duplicate( ArgBuilderFactory_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ArgBuilderFactory_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::SL3AQArgs::ArgBuilder_ptr create_arg_builder( ::SL3CM::CredentialsUsage usage ) = 0;

  protected:
    ArgBuilderFactory() {};
  private:
    ArgBuilderFactory( const ArgBuilderFactory& );
    void operator=( const ArgBuilderFactory& );
};


}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

#endif
