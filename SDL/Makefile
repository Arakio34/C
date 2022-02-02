CC=gcc
CFLAGS=-Wall -g -o
EXEC=main
BUILDDIR= build
all: main

creatBuild:
	mkdir -p $(BUILDDIR)

main: creatBuild
	$(CC) $@.c $(CFLAGS) $(BUILDDIR)/$(EXEC) 
