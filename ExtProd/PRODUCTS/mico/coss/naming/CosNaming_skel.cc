/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CosNaming.h>

//--------------------------------------------------------
//  Implementation of skeletons
//--------------------------------------------------------

// PortableServer Skeleton Class for interface CosNaming::BindingIterator
POA_CosNaming::BindingIterator::~BindingIterator()
{
}

::CosNaming::BindingIterator_ptr
POA_CosNaming::BindingIterator::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosNaming::BindingIterator::_narrow (obj);
}

CORBA::Boolean
POA_CosNaming::BindingIterator::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosNaming/BindingIterator:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosNaming::BindingIterator::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosNaming/BindingIterator:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosNaming::BindingIterator::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosNaming/BindingIterator:1.0");
}

CORBA::Object_ptr
POA_CosNaming::BindingIterator::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosNaming::BindingIterator_stub_clp (poa, obj);
}

bool
POA_CosNaming::BindingIterator::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "next_one" ) == 0 ) {
      ::CosNaming::Binding* _par_b;
      CORBA::StaticAny _sa_b( _marshaller_CosNaming_Binding );

      CORBA::Boolean _res;
      CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
      __req->add_out_arg( &_sa_b );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = next_one( _par_b );
      _sa_b.value( _marshaller_CosNaming_Binding, _par_b );
      __req->write_results();
      delete _par_b;
      return true;
    }
    if( strcmp( __req->op_name(), "next_n" ) == 0 ) {
      CORBA::ULong _par_how_many;
      CORBA::StaticAny _sa_how_many( CORBA::_stc_ulong, &_par_how_many );
      ::CosNaming::BindingList* _par_bl;
      CORBA::StaticAny _sa_bl( _marshaller__seq_CosNaming_Binding );

      CORBA::Boolean _res;
      CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
      __req->add_in_arg( &_sa_how_many );
      __req->add_out_arg( &_sa_bl );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = next_n( _par_how_many, _par_bl );
      _sa_bl.value( _marshaller__seq_CosNaming_Binding, _par_bl );
      __req->write_results();
      delete _par_bl;
      return true;
    }
    if( strcmp( __req->op_name(), "destroy" ) == 0 ) {

      if( !__req->read_args() )
        return true;

      destroy();
      __req->write_results();
      return true;
    }
  #ifdef HAVE_EXCEPTIONS
  } catch( CORBA::SystemException_catch &_ex ) {
    __req->set_exception( _ex->_clone() );
    __req->write_results();
    return true;
  } catch( ... ) {
    CORBA::UNKNOWN _ex (CORBA::OMGVMCID | 1, CORBA::COMPLETED_MAYBE);
    __req->set_exception (_ex->_clone());
    __req->write_results ();
    return true;
  }
  #endif

  return false;
}

void
POA_CosNaming::BindingIterator::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface CosNaming::NamingContext
POA_CosNaming::NamingContext::~NamingContext()
{
}

::CosNaming::NamingContext_ptr
POA_CosNaming::NamingContext::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosNaming::NamingContext::_narrow (obj);
}

CORBA::Boolean
POA_CosNaming::NamingContext::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosNaming/NamingContext:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosNaming::NamingContext::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosNaming/NamingContext:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosNaming::NamingContext::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosNaming/NamingContext:1.0");
}

CORBA::Object_ptr
POA_CosNaming::NamingContext::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosNaming::NamingContext_stub_clp (poa, obj);
}

