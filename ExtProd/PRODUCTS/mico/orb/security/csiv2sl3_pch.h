//
// This file aims to speed-up MICO compilation
// while using precompiled-headers
//

#include <CORBA.h>

// CSIv2
#include <mico/security/csiv2_impl.h>

// SL3
#ifdef USE_SL3
#include <mico/security/sl3pm_impl.h>
#include <mico/security/sl3csi_impl.h>
#include <mico/security/transportsecurity_impl.h>
#include <mico/security/securitylevel3_impl.h>
#include <mico/security/sl3aqargs_impl.h>
#include <mico/security/sl3aqargs_p_impl.h>
#include <mico/security/sl3utils.h>
#include <mico/security/sl3tcpip_impl.h>
#include <mico/security/sl3tls_impl.h>
#include <mico/security/sl3ac.h>
#include <mico/security/sl3ipc_impl.h>
#endif // USE_SL3

// Others
#include <mico/codec_impl.h>
#include <mico/util.h>
#include <mico/impl.h>
#include <mico/ssl.h>
#include <iostream>
#include <iomanip>
#ifdef USE_SL3
#include <sstream>
#endif // USE_SL3
