CC = gcc
CFLAGS = -Wall -g 
EXEC = main

all: $(EXEC)

main: schema.o main.o
	$(CC) -o $@ $^ 

main.o: schema.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) 	

clean:
	rm *.o
	rm main
