CC = gcc
CFLAGS = -Wall -g 
EXEC = main

all: $(EXEC)

main: sudoku.o main.o
	$(CC) -o $@ $^ 

main.o: sudoku.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) 	

clean:
	rm *.o
	rm main
