CC = gcc
CFLAGS = -g 
EXEC = main

all: $(EXEC)

main: ell17lib.o main.o
	$(CC) -o $@ $^ 

main.o: ell17lib.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) 	

clean:
	rm *.o
	rm main
