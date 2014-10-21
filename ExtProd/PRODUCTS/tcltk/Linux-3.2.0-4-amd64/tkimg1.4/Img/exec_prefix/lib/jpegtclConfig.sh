# jpegtclConfig.sh --
#
# This shell script (for sh) is generated automatically by jpegtcl's
# configure script.  It will create shell variables for most of
# the configuration options discovered by the configure script.
# This script is intended to be included by the configure scripts
# for jpegtcl extensions so that they don't have to figure this all
# out for themselves.  This file does not duplicate information
# already provided by tclConfig.sh, so you may need to use that
# file in addition to this one.
#
# The information in this file is specific to a single platform.

# jpegtcl's version number.
jpegtcl_VERSION='8.2'
jpegtcl_MAJOR_VERSION=''
jpegtcl_MINOR_VERSION=''
jpegtcl_RELEASE_LEVEL=''

# The name of the jpegtcl library (may be either a .a file or a shared library):
jpegtcl_LIB_FILE=libjpegtcl8.2.so

# String to pass to linker to pick up the jpegtcl library from its
# build directory.
jpegtcl_BUILD_LIB_SPEC='-L/home/almamgr/ACS_javarias/ExtProd/PRODUCTS/tcltk/Linux-3.2.0-4-amd64/tkimg1.4/libjpeg -ljpegtcl8.2'

# String to pass to linker to pick up the jpegtcl library from its
# installed directory.
jpegtcl_LIB_SPEC='-L/alma/ACS-2014.4/tcltk/lib/Img1.4 -ljpegtcl8.2'

# The name of the jpegtcl stub library (a .a file):
jpegtcl_STUB_LIB_FILE=libjpegtclstub8.2.a

# String to pass to linker to pick up the jpegtcl stub library from its
# build directory.
jpegtcl_BUILD_STUB_LIB_SPEC='-L/home/almamgr/ACS_javarias/ExtProd/PRODUCTS/tcltk/Linux-3.2.0-4-amd64/tkimg1.4/libjpeg -ljpegtclstub8.2'

# String to pass to linker to pick up the jpegtcl stub library from its
# installed directory.
jpegtcl_STUB_LIB_SPEC='-L/alma/ACS-2014.4/tcltk/lib/Img1.4 -ljpegtclstub8.2'

# String to pass to linker to pick up the jpegtcl stub library from its
# build directory.
jpegtcl_BUILD_STUB_LIB_PATH='/home/almamgr/ACS_javarias/ExtProd/PRODUCTS/tcltk/Linux-3.2.0-4-amd64/tkimg1.4/libjpeg/libjpegtclstub8.2.a'

# String to pass to linker to pick up the jpegtcl stub library from its
# installed directory.
jpegtcl_STUB_LIB_PATH='/alma/ACS-2014.4/tcltk/lib/Img1.4/libjpegtclstub8.2.a'

# Location of the top-level source directories from which jpegtcl
# was built.  This is the directory that contains generic, unix, etc.
# If jpegtcl was compiled in a different place than the directory
# containing the source files, this points to the location of the
# sources, not the location where jpegtcl was compiled. This can
# be relative to the build directory.

jpegtcl_SRC_DIR='.'
