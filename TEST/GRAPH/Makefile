CC = gcc
CFLAGS = -Wall -g 
EXEC = main

all: $(EXEC)

main: graph.o main.o
	$(CC) -o $@ $^ 

main.o: graph.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) 	

clean:
	rm *.o
	rm main
