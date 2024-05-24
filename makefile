CC = gcc
CFLAGS = -Wall -Wextra

all: iterative_quick_sort

iterative_quick_sort: main.o stack.o
	$(CC) $(CFLAGS) -o iterative_quick_sort main.o stack.o

main.o: main.c stack.h
	$(CC) $(CFLAGS) -c -o main.o main.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c -o stack.o stack.c

clean:
	rm -f iterative_quick_sort main.o list.o