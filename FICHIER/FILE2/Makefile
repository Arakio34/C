CC=gcc
CFLAGS= -Wall -g
LDFLAGS=
all: main

main: main.o
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c $< $(CFLAGS)
