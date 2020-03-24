#ifndef _STACK_
#define _STACK_
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#pragma warning(disable:4996)
typedef int DataType;
typedef struct Node{
	DataType num;
	struct Node *next;
}Node;
typedef struct Stack
{
	struct Node* Top;
	struct Node* Bottom;
	size_t size;

}Stack;
void stackInit(Stack *A, size_t n);
void stackPush(Stack* A, DataType data);
void stackPop(Stack* st);
DataType stackTop(Stack* st);
size_t stackSize(Stack* st);
int stackEmpty(Stack* st);
void stackDestory(Stack* st);
#endif 
