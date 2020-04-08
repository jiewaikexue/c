#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sort.h"
void printArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void test1()
{
	int array[] = { 10, -1, 2, 9, 3, 4, 5, 6, 7, 100 };
	int num = sizeof(array) / sizeof(array[0]);
	int* copy = (int*)malloc(num * sizeof(int));
	memcpy(copy, array, sizeof(int)* num);
	printArray(array, num);
	insertSort(array, num);
	printArray(array, num);

	printArray(copy, num);
	shellSort(copy, num);
	printArray(copy, num);


}

void testTime()
{
	int n;
	int* array, *copy;
	scanf("%d", &n);
	array = (int*)malloc(sizeof(int)* n);
	copy = (int*)malloc(sizeof(int)* n);
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
	{
		array[i] = rand();
	}
	
	memcpy(copy, array, sizeof(int)* n);
	/*
	size_t  begin = clock();
	insertSort(array, n);
	size_t  end = clock();
	printf("%d\n", end - begin);

	begin = clock();
	insertSort(array, n);
	end = clock();
	printf("%d\n", end - begin);
	*/
	size_t begin = clock();
	shellSort(copy, n);
	size_t end = clock();
	printf("%d\n", end - begin);
}
int main()
{
	//test1();
	testTime();
	return 0;
}