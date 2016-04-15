#include <stdio.h>
#include <stdlib.h>
#include "PCB.h"

#define DEFAULT_PID 0x1
#define DEFAULT_STATE new
#define DEFAULT_PRIORITY 15
#define DEFAULT_PC 0x0000

PCB_p PCB_construct (void) {// returns a pcb pointer to heap allocation
	PCB_p p = (PCB_p) malloc (sizeof(PCB));
	return p;
}

void PCB_destruct (PCB_p p) {  // deallocates pcb from the heap
	if (!p) {
		printf("ERROR: Null pointer passed to PCB_destruct.\n");
	}
	else free(p);
}

void PCB_init (PCB_p p) {      // sets default values for member data
	if (!p) {
		printf("ERROR: Null pointer passed to PCB_init.\n");
	}
	else {
		p->pid = DEFAULT_PID;
		p->state = DEFAULT_STATE;
		p->priority = DEFAULT_PRIORITY;
		p->pc = DEFAULT_PC;
	}
}
int PCB_set_pid (PCB_p p, unsigned long num) {
	if (!p) {
		printf("ERROR: Null pointer passed to PCB_set_pid.\n");
	} else {
		p->pid = num;
	}
	return 1;
}

unsigned long PCB_get_pid (PCB_p p) {  // returns pid of the process
	if (!p) {
		printf("ERROR: Null pointer passed to PCB_get_pid.\n");
		return -1;
	}
	else return p->pid;
}

int PCB_set_state (PCB_p p, enum state_type s) {	
	if (!p) {
		printf("ERROR: Null pointer passed to PCB_set_state.\n");
	}
	else p->state = s;
	return 1;
}

const char* PCB_get_state(PCB_p p) {	
	if (!p) {
		printf("ERROR: Null pointer passed to PCB_get_state.\n");
		return "ERROR: Null pointer passed to PCB_get_state.";
	}
	else switch (p->state) {
      case new: return "new";
      case ready: return "ready";
	  case running: return "running";
	  case interrupted: return "interrupted";
	  case waiting: return "waiting";
	  case halted: return "halted";
   }
}

void PCB_set_priority (PCB_p p, unsigned short num) {
	if (!p) {
		printf("ERROR: Null pointer passed to PCB_set_priority.\n");
	}
	else p->priority = num;
}

unsigned short PCB_get_priority (PCB_p p) {
	if (!p) {
		printf("ERROR: Null pointer passed to PCB_get_priority.\n");
		return 0;
	}
	else return p->priority;
}

void PCB_set_pc (PCB_p p, unsigned long num) {
	if (!p) {
		printf("ERROR: Null pointer passed to PCB_set_pc.\n");
	}
	else p->pc = num;
}

unsigned long PCB_get_pc (PCB_p p) {
	if (!p) {
		printf("ERROR: Null pointer passed to PCB_get_pc.\n");
		return 0;
	}
	else return p->pc;
}

int digits (unsigned long num) {
	int n = num;
	int count = 0;
	if (n > 0) {
			
		while (n > 0) {
			n/=10;
			count++;
		}
	} else count = 1;
	int i;
	for(i = 4; i - count > 0; i--) {
		printf("0");
	}
	return count;
	
}

void PCB_toString (PCB_p p) {  // returns a string representing the contents of the pcb
	printf("pid = 0x%x \nstate = %s \npriority = 0x%x \npc = 0x", PCB_get_pid(p), PCB_get_state(p), PCB_get_priority(p));
	digits(PCB_get_pc(p));
	printf("%x\n\n", PCB_get_pc(p));
}

