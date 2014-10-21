/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2008 by The Mico Team
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  For more information, visit the MICO Home Page at
 *  http://www.mico.org/
 */

#ifdef FAST_PCH
#include "orb_pch.h"
#endif // FAST_PCH
#ifdef __COMO__
#pragma hdrstop
#endif // __COMO__

#ifndef FAST_PCH

#define MICO_CONF_IMR
#define MICO_CONF_IR
#define MICO_CONF_POA
#define MICO_CONF_INTERCEPT

#include <CORBA-SMALL.h>
#include <mico/impl.h>
#include <mico/throw.h>
#include <mico/poa_impl.h>
#include <mico/template_impl.h>
#include <mico/pi_impl.h>
#ifdef USE_MESSAGING
#include <mico/messaging_impl.h>
#endif // USE_MESSAGING
#ifdef THREADING_POLICIES
#include <mico/mtpolicy_impl.h>
#endif // THREADING_POLICIES

#endif // FAST_PCH

using namespace CORBA;


MICO::Policy_impl::Policy_impl (CORBA::PolicyType _pt)
{
    pt = _pt;
}

MICO::Policy_impl::~Policy_impl ()
{
    // nothing to do
}

CORBA::PolicyType
MICO::Policy_impl::policy_type ()
{
    return pt;
}

void
MICO::Policy_impl::destroy ()
{
    // nothing to do
}


//
// PolicyManager (CORBA 3.0)
//
MICO::PolicyManager_impl::PolicyManager_impl()
{
    policies_.length(0);
}

PolicyList*
MICO::PolicyManager_impl::get_policy_overrides(const CORBA::PolicyTypeSeq& ts)
{
    MICOMT::AutoLock lock(this->policies_mutex_);
    if (ts.length() == 0)
        return new PolicyList(this->policies_);

    PolicyList_var retval = new PolicyList;
    for (ULong i = 0; i < ts.length(); i++) {
        for (ULong j = 0; j < this->policies_.length(); j++) {
            if (this->policies_[j]->policy_type() == ts[i]) {
                retval->length(retval->length() + 1);
                retval[retval->length() - 1] = Policy::_duplicate(this->policies_[j]);
            }
        }
    }
    return retval._retn();
}

void
MICO::PolicyManager_impl::set_policy_overrides(const PolicyList& policies, SetOverrideType set_add)
{
    MICOMT::AutoLock lock(this->policies_mutex_);
    for (ULong i = 0; i < policies.length() - 1; i++) {
        for (ULong j = i + 1; j < policies.length(); j++) {
            if (policies[i]->policy_type() == policies[j]->policy_type()) {
                throw BAD_PARAM(30, COMPLETED_NO);
            }
        }
    }

    if (set_add == SET_OVERRIDE) {
        this->policies_ = policies;
    }
    else if (set_add == ADD_OVERRIDE) {
        for (ULong i = 0; i < policies.length(); i++) {
            Boolean set = FALSE;
            for (ULong j = 0; j < this->policies_.length(); j++) {
                if (policies[i]->policy_type() == this->policies_[j]->policy_type()) {
                    this->policies_[j] = policies[i];
                    set = TRUE;
                    break;
                }
            }
            if (!set) {
                // we need to add
                this->policies_.length(this->policies_.length() + 1);
                this->policies_[this->policies_.length() - 1] = policies[i];
            }
        }
    }
    else {
        // incorrect value
        assert(0);
    }
}

//
// PolicyCurrent (CORBA 3.0)
//
#ifdef HAVE_THREADS
static void
__policy_current_cleanup(void* value)
{
    MICO::PolicyManager_impl* pm =
        static_cast<MICO::PolicyManager_impl*>(value);
    if (pm)
        delete pm;
}
#endif

MICO::PolicyCurrent_impl::PolicyCurrent_impl()
{
#ifdef HAVE_THREADS
    MICOMT::Thread::create_key(policy_current_key_, &__policy_current_cleanup);
#else // HAVE_THREADS
    this->manager_ = NULL;
#endif // HAVE_THREADS
}

MICO::PolicyCurrent_impl::~PolicyCurrent_impl()
{
#ifndef HAVE_THREADS
    if (this->manager_) {
        delete this->manager_;
        this->manager_ = NULL;
    }
#endif // HAVE_THREADS
}

