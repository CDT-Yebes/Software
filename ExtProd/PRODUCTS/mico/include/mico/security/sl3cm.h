/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>

#ifndef __SL3CM_H__
#define __SL3CM_H__


#ifdef _WIN32
#ifdef BUILD_MICO_DLL
#define MICO_EXPORT /**/
#else // BUILD_MICO_DLL
#define MICO_EXPORT __declspec(dllimport)
#endif // BUILD_MICO_DLL
#else // _WIN32
#define MICO_EXPORT /**/
#endif // _WIN32






namespace SL3CM
{

typedef CORBA::ULong CredentialsType;
typedef CredentialsType& CredentialsType_out;
extern MICO_EXPORT CORBA::TypeCodeConst _tc_CredentialsType;

const CredentialsType CT_OwnCredentials = 0;
const CredentialsType CT_ClientCredentials = 1;
const CredentialsType CT_TargetCredentials = 2;
typedef CORBA::Long CredentialsState;
typedef CredentialsState& CredentialsState_out;
extern MICO_EXPORT CORBA::TypeCodeConst _tc_CredentialsState;

const CredentialsState CS_Invalid = -3;
const CredentialsState CS_Expired = -2;
const CredentialsState CS_PendingRelease = -1;
const CredentialsState CS_Initialized = 0;
const CredentialsState CS_Valid = 1;
typedef char* CredentialsId;
typedef CORBA::String_var CredentialsId_var;
typedef CORBA::String_out CredentialsId_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_CredentialsId;

typedef StringSequenceTmpl<CORBA::String_var> CredentialsIdList;
typedef TSeqVar< StringSequenceTmpl<CORBA::String_var> > CredentialsIdList_var;
typedef TSeqOut< StringSequenceTmpl<CORBA::String_var> > CredentialsIdList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_CredentialsIdList;

typedef char* ContextId;
typedef CORBA::String_var ContextId_var;
typedef CORBA::String_out ContextId_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ContextId;

typedef StringSequenceTmpl<CORBA::String_var> ContextIdList;
typedef TSeqVar< StringSequenceTmpl<CORBA::String_var> > ContextIdList_var;
typedef TSeqOut< StringSequenceTmpl<CORBA::String_var> > ContextIdList_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_ContextIdList;

typedef CORBA::ULong CredentialsUsage;
typedef CredentialsUsage& CredentialsUsage_out;
extern MICO_EXPORT CORBA::TypeCodeConst _tc_CredentialsUsage;

const CredentialsUsage CU_Indefinite = 1;
const CredentialsUsage CU_None = 2;
const CredentialsUsage CU_AcceptOnly = 3;
const CredentialsUsage CU_InitiateOnly = 4;
const CredentialsUsage CU_InitiateAndAccept = 5;
typedef CORBA::ULong CredsDirective;
typedef CredsDirective& CredsDirective_out;
extern MICO_EXPORT CORBA::TypeCodeConst _tc_CredsDirective;

const CredsDirective CD_Default = 0;
const CredsDirective CD_InvokeTarget = 1;
const CredsDirective CD_EndorseTarget = 2;
const CredsDirective CD_EmbodyTarget = 3;
typedef CORBA::Long FeatureDirective;
typedef FeatureDirective& FeatureDirective_out;
extern MICO_EXPORT CORBA::TypeCodeConst _tc_FeatureDirective;

const FeatureDirective FD_DoNotUse = -2;
const FeatureDirective FD_DoNotUseIfPossible = -1;
const FeatureDirective FD_UseDefault = 0;
const FeatureDirective FD_UseIfPossible = 1;
const FeatureDirective FD_Use = 2;
typedef char* AcquisitionArgumentType;
typedef CORBA::String_var AcquisitionArgumentType_var;
typedef CORBA::String_out AcquisitionArgumentType_out;

extern MICO_EXPORT CORBA::TypeCodeConst _tc_AcquisitionArgumentType;

}


#ifndef MICO_CONF_NO_POA

#endif // MICO_CONF_NO_POA

void operator<<=( CORBA::Any &_a, const StringSequenceTmpl<CORBA::String_var> &_s );
void operator<<=( CORBA::Any &_a, StringSequenceTmpl<CORBA::String_var> *_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, StringSequenceTmpl<CORBA::String_var> &_s );
CORBA::Boolean operator>>=( const CORBA::Any &_a, const StringSequenceTmpl<CORBA::String_var> *&_s );

#endif
