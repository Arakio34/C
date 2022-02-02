CC=gcc
CFLAGS=-Wall -g
LDFLAGS=
BUILDDIR= build
all: main


main: main.o
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c $< $(CFLAGS) 
