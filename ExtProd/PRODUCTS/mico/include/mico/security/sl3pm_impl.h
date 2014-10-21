// -*- c++ -*-
//
//  MICO SL3 --- an Open Source SL3 implementation
//  Copyright (C) 2003, 2004 ObjectSecurity Ltd.
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

#ifndef __SL3PM_IMPL_H__
#define __SL3PM_IMPL_H__

#include <mico/security/sl3pm.h>


namespace MICOSL3_SL3PM
{
    // initialization function
    void
    _init();


    class SimplePrincipal_impl
	: public virtual OBV_SL3PM::SimplePrincipal,
	  public virtual CORBA::DefaultValueRefCountBase
    {
    public:
	SimplePrincipal_impl();

	SimplePrincipal_impl
	(const SL3PM::PrincipalName name,
	 const SL3PM::ScopedPrivilegesList& with_privileges,
	 const SL3PM::PrincipalNameList& alternate_names);

	virtual
	~SimplePrincipal_impl();
    };


    class SimplePrincipalFactory_impl
	: virtual public SL3PM::SimplePrincipal_init
    {
    public:
	virtual CORBA::ValueBase*
	create_for_unmarshal();

	virtual SL3PM::SimplePrincipal*
	create
	(const SL3PM::PrincipalName& the_name,
	 const SL3PM::ScopedPrivilegesList& with_privileges,
	 const SL3PM::PrincipalNameList& alternate_names);
    };


    class ProxyPrincipal_impl
	: virtual public OBV_SL3PM::ProxyPrincipal,
	  virtual public CORBA::DefaultValueRefCountBase
    {
    public:
	ProxyPrincipal_impl();

	ProxyPrincipal_impl
	(SL3PM::Principal* speaking,
	 SL3PM::Principal* speaks_for);

	virtual
	~ProxyPrincipal_impl();
    };


    class ProxyPrincipalFactory_impl
	: virtual public SL3PM::ProxyPrincipal_init
    {
    public:
	virtual CORBA::ValueBase*
	create_for_unmarshal();

	virtual SL3PM::ProxyPrincipal*
	create
	(SL3PM::Principal* speaking,
	 SL3PM::Principal* speaks_for);
    };


    class QuotingPrincipal_impl
	: virtual public OBV_SL3PM::QuotingPrincipal,
	  virtual public CORBA::DefaultValueRefCountBase
    {
    public:
	QuotingPrincipal_impl();

	QuotingPrincipal_impl
	(SL3PM::Principal* speaking,
	 SL3PM::Principal* quotes_for);

	virtual
	~QuotingPrincipal_impl();
    };


    class QuotingPrincipalFactory_impl
	: virtual public SL3PM::QuotingPrincipal_init
    {
    public:
	virtual CORBA::ValueBase*
	create_for_unmarshal();

	virtual SL3PM::QuotingPrincipal*
	create
	(SL3PM::Principal* speaking,
	 SL3PM::Principal* quotes_for);
    };


    class Statement_impl
	: virtual public OBV_SL3PM::Statement,
	  virtual public CORBA::DefaultValueRefCountBase
    {
    public:
	Statement_impl();

	Statement_impl
	(const char* encoding_type,
	 const SL3PM::Encoding& the_encoding);

	virtual char*
	get_encoding_type();

	virtual SL3PM::Encoding*
	get_encoding(const char* encoding_type);
    protected:
	SL3PM::Encoding encoding_;
	SL3PM::EncodingType_var encoding_type_;
    };


    class StatementFactory_impl
	: virtual public SL3PM::Statement_init
    {
    public:
	virtual CORBA::ValueBase*
	create_for_unmarshal();

	virtual SL3PM::Statement*
	create
	(const char* encoding_type,
	 const SL3PM::Encoding& the_encoding);
    };


    class IdentityStatement_impl
	: virtual public Statement_impl,
	  virtual public OBV_SL3PM::IdentityStatement
    {
    public:
	IdentityStatement_impl();

	IdentityStatement_impl
	(const char* encoding_type,
	 const SL3PM::Encoding& the_encoding);
    };


    class IdentityStatementFactory_impl
	: virtual public MICOSL3_SL3PM::StatementFactory_impl
    {
    public:
	virtual CORBA::ValueBase*
	create_for_unmarshal();
    };


    class PrincipalIdentityStatement_impl
	: virtual public IdentityStatement_impl,
	  virtual public OBV_SL3PM::PrincipalIdentityStatement
    {
    public:
	PrincipalIdentityStatement_impl();

	PrincipalIdentityStatement_impl
	(const char* encoding_type,
	 const SL3PM::Encoding& the_encoding);
    };


    class PrincipalIdentityStatementFactory_impl
	: virtual public MICOSL3_SL3PM::IdentityStatementFactory_impl
    {
    public:
	virtual CORBA::ValueBase*
	create_for_unmarshal();
    };


    //
    // various supporting classes
    //

    class ORBInitializer
	: virtual public PortableInterceptor::ORBInitializer,
	  virtual public CORBA::LocalObject
    {
    public:
	ORBInitializer();

	virtual
	~ORBInitializer();

	virtual void
	pre_init(PortableInterceptor::ORBInitInfo_ptr info);

	virtual void
	post_init(PortableInterceptor::ORBInitInfo_ptr info);
    };

} // MICOSL3_SL3PM

#endif // __SL3PM_IMPL_H__
