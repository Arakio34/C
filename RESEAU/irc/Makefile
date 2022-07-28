CC=gcc
CFLAGS=-Wall -g
EXEC=main
all: $(EXEC)

main: ttirc.o main.o
	$(CC) -o $@ $^ -lm 

main.o: ttirc.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) 	


