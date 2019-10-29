#include <stdio.h>

#include "mec.h"
#include "mecStack.h"

void *pop(MECSTACK *head) {
	void *value = NULL;

	if (head == NULL || isEmpty(head)) {
		return NULL;
	}
	head->top--;
	value = head->data[head->top]; 
	head->data[head->top] == NULL;
	
	return value;
}

boolean push(MECSTACK *head, void *data) {
	if (head == NULL || isFull(head)) {
		return FALSE;
	}

	head->data[head->top] = data;
	++head->top;

	return TRUE;
}

boolean isFull(MECSTACK *head) {
	if (head == NULL ) {
		return FALSE;
	}

	return head->top >= head->capacity;
}

boolean isEmpty(MECSTACK *head) {
	if (head == NULL ) {
		return FALSE;
	}

	return head->top == 0;
}

boolean readMecStackTop(MECSTACK *head,int *value) {
	if (head == NULL || value == NULL || isEmpty(head)) {
		return FALSE;
	}

	*value = head->data[head->top - 1];

	return TRUE;
}

void destroyMecStack(MECSTACK **head) {
	if (head == NULL || *head == NULL) {
		return ;
	}	

	free((*head)->data);
	free(*head);
	*head = NULL; 

	return ;
}

boolean initMecStack(MECSTACK **head ,int capacity) {
	MECSTACK *mecStack = NULL;	

	if ( NULL = head || NULL != *head || capacity < 0) {
		return FALSE;
	}

	mecStack = (MECSTACK *) calloc (sizeof(MECSTACK),1);
	mecStack->data = (void **) calloc (sizeof(void *),capacity);
	mecStack->capacity = capacity;
	mecStack->top = 0;

	*head = mecStack;

	return TRUE;
}
