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

#ifdef FAST_PCH
#include "csiv2sl3_pch.h"
#endif // FAST_PCH
#ifdef __COMO__
#pragma hdrstop
#endif // __COMO__

#ifndef FAST_PCH
// for decoding ACs
#include <smp/AttributeCertificateDefinitions.h>
#include <smp/EnhancedSecurity.h>
#include "acext.h"
#include <openssl/err.h>
#include <mico/security/sl3ac.h>
#include <mico/security/sl3pm_impl.h>
// just for debug purposes (sl3utils.h)
#include <mico/security/sl3utils.h>
#include <mico/util.h>
#endif // FAST_PCH


using namespace SL3Authorization;
using namespace SL3PM;
using namespace CSI;
using CORBA::Boolean;
using CORBA::OctetSeq;
using CORBA::BAD_PARAM;
using CORBA::NO_IMPLEMENT;
using namespace SNACC;
using namespace std;


extern void debug(ostream* out, const CORBA::OctetSeq* seq);


MICOSL3_AC::AttributeCertChainTokenProcessor::AttributeCertChainTokenProcessor
(const std::string& ca_file)
    : ca_file_(ca_file)
{
}


Boolean
MICOSL3_AC::AttributeCertChainTokenProcessor::supports_endorsement_by_client()
{
    return FALSE;
}


Boolean
MICOSL3_AC::AttributeCertChainTokenProcessor::requires_endorsement_by_client()
{
    return FALSE;
}


