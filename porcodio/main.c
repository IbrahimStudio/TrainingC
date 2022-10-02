#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

void stampa_scacchiera(char*s);        //definisco la funzione stampa_scacchiera: void-> no output; char*s -> il parametro della f e' il puntatore dell'array s
int converti_riga(char*r);
int converti_colonna(char*c);
void f_mossa(char *s, char *mossa);

int main()
{
    int a, b;
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

    while(1)
    {
        char mossa[6];
        printf("Inserire coordinate 'pezzo-c.part.-r.part.-c.arr.-r.arr.' : \n");
        gets(mossa);
        printf("La mossa indicata e': %s");
        f_mossa(s, mossa);

        if(mossa[0]==0)
        {
            printf("Sequenza di uscita");
            break;
        }




    return 0;
}



void stampa_scacchiera(char*s)
{
    int c, r;
    printf("    ");
    for(c='a'; c<='h'; c++)
    {
        printf("  %c ", c);
    }
    printf("\n+---+---+---+---+---+---+---+---+---+\n");
    for(r=0; r<SIZE; r++)
    {
        printf("  %d |", r+1);
        for(c=0; c<SIZE; c++)
        {
            printf(" %c |", s[r*SIZE+c]);
        }
        printf("\n+---+---+---+---+---+---+---+---+---+\n");
    }
}



void f_mossa(char *s, char *mossa)
{
    int r1 = mossa[2]-'1';
    int c1 = mossa[1]-'a';
    int r2 = mossa[4]-'1';
    int c2 = mossa[3]-'a';
    do
    {
        int c, r;
        printf("    ");
        for(c='a'; c<='h'; c++)
        {
            printf("  %c ", c);
        }
        printf("\n+---+---+---+---+---+---+---+---+---+\n");
        for(r=0; r<SIZE; r++)
        {
            printf("  %d |", r+1);
            for(c=0; c<SIZE; c++)
            {
                if(r==r1 && c==c1)
                {
                    printf("    ");
                }
                else if(r==r2 && c==c2)
                {
                    printf("  %c |", mossa[0]);
                }
                else
                {
                    printf(" %c |", s[r*SIZE+c]);
                }
            }
            printf("\n+---+---+---+---+---+---+---+---+---+\n");
        }
    }
    while(mossa[0] != 0);

}
