//
//  MICO SL3 --- an Open Source SL3 implementation
//  Copyright (C) 2002, 2003, 2004 ObjectSecurity Ltd.
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
#include <mico/security/sl3pm_impl.h>
#endif // FAST_PCH


using namespace SL3PM;
using CORBA::ValueBase;

using namespace std;


//
// module initialization
//

void
MICOSL3_SL3PM::_init()
{
    PortableInterceptor::register_orb_initializer(new ORBInitializer());
}


//
// SimplePrincipal_impl
//

MICOSL3_SL3PM::SimplePrincipal_impl::SimplePrincipal_impl()
{
    this->the_type(PT_Simple);
    this->authenticated(false);
}


MICOSL3_SL3PM::SimplePrincipal_impl::SimplePrincipal_impl
(const PrincipalName name,
 const ScopedPrivilegesList& with_privileges,
 const PrincipalNameList& alternate_names)
{
    this->the_name(name);
    this->the_type(PT_Simple);
    this->with_privileges(with_privileges);
    this->alternate_names(alternate_names);
    this->authenticated(false);
}


MICOSL3_SL3PM::SimplePrincipal_impl::~SimplePrincipal_impl()
{
}


//
// SimplePrincipalFactory_impl
//

ValueBase*
MICOSL3_SL3PM::SimplePrincipalFactory_impl::create_for_unmarshal()
{
    return new SimplePrincipal_impl();
}


SimplePrincipal*
MICOSL3_SL3PM::SimplePrincipalFactory_impl::create
(const PrincipalName& the_name,
 const ScopedPrivilegesList& with_privileges,
 const PrincipalNameList& alternate_names)
{
    return new SimplePrincipal_impl
	(the_name, with_privileges, alternate_names);
}


//
// ProxyPrincipal_impl
//

MICOSL3_SL3PM::ProxyPrincipal_impl::ProxyPrincipal_impl()
{
    this->the_type(PT_Proxy);
}


MICOSL3_SL3PM::ProxyPrincipal_impl::ProxyPrincipal_impl
(SL3PM::Principal* speaking, SL3PM::Principal* speaks_for)
    : OBV_SL3PM::ProxyPrincipal(PT_Proxy, speaks_for->the_name(), speaks_for->with_privileges(), speaking, speaks_for)
{
}


MICOSL3_SL3PM::ProxyPrincipal_impl::~ProxyPrincipal_impl()
{
}


//
// ProxyPrincipalFactory_impl
//

ValueBase*
MICOSL3_SL3PM::ProxyPrincipalFactory_impl::create_for_unmarshal()
{
    return new ProxyPrincipal_impl;
}


ProxyPrincipal*
MICOSL3_SL3PM::ProxyPrincipalFactory_impl::create
(Principal* speaking,
 Principal* speaks_for)
{
    return new ProxyPrincipal_impl(speaking, speaks_for);
}


//
// QuotingPrincipal_impl
//

MICOSL3_SL3PM::QuotingPrincipal_impl::QuotingPrincipal_impl()
{
    this->the_type(PT_Quoting);
}


MICOSL3_SL3PM::QuotingPrincipal_impl::QuotingPrincipal_impl
(SL3PM::Principal* speaking, SL3PM::Principal* quotes_for)
    : OBV_SL3PM::QuotingPrincipal(PT_Quoting, quotes_for->the_name(), quotes_for->with_privileges(), speaking, quotes_for)
{
}


MICOSL3_SL3PM::QuotingPrincipal_impl::~QuotingPrincipal_impl()
{
}


//
// QuotingPrincipalFactory_impl
//

ValueBase*
MICOSL3_SL3PM::QuotingPrincipalFactory_impl::create_for_unmarshal()
{
    return new QuotingPrincipal_impl;
}


QuotingPrincipal*
MICOSL3_SL3PM::QuotingPrincipalFactory_impl::create
(Principal* speaking,
 Principal* quotes_for)
{
    return new QuotingPrincipal_impl(speaking, quotes_for);
}


//
// Statement_impl
//

MICOSL3_SL3PM::Statement_impl::Statement_impl()
{
    //cerr << "Statement_impl()" << endl;
    encoding_.length(0);
    encoding_type_ = "";
    this->the_type(0);
    this->the_layer(0);
}


