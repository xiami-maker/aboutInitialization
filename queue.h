#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "mec.h"
//循环队列
typedef struct QUEUE {
	USER_TYPE *queue;
	int capacity;
	int head;
	int tail;
	boolean lastAction;
}QUEUE;

#define IN  1
#define OUT 2

boolean initQueue(QUEUE **queue,int capacity);
void destoryQueue(QUEUE **queue);
boolean isQueueEmpty(QUEUE *queue);
boolean isQueueFull(QUEUE *queue);
boolean in(QUEUE *queue,USER_TYPE *data);
USER_TYPE *out(QUEUE *queue);

#endif