PolicyList*
MICO::PolicyCurrent_impl::get_policy_overrides(const CORBA::PolicyTypeSeq& ts)
{
    PolicyManager_impl* pm = this->get_current_manager(FALSE);
    if (pm != NULL)
        return pm->get_policy_overrides(ts);
    return new PolicyList;
}

void
MICO::PolicyCurrent_impl::set_policy_overrides(const PolicyList& policies, SetOverrideType set_add)
{
    return this->get_current_manager(TRUE)->set_policy_overrides(policies, set_add);
}

MICO::PolicyManager_impl*
MICO::PolicyCurrent_impl::get_current_manager(Boolean create)
{
#ifdef HAVE_THREADS
    MICO::PolicyManager_impl* pm = static_cast<MICO::PolicyManager_impl*>
        (MICOMT::Thread::get_specific(policy_current_key_));
    if (pm == NULL && create) {
        pm = new PolicyManager_impl;
        MICOMT::Thread::set_specific(policy_current_key_, pm);
    }
    return pm;
#else // HAVE_THREADS
    if (this->manager_ == NULL && create)
        this->manager_ = new MICO::PolicyManager_impl;
    return this->manager_;
#endif // HAVE_THREADS
}

//-------------------


MICO::DomainManager_impl::DomainManager_impl ()
{
    _policies.length (1);
    _policies[0] = new MICO::ConstructionPolicy_impl;
}

MICO::DomainManager_impl::~DomainManager_impl ()
{
}

CORBA::Policy_ptr
MICO::DomainManager_impl::get_domain_policy (CORBA::PolicyType policy_type)
{
    // look only at this domain's policies
    for (CORBA::ULong i0 = 0; i0 < _policies.length(); ++i0) {
	if (_policies[i0]->policy_type() == policy_type)
	    return CORBA::Policy::_duplicate (_policies[i0]);
    }
    mico_throw (CORBA::INV_POLICY());
    return CORBA::Policy::_nil();
}

void
MICO::DomainManager_impl::set_domain_policy (CORBA::Policy_ptr policy)
{
    CORBA::PolicyType policy_type = policy->policy_type();
    for (CORBA::ULong i0 = 0; i0 < _policies.length(); ++i0) {
	if (_policies[i0]->policy_type() == policy_type) {
	    _policies[i0] = CORBA::Policy::_duplicate (policy);
	    return;
	}
    }
    _policies.length (_policies.length()+1);
    _policies[_policies.length()-1] = CORBA::Policy::_duplicate (policy);
}

CORBA::DomainManager_ptr
MICO::DomainManager_impl::copy ()
{
    DomainManager_impl *d = new DomainManager_impl;
    d->_managers = _managers;

    d->_policies.length (_policies.length());
    for (CORBA::ULong i = 0; i < _policies.length(); ++i)
	d->_policies[i] = _policies[i]->copy();

    return d;
}


//-------------------


MICO::ConstructionPolicy_impl::ConstructionPolicy_impl ()
    : MICO::Policy_impl(CORBA::SecConstruction)
{
}

MICO::ConstructionPolicy_impl::~ConstructionPolicy_impl ()
{
}

void
MICO::ConstructionPolicy_impl::make_domain_manager (
    CORBA::InterfaceDef_ptr in,
    CORBA::Boolean constr_policy)
{
    CORBA::InterfaceDef::FullInterfaceDescription_var idef =
	in->describe_interface();

    _constr[idef->id.in()] = constr_policy;
}

CORBA::Boolean
MICO::ConstructionPolicy_impl::constr_policy (CORBA::Object_ptr object)
{
    IdConstrMap::iterator i = _constr.find (object->_repoid());
    if (i != _constr.end())
	return (*i).second;
    return FALSE;
}

CORBA::Policy_ptr
MICO::ConstructionPolicy_impl::copy ()
{
    MICO::ConstructionPolicy_impl *p = new MICO::ConstructionPolicy_impl;
    p->_constr = _constr;
    return p;
}


//-------------------


MICO::TransportPrefPolicy_impl::TransportPrefPolicy_impl (
    const ProfileTagSeq &prefs)
    : MICO::Policy_impl(MICOPolicy::TRANSPORTPREF_POLICY_TYPE)
{
    _prefs = prefs;
}

MICO::TransportPrefPolicy_impl::TransportPrefPolicy_impl ()
    : MICO::Policy_impl(MICOPolicy::TRANSPORTPREF_POLICY_TYPE)
{
}

MICO::TransportPrefPolicy_impl::~TransportPrefPolicy_impl ()
{
}

