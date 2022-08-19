CC=g++
CPPFLAGS=-c -g -Wall
OBJ=obj/
SRC=src/
BIN=bin/
INCLUDE=inc/

#all:$(BIN)file

file:$(OBJ)main.o $(OBJ)file.o
	$(CC) -o file $(OBJ)main.o $(OBJ)file.o 
	mv file $(BIN)
$(OBJ)main.o:$(SRC)main.cpp
	$(CC) $(CPPFLAGS) $(SRC)main.cpp -I $(INCLUDE)
	mv main.o $(OBJ)
$(OBJ)file.o:$(SRC)file.cpp
	$(CC) $(CPPFLAGS) $(SRC)file.cpp -I $(INCLUDE)
	mv file.o $(OBJ)
valgrind:$(BIN)*.out
	valgrind --tool=memcheck $(BIN)file 1> $(BIN)valgrind.txt

clean:
	rm -f $(OBJ)*.o
	rm -f $(BIN)file
	rm -f $(BIN)valgrind.txt
	@echo "Cleaned Successfully"
