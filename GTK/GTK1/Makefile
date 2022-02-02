CC = gcc
CFLAGS = -I . 
PACKAGE = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`
EXE = main

main: main.o
	clear
	$(CC) -o $(EXE) $^ $(LIBS)  

main.o: main.c	
	$(CC) $(PACKAGE) -c $^