AuthorizationInfo*
MICOSL3_AC::AttributeCertChainTokenProcessor::accept_token
(Principal* transport_principal,
 const StatementList& transport_statements,
 const ResourceNameList& transport_resources,
 SimplePrincipal* client_auth_principal,
 IdentityStatement* client_auth_statement,
 Principal* identity_assert_principal,
 const StatementList& identity_assert_statements,
 const AuthorizationToken& auth_token)
{
    AuthorizationInfo* info = new AuthorizationInfo;
    StatementList stats;
    //stats = transport_statements;
    //cerr << "AttributeCertChainTokenProcessor::accept_token" << endl;
    //wcout << L"transport_principal:" << endl;
    //MICOSL3Utils::PP::print_principal(&wcout, transport_principal);
    //wcout << L"transport_statements:" << endl;
    //StatementList* sl = new StatementList(transport_statements);
    //MICOSL3Utils::PP::print_statement_list(&wcout, sl);
    //wcout << L"transport_resources:" << endl;
    //ResourceNameList* rsl = new ResourceNameList(transport_resources);
    //MICOSL3Utils::PP::print_resource_name_list(&wcout, rsl);
    assert(transport_principal != NULL);
    ProxyPrincipal* proxy = NULL;
    if (client_auth_principal != NULL) {
	//wcout << L"client_auth_principal:" << endl;
	//MICOSL3Utils::PP::print_principal(&wcout, client_auth_principal);
	proxy = new MICOSL3_SL3PM::ProxyPrincipal_impl
	    (transport_principal, client_auth_principal);
	//info->the_principal = proxy;
    }
    QuotingPrincipal* quoting = NULL;
    if (identity_assert_principal != NULL && proxy != NULL) {
	QuotingPrincipal* tmp = QuotingPrincipal::_downcast
	    (identity_assert_principal);
	assert(tmp != NULL);
	quoting = new MICOSL3_SL3PM::QuotingPrincipal_impl
	    (proxy, tmp->quotes_for());
    }
    if (quoting != NULL) {
	info->the_principal = quoting;
    }
    else if (proxy != NULL) {
	info->the_principal = proxy;
    }
    else {
	info->the_principal = transport_principal;
    }
    if (identity_assert_principal != NULL
	&& identity_assert_statements.length() > 0) {
	for (CORBA::ULong i = 0; i < identity_assert_statements.length(); i++) {
	    stats.length(stats.length() + 1);
	    stats[stats.length() - 1] = identity_assert_statements[i];
	}
    }
    else if (client_auth_statement != NULL) {
	//wcout << L"client_auth_statement:" << endl;
	//MICOSL3Utils::PP::print_statement(&wcout, client_auth_statement);
	stats = transport_statements;
	stats.length(stats.length() + 1);
	stats[stats.length() - 1] = client_auth_statement;
    }
    else {
	stats = transport_statements;
    }
    if (identity_assert_principal != NULL) {
	//wcout << L"identity_assert_principal:" << endl;
	//MICOSL3Utils::PP::print_principal(&wcout, identity_assert_principal);
    }
    //wcout << L"identity_assert_statements:" << endl;
    //StatementList* iasl = new StatementList(identity_assert_statements);
    //MICOSL3Utils::PP::print_statement_list(&wcout, iasl);
    //cerr << "auth_token:" << endl;
    ScopedPrivilegesList privileges(0);
    for (CORBA::ULong k = 0; k < auth_token.length(); k++) {
	//cerr << "auth_token[" << k << "].the_type: "
	//<< auth_token[k].the_type << endl;
//  	cerr << "auth_token[" << k << "].the_element:" << endl;
//  	CORBA::OctetSeq seq = auth_token[k].the_element;
//  	debug(&cerr, &seq);
	if (auth_token[k].the_type != CSI::X509AttributeCertChain) {
	    mico_throw(InvalidMechanism());
	}
	X509AttrCertChain chain(auth_token[k].the_element, "ca.pem");
	if (!chain.verify()) {
	    mico_throw(InvalidEvidence());
	}
//  	try {
//  	    cerr << "testing for security("
//  		 << auth_token[k].the_element.length()
//  		 << "):" << endl;
//  	    CORBA::OctetSeq seq = auth_token[k].the_element;
//  	    debug(&cerr, &seq);
//  	    cerr << "going" << flush;
//  	    for (CORBA::ULong i = 0; i < auth_token[k].the_element.length(); i++) {
//  		CORBA::OctetSeq for_test = auth_token[k].the_element;
//  		for_test[i] = for_test[i] + 1;
//  		try {
//  		    X509AttrCertChain chain(for_test, "ca.pem");
//  		    if (chain.verify())
//  			cerr << endl << "verified ok at: " << i << ", " << flush;
//  		    else
//  			cerr << "." << flush;
//  		} catch (const SL3Authorization::InvalidEvidence& ex) {
//  		    cerr << "E" << flush;
//  		}
//  	    }
//  	} catch (const CORBA::SystemException& ex) {
//  	    cerr << "caught: " << ex._repoid() << endl;
//  	} catch (const CORBA::Exception& ex) {
//  	    cerr << "cex: " << ex._repoid() << endl;
//  	} catch (const SnaccException& ex) {
//  	    cerr << "snacc ex: " << ex.what() << endl;
//  	} catch (...) {
//  	    cerr << "caught ex" << endl;
//  	}
	X509AttrCert acert = chain.attribute_certificate();
	AttributeList alist = acert.attributes();
	ScopedPrivilegesList* privs = attr_list2sp_list(alist);
	CORBA::ULong len = privileges.length();
	privileges.length(len + privs->length());
	for (CORBA::ULong i = 0, j = len;
	     i < privs->length();
	     i++, j++) {
	    //cerr << "i(" << i << "), j(" << j << ")" << endl;
	    privileges[j] = (*privs)[i];
	}
    }
    info->the_principal->with_privileges(privileges);
    info->the_statements = stats;
    info->the_resources = transport_resources;
    return info;
}


CSI::AuthorizationElementType
MICOSL3_AC::AttributeCertChainTokenProcessor::accept_token_type()
{
    return CSI::X509AttributeCertChain;
}


SL3PM::ScopedPrivilegesList*
MICOSL3_AC::AttributeCertChainTokenProcessor::attr_list2sp_list
(const AttributeList& attrs)
{
    //cerr << "attr_list2sp_list" << endl;
    SL3PM::ScopedPrivilegesList* result = new SL3PM::ScopedPrivilegesList;
    result->length(0);
    for (AttributeList::const_iterator i = attrs.begin();
	 i != attrs.end();
	 i++) {
	string type = i->type();
	string tmp = i->value();
	tmp = tmp.substr(tmp.find_first_of("=") + 1);
	string name = tmp.substr(0, tmp.find_first_of(","));
	tmp = i->value();
	string authority = tmp.substr(tmp.find_last_of("=") + 1);
	//cerr << "type: ``" << type << "''" << endl;
	//cerr << "name: ``" << name << "''" << endl;
	//cerr << "auth: ``" << authority << "''" << endl;
	PrincipalName priv_authority;
	priv_authority.the_type = (const char*)CSI::GSS_NT_Scoped_Username_OID;
	priv_authority.the_name.length(1);
	wstring wauth = str2wstr(authority);
	priv_authority.the_name[0] = wauth.c_str();
	PrinAttribute privilege;
	privilege.the_type = type.c_str();
	wstring wname = str2wstr(name);
	privilege.the_value = wname.c_str();
	result->length(result->length() + 1);
	(*result)[result->length() - 1].privilege_authority = priv_authority;
	(*result)[result->length() - 1].privileges.length(1);
	(*result)[result->length() - 1].privileges[0] = privilege;
    }
    return result;
}


