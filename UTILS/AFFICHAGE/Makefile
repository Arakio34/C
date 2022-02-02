CC = gcc
CFLAGS = -Wall -g 
EXEC = main

all: $(EXEC)

main: affichage.o main.o
	$(CC) -o $@ $^ 

main.o: affichage.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) 	

clean:
	rm *.o
	rm main
