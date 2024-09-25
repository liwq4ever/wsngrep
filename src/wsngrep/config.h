#pragma once
/* src/config.h.  Generated from config.h.in by configure.  */
/* src/config.h.in.  Generated from configure.ac by autoheader.  */

/* Define to 1 if you have the `fopencookie' function. */
#define HAVE_FOPENCOOKIE 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `form' library (-lform). */
#define HAVE_LIBFORM 1

/* Define to 1 if you have the `formw' library (-lformw). */
/* #undef HAVE_LIBFORMW */

/* Define to 1 if you have the `menu' library (-lmenu). */
#define HAVE_LIBMENU 1

/* Define to 1 if you have the `menuw' library (-lmenuw). */
/* #undef HAVE_LIBMENUW */

/* Define to 1 if you have the `ncurses' library (-lncurses). */
#define HAVE_LIBNCURSES 1

/* Define to 1 if you have the `panel' library (-lpanel). */
#define HAVE_LIBPANEL 1

/* Define to 1 if you have the `panelw' library (-lpanelw). */
/* #undef HAVE_LIBPANELW */

/* Define to 1 if you have the `pcap' library (-lpcap). */
#define HAVE_LIBPCAP 1

/* Define to 1 if you have the `pcre' library (-lpcre). */
/* #undef HAVE_LIBPCRE */

/* Define to 1 if you have the `pthread' library (-lpthread). */
#define HAVE_LIBPTHREAD 1

/* Define to 1 if you have the `z' library (-lz). */
/* #undef HAVE_LIBZ */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <netinet/in.h> header file. */
/* #undef HAVE_NETINET_IN_H */

/* Define to 1 if you have the <netinet/ip6.h> header file. */
/* #undef HAVE_NETINET_IP6_H */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Name of package */
#define PACKAGE "sngrep"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "kaian@irontec.com"

/* Define to the full name of this package. */
#define PACKAGE_NAME "sngrep"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "sngrep 1.8.2"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "sngrep"

/* Define to the home page for this package. */
#define PACKAGE_URL "http://www.irontec.com/"

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.8.2"

/* Required for including pcre2.h */
/* #undef PCRE2_CODE_UNIT_WIDTH */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Compile With EEP support */
/* #undef USE_EEP */

/* Compile With IPv6 support */
/* #undef USE_IPV6 */

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif


/* Version number of package */
#define VERSION "1.8.2"

/* Compile With GnuTLS compatibility */
/* #undef WITH_GNUTLS */

/* Compile With Openssl compatibility */
/* #undef WITH_OPENSSL */

/* Compile With Perl Compatible regular expressions support */
/* #undef WITH_PCRE */

/* Compile With Perl Compatible regular expressions support */
/* #undef WITH_PCRE2 */

/* The library is present. */
/* #undef WITH_UNICODE */

/* Compile With zlib support */
/* #undef WITH_ZLIB */

/* Define to 1 if on MINIX. */
/* #undef _MINIX */

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
   /* #undef _POSIX_1_SOURCE */

   /* Define to 1 if you need to in order for `stat' and other things to work. */
   /* #undef _POSIX_SOURCE */
