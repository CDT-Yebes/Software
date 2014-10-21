// -*- c++ -*-
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


#ifndef __SL3AQARGS_IMPL_H__
#define __SL3AQARGS_IMPL_H__

#include <mico/security/sl3aqargs.h>

namespace MICOSL3_SL3AQArgs
{
    class Argument_impl
	: virtual public SL3AQArgs::Argument,
	  virtual public CORBA::LocalObject
    {
    public:
	Argument_impl(const char* type);

	virtual char*
	type();

    protected:
	CORBA::String_var type_;
    };

    class ArgBuilder_impl
	: virtual public SL3AQArgs::ArgBuilder,
	  virtual public CORBA::LocalObject
    {
    public:
	ArgBuilder_impl(SL3CM::CredentialsUsage usage);

	virtual void
	add_arg(SL3AQArgs::Argument_ptr arg);

	virtual void
	add_args(const SL3AQArgs::ArgumentSeq& args);

	virtual SL3AQArgs::Argument_ptr
	reap_args();

	virtual void
	destroy();

    protected:
	SL3CM::CredentialsUsage
	usage();

	void
	check();

    private:
	CORBA::Boolean destroyed_;
	SL3AQArgs::ArgumentSeq arguments_;
	SL3CM::CredentialsUsage usage_;
    };
} // MICOSL3_SL3AQArgs
    
#endif // __SL3AQARGS_P_IMPL_H__

