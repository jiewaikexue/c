#if 0
#include<stdio.h>
#include<Windows.h>

void exchange(int arr[], int x)
{
	int a[10];
	int b[10];
	int ax = 0;
	int bx = 0;
	for (int c = 0; c < x; c++)
	{
		if (arr[c] % 2 == 0)
		{
			a[ax] = arr[c];
			ax++;
		}
		else
		{
			b[bx] = arr[c];
			bx++;
		}
	}
	
	for (int e = 0; e < bx; e++)
	{
		arr[e] = b[e];
	}
	for (int d = 0; d < ax; d++)
	{
		arr[d+bx] = a[d];
	}
	

}
void main()
{
	
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	exchange(arr, 10);
	system("pause");
}
#endif