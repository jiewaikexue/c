
#include<stdio.h>
#include<Windows.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#define A 200

int * random_num()
{
	srand((unsigned)time(NULL));

	int * a = (int *)malloc(sizeof(int) * A);
	if (!a)return NULL;
	else
	{
		for (int i = 0; i < A; i++)
		{
			a[i] = rand() % 1000;
		}
	}
	return a;
}
void siftDown(int a,int *b,int c)
{
	int tmp = b[a];
	while (a < c / 2)
	{
		int childIndex = a * 2 + 1;
		int L_C_Index = a * 2 + 1;
		int R_C_Index = L_C_Index + 1;
		int child = b[L_C_Index];
		if (b[R_C_Index]>b[L_C_Index] && R_C_Index < c)
		{
			child = b[childIndex = R_C_Index];
		}if (tmp >= child)break;

		b[a] = child;
		a = childIndex;
	}
	b[a] = tmp;
	
}

void main()
{

	int * array = random_num();

	if (!array)return;
	else
	{
		for (int i = 0; i <A; i++)
		{
			printf("( %d ) -->%d \n  ", i, array[i]);
			
		}
		printf("\n");	printf("\n");	printf("\n");
		for (int i = A / 2 - 1; i >= 0; i--)
		{
		siftDown(i,array,A);
		}	
		int z = A;
		while (z > 1){
			int tmp = array[0];	
			array[0] = array[z-1];
			array[z-1] = tmp;
			z--;
			siftDown(0,array,z);
		}
		
	}for (int i = 0; i <A; i++)
	{
		printf("( %d ) -->%d  \n ", i,array[i]);
	}
	system("pause");

	

}