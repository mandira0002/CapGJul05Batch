CC = g++

CCFLAGS = -c -g -Wall
LDFLAGS = -o
IFLAGS = -I

OBJ = obj
SRC = src
BIN = bin
INC = inc


all: Server	Client

Server: $(OBJ)/UDP_Server.o
	$(CC) $(LDFLAGS) $(BIN)/Server $(OBJ)/UDP_Server.o

$(OBJ)/UDP_Server.o: $(SRC)/UDP_Server.cpp
	$(CC) $(CCFLAGS) $(SRC)/UDP_Server.cpp $(IFLAGS) $(INC)
	mv *.o $(OBJ)/

Client: $(OBJ)/UDP_Client.o
	$(CC) $(LDFLAGS) $(BIN)/Client $(OBJ)/UDP_Client.o

$(OBJ)/UDP_Client.o: $(SRC)/UDP_Client.cpp
	$(CC) $(CCFLAGS) $(SRC)/UDP_Client.cpp $(IFLAGS) $(INC)
	mv *.o $(OBJ)/

clean:
	rm a.out *.o
	rm $(OBJ)/*.o
	rm $(BIN)/Server $(BIN)/Client
	@echo "Cleaning Done"

