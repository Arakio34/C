CC="gcc"
CFLAGS="-Wall"


main:
	$(CC) -c $(CFLAGS) serveur.c -o LINK/serveur.o
	$(CC) -c $(CFLAGS) client.c -o LINK/client.o
	$(CC) -o EXEC/SERV LINK/serveur.o 
	$(CC) -o EXEC/CLI LINK/client.o

