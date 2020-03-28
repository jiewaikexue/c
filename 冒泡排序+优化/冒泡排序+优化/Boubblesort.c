//Boubblesort1
#include<stdio.h>
#include<Windows.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#define A 10

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
void MY_printf(int *a,int size )
{
	for (int i = 0; i <size; i++)
	{
		printf("( %d ) -->%d \n  ", i, a[i]);

	}
	printf("============================================================\n");
}
void Boubblesort1(int *a,int size)
{
	for (int i = size-1; i >0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[j]<a[j-1]) {
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
	}
}
void Boubblesort2(int *a, int size)
{
	for (int i = size - 1; i >0; i--)
	{
		int key = 1;
		for (int j = 1; j <= i; j++)
		{
			if (a[j]<a[j - 1]) {
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
				key = 0;
			}
		}
		if (key)return;
	}
}
void Boubblesort3(int *a, int size)
{
	for (int i = size - 1; i >0; i--)
	{
		int LastIndex = 1;
		for (int j = 1; j <= i; j++)
		{
			if (a[j]<a[j - 1]) {
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
				LastIndex = j;
			}
		}

		i = LastIndex;
	}
}
void main()
{
	int * array = random_num();
	if (!array)return;
	else
	{
		int ab[A] = { 0 };
		for (int i = 0; i <A; i++)
		{
			ab[i] = array[i];

		}
		MY_printf(ab, A);
		
		//Boubblesort1(ab, A);
		//Boubblesort2(ab, A);
		Boubblesort3(ab, A);
		MY_printf(ab, A);
	}
	system("pause");

}