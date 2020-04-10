#pragma  once
//����βָ��ĵ�����ʵ�ֶ���
#include <stdio.h>
typedef int QDataType;
typedef struct QNode
{
	struct QNode* _next;
	QDataType _data;
} QNode;

typedef struct Queue
{
	//ͷβָ��
	QNode* _front;
	QNode* _rear;
	size_t _size;
}Queue;

void queueInit(Queue* q);

void queuePush(Queue* q, QDataType data);

void queuePop(Queue* q);

QDataType queueFront(Queue* q);

QDataType queueBack(Queue* q);

int queueEmpty(Queue* q);

size_t QueueSize(Queue* q);

void queueDestory(Queue* q);