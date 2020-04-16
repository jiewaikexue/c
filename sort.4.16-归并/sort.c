#include "sort.h"
#include "stack.h"
#include "queue.h"
#include <memory.h>
#include <stdlib.h>
void swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


/*
ʱ�临�Ӷȣ��O(n^2)  ƽ��O(n^2)  ���O(n): ���ݱ�������
�ռ临�Ӷȣ�O(1)
�ȶ���: �ȶ�
�������У�����
*/
void insertSort(int* array, int n)
{
	//i: �������е����һ��λ��
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int key = array[end + 1];
		//�Ӻ���ǰ��һ�����ʵ�λ�ã����в���
		while (end >= 0 && array[end] > key)
		{
			array[end + 1] = array[end];
			--end;
		}
		//array[end] < key:  key����end����һ��λ��
		//����
		array[end + 1] = key;
	}
}
/*
ʱ�临�Ӷȣ�ƽ��O(n^1.3)  ���O(n): ���ݱ�������
�ռ临�Ӷȣ�O(1)
�ȶ���: ���ȶ�  ---> Ԥ������ƻ��ȶ��ԣ� ���ݿ��ܻ�ֵ���ͬ����
�������У�����
*/
void shellSort(int* array, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		// gap > 1:  Ԥ����
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
	//i�� δ�����Ԫ�ظ���
	for (int i = n; i > 0; --i)
	{
		//ÿ��ѡһ����С��ֵ������δ�������ݵ���ʼλ��
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
ʱ�临�Ӷȣ�� O(n^2)  ƽ�� O(n^2)  ���  O(n^2)
�ռ临�Ӷȣ�O(1)
�ȶ���: �ȶ�
�������У�������
*/
void selectSort2(int* array, int n)
{
	int begin = 0;
	int end = n - 1;
	int min, max;
	while (begin < end)
	{
		//ÿ����һ�����ֵ����Сֵ���ڵ�λ��
		min = max = begin;
		for (int j = begin + 1; j <= end; ++j)
		{
			if (array[j] >= array[max])
				max = j;
			if (array[j] < array[min])
				min = j;
		}
		//��Сֵ����ʼλ�ý���
		swap(array, begin, min);
		//���ֵ�ͽ���λ�ý���, ������ֵ��λ����begin���� ��ʱ��Ҫ����
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
ʱ�临�Ӷȣ��O(nlogn)  ƽ��O(nlogn)   ���O(nlogn)  
�ռ临�Ӷȣ�O(1)
�ȶ���: ���ȶ� ---> ���µ������ܻ��ƻ����λ��
�������У�������
*/
//����
void heapSort(int* array, int n)
{
	int end = n - 1;
	//�����
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		shiftDown(array, n, i);
	}
	//ѭ��ִ�У� swap, shiftDown
	while (end > 0)
	{
		swap(array, 0, end);
		//��ʣ��Ԫ�����µ���
		shiftDown(array, end, 0);
		--end;
	}
}

/*
ʱ�临�Ӷȣ��O(n^2)  ƽ��O(n^2)   ���O(n)
�ռ临�Ӷȣ�O(1)
�ȶ���: �ȶ� 
�������У�����
*/
void bubbleSort(int* array, int n)
{
	int end = n;
	while (end > 0)
	{
		//һ������
		// flag: һ���������Ƿ����˽�������
		int flag = 1;
		for (int i = 1; i < end; ++i)
		//for (int i = 0; i < end - 1; ++i) : array[i] > array[i + 1]
		{
			//�������ƶ��� ��ȵ�Ԫ�ز��ύ�������λ�ò���ı�
			if (array[i - 1] > array[i])
			{
				flag = 0;
				swap(array, i - 1, i);
			}
		}
		//���û�з���������˵������Ԫ��֮�����һ�������Ĺ�ϵ��������
		if (flag)
			break;

		--end;
	}
}
//����ȡ��
int getMid(int* array, int left, int right)
{
	int mid = left + (right - left) / 2;
	//�� array[left], array[mid], array[right]ѡһ���м�ֵ��λ��
	if (array[mid] > array[left])
	{
		if (array[mid] < array[right])   // left mid right
			return mid;
		else
		{
			// mid > left   mid >= right    
			if (array[left] > array[right])   //  right  left   mid
				return left;
			else
				return right;  //  left  right  mid
		}
	}
	else
	{
		// mid <= left
		if (array[mid] > array[right])  // right  mid  left
			return mid;
		else
		{
			//mid <= right   mid <= left
			if (array[left] < array[right])   // mid  left  right
				return left;
			else
				return right;  // mid  right  left  
		}

	}
}

int partion(int* array, int begin, int end)
{
	//��һ��������Ϊ��׼ֵ
	int key = array[begin];
	int start = begin;
	while (begin < end)
	{
		//�Ӻ���ǰ��С
		while (begin < end && array[end] >= key)
			--end;
		//��ǰ����Ҵ�
		while (begin < end && array[begin] <= key)
			++begin;
		//�����ҵ����������ݣ� ����
		swap(array, begin, end);
	}
	//������׼ֵ������λ�õ�ֵ
	swap(array, start, begin);
	//���ػ�׼ֵλ��
	return begin;
}

//�ڿӷ�
int partion2(int* array, int begin, int end)
{
	int key = array[begin];
	while (begin < end)
	{
		//�Ӻ���ǰ��С
		while (begin < end && array[end] >= key)
			--end;
		//��beginλ�õĿ�
		array[begin] = array[end];
		while (begin < end && array[begin] <= key)
			++begin;
		//��end��
		array[end] = array[begin];
	}
	//key ����������λ�ã� ���һ����
	array[begin] = key;
	return begin;
}

//ǰ��ָ�뷨
int partion3(int* array, int begin, int end)
{
	int mid = getMid(array, begin, end);
	swap(array, mid, begin);
	//prev: ���һ��С��key��λ��
	int prev = begin;
	//cur: ��һ��С��key��λ��
	int cur = begin + 1;
	int key = array[begin];
	while (cur <= end)
	{
		// �����һ��С��key��λ�������һ��С��key��λ�ò�������
		// ˵��cur, prev�м����д���key��ֵ, ����Ҫ��СԪ�ؽ��н���
		if (array[cur] < key && ++prev != cur)
			swap(array, cur, prev);
		++cur;
	}
	swap(array, begin, prev);
	return prev;
}

/*
    ʱ�临�Ӷȣ����: nlogn  ƽ��  nlogn   ��� n^2  (��������, һ�������Ż�����������ȡ�з��� ����ᷢ����
	�ռ临�Ӷȣ� logn
	�ȶ��ԣ����ȶ�  --> �����ǣ����ݻᷢ�����������ܻᵼ�����λ�÷����仯
	�������У� ����
*/

void quickSort(int* array, int begin, int end)
{
	if (begin >= end)
		return;
	//С�����Ż������ٵײ�ݹ�ĵ���
	if (end - begin + 1 < 10)
	{
		shellSort(array + begin, end - begin + 1);
	}
	else
	{
		int mid = partion3(array, begin, end);
		//����С����
		quickSort(array, begin, mid - 1);
		quickSort(array, mid + 1, end);
	} 
	
}

// �ǵݹ飺 ��¼ÿһ��ȷ������ʼ�ͽ���λ�ã�
//         Ȼ�����Ȼ��ִ����䣬�ٻ���С�����˳�������������Ļ��֣� �����������
// 1. ��ջ�����������ʼ�ͽ���λ��

void quickSortNoR(int* array, int n)
{
	Stack st;
	stackInit(&st, 10);
	//���ȱ��������
	if (n > 0)
	{
		stackPush(&st, n - 1);
		stackPush(&st, 0);
	}
	//������������л���
	while (stackEmpty(&st) != 1)
	{
			//��������û�л���
			//ȡ��һ���������ʼ�ͽ���λ��
			int left = stackTop(&st);
			stackPop(&st);
			int right = stackTop(&st);
			stackPop(&st);
			//���ֵ�ǰ����
			int div = partion3(array, left, right);
			//�������������ʼ�ͽ���λ��
			if (left < div - 1)
			{
				stackPush(&st, div - 1);
				stackPush(&st, left);
			}
			if (div + 1 < right)
			{
				stackPush(&st, right);
				stackPush(&st, div + 1);
			}
	}
	
}

// ���ŷǵݹ�
// �ö��б����������ʼ�ͽ���λ��
void quickSortNoR2(int* array, int n)
{
	//��ʼ������
	Queue q;
	queueInit(&q);
	if (n > 1)
	{
		//���˳�� �������
		queuePush(&q, 0);
		queuePush(&q, n - 1);
	}
	while (queueEmpty(&q) != 1)
	{
		//�Ӷ�ͷ��ȡ������Ϣ
		int left = queueFront(&q);
		queuePop(&q);
		int right = queueFront(&q);
		queuePop(&q);

		//����
		int div = partion3(array, left, right);
		//����֮����������
		if (left < div - 1)
		{
			queuePush(&q, left);
			queuePush(&q, div - 1);
		}
		if (div + 1 < right)
		{
			queuePush(&q, div + 1);
			queuePush(&q, right);
		}
	}
}


void mergeInternal(int* array, int left, int mid, int right, int* tmp)
{
	//����������鲢: [left, mid]  ��  [mid + 1, right]
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int idx = left;
	//�鲢
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (array[begin1] <= array[begin2])
			tmp[idx++] = array[begin1++];
		else
			tmp[idx++] = array[begin2++];
	}
	//����ʣ��Ԫ��
	if (begin1 <= end1)
		memcpy(tmp + idx, array + begin1, sizeof(int)* (end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, array + begin2, sizeof(int)* (end2 - begin2 + 1));
	//��ǰ�����������򣬰Ѹ����ռ��Ӧλ�õ�Ԫ�ؿ���ȥ
	memcpy(array + left, tmp + left, sizeof(int)* (right - left + 1));
}

void merge(int* array, int left, int right, int* tmp)
{
	//����ֻ��һ��Ԫ�أ�����Ҫ�ֽ⣬����Ҫ�鲢
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	
	//1.�ֽ�
	//���Ƚ���������Ĺ鲢����
	// [left, mid]
	merge(array, left, mid, tmp);
	// [mid + 1, right]
	merge(array, mid + 1, right, tmp);
	
	//2.�ϲ�
	// ǰ�᣺ [left, mid], [mid + 1, right]����
	//�鲢�� [left, mid], [mid + 1, right]
	mergeInternal(array, left, mid, right, tmp);
}

/*
  ʱ�临�Ӷȣ� � nlogn   ƽ��nlog   ��� nlogn
  �ռ临�Ӷȣ� n   ���������ռ�
  �ȶ��ԣ��ȶ�
  ���У� ������
*/

void mergeSort(int* array, int n)
{
	//�����ռ�
	int* tmp = (int*)malloc(sizeof(int)* n);
	merge(array, 0, n - 1, tmp);
	free(tmp);
}

void mergeSortNoR(int* array, int n)
{
	//num: ÿ�δ��鲢��������Ԫ�ظ���
	int num = 1;
	int* tmp = (int*)malloc(sizeof(int)* n);
	while (num < n)
	{
		//ÿ�ζ�Ҫ�����������Ԫ�ؽ��й鲢
		for (int i = 0; i < n; i += 2 * num)
		{
			//��һ������ [left, mid], �ڶ������� [mid + 1, right]
			int left = i;
			int mid = i + num - 1;

			if (mid >= n - 1)
				//û�еڶ�������, ����Ҫ�鲢, ʣ���һ�����䲻Ҫ�鲢
				continue;

			int right = i + 2 * num - 1;
			//�жϵڶ�������Ľ���λ���Ƿ�Խ��
			if (right >= n)
				right = n - 1;

			mergeInternal(array, left, mid, right, tmp);
		}
		num *= 2;
	}
	free(tmp);
}

/*
ʱ�临�Ӷȣ� max(n, range)
�ռ临�Ӷȣ� range
�ȶ��ԣ��ȶ�
���У� ������
ֻ�ʺ�С��Χ������
*/
void countSort(int* array, int n)
{
	//�ҵ����ֵ����Сֵ
	int max = array[0], min = array[0];
	int range;
	int* countArr;
	int idx = 0;
	for (int i = 1; i < n; ++i)
	{
		if (array[i] < min)
			min = array[i];
		if (array[i] > max)
			max = array[i];
	}
	//���ݷ�Χ
	range = max - min + 1;
	countArr = (int*)malloc(sizeof(int)* range);
	// countArr = (int*)calloc(sizeof(int)* range);  calloc: ��ɿռ������0�ĳ�ʼ��
	memset(countArr, 0, sizeof(int)* range);
	//��¼ÿһ�����ݳ��ֵĴ���
	for (int i = 0; i < n; ++i)
	{
		countArr[array[i] - min]++;
	}
	//������������
	for (int i = 0; i < range; ++i)
	{
		//�п������ظ�����
		while (countArr[i]--)
		{
			array[idx++] = i + min;
		}
	}
}


