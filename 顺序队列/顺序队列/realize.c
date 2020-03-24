#include"queeu.h"
int queueInit(Queue* q,size_t CAP)
{
	
	DataType *x = (DataType *)calloc(q->capaciaty = q->capaciaty>CAP ? q->capaciaty:CAP, sizeof(DataType));
	if (!x)return -1;
	else
	
		q->array = x;
	return 0;
}


int  queuePush(Queue* q, DataType data)
{
	if (isEmpty(q))
	{
		DataType * x = (DataType *)malloc(q->array, sizeof(DataType)*q->capaciaty <<1);
		if (!x)return -1;
		else
		{
			for (int i = 0; i < q->capaciaty; i++)
			{
				x[i] = q->array[(q->head_index + i)%q->size];
				
			}	
				q->head_index = 0;
				free(q->array);
				q->array = x;
				q->capaciaty = q->capaciaty << 1;
		}
	}
	q->array[(q->size+q->head_index)%q->capaciaty] = data;
	q->size++;
}

int queuePop(Queue* q)
{
	if (!q->size)
	{
		printf("队列已经空了\n");
		return -1;
	}
	else if (q->size==1)
	{
		printf("本次删除后队列为空\n");
		
	}
	int x=q->head_index;
	q->array[q->head_index] = -1024;
	q->head_index = (x + 1)%q->capaciaty;
	q->size--;
}

int queueDistory(Queue *q)
{
	if (!q->size)
	{
		printf("销毁失败");
		return -1;
	}
	else
	{
		free(q->array);
		printf("销毁成功");
		return 1;
	}
}






int isEmpty(Queue* q)
{
	return q->size < q->capaciaty ? 0: 1;
}
