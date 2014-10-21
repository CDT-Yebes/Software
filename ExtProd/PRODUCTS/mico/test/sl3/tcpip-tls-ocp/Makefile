
include ../../../MakeVars

CXXFLAGS := -I. -I../../../include $(CXXFLAGS) #$(EHFLAGS)
LDFLAGS  := -L../../../orb $(LDFLAGS) 
LDLIBS    = -lmico$(VERSION) $(CONFLIBS)

all: .depend client client-tcpip server

client:	hello.o client.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@
	$(POSTLD) $@                                                            

client-tcpip: hello.o client-tcpip.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@
	$(POSTLD) $@

server:	hello.o server.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@
	$(POSTLD) $@                                                            

hello.cc hello.h : hello.idl
	$(IDL) hello.idl                                            

clean:
	$(RM) -f *.o core server client client-tcpip hello.h hello.cc *.ref *~ .depend

check:
	@./hello|grep -v "Establish" > log
	@if cmp expected-output log >/dev/null; then : ; \
	else echo "FAILED:"; echo "===============================" ; \
	diff -u expected-output log ; \
	echo "==============================="; fi
	@rm -f log

ifeq (.depend, $(wildcard .depend))
include .depend
endif

.depend:
	echo "# module dependencies" > .depend
	$(MKDEPEND) $(CXXFLAGS) *.cc >> .depend
