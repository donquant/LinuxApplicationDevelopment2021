CFLAGS = -std=c99 -pedantic -Wall -Wextra

if COND_GCOV
    CFLAGS  += -O0 -g -fprofile-arcs -ftest-coverage
else
    CFLAGS  += -O3 -g3
endif

lib_LTLIBRARIES = libbuf.la
libbuf_la_SOURCES = libbuf.c

buf_LDADD = libbuf.la

libbuf.c: buf.h

gcov:
	gcov .libs/libbuf -a -f
