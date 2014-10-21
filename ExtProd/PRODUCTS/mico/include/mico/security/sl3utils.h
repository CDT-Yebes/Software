// -*- c++ -*-
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


#ifndef __SL3UTILS_H__
#define __SL3UTILS_H__

#include <CORBA.h>
#include <mico/ssl.h>


namespace MICOSL3Utils
{
    class PP
    {
    public:
	static void
	indent(std::wostream* out);

	static void
	inner_scope();

	static void
	outer_scope();

	static void
	print_time
	(std::wostream* out,
	 const TimeBase::UtcT& time);

	static void
	print_principal_name
	(std::wostream* out,
	 const SL3PM::PrincipalName& name);

	static void
	print_principal
	(std::wostream* out,
	 SL3PM::Principal* principal);

	static void
	print_statement
	(std::wostream* out,
	 SL3PM::Statement* statement);

	static void
	print_statement_list
	(std::wostream* out,
	 SL3PM::StatementList* statement_list);

	static void
	print_resource_name_list
	(std::wostream* out,
	 SL3PM::ResourceNameList* rslist);

	static void
	print_credentials_initiator
	(std::wostream* out,
	 TransportSecurity::CredentialsInitiator_ptr initiator);

	static void
	print_credentials_acceptor
	(std::wostream* out,
	 TransportSecurity::CredentialsAcceptor_ptr acceptor);

	static void
	print_own_credentials
	(std::wostream* out,
	 TransportSecurity::OwnCredentials_ptr creds);

	static void
	print_target_credentials
	(std::wostream* out,
	 TransportSecurity::TargetCredentials_ptr creds);

	static void
	print_client_credentials
	(std::wostream* out,
	 TransportSecurity::ClientCredentials_ptr creds);

	static void
	print_creds_initiator
	(std::wostream* out,
	 SecurityLevel3::CredsInitiator_ptr initiator);

	static void
	print_creds_acceptor
	(std::wostream* out,
	 SecurityLevel3::CredsAcceptor_ptr acceptor);

	static void
	print_own_credentials
	(std::wostream* out,
	 SecurityLevel3::OwnCredentials_ptr creds);

	static void
	print_target_credentials
	(std::wostream* out,
	 SecurityLevel3::TargetCredentials_ptr creds);

	static void
	print_client_credentials
	(std::wostream* out,
	 SecurityLevel3::ClientCredentials_ptr creds);

	static void
	print_environmental_attributes
	(std::wostream& out,
	 const SL3PM::PrinAttributeList& attrs);

	static void
	print_scoped_privilege
	(std::wostream& out,
	 const SL3PM::ScopedPrivileges& privilege);

	static void
	print_prinattribute
	(std::wostream& out,
	 const SL3PM::PrinAttribute& attr);
    private:
	static long i_count_;
    };

    class Address
    {
    public:
	static std::string
	addr_to_string(const CORBA::Address* addr);

	static std::wstring
	addr_to_wstring(const CORBA::Address* addr);

	static std::string
	ip_to_string(const CORBA::Address* addr);

	static std::wstring
	ip_to_wstring(const CORBA::Address* addr);

	static std::string
	port_to_string(const CORBA::Address* addr);

	static std::wstring
	port_to_wstring(const CORBA::Address* addr);
    };

    class X509Cert
    {
    public:
	X509Cert(const std::string& cert);
	X509Cert(X509* cert);
	X509Cert(const std::string& cert, const std::string& verification_cert);
	X509Cert(X509* cert, X509* verification_cert);
	X509Cert(const X509Cert& cert);

	X509Cert&
	operator=(const X509Cert& cert);

	std::string
	issuer() const;

	std::string
	subject() const;

	bool
	verify() const;
    protected:
	X509Cert();

	void
	init_from_x509(X509* data);

	bool
	verify(X509* cert, X509* verification_cert);

	std::string issuer_;
	std::string subject_;
	bool verified_;
    };

    class CredsRetriever
    {
    public:
	static SecurityLevel3::OwnCredentialsList*
	get_own_credentials_list
	(CORBA::ORB_ptr orb,
	 CORBA::Object_ptr target,
	 CORBA::Boolean use_context_establishment_policy);

	static SecurityLevel3::OwnCredentials_ptr
	get_client_side_own_credentials
	(CORBA::ORB_ptr orb,
	 CORBA::Object_ptr target,
	 CORBA::Boolean use_context_establishment_policy);

	static SecurityLevel3::OwnCredentials_ptr
	get_server_side_own_credentials
	(CORBA::ORB_ptr orb);
    };
} // MICOSL3Utils


#endif // __SL3UTILS_H__


