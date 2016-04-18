CFLAGS=-Wall -std=c99











queue.o: queue.c
	gcc $(CFLAGS) -c queue.c 
PCB.o: PCB.c
	gcc $(CFLAGS) -c PCB.c
