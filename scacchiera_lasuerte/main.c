#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

int main()
{
    char colonne[SIZE]={'a','b','c','d','e','f','g','h'};
    char righe[SIZE]={'1','2','3','4','5','6','7','8'};
    char scacchiera[SIZE*SIZE]={
    'R','N','B','Q','K','B','N','R',
    'p','p','p','p','p','p','p','p',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    'p','p','p','p','p','p','p','p',
    'r','n','b','q','k','b','n','r'
    };

    int r;
    char c;

    printf("    ");

    for(c='a'; c<='h'; c++)
    {
        printf("  %c ", c);
    }

    printf("\n+---+---+---+---+---+---+---+---+---+");


    printf("\n");

    for(r=0; r<SIZE; r++)
    {
        printf("  %c |", righe[r]);

        for(c=0; c<SIZE; c++)
        {
            printf(" %c |", scacchiera[r*SIZE+c]);
        }

        printf("\n+---+---+---+---+---+---+---+---+---+\n");

    }

 /*   while(1)
    {


        char mossa[6];
        printf("Digita la mossa in formato 'pezzo'-'partenza'-'arrivo' - pa7a5: ");
        gets(mossa);
        printf("La mossa inserita e': %s", mossa);

        c1 =



        printf("    ");

        for(c=0; c<SIZE; c++)
        {
            printf("  %c ", colonne[c]);
        }

        printf("\n+---+---+---+---+---+---+---+---+---+");


        printf("\n");

        for(r=0; r<SIZE; r++)
        {
            printf(" %c |", righe[r]);

            for(c=0; c<SIZE; c++)
            {
                if
            }
    }*/

    return 0;
}
