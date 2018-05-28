all: prog

item.o: item.c
	gcc -c item.c

main.o: main.c
	gcc -c main.c 

prog: item.o main.o
	gcc -o prog item.o main.o -lm
