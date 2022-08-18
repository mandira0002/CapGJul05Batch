CC=g++
CPPFLAGS=-c -g -Wall -std=c++11
OBJ=obj/
SRC=src/
BIN=bin/
INCLUDE=inc/

list.out:$(OBJ)main.o $(OBJ)list.o
	$(CC) -o list.out $(OBJ)main.o $(OBJ)list.o
	mv list.out $(BIN)
$(OBJ)main.o: $(SRC)main.cpp
	$(CC) $(CPPFLAGS) $(SRC)main.cpp -I $(INCLUDE)
	mv main.o $(OBJ)
$(OBJ)list.o : $(SRC)list.cpp
	$(CC) $(CPPFLAGS) $(SRC)list.cpp -I $(INCLUDE)
	mv list.o $(OBJ)
valgrind : $(BIN)list.out
	valgrind --leak-check=full -show-reachable=yes $(BIN)list.out 1>$(BIN)/valgrind.txt

clean :
	rm -f $(OBJ)*.o
	rm -f $(BIN)list.out
	rm -f $(BIN)/valgrind.txt