MICOSL3_SL3PM::Statement_impl::Statement_impl
(const char* encoding_type,
 const Encoding& the_encoding)
    : encoding_(the_encoding), encoding_type_(encoding_type)
{
    //cerr << "Statement_impl <- " << encoding_type << endl;
}


char*
MICOSL3_SL3PM::Statement_impl::get_encoding_type()
{
    return CORBA::string_dup(encoding_type_.in());
}


Encoding*
MICOSL3_SL3PM::Statement_impl::get_encoding(const char* encoding_type)
{
    assert(0);
    return NULL;
}


//
// StatementFactory_impl
//

ValueBase*
MICOSL3_SL3PM::StatementFactory_impl::create_for_unmarshal()
{
    return new Statement_impl;
}


Statement*
MICOSL3_SL3PM::StatementFactory_impl::create
(const char* encoding_type,
 const Encoding& the_encoding)
{
    return new Statement_impl(encoding_type, the_encoding);
}


//
// IdentityStatement_impl
//

MICOSL3_SL3PM::IdentityStatement_impl::IdentityStatement_impl()
{
}


MICOSL3_SL3PM::IdentityStatement_impl::IdentityStatement_impl
(const char* encoding_type,
 const Encoding& the_encoding)
    //    : Statement_impl::encoding_type_(encoding_type), Statement_impl::encoding_(the_encoding)
{
    encoding_type_ = encoding_type;
    encoding_ = the_encoding;
    //cerr << "IdentityStatement_impl <- " << encoding_type << endl;
}

//
// IdentityStatementFactory_impl
//

ValueBase*
MICOSL3_SL3PM::IdentityStatementFactory_impl::create_for_unmarshal()
{
    return new IdentityStatement_impl;
}


//
// PrincipalIdentityStatement_impl
//

MICOSL3_SL3PM::PrincipalIdentityStatement_impl::PrincipalIdentityStatement_impl()
{
}


MICOSL3_SL3PM::PrincipalIdentityStatement_impl::PrincipalIdentityStatement_impl
(const char* encoding_type,
 const Encoding& the_encoding)
    //    : encoding_type_(encoding_type), encoding_(the_encoding)
{
    encoding_type_ = encoding_type;
    encoding_ = the_encoding;
    //cerr << "PrincipalIdentityStatement_impl <- " << encoding_type << endl;
}

//
// PrincipalIdentityStatementFactory_impl
//

ValueBase*
MICOSL3_SL3PM::PrincipalIdentityStatementFactory_impl::create_for_unmarshal()
{
    return new PrincipalIdentityStatement_impl;
}


//
// various supporting classes
//

MICOSL3_SL3PM::ORBInitializer::ORBInitializer()
{
}


MICOSL3_SL3PM::ORBInitializer::~ORBInitializer()
{
}


void
MICOSL3_SL3PM::ORBInitializer::pre_init
(PortableInterceptor::ORBInitInfo_ptr info)
{
    //cerr << "MICOSL3_SL3PM::ORBInitializer::pre_init" << endl;
    // crude hack since ORBInitInfo doesn't support
    // valuetype factory registration
    CORBA::ORB_var orb = CORBA::ORB_instance("mico-local-orb", FALSE);
    SimplePrincipalFactory_impl* f1 = new SimplePrincipalFactory_impl;
    orb->register_value_factory
	("IDL:adiron.com/SL3PM/SimplePrincipal:1.0", f1);
    orb->register_value_factory
	("IDL:adiron.com/SL3PM/ProxyPrincipal:1.0",
	 new ProxyPrincipalFactory_impl);
    orb->register_value_factory
	("IDL:adiron.com/SL3PM/QuotingPrincipal:1.0",
	 new QuotingPrincipalFactory_impl);
    StatementFactory_impl* f2 = new StatementFactory_impl;
    orb->register_value_factory
	("IDL:adiron.com/SL3PM/Statement:1.0", f2);
    IdentityStatementFactory_impl* f3 = new IdentityStatementFactory_impl;
    orb->register_value_factory
	("IDL:adiron.com/SL3PM/IdentityStatement:1.0", f3);
    PrincipalIdentityStatementFactory_impl* f4
	= new PrincipalIdentityStatementFactory_impl;
    orb->register_value_factory
	("IDL:adiron.com/SL3PM/PrincipalIdentityStatement:1.0", f4);
}


void
MICOSL3_SL3PM::ORBInitializer::post_init
(PortableInterceptor::ORBInitInfo_ptr info)
{
}

