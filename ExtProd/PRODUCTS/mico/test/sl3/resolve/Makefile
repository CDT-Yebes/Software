
include ../../../MakeVars

CXXFLAGS := -I../../../include $(CXXFLAGS) #$(EHFLAGS)
LDFLAGS  := -L../../../orb $(LDFLAGS) 
LDLIBS    = -lmico$(VERSION) $(CONFLIBS)

all: .depend main

main: main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@
	$(POSTLD) $@                                                            

clean:
	$(RM) -f *.o core main *.ref *~ .depend

check:
	@./main > log
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
