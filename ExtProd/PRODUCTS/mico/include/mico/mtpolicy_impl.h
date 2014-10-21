// -*- c++ -*-
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

#ifndef __MTPOLICY_IMPL_H_20080718__
#define __MTPOLICY_IMPL_H_20080718__

namespace MICOMT
{
class ServerConcurrencyModelPolicy_impl
    : public virtual ServerConcurrencyModelPolicy,
      public virtual ::MICO::Policy_impl,
      public virtual ::CORBA::LocalObject
{
protected:
    ServerConcurrencyModelPolicy_impl()
        : Policy_impl(MICOMT::SERVER_CONCURRENCY_MODEL_POLICY_TYPE)
    {}
public:
    ServerConcurrencyModelPolicy_impl(ServerConcurrencyModel model);

    virtual
    ~ServerConcurrencyModelPolicy_impl();

    virtual ::CORBA::Policy_ptr
    copy();

    virtual ServerConcurrencyModel
    model();
private:
    ServerConcurrencyModel model_;
};

class ClientConcurrencyModelPolicy_impl
    : public virtual ClientConcurrencyModelPolicy,
      public virtual ::MICO::Policy_impl,
      public virtual ::CORBA::LocalObject
{
protected:
    ClientConcurrencyModelPolicy_impl()
        : Policy_impl(MICOMT::CLIENT_CONCURRENCY_MODEL_POLICY_TYPE)
    {}
public:
    ClientConcurrencyModelPolicy_impl(ClientConcurrencyModel model);

    virtual
    ~ClientConcurrencyModelPolicy_impl();

    virtual ::CORBA::Policy_ptr
    copy();

    virtual ClientConcurrencyModel
    model();
private:
    ClientConcurrencyModel model_;
};

class ConnectionLimitPolicy_impl
    : public virtual ConnectionLimitPolicy,
      public virtual ::MICO::Policy_impl,
      public virtual ::CORBA::LocalObject
{
protected:
    ConnectionLimitPolicy_impl()
        : Policy_impl(MICOMT::CONNECTION_LIMIT_POLICY_TYPE)
    {}
public:
    ConnectionLimitPolicy_impl(CORBA::ULong value);

    virtual
    ~ConnectionLimitPolicy_impl();

    virtual ::CORBA::Policy_ptr
    copy();

    virtual CORBA::ULong
    limit();
private:
    CORBA::ULong limit_;
};

class RequestLimitPolicy_impl
    : public virtual RequestLimitPolicy,
      public virtual ::MICO::Policy_impl,
      public virtual ::CORBA::LocalObject
{
protected:
    RequestLimitPolicy_impl()
        : Policy_impl(MICOMT::REQUEST_LIMIT_POLICY_TYPE)
    {}
public:
    RequestLimitPolicy_impl(CORBA::ULong value);

    virtual
    ~RequestLimitPolicy_impl();

    virtual ::CORBA::Policy_ptr
    copy();

    virtual CORBA::ULong
    limit();
private:
    CORBA::ULong limit_;
};
} // MICOMT
#endif // __MTPOLICY_IMPL_H_20080718__