MICOSL3_AC::Attribute::Attribute(const string& type, const string& value)
    : type_(type), value_(value)
{
    //cerr << "Attribute ctor: " << type_ << " -> " << value_ << endl;
}


MICOSL3_AC::Attribute::Attribute(const Attribute& attr)
    : type_(attr.type_), value_(attr.value_)
{
    //cerr << "Attribute copy ctor: " << type_ << " -> " << value_ << endl;
}


MICOSL3_AC::Attribute&		       
MICOSL3_AC::Attribute::operator=(const MICOSL3_AC::Attribute& attr)
{
    //cerr << "Attribute::operator=" << endl;
    type_ = attr.type_;
    value_ = attr.value_;
    return *this;
}


string
MICOSL3_AC::Attribute::type() const
{
    return type_;
}


string
MICOSL3_AC::Attribute::value() const
{
    return value_;
}


// declared here to not depend on SNACC/SMP in header file (sl3ac.h)
// i.e. type GeneralName is used...
string
gn2string(GeneralName* gn)
{
    string name = "";
    if (gn->choiceId == GeneralName::rfc822NameCid) {
	name = *(gn->rfc822Name);
    }
    else if (gn->choiceId == GeneralName::directoryNameCid) {
	Name* n = gn->directoryName;
	assert(n != NULL);
	//cerr << n->rdnSequence->Count() << endl;
	for (CORBA::Long i = n->rdnSequence->Count() - 1; i >= 0; i--) {
	    n->rdnSequence->SetCurrElmt(i);
	    RelativeDistinguishedName* rdn = n->rdnSequence->Curr();
	    assert(rdn != NULL);
	    for (long j = 0; j < rdn->Count(); j++) {
		rdn->SetCurrElmt(j);
		if (rdn->Curr()->type == id_at_organizationName
		    ||rdn->Curr()->type == id_at_organizationalUnitName
		    ||rdn->Curr()->type == id_at_commonName) {
		    // kcg: seems like these are currently ``decoded''
		    //      which is ugly since id_at_countryName is not
		    //      decoded yet -- maybe this is a bug somewhere...
		    //  			    AsnLen len = 0;
		    //  			    cerr << "current: " << *(rdn->Curr()) << endl;
		    //  			    cerr << "current any: " << rdn->Curr()->value << endl;
		    //  			    cerr << "v.v: " << rdn->Curr()->value.value << endl;
		    //  			    cerr << "v.v->typeName(): " << rdn->Curr()->value.value->typeName() << endl;
		    //  			    cerr << typeid(rdn->Curr()->value.value).name() << endl;
		    DirectoryString* str2 = dynamic_cast<SNACC::DirectoryString*>
			(rdn->Curr()->value.value);
		    //  			    cerr << "str2: " << str2 << endl;
		    //  			    cerr << "str2->choiceId: " << str2->choiceId << endl;
		    wstring wstr = str2->uTF8String->c_str();
		    string sx = wstr2str(wstr);
		    //cerr << "sx: " << sx << endl;
		    if (rdn->Curr()->type == id_at_organizationName) {
			if (name != "")
			    name += ", ";
			name += "O=" + sx;
		    }
		    else if (rdn->Curr()->type == id_at_organizationalUnitName) {
			if (name != "")
			    name += ", ";
			name += "OU=" + sx;
		    }
		    else if (rdn->Curr()->type == id_at_commonName) {
			if (name != "")
			    name += ", ";
			name += "C=" + sx;
		    }
		    else {
			// cannot be anything different
			mico_throw(BAD_PARAM());
		    }
		}
		else if (rdn->Curr()->type == id_at_countryName) {
		    rdn->Curr()->value.SetTypeByOid(rdn->Curr()->type);
		    AsnString* str = dynamic_cast<SNACC::AsnString*>
			(rdn->Curr()->value.value);
		    if (str != NULL) {
			//cerr << "HEUREKA!!!" << endl;
			//cerr << "obtained string is: " << str->c_str() << endl;
			string tmp = str->c_str();
			if (name != "")
			    name += ", ";
			name += "C=" + tmp;
		    }
		    else {
			cerr << "Sorry... :-(" << endl;
			assert(0);
		    }
		}
		else {
		    // anything other?
		    mico_throw(BAD_PARAM());
		}
	    }
	}
    }
    else {
	// everything other is not supported yet
	//cerr << gn->choiceId << " is not supported yet" << endl;
	mico_throw(NO_IMPLEMENT());
    }
    return name;
}


