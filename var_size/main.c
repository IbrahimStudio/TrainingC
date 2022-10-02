#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("La dimensione in byte delle variabili e':\n\n");
    printf("char: \t%d\n", sizeof(char));
    printf("short: \t%d\n", sizeof(short));
    printf("int: \t%d\n", sizeof(int));
    printf("long: \t%d\n", sizeof(long));
    printf("float: \t%d\n", sizeof(float));
    printf("double:\t%d\n", sizeof(double));
    return 0;
}
