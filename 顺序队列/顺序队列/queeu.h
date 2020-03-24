#ifndef _Queue_
#define _Queue_

#include<stdio.h>
#include<Windows.h>
#include <stdlib.h>
#pragma warning (disable:4996)
typedef int DataType;

typedef struct Queue{
	size_t size;
	DataType *array;
	size_t capaciaty;
	DataType head_index;
}Queue;
int queueInit(Queue* q,size_t CAP);
int queuePush(Queue* q, DataType data);

int queuePop(Queue* q);

DataType queueFront(Queue* q);

DataType queueBack(Queue* q);

int queueEmpty(Queue* q);

size_t QueueSize(Queue* q);
int isEmpty(Queue* q);
#endif