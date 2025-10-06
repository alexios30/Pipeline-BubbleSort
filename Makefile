CC = gcc
CFLAGS = -Wall -Wextra

all: bubblesort

bubblesort: bubblesort.o
	$(CC) $(CFLAGS) -o bubblesort bubblesort.o

bubblesort.o: bubblesort.c
	$(CC) $(CFLAGS) -c bubblesort.c

clean:
	rm -f *.o bubblesort
