CC=g++
CPPFLAGS=-c -g -Wall
OBJ=obj/
SRC=src/
BIN=bin/
INCLUDE=inc/

#all:$(BIN)multi.out

multi.out:$(OBJ)main.o $(OBJ)mp.o
	$(CC) -o multi.out $(OBJ)main.o $(OBJ)mp.o 
	mv multi.out $(BIN)
$(OBJ)main.o:$(SRC)main.cpp
	$(CC) $(CPPFLAGS) $(SRC)main.cpp -I $(INCLUDE)
	mv main.o $(OBJ)
$(OBJ)mp.o:$(SRC)mp.cpp
	$(CC) $(CPPFLAGS) $(SRC)mp.cpp -I $(INCLUDE)
	mv mp.o $(OBJ)
valgrind:$(BIN) multi.out
	valgrind --leak-check=full --show-reachable=yes $(BIN)multi.out 1>$(BIN)/valgrind.txt

clean:
	rm -f $(OBJ)*.o
	rm -f $(BIN)multi.out
	rm -f $(BIN)/valgrind.txt

