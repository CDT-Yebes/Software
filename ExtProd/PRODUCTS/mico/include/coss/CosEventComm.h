/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>
#include <mico/throw.h>

#ifndef __COSEVENTCOMM_H__
#define __COSEVENTCOMM_H__






namespace CosEventComm
{

class PushConsumer;
typedef PushConsumer *PushConsumer_ptr;
typedef PushConsumer_ptr PushConsumerRef;
typedef ObjVar< PushConsumer > PushConsumer_var;
typedef ObjOut< PushConsumer > PushConsumer_out;

class PushSupplier;
typedef PushSupplier *PushSupplier_ptr;
typedef PushSupplier_ptr PushSupplierRef;
typedef ObjVar< PushSupplier > PushSupplier_var;
typedef ObjOut< PushSupplier > PushSupplier_out;

class PullSupplier;
typedef PullSupplier *PullSupplier_ptr;
typedef PullSupplier_ptr PullSupplierRef;
typedef ObjVar< PullSupplier > PullSupplier_var;
typedef ObjOut< PullSupplier > PullSupplier_out;

class PullConsumer;
typedef PullConsumer *PullConsumer_ptr;
typedef PullConsumer_ptr PullConsumerRef;
typedef ObjVar< PullConsumer > PullConsumer_var;
typedef ObjOut< PullConsumer > PullConsumer_out;

}






