CC = g++
CCFLAGS = -c -g -Wall
LDFLAGS = -o 
IFLAGS = -I $(INC)
INC = inc/
BIN = bin/
OBJ = obj/
SRC = src/

#all: $(BIN)/p1 
	
p1: $(OBJ)/f1.o
		$(CC) $(LDFLAGS) p1 $(OBJ)/f1.o
			mv p1 $(BIN)/

$(OBJ)/f1.o: $(SRC)/f1.cpp
		$(CC) $(CCFLAGS) $(IFLAGS)/ $(SRC)/f1.cpp
			mv *.o $(OBJ)/

clean:
		rm $(OBJ)/*.o
		rm $(BIN)/p1 
