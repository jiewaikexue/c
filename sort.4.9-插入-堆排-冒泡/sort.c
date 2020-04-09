#include "sort.h"

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

