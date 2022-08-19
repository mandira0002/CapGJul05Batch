CC = g++

CCFLAGS = -c -g -Wall
LDFLAGS = -o 
IFLAGS = -I $(INC)

INC = inc
BIN = bin
OBJ = obj
SRC = src

all: $(BIN)/p1 
	
p1: $(OBJ)/p1.o
	$(CC) $(LDFLAGS) p1 $(OBJ)/p1.o
	mv p1 $(BIN)/
	@echo "p1 Compiled Successfully!"

$(OBJ)/p1.o: $(SRC)/p1.cpp
	$(CC) $(CCFLAGS) $(IFLAGS)/ $(SRC)/p1.cpp
	mv *.o $(OBJ)/

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/p1 
	@echo "Cleaning Done!"
