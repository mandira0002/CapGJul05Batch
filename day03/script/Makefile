CC = g++

CCFLAGS = -c -g -Wall
LDFLAGS = -o 
IFLAGS = -I

INC = inc
BIN = bin
OBJ = obj
SRC = src

all: sysPrg1 sysPrg2 sysPrg4

sysPrg1: $(OBJ)/sysPrg1.o
	$(CC) $(LDFLAGS) $(BIN)/sysPrg1 $(OBJ)/sysPrg1.o

$(OBJ)/sysPrg1.o: $(SRC)/sysPrg1.cpp
	$(CC) $(CCFLAGS) $(IFLAGS)$(INC)/ $(SRC)/sysPrg1.cpp
	mv *.o $(OBJ)/

sysPrg2: $(OBJ)/sysPrg2.o
	$(CC) $(LDFLAGS) $(BIN)/sysPrg2 $(OBJ)/sysPrg2.o

$(OBJ)/sysPrg2.o: $(SRC)/sysPrg2.cpp
	$(CC) $(CCFLAGS) $(IFLAGS)$(INC)/ $(SRC)/sysPrg2.cpp
	mv *.o $(OBJ)/

sysPrg4: $(OBJ)/sysPrg4.o
	$(CC) $(LDFLAGS) $(BIN)/sysPrg4 $(OBJ)/sysPrg4.o

$(OBJ)/sysPrg4.o: $(SRC)/sysPrg4.cpp
	$(CC) $(CCFLAGS) $(IFLAGS)$(INC)/ $(SRC)/sysPrg4.cpp
	mv *.o $(OBJ)/

p4: $(OBJ)/p4.o
	$(CC) $(LDFLAGS) $(BIN)/p4 $(OBJ)/p4.o

$(OBJ)/p4.o: $(SRC)/p4.cpp
	$(CC) $(CCFLAGS) $(IFLAGS)$(INC)/ $(SRC)/p4.cpp
	mv *.o $(OBJ)/

p5: $(OBJ)/p5.o
	$(CC) $(LDFLAGS) $(BIN)/p5 $(OBJ)/p5.o

$(OBJ)/p5.o: $(SRC)/p5.cpp
	$(CC) $(CCFLAGS) $(IFLAGS)$(INC)/ $(SRC)/p5.cpp
	mv *.o $(OBJ)/

clean:
	rm -f a.out *.o
	rm $(OBJ)/*.o
	rm $(BIN)/sysPrg1 $(BIN)/sysPrg2 $(BIN)/sysPrg4 $(BIN)/p4
	rm $(BIN)/p5
	@echo "Cleaning Done!"
