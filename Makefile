comp: 
	gcc -Wall -c main.c lib.c

main:
	gcc -Wall main.o lib.o -lm

clean:
	rm -f *.o *~ *.in a.out
