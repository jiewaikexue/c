//Boubblesort1
#include<stdio.h>
#include<Windows.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#define A 60000*5

int * random_num()
{
	srand((unsigned)time(NULL));

	int * a = (int *)malloc(sizeof(int) * A);
	if (!a)return NULL;
	else
	{
		for (int i = 0; i < A; i++)
		{
			a[i] = rand() % 100000;
		}
	}
	return a;
}
void MY_printf(int *a, int size)
{
	for (int i = 0; i <size; i++)
	{
		printf("( %d ) -->%d \n  ", i, a[i]);

	}
	printf("============================================================\n");
}



void merge(int begin, int mid, int end, int *ab)
{
	int *a = (int *)malloc(sizeof(int)*(mid - begin));//备份左边的
	
	if (!a)return;
	else{
		int *backupsarray = a;
		for (int i = 0; i < mid-begin; i++)
		{
			backupsarray[i] = ab[begin + i];
		}
		int backupsbegin = 0, backupsend = mid - begin;
		int ri = mid, re = end;
		int ai = begin;
		while (backupsbegin < backupsend)
		{
			if (backupsarray[backupsbegin] >ab[ri] && ri < re)
			{
				ab[ai++] = ab[ri++];
			}
			else
			{
				ab[ai++] = backupsarray[backupsbegin++];
			}
		}
	free(a);
	}
}

void sort(int begin, int end, int *ab)
{
	if ((end - begin) < 2)return;
	int mid = (begin + end) >> 1;
	sort(begin, mid, ab);// [begin，mid）
	sort(mid, end, ab);//统一采用左闭右开区间  [mid,end)
	merge(begin, mid, end, ab);// [begin，mid） [mid,end)
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
		sort(0, A, ab);
		MY_printf(ab, A);
	}
	system("pause");
	
}