//Boubblesort1
#include<stdio.h>
#include<Windows.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#define A 500

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

//传统插入排序
//从1开始，默认0号元素是有序的
//没选择一个元素，就与他前面的一个元素进行比较
//如果小于前面的元素，两个元素交换
//交换完毕之后，并不能直接退出循环，
//因为交换之后，并不能确保他和他前面的元素也是完全升序的
//所以还需要继续往前比较
//直到遇到了第一个小于他的元素，或者比较完发现自己是最小的1
//这个时候退出内循环，在按照此步骤遍历每一个元素。
void insertionSort1(int *a, int size)
{
	for (int i = 1; i < size; i++)
	{
		int cur = i;
		while (cur > 0 && a[cur] < a[cur - 1])
		{
			int tmp = a[cur];
			a[cur] = a[cur - 1];
			a[cur - 1] = tmp;

			cur--;
		}
	}
}
//优化1
//对两两交换这一步骤进行优化，
//只交换一次，暨大于待插入元素的元素后移
//直到遇到第一个不大于待插入元素的元素
//然后把事先备份的待插入元素覆盖到当前下标所在位置。
//备份---是因为如果发生后移，就会破坏待插入元素
//覆盖下标元素----这样并不会破坏原有数组，因为如果发生了后移，则待插入位置的元素已经在后面1格有了，我们只需要覆盖当前这
//个垃圾元素所在的位置就好了
//既然只后移元素，而不进行交换，这样就不能使用insertionSort1中的比较条件，只能用提前备份的待插入元素进行比较
void insertionSort2(int *a, int size)
{
	for (int i = 1; i < size; i++)
	{
		int cur = i;
		int x = a[i];
		while (cur > 0 && x < a[cur - 1])
		{
			a[cur] = a[cur - 1];
			cur--;
		}
		a[cur] = x;
	}
}

//优化3
//核心---对前面的已经有序的元素进行二分搜索，找到当前元素的待插入位置，一步到位，减少频繁的比较。
//二分搜索用处--找到第一个大于该元素的元素，并返回他的位置
//上面这一条也解释了为什么当a[index] =a[mid]时也要向后进行二分搜索，同时这样做也确保了排序的稳定性
//insert---对待插入元素原本的位置，和二分搜索之后确定的直接插入的位置之间的所用元素进行后移 然后再插入待插入元素
//这样就确保了待插入元素之前完全有序
//insertionSort3----老方法，依次遍历每一个元素，二分搜索确定该元素待插入的位置，insert进行大规模移动之后形成前半部分的有序


void insert1(int *a, int b, int c)
{
	int v = a[b];
	for (int i = b; i > c; i--) {
		a[i] = a[i - 1];
	}
	a[c] = v;
}
int  Two_point_search(int *a, int index){
	int begin = 0;
	int end = index;
	while (begin < end)
	{
		int mid = (begin + end) >> 1;
		if (a[index] < a[mid])
		{
			end = mid;
		}
		else
		{
			begin = mid + 1;//要找到第一个大于待插入元素。即使是a[index] =a[mid]也要在mid之后进行二分搜索//这样保证了稳定性

		}
	}
	return begin;

}
void insertionSort3(int *a, int size)
{
	for (int begin = 1; begin < size; begin++)
	{
		insert1(a, begin, Two_point_search(a, begin));
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

		//insertionSort(ab,A);
		insertionSort3(ab, A);
		MY_printf(ab, A);
	}
	system("pause");

}