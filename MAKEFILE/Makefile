CC=gcc
CFLAGS=-Wall
EXEC=exec
BUILDDIR= build
all: main

createEnv:
	mkdir -p $(BUILDDIR)
clean: 
	rm -rf $(BUILDDIR) $(EXEC)
	
main: createEnv helloworld.o lib.o
	$(CC) $(CFLAGS) -o $(EXEC) $(BUILDDIR)/*.o $(CFLAGS)

helloworld.o: helloworld.c
	$(CC) -o $(BUILDDIR)/$@ -c $< $(CFLAGS)
lib.o: lib.c lib.h
	$(CC) -o $(BUILDDIR)/$@ -c $< $(CFLAGS)

