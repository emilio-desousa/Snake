all: proper Snake

build: proper Snake
	rm -rf *.o

bl: build launch

Snake: Snake.o functions.o window.o
	gcc -o Snake Snake.o functions.o window.o -lgraph -lm

functions.o: functions.c functions.h
	gcc -c functions.c -lgraph -lm

window.o: window.c window.h
	gcc -c window.c -lgraph -lm

Snake.o: Snake.c functions.h window.h
	gcc -c Snake.c -lgraph

clean: 
	rm -rf *.o

proper: clean
	rm -rf Snake

launch: 
	./Snake

.PHONY: clean