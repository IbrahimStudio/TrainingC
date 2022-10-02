#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

void stampa_scacchiera(char*s);        //definisco la funzione stampa_scacchiera: void-> no output; char*s -> il parametro della f e' il puntatore dell'array s
int converti_riga(char*r);
int converti_colonna(char*c);
void stampa_scacchiera1(char*s, int *ri, int *rig, int *co, int *col, char mossa[]);

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
        int *ri=converti_riga(mossa[2]);
        int *rig=converti_riga(mossa[4]);
        int *co=converti_colonna(mossa[1]);
        int *col=converti_colonna(mossa[3]);

        if(mossa[0]==0)
        {
            printf("Sequenza di uscita");
            break;
        }

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
            if(s[r*SIZE+c] != mossa[0])
            {
                printf("Il pezzo non e' in quelle coordinate\n");
                break;
            }
            else if(r==ri && c==co)
            {
                printf("   |");
            }
            else if(r==rig && c==col)
            {
                printf("  %c |", mossa[0]);
            }
            else
            printf(" %c |", s[r*SIZE+c]);
        }
        printf("\n+---+---+---+---+---+---+---+---+---+\n");
    }

        //stampa_scacchiera1(s, ri, rig, co, col, mossa);







    return 0;
}


int converti_riga(char*r)
{
    return r-'1';
}

int converti_colonna(char*c)
{
    return c-'a';
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

void stampa_scacchiera1(char*s, int *ri, int *rig, int *co, int *col, char mossa[])
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
            if(s[r*SIZE+c] != mossa[0])
            {
                printf("Il pezzo non e' in quelle coordinate\n");
                exit("EXIT_SUCCESS");
            }
            else if(r==ri && c==co)
            {
                printf("   |");
            }
            else if(r==rig && c==col)
            {
                printf("  %c |", mossa[0]);
            }
            else
            printf(" %c |", s[r*SIZE+c]);
        }
        printf("\n+---+---+---+---+---+---+---+---+---+\n");
    }
}



/*
void stampa_scacchiera(char *s)
{
    int c, r;

    printf("   ");                  //lascio uno spazio in alto, per motivi grafici
    for(c='a'; c<='h'; c++)         //stampo l'intestazione delle colonne
    {
        printf(" %c ", c);          //uno spazio prima di %c e uno dopo, per motivi grafici
    }

    printf("\n+---+---+---+---+---+---+---+---+---+\n");            //per motivi grafici

    for(r=0; r<SIZE; r++)              //comincio a stampare l'intestazione delle righe
    {
        printf(" %d ", r+1);          //uno spazio prima di %c e uno dopo, per motivi grafici

        for(c=0; c<SIZE; c++)   //inizializzo i, che mi rappresenta le colonne. solo perche' così lavoro con un int e non con un char->più comodo per indice array
        {
            printf(" %c |", s[r*SIZE+c]);       //prima che ogni ciclo for relativo alle righe si chiuda, avvio un ciclo for che essendo nidificato nel precedente legge "dove è arrivato r nella sua crescita (r++)" e combinato con la condizione del for nidificato (c++) va ad identificarmi una casella precisa -> stampo la riga di scacchiera corrispondente

        }
        //esco dal for nidificato, vado a capo e stampo la componente grafica; si chiude il ciclo relativo alla prima riga e comincia di nuovo la stessa cosa per la seconda riga
        printf("\n+---+---+---+---+---+---+---+---+---+\n");    //per motivi grafici

    }
}*/
