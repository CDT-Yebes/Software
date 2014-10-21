//
//  MICO --- an Open Source CORBA implementation
//  Copyright (C) 2008 ObjectSecurity Ltd.
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

#include <CORBA.h>
#include <mico/impl.h>
#include <mico/throw.h>
#include <mico/mtpolicy_impl.h>

#endif // FAST_PCH


using namespace CORBA;


MICOMT::ServerConcurrencyModelPolicy_impl::ServerConcurrencyModelPolicy_impl
(ServerConcurrencyModel value)
    : Policy_impl(SERVER_CONCURRENCY_MODEL_POLICY_TYPE), model_(value)
{
}


MICOMT::ServerConcurrencyModelPolicy_impl::~ServerConcurrencyModelPolicy_impl()
{
}


::CORBA::Policy_ptr
MICOMT::ServerConcurrencyModelPolicy_impl::copy()
{
    return new ServerConcurrencyModelPolicy_impl(this->model_);
}


MICOMT::ServerConcurrencyModel
MICOMT::ServerConcurrencyModelPolicy_impl::model()
{
    return model_;
}


MICOMT::ClientConcurrencyModelPolicy_impl::ClientConcurrencyModelPolicy_impl
(ClientConcurrencyModel value)
    : Policy_impl(CLIENT_CONCURRENCY_MODEL_POLICY_TYPE), model_(value)
{
}


MICOMT::ClientConcurrencyModelPolicy_impl::~ClientConcurrencyModelPolicy_impl()
{
}


::CORBA::Policy_ptr
MICOMT::ClientConcurrencyModelPolicy_impl::copy()
{
    return new ClientConcurrencyModelPolicy_impl(this->model_);
}


MICOMT::ClientConcurrencyModel
MICOMT::ClientConcurrencyModelPolicy_impl::model()
{
    return model_;
}


MICOMT::ConnectionLimitPolicy_impl::ConnectionLimitPolicy_impl
(ULong value)
    : Policy_impl(CONNECTION_LIMIT_POLICY_TYPE), limit_(value)
{
}


MICOMT::ConnectionLimitPolicy_impl::~ConnectionLimitPolicy_impl()
{
}


::CORBA::Policy_ptr
MICOMT::ConnectionLimitPolicy_impl::copy()
{
    return new ConnectionLimitPolicy_impl(this->limit_);
}


CORBA::ULong
MICOMT::ConnectionLimitPolicy_impl::limit()
{
    return limit_;
}


MICOMT::RequestLimitPolicy_impl::RequestLimitPolicy_impl
(ULong value)
    : Policy_impl(REQUEST_LIMIT_POLICY_TYPE), limit_(value)
{
}


MICOMT::RequestLimitPolicy_impl::~RequestLimitPolicy_impl()
{
}


::CORBA::Policy_ptr
MICOMT::RequestLimitPolicy_impl::copy()
{
    return new RequestLimitPolicy_impl(this->limit_);
}


CORBA::ULong
MICOMT::RequestLimitPolicy_impl::limit()
{
    return limit_;
}

