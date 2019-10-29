#ifndef _MEC_STACK_H_
#define _MEC_STACK_H_

#include "mec.h"

typedef struct MECSTACK {
	void **stack;
	int capacity;
	int top;
}MECSTACK;

boolean initMecStack(MECSTACK **head ,int capacity);
void destroyMecStack(MECSTACK **head);
boolean readMecStackTop(MECSTACK *head,int *value);
boolean isFull(MECSTACK *head);
boolean isEmpty(MECSTACK *head);
boolean push(MECSTACK *head, void *data);
void *pop(MECSTACK *head);

#endif
