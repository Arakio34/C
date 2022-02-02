CC = gcc
CFLAGS = -Wall -g 
EXEC = main

all: $(EXEC)

main: ttutils.o main.o
	$(CC) -o $@ $^ 

main.o: ttutils.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) 	

clean:
	rm *.o
	rm main
