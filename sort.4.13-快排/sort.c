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


int partion(int* array, int begin, int end)
{
	//第一个数据作为基准值
	int key = array[begin];
	int start = begin;
	while (begin < end)
	{
		//从后向前找小
		while (begin < end && array[end] >= key)
			--end;
		//从前向后找大
		while (begin < end && array[begin] <= key)
			++begin;
		//可能找到了两个数据， 交换
		swap(array, begin, end);
	}
	//交换基准值和相遇位置的值
	swap(array, start, begin);
	//返回基准值位置
	return begin;
}

//挖坑法
int partion2(int* array, int begin, int end)
{
	int key = array[begin];
	while (begin < end)
	{
		//从后向前找小
		while (begin < end && array[end] >= key)
			--end;
		//填begin位置的坑
		array[begin] = array[end];
		while (begin < end && array[begin] <= key)
			++begin;
		//填end坑
		array[end] = array[begin];
	}
	//key 放入相遇的位置： 最后一个坑
	array[begin] = key;
	return begin;
}

//前后指针法
int partion3(int* array, int begin, int end)
{
	//prev: 最后一个小于key的位置
	int prev = begin;
	//cur: 下一个小于key的位置
	int cur = begin + 1;
	int key = array[begin];
	while (cur <= end)
	{
		// 如果下一个小于key的位置与最后一个小于key的位置不连续，
		// 说明cur, prev中间是有大于key的值, 则需要大小元素进行交换
		if (array[cur] < key && ++prev != cur)
			swap(array, cur, prev);
		++cur;
	}
	swap(array, begin, prev);
	return prev;
}

void quickSort(int* array, int begin, int end)
{
	if (begin >= end)
		return;
	int mid = partion3(array, begin, end);
	//划分小区间
	quickSort(array, begin, mid - 1);
	quickSort(array, mid + 1, end);
}
