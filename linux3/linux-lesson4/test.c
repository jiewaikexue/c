#include <stdio.h>

//不严谨的宏定义
#define calc(x,y) x + y * x + y
// 2 + 3 * 2 + 3   理论上是25
//                 实际是11

int main()
{
    //printf("linux-68\n");
    //printf("linux-68\n");
    //printf("linux-68\n");
    //printf("linux-68\n");
    printf("linux-68\n");
    printf("%d\n", calc(2 ,3));
    //printf("linux-68\n");
    //printf("linux-68\n");
    return 0;
}
