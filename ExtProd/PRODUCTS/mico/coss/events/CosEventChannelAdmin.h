/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>
#include <mico/throw.h>

#ifndef __COSEVENTCHANNELADMIN_H__
#define __COSEVENTCHANNELADMIN_H__






namespace CosEventChannelAdmin
{

class ProxyPushConsumer;
typedef ProxyPushConsumer *ProxyPushConsumer_ptr;
typedef ProxyPushConsumer_ptr ProxyPushConsumerRef;
typedef ObjVar< ProxyPushConsumer > ProxyPushConsumer_var;
typedef ObjOut< ProxyPushConsumer > ProxyPushConsumer_out;

class ProxyPullSupplier;
typedef ProxyPullSupplier *ProxyPullSupplier_ptr;
typedef ProxyPullSupplier_ptr ProxyPullSupplierRef;
typedef ObjVar< ProxyPullSupplier > ProxyPullSupplier_var;
typedef ObjOut< ProxyPullSupplier > ProxyPullSupplier_out;

class ProxyPullConsumer;
typedef ProxyPullConsumer *ProxyPullConsumer_ptr;
typedef ProxyPullConsumer_ptr ProxyPullConsumerRef;
typedef ObjVar< ProxyPullConsumer > ProxyPullConsumer_var;
typedef ObjOut< ProxyPullConsumer > ProxyPullConsumer_out;

class ProxyPushSupplier;
typedef ProxyPushSupplier *ProxyPushSupplier_ptr;
typedef ProxyPushSupplier_ptr ProxyPushSupplierRef;
typedef ObjVar< ProxyPushSupplier > ProxyPushSupplier_var;
typedef ObjOut< ProxyPushSupplier > ProxyPushSupplier_out;

class ConsumerAdmin;
typedef ConsumerAdmin *ConsumerAdmin_ptr;
typedef ConsumerAdmin_ptr ConsumerAdminRef;
typedef ObjVar< ConsumerAdmin > ConsumerAdmin_var;
typedef ObjOut< ConsumerAdmin > ConsumerAdmin_out;

class SupplierAdmin;
typedef SupplierAdmin *SupplierAdmin_ptr;
typedef SupplierAdmin_ptr SupplierAdminRef;
typedef ObjVar< SupplierAdmin > SupplierAdmin_var;
typedef ObjOut< SupplierAdmin > SupplierAdmin_out;

class EventChannel;
typedef EventChannel *EventChannel_ptr;
typedef EventChannel_ptr EventChannelRef;
typedef ObjVar< EventChannel > EventChannel_var;
typedef ObjOut< EventChannel > EventChannel_out;

}


namespace SimpleEventChannelAdmin
{

class EventChannelFactory;
typedef EventChannelFactory *EventChannelFactory_ptr;
typedef EventChannelFactory_ptr EventChannelFactoryRef;
typedef ObjVar< EventChannelFactory > EventChannelFactory_var;
typedef ObjOut< EventChannelFactory > EventChannelFactory_out;

}



#include <coss/CosEventComm.h>



