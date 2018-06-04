all: prog

item.o: item.c
	gcc -g -c item.c

main.o: main.c
	gcc -g -c main.c 

prog: item.o main.o 
	gcc -g -o prog item.o main.o -lm

clean:
	rm -f item.o main.o prog
