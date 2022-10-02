/*Il gioco degli scacchi prevede l'uso di due set di pedine. Uno bianco e uno nero, composti da:

8 Pedoni: P/p

2 Torri: R/r

2 Cavalli: N/n

2 Alfieri: B/b

1 Regina: Q/q

1 Re: K/k


Disposti su una scacchiera 8x8.

Convenzionalmente le colonne della scacchiera sono indicate con le lettere da 'a' a 'h' e le righe con i numeri da 1 a 8.

Supponendo di usare come lettere delle pedine quelle indicate con il minuscolo per i bianchi e il maiuscolo per i neri, la configurazione iniziale del giuoco sarebbe:


  a b c d e f g h
 +-+-+-+-+-+-+-+-+
1|R|N|B|Q|K|B|N|R|
 +-+-+-+-+-+-+-+-+
2|P|P|P|P|P|P|P|P|
 +-+-+-+-+-+-+-+-+
3| | | | | | | | |
 +-+-+-+-+-+-+-+-+
4| | | | | | | | |
 +-+-+-+-+-+-+-+-+
5| | | | | | | | |
 +-+-+-+-+-+-+-+-+
6| | | | | | | | |
 +-+-+-+-+-+-+-+-+
7|p|p|p|p|p|p|p|p|
 +-+-+-+-+-+-+-+-+
8|r|n|b|q|k|b|n|r|
 +-+-+-+-+-+-+-+-+


Sviluppare un programma in C che:


1. usi un array bidimensionale per memorizzare una scacchiera e le possibili posizioni dei pezzi.

2. inizializzi tale array con la posizione iniziale come sopra indicata e la stampi.

3. iterativamente:

3a. chieda all'utente 5 caratteri che codificano una mossa. Il primo carattere è la codifica del pezzo spostato, gli altri le coordinate di partenza e arrivo (esempio: Pb2b4)

3b. aggiorni la struttura dati e ristampi la scacchiera

3c. esca dal ciclo se il primo carattere è '0'

4. modificare quanto sviluppato sostituendo all'array bidimensionale un array monodimensionale */

#include <stdio.h>
#include <stdlib.h>
#define SIZE (8)

int main(int argc, char**argv)
{
    //punto 1,2,3a,3b,3c
    char s[SIZE * SIZE]={'R','N','B','Q','K','B','N','R',
                       'p','p','p','p','p','p','p','p',
                       ' ',' ',' ',' ',' ',' ',' ',' ',
                       ' ',' ',' ',' ',' ',' ',' ',' ',
                       ' ',' ',' ',' ',' ',' ',' ',' ',
                       ' ',' ',' ',' ',' ',' ',' ',' ',
                       'p','p','p','p','p','p','p','p',
                       'r','n','b','q','k','b','n','r'};
    //stampo cordinate colonne
    char i;
    printf(" ");
    for(i = 'a'; i <= 'h'; ++i)
        printf(" ");
    printf("/n");

    int r, c;
    for(r=0;r<SIZE;++r)  // ciclo su riga
        {
        printf("+---+---+---+---+---+---+---+---+\n",r);
        printf("%d", r+1);
            for(c=0;c<SIZE;++c) // ciclo su colonna
                {
                printf("| %c", s[r * SIZE + c]);
                }
            printf("| /n");
        }
        printf("+---+---+---+---+---+---+---+---+\n",r);

        while(1){
            char pezzo, c1, r1, c2, r2;
            printf("Inserisci mossa:");
            scanf("%c %c %c %c %c, &pezzo, &c1, &r1, &c2, &r2");

            if(pezzo == '0')
                exit(EXIT_SUCCESS);

            r = r1 - '1';
            c = c1 - 'a';

            if(s[r * SIZE + c] != pezzo){
                printf("In %c %c non c'e' il pezzo %c richiesto\n", c1, r1, pezzo);
                exit(EXIT_FAILURE);
            }
            s[r * SIZE + c] = ' ';
            r = r2 - '1';
            c = c2 - 'a';
            s[r * SIZE + c] = pezzo;
        }
    return 0;
}
