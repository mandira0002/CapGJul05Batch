CC = g++

CCFLAGS = -c -g -Wall
LDFLAGS = -o 
IFLAGS = -I

INC = inc
BIN = bin
OBJ = obj
SRC = src

all: p1 p2

p1: $(OBJ)/p1.o
	$(CC) $(LDFLAGS) $(BIN)/p1 $(OBJ)/p1.o

$(OBJ)/p1.o: $(SRC)/p1.cpp
	$(CC) $(CCFLAGS) $(IFLAGS)$(INC)/ $(SRC)/p1.cpp
	mv *.o $(OBJ)/

p2: $(OBJ)/p2.o
	$(CC) $(LDFLAGS) $(BIN)/p2 $(OBJ)/p2.o

$(OBJ)/p2.o: $(SRC)/p2.cpp
	$(CC) $(CCFLAGS) $(IFLAGS)$(INC)/ $(SRC)/p2.cpp
	mv *.o $(OBJ)/

clean:
	rm -f a.out *.o
	rm $(OBJ)/*.o
	rm $(BIN)/p1 $(BIN)/p2
	@echo "Cleaning Done!"