namespace CosEventComm
{

struct Disconnected : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  Disconnected();
  ~Disconnected();
  Disconnected( const Disconnected& s );
  Disconnected& operator=( const Disconnected& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  Disconnected *operator->() { return this; }
  Disconnected& operator*() { return *this; }
  operator Disconnected*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static Disconnected *_downcast( CORBA::Exception *ex );
  static const Disconnected *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef Disconnected Disconnected_catch;
#else
typedef ExceptVar< Disconnected > Disconnected_var;
typedef TVarOut< Disconnected > Disconnected_out;
typedef Disconnected_var Disconnected_catch;
#endif // HAVE_STD_EH


/*
 * Base class and common definitions for interface PushConsumer
 */

class PushConsumer : 
  virtual public CORBA::Object
{
  public:
    virtual ~PushConsumer();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef PushConsumer_ptr _ptr_type;
    typedef PushConsumer_var _var_type;
    #endif

    static PushConsumer_ptr _narrow( CORBA::Object_ptr obj );
    static PushConsumer_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static PushConsumer_ptr _duplicate( PushConsumer_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static PushConsumer_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void push( const CORBA::Any& data ) = 0;
    virtual void disconnect_push_consumer() = 0;

  protected:
    PushConsumer() {};
  private:
    PushConsumer( const PushConsumer& );
    void operator=( const PushConsumer& );
};

// Stub for interface PushConsumer
class PushConsumer_stub:
  virtual public PushConsumer
{
  public:
    virtual ~PushConsumer_stub();
    void push( const CORBA::Any& data );
    void disconnect_push_consumer();

  private:
    void operator=( const PushConsumer_stub& );
};

#ifndef MICO_CONF_NO_POA

class PushConsumer_stub_clp :
  virtual public PushConsumer_stub,
  virtual public PortableServer::StubBase
{
  public:
    PushConsumer_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~PushConsumer_stub_clp ();
    void push( const CORBA::Any& data );
    void disconnect_push_consumer();

  protected:
    PushConsumer_stub_clp ();
  private:
    void operator=( const PushConsumer_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface PushSupplier
 */

class PushSupplier : 
  virtual public CORBA::Object
{
  public:
    virtual ~PushSupplier();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef PushSupplier_ptr _ptr_type;
    typedef PushSupplier_var _var_type;
    #endif

    static PushSupplier_ptr _narrow( CORBA::Object_ptr obj );
    static PushSupplier_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static PushSupplier_ptr _duplicate( PushSupplier_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static PushSupplier_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void disconnect_push_supplier() = 0;

  protected:
    PushSupplier() {};
  private:
    PushSupplier( const PushSupplier& );
    void operator=( const PushSupplier& );
};

// Stub for interface PushSupplier
class PushSupplier_stub:
  virtual public PushSupplier
{
  public:
    virtual ~PushSupplier_stub();
    void disconnect_push_supplier();

  private:
    void operator=( const PushSupplier_stub& );
};

#ifndef MICO_CONF_NO_POA

class PushSupplier_stub_clp :
  virtual public PushSupplier_stub,
  virtual public PortableServer::StubBase
{
  public:
    PushSupplier_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~PushSupplier_stub_clp ();
    void disconnect_push_supplier();

  protected:
    PushSupplier_stub_clp ();
  private:
    void operator=( const PushSupplier_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface PullSupplier
 */

class PullSupplier : 
  virtual public CORBA::Object
{
  public:
    virtual ~PullSupplier();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef PullSupplier_ptr _ptr_type;
    typedef PullSupplier_var _var_type;
    #endif

    static PullSupplier_ptr _narrow( CORBA::Object_ptr obj );
    static PullSupplier_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static PullSupplier_ptr _duplicate( PullSupplier_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static PullSupplier_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual CORBA::Any* pull() = 0;
    virtual CORBA::Any* try_pull( CORBA::Boolean_out has_event ) = 0;
    virtual void disconnect_pull_supplier() = 0;

  protected:
    PullSupplier() {};
  private:
    PullSupplier( const PullSupplier& );
    void operator=( const PullSupplier& );
};

// Stub for interface PullSupplier
class PullSupplier_stub:
  virtual public PullSupplier
{
  public:
    virtual ~PullSupplier_stub();
    CORBA::Any* pull();
    CORBA::Any* try_pull( CORBA::Boolean_out has_event );
    void disconnect_pull_supplier();

  private:
    void operator=( const PullSupplier_stub& );
};

#ifndef MICO_CONF_NO_POA

class PullSupplier_stub_clp :
  virtual public PullSupplier_stub,
  virtual public PortableServer::StubBase
{
  public:
    PullSupplier_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~PullSupplier_stub_clp ();
    CORBA::Any* pull();
    CORBA::Any* try_pull( CORBA::Boolean_out has_event );
    void disconnect_pull_supplier();

  protected:
    PullSupplier_stub_clp ();
  private:
    void operator=( const PullSupplier_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface PullConsumer
 */

class PullConsumer : 
  virtual public CORBA::Object
{
  public:
    virtual ~PullConsumer();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef PullConsumer_ptr _ptr_type;
    typedef PullConsumer_var _var_type;
    #endif

    static PullConsumer_ptr _narrow( CORBA::Object_ptr obj );
    static PullConsumer_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static PullConsumer_ptr _duplicate( PullConsumer_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static PullConsumer_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void disconnect_pull_consumer() = 0;

  protected:
    PullConsumer() {};
  private:
    PullConsumer( const PullConsumer& );
    void operator=( const PullConsumer& );
};

// Stub for interface PullConsumer
class PullConsumer_stub:
  virtual public PullConsumer
{
  public:
    virtual ~PullConsumer_stub();
    void disconnect_pull_consumer();

  private:
    void operator=( const PullConsumer_stub& );
};

#ifndef MICO_CONF_NO_POA

class PullConsumer_stub_clp :
  virtual public PullConsumer_stub,
  virtual public PortableServer::StubBase
{
  public:
    PullConsumer_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~PullConsumer_stub_clp ();
    void disconnect_pull_consumer();

  protected:
    PullConsumer_stub_clp ();
  private:
    void operator=( const PullConsumer_stub_clp & );
};

#endif // MICO_CONF_NO_POA

}


#ifndef MICO_CONF_NO_POA



namespace POA_CosEventComm
{

class PushConsumer : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~PushConsumer ();
    CosEventComm::PushConsumer_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static PushConsumer * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual void push( const CORBA::Any& data ) = 0;
    virtual void disconnect_push_consumer() = 0;

  protected:
    PushConsumer () {};

  private:
    PushConsumer (const PushConsumer &);
    void operator= (const PushConsumer &);
};

class PushSupplier : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~PushSupplier ();
    CosEventComm::PushSupplier_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static PushSupplier * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual void disconnect_push_supplier() = 0;

  protected:
    PushSupplier () {};

  private:
    PushSupplier (const PushSupplier &);
    void operator= (const PushSupplier &);
};

class PullSupplier : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~PullSupplier ();
    CosEventComm::PullSupplier_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static PullSupplier * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual CORBA::Any* pull() = 0;
    virtual CORBA::Any* try_pull( CORBA::Boolean_out has_event ) = 0;
    virtual void disconnect_pull_supplier() = 0;

  protected:
    PullSupplier () {};

  private:
    PullSupplier (const PullSupplier &);
    void operator= (const PullSupplier &);
};

class PullConsumer : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~PullConsumer ();
    CosEventComm::PullConsumer_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static PullConsumer * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual void disconnect_pull_consumer() = 0;

  protected:
    PullConsumer () {};

  private:
    PullConsumer (const PullConsumer &);
    void operator= (const PullConsumer &);
};

}


#endif // MICO_CONF_NO_POA

extern CORBA::StaticTypeInfo *_marshaller_CosEventComm_Disconnected;

extern CORBA::StaticTypeInfo *_marshaller_CosEventComm_PushConsumer;

extern CORBA::StaticTypeInfo *_marshaller_CosEventComm_PushSupplier;

extern CORBA::StaticTypeInfo *_marshaller_CosEventComm_PullSupplier;

extern CORBA::StaticTypeInfo *_marshaller_CosEventComm_PullConsumer;

#endif
