CC = g++

CCFLAGS = -c -g -Wall
LDFLAGS = -o 
IFLAGS = -I $(INC)

INC = inc
BIN = bin
OBJ = obj
SRC = src

#all: $(BIN)/prg1
	
prg1: $(OBJ)/prg1.o
		$(CC) $(LDFLAGS) prg1 $(OBJ)/prg1.o
		mv prg1 $(BIN)/
		@echo "Compiled Successfully!"

$(OBJ)/prg1.o: $(SRC)/prg1.cpp
		$(CC) $(CCFLAGS) $(IFLAGS)/ $(SRC)/prg1.cpp
		mv *.o $(OBJ)/

clean:
		rm $(OBJ)/*.o
		rm $(BIN)/prg
		@echo "Cleaning Done!"
