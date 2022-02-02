CC = gcc
CFLAGS = -Wall -g 
EXEC = main

all: $(EXEC)

main: matrice.o main.o
	$(CC) -o $@ $^ -lm 

main.o: matrice.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) 	


