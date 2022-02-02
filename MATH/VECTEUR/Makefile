CC = gcc
CFLAGS = -Wall -g 
EXEC = main

all: $(EXEC)

main: vecteur.o main.o
	$(CC) -o $@ $^ -lm 

main.o: vecteur.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) 	


