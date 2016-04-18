#include "queue.h"
#include "PCB.h"
#include <stdlib.h>

#define IDL_PID 0xFFFFFFFF

unsigned long sysStack;

Queue_q createdQueue;
Queue_q readyQueue;
PCB_p currentPCB;

PCB_p idl;

void dispatcher() {
	currentPCB = dequeue(readyQueue);
	PCB_set_state(currentPCB, running);
	sysStack = PCB_get_pc(currentPCB);
}

void scheduler(int interruptType) {
	while (!isEmpty(createdQueue)) {
		PCB_p p = dequeue(createdQueue);
		PCB_set_state(p, ready);
		enqueue(readyQueue, p);
	}
	if (interruptType == 1) {
		PCB_set_state(currentPCB, ready);
		enqueue(readyQueue, currentPCB);
	} 
	dispatcher();
}


void isrTimer() {
	PCB_set_state(currentPCB, interrupted);
	PCB_set_pc(currentPCB, sysStack);
	scheduler(1);
}


int main() {
	idl = PCB_construct();
	PCB_init(idl);
	PCB_set_pid(idl, IDL_PID);

	createdQueue = queue_construct();
	queue_init(createdQueue);
	readyQueue = queue_construct();
	queue_init(readyQueue);
	
	for (int i = 0; i < 10; i++) {

		int newProcesses = rand() % 6;
		for (int j = 0; j < newProcesses; j++) {
			PCB_p p = PCB_construct();
			PCB_init(p);
			PCB_set_pid(p, rand());
			enqueue(createdQueue, p);
		}

		sysStack = PCB_get_pc(currentPCB) + rand() % 1001 + 3000;
		isrTimer();


	}
	return 0;
}