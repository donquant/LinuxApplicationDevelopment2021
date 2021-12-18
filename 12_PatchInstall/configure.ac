#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([guess], [1.0], [dasurfspot@gmail.com])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN([guess.c])
AC_CONFIG_SRCDIR([guess.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PATH_PROG([HELP2MAN], [help2man])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h argp.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale strcasecmp])

AC_CONFIG_FILES([Makefile Doxyfile])
AC_OUTPUT
