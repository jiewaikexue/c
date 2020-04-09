#include "sort.h"

void swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


/*
时间复杂度：最坏O(n^2)  平均O(n^2)  最好O(n): 数据本身有序
空间复杂度：O(1)
稳定性: 稳定
数据敏感：敏感
*/
void insertSort(int* array, int n)
{
	//i: 有序序列的最后一个位置
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int key = array[end + 1];
		//从后向前找一个合适的位置，进行插入
		while (end >= 0 && array[end] > key)
		{
			array[end + 1] = array[end];
			--end;
		}
		//array[end] < key:  key放在end的下一个位置
		//插入
		array[end + 1] = key;
	}
}
/*
时间复杂度：平均O(n^1.3)  最好O(n): 数据本身有序
空间复杂度：O(1)
稳定性: 不稳定  ---> 预排序会破坏稳定性： 数据可能会分到不同的组
数据敏感：敏感
*/
void shellSort(int* array, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		// gap > 1:  预排序
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int key = array[end + gap];
			while (end >= 0 && array[end] > key)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}

}

void selectSort(int* array, int n)
{
	//i： 未排序的元素个数
	for (int i = n; i > 0; --i)
	{
		//每次选一个最小的值，存入未排序数据的起始位置
		int start = n - i;
		int min = start;
		for (int j = start; j < n; ++j)
		{
			if (array[j] < array[min])
				min = j;
		}
		swap(array, start, min);
	}
}


/*
时间复杂度：最坏 O(n^2)  平均 O(n^2)  最好  O(n^2)
空间复杂度：O(1)
稳定性: 稳定
数据敏感：不敏感
*/
void selectSort2(int* array, int n)
{
	int begin = 0;
	int end = n - 1;
	int min, max;
	while (begin < end)
	{
		//每次找一个最大值和最小值所在的位置
		min = max = begin;
		for (int j = begin + 1; j <= end; ++j)
		{
			if (array[j] >= array[max])
				max = j;
			if (array[j] < array[min])
				min = j;
		}
		//最小值和起始位置交换
		swap(array, begin, min);
		//最大值和结束位置交换, 如果最大值的位置在begin处， 此时需要更新
		if (max == begin)
			max = min;
		swap(array, end, max);

		++begin;
		--end;
	}
}

void shiftDown(int* array, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && array[child + 1] > array[child])
			++child;
		if (array[child] > array[parent])
		{
			swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

/*
时间复杂度：最坏O(nlogn)  平均O(nlogn)   最好O(nlogn)  
空间复杂度：O(1)
稳定性: 不稳定 ---> 向下调整可能会破坏相对位置
数据敏感：不敏感
*/
//升序
void heapSort(int* array, int n)
{
	int end = n - 1;
	//建大堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		shiftDown(array, n, i);
	}
	//循环执行： swap, shiftDown
	while (end > 0)
	{
		swap(array, 0, end);
		//给剩余元素向下调整
		shiftDown(array, end, 0);
		--end;
	}
}

/*
时间复杂度：最坏O(n^2)  平均O(n^2)   最好O(n)
空间复杂度：O(1)
稳定性: 稳定 
数据敏感：敏感
*/
void bubbleSort(int* array, int n)
{
	int end = n;
	while (end > 0)
	{
		//一趟排序
		// flag: 一趟排序中是否发生了交换操作
		int flag = 1;
		for (int i = 1; i < end; ++i)
		//for (int i = 0; i < end - 1; ++i) : array[i] > array[i + 1]
		{
			//大的向后移动， 相等的元素不会交换，相等位置不会改变
			if (array[i - 1] > array[i])
			{
				flag = 0;
				swap(array, i - 1, i);
			}
		}
		//如果没有发生交换，说明序列元素之间就是一个递增的关系，已有序
		if (flag)
			break;

		--end;
	}
}

