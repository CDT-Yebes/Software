//
//  MICO --- an Open Source CORBA implementation
//  Copyright (C) 2007, 2008 ObjectSecurity Ltd.
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

//  For more information, visit the MICO Home Page at
//  http://www.mico.org/
//

//  Written by Karel Gardas, <kgardas@objectsecurity.com>

#ifdef FAST_PCH
#include "orb_pch.h"
#endif // FAST_PCH
#ifdef __COMO__
#pragma hdrstop
#endif // __COMO__

#ifndef FAST_PCH
/*
#define MICO_CONF_IMR
#define MICO_CONF_IR
#define MICO_CONF_POA
#define MICO_CONF_INTERCEPT

#include <CORBA-SMALL.h>
*/
#include <CORBA.h>
#include <mico/impl.h>
#include <mico/throw.h>
#include <mico/messaging_impl.h>

#endif // FAST_PCH


MICO::RelativeRoundtripTimeoutPolicy_impl::RelativeRoundtripTimeoutPolicy_impl
(TimeBase::TimeT value)
    : Policy_impl(Messaging::RELATIVE_RT_TIMEOUT_POLICY_TYPE), relative_expiry_(value)
{
    CORBA::Object::increase_timeout_policy_instance_counter();
}

MICO::RelativeRoundtripTimeoutPolicy_impl::~RelativeRoundtripTimeoutPolicy_impl()
{
    CORBA::Object::decrease_timeout_policy_instance_counter();
}

::CORBA::Policy_ptr
MICO::RelativeRoundtripTimeoutPolicy_impl::copy()
{
    return new RelativeRoundtripTimeoutPolicy_impl(this->relative_expiry_);
}

::TimeBase::TimeT
MICO::RelativeRoundtripTimeoutPolicy_impl::relative_expiry()
{
    return relative_expiry_;
}

