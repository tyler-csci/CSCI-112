
pgm1: main.o course.o linked_list.o
	gcc -o pgm1 main.o course.o linked_list.o

main.o: main.c main.h
	gcc -c -g -Wall main.c

course.o: course.c course.h
	gcc -c -g -Wall course.c 

linked_list.o: linked_list.c linked_list.h
	gcc -c -g -Wall linked_list.c