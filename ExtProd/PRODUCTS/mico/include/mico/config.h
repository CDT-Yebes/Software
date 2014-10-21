/* include/mico/config.h.  Generated automatically by configure.  */
/* include/mico/config.h.in.  Generated automatically from configure.in by autoheader.  */

/* Define if you don't have vprintf but do have _doprnt.  */
/* #undef HAVE_DOPRNT */

/* Define if you have the vprintf function.  */
#define HAVE_VPRINTF 1

/* Define if you need to in order for stat and other things to work.  */
/* #undef _POSIX_SOURCE */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#define TIME_WITH_SYS_TIME 1

/* Define if your processor stores words with the most significant
   byte first (like Motorola and SPARC, unlike Intel and VAX).  */
/* #undef WORDS_BIGENDIAN */

/* Define if the X Window System is missing or not being used.  */
#define X_DISPLAY_MISSING 1

/* whether or not --enable-mini-stl is used */
/* #undef HAVE_MINI_STL */

/* whether CORBASec Level 2 is used */
/* #undef USE_CSL2 */

/* whether CSIv2 is used */
#define USE_CSIV2 1

/* whether SL3 is used */
#define USE_SL3 1

/* whether anything wireless is built */
/* #undef USE_WIRELESS */

/* whether we have byteorder big endian */
/* #undef HAVE_BYTEORDER_BE */

/* whether we have byteorder little endian */
#define HAVE_BYTEORDER_LE 1

/* whether we have a prototype for gethostname */
#define HAVE_GETHOSTNAME_PROTO 1

/* whether we have a prototype for finite */
#define HAVE_FINITE_PROTO 1

/* whether we have a prototype for strerror */
#define HAVE_STRERROR_PROTO 1

/* whether we have a prototype for ftime */
#define HAVE_FTIME_PROTO 1

/* whether C++ compiler supports exception handling */
#define HAVE_EXCEPTS 1

/* whether C++ compiler supports exceptions in shared libs */
#define HAVE_SHARED_EXCEPTS 1

/* whether C++ compiler supports standard exception handling */
#define HAVE_STD_EH 1

/* whether to built ORB with exception support */
#define HAVE_ORB_EXCEPTS 1

/* whether we need to explicitely call global ctors in dlopen()ed module */
/* #undef HAVE_EXPLICIT_CTORS */

/* whether we have IEEE compliant floating point types */
#define HAVE_IEEE_FP 1

/* whether or not class foo { friend void f <> (); } works */
#define HAVE_GUIDING_DECLS 1

/* whether or not namespaces work */
#define HAVE_NAMESPACE 1

/* type of size argument to socket calls */
#define socket_size_t socklen_t

/* type of sockaddr argument to socket calls */
#define socket_addr_t struct sockaddr *

/* type of fd_set arguments to select calls */
#define select_addr_t fd_set *

/* whether gettimeofday has two args */
#define HAVE_GETTIMEOFDAY_TWOARGS 1

/* whether or not he have SSLeay */
#define HAVE_SSL 1

/* whether or not he have Postgresql */
/* #undef HAVE_PGSQL */

/* whether or not we have Bluetooth */
/* #undef HAVE_BLUETOOTH */

/* whether or not bool is supported by C++ compiler */
#define HAVE_BOOL_TYPE 1

/* whether or not typename is supported by C++ compiler */
#define HAVE_TYPENAME 1
/* #undef typename */

/* whether or not scanf ("%Lf", ...) works */
#define HAVE_SCANF_LF 1

/* whether or not printf ("%Lf", ...) works */
#define HAVE_PRINTF_LF 1

/* whether the system supports dynamic module loading */
#define HAVE_DYNAMIC 1

/* whether c++ compiler supports const overload of conversion operators */
/* #undef HAVE_CONST_OVERLOAD */

/* whether virtual methods inherited from two or more base class must be
   overridden */
#define HAVE_EXPLICIT_METHOD_OVERRIDE 1

/* whether the compiler fails to automatically generate working
   copy constructors, assignment operators and destructors on structs
   with template members */
/* #undef HAVE_EXPLICIT_STRUCT_OPS */

/* whether we can use the advanced memchecker */
/* #undef USE_MEMTRACE */

/* whether a derived class can override a typedef in the base class */
#define HAVE_TYPEDEF_OVERLOAD 1

/* Define if you have the <pth.h> header file.  */
/* #undef HAVE_PTH_H */

/* Define if you have pthread support */
#define HAVE_PTHREADS 1

/* Define if you have DCE thread support */
/* #undef HAVE_DCE_THREADS */

/* Define if you have Solaris thread support */
/* #undef HAVE_SOLARIS_THREADS */

/* Define if you have GNU Pth thread support */
/* #undef HAVE_PTH_THREADS */

