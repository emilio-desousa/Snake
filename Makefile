all: proper Snake

build: proper Snake
	rm -rf *.o

Snake: Snake.o functions.o
	gcc -o Snake Snake.o functions.o -lgraph

functions.o: functions.c functions.h
	gcc -c functions.c -lgraph

Snake.o: Snake.c functions.h
	gcc -c Snake.c -lgraph

clean: 
	rm -rf *.o

proper: clean
	rm -rf Snake

.PHONY: clean