//scacchiera 08/11
#include <stdio.h>
#include <stdlib.h>

#define SIZE (8)

void stampa_scacchiera(char *s);
void mossa_pezzo(char *s,char *mossa);
void mosse(char *s);

int main()
{

//inizializzo con array monodimensionale;

char s[SIZE*SIZE]=
    {
    'R','N','B','Q','K','B','N','R',
    'p','p','p','p','p','p','p','p',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    'p','p','p','p','p','p','p','p',
    'r','n','b','q','k','b','n','r'
    };

    char mossa[7];
    stampa_scacchiera(s);
    mossa_pezzo(s,mossa);  //con i vettori non bisogna passare &(l'indirizzo), nei puntatori si.
    printf("\n\n");

    int a;
    printf("Il pedone (p) può muoversi solo in avanti e se è nella casella di partenza e ha il fronte libero può saltare di due caselle ma mangia in diagonale di una casella\n\n");
    printf("inserire '1' per visualizzare mosse possibili del pedone\n");
    scanf("%d",&a);
    if(a==1)
    mosse(s);

}





void stampa_scacchiera(char*s)
{
    //stampo array monodimensionmale
//per effettuare tutti i punti basta sostiuire  s[r][c]   con   s[r*SIZE+c]

 printf("  ");
        for(int i='a';i<='h';i++)
            printf("%c ",i);
        printf("\n");

int r,c;
    for(r=0;r<SIZE;r++)//   r --> riga
        {
             printf("  +-+-+-+-+-+-+-+-\n");
             printf("%d",r+1);
            for(c=0;c<SIZE;c++) // c-->colonna
                {
                printf("|%c",s[r*SIZE+c]);
                }
            printf("|\n");
        }
        printf("  +-+-+-+-+-+-+-+-\n");


}

#include<string.h>

void mossa_pezzo(char *s,char *mossa)
{

// leggo stringa da tastiera
  printf("Inserisci mossa (pezzo,colonna partenza,riga partenza,x (se mangio pezzo),colonna arrivo, riga arrivo: ");
  scanf(" %s", mossa); // attenzione la lettura termina alla prima spaziatura  //metto lo spazio davanti perche altrimenti non legge mossa dopo
  printf("hai inserito la mossa:\n '%s'\n", mossa);

  int r,c;
    if(mossa[0]=='0') //se il pezzo=0 esco dal programma
            exit(EXIT_SUCCESS);

        //devo controllare che il pezzo si trovi in quelle cordinate di partenza
        r=mossa[2]-'1';
        c=mossa[1]-'a';
        if(s[r*8+c]!=mossa[0])
        {
            printf("in %s non c'e' il pezzo %c richiesto\n",mossa);
            exit(EXIT_FAILURE);
        }

        s[r*8+c]=' ';   //tolgo pezzo dalla posizione precedente

        if(strchr(mossa,'x')==NULL) //restituisce NULL se non ce la x
        {
        r=mossa[4]-'1';
        c=mossa[3]-'a';
        if(s[r*8+c]!=' ')
            printf("\n ho mangiato %c \n\n",s[r*8+c]);
        s[r*8+c]=mossa[0];   //metto pezzo nella nuova posizione;
        }

        else   //mossa[pezzo,c_partenza,r_partenza,x,c_arrivo,r_arrivo]
        {
            printf("ho mangiato\n\n");
        r=mossa[5]-'1';
        c=mossa[4]-'a';
        s[r*8+c]=mossa[0];   //metto pezzo nella nuova posizione;
        }

        //faccio vedere scacchiera aggiornata
        stampa_scacchiera(s);

}



void mosse(char *s)
{
    char casella[3];//casella del pedone
    printf("dimmi la casella di un pedone\n");
    scanf(" %s", casella);
    if(s[casella[1]*8+casella[0]]=='p')
    {
    printf("\n\n Il pedone puo fare queste mosse:\n");
    }



    else
    {
        printf("nella casella %s non c'e' alcun pedone\n",casella);
        exit(EXIT_FAILURE);
    }


}
