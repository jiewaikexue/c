#include<stdio.h>

int main()
{
	int temp, temp1; int count = 0;
	int n;
	int i;
	printf("~~~~此程序カ竍算1x2x3…n.所得的数末尾有多少个零。~~~~~~\n\n");
	printf(" please input a number between 1000and 10000:\n");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		temp = i % 10;
		if (temp == 5)
			count++;
		else
			if (temp == 0){
				temp1= i;
				while((temp1% 10) == 0)
				{
					temp1 = temp1 / 10;
					count++;
				}
			}
	}
	printf("There are %d zeros.n ", count);
	return 0;
}




#include <stdio.h>
void main()
{
int a,b,c,d,e;
for(a=1;a<=5;a=a+1)
for(b=1;b<=5;b=b+1)
if(a!=b)
for(c=1;c<=5;c=c+1)
if(c!=a&&c!=b)
for(d=1;d<=5;d=d+1)
if(d!=a&&d!=b&&d!=c)
{
e=15-a-b-c-d;
if(e!=a&&e!=b&&e!=c&&e!=d)
if((((b==3)+(c==5))==1)&&(((d==2)+(e==4))==1)&&(((b==1)+(e==4))==1)&&(((c==1)+(b==2))==1)&& (((d==2)+(a==3))==1))
printf('a=%d;b=%d;c=%d;d=%d;e=%d',a,b,c,d,e);
}
}


#include "stdio.h"
#include "math.h"
main()
{int a,b,k;
int sqr(int a);
int fff(int b);
for (a=100;a<1000;a++)
{b=sqr(a);
k=fff(a);
if(b==k) printf("%d\n",b);}
}
int sqr(int a)
{float n;
n=sqrt(a);
if(n==(int)n) return(a);
}
int fff(int b)
{int g,s,a;
a=b/100;
s=(b-a*100)/10;
g=b-a*100-s*10;
if(a==s||a==g||s==g) return(b);
}