MICOPolicy::TransportPrefPolicy::ProfileTagSeq *
MICO::TransportPrefPolicy_impl::preferences()
{
    return new ProfileTagSeq (_prefs);
}

void
MICO::TransportPrefPolicy_impl::preferences (const ProfileTagSeq &prefs)
{
    _prefs = prefs;
}

MICOPolicy::TransportPrefPolicy::ProfileTagSeq *
MICO::TransportPrefPolicy_impl::preferences_nocopy()
{
    // no copy ...
    return &_prefs;
}

CORBA::Policy_ptr
MICO::TransportPrefPolicy_impl::copy ()
{
    MICO::TransportPrefPolicy_impl *p = new MICO::TransportPrefPolicy_impl;
    p->_prefs = _prefs;
    return p;
}


//-------------------


MICO::BidirectionalPolicy_impl::BidirectionalPolicy_impl (
    BiDirPolicy::BidirectionalPolicyValue value)
    : MICO::Policy_impl(BiDirPolicy::BIDIRECTIONAL_POLICY_TYPE)
{
    _value = value;
}

MICO::BidirectionalPolicy_impl::BidirectionalPolicy_impl ()
    : MICO::Policy_impl(BiDirPolicy::BIDIRECTIONAL_POLICY_TYPE)
{
    _value = BiDirPolicy::NORMAL;
}

MICO::BidirectionalPolicy_impl::~BidirectionalPolicy_impl ()
{
}

BiDirPolicy::BidirectionalPolicyValue
MICO::BidirectionalPolicy_impl::value ()
{
    return _value;
}

CORBA::Policy_ptr
MICO::BidirectionalPolicy_impl::copy ()
{
    MICO::BidirectionalPolicy_impl *p = new MICO::BidirectionalPolicy_impl ();
    p->_value = _value;
    return p;
}


//-------------------

#ifdef USE_MESSAGING
MICO::RelativeConnectionBindingTimeoutPolicy_impl::RelativeConnectionBindingTimeoutPolicy_impl
(TimeBase::TimeT value)
    : Policy_impl(MICOPolicy::RELATIVE_CB_TIMEOUT_POLICY_TYPE), relative_expiry_(value)
{
    CORBA::Object::increase_timeout_policy_instance_counter();
}

MICO::RelativeConnectionBindingTimeoutPolicy_impl::~RelativeConnectionBindingTimeoutPolicy_impl()
{
    CORBA::Object::decrease_timeout_policy_instance_counter();
}

::CORBA::Policy_ptr
MICO::RelativeConnectionBindingTimeoutPolicy_impl::copy()
{
    return new RelativeConnectionBindingTimeoutPolicy_impl(this->relative_expiry_);
}

::TimeBase::TimeT
MICO::RelativeConnectionBindingTimeoutPolicy_impl::relative_expiry()
{
    return relative_expiry_;
}
#endif // USE_MESSAGING

//-------------------