bool
POA_CosNaming::NamingContext::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    switch (mico_string_hash (__req->op_name(), 17)) {
    case 0:
      if( strcmp( __req->op_name(), "bind_new_context" ) == 0 ) {
        ::CosNaming::Name _par_n;
        CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );

        ::CosNaming::NamingContext_ptr _res;
        CORBA::StaticAny __res( _marshaller_CosNaming_NamingContext, &_res );
        __req->add_in_arg( &_sa_n );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          _res = bind_new_context( _par_n );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::CosNaming::NamingContext::NotFound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::AlreadyBound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::CannotProceed_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::InvalidName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        CORBA::release( _res );
        return true;
      }
      break;
    case 1:
      if( strcmp( __req->op_name(), "rebind" ) == 0 ) {
        ::CosNaming::Name _par_n;
        CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );
        CORBA::Object_var _par_obj;
        CORBA::StaticAny _sa_obj( CORBA::_stc_Object, &_par_obj._for_demarshal() );

        __req->add_in_arg( &_sa_n );
        __req->add_in_arg( &_sa_obj );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          rebind( _par_n, _par_obj.inout() );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::CosNaming::NamingContext::NotFound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::CannotProceed_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::InvalidName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      break;
    case 3:
      if( strcmp( __req->op_name(), "rebind_context" ) == 0 ) {
        ::CosNaming::Name _par_n;
        CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );
        ::CosNaming::NamingContext_var _par_nc;
        CORBA::StaticAny _sa_nc( _marshaller_CosNaming_NamingContext, &_par_nc._for_demarshal() );

        __req->add_in_arg( &_sa_n );
        __req->add_in_arg( &_sa_nc );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          rebind_context( _par_n, _par_nc.inout() );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::CosNaming::NamingContext::NotFound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::CannotProceed_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::InvalidName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      break;
    case 7:
      if( strcmp( __req->op_name(), "unbind" ) == 0 ) {
        ::CosNaming::Name _par_n;
        CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );

        __req->add_in_arg( &_sa_n );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          unbind( _par_n );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::CosNaming::NamingContext::NotFound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::CannotProceed_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::InvalidName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      break;
    case 13:
      if( strcmp( __req->op_name(), "bind_context" ) == 0 ) {
        ::CosNaming::Name _par_n;
        CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );
        ::CosNaming::NamingContext_var _par_nc;
        CORBA::StaticAny _sa_nc( _marshaller_CosNaming_NamingContext, &_par_nc._for_demarshal() );

        __req->add_in_arg( &_sa_n );
        __req->add_in_arg( &_sa_nc );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          bind_context( _par_n, _par_nc.inout() );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::CosNaming::NamingContext::NotFound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::CannotProceed_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::InvalidName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::AlreadyBound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      break;
    case 14:
      if( strcmp( __req->op_name(), "bind" ) == 0 ) {
        ::CosNaming::Name _par_n;
        CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );
        CORBA::Object_var _par_obj;
        CORBA::StaticAny _sa_obj( CORBA::_stc_Object, &_par_obj._for_demarshal() );

        __req->add_in_arg( &_sa_n );
        __req->add_in_arg( &_sa_obj );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          bind( _par_n, _par_obj.inout() );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::CosNaming::NamingContext::NotFound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::CannotProceed_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::InvalidName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::AlreadyBound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "resolve" ) == 0 ) {
        ::CosNaming::Name _par_n;
        CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );

        CORBA::Object_ptr _res;
        CORBA::StaticAny __res( CORBA::_stc_Object, &_res );
        __req->add_in_arg( &_sa_n );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          _res = resolve( _par_n );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::CosNaming::NamingContext::NotFound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::CannotProceed_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::InvalidName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        CORBA::release( _res );
        return true;
      }
      if( strcmp( __req->op_name(), "new_context" ) == 0 ) {
        ::CosNaming::NamingContext_ptr _res;
        CORBA::StaticAny __res( _marshaller_CosNaming_NamingContext, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = new_context();
        __req->write_results();
        CORBA::release( _res );
        return true;
      }
      break;
    case 15:
      if( strcmp( __req->op_name(), "destroy" ) == 0 ) {

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          destroy();
        #ifdef HAVE_EXCEPTIONS
        } catch( ::CosNaming::NamingContext::NotEmpty_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "list" ) == 0 ) {
        CORBA::ULong _par_how_many;
        CORBA::StaticAny _sa_how_many( CORBA::_stc_ulong, &_par_how_many );
        ::CosNaming::BindingList* _par_bl;
        CORBA::StaticAny _sa_bl( _marshaller__seq_CosNaming_Binding );
        ::CosNaming::BindingIterator_ptr _par_bi;
        CORBA::StaticAny _sa_bi( _marshaller_CosNaming_BindingIterator, &_par_bi );

        __req->add_in_arg( &_sa_how_many );
        __req->add_out_arg( &_sa_bl );
        __req->add_out_arg( &_sa_bi );

        if( !__req->read_args() )
          return true;

        list( _par_how_many, _par_bl, _par_bi );
        _sa_bl.value( _marshaller__seq_CosNaming_Binding, _par_bl );
        __req->write_results();
        delete _par_bl;
        CORBA::release( _par_bi );
        return true;
      }
      break;
    }
  #ifdef HAVE_EXCEPTIONS
  } catch( CORBA::SystemException_catch &_ex ) {
    __req->set_exception( _ex->_clone() );
    __req->write_results();
    return true;
  } catch( ... ) {
    CORBA::UNKNOWN _ex (CORBA::OMGVMCID | 1, CORBA::COMPLETED_MAYBE);
    __req->set_exception (_ex->_clone());
    __req->write_results ();
    return true;
  }
  #endif

  return false;
}

void
POA_CosNaming::NamingContext::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface CosNaming::NamingContextExt
POA_CosNaming::NamingContextExt::~NamingContextExt()
{
}

