
#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([esub], [0.0], [dasurfspot@gmail.com])
AC_CONFIG_SRCDIR([esub.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AM_INIT_AUTOMAKE([foreign subdir-objects])

# Checks for header files.
AC_CHECK_HEADER([regex.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([regcomp])
AC_CHECK_FUNCS([regexec])
AC_CHECK_FUNCS([regerror])
AC_CHECK_FUNCS([regfree])


# Epilog.
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
