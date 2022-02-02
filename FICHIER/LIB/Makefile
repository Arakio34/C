CC = gcc 
CFLAGS = -I .
HEAD = fichier.h

%.o : %.c $(HEAD)
	clear
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o fichier.o
	$(CC) -o  $@ $^ $(CFLAGS)
