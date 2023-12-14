CC = g++
CFLAGS = -Wall -Wextra -std=c++11

all: sudoku

sudoku: sudoku_functions.o sudoku.cpp
	$(CC) $(CFLAGS) sudoku_functions.o sudoku.cpp -o sudoku
	./sudoku

sudoku_functions.o: sudoku_functions.cpp sudoku_functions.h
	$(CC) $(CFLAGS) -c sudoku_functions.cpp -o sudoku_functions.o

clean:
	rm -f *.o sudoku