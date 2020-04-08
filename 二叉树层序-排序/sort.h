#pragma once

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



