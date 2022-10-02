#include <stdio.h>
#include <stdlib.h>
#define righe 8
#define colonne 8


int main()
{
    char colonne_scacc[colonne]={'a','b','c','d','e','f','g','h'};
    char righe_scacc[righe]={'1','2','3','4','5','6','7','8'};
    char scacchiera[righe][colonne]=
    {
        {'R','N','B','Q','K','B','N','R'},
        {'P','P','P','P','P','P','P','P'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'p','p','p','p','p','p','p','p'},
        {'r','n','b','q','k','b','n','r'}
    };
    int r,c;
    printf("  ");
    for(c=0; c<colonne; c++)
    {
        printf(" %c  ", colonne_scacc[c]);
    }
    printf("\n");
    for(r=0; r<righe; r++)
    {
        printf("%c", righe_scacc[r]);
        for(c=0; c<colonne; c++)
        {
            printf(" %c |", scacchiera[r][c]);
        }
        printf("\n");
        printf("+---+---+---+---+---+---+---+---+");
        printf("\n");
    }


    while(1)
    {
        int c1, r1, c2, r2;
        char mossa[6];
        printf("Digitare la mossa da eseguire pezzo-partenza-arrivo 'pa1a2': ");
        gets(mossa);
        printf("La mossa e': %s", mossa);
        c1=mossa[1] - 'a';
        r1=mossa[2] - '1';
        c2=mossa[3] - 'a';
        r2=mossa[4] - '1';

        printf("\n");

        if(mossa[0]==0)
        {
            break;
        }
        else
        {
            if(scacchiera[r1][c1]!=mossa[0])
            {
                printf("Il pezzo che vuoi muovere non e' in quelle coordinate");
                break;
            }
            else
            {
            printf("  ");
            for(c=0; c<colonne; c++)
            {
                printf(" %c  ", colonne_scacc[c]);
            }
            printf("\n");
            for(r=0; r<righe; r++)
            {
                printf("%c|", righe_scacc[r]);
                for(c=0; c<colonne; c++)
                {
                    if(r==r1 && c==c1)
                    {
                        printf("   |");
                    }
                    else if(r==r2 && c==c2)
                    {
                        printf(" %c |", mossa[0]);
                    }
                    else
                    {
                        printf(" %c |", scacchiera[r][c]);
                    }
                }
                printf("\n");
                printf("+---+---+---+---+---+---+---+---+");
                printf("\n");
            }

            }
        }
    }
    return 0;
}
