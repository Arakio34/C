CC=gcc
CFLAGS=-Wall -g
all: main

main:
	gcc -c Cmain.c
	gcc -c Smain.c	
	gcc -o Cmain Cmain.o	
	gcc -o Smain Smain.o

#Cmain: Cmain.o
	# $(CC) -o $@ $^

# Smain: Smain.o
	# $(CC) -o $@ $^

# Cmain.o: Cmain.c
	# $(CC) -c Cmain.o $(CFLAGS) 

# Smain.o: Smain.c
	# $(CC) -c Cmain.o $(CFLAGS) 
