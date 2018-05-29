all: prog

item.o: item.c
	gcc -c item.c

ST.o: ST.c
	gcc -c ST.c

main.o: main.c
	gcc -c main.c 

prog: item.o ST.o main.o 
	gcc -o prog item.o ST.o main.o -lm
