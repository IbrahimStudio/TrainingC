#include <stdio.h>
#include <stdlib.h>
#define righe 8
#define colonne 8
int main()
{


int main()
{
    int c, r;
    //inizializzazione arrays: intestazione colonne/righe e scacchiera stessa
    char righe_scacc[righe]={'1','2','3','4','5','6','7','8'};
    char colonne_scacc[colonne]={'a','b','c','d','e','f','g','h'};
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
//stampa intestazione colonne
    printf(" ");
    for(c=0; c<=7; c++)
    {
        printf("  %c", colonne_scacc[c]);
    }

    printf("\n"); //a capo

//cicli for nidificati: parto stampando il primo elemento dell'array righe,
//avvio il secondo for che stampa gli elementi dell'array scacchiera associati alla riga r in questione
    for(r=0; r<=7; r++)
    {
        printf("+-+-+-+-+-+-+-+-+-+-+-+-+ \n");
        printf("%c|", righe_scacc[r]);

        for(c=0; c<=7; c++)
        {
            printf(" %c|", scacchiera[r][c]);
        }

        printf("\n");
    }

    while(1)
    {
//leggo le istruzioni dell'utente
    char mossa[6];
    int i;
    printf("Inserire la propria mossa nel formato 'pezzo''casella di partenza''casella di arrivo': \t");
    gets(mossa);
    printf("La mossa eseguita e': %s", mossa);

    /*for(i=0; i<=5; i++)
    {
         scanf("%d", &mossa[i]);
    }

    printf("\n");
    */
    for(i=0; i<=5; i++)
    {
        printf("%c", mossa[i]);
    }
    printf("\n");





        //associo una variabile alle coordinate di arrivo e partenza
        int c1, r1, c2, r2;
        c1=mossa[1] - 'a';
        r1=mossa[2] - '1';
        c2=mossa[3] - 'a';
        r2=mossa[4] - '1';

        if(mossa[0]==0)
        {
            exit("EXIT_SUCCESS");
        }
        else
        {
        //stampa intestazione colonne
        printf(" ");
        for(c=0; c<=7; c++)
        {
            printf("  %c", colonne_scacc[c]);
        }

        printf("\n"); //a capo


    //cicli for nidificati: parto stampando il primo elemento dell'array righe,
    //avvio il secondo for che stampa gli elementi dell'array scacchiera associati alla riga r in questione
        for(r=0; r<=7; r++)
        {
            printf("+-+-+-+-+-+-+-+-+-+-+-+-+ \n");
            printf("%c|", righe_scacc[r]);
            for(c=0; c<=7; c++)
        {
                if(r==r2 && c==c2)
                {
                    printf(" %c|", mossa[0]);

                }
                else if(r==r1 && c==c1)
                {
                    printf("  ");
                }
                else
                {
                    printf(" %c|", scacchiera[r][c]);
                }
        }
        printf("\n");
        }
    }

    }
    printf("____________________________");

    return 0;
}

    return 0;
}
