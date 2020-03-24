#include"sta.h"



void stackPush(Stack* A, DataType data)
{
	Node * x = (Node *)malloc(sizeof(Node));
	x->num = data;
	x->next = NULL;
	if (A->Bottom == NULL)
	{
		A->Bottom = x;
		A->Top = x;
		A->size++;

	}
	else
	{
		x->next = A->Top;
		A->Top = x;
		A->size++;
	}
}
void stackPop(Stack* st)
{
	if (st->Top != st->Bottom)
	{
		Node *x = st->Top;
		st->Top = x->next;
		free(x);
		st->size--;
	}
	else
	{
		Node *y = st->Top;
		st->Top = NULL;
		st->Bottom = NULL;
		free(y);
		st->size--;
	}
}

DataType stackTop(Stack* st);
size_t stackSize(Stack* st);
int stackEmpty(Stack* st);
void stackDestory(Stack* st);