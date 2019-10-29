#ifndef _MECLINEAR_H_
#define _MECLINEAR_H_

#include "mec.h"

typedef struct MECLINEAR {
	void **data;
	int capacity;
	int count;
}MECLINEAR;

boolean initMecLinear(MECLINEAR **mecLinear,int capacity);
boolean destoryMecLinear(MECLINEAR **mecLinear);
int getMecLinearCount(MECLINEAR *mecLinear);
int getMecLinearCapacity(MECLINEAR *mecLinear);
void *getMecLinearValueAt(MECLINEAR *mecLinear,int index);


#endif
