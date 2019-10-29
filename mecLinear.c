#include <stdio.h>
#include <malloc.h>

#include "mecLinear.h"
#include "mec.h"

void *getMecLinearValueAt(MECLINEAR *mecLinear,int index) {
	if (mecLinear == NULL || index <= -1 || index >= mecLinear->capacity) {
		return NULL;
	}

	return mecLinear->data[index];
}

int getMecLinearCapacity(MECLINEAR *mecLinear) {
	if (mecLinear == NULL) {
		return -1;
	}

	return mecLinear->capacity;
}

int getMecLinearCount(MECLINEAR *mecLinear) {
	if (mecLinear == NULL) {
		return -1;
	}

	return mecLinear->count;
}

boolean initMecLinear(MECLINEAR **mecLinear,int capacity) {
	MECLINEAR *head = NULL;

	if (mecLinear == NULL || *mecLinear != NULL  || capacity <= 0) {
		return FALSE; 
	}

	head = (MECLINEAR *) calloc (sizeof(MECLINEAR),1);
	head->data = (void **) calloc (sizeof(void *),capacity);
	head->capacity = capacity;
	heda->count = count;

	*mecLinear = head;

	return TRUE;
}

boolean destoryMecLinear(MECLINEAR **mecLinear) {
	if (mecLinear == NULL) {
		return FALSE;
	}

	free((*mecLinear)->data);
	free(*mecLinear);
	*mecLinear = NULL;					//这里容易忘记！！！

	return TRUE;
}
