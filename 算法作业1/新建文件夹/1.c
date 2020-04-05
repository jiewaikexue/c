#include<stdio.h>
#include<windows.h>
#include<math.h>
static void setpos(int x,int y)
{
	COORD point={x,y};
	HANDLE houtput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(houtput,point);
}
int Chun(int i,int j,int p,int n)
{       
	     int y=0;
	     int m=0;
	for(;i<=n;i++)
	{
	 
		setpos(i*4,j);
			printf("%d",p);
			
		    	p++;
                m++;

	}

    i=i*4-4;
	j++;
	for(;j<=n;j++)
	{
		setpos(i,j);
		printf("%d",p);
		p++; 
        y++;
			
	}
	j--;
	for(m--;m>=1;m--)
	{   i=i-4;
		setpos(i,j);
		printf("%d",p);
		p++;
                               
	}
    
    n--;
    j--;
	for(y--;y>=1;y--)
	{  
		setpos(i,j);
		 j--;
		printf("%d",p);
		p++;}
		
    
        return p;


}
void main()
{ int i;
int k;
int j;
int n=7;
int p;
int q;
q=n/2+1;
p=1;
for(i=1,j=1;j<=q;i++,j++)
{ p=Chun(i,j,p,n);
 n=n-1;


}
for(k=1;k<=20;k++){
		printf("\n");}

}