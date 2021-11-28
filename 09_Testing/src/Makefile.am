AM_CFLAGS = -ansi -pedantic -std=c99 -Wall -Wextra

if COND_GCOV
    CFLAGS  += -O0 -g -fprofile-arcs -ftest-coverage
endif

lib_LTLIBRARIES = libbuf.la
libbuf_la_SOURCES = libbuf.c

#bin_PROGRAMS=buf
#buf_SOURCES = buf.c
buf_LDADD = libbuf.la

libbuf.c: buf.h

gcov:
	gcov .libs/libbuf -j
