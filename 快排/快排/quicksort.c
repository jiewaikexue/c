//Boubblesort1
#include<stdio.h>
#include<Windows.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#define A 60000000

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
void MY_printf(int *a, int size)
{
	for (int i = 0; i <size; i++)
	{
		printf("( %d ) -->%d \n  ", i, a[i]);

	}
	printf("============================================================\n");
}

void sort(int *a ,int begin ,int end)
{
	if ((end - begin) < 2)return;
	int mid = pivotIndex(a,begin, end);
	// 对子序列进行快速排序
	sort(a,begin, mid);
	sort(a,mid + 1, end);
}
int pivotIndex(int *a,int begin, int end) 
{
	int pivot = a[begin];//选取最左边的元素作为轴点元素
	end--;
	while (begin < end)
	{
		while (begin<end)
		{
			if (a[end]>pivot)
				end--;
			else{
				a[begin++] = a[end];
				break;
			}
		}
		while (begin<end)
		{
			if (a[begin]<pivot)
				begin ++ ;
			else
			{
				a[end--] = a[begin];
				break;
			}
		}
	}
	a[begin] = pivot;
	return begin;
}
void main()
{
	int * array = random_num();
	if (!array)return;
	else
	{
		int *ab = array;
		//MY_printf(ab, A);
		sort(ab, 0,A);
		//insertionSort(ab,A);
		//insertionSort3(ab, A);
		//MY_printf(ab, A);
		printf("( %d ) -->%d \n  ", 5, ab[5]);
	}
	system("pause");

}