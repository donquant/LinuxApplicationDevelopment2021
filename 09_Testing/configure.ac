#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Growable Memory Buffers], [1.0], [dasurfspot@gmail.com])
AM_INIT_AUTOMAKE([foreign])
LT_INIT([disable-static])
AC_CONFIG_SRCDIR([src/libbuf.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Joint pkgconfig library/include tests
PKG_CHECK_MODULES([CHECK],[check])

# Enabe/disable things
AC_ARG_ENABLE([gcov],
              [AS_HELP_STRING([--enable-gcov],
              [use Gcov to test the test suite])],
              [], 
              [enable_gcov=no])

AM_CONDITIONAL([COND_GCOV],[test '!' "$enable_gcov" = no])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

AC_CONFIG_FILES([Makefile
                src/Makefile
                tests/Makefile])
AC_OUTPUT
