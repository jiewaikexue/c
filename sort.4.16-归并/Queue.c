#include "queue.h"
#include <stdlib.h>

void queueInit(Queue* q){
	//�ն���
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

void queuePush(Queue* q, QDataType data)
{
	//�����ڵ�
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	node->_next = NULL;
	//β��
	//����ǿն���
	if (q->_front == NULL)
	{
		q->_front = q->_rear = node;
	}
	else
		q->_rear->_next = node;

	//����β���
	q->_rear = node;
	++q->_size;
}

void queuePop(Queue* q)
{
	if (q->_front != NULL)
	{
		QNode* next = q->_front->_next;
		//ɾ��ͷ���
		free(q->_front);
		//����ͷ���
		q->_front = next;
		if (q->_front == NULL)
			q->_rear = NULL;

		--q->_size;
	}
}

QDataType queueFront(Queue* q)
{
	return q->_front->_data;
}

QDataType queueBack(Queue* q)
{
	return q->_rear->_data;
}

int queueEmpty(Queue* q)
{
	// if(q->_size == 0)
	if (q->_front == NULL)
		return 1;
	return 0;
}

size_t QueueSize(Queue* q)
{
	return q->_size;
}

void queueDestory(Queue* q)
{
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_rear = q->_front = NULL;
	q->_size = 0;
}