//
// X509AttrCert
//
MICOSL3_AC::X509AttrCert::X509AttrCert()
    : version_(-1), holder_(""), issuer_(""), algorithm_(""), verified_(FALSE)
{
}


MICOSL3_AC::X509AttrCert::X509AttrCert
(AttributeCertificate* attr_cert,
 Certificate* pubkey_cert)
{
    verified_ = FALSE;
    assert(attr_cert != NULL && pubkey_cert != NULL);
    //cerr << "going to verify now..." << endl;
    // verification
    AsnBuf buf;
    buf.ResetMode(std::ios_base::out);
    pubkey_cert->BEnc(buf);
    buf.ResetMode();
    SNACC::AsnLen len = buf.length();
    unsigned char* data = (unsigned char*)buf.GetSeg(len);
    unsigned char* bp = data;
    X509* pubkey_x = d2i_X509(NULL, &data, len);
    delete[] bp;
    verified_ = this->verify(attr_cert, pubkey_x);
    this->initialize(attr_cert);
    X509_free(pubkey_x);
}


MICOSL3_AC::X509AttrCert::X509AttrCert
(AttributeCertificate* attr_cert,
 const string& pubkey_cert)
{
    verified_ = FALSE;
    assert(attr_cert != NULL);
    // verification
    FILE* f = fopen (pubkey_cert.c_str(), "r");
    if (f == NULL) {
	mico_throw(BAD_PARAM());
    }
    X509* pubkey_x = PEM_read_X509(f, NULL, NULL, NULL);
    fclose (f);
    verified_ = this->verify(attr_cert, pubkey_x);
    this->initialize(attr_cert);
}


MICOSL3_AC::X509AttrCert::X509AttrCert(const X509AttrCert& ac)
    : version_(ac.version_), holder_(ac.holder_), issuer_(ac.issuer_), algorithm_(ac.algorithm_), attributes_(ac.attributes_), verified_(ac.verified_)
{
}


MICOSL3_AC::X509AttrCert&
MICOSL3_AC::X509AttrCert::operator=(const X509AttrCert& ac)
{
    version_ = ac.version_;
    holder_ = ac.holder_;
    issuer_ = ac.issuer_;
    algorithm_ = ac.algorithm_;
    attributes_ = ac.attributes_;
    verified_ = ac.verified_;
    return *this;
}


long
MICOSL3_AC::X509AttrCert::version() const
{
    return version_;
}


string
MICOSL3_AC::X509AttrCert::holder() const
{
    return holder_;
}


string
MICOSL3_AC::X509AttrCert::issuer() const
{
    return issuer_;
}


string
MICOSL3_AC::X509AttrCert::algorithm() const
{
    return algorithm_;
}


MICOSL3_AC::AttributeList
MICOSL3_AC::X509AttrCert::attributes() const
{
    return attributes_;
}


bool
MICOSL3_AC::X509AttrCert::verify() const
{
    return verified_;
}


