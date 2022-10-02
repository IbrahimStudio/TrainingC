#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int righefile(const char valuta);

int main()
{
    char valuta[5];
    printf("Indicare la valuta con cui si vuole confrontare l'EUR: ");
    scanf("%s", valuta);

    int nrighe=0;



/*
    if(strcmp(valuta,'USD'))
    {
        printf("Apro il file USD, %s", valuta);
        FILE *fp=fopen("USD.txt", "r");
        if(!fp)
        {
            perror("ERRORE");
            exit(1);
        }
        char temp[100];
        while((fscanf(fp, " %[^\n]", temp))!=EOF)
        {
            nrighe++;
        }
        fclose(fp);
          printf("il file contiene %d righe", nrighe);
    }
    else
        printf("errore");

        else if(strcmp(valuta,'AUD'))
    else if(strcmp(valuta,'CAD'))
    else if(strcmp(valuta,'GBP'))
    else if(strcmp(valuta,'HKD'))

*/
    ///parte di codice per aprire e contare i file con la funzione


    char par[10]; //= {'"', valuta[0], valuta[1], valuta[2], '.', 't', 'x', 't', '"'};
    strcpy(par, valuta);
    strcat(par,".txt");


    printf("%s", par);

    FILE *fp=fopen(par, "r");
    if(!fp)
    {
        perror("ERRORE");
        exit(1);
    }
    else{

    char val[10];
    float tasso;
    int anno, mese, giorno, count=0;

    while((fscanf(fp," %s, %f, %d, %d, %d", val, &tasso, &anno, &mese, &giorno))==5)
    {
        count++;
        printf("%s, %f, %d, %d, %d", val, tasso, anno, mese, giorno);
    }

    fclose(fp);

    }

    return 0;
}

int righefile(const char par)
{
    FILE *fp=fopen(par, "r");
    if(!fp)
    {
        perror("ERRORE");
        exit(1);
    }

    char val[10];
    float tasso;
    int anno, mese, giorno, count=0;

    while((fscanf(fp," %s,%f,%d,%d,%d", val, &tasso, &anno, &mese, &giorno))==5)
    {
        count++;
        printf("%s, %f, %d, %d, %d", val, tasso, anno, mese, giorno);
    }

    fclose(fp);

    return count;
}