CORBA::Policy_ptr
CORBA::ORB::create_policy (CORBA::PolicyType type, const CORBA::Any &any)
{
  if (type == PortableServer::THREAD_POLICY_ID) {
    PortableServer::ThreadPolicyValue val;
    if (!(any >>= val))
      mico_throw (CORBA::PolicyError (CORBA::BAD_POLICY_TYPE));
    return new MICOPOA::ThreadPolicy_impl (type, val);
  }
  else if (type == PortableServer::LIFESPAN_POLICY_ID) {
    PortableServer::LifespanPolicyValue val;
    if (!(any >>= val))
      mico_throw (CORBA::PolicyError (CORBA::BAD_POLICY_TYPE));
    return new MICOPOA::LifespanPolicy_impl (type, val);
  }
  else if (type == PortableServer::ID_UNIQUENESS_POLICY_ID) {
    PortableServer::IdUniquenessPolicyValue val;
    if (!(any >>= val))
      mico_throw (CORBA::PolicyError (CORBA::BAD_POLICY_TYPE));
    return new MICOPOA::IdUniquenessPolicy_impl (type, val);
  }
  else if (type == PortableServer::ID_ASSIGNMENT_POLICY_ID) {
    PortableServer::IdAssignmentPolicyValue val;
    if (!(any >>= val))
      mico_throw (CORBA::PolicyError (CORBA::BAD_POLICY_TYPE));
    return new MICOPOA::IdAssignmentPolicy_impl (type, val);
  }
  else if (type == PortableServer::IMPLICIT_ACTIVATION_POLICY_ID) {
    PortableServer::ImplicitActivationPolicyValue val;
    if (!(any >>= val))
      mico_throw (CORBA::PolicyError (CORBA::BAD_POLICY_TYPE));
    return new MICOPOA::ImplicitActivationPolicy_impl (type, val);
  }
  else if (type == PortableServer::SERVANT_RETENTION_POLICY_ID) {
    PortableServer::ServantRetentionPolicyValue val;
    if (!(any >>= val))
      mico_throw (CORBA::PolicyError (CORBA::BAD_POLICY_TYPE));
    return new MICOPOA::ServantRetentionPolicy_impl (type, val);
  }
  else if (type == PortableServer::REQUEST_PROCESSING_POLICY_ID) {
    PortableServer::RequestProcessingPolicyValue val;
    if (!(any >>= val))
      mico_throw (CORBA::PolicyError (CORBA::BAD_POLICY_TYPE));
    return new MICOPOA::RequestProcessingPolicy_impl (type, val);
  }
  else if (type == MICOPolicy::TRANSPORTPREF_POLICY_TYPE) {
    MICOPolicy::TransportPrefPolicy::ProfileTagSeq val;
    if (!(any >>= val))
      mico_throw (CORBA::PolicyError (CORBA::BAD_POLICY_TYPE));
    return new MICO::TransportPrefPolicy_impl (val);
  }
  else if (type == BiDirPolicy::BIDIRECTIONAL_POLICY_TYPE) {
    BiDirPolicy::BidirectionalPolicyValue val;
    if (!(any >>= val))
      mico_throw (CORBA::PolicyError (CORBA::BAD_POLICY_TYPE));
    return new MICO::BidirectionalPolicy_impl (val);
  }
#ifdef USE_MESSAGING
  else if (type == Messaging::RELATIVE_RT_TIMEOUT_POLICY_TYPE) {
    TimeBase::TimeT val;
    if (!(any >>= val))
      mico_throw(CORBA::PolicyError(CORBA::BAD_POLICY_TYPE));
    return new MICO::RelativeRoundtripTimeoutPolicy_impl(val);
  }
  else if (type == MICOPolicy::RELATIVE_CB_TIMEOUT_POLICY_TYPE) {
    TimeBase::TimeT val;
    if (!(any >>= val))
      mico_throw(CORBA::PolicyError(CORBA::BAD_POLICY_TYPE));
    return new MICO::RelativeConnectionBindingTimeoutPolicy_impl(val);
  }
#endif // USE_MESSAGING
#ifdef THREADING_POLICIES
  else if (type == MICOMT::SERVER_CONCURRENCY_MODEL_POLICY_TYPE) {
    MICOMT::ServerConcurrencyModel val;
    if (!(any >>= val))
      mico_throw(CORBA::PolicyError(CORBA::BAD_POLICY_TYPE));
    return new MICOMT::ServerConcurrencyModelPolicy_impl(val);
  }
  else if (type == MICOMT::CLIENT_CONCURRENCY_MODEL_POLICY_TYPE) {
    MICOMT::ClientConcurrencyModel val;
    if (!(any >>= val))
      mico_throw(CORBA::PolicyError(CORBA::BAD_POLICY_TYPE));
    return new MICOMT::ClientConcurrencyModelPolicy_impl(val);
  }
  else if (type == MICOMT::CONNECTION_LIMIT_POLICY_TYPE) {
    CORBA::ULong val;
    if (!(any >>= val))
      mico_throw(CORBA::PolicyError(CORBA::BAD_POLICY_TYPE));
    return new MICOMT::ConnectionLimitPolicy_impl(val);
  }
  else if (type == MICOMT::REQUEST_LIMIT_POLICY_TYPE) {
    CORBA::ULong val;
    if (!(any >>= val))
      mico_throw(CORBA::PolicyError(CORBA::BAD_POLICY_TYPE));
    return new MICOMT::RequestLimitPolicy_impl(val);
  }
#endif // THREADING_POLICIES
  else if (PInterceptor::PI::S_pfmap_.find(type)
	   != PInterceptor::PI::S_pfmap_.end()) {
    return PInterceptor::PI::S_pfmap_[type]->create_policy
      (type, any); // see orbos/99-12-02 p. 8-67
  }
  mico_throw (CORBA::PolicyError (CORBA::BAD_POLICY_TYPE));
  // Make Sun CC happy
  return CORBA::Policy::_nil ();
}
