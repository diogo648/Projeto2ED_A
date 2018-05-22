all: prog

item.o: item.c
	gcc -c item.c

matriz.o: matriz.c
	gcc -c matriz.c

main.o: main.c
	gcc -c main.c 

prog: matriz.o main.o lista.o
	gcc -o prog matriz.o lista.o main.o
