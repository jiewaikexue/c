
#include<stdio.h>
#include<Windows.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#define A 50

int * random_num()
{
	srand((unsigned)time(NULL));

	int * a = (int *)malloc(sizeof(int) * A);
	if (!a)return NULL;
	else
	{
		for (int i = 0; i < A; i++)
		{
			a[i] = rand() % 100;
		}
	}
	return a;
}
void siftDown(int i,int * a,int heapsize)
{
	int x = a[i];
	while (i<heapsize/2)
	{
		int childIndex = i*2+1;
		int L_C_Index = i * 2 + 1;
		int R_C_Index = L_C_Index + 1;
		int child = a[L_C_Index];
		if (R_C_Index<heapsize&&child<a[R_C_Index])
		{
			child = a[childIndex=R_C_Index];
		}
		if (x >= child)break;
		
		a[i] = child;
		i = childIndex;
	}
	a[i] = x;
}

void main(){
	int * array = random_num() != NULL ? random_num():NULL;
	int ab[A] = { 0 };
	for (int i = 0; i < A; i++)
	{
		ab[i] = array[i];
	}
	for (int i = A / 2 - 1; i >= 0; i--)
	{
		siftDown(i,ab,A);
	}
	int z = A;
	while (z > 1)
	{
		int tmp = ab[z - 1];
		ab[z - 1] = ab[0];
		ab[0] = tmp;
		siftDown(0, ab, --z);
	}
	system("pause");
	
}