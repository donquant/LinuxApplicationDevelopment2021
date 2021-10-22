CFLAGS = -Wall -Wextra -O0 -g

all: range
 
range: range.c
	cc $(CFLAGS) range.c -o range 

test: range gdb_script_1 gdb_script_2 reference_1.txt reference_2.txt
	gdb --batch-silent --command=gdb_script_1 -q ./range
	cat gdb.txt | grep start | cmp reference_1.txt
	rm gdb.txt	
	gdb --batch-silent --command=gdb_script_2 -q ./range
	cat gdb.txt | grep start | cmp reference_2.txt
	rm gdb.txt	

clean:
	rm -r range range.dSYM	
