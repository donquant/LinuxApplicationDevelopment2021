#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([rhasher], [0.0], [dasurfspot@gmail.com])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_ARG_WITH([readline], [AS_HELP_STRING([--without-readline], [Disable readline])], [], [with_readline=yes])

# Checks for libraries.
AS_IF([test "x$with_readline" != xno], [AC_CHECK_LIB([readline], [readline])])
AC_CHECK_LIB([rhash], [rhash_library_init], [], [AC_MSG_ERROR([Unable to find librhash])])

# Checks for header files.
AC_CHECK_HEADER([rhash.h])
AC_CHECK_HEADER([readline/readline.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# Epilog.
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
