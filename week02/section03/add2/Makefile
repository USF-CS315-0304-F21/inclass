all: add2

add2.o: add2.c
	gcc -g -c -o add2.o add2.c

add2_c.o: add2_c.c
	gcc -g -c -o add2_c.o add2_c.c

add2_s.o: add2_s.s
	as -g -o add2_s.o add2_s.s
	
add2: add2.o add2_c.o add2_s.o
	gcc -g -o add2 add2.o add2_c.o add2_s.o

clean:
	rm -rf add2 *.o
