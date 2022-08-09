CC=gcc

app:test.o config.o
	$(CC) -o app test.o config.o

config.o: config.cpp
	$(CC) -c config.cpp

clean:
	rm -f config.o app a.out

