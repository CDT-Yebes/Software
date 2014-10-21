//
//  MICO SL3 --- an Open Source SL3 implementation
//  Copyright (C) 2002, 2003 ObjectSecurity Ltd.
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Library General Public
//  License as published by the Free Software Foundation; either
//  version 2 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Library General Public License for more details.
//
//  You should have received a copy of the GNU Library General Public
//  License along with this library; if not, write to the Free
//  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

//  Send comments and/or bug reports to:
//                 micosec@objectsecurity.com
//

//  Written by Karel Gardas, <kgardas@objectsecurity.com>


#ifdef FAST_PCH
#include "csiv2sl3_pch.h"
#endif // FAST_PCH
#ifdef __COMO__
#pragma hdrstop
#endif // __COMO__

#ifndef FAST_PCH
#include <mico/security/sl3aqargs_impl.h>
#include <mico/security/sl3aqargs_p_impl.h>
#include <mico/util.h>
#endif // FAST_PCH

using namespace std;
using namespace CORBA;
using namespace SL3AQArgs;
using namespace SL3CM;

//
// Argument_impl
//

MICOSL3_SL3AQArgs::Argument_impl::Argument_impl(const char* type)
    : type_(type)
{
}

char*
MICOSL3_SL3AQArgs::Argument_impl::type()
{
    return CORBA::string_dup(type_.in());
}


//
// ArgBuilder_impl
//

MICOSL3_SL3AQArgs::ArgBuilder_impl::ArgBuilder_impl
(CredentialsUsage usage)
    : destroyed_(FALSE), usage_(usage)
{
    arguments_.length(0);
}


void
MICOSL3_SL3AQArgs::ArgBuilder_impl::add_arg(SL3AQArgs::Argument_ptr arg)
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3AQArgs: ArgBuilder_impl::add_arg: " << arg->type() << endl;
    }
    this->check();
    ULong len = arguments_.length();
    arguments_.length(len + 1);
    arguments_[len] = SL3AQArgs::Argument::_duplicate(arg);
}


void
MICOSL3_SL3AQArgs::ArgBuilder_impl::add_args(const ArgumentSeq& args)
{
    this->check();
    for (ULong i = 0; i < args.length(); i++) {
	this->add_arg(args[i].in());
    }
}


SL3AQArgs::Argument_ptr
MICOSL3_SL3AQArgs::ArgBuilder_impl::reap_args()
{
    if (MICO::Logger::IsLogged(MICO::Logger::Security)) {
	MICOMT::AutoDebugLock lock;
	MICO::Logger::Stream(MICO::Logger::Security)
	    << "SL3AQArgs: ArgBuilder_impl::reap_args()" << endl;
    }
    this->check();
    destroyed_ = TRUE;
    Argument_ptr result = new ArgsHolder_impl(usage_, arguments_);
    return result;
}


void
MICOSL3_SL3AQArgs::ArgBuilder_impl::destroy()
{
    this->check();
    destroyed_ = TRUE;
}


CredentialsUsage
MICOSL3_SL3AQArgs::ArgBuilder_impl::usage()
{
    return usage_;
}


void
MICOSL3_SL3AQArgs::ArgBuilder_impl::check()
{
    if (destroyed_)
	mico_throw(CORBA::BAD_INV_ORDER());
}

