
include ../../../MakeVars

CXXFLAGS := -I../../../include $(CXXFLAGS) #$(EHFLAGS)
LDFLAGS  := -L../../../orb $(LDFLAGS) 
LDLIBS    = -lmico$(VERSION) $(CONFLIBS)

all: .depend client server relay

client:	hello.o client.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@
	$(POSTLD) $@                                                            

server:	hello.o server.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@
	$(POSTLD) $@                                                            

relay:	hello.o relay.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@
	$(POSTLD) $@                                                            

hello.cc hello.h : hello.idl
	$(IDL) hello.idl                                            

clean:
	$(RM) -f *.o core server client relay hello.h hello.cc *.ref *~ .depend

check:
	@if test -f atlas.ref; then \
	./hello|grep -v "Establish"|grep -v "ChannelIdentifier"|grep -v "LocalAddress" > log; \
	if cmp expected-output log >/dev/null; then : ; \
	else echo "FAILED:"; echo "===============================" ; \
	diff -u expected-output log ; \
	echo "==============================="; fi; \
	rm -f log; \
	else echo "You need to provide ATLAS reference in atlas.ref file to run this test"; fi

ifeq (.depend, $(wildcard .depend))
include .depend
endif

.depend:
	echo "# module dependencies" > .depend
	$(MKDEPEND) $(CXXFLAGS) *.cc >> .depend
