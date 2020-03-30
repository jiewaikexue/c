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

//��ͳ��������
//��1��ʼ��Ĭ��0��Ԫ���������
//ûѡ��һ��Ԫ�أ�������ǰ���һ��Ԫ�ؽ��бȽ�
//���С��ǰ���Ԫ�أ�����Ԫ�ؽ���
//�������֮�󣬲�����ֱ���˳�ѭ����
//��Ϊ����֮�󣬲�����ȷ��������ǰ���Ԫ��Ҳ����ȫ�����
//���Ի���Ҫ������ǰ�Ƚ�
//ֱ�������˵�һ��С������Ԫ�أ����߱Ƚ��귢���Լ�����С��1
//���ʱ���˳���ѭ�����ڰ��մ˲������ÿһ��Ԫ�ء�
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
//�Ż�1
//������������һ��������Ż���
//ֻ����һ�Σ��ߴ��ڴ�����Ԫ�ص�Ԫ�غ���
//ֱ��������һ�������ڴ�����Ԫ�ص�Ԫ��
//Ȼ������ȱ��ݵĴ�����Ԫ�ظ��ǵ���ǰ�±�����λ�á�
//����---����Ϊ����������ƣ��ͻ��ƻ�������Ԫ��
//�����±�Ԫ��----�����������ƻ�ԭ�����飬��Ϊ��������˺��ƣ��������λ�õ�Ԫ���Ѿ��ں���1�����ˣ�����ֻ��Ҫ���ǵ�ǰ��
//������Ԫ�����ڵ�λ�þͺ���
//��Ȼֻ����Ԫ�أ��������н����������Ͳ���ʹ��insertionSort1�еıȽ�������ֻ������ǰ���ݵĴ�����Ԫ�ؽ��бȽ�
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

//�Ż�3
//����---��ǰ����Ѿ������Ԫ�ؽ��ж����������ҵ���ǰԪ�صĴ�����λ�ã�һ����λ������Ƶ���ıȽϡ�
//���������ô�--�ҵ���һ�����ڸ�Ԫ�ص�Ԫ�أ�����������λ��
//������һ��Ҳ������Ϊʲô��a[index] =a[mid]ʱҲҪ�����ж���������ͬʱ������Ҳȷ����������ȶ���
//insert---�Դ�����Ԫ��ԭ����λ�ã��Ͷ�������֮��ȷ����ֱ�Ӳ����λ��֮�������Ԫ�ؽ��к��� Ȼ���ٲ��������Ԫ��
//������ȷ���˴�����Ԫ��֮ǰ��ȫ����
//insertionSort3----�Ϸ��������α���ÿһ��Ԫ�أ���������ȷ����Ԫ�ش������λ�ã�insert���д��ģ�ƶ�֮���γ�ǰ�벿�ֵ�����


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
			begin = mid + 1;//Ҫ�ҵ���һ�����ڴ�����Ԫ�ء���ʹ��a[index] =a[mid]ҲҪ��mid֮����ж�������//������֤���ȶ���

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