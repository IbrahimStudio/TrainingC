#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=5;
    int *p;

    *p=a;
    printf("a = %d, p=%d, p=%p", a, p, p);
    return 0;
}
