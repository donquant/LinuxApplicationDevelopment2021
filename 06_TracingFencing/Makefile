move: move.c
	cc -Wall -Wextra move.c -o move

sub.so: sub.c
	cc -shared -fPIC sub.c -o sub.so 

clean: 
	rm move sub.so

test: move sub.so
	truncate -s 1m infile 
	hexdump -C infile 
	./move infile outfile
	hexdump -C outfile 
	rm outfile 
	truncate -s 1m PROTECTed_infile 
	LD_PRELOAD=$(shell pwd)/sub.so ./move PROTECTed_infile outfile
	hexdump -C PROTECTed_infile 
	hexdump -C outfile 
	cmp PROTECTed_infile outfile 
	rm PROTECTed_infile outfile 

