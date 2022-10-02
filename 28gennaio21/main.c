#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp=fopen("comuni.csv");
    if(!fp)
    {
        perror("Errore");
        exit(1);
    }

    char riga[71];
    int count;
    while((fscanf("%[^\n]", riga))!=EOF)
    {
        count++;
    }
    return 0;
}
