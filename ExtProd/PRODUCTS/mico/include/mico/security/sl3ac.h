// -*- c++ -*-
//
//  MICO SL3 --- an Open Source SL3 implementation
//  Copyright (C) 2004 ObjectSecurity Ltd.
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


#ifndef __SL3AC_H__
#define __SL3AC_H__

#include <smp/AttributeCertificateDefinitions.h>
#include <smp/EnhancedSecurity.h>
#include <mico/security/sl3authorization.h>
#include <mico/security/sl3utils.h>


namespace MICOSL3_AC
{
    class Attribute;
    typedef std::list<Attribute> AttributeList;


    class AttributeCertChainTokenProcessor
	: virtual public SL3Authorization::TokenProcessor,
	  virtual public CORBA::LocalObject
    {
    public:
	AttributeCertChainTokenProcessor(const std::string& ca_file);

	virtual CORBA::Boolean
	supports_endorsement_by_client();

	virtual CORBA::Boolean
	requires_endorsement_by_client();

	virtual SL3Authorization::AuthorizationInfo*
	accept_token
	(SL3PM::Principal* transport_principal,
	 const SL3PM::StatementList& transport_statements,
	 const SL3PM::ResourceNameList& transport_resources,
	 SL3PM::SimplePrincipal* client_auth_principal,
	 SL3PM::IdentityStatement* client_auth_statement,
	 SL3PM::Principal* identity_assert_principal,
	 const SL3PM::StatementList& identity_assert_statements,
	 const CSI::AuthorizationToken& auth_token);

	virtual CSI::AuthorizationElementType
	accept_token_type();
    private:
	SL3PM::ScopedPrivilegesList*
	attr_list2sp_list(const AttributeList& attrs);

	std::string ca_file_;
    };


    // attribute and attribute certificate classes

    class Attribute
    {
    public:
	Attribute(const std::string& type, const std::string& value);
	Attribute(const Attribute& attr);

	Attribute&
	operator=(const Attribute& attr);

	std::string
	type() const;

	std::string
	value() const;
    private:
	std::string type_;
	std::string value_;
    };


    class X509AttrCert
    {
    public:
	X509AttrCert();
	X509AttrCert(SNACC::AttributeCertificate* attr_cert, SNACC::Certificate* pubkey_cert);
	X509AttrCert(SNACC::AttributeCertificate* attr_cert, const std::string& pubkey_cert);
	X509AttrCert(const X509AttrCert& ac);

	X509AttrCert&
	operator=(const X509AttrCert& ac);

	long
	version() const;

	std::string
	holder() const;

	std::string
	issuer() const;

	std::string
	algorithm() const;

	AttributeList
	attributes() const;

	bool
	verify() const;
    private:
	void
	initialize(SNACC::AttributeCertificate* ac);

	bool
	verify(SNACC::AttributeCertificate* attr_cert, X509* pubkey_cert);

	long version_;
	std::string holder_;
	std::string issuer_;
	std::string algorithm_;
	AttributeList attributes_;
	bool verified_;
    };


    class X509AttrCertChain
    {
    public:
	X509AttrCertChain(const CORBA::OctetSeq& data, const std::string& ca_file);

	X509AttrCert
	attribute_certificate() const;

	bool
	verify() const;
    private:
	X509AttrCert attribute_certificate_;
	bool verified_;
    };


    class X509Cert
	: public virtual MICOSL3Utils::X509Cert
    {
    public:
	X509Cert(SNACC::Certificate* cert, SNACC::Certificate* verification_cert);
	X509Cert(SNACC::Certificate* cert, const std::string& verification_cert);
	X509Cert(const std::string& cert);
	X509Cert(X509* cert);
	X509Cert(const std::string& cert, const std::string& verification_cert);
	X509Cert(X509* cert, X509* verification_cert);
	X509Cert(const X509Cert& cert);
    };
}

#endif // __SL3AC_H__