/* Define if you want thread support at all */
#define HAVE_THREADS 1

/* whether we support dynamic_cast<> */
#define HAVE_DYNAMIC_CAST 1

/* whether to build CCM-specific parts */
/* #undef USE_CCM */

/* whether to build CORBA messaging specific parts */
#define USE_MESSAGING 1

/* path information */
#define ABSEXECDIR "/alma/ACS-2014.4/mico"
#define ABSSHRDDIR "/alma/ACS-2014.4/mico"

/* whether ANSI C++ header files are present */
#define HAVE_ANSI_CPLUSPLUS_HEADERS 1

/* whether to build Threading Policies API */
#define THREADING_POLICIES 1

/* The number of bytes in a double.  */
#define SIZEOF_DOUBLE 8

/* The number of bytes in a float.  */
#define SIZEOF_FLOAT 4

/* The number of bytes in a int.  */
#define SIZEOF_INT 4

/* The number of bytes in a long.  */
#define SIZEOF_LONG 8

/* The number of bytes in a long double.  */
#define SIZEOF_LONG_DOUBLE 16

/* The number of bytes in a long long.  */
#define SIZEOF_LONG_LONG 8

/* The number of bytes in a short.  */
#define SIZEOF_SHORT 2

/* The number of bytes in a unsigned char.  */
#define SIZEOF_UNSIGNED_CHAR 1

/* The number of bytes in a unsigned int.  */
#define SIZEOF_UNSIGNED_INT 4

/* The number of bytes in a unsigned long.  */
#define SIZEOF_UNSIGNED_LONG 8

/* The number of bytes in a unsigned long long.  */
#define SIZEOF_UNSIGNED_LONG_LONG 8

/* The number of bytes in a unsigned short.  */
#define SIZEOF_UNSIGNED_SHORT 2

/* Define if you have the __cxa_demangle function.  */
#define HAVE___CXA_DEMANGLE 1

/* Define if you have the asinl function.  */
#define HAVE_ASINL 1

/* Define if you have the backtrace function.  */
#define HAVE_BACKTRACE 1

/* Define if you have the backtrace_symbols function.  */
#define HAVE_BACKTRACE_SYMBOLS 1

/* Define if you have the ceill function.  */
#define HAVE_CEILL 1

/* Define if you have the dlopen function.  */
#define HAVE_DLOPEN 1

/* Define if you have the fabsl function.  */
#define HAVE_FABSL 1

/* Define if you have the finite function.  */
#define HAVE_FINITE 1

/* Define if you have the floorl function.  */
#define HAVE_FLOORL 1

/* Define if you have the fmodl function.  */
#define HAVE_FMODL 1

/* Define if you have the frexpl function.  */
#define HAVE_FREXPL 1

/* Define if you have the ftime function.  */
#define HAVE_FTIME 1

/* Define if you have the gethostname function.  */
#define HAVE_GETHOSTNAME 1

/* Define if you have the infnan function.  */
/* #undef HAVE_INFNAN */

/* Define if you have the infnanl function.  */
/* #undef HAVE_INFNANL */

/* Define if you have the isinf function.  */
#define HAVE_ISINF 1

/* Define if you have the isinfl function.  */
#define HAVE_ISINFL 1

/* Define if you have the isnan function.  */
#define HAVE_ISNAN 1

/* Define if you have the isnanl function.  */
#define HAVE_ISNANL 1

/* Define if you have the ldexpl function.  */
#define HAVE_LDEXPL 1

/* Define if you have the powl function.  */
#define HAVE_POWL 1

/* Define if you have the shl_load function.  */
/* #undef HAVE_SHL_LOAD */

/* Define if you have the strdup function.  */
#define HAVE_STRDUP 1

/* Define if you have the strerror function.  */
#define HAVE_STRERROR 1

/* Define if you have the <arpa/inet.h> header file.  */
#define HAVE_ARPA_INET_H 1

/* Define if you have the <bfd.h> header file.  */
/* #undef HAVE_BFD_H */

/* Define if you have the <byteorder.h> header file.  */
/* #undef HAVE_BYTEORDER_H */

/* Define if you have the <cxxabi.h> header file.  */
#define HAVE_CXXABI_H 1

/* Define if you have the <dl.h> header file.  */
/* #undef HAVE_DL_H */

/* Define if you have the <dlfcn.h> header file.  */
#define HAVE_DLFCN_H 1

/* Define if you have the <exception> header file.  */
#define HAVE_EXCEPTION 1

/* Define if you have the <exception.h> header file.  */
/* #undef HAVE_EXCEPTION_H */

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <float.h> header file.  */
#define HAVE_FLOAT_H 1

/* Define if you have the <ieeefp.h> header file.  */
/* #undef HAVE_IEEEFP_H */

