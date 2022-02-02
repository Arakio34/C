CC=gcc
CFLAGS=-Wall -g -o
EXEC=tower
BUILDDIR= build
all: main

creatBuild:
	mkdir -p $(BUILDDIR)

main: creatBuild
	$(CC) $@.c $(CFLAGS) $(BUILDDIR)/$(EXEC) 
