CC = gcc

exe : foo.o bar.o main.o
	gcc -o exe foo.o bar.o main.o

main.o : main.c
	gcc -c main.c
foo.o : foo.c
	gcc -c foo.c
bar.o : bar.c
	gcc -c bar.c

clean :
	rm *.o exe
