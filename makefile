all: prog

item.o: item.c
	gcc -c item.c

st.o: st.c
	gcc -c st.c

main.o: main.c
	gcc -c main.c 

prog: item.o main.o st.o
	gcc -o prog item.o st.o main.o
