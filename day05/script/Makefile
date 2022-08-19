CC = g++

CCFLAGS = -c -g -Wall
LDFLAGS = -o
IFLAGS = -I

OBJ = obj
SRC = src
BIN = bin
INC = inc


all: Server	Client

Server: $(OBJ)/Server.o
	$(CC) $(LDFLAGS) $(BIN)/Server $(OBJ)/Server.o

$(OBJ)/Server.o: $(SRC)/Server.cpp
	$(CC) $(CCFLAGS) $(SRC)/Server.cpp $(IFLAGS) $(INC)
	mv *.o $(OBJ)/

Client: $(OBJ)/Client.o
	$(CC) $(LDFLAGS) $(BIN)/Client $(OBJ)/Client.o

$(OBJ)/Client.o: $(SRC)/Client.cpp
	$(CC) $(CCFLAGS) $(SRC)/Client.cpp $(IFLAGS) $(INC)
	mv *.o $(OBJ)/

clean:
	rm a.out *.o
	rm $(OBJ)/*.o
	rm $(BIN)/Server $(BIN)/Client
	@echo "Cleaning Done"
	
