numbers: numbers.o utils.o numbers.h
	gcc -g -ansi -Wall -pedantic numbers.o utils.o -o numbers -lm

utils.o: utils.c numbers.h
	gcc -c -g -ansi -Wall -pedantic utils.c -o utils.o