namespace CosEventChannelAdmin
{

struct AlreadyConnected : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  AlreadyConnected();
  ~AlreadyConnected();
  AlreadyConnected( const AlreadyConnected& s );
  AlreadyConnected& operator=( const AlreadyConnected& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  AlreadyConnected *operator->() { return this; }
  AlreadyConnected& operator*() { return *this; }
  operator AlreadyConnected*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static AlreadyConnected *_downcast( CORBA::Exception *ex );
  static const AlreadyConnected *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef AlreadyConnected AlreadyConnected_catch;
#else
typedef ExceptVar< AlreadyConnected > AlreadyConnected_var;
typedef TVarOut< AlreadyConnected > AlreadyConnected_out;
typedef AlreadyConnected_var AlreadyConnected_catch;
#endif // HAVE_STD_EH

struct TypeError : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  TypeError();
  ~TypeError();
  TypeError( const TypeError& s );
  TypeError& operator=( const TypeError& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  TypeError *operator->() { return this; }
  TypeError& operator*() { return *this; }
  operator TypeError*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static TypeError *_downcast( CORBA::Exception *ex );
  static const TypeError *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef TypeError TypeError_catch;
#else
typedef ExceptVar< TypeError > TypeError_var;
typedef TVarOut< TypeError > TypeError_out;
typedef TypeError_var TypeError_catch;
#endif // HAVE_STD_EH


/*
 * Base class and common definitions for interface ProxyPushConsumer
 */

class ProxyPushConsumer : 
  virtual public ::CosEventComm::PushConsumer
{
  public:
    virtual ~ProxyPushConsumer();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ProxyPushConsumer_ptr _ptr_type;
    typedef ProxyPushConsumer_var _var_type;
    #endif

    static ProxyPushConsumer_ptr _narrow( CORBA::Object_ptr obj );
    static ProxyPushConsumer_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ProxyPushConsumer_ptr _duplicate( ProxyPushConsumer_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ProxyPushConsumer_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void connect_push_supplier( ::CosEventComm::PushSupplier_ptr push_supplier ) = 0;

  protected:
    ProxyPushConsumer() {};
  private:
    ProxyPushConsumer( const ProxyPushConsumer& );
    void operator=( const ProxyPushConsumer& );
};

// Stub for interface ProxyPushConsumer
class ProxyPushConsumer_stub:
  virtual public ProxyPushConsumer,
  virtual public ::CosEventComm::PushConsumer_stub
{
  public:
    virtual ~ProxyPushConsumer_stub();
    void connect_push_supplier( ::CosEventComm::PushSupplier_ptr push_supplier );

  private:
    void operator=( const ProxyPushConsumer_stub& );
};

#ifndef MICO_CONF_NO_POA

class ProxyPushConsumer_stub_clp :
  virtual public ProxyPushConsumer_stub,
  virtual public ::CosEventComm::PushConsumer_stub_clp
{
  public:
    ProxyPushConsumer_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~ProxyPushConsumer_stub_clp ();
    void connect_push_supplier( ::CosEventComm::PushSupplier_ptr push_supplier );

  protected:
    ProxyPushConsumer_stub_clp ();
  private:
    void operator=( const ProxyPushConsumer_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface ProxyPullSupplier
 */

class ProxyPullSupplier : 
  virtual public ::CosEventComm::PullSupplier
{
  public:
    virtual ~ProxyPullSupplier();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ProxyPullSupplier_ptr _ptr_type;
    typedef ProxyPullSupplier_var _var_type;
    #endif

    static ProxyPullSupplier_ptr _narrow( CORBA::Object_ptr obj );
    static ProxyPullSupplier_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ProxyPullSupplier_ptr _duplicate( ProxyPullSupplier_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ProxyPullSupplier_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void connect_pull_consumer( ::CosEventComm::PullConsumer_ptr pull_consumer ) = 0;
    virtual void notify( const CORBA::Any& a ) = 0;

  protected:
    ProxyPullSupplier() {};
  private:
    ProxyPullSupplier( const ProxyPullSupplier& );
    void operator=( const ProxyPullSupplier& );
};

// Stub for interface ProxyPullSupplier
class ProxyPullSupplier_stub:
  virtual public ProxyPullSupplier,
  virtual public ::CosEventComm::PullSupplier_stub
{
  public:
    virtual ~ProxyPullSupplier_stub();
    void connect_pull_consumer( ::CosEventComm::PullConsumer_ptr pull_consumer );
    void notify( const CORBA::Any& a );

  private:
    void operator=( const ProxyPullSupplier_stub& );
};

#ifndef MICO_CONF_NO_POA

class ProxyPullSupplier_stub_clp :
  virtual public ProxyPullSupplier_stub,
  virtual public ::CosEventComm::PullSupplier_stub_clp
{
  public:
    ProxyPullSupplier_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~ProxyPullSupplier_stub_clp ();
    void connect_pull_consumer( ::CosEventComm::PullConsumer_ptr pull_consumer );
    void notify( const CORBA::Any& a );

  protected:
    ProxyPullSupplier_stub_clp ();
  private:
    void operator=( const ProxyPullSupplier_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface ProxyPullConsumer
 */

class ProxyPullConsumer : 
  virtual public ::CosEventComm::PullConsumer
{
  public:
    virtual ~ProxyPullConsumer();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ProxyPullConsumer_ptr _ptr_type;
    typedef ProxyPullConsumer_var _var_type;
    #endif

    static ProxyPullConsumer_ptr _narrow( CORBA::Object_ptr obj );
    static ProxyPullConsumer_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ProxyPullConsumer_ptr _duplicate( ProxyPullConsumer_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ProxyPullConsumer_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void connect_pull_supplier( ::CosEventComm::PullSupplier_ptr pull_supplier ) = 0;
    virtual void listen() = 0;

  protected:
    ProxyPullConsumer() {};
  private:
    ProxyPullConsumer( const ProxyPullConsumer& );
    void operator=( const ProxyPullConsumer& );
};

// Stub for interface ProxyPullConsumer
class ProxyPullConsumer_stub:
  virtual public ProxyPullConsumer,
  virtual public ::CosEventComm::PullConsumer_stub
{
  public:
    virtual ~ProxyPullConsumer_stub();
    void connect_pull_supplier( ::CosEventComm::PullSupplier_ptr pull_supplier );
    void listen();

  private:
    void operator=( const ProxyPullConsumer_stub& );
};

#ifndef MICO_CONF_NO_POA

class ProxyPullConsumer_stub_clp :
  virtual public ProxyPullConsumer_stub,
  virtual public ::CosEventComm::PullConsumer_stub_clp
{
  public:
    ProxyPullConsumer_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~ProxyPullConsumer_stub_clp ();
    void connect_pull_supplier( ::CosEventComm::PullSupplier_ptr pull_supplier );
    void listen();

  protected:
    ProxyPullConsumer_stub_clp ();
  private:
    void operator=( const ProxyPullConsumer_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface ProxyPushSupplier
 */

class ProxyPushSupplier : 
  virtual public ::CosEventComm::PushSupplier
{
  public:
    virtual ~ProxyPushSupplier();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ProxyPushSupplier_ptr _ptr_type;
    typedef ProxyPushSupplier_var _var_type;
    #endif

    static ProxyPushSupplier_ptr _narrow( CORBA::Object_ptr obj );
    static ProxyPushSupplier_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ProxyPushSupplier_ptr _duplicate( ProxyPushSupplier_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ProxyPushSupplier_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void connect_push_consumer( ::CosEventComm::PushConsumer_ptr push_consumer ) = 0;
    virtual void notify( const CORBA::Any& a ) = 0;

  protected:
    ProxyPushSupplier() {};
  private:
    ProxyPushSupplier( const ProxyPushSupplier& );
    void operator=( const ProxyPushSupplier& );
};

// Stub for interface ProxyPushSupplier
class ProxyPushSupplier_stub:
  virtual public ProxyPushSupplier,
  virtual public ::CosEventComm::PushSupplier_stub
{
  public:
    virtual ~ProxyPushSupplier_stub();
    void connect_push_consumer( ::CosEventComm::PushConsumer_ptr push_consumer );
    void notify( const CORBA::Any& a );

  private:
    void operator=( const ProxyPushSupplier_stub& );
};

#ifndef MICO_CONF_NO_POA

class ProxyPushSupplier_stub_clp :
  virtual public ProxyPushSupplier_stub,
  virtual public ::CosEventComm::PushSupplier_stub_clp
{
  public:
    ProxyPushSupplier_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~ProxyPushSupplier_stub_clp ();
    void connect_push_consumer( ::CosEventComm::PushConsumer_ptr push_consumer );
    void notify( const CORBA::Any& a );

  protected:
    ProxyPushSupplier_stub_clp ();
  private:
    void operator=( const ProxyPushSupplier_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface ConsumerAdmin
 */

class ConsumerAdmin : 
  virtual public CORBA::Object
{
  public:
    virtual ~ConsumerAdmin();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef ConsumerAdmin_ptr _ptr_type;
    typedef ConsumerAdmin_var _var_type;
    #endif

    static ConsumerAdmin_ptr _narrow( CORBA::Object_ptr obj );
    static ConsumerAdmin_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static ConsumerAdmin_ptr _duplicate( ConsumerAdmin_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static ConsumerAdmin_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::CosEventChannelAdmin::ProxyPushSupplier_ptr obtain_push_supplier() = 0;
    virtual ::CosEventChannelAdmin::ProxyPullSupplier_ptr obtain_pull_supplier() = 0;

  protected:
    ConsumerAdmin() {};
  private:
    ConsumerAdmin( const ConsumerAdmin& );
    void operator=( const ConsumerAdmin& );
};

// Stub for interface ConsumerAdmin
class ConsumerAdmin_stub:
  virtual public ConsumerAdmin
{
  public:
    virtual ~ConsumerAdmin_stub();
    ::CosEventChannelAdmin::ProxyPushSupplier_ptr obtain_push_supplier();
    ::CosEventChannelAdmin::ProxyPullSupplier_ptr obtain_pull_supplier();

  private:
    void operator=( const ConsumerAdmin_stub& );
};

#ifndef MICO_CONF_NO_POA

class ConsumerAdmin_stub_clp :
  virtual public ConsumerAdmin_stub,
  virtual public PortableServer::StubBase
{
  public:
    ConsumerAdmin_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~ConsumerAdmin_stub_clp ();
    ::CosEventChannelAdmin::ProxyPushSupplier_ptr obtain_push_supplier();
    ::CosEventChannelAdmin::ProxyPullSupplier_ptr obtain_pull_supplier();

  protected:
    ConsumerAdmin_stub_clp ();
  private:
    void operator=( const ConsumerAdmin_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface SupplierAdmin
 */

class SupplierAdmin : 
  virtual public CORBA::Object
{
  public:
    virtual ~SupplierAdmin();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef SupplierAdmin_ptr _ptr_type;
    typedef SupplierAdmin_var _var_type;
    #endif

    static SupplierAdmin_ptr _narrow( CORBA::Object_ptr obj );
    static SupplierAdmin_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static SupplierAdmin_ptr _duplicate( SupplierAdmin_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static SupplierAdmin_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::CosEventChannelAdmin::ProxyPushConsumer_ptr obtain_push_consumer() = 0;
    virtual ::CosEventChannelAdmin::ProxyPullConsumer_ptr obtain_pull_consumer() = 0;

  protected:
    SupplierAdmin() {};
  private:
    SupplierAdmin( const SupplierAdmin& );
    void operator=( const SupplierAdmin& );
};

// Stub for interface SupplierAdmin
class SupplierAdmin_stub:
  virtual public SupplierAdmin
{
  public:
    virtual ~SupplierAdmin_stub();
    ::CosEventChannelAdmin::ProxyPushConsumer_ptr obtain_push_consumer();
    ::CosEventChannelAdmin::ProxyPullConsumer_ptr obtain_pull_consumer();

  private:
    void operator=( const SupplierAdmin_stub& );
};

#ifndef MICO_CONF_NO_POA

class SupplierAdmin_stub_clp :
  virtual public SupplierAdmin_stub,
  virtual public PortableServer::StubBase
{
  public:
    SupplierAdmin_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~SupplierAdmin_stub_clp ();
    ::CosEventChannelAdmin::ProxyPushConsumer_ptr obtain_push_consumer();
    ::CosEventChannelAdmin::ProxyPullConsumer_ptr obtain_pull_consumer();

  protected:
    SupplierAdmin_stub_clp ();
  private:
    void operator=( const SupplierAdmin_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface EventChannel
 */

class EventChannel : 
  virtual public CORBA::Object
{
  public:
    virtual ~EventChannel();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef EventChannel_ptr _ptr_type;
    typedef EventChannel_var _var_type;
    #endif

    static EventChannel_ptr _narrow( CORBA::Object_ptr obj );
    static EventChannel_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static EventChannel_ptr _duplicate( EventChannel_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static EventChannel_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::CosEventChannelAdmin::ConsumerAdmin_ptr for_consumers() = 0;
    virtual ::CosEventChannelAdmin::SupplierAdmin_ptr for_suppliers() = 0;
    virtual void destroy() = 0;

  protected:
    EventChannel() {};
  private:
    EventChannel( const EventChannel& );
    void operator=( const EventChannel& );
};

// Stub for interface EventChannel
class EventChannel_stub:
  virtual public EventChannel
{
  public:
    virtual ~EventChannel_stub();
    ::CosEventChannelAdmin::ConsumerAdmin_ptr for_consumers();
    ::CosEventChannelAdmin::SupplierAdmin_ptr for_suppliers();
    void destroy();

  private:
    void operator=( const EventChannel_stub& );
};

#ifndef MICO_CONF_NO_POA

class EventChannel_stub_clp :
  virtual public EventChannel_stub,
  virtual public PortableServer::StubBase
{
  public:
    EventChannel_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~EventChannel_stub_clp ();
    ::CosEventChannelAdmin::ConsumerAdmin_ptr for_consumers();
    ::CosEventChannelAdmin::SupplierAdmin_ptr for_suppliers();
    void destroy();

  protected:
    EventChannel_stub_clp ();
  private:
    void operator=( const EventChannel_stub_clp & );
};

#endif // MICO_CONF_NO_POA

}


namespace SimpleEventChannelAdmin
{


/*
 * Base class and common definitions for interface EventChannelFactory
 */

class EventChannelFactory : 
  virtual public CORBA::Object
{
  public:
    virtual ~EventChannelFactory();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef EventChannelFactory_ptr _ptr_type;
    typedef EventChannelFactory_var _var_type;
    #endif

    static EventChannelFactory_ptr _narrow( CORBA::Object_ptr obj );
    static EventChannelFactory_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static EventChannelFactory_ptr _duplicate( EventChannelFactory_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static EventChannelFactory_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::CosEventChannelAdmin::EventChannel_ptr create_eventchannel() = 0;

  protected:
    EventChannelFactory() {};
  private:
    EventChannelFactory( const EventChannelFactory& );
    void operator=( const EventChannelFactory& );
};

// Stub for interface EventChannelFactory
class EventChannelFactory_stub:
  virtual public EventChannelFactory
{
  public:
    virtual ~EventChannelFactory_stub();
    ::CosEventChannelAdmin::EventChannel_ptr create_eventchannel();

  private:
    void operator=( const EventChannelFactory_stub& );
};

#ifndef MICO_CONF_NO_POA

class EventChannelFactory_stub_clp :
  virtual public EventChannelFactory_stub,
  virtual public PortableServer::StubBase
{
  public:
    EventChannelFactory_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~EventChannelFactory_stub_clp ();
    ::CosEventChannelAdmin::EventChannel_ptr create_eventchannel();

  protected:
    EventChannelFactory_stub_clp ();
  private:
    void operator=( const EventChannelFactory_stub_clp & );
};

#endif // MICO_CONF_NO_POA

}


#ifndef MICO_CONF_NO_POA



namespace POA_CosEventChannelAdmin
{

class ProxyPushConsumer : 
  virtual public POA_CosEventComm::PushConsumer
{
  public:
    virtual ~ProxyPushConsumer ();
    CosEventChannelAdmin::ProxyPushConsumer_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static ProxyPushConsumer * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual void connect_push_supplier( ::CosEventComm::PushSupplier_ptr push_supplier ) = 0;

  protected:
    ProxyPushConsumer () {};

  private:
    ProxyPushConsumer (const ProxyPushConsumer &);
    void operator= (const ProxyPushConsumer &);
};

class ProxyPullSupplier : 
  virtual public POA_CosEventComm::PullSupplier
{
  public:
    virtual ~ProxyPullSupplier ();
    CosEventChannelAdmin::ProxyPullSupplier_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static ProxyPullSupplier * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual void connect_pull_consumer( ::CosEventComm::PullConsumer_ptr pull_consumer ) = 0;
    virtual void notify( const CORBA::Any& a ) = 0;

  protected:
    ProxyPullSupplier () {};

  private:
    ProxyPullSupplier (const ProxyPullSupplier &);
    void operator= (const ProxyPullSupplier &);
};

class ProxyPullConsumer : 
  virtual public POA_CosEventComm::PullConsumer
{
  public:
    virtual ~ProxyPullConsumer ();
    CosEventChannelAdmin::ProxyPullConsumer_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static ProxyPullConsumer * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual void connect_pull_supplier( ::CosEventComm::PullSupplier_ptr pull_supplier ) = 0;
    virtual void listen() = 0;

  protected:
    ProxyPullConsumer () {};

  private:
    ProxyPullConsumer (const ProxyPullConsumer &);
    void operator= (const ProxyPullConsumer &);
};

class ProxyPushSupplier : 
  virtual public POA_CosEventComm::PushSupplier
{
  public:
    virtual ~ProxyPushSupplier ();
    CosEventChannelAdmin::ProxyPushSupplier_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static ProxyPushSupplier * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual void connect_push_consumer( ::CosEventComm::PushConsumer_ptr push_consumer ) = 0;
    virtual void notify( const CORBA::Any& a ) = 0;

  protected:
    ProxyPushSupplier () {};

  private:
    ProxyPushSupplier (const ProxyPushSupplier &);
    void operator= (const ProxyPushSupplier &);
};

class ConsumerAdmin : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~ConsumerAdmin ();
    CosEventChannelAdmin::ConsumerAdmin_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static ConsumerAdmin * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual ::CosEventChannelAdmin::ProxyPushSupplier_ptr obtain_push_supplier() = 0;
    virtual ::CosEventChannelAdmin::ProxyPullSupplier_ptr obtain_pull_supplier() = 0;

  protected:
    ConsumerAdmin () {};

  private:
    ConsumerAdmin (const ConsumerAdmin &);
    void operator= (const ConsumerAdmin &);
};

class SupplierAdmin : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~SupplierAdmin ();
    CosEventChannelAdmin::SupplierAdmin_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static SupplierAdmin * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual ::CosEventChannelAdmin::ProxyPushConsumer_ptr obtain_push_consumer() = 0;
    virtual ::CosEventChannelAdmin::ProxyPullConsumer_ptr obtain_pull_consumer() = 0;

  protected:
    SupplierAdmin () {};

  private:
    SupplierAdmin (const SupplierAdmin &);
    void operator= (const SupplierAdmin &);
};

class EventChannel : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~EventChannel ();
    CosEventChannelAdmin::EventChannel_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static EventChannel * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual ::CosEventChannelAdmin::ConsumerAdmin_ptr for_consumers() = 0;
    virtual ::CosEventChannelAdmin::SupplierAdmin_ptr for_suppliers() = 0;
    virtual void destroy() = 0;

  protected:
    EventChannel () {};

  private:
    EventChannel (const EventChannel &);
    void operator= (const EventChannel &);
};

}


namespace POA_SimpleEventChannelAdmin
{

class EventChannelFactory : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~EventChannelFactory ();
    SimpleEventChannelAdmin::EventChannelFactory_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static EventChannelFactory * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual ::CosEventChannelAdmin::EventChannel_ptr create_eventchannel() = 0;

  protected:
    EventChannelFactory () {};

  private:
    EventChannelFactory (const EventChannelFactory &);
    void operator= (const EventChannelFactory &);
};

}


#endif // MICO_CONF_NO_POA

extern CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_AlreadyConnected;

extern CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_TypeError;

extern CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_ProxyPushConsumer;

extern CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_ProxyPullSupplier;

extern CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_ProxyPullConsumer;

extern CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_ProxyPushSupplier;

extern CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_ConsumerAdmin;

extern CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_SupplierAdmin;

extern CORBA::StaticTypeInfo *_marshaller_CosEventChannelAdmin_EventChannel;

extern CORBA::StaticTypeInfo *_marshaller_SimpleEventChannelAdmin_EventChannelFactory;

#endif
