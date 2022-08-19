CC = g++

CCFLAGS = -c -g -Wall
LDFLAGS = -o
IFLAGS = -I

INC = inc
BIN = bin
OBJ = obj
SRC = src

all: p1 

p1: $(OBJ)/p1.o
	$(CC) $(LDFLAGS) $(BIN)/p1 $(OBJ)/p1.o

$(OBJ)/p1.o: $(SRC)/p1.cpp
	$(CC) $(CCFLAGS) $(IFLAGS)$(INC)/ $(SRC)/p1.cpp
	mv *.o $(OBJ)/

clean:
	rm -f a.out *.o
	rm $(OBJ)/*.o
	rm $(BIN)/p1 $(BIN)/p2 $(BIN)/p3
	@echo "Cleaning Done!"
