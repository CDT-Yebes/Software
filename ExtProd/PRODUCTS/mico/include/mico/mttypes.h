/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __MTTYPES_H__
#define __MTTYPES_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32






namespace MICOMT
{

enum ServerConcurrencyModel {
  THREAD_POOL = 0,
  THREAD_PER_CONNECTION
};

typedef ServerConcurrencyModel& ServerConcurrencyModel_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ServerConcurrencyModel;

enum ClientConcurrencyModel {
  REACTIVE = 0,
  THREADED,
  BLOCKING_THREADED
};

typedef ClientConcurrencyModel& ClientConcurrencyModel_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ClientConcurrencyModel;

}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

void operator<<=( CORBA::Any &a, const ::MICOMT::ServerConcurrencyModel &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, ::MICOMT::ServerConcurrencyModel &e );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_MICOMT_ServerConcurrencyModel;

void operator<<=( CORBA::Any &a, const ::MICOMT::ClientConcurrencyModel &e );

CORBA::Boolean operator>>=( const CORBA::Any &a, ::MICOMT::ClientConcurrencyModel &e );

extern MICO_EXPORT CORBA::StaticTypeInfo *_marshaller_MICOMT_ClientConcurrencyModel;

#endif