::CosNaming::NamingContextExt_ptr
POA_CosNaming::NamingContextExt::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::CosNaming::NamingContextExt::_narrow (obj);
}

CORBA::Boolean
POA_CosNaming::NamingContextExt::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:omg.org/CosNaming/NamingContextExt:1.0") == 0) {
    return TRUE;
  }
  if (POA_CosNaming::NamingContext::_is_a (repoid)) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_CosNaming::NamingContextExt::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:omg.org/CosNaming/NamingContextExt:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_CosNaming::NamingContextExt::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:omg.org/CosNaming/NamingContextExt:1.0");
}

CORBA::Object_ptr
POA_CosNaming::NamingContextExt::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::CosNaming::NamingContextExt_stub_clp (poa, obj);
}

bool
POA_CosNaming::NamingContextExt::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    switch (mico_string_hash (__req->op_name(), 7)) {
    case 0:
      if( strcmp( __req->op_name(), "to_string" ) == 0 ) {
        ::CosNaming::Name _par_n;
        CORBA::StaticAny _sa_n( _marshaller__seq_CosNaming_NameComponent, &_par_n );

        ::CosNaming::NamingContextExt::StringName _res;
        CORBA::StaticAny __res( CORBA::_stc_string, &_res );
        __req->add_in_arg( &_sa_n );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          _res = to_string( _par_n );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::CosNaming::NamingContext::InvalidName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        CORBA::string_free( _res );
        return true;
      }
      if( strcmp( __req->op_name(), "resolve_str" ) == 0 ) {
        ::CosNaming::NamingContextExt::StringName_var _par_n;
        CORBA::StaticAny _sa_n( CORBA::_stc_string, &_par_n._for_demarshal() );

        CORBA::Object_ptr _res;
        CORBA::StaticAny __res( CORBA::_stc_Object, &_res );
        __req->add_in_arg( &_sa_n );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          _res = resolve_str( _par_n.inout() );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::CosNaming::NamingContext::NotFound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::CannotProceed_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::InvalidName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::AlreadyBound_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        CORBA::release( _res );
        return true;
      }
      break;
    case 1:
      if( strcmp( __req->op_name(), "to_name" ) == 0 ) {
        ::CosNaming::NamingContextExt::StringName_var _par_sn;
        CORBA::StaticAny _sa_sn( CORBA::_stc_string, &_par_sn._for_demarshal() );

        ::CosNaming::Name* _res;
        CORBA::StaticAny __res( _marshaller__seq_CosNaming_NameComponent );
        __req->add_in_arg( &_sa_sn );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          _res = to_name( _par_sn.inout() );
          __res.value( _marshaller__seq_CosNaming_NameComponent, _res );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::CosNaming::NamingContext::InvalidName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        delete _res;
        return true;
      }
      break;
    case 3:
      if( strcmp( __req->op_name(), "to_url" ) == 0 ) {
        ::CosNaming::NamingContextExt::Address_var _par_addr;
        CORBA::StaticAny _sa_addr( CORBA::_stc_string, &_par_addr._for_demarshal() );
        ::CosNaming::NamingContextExt::StringName_var _par_sn;
        CORBA::StaticAny _sa_sn( CORBA::_stc_string, &_par_sn._for_demarshal() );

        ::CosNaming::NamingContextExt::URLString _res;
        CORBA::StaticAny __res( CORBA::_stc_string, &_res );
        __req->add_in_arg( &_sa_addr );
        __req->add_in_arg( &_sa_sn );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        #ifdef HAVE_EXCEPTIONS
        try {
        #endif
          _res = to_url( _par_addr.inout(), _par_sn.inout() );
        #ifdef HAVE_EXCEPTIONS
        } catch( ::CosNaming::NamingContextExt::InvalidAddress_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        } catch( ::CosNaming::NamingContext::InvalidName_catch &_ex ) {
          __req->set_exception( _ex->_clone() );
          __req->write_results();
          return true;
        }
        #endif
        __req->write_results();
        CORBA::string_free( _res );
        return true;
      }
      break;
    }
  #ifdef HAVE_EXCEPTIONS
  } catch( CORBA::SystemException_catch &_ex ) {
    __req->set_exception( _ex->_clone() );
    __req->write_results();
    return true;
  } catch( ... ) {
    CORBA::UNKNOWN _ex (CORBA::OMGVMCID | 1, CORBA::COMPLETED_MAYBE);
    __req->set_exception (_ex->_clone());
    __req->write_results ();
    return true;
  }
  #endif

  if (POA_CosNaming::NamingContext::dispatch (__req)) {
    return true;
  }

  return false;
}

void
POA_CosNaming::NamingContextExt::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}

