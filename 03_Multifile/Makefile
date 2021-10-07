CFLAGS = -Wall -Wextra
GENERATES = README prog prog-a prog-so liboutput_static.a liboutput.so
TRASH = *.o *~ o.*

all: README prog prog-a prog-so
 
prog: const.o fun.o prog.o

prog-a: prog.o liboutput_static.a
	cc $(CFLAGS) -L. $< -loutput_static -o $@

prog-so: prog.o liboutput.so
	cc $(CFLAGS) -L. $< -loutput -o $@

liboutput_static.a: fun.o const.o
	ar -rcs $@ $^

liboutput.so: fun.o const.o
	cc -shared $^ -o $@

fun.o: outlib.h
    
README: prog
	./$< 2> $@

test: prog prog-a prog-so
	./prog &> t1.txt
	./prog-a &> tmp1.txt
	LD_LIBRARY_PATH=`pwd` ./prog-so &> tmp2.txt
	sed 's/-a//g' tmp1.txt &> t2.txt
	sed 's/-so//g' tmp2.txt &> t3.txt
	cmp t1.txt t2.txt
	cmp t1.txt t3.txt
	cmp t2.txt t3.txt
	rm *.txt
	./prog bla &> t1.txt
	./prog-a bla &> t2.txt
	LD_LIBRARY_PATH=`pwd` ./prog-so bla &> t3.txt
	cmp t1.txt t2.txt
	cmp t1.txt t3.txt
	cmp t2.txt t3.txt
	rm *.txt
	./prog bla bla bla &> t1.txt
	./prog-a bla bla bla &> t2.txt
	LD_LIBRARY_PATH=`pwd` ./prog-so bla bla bla &> t3.txt
	cmp t1.txt t2.txt
	cmp t1.txt t3.txt
	cmp t2.txt t3.txt
	rm *.txt

clean:
	rm -f $(TRASH)

distclean: clean
	rm -rf $(GENERATES)
