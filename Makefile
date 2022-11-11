CC = gcc
FLAGS = -Wall -std=c99 -g
BIN = ./conjunto

all: conjunto

conjunto: main.o item.o avl.o set.o
	$(CC) $(FLAGS) *.o -o $(BIN)

item.o: item.c item.h
	$(CC) $(FLAGS) -c item.c

avl.o: avl.c avl.h set.h item.h
	$(CC) $(FLAGS) -c avl.c

set.o: set.c set.h item.h
	$(CC) $(FLAGS) -c set.c

main.o: main.c avl.h
	$(CC) $(FLAGS) -c main.c

run:
	$(BIN)

clean:
	rm $(BIN) *.o