CC = gcc
CFLAGS = -Wall -Wextra

all: quick_sort_iterativo

quick_sort_iterativo: main.o pilha.o
	$(CC) $(CFLAGS) -o quick_sort_iterativo main.o pilha.o

main.o: main.c pilha.h
	$(CC) $(CFLAGS) -c -o main.o main.c

pilha.o: pilha.c pilha.h
	$(CC) $(CFLAGS) -c -o pilha.o pilha.c

clean:
	rm -f quick_sort_iterativo main.o pilha.o