void
MICOSL3_AC::X509AttrCert::initialize(SNACC::AttributeCertificate* ac)
{
    //cerr << "X509AttrCert::initialize..." << endl;
    version_ = *(ac->toBeSigned->version);
    //cerr << "version: " << version_ << endl;
    if (version_ == 1) {
	if (ac->toBeSigned->eitherHolder->choiceId
	    == AttributeCertificateInfoChoice::subjectNameCid) {
	    if (ac->toBeSigned->eitherHolder->subjectName->Count() == 1) {
		holder_ = gn2string
		    (ac->toBeSigned->eitherHolder->subjectName->First());
	    }
	    else {
		// longer names are not supported yet
		mico_throw(NO_IMPLEMENT());
	    }
	}
	else {
	    // baseCertificateId is not supported yet
	    mico_throw(NO_IMPLEMENT());
	}
	//cerr << "holder: " << holder_ << endl;
	if (ac->toBeSigned->issuer->choiceId == AttCertIssuer::v1FormCid) {
	    if (ac->toBeSigned->issuer->v1Form->Count() == 1) {
		issuer_ = gn2string(ac->toBeSigned->issuer->v1Form->First());
	    }
	    else {
		// we do not support issuer to be longer than 1 GN
		mico_throw(NO_IMPLEMENT());
	    }
	}
	else {
	    // v1Form is the only valid for version 1
	    mico_throw(BAD_PARAM());
	}
	//cerr << "issuer: " << issuer_ << endl;
	CORBA::String_var alg = ac->toBeSigned->signature->algorithm.GetChar();
	algorithm_ = alg.in();
	//cerr << "algorithm: " << algorithm_ << endl;
	// attributes decoding
	//cerr << "attributes count: " << ac->toBeSigned->attributes.Count() << endl;
	for (int i = 0; i < ac->toBeSigned->attributes.Count(); i++) {
	    ac->toBeSigned->attributes.SetCurrElmt(i);
	    //cerr << i << ". " << ac->toBeSigned->attributes.Curr()->type << endl;
	    SNACC::Attribute* attr = ac->toBeSigned->attributes.Curr();
	    try {
		if (attr->type == id_at_role) {
		    //cerr << "decoding role..." << endl;
		    AsnAny* any = attr->values.First();
		    any->SetTypeByOid(id_at_role);
		    AsnLen len = 0;
		    any->BDec(*(any->anyBuf), len);
		    RoleSyntax* rs = dynamic_cast<RoleSyntax*>(any->value);
		    if (rs != NULL) {
			assert(rs->roleAuthority->Count() == 1);
			string val = "";
			val += "Role=" + gn2string(rs->roleName);
			val += ", RoleAuthority=" + gn2string(rs->roleAuthority->First());
			Attribute at("Role", val);
			attributes_.push_back(at);
		    }
		    else {
			// error
			mico_throw(BAD_PARAM());
		    }
		}
		else if (attr->type == id_at_right) {
		    //cerr << "decoding right..." << endl;
		    AsnAny* any = attr->values.First();
		    any->SetTypeByOid(id_at_right);
		    AsnLen len = 0;
		    any->BDec(*(any->anyBuf), len);
		    RightSyntax* rs = dynamic_cast<RightSyntax*>(any->value);
		    if (rs != NULL) {
			assert(rs->rightAuthority->Count() == 1);
			string val = "";
			val += "Right=" + gn2string(rs->rightName);
			val += ", RightAuthority=" + gn2string(rs->rightAuthority->First());
			Attribute at("Right", val);
			attributes_.push_back(at);
		    }
		    else {
			// error
			mico_throw(BAD_PARAM());
		    }
		    
		}
		else if (attr->type == id_at_group) {
		    //cerr << "decoding group..." << endl;
		    AsnAny* any = attr->values.First();
		    any->SetTypeByOid(id_at_group);
		    AsnLen len = 0;
		    any->BDec(*(any->anyBuf), len);
		    GroupSyntax* gs = dynamic_cast<GroupSyntax*>(any->value);
		    if (gs != NULL) {
			assert(gs->groupAuthority->Count() == 1);
			string val = "";
			val += "Group=" + gn2string(gs->groupName);
			val += ", GroupAuthority=" + gn2string(gs->groupAuthority->First());
			Attribute at("Group", val);
			attributes_.push_back(at);
		    }
		    else {
			// error
			mico_throw(BAD_PARAM());
		    }		    
		}
		else if (attr->type == id_at_clearance) {
		    // needs to be supported later
		    mico_throw(NO_IMPLEMENT());
		}
		else {
		    // unsupported attribute type
		    mico_throw(NO_IMPLEMENT());
		}
	    } catch (const SnaccException& ex) {
		cerr << "s" << flush;
	    }
	}
    }
    else {
	// version 2 is not supported yet
	mico_throw(NO_IMPLEMENT());
    }
}


