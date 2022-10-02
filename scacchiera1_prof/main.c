#include <stdio.h>
#include <stdlib.h>
#define SIZE (8)
int main()
{
    int r,c;
    char  s[SIZE][SIZE]={{'R','N','B','Q','K','B','N','R'},
                         {'P','P','P','P','P','P','P','P'},
                         {' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' '},
                         {'p','p','p','p','p','p','p','p'},
                         {'r','n','b','q','k','b','n','r'}};
    char i;
    printf(" ");
    for(i='a';i<='h';++i)
    {
        printf(" %c| ",i);
    }
    printf("\n");
    for(r=0;r<SIZE;++r)
    {
        printf(" +---+---+---+---+---+---+---+---+ \n");
        printf("%d",r+1);
        for(c=0;c<SIZE;++c)
        {
            printf("| %c ",s[r][c]);
        }
        printf("|\n");
    }
    printf(" +---+---+---+---+---+---+---+---+ \n");

    while(1)
    {
        char pezzo,c1,r1,c2,r2;
        printf("inserisci mossa: ");
        scanf(" %c%c%c%c%c",&pezzo,&c1,&r1,&c2,&r2);
        if(pezzo=='0')
        {
            exit(EXIT_SUCCESS);
        }
        r=r1-'1';
        c=c1-'a';
        if(s[r][c]!=pezzo)
        {
            printf("in %c%c non c'e' il pezzo %c richiesto \n",c1,r1,pezzo);
            exit(EXIT_FAILURE);
        }

        s[r][c]=' ';
        r=r2-'1';
        c=c2-'a';
        s[r][c]=pezzo;
        printf("  ");
        for(i='a';i<='h';++i)
        {
            printf(" %c  ",i);
        }
        printf("\n");
        for(r=0;r<SIZE;++r)
        {
            printf(" +---+---+---+---+---+---+---+---+ \n");
            printf("%d",r+1);
            for(c=0;c<SIZE;++c)
            {
                printf("| %c ",s[r][c]);
            }
            printf("|\n");
        }
        printf(" +---+---+---+---+---+---+---+---+ \n");
    }
    return 0;
}
