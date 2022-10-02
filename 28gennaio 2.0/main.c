#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct comune{
    char nome[41];
    char sigla[3];
    char regione[4];
    char cap[7];
    unsigned int abitanti;
    };

int ordinapop(const void *a, const void *b);
int ordinanome(const void *a, const void *b);

int main()
{
    FILE *fp=fopen("comuni.csv", "r");
    if(!fp)
    {
        perror("ERRORE");
        exit(1);
    }

    char temp[71];
    int righe;
    while((fscanf(fp, " %[^\n]", temp))!=EOF)
    {
        righe++;
    }

    printf("%d", righe);

    fseek(fp, 0, SEEK_SET);

    struct comune *lista=malloc(righe*sizeof(struct comune));


    int i=0;

    while(fscanf(fp, " %[^\;];%[^\;];%[^\;];%[^\;];%u", lista[i].nome, lista[i].sigla, lista[i].regione, lista[i].cap, &lista[i].abitanti)==5)
    {
        i++;
    }

/*    for(int j=0; j<righe; j++)
    {
        printf("%s; %s; %s; %s; %u\n", lista[j].nome, lista[j].sigla, lista[j].regione, lista[j].cap, lista[j].abitanti);
    }
*/
    fclose(fp);


while(1)
{
    int comando;
    printf("\nInserire il comando: ");
    scanf(" %d", &comando);

    switch(comando)
    {
        case 0:
        {
            printf("\nsequenza di uscita");
            exit("EXIT_SUCCESS");
        }
        case 1:
        {
            char ucap[7];
            printf("\nInserisce un CAP: ");
            scanf(" %s", ucap);
            for(int j=0; j<righe; j++)
            {
                if(strcmp(lista[j].cap, ucap)==0)
                    printf("%s; %s; %s; %s; %u", lista[j].nome, lista[j].sigla, lista[j].regione, lista[j].cap, lista[j].abitanti);
            }
        }
        break;
        case 2:
        {
            char uregione[4];
            printf("\nIndicare una regione su: ");
            scanf(" %s", uregione);
            unsigned int pop_tot=0;
            for(int j=0; j<righe; j++)
            {
                if(strcmp(lista[j].regione, uregione)==0)
                {
                    printf("\n%s\t%u", lista[j].nome, lista[j].abitanti);
                    pop_tot=pop_tot+lista[j].abitanti;
                }
            }
            printf("\n\nGli abitanti totali della regione sono: %u", pop_tot);
        }
        break;
        case 3:
        {
            char usigla[3];
            printf("\nInserisce la sigla di una provincia: ");
            scanf(" %s", usigla);
            for(int j=0; j<righe; j++)
            {
                if(strcmp(lista[j].sigla, usigla)==0)
                    printf("%s; %s; %s; %s; %u", lista[j].nome, lista[j].sigla, lista[j].regione, lista[j].cap, lista[j].abitanti);
            }
        }
        break;
        case 4:
        {
            qsort(lista, righe, sizeof(struct comune), ordinapop);
        }
        break;
        case 5:
        {
            qsort(lista, righe, sizeof(struct comune), ordinanome);
        }
        break;
        case 6:
        {
            FILE *fout=fopen("out.bin", "wb");
            if(!fout)
            {
                perror("ERRORE");
                exit(1);
            }

            fwrite(lista, sizeof(struct comune), righe, fout);
            fclose(fout);
        }
        break;
        default:
            printf("\nComando non valido\n");
            break;

    }

}

    return 0;
}

int ordinapop(const void *a, const void *b)
{
    const struct comune *pa=a;
    const struct comune *pb=b;

    return pa->abitanti -pb->abitanti;

}

int ordinanome(const void *a, const void *b)
{
    const struct comune *pa=a;
    const struct comune *pb=b;

    return (strcmp(pa->nome, pb->nome));
}
