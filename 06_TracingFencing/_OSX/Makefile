move: move.c
	cc -Wall -Wextra move.c -o move

sub.dylib: sub.c
	cc -shared -fPIC sub.c -o sub.dylib 

clean: 
	rm move sub.dylib 

test: move sub.dylib
	gtruncate -s 1m infile 
	hexdump -C infile 
	./move infile outfile
	hexdump -C outfile 
	rm outfile 
	gtruncate -s 1m PROTECTed_infile 
	DYLD_INSERT_LIBRARIES=$(shell pwd)/sub.dylib DYLD_FORCE_FLAT_NAMESPACE=1 ./move PROTECTed_infile outfile
	hexdump -C PROTECTed_infile 
	hexdump -C outfile 
	cmp PROTECTed_infile outfile 
	rm PROTECTed_infile outfile 

