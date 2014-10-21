/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>
#include <mico/throw.h>

#ifndef __COSTIME_H__
#define __COSTIME_H__






namespace CosTime
{

class UTO;
typedef UTO *UTO_ptr;
typedef UTO_ptr UTORef;
typedef ObjVar< UTO > UTO_var;
typedef ObjOut< UTO > UTO_out;

class TIO;
typedef TIO *TIO_ptr;
typedef TIO_ptr TIORef;
typedef ObjVar< TIO > TIO_var;
typedef ObjOut< TIO > TIO_out;

class TimeService;
typedef TimeService *TimeService_ptr;
typedef TimeService_ptr TimeServiceRef;
typedef ObjVar< TimeService > TimeService_var;
typedef ObjOut< TimeService > TimeService_out;

}



#include <mico/timebase.h>



namespace CosTime
{

enum TimeComparison {
  TCEqualTo = 0,
  TCLessThan,
  TCGreaterThan,
  TCIndeterminate
};

typedef TimeComparison& TimeComparison_out;

enum ComparisonType {
  IntervalC = 0,
  MidC
};

typedef ComparisonType& ComparisonType_out;

enum OverlapType {
  OTContainer = 0,
  OTContained,
  OTOverlap,
  OTNoOverlap
};

typedef OverlapType& OverlapType_out;

struct TimeUnavailable : public CORBA::UserException {
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  TimeUnavailable();
  ~TimeUnavailable();
  TimeUnavailable( const TimeUnavailable& s );
  TimeUnavailable& operator=( const TimeUnavailable& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS


  #ifdef HAVE_STD_EH
  TimeUnavailable *operator->() { return this; }
  TimeUnavailable& operator*() { return *this; }
  operator TimeUnavailable*() { return this; }
  #endif // HAVE_STD_EH

  void _throwit() const;
  const char *_repoid() const;
  void _encode( CORBA::DataEncoder &en ) const;
  void _encode_any( CORBA::Any &a ) const;
  CORBA::Exception *_clone() const;
  static TimeUnavailable *_downcast( CORBA::Exception *ex );
  static const TimeUnavailable *_downcast( const CORBA::Exception *ex );
};

#ifdef HAVE_STD_EH
typedef TimeUnavailable TimeUnavailable_catch;
#else
typedef ExceptVar< TimeUnavailable > TimeUnavailable_var;
typedef TVarOut< TimeUnavailable > TimeUnavailable_out;
typedef TimeUnavailable_var TimeUnavailable_catch;
#endif // HAVE_STD_EH


/*
 * Base class and common definitions for interface UTO
 */

class UTO : 
  virtual public CORBA::Object
{
  public:
    virtual ~UTO();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef UTO_ptr _ptr_type;
    typedef UTO_var _var_type;
    #endif

    static UTO_ptr _narrow( CORBA::Object_ptr obj );
    static UTO_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static UTO_ptr _duplicate( UTO_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static UTO_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::TimeBase::TimeT time() = 0;
    virtual ::TimeBase::InaccuracyT inaccuracy() = 0;
    virtual ::TimeBase::TdfT tdf() = 0;
    virtual ::TimeBase::UtcT utc_time() = 0;

    virtual ::CosTime::UTO_ptr absolute_time() = 0;
    virtual ::CosTime::TimeComparison compare_time( ::CosTime::ComparisonType comparison_type, ::CosTime::UTO_ptr uto ) = 0;
    virtual ::CosTime::TIO_ptr time_to_interval( ::CosTime::UTO_ptr uto ) = 0;
    virtual ::CosTime::TIO_ptr interval() = 0;
    virtual void destroy() = 0;

  protected:
    UTO() {};
  private:
    UTO( const UTO& );
    void operator=( const UTO& );
};

// Stub for interface UTO
class UTO_stub:
  virtual public UTO
{
  public:
    virtual ~UTO_stub();
    ::TimeBase::TimeT time();
    ::TimeBase::InaccuracyT inaccuracy();
    ::TimeBase::TdfT tdf();
    ::TimeBase::UtcT utc_time();

    ::CosTime::UTO_ptr absolute_time();
    ::CosTime::TimeComparison compare_time( ::CosTime::ComparisonType comparison_type, ::CosTime::UTO_ptr uto );
    ::CosTime::TIO_ptr time_to_interval( ::CosTime::UTO_ptr uto );
    ::CosTime::TIO_ptr interval();
    void destroy();

  private:
    void operator=( const UTO_stub& );
};

#ifndef MICO_CONF_NO_POA

class UTO_stub_clp :
  virtual public UTO_stub,
  virtual public PortableServer::StubBase
{
  public:
    UTO_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~UTO_stub_clp ();
    ::TimeBase::TimeT time();
    ::TimeBase::InaccuracyT inaccuracy();
    ::TimeBase::TdfT tdf();
    ::TimeBase::UtcT utc_time();

    ::CosTime::UTO_ptr absolute_time();
    ::CosTime::TimeComparison compare_time( ::CosTime::ComparisonType comparison_type, ::CosTime::UTO_ptr uto );
    ::CosTime::TIO_ptr time_to_interval( ::CosTime::UTO_ptr uto );
    ::CosTime::TIO_ptr interval();
    void destroy();

  protected:
    UTO_stub_clp ();
  private:
    void operator=( const UTO_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface TIO
 */

class TIO : 
  virtual public CORBA::Object
{
  public:
    virtual ~TIO();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TIO_ptr _ptr_type;
    typedef TIO_var _var_type;
    #endif

    static TIO_ptr _narrow( CORBA::Object_ptr obj );
    static TIO_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TIO_ptr _duplicate( TIO_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TIO_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::TimeBase::IntervalT time_interval() = 0;

    virtual ::CosTime::OverlapType spans( ::CosTime::UTO_ptr time, ::CosTime::TIO_out overlap ) = 0;
    virtual ::CosTime::OverlapType overlaps( ::CosTime::TIO_ptr interval, ::CosTime::TIO_out overlap ) = 0;
    virtual ::CosTime::UTO_ptr time() = 0;
    virtual void destroy() = 0;

  protected:
    TIO() {};
  private:
    TIO( const TIO& );
    void operator=( const TIO& );
};

// Stub for interface TIO
class TIO_stub:
  virtual public TIO
{
  public:
    virtual ~TIO_stub();
    ::TimeBase::IntervalT time_interval();

    ::CosTime::OverlapType spans( ::CosTime::UTO_ptr time, ::CosTime::TIO_out overlap );
    ::CosTime::OverlapType overlaps( ::CosTime::TIO_ptr interval, ::CosTime::TIO_out overlap );
    ::CosTime::UTO_ptr time();
    void destroy();

  private:
    void operator=( const TIO_stub& );
};

#ifndef MICO_CONF_NO_POA

class TIO_stub_clp :
  virtual public TIO_stub,
  virtual public PortableServer::StubBase
{
  public:
    TIO_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~TIO_stub_clp ();
    ::TimeBase::IntervalT time_interval();

    ::CosTime::OverlapType spans( ::CosTime::UTO_ptr time, ::CosTime::TIO_out overlap );
    ::CosTime::OverlapType overlaps( ::CosTime::TIO_ptr interval, ::CosTime::TIO_out overlap );
    ::CosTime::UTO_ptr time();
    void destroy();

  protected:
    TIO_stub_clp ();
  private:
    void operator=( const TIO_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface TimeService
 */

class TimeService : 
  virtual public CORBA::Object
{
  public:
    virtual ~TimeService();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TimeService_ptr _ptr_type;
    typedef TimeService_var _var_type;
    #endif

    static TimeService_ptr _narrow( CORBA::Object_ptr obj );
    static TimeService_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TimeService_ptr _duplicate( TimeService_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TimeService_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::CosTime::UTO_ptr universal_time() = 0;
    virtual ::CosTime::UTO_ptr secure_universal_time() = 0;
    virtual ::CosTime::UTO_ptr new_universal_time( ::TimeBase::TimeT time, ::TimeBase::InaccuracyT inaccuracy, ::TimeBase::TdfT tdf ) = 0;
    virtual ::CosTime::UTO_ptr uto_from_utc( const ::TimeBase::UtcT& utc ) = 0;
    virtual ::CosTime::TIO_ptr new_interval( ::TimeBase::TimeT lower, ::TimeBase::TimeT upper ) = 0;

  protected:
    TimeService() {};
  private:
    TimeService( const TimeService& );
    void operator=( const TimeService& );
};

// Stub for interface TimeService
class TimeService_stub:
  virtual public TimeService
{
  public:
    virtual ~TimeService_stub();
    ::CosTime::UTO_ptr universal_time();
    ::CosTime::UTO_ptr secure_universal_time();
    ::CosTime::UTO_ptr new_universal_time( ::TimeBase::TimeT time, ::TimeBase::InaccuracyT inaccuracy, ::TimeBase::TdfT tdf );
    ::CosTime::UTO_ptr uto_from_utc( const ::TimeBase::UtcT& utc );
    ::CosTime::TIO_ptr new_interval( ::TimeBase::TimeT lower, ::TimeBase::TimeT upper );

  private:
    void operator=( const TimeService_stub& );
};

#ifndef MICO_CONF_NO_POA

class TimeService_stub_clp :
  virtual public TimeService_stub,
  virtual public PortableServer::StubBase
{
  public:
    TimeService_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~TimeService_stub_clp ();
    ::CosTime::UTO_ptr universal_time();
    ::CosTime::UTO_ptr secure_universal_time();
    ::CosTime::UTO_ptr new_universal_time( ::TimeBase::TimeT time, ::TimeBase::InaccuracyT inaccuracy, ::TimeBase::TdfT tdf );
    ::CosTime::UTO_ptr uto_from_utc( const ::TimeBase::UtcT& utc );
    ::CosTime::TIO_ptr new_interval( ::TimeBase::TimeT lower, ::TimeBase::TimeT upper );

  protected:
    TimeService_stub_clp ();
  private:
    void operator=( const TimeService_stub_clp & );
};

#endif // MICO_CONF_NO_POA

}


#ifndef MICO_CONF_NO_POA



namespace POA_CosTime
{

class UTO : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~UTO ();
    CosTime::UTO_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static UTO * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual ::TimeBase::TimeT time() = 0;
    virtual ::TimeBase::InaccuracyT inaccuracy() = 0;
    virtual ::TimeBase::TdfT tdf() = 0;
    virtual ::TimeBase::UtcT utc_time() = 0;

    virtual ::CosTime::UTO_ptr absolute_time() = 0;
    virtual ::CosTime::TimeComparison compare_time( ::CosTime::ComparisonType comparison_type, ::CosTime::UTO_ptr uto ) = 0;
    virtual ::CosTime::TIO_ptr time_to_interval( ::CosTime::UTO_ptr uto ) = 0;
    virtual ::CosTime::TIO_ptr interval() = 0;
    virtual void destroy() = 0;

  protected:
    UTO () {};

  private:
    UTO (const UTO &);
    void operator= (const UTO &);
};

class TIO : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~TIO ();
    CosTime::TIO_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static TIO * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual ::TimeBase::IntervalT time_interval() = 0;

    virtual ::CosTime::OverlapType spans( ::CosTime::UTO_ptr time, ::CosTime::TIO_out overlap ) = 0;
    virtual ::CosTime::OverlapType overlaps( ::CosTime::TIO_ptr interval, ::CosTime::TIO_out overlap ) = 0;
    virtual ::CosTime::UTO_ptr time() = 0;
    virtual void destroy() = 0;

  protected:
    TIO () {};

  private:
    TIO (const TIO &);
    void operator= (const TIO &);
};

class TimeService : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~TimeService ();
    CosTime::TimeService_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static TimeService * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual ::CosTime::UTO_ptr universal_time() = 0;
    virtual ::CosTime::UTO_ptr secure_universal_time() = 0;
    virtual ::CosTime::UTO_ptr new_universal_time( ::TimeBase::TimeT time, ::TimeBase::InaccuracyT inaccuracy, ::TimeBase::TdfT tdf ) = 0;
    virtual ::CosTime::UTO_ptr uto_from_utc( const ::TimeBase::UtcT& utc ) = 0;
    virtual ::CosTime::TIO_ptr new_interval( ::TimeBase::TimeT lower, ::TimeBase::TimeT upper ) = 0;

  protected:
    TimeService () {};

  private:
    TimeService (const TimeService &);
    void operator= (const TimeService &);
};

}


#endif // MICO_CONF_NO_POA

extern CORBA::StaticTypeInfo *_marshaller_CosTime_TimeComparison;

extern CORBA::StaticTypeInfo *_marshaller_CosTime_ComparisonType;

extern CORBA::StaticTypeInfo *_marshaller_CosTime_OverlapType;

extern CORBA::StaticTypeInfo *_marshaller_CosTime_TimeUnavailable;

extern CORBA::StaticTypeInfo *_marshaller_CosTime_UTO;

extern CORBA::StaticTypeInfo *_marshaller_CosTime_TIO;

extern CORBA::StaticTypeInfo *_marshaller_CosTime_TimeService;

#endif
