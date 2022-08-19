
CC = g++

CCFLAGS = -c -g -Wall
LDFLAGS = -o 
IFLAGS = -I

INC = inc
BIN = bin
OBJ = obj
SRC = src

all: multi

multi: $(OBJ)/multi.o
	$(CC) $(LDFLAGS) $(BIN)/multi $(OBJ)/multi.o

$(OBJ)/multi.o: $(SRC)/multi.cpp
	$(CC) $(CCFLAGS) $(IFLAGS)$(INC)/ $(SRC)/multi.cpp
	mv *.o $(OBJ)/


clean:
	rm -f a.out *.o
	rm $(OBJ)/*.o
	rm $(BIN)/multi 