bool
MICOSL3_AC::X509AttrCert::verify
(SNACC::AttributeCertificate* attr_cert,
 X509* pubkey_cert)
{
    //cerr << "X509AttrCert::verify" << endl;
    EVP_PKEY* pub_key = X509_get_pubkey(pubkey_cert);
    assert(pub_key != NULL);
    AsnBuf data_buf;
    data_buf.ResetMode(std::ios_base::out);
    AttributeCertificateInfo tbs = *(attr_cert->toBeSigned);
    AsnLen len = tbs.BEnc(data_buf);
    data_buf.ResetMode();
    //cerr << "size encoded: " << len << endl;
    //cerr << "data_buf.length(): " << data_buf.length() << endl;
    int data_len = data_buf.length();
    char* dx = data_buf.GetSeg(data_len);		
    //cerr << "data_buf.length(): " << data_buf.length() << endl;
    {
	CORBA::OctetSeq dd; 
	dd.length(data_len);
	for (CORBA::ULong i = 0; i < dd.length(); i++) {
	    dd[i] = dx[i];
	}
	//cerr << "data: len: " << dd.length() << endl;
	//debug(&cerr, &dd);
    }
    EVP_MD_CTX mdctx;
    EVP_VerifyInit(&mdctx, EVP_sha1());
    EVP_VerifyUpdate(&mdctx, dx, data_len);
    unsigned char* sig = new unsigned char[attr_cert->signature.length()];
    memcpy(sig, attr_cert->signature.data(), attr_cert->signature.length());
    { // debug
	CORBA::OctetSeq dd; 
	dd.length(attr_cert->signature.length());
	for (CORBA::ULong i = 0; i < dd.length(); i++) {
	    dd[i] = sig[i];
	}
	//cerr << "signature: len: " << dd.length() << endl;
	//debug(&cerr, &dd);
    }
    int res = EVP_VerifyFinal(&mdctx, sig, attr_cert->signature.length(), pub_key);
    // cleanup
    EVP_PKEY_free(pub_key);
    delete[] sig;
    delete[] dx;
    if (res == 1) {
	//cerr << "correct signature" << endl;
	return TRUE;
    }
    else if (res == 0) {
	//cerr << "WRONG SIGNATURE!!!" << endl;
    }
    else {
	//cerr << "other error..." << endl;
	//cerr << ERR_error_string(ERR_get_error(), NULL) << endl;
    }
    return FALSE;
}


//
// X509AttrCertChain
//
MICOSL3_AC::X509AttrCertChain::X509AttrCertChain
(const OctetSeq& data,
 const std::string& ca_file)
{
    //cerr << "X509AttrCertChain ctor" << endl;
    //cerr << "CA file: " << ca_file << endl;
    verified_ = FALSE;
    try {
	X509Cert ca(ca_file, ca_file);
	assert(ca.verify());
	//debug(&cerr, &data);
	CORBA::ULong count = data.length();
	char* buf = new char[count];
	for (CORBA::ULong i = 0; i < count; i++) {
	    buf[i] = data[i];
	}
	AsnBuf asn_buf(buf, count);
	delete[] buf;
	AttributeCertChain chain;
	AsnLen len = 0;
	chain.BDec(asn_buf, len);
	//cerr << "X509AttributeCertChain decoded: " << len << endl;
	if (chain.certificateChain.Count() > 0) {
	    //cerr << "chain.certificateChain.Count(): " << chain.certificateChain.Count() << endl;
	    chain.certificateChain.SetCurrToLast();
	    X509Cert tmp(chain.certificateChain.Curr(), ca_file);
	    if (!tmp.verify()) {
		mico_throw(InvalidEvidence());
	    }
	    //cerr << "last cert verified ok" << endl;
	    for (long i = chain.certificateChain.Count() - 1; i > 0; i--) {
		chain.certificateChain.SetCurrElmt(i);
		X509Cert tmp(chain.certificateChain.Prev(), chain.certificateChain.Curr());
		if (!tmp.verify()) {
		    mico_throw(InvalidEvidence());
		}
		//cerr << i << ". cert verified ok" << endl;
	    }
	    chain.certificateChain.SetCurrToFirst();
	    X509AttrCert ac(chain.attributeCert, chain.certificateChain.Curr());
	    if (!ac.verify()) {
		mico_throw(InvalidEvidence());
	    }
	    attribute_certificate_ = ac;
	    //cerr << "AttrCert verified ok" << endl;
	}
	else {
	    // we will verify by using CA cert directly
	    X509AttrCert ac(chain.attributeCert, ca_file);
	    if (!ac.verify()) {
		mico_throw(InvalidEvidence());
	    }
	    attribute_certificate_ = ac;
	    //cerr << "AttrCert verified ok" << endl;
	}
	verified_ = TRUE;
    } catch (const SnaccException& ex) {
	cerr << "S" << flush;
	verified_ = FALSE;
    } catch (const CORBA::BAD_PARAM& ex) {
	cerr << "B" << flush;
	verified_ = FALSE;
    } catch (const CORBA::NO_IMPLEMENT& ex) {
	cerr << "I" << flush;
	verified_ = FALSE;
    }
}


