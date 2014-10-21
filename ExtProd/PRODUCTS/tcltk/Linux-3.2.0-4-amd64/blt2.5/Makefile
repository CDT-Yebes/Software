# Generated automatically from Makefile.in by configure.
# ------------------------------------------------------------------------
#       Makefile for BLT distribution
# ------------------------------------------------------------------------

# ------------------------------------------------------------------------
#       Source and target installation directories
# ------------------------------------------------------------------------

prefix =	/alma/ACS-2014.4/tcltk
exec_prefix  =	/alma/ACS-2014.4/tcltk
srcdir =	.
bindir =	${exec_prefix}/bin
includedir =	${prefix}/include
libdir =	/alma/ACS-2014.4/tcltk/lib
version =	2.5
scriptdir =	$(prefix)/lib/blt$(version)

instdirs =	$(prefix) \
		$(exec_prefix) \
		$(bindir) \
		$(libdir) \
		$(includedir) \
		$(scriptdir)

# ------------------------------------------------------------------------
#       Don't edit anything beyond this point
# ------------------------------------------------------------------------

INSTALL =	/usr/bin/install -c
INSTALL_DATA =	${INSTALL} -m 644
INSTALL_ROOT = 
SHELL =		/bin/sh
RM =		rm -f

subdirs =	generic library man demos 

all:  
	(cd generic; $(MAKE) all)
	(cd library; $(MAKE) all)
	(cd man; $(MAKE) all)
	(cd demos; $(MAKE) all)

install: mkdirs install-all 

install-all:
	(cd generic; $(MAKE) install)
	(cd library; $(MAKE) install)
	(cd man; $(MAKE) install)
	(cd demos; $(MAKE) install)
	$(INSTALL_DATA) $(srcdir)/README $(INSTALL_DIR)$(scriptdir)
	$(INSTALL_DATA) $(srcdir)/PROBLEMS $(INSTALL_DIR)$(scriptdir)
	$(INSTALL_DATA) $(srcdir)/NEWS $(INSTALL_DIR)$(scriptdir)

mkdirs:
	@for i in $(instdirs) ; do \
          if test -d $(INSTALL_ROOT)$$i ; then \
	    : ; \
	  else \
            echo " mkdir $(INSTALL_ROOT)$$i" ; \
            mkdir $(INSTALL_ROOT)$$i ; \
          fi ; \
        done

clean:
	(cd generic; $(MAKE) clean)
	(cd library; $(MAKE) clean)
	(cd man; $(MAKE) clean)
	(cd demos; $(MAKE) clean)
	$(RM) *.bak *\~ "#"* *pure* .pure*

GENERATED_FILES = \
	config.status config.cache config.log Makefile 

distclean: clean
	$(RM) $(GENERATED_FILES)
