CC=gcc
CFLAGS=-I .
HEAD = pile.h

%.o: %.c $(HEAD)
	clear
	$(CC) -c -o $@ $< $(CFLAGS)
main: main.o pile.o
	$(CC) -o $@ $^ $(CFLAGS)
