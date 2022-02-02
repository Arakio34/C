CC = gcc
CFLAGS = -Wall -g 
EXEC = main

all: $(EXEC)

main: factoriel.o main.o
	$(CC) -o $@ $^ 

main.o: factoriel.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) 	


