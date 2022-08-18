CC=g++
CPPFLAGS=-c -g -Wall 
OBJ=obj/
SRC=src/
BIN=bin/
INCLUDE=inc/

assign.out:$(OBJ)assign2.o 
	        $(CC) -o assign.out $(OBJ)assign2.o 
		mv assign.out $(BIN)
$(OBJ)assign2.o:$(SRC)assign2.cpp
	        $(CC) $(CPPFLAGS) $(SRC)assign2.cpp -I $(INCLUDE)
		mv assign2.o $(OBJ)
valgrind:$(BIN) assign.out
	        valgrind --leak-check=full --show-reachable=yes $(BIN)assign.out 1>$(BIN)/valgrind.txt

clean:
	        rm -f $(OBJ)*.o
		rm -f $(BIN)vec.out
	        rm -f $(BIN)/valgrind.txt
