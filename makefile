CFLAGS=-Wall -std=c99




all: Round_Robin


Round_Robin: Round_Robin.o PCB.o queue.o
	gcc Round_Robin.o PCB.o queue.o -o Round_Robin





Round_Robin.o: Round_Robin.c
	gcc $(CFLAGS) -c Round_Robin.c
queue.o: queue.c
	gcc $(CFLAGS) -c queue.c 
PCB.o: PCB.c
	gcc $(CFLAGS) -c PCB.c