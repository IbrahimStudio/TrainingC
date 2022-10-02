#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 8

void stampa_scacchiera(char *s);
void mossa_f(char *s);
void converti_coord(char mossa_c[], char mossa_r[]);

int main()
{
    char s[SIZE*SIZE]={
    'R','N','B','Q','K','B','N','R',
    'p','p','p','p','p','p','p','p',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    'p','p','p','p','p','p','p','p',
    'r','n','b','q','k','b','n','r'
    };

    stampa_scacchiera(s);
    mossa_f(s);

 //   while(1)
   // {
        char mossa[7];
        printf("\nDigita la mossa pezzo-partenza-x'stai mangiando'-arrivo: ");
        gets(mossa);
        printf("La mossa inserita e': %s");
        int x;
        x=strchr(mossa, 'x');
        converti_coord(mossa[2], mossa[1]);
        if(!x)
        {
            converti_coord(mossa[4], mossa[3]);
        }
        else
        {
            converti_coord(mossa[5], mossa[4]);
        }

      printf("%d %d", mossa_c, mossa_r);
   // }


    return 0;
}

void converti_coord(char mossa_c[], char mossa_r[])
{
    *r1=mossa_r[]-'1';
    *c1=mossa_c[]-'a';
}

void stampa_scacchiera(char*s)
{
    printf("    ");
    for(int i='a'; i<='h'; i++)
    {
        printf("  %c ", i);
    }

    int r, c;
    for(r=0; r<8; r++)
    {
        printf("\n+---+---+---+---+---+---+---+---+---+\n");
        printf("  %d |", r+1 );

        for(c=0; c<SIZE; c++)
        {
            printf(" %c |", s[r*SIZE+c]);
        }
    }
}

void mossa_f(char*s)
{
    char mossa[6];
    printf("\nDigitare la propria mossa in forma pezzo-partenza-arrivo 'pa7a5': ");
    gets(mossa);
    printf("La mossa e': %s", mossa);
    int c1, r1, c2, r2, co_p, co_a;
    c1=mossa[1] - 'a';
    r1=mossa[2] - '1';
    c2=mossa[3] - 'a';
    r2=mossa[4] - '1';
    co_p=r1*SIZE+c1;
    co_a=r2*SIZE+c2;

    if(s[r1*SIZE+c1]!= mossa[0])
    {
        printf("Il pezzo non occupa quella posizione");
        exit("EXIT_FAILURE");
    }
    else
    {
        printf("  ");
        for(int c='a'; c<='h'; c++)
        {
            printf("%c", c);
        }
        printf("\n+---+---+---+---+---+---+---+---+---+\n");
        for(int r=0; r<SIZE; r++)
        {
            printf("%c", r);
            for(int c=0; c<SIZE; c++)
            {
                if(s[r*SIZE+c] == s[r1*SIZE+c1])
                {
                    printf("   |");
                }
                else if(s[r*SIZE+c]==s[r2*SIZE+c2])     //??? se in questo if metto delle condizioni ulteriori: se mossa[0]=minusc e s[r*SIZE+c]= maiusc -> mangia; poi condizione inversa???
                {
                    printf(" %c |", mossa[0]);
                }
            }
        }
    stampa_scacchiera(s);
    }

}



