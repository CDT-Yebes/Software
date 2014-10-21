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

LDLIBS    = -lidl -lmico$(VERSION) $(CONFLIBS)
LDFLAGS  := -L../idl -L../orb $(LDFLAGS)
CXXFLAGS := -DCPP=\"mico-cpp\" -I. -I../idl -I../include $(CXXFLAGS)

ifeq ($(HAVE_EXCEPTIONS), yes)
NOPICFLAGS := $(NOPICFLAGS) $(EHOPTFLAGS)
endif
ifeq ($(HAVE_SHARED_EXCEPTS), yes)
PICFLAGS := $(PICFLAGS) $(EHOPTFLAGS)
endif

# generated files

ifeq ($(HAVE_FINAL), yes)
STATIC_OBJS=AuditClientIntercept.o AuditOptions.o AuditServIntercept.o \
audit_impl.o security.o securitylevel1.o securitylevel1_impl.o \
securitylevel2.o securitylevel2_impl.o ODMConfig.o DomainManager.o \
odm.o odm_impl.o DomainManager_impl.o AccessConfig.o RightsConfig.o \
SecurityAdmin_impl.o
else
STATIC_OBJS=AuditClientIntercept.o AuditOptions.o AuditServIntercept.o \
audit_impl.o security.o securitylevel1.o securitylevel1_impl.o \
securitylevel2.o securitylevel2_impl.o ODMConfig.o DomainManager.o \
odm.o odm_impl.o DomainManager_impl.o AccessConfig.o RightsConfig.o \
SecurityAdmin_impl.o
endif
SHARED_OBJS=$(STATIC_OBJS:.o=.pic.o)

ifeq ($(HAVE_SHARED), yes)
ifeq ($(HAVE_EXCEPTIONS), yes)
ifeq ($(HAVE_SHARED_EXCEPTS), no)
IR_OBJS=ir_impl.o
endif
endif
endif

# normal rules

all:
	cd ..; make

ifeq ($(HAVE_SHARED), yes)
ifeq ($(HAVE_STATIC), yes)
lib: .depend $(STATIC_OBJS) $(SHARED_OBJS) 
else
lib: .depend $(SHARED_OBJS)
endif
else
lib: .depend $(STATIC_OBJS)
endif

prg: .depend

generate: csi-base-generate csl2-generate csiv2-generate sl3-touch sl3-generate atlas-generate

csi-base-generate:
	$(IDL) --windows-dll mico -B.. --no-poa \
		--pseudo --any --mico-core \
		../../include/mico/security/csi_base.idl
	mv csi_base.h ../../include/mico/security/csi_base.h

csl2-generate:
	$(IDL)  --any --name security --windows-dll mico --pseudo \
		--mico-core -B../.. \
		../../include/mico/security/security.idl
	mv security.h ../../include/mico/security/security.h
	$(IDL)  --name securitylevel1 --windows-dll mico --pseudo \
	     	--mico-core -B../.. \
		../../include/mico/security/securitylevel1.idl
	mv securitylevel1.h ../../include/mico/security/securitylevel1.h
	$(IDL)  --name securitylevel2 --windows-dll mico --pseudo \
	     	--mico-core -B../.. \
		../../include/mico/security/securitylevel2.idl
	mv securitylevel2.h ../../include/mico/security/securitylevel2.h
	$(IDL)  --any --name SecurityAdmin --windows-dll mico --pseudo \
		     	--mico-core -B../.. \
			../../include/mico/security/SecurityAdmin.idl
	mv SecurityAdmin.h ../../include/mico/security/SecurityAdmin.h
	$(IDL)  --windows-dll mico --pseudo --mico-core \
		-B../.. --name DomainManager \
		../../include/mico/security/DomainManager.idl
	mv DomainManager.h ../../include/mico/security/DomainManager.h
