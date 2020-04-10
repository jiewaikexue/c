#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
#include "common.h"
//À≥–Ú±Ì µœ÷’ª


typedef Node* SDataType;

typedef struct Stack
{
	SDataType* _array;
	size_t _size;
	size_t _capacity;
}Stack;

void stackInit(Stack* st, size_t n);

void stackPush(Stack* st, SDataType data);

void stackPop(Stack* st);

SDataType stackTop(Stack* st);

size_t stackSize(Stack* st);

int stackEmpty(Stack* st);

void stackDestory(Stack* st);




