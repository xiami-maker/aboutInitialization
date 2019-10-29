/**
 * 循环队列的初始化
 */
#include <stdio.h>

#include "queue.h"

boolean in(QUEUE *queue,USER_TYPE *data) {
	if (queue == NULL || isQueueFull(queue)) {
		return FALSE;
	}

	queue->queue[queue->tail] = data;
	queue->tail = (queue->tail + 1) % queue->capacity;//这里的操作与前面的OUT类似
	queue->lastAction = IN;

	return TRUE;
}

USER_TYPE *out(QUEUE *queue) {
	USER_TYPE *data = NULL;

	if (queue == NULL || isQueueEmpty(queue)) {
		return FALSE;
	}
	data = queue->queue[queue->head];	//这里容易出错   不是：data = queue->queue[queue->head % queue->capacity];
	queue->head = (queue->head + 1) % queue->capacity;	//这里不是直接 queue->head++;   因为这里是循环队列
	queue->lastAction = OUT;	//队列是先入先出  所以出队列是对 queue->head 操作，而不是对 queue->tail 操作

	return data;
}

boolean isQueueEmpty(QUEUE *queue) {
	if (queue == NULL ) {
		return FALSE;
	}
	return queue->head == queue->tail && queue->lastAction == OUT;

}

boolean isQueueFull(QUEUE *queue) {
	if (queue == NULL ) {
		return FALSE;
	}
	return queue->head == queue->tail && queue->lastAction == IN;
}

void destoryQueue(QUEUE **queue) {
	if (queue == NULL || *queue == NULL) {
		return ;
	} 

	free((*queue)->queue);
	free(*queue);
	*queue = NULL;
	return ;
}

boolean initQueue(QUEUE **queue,int capacity) {
	QUEUE *head = NULL;

	if (queue == NULL || *queue != NULL || capacity <= 0) {
		return FALSE;
	}
	head = (QUEUE *) calloc(sizeof(QUEUE),1);

	if (head == NULL) {
		return FALSE;
	}

	head->queue = (USER_TYPE *) calloc(sizeof(USER_TYPE),capacity);

	if (head->queue == NULL) {
		free(head);
		head = NULL;
		return FALSE;
	}
	head->capacity = capacity;
	head->head = 0;
	head->tail = 0;
	head->lastAction = OUT;
	*queue = head;

	return TRUE;

}