#	flex -+ -Podm -oODMConfig.cc odmconf.lex
#	flex -+ -Pac -oAccessConfig.cc accessconf.lex
#	flex -+ -Prr -oRightsConfig.cc rightsconf.lex
#	flex -+ -Pau -oAuditConfig.cc auditconf.lex
	$(IDL)  --windows-dll mico --pseudo --mico-core \
		-B../.. --name odm \
		../../include/mico/security/odm.idl
	mv odm.h ../../include/mico/security/odm.h


csiv2-generate:
	$(IDL) --windows-dll mico -B../.. --no-poa \
		--pseudo --any --mico-core ../../include/mico/security/csi.idl
	mv csi.h ../../include/mico/security/csi.h
	$(IDL) --windows-dll mico -B../.. --no-poa \
		--pseudo --any --mico-core ../../include/mico/security/csiiop.idl
	mv csiiop.h ../../include/mico/security/csiiop.h
	$(IDL) --windows-dll mico -B../.. --no-poa \
		--pseudo --any --mico-core ../../include/mico/security/gssup.idl
	mv gssup.h ../../include/mico/security/gssup.h
	$(IDL) --windows-dll mico -B../.. --no-poa \
		--pseudo --any --mico-core ../../include/mico/security/csiv2.idl
	mv csiv2.h ../../include/mico/security/csiv2.h

IDLFLAGS=--windows-dll mico -B../.. -I../../include --no-poa \
		--pseudo --any --mico-core

SL3GENFILES=sl3pm.cc sl3cm.cc sl3om.cc securitylevel3.cc transportsecurity.cc \
	transportsecurity_p.cc sl3aqargs.cc sl3tcpip.cc sl3tls.cc sl3aqargs_p.cc \
	sl3csi.cc userpassword.cc trust.cc sl3authorization.cc sl3omext.cc

sl3-generate: $(SL3GENFILES)

sl3-touch:
	touch ../../include/mico/security/sl3pm.idl
	touch ../../include/mico/security/sl3cm.idl
	touch ../../include/mico/security/sl3om.idl
	touch ../../include/mico/security/securitylevel3.idl
	touch ../../include/mico/security/transportsecurity.idl
	touch ../../include/mico/security/transportsecurity_p.idl
	touch ../../include/mico/security/sl3aqargs.idl
	touch ../../include/mico/security/sl3tcpip.idl
	touch ../../include/mico/security/sl3tls.idl
	touch ../../include/mico/security/sl3aqargs_p.idl
	touch ../../include/mico/security/sl3csi.idl
	touch ../../include/mico/security/userpassword.idl
	touch ../../include/mico/security/trust.idl
	touch ../../include/mico/security/sl3authorization.idl
	touch ../../include/mico/security/sl3omext.idl

atlas-generate:
	$(IDL) --windows-dll mico -B../.. -I../../include \
		--any --mico-core \
		../../include/mico/security/atlas.idl
	mv atlas.h ../../include/mico/security/atlas.h

ac-generate:
#
# kcg: esnacc is quite sensitive to setuped include directories.
#      In case you would like to regenerate acext.cc/h, please
#      change the directory below to point correctly to your smp
#      installation.
#
	$(SNACC) -C -I$(HOME)/usr/local/smp23-icc8/include/smp/Modules \
		../../include/mico/security/acext.asn1
	mv acext.cpp acext.cc
	cp acext.h ../../include/mico/security/acext.h


%.cc ../../include/mico/security/%.h: ../../include/mico/security/%.idl
	$(IDL) $(IDLFLAGS) $<
	mv $(subst .idl,.h,$(<F)) $(<D)/$(subst .idl,.h,$(<F))

diffs:

clean:
	-$(RM) -f libs
	-$(RM) *.o *.o0 *.a *~ *.rpo *.objid ird
	-$(RM) .depend TAGS core nohup.out

install:

install-cd: install

ifeq (.depend, $(wildcard .depend))
include .depend
endif

.depend :
	echo '# Module dependencies' > .depend
	$(MKDEPEND) $(CXXFLAGS) *.cc >> .depend




