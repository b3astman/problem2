#pragma once

enum state_type {new, ready, running, interrupted, waiting, halted};

typedef struct pcb {
    unsigned long pid;        // process ID #, a unique number
	enum state_type state;    // process state (running, waiting, etc.)
	unsigned short priority;  // priorities 0=highest, 15=lowest
	unsigned long pc;         // holds the current pc value when preempted
} PCB;

typedef PCB * PCB_p;

PCB_p PCB_construct(void); // returns a pcb pointer to heap allocation

void PCB_destruct(PCB_p);  // deallocates pcb from the heap

void PCB_init(PCB_p);       // sets default values for member data

void PCB_set_pc (PCB_p p, unsigned long num);

unsigned long PCB_get_pc (PCB_p p);

int PCB_set_state (PCB_p p, enum state_type s);

const char* PCB_get_state(PCB_p p);

int PCB_set_pid(PCB_p, unsigned long pid);

unsigned long PCB_get_pid (PCB_p p);

void PCB_set_priority (PCB_p p, unsigned short num);

unsigned short PCB_get_priority (PCB_p p);

unsigned long PCB_get_pid (PCB_p);  // returns pid of the process

const char * getStateName(PCB_p);

void PCB_toString(PCB_p);  // returns a string representing the contents of the pcb