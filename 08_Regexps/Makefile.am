CFLAGS = -Wall -Wextra
bin_PROGRAMS=esub
esub_SOURCES=esub.c
clean:
	rm -rf autom4te.cache config.h.in install-sh Makefile.in aclocal.m4 compile configure depcomp missing
	rm -rf config.log Makefile configure~ config.h config.h.in~ config.status stamp-h1 esub esub.o .deps
test: esub
	echo "ffffaaa7aaaaaa" | sed -E 's/a([1-9])/\\\01g\\/' > reference.txt 
	./esub 'a([1-9])' '\\\01g\\' 'ffffaaa7aaaaaa' > test.txt 
	echo "ffffaaa7aaaaaa" | sed -E 's/a([1-9])/\1g\\/' >> reference.txt 
	./esub 'a([1-9])' '\1g\\' 'ffffaaa7aaaaaa' >> test.txt 
	echo "ffffaaa7aaaaaa" | sed -E 's/(a([1-9]))/\\\2\1g\\/' >> reference.txt 
	./esub '(a([1-9]))' '\\\2\1g\\' 'ffffaaa7aaaaaa' >> test.txt 
	cat reference.txt test.txt
	cmp reference.txt test.txt
	rm -f reference.txt test.txt
