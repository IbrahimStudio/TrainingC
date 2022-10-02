#include <stdlib.h>
#include <stdio.h>
#define DIM 8

int main()
{
    char scacchiera[DIM][DIM] = {{'R','N','B','Q','K','B','N','R'},
                         {'P','P','P','P','P','P','P','P'},
                         {' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' '},
                         {'p','p','p','p','p','p','p','p'},
                         {'r','n','b','q','k','b','n','r'}};

    int riga, colonna;
    char pezzo, r1, c1, r2, c2;
    for(riga=0; riga<DIM;++riga){
        for(colonna=0; colonna<DIM;++colonna){
            printf("| %c", scacchiera[riga][colonna]);
        }
        printf("\n+---+---+---+---+---+---+---+---+\n");
    }

    while(1){
        printf("\nInserisci il pezzo e la mossa: ");
        scanf(" %c%c%c%c%c", &pezzo, &c1, &r1, &c2, &r2);
        scacchiera[r1-'1'][c1-'a']=' ';
        scacchiera[r2-'1'][c2-'a']=pezzo;
        printf("\n");
         for(riga=0; riga<DIM;++riga){
        for(colonna=0; colonna<DIM;++colonna){
            printf("| %c", scacchiera[riga][colonna]);
        }
        printf("\n+---+---+---+---+---+---+---+---+\n");
    }
    }

    return 0;
}
