pgm1: query.o parser.o sorter.o printer.o
	gcc -o pgm1 query.o parser.o sorter.o printer.o

query.o: query.c structure.h
	gcc -c -g -Wall query.c

parser.o: parser.c structure.h
	gcc -c -g -Wall parser.c

sorter.o: sorter.c structure.h
	gcc -c -g -Wall sorter.c

printer.o: printer.c structure.h
	gcc -c -g -Wall printer.c

clean:
	rm *.o output.txt pgm1