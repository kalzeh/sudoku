CC = g++
CFLAGS = -Wall -Wextra -std=c++11

UI_FILES =  cmd_ui.o

all: sudoku

sudoku: sudoku_functions.o sudoku.cpp $(UI_FILES)
	$(CC) $(CFLAGS) sudoku_functions.o sudoku.cpp $(UI_FILES) -o sudoku
	./sudoku

cmd_ui.o: cmd_ui.cpp cmd_ui.h
	$(CC) $(CFLAGS) -c cmd_ui.cpp -o cmd_ui.o

sudoku_functions.o: sudoku_functions.cpp sudoku_functions.h
	$(CC) $(CFLAGS) -c sudoku_functions.cpp -o sudoku_functions.o

clean:
	rm -f *.o sudoku
