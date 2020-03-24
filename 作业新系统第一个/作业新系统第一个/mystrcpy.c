#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

void mystrcpy(char a[], const char *c)
{
	char *b = c;
	if (a == NULL)
	{
		exit(-1);
	}
	else if (b == NULL)
	{
		return a;
	}

	else
	{
		for (int x = 0; ; b = b + 1,x++)
		{
			a[x] = *b;
			if (*b == '\0')
			{
				break;
			}
		}
		
	}
	return a;

}

int mystrlen(char const *p)
{
	int x = 0;
	for (; *p != '\0'; p = p + 1, x++)
	{
		;
	}
	return x;
}

void main()
{
	char *a ="hellow word" ;
	char *b = "i want to sleep";
	char c[50] ;
	mystrcpy(c, b);
	int y=mystrlen(a);
	system("pause");
}