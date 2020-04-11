#include "test.hpp"
#include <unistd.h>


int main()
{
    char* lp = (char*)malloc(10);
    strcpy(lp, "linux-68");
    printf("lp : %s\n", lp);
    free(lp);
    free(lp);
    func(5, 14);
    TestUserInfo();
    while(1)
    {
        printf("hhehheh\n");
        sleep(1);
    }
    return 0;
}
