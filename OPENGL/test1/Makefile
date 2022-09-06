CC = gcc
CFLAGS = -g 
EXEC = main

all: $(EXEC)

main: main.o
	$(CC) -o $@ $^ 


%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) 	

clean:
	rm *.o
	rm main
