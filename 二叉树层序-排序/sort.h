#pragma once

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



