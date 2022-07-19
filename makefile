CC=g++

all: add-nbo

add-nbo: main.o
	$(CC) -o add-nbo main.o

main.o: main.cpp
	$(CC) -c -o main.o main.cpp

clean:
	rm add-nbo *.o