
all: Location2D.o RandomMazeGenerator.o
	gcc -Wall Location2D.o RandomMazeGenerator.o -o RandomMazeGenerator



RandomMazeGenerator.o:
	gcc -Wall -c RandomMazeGenerator.c -o RandomMazeGenerator.o

Location2D.o: Location2D.c
	gcc -Wall -c Location2D.c -o Location2D.o



.PHONY: clean
clean:
	rm *.o RandomMazeGenerator
