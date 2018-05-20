# RandomMazeGenerator Makefile
# Author: Daniel Tranfaglia

all: Location2D.o RandomMazeGenerator.o Stack.o
	gcc -Wall Stack.o Location2D.o RandomMazeGenerator.o -o RandomMazeGenerator



RandomMazeGenerator.o: RandomMazeGenerator.c
	gcc -Wall -c RandomMazeGenerator.c -o RandomMazeGenerator.o

Location2D.o: Location2D.c
	gcc -Wall -c Location2D.c -o Location2D.o

Stack.o: Stack.c
	gcc -Wall -c Stack.c -o Stack.o



.PHONY: clean
clean:
	rm *.o RandomMazeGenerator
