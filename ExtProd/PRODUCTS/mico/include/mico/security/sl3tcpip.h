/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __SL3TCPIP_H__
#define __SL3TCPIP_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32




namespace SL3TCPIP
{

class TCPIPArgBuilder;
typedef TCPIPArgBuilder *TCPIPArgBuilder_ptr;
typedef TCPIPArgBuilder_ptr TCPIPArgBuilderRef;
typedef ObjVar< TCPIPArgBuilder > TCPIPArgBuilder_var;
typedef ObjOut< TCPIPArgBuilder > TCPIPArgBuilder_out;

}






namespace SL3TCPIP
{


/*
 * Base class and common definitions for local interface TCPIPArgBuilder
 */

class TCPIPArgBuilder : 
  virtual public ::SL3AQArgs::ArgBuilder
{
  public:
    virtual ~TCPIPArgBuilder();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef TCPIPArgBuilder_ptr _ptr_type;
    typedef TCPIPArgBuilder_var _var_type;
    #endif

    static TCPIPArgBuilder_ptr _narrow( CORBA::Object_ptr obj );
    static TCPIPArgBuilder_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static TCPIPArgBuilder_ptr _duplicate( TCPIPArgBuilder_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static TCPIPArgBuilder_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual void add_CSIv1_support( CORBA::Boolean support ) = 0;
    virtual void add_CSIv2_support( CORBA::Boolean support ) = 0;
    virtual void add_tcpip_initiator_options( const char* bind, CORBA::Long low_port, CORBA::Long high_port, CORBA::Long timeout ) = 0;
    virtual void add_tcpip_acceptor_options( const ::CORBA::StringSeq& hosts, const char* bind, CORBA::Long low_port, CORBA::Long high_port, CORBA::Long backlog, CORBA::Boolean numeric ) = 0;
    virtual void add_accepting_context_observer( ::SL3OM::AcceptingContextObserver_ptr observer ) = 0;
    virtual void add_initiating_context_observer( ::SL3OM::InitiatingContextObserver_ptr observer ) = 0;
    virtual void add_credentials_observer( ::SL3OM::CredentialsObserver_ptr observer ) = 0;

  protected:
    TCPIPArgBuilder() {};
  private:
    TCPIPArgBuilder( const TCPIPArgBuilder& );
    void operator=( const TCPIPArgBuilder& );
};


}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

#endif
