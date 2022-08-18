CC = g++

CCFLAGS = -c -g -Wall
LDFLAGS = -o
IFLAGS = -I

INC = inc
BIN = bin
OBJ = obj
SRC = src

all: myexecutable mycmd

myexecutable: $(OBJ)/myexecutable.o
	$(CC) $(LDFLAGS) $(BIN)/myexecutable $(OBJ)/myexecutable.o

$(OBJ)/myexecutable.o: $(SRC)/myexecutable.cpp
	$(CC) $(CCFLAGS) $(IFLAGS)$(INC)/ $(SRC)/myexecutable.cpp
	mv *.o $(OBJ)/

mycmd: $(OBJ)/mycmd.o
	$(CC) $(LDFLAGS) $(BIN)/mycmd $(OBJ)/mycmd.o

$(OBJ)/mycmd.o: $(SRC)/mycmd.cpp
	$(CC) $(CCFLAGS) $(IFLAGS)$(INC)/ $(SRC)/mycmd.cpp
	mv *.o $(OBJ)/
clean:
	rm -f a.out *.o
	rm $(OBJ)/*.o
	rm $(BIN)/myexecutable $(BIN)/mycmd 
	@echo "Cleaning Done!"
