#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studente{
    char mat[11];
    char nome[64];
    char cognome[64];
    int nesami;
    char voti[73];
    };

int leggi_studente(FILE *fp, struct studente *dest);
int compara_studenti(const struct studente *a, const struct studente *b);
struct studente *leggi_file(const char *filename, int *n);

int main()
{
    FILE *fp=fopen("elenco.txt", "r");
    if(!fp)
    {
        perror("ERRORE");
        exit(1);
    }
///conto le righe per conoscere il file e poi allocare dinamicamente
    int righe=0;
    char contarighe[1000];
    while(fscanf(fp, " %[^\n]", contarighe)==1)
    {
        righe++;
    }

    printf("Il file elenco.txt contiene %d righe\n", righe);

///alloco fin da subito dinamicamente la struttura
    struct studente *dest=malloc(righe*sizeof(struct studente));
    //struct studente dest;
///torno all'inizio del file
    fseek(fp, 0, SEEK_SET);
///utilizzo la funzione per leggere una riga del file e stampo se e' avvenuta con successo
    int a=leggi_studente(fp, dest);
    if(a==0)
        printf("\nLettura avvenuta con successo");            ///provare ad usare a=0 \n while(a==0){a=leggi_studente}
    else
        printf("Lettura fallita");

///punto 3
    fseek(fp, 0, SEEK_SET); //torno all'inizio del file
    int i=0;
    while(fscanf(fp, " %s %s %s %d %[^\n]", dest[i].mat, dest[i].nome, dest[i].cognome, &dest[i].nesami, dest[i].voti)==5)
    {
        i++;
    }

    fclose(fp);

    int x, y;
    printf("\n\nNumeri delle righe della lista di cui confrontare le matricole: ");
    scanf(" %d %d", &x, &y);

    int b=compara_studenti(&dest[x], &dest[y]);
    if(b==0)
        printf("\nStesso studente\n");
    else
        printf("\nNon e' lo stesso studente\n");

///punto 4
    char filename[13];
    char nomefile[10];
    printf("\nInserire nome file: ");
    scanf(" %s", nomefile);
    strcpy(filename, nomefile);
    strcat(filename, ".txt");
    printf("%s", filename);


    leggi_file;


    return 0;
}

int leggi_studente(FILE *fp, struct studente *dest)
{
    int i;  ///siccome non mi viene detto quale elemento leggere della lista inizializzo a caso
    if(fscanf(fp, " %s %s %s %d %[^\n]", dest[i].mat, dest[i].nome, dest[i].cognome, &dest[i].nesami, dest[i].voti)==5)
        return 0;
    else
        return 1;
}

int compara_studenti(const struct studente *a, const struct studente *b)
{
    if(strcmp(a->mat, b->mat)==0)
        return 0;
    else
        return 1;
}

struct studente *filename(const char *filename, int *n)
{
    FILE *ff=fopen(filename, "r");
    if(!ff)
    {
        perror("ERRORE");
        exit(1);
    }
    struct elenco1{
        char mat[11];
        char nome[64];
        char cognome[64];
        int nesami;
        char voti[73];
        };
    struct elenco1 *lista=malloc(&n*sizeof(struct elenco1));

    while(fscanf(fp, " %s %s %s %d %[^\n]", dest[i].mat, dest[i].nome, dest[i].cognome, &dest[i].nesami, dest[i].voti)==5)
    {
        i++;
    }


    return lista;
}
