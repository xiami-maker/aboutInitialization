/**
 * 普通的队列
 */
#ifndef _ABOUT_QUEUE_H_
#define _ABOUT_QUEUE_H_

#include "mec.h"

tyoedef struct NODE{
	UESR_TYPE data;
	struct NODE *next; 
}NODE;

typedef struct ABOUT_QUEUE{
	NODE head;
	NODE *tail;
}ABOUT_QUEUE;

#endif
