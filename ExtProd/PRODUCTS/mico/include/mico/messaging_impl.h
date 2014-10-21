// -*- c++ -*-
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

#ifndef __MESSAGING_IMPL_H_20071115__
#define __MESSAGING_IMPL_H_20071115__

namespace MICO
{
class RelativeRoundtripTimeoutPolicy_impl
    : public virtual ::Messaging::RelativeRoundtripTimeoutPolicy,
      public virtual Policy_impl,
      public virtual ::CORBA::LocalObject
{
protected:
    RelativeRoundtripTimeoutPolicy_impl()
        : Policy_impl(Messaging::RELATIVE_RT_TIMEOUT_POLICY_TYPE)
    {}
public:
    RelativeRoundtripTimeoutPolicy_impl(TimeBase::TimeT value);

    virtual
    ~RelativeRoundtripTimeoutPolicy_impl();

    virtual ::CORBA::Policy_ptr
    copy();

    virtual ::TimeBase::TimeT
    relative_expiry();
private:
    ::TimeBase::TimeT relative_expiry_;
};

} // MICO
#endif // __MESSAGING_IMPL_H_20071115__