MICOSL3_AC::X509AttrCert
MICOSL3_AC::X509AttrCertChain::attribute_certificate() const
{
    return attribute_certificate_;
}


bool
MICOSL3_AC::X509AttrCertChain::verify() const
{
    return verified_;
}


//
// X509Cert
//
MICOSL3_AC::X509Cert::X509Cert(Certificate* cert, Certificate* verification_cert)
{
    AsnBuf buf1;
    buf1.ResetMode(ios_base::out);
    cert->BEnc(buf1);
    buf1.ResetMode();
    AsnLen len1 = buf1.length();
    unsigned char* data1 = (unsigned char*)buf1.GetSeg(len1);
    unsigned char* bp1 = data1;
    X509* c = d2i_X509(NULL, &data1, len1);
    delete[] bp1;
    AsnBuf buf2;
    buf2.ResetMode(ios_base::out);
    verification_cert->BEnc(buf2);
    buf2.ResetMode();
    AsnLen len2 = buf2.length();
    unsigned char* data2 = (unsigned char*)buf2.GetSeg(len2);
    unsigned char* bp2 = data2;
    X509* v = d2i_X509(NULL, &data2, len2);
    delete[] bp2;
    verified_ = this->verify(c, v);
    this->init_from_x509(c);
    X509_free(c);
    X509_free(v);
}


MICOSL3_AC::X509Cert::X509Cert
(SNACC::Certificate* cert,
 const string& verification_cert)
{
    AsnBuf buf1;
    buf1.ResetMode(ios_base::out);
    cert->BEnc(buf1);
    buf1.ResetMode();
    AsnLen len1 = buf1.length();
    unsigned char* data1 = (unsigned char*)buf1.GetSeg(len1);
    unsigned char* bp1 = data1;
    X509* c = d2i_X509(NULL, &data1, len1);
    delete[] bp1;
    FILE* vf = fopen(verification_cert.c_str(), "r");
    if (vf == NULL)
	mico_throw(BAD_PARAM());
    X509* v = PEM_read_X509(vf, NULL, NULL, NULL);
    fclose(vf);
    verified_ = this->verify(c, v);
    this->init_from_x509(c);
    X509_free(c);
    X509_free(v);
}


MICOSL3_AC::X509Cert::X509Cert(const string& cert)
    : MICOSL3Utils::X509Cert(cert)
{
}


MICOSL3_AC::X509Cert::X509Cert(X509* cert)
    : MICOSL3Utils::X509Cert(cert)
{
}


MICOSL3_AC::X509Cert::X509Cert
(const string& cert,
 const string& verification_cert)
    : MICOSL3Utils::X509Cert(cert, verification_cert)
{
    //cerr << "MICOSL3_AC::X509Cert, file, file" << endl;
}


MICOSL3_AC::X509Cert::X509Cert(X509* cert, X509* verification_cert)
    : MICOSL3Utils::X509Cert(cert, verification_cert)
{
}


MICOSL3_AC::X509Cert::X509Cert(const X509Cert& cert)
    : MICOSL3Utils::X509Cert(cert)
{
}