/* Define if you have the <iostream> header file.  */
#define HAVE_IOSTREAM 1

/* Define if you have the <link.h> header file.  */
/* #undef HAVE_LINK_H */

/* Define if you have the <map> header file.  */
#define HAVE_MAP 1

/* Define if you have the <netdb.h> header file.  */
#define HAVE_NETDB_H 1

/* Define if you have the <netinet/in.h> header file.  */
#define HAVE_NETINET_IN_H 1

/* Define if you have the <netinet/tcp.h> header file.  */
#define HAVE_NETINET_TCP_H 1

/* Define if you have the <openssl/ssl.h> header file.  */
#define HAVE_OPENSSL_SSL_H 1

/* Define if you have the <pgsql/libpq-fe.h> header file.  */
/* #undef HAVE_PGSQL_LIBPQ_FE_H */

/* Define if you have the <poll.h> header file.  */
#define HAVE_POLL_H 1

/* Define if you have the <pthread.h> header file.  */
#define HAVE_PTHREAD_H 1

/* Define if you have the <qapplication.h> header file.  */
/* #undef HAVE_QAPPLICATION_H */

/* Define if you have the <qlineedit.h> header file.  */
/* #undef HAVE_QLINEEDIT_H */

/* Define if you have the <qsocketnotifier.h> header file.  */
/* #undef HAVE_QSOCKETNOTIFIER_H */

/* Define if you have the <sched.h> header file.  */
#define HAVE_SCHED_H 1

/* Define if you have the <semaphore.h> header file.  */
#define HAVE_SEMAPHORE_H 1

/* Define if you have the <sstream> header file.  */
#define HAVE_SSTREAM 1

/* Define if you have the <stdlib.h> header file.  */
#define HAVE_STDLIB_H 1

/* Define if you have the <string> header file.  */
#define HAVE_STRING 1

/* Define if you have the <strings.h> header file.  */
#define HAVE_STRINGS_H 1

/* Define if you have the <sunmath.h> header file.  */
/* #undef HAVE_SUNMATH_H */

/* Define if you have the <synch.h> header file.  */
/* #undef HAVE_SYNCH_H */

/* Define if you have the <sys/select.h> header file.  */
#define HAVE_SYS_SELECT_H 1

/* Define if you have the <sys/stat.h> header file.  */
#define HAVE_SYS_STAT_H 1

/* Define if you have the <sys/time.h> header file.  */
#define HAVE_SYS_TIME_H 1

/* Define if you have the <sys/un.h> header file.  */
#define HAVE_SYS_UN_H 1

/* Define if you have the <terminate.h> header file.  */
/* #undef HAVE_TERMINATE_H */

/* Define if you have the <thread.h> header file.  */
/* #undef HAVE_THREAD_H */

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the Hcurses library (-lHcurses).  */
/* #undef HAVE_LIBHCURSES */

/* Define if you have the bfd library (-lbfd).  */
/* #undef HAVE_LIBBFD */

/* Define if you have the bluetooth library (-lbluetooth).  */
/* #undef HAVE_LIBBLUETOOTH */

/* Define if you have the bsd library (-lbsd).  */
/* #undef HAVE_LIBBSD */

/* Define if you have the crypto library (-lcrypto).  */
#define HAVE_LIBCRYPTO 1

/* Define if you have the curses library (-lcurses).  */
/* #undef HAVE_LIBCURSES */

/* Define if you have the dl library (-ldl).  */
#define HAVE_LIBDL 1

/* Define if you have the dld library (-ldld).  */
/* #undef HAVE_LIBDLD */

/* Define if you have the elf library (-lelf).  */
/* #undef HAVE_LIBELF */

/* Define if you have the iberty library (-liberty).  */
/* #undef HAVE_LIBIBERTY */

/* Define if you have the ld library (-lld).  */
/* #undef HAVE_LIBLD */

/* Define if you have the m library (-lm).  */
#define HAVE_LIBM 1

/* Define if you have the ncurses library (-lncurses).  */
/* #undef HAVE_LIBNCURSES */

/* Define if you have the nsl library (-lnsl).  */
/* #undef HAVE_LIBNSL */

/* Define if you have the pq library (-lpq).  */
/* #undef HAVE_LIBPQ */

/* Define if you have the readline library (-lreadline).  */
/* #undef HAVE_LIBREADLINE */

/* Define if you have the socket library (-lsocket).  */
/* #undef HAVE_LIBSOCKET */

/* Define if you have the ssl library (-lssl).  */
#define HAVE_LIBSSL 1

/* Define if you have the termcap library (-ltermcap).  */
/* #undef HAVE_LIBTERMCAP */

/* Define if you have the wsock32 library (-lwsock32).  */
/* #undef HAVE_LIBWSOCK32 */
