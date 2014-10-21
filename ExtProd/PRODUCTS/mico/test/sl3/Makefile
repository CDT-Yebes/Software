#
# MICO --- a free CORBA implementation
# Copyright (C) 1997 Kay Roemer & Arno Puder
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
# Send comments and/or bug reports to:
#                mico@informatik.uni-frankfurt.de
#

include ../../MakeVars

DIRS = resolve tcpip user-pass-tcpip tls user-pass-tls \
  tls-anon user-pass-tls-anon tls-naming user-pass-tcpip-identity \
  tcpip-cep tls-cep tcpip-tls-cep tcpip-tls-cep2 tcpip-tls-priority \
  tcpip-tls-priority2 user-pass-tcpip-cep user-pass-tcpip-cep-identity \
  relay-tcpip relay-tcpip2 ipc ipc-tcpip user-pass-ipc tcpip-release \
  tls-release user-pass-tcpip-release tcpip-cmdext tls-cmdext \
  user-pass-tcpip-cmdext user-pass-tls-plain-tls-client \
  user-pass-tls-trust-decider tcpip-wo-creds tls-wo-creds tcpip-identity \
  tcpip-ocp tls-ocp tcpip-tls-ocp tcpip-oneway

ifeq ($(HAVE_SNACC), yes)
ifeq ($(HAVE_SMP), yes)
DIRS := $(DIRS) atlas-tcpip atlas-relay-tcpip
endif
endif

all: prg

prg:
	for i in $(DIRS); do $(MAKE) -C $$i || exit 1; done

check:
	for i in $(DIRS); do $(MAKE) -C $$i check || exit 1; done

clean:
	for i in $(DIRS); do $(MAKE) -C $$i clean || exit 1; done

install:
