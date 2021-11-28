SUBDIRS = src tests 

gcov: check
	$(MAKE) $(MAKEFLAGS) -C src gcov

gitclean:
	git clean -df

clean:
	rm -rf aclocal.m4 compile config.h.in config.sub depcomp ltmain.sh Makefile.in	
	rm -rf autom4te.cache config.guess config.h.in~ configure configure~ install-sh missing
	rm -rf libtool config.h config.log stamp-h1 config.status Makefile src/Makefile src/Makefile.in 
	rm -rf src/libbuf.la src/libbuf.lo test-driver tests/Makefile tests/Makefile.in src/.deps src/.libs tests/.deps
	rm -rf tests/.deps tests/.libs  tests/test-suite.log tests/lib_test
	rm -rf tests/lib_test.c tests/lib_test.log tests/lib_test.o tests/lib_test.trs
