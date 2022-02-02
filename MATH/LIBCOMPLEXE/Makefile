CC = gcc
CFLAGS =-lm -I . 
HEAD = complexeTT.h

%.o : %.c $(HEAD)
	clear
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o complexeTT.o
	$(CC) -o $@ $^ $(CFLAGS)
