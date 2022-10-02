#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LNOME 4

struct valuta{
    char nome[LNOME];
    float tasso;
    int anno, mese, giorno;
    };

int ordinatasso(const void *a, const void *b);
int ordinadata(const void *a, const void *b);

int main()
{
    ///SCELGO QUALE FILE APRIRE E LO APRO (1)
    char sigla[LNOME];
    printf("Indicare la sigla della valuta che si vuole analizzare: ");
    scanf(" %s", sigla);
    char filename[10];
    strcpy(filename, sigla);
    strcat(filename, ".txt");

    FILE *fp=fopen(filename, "r");
    if(!fp)
    {
        perror("Errore");
        exit(1);
    }

    ///CONTO LE RIGHE (2)
    int righe=0;
    char buffer[1000];
    while(fscanf(fp, " %[^\n]", buffer)==1)
    {
        righe++;
    }

    //printf("\nIl file contiene %d righe", righe); DEBUG

    ///ALLOCO DINAMICAMENTE L'ARRAY DI STRUTTURE (3)
    struct valuta *converti=malloc(righe*sizeof(struct valuta));

    fseek(fp, 0, SEEK_SET);
    int i=0;
    while(fscanf(fp, " %[^,], %f, %d, %d, %d", converti[i].nome, &converti[i].tasso, &converti[i].anno, &converti[i].mese, &converti[i].giorno)==5)
    {
        i++;
    }

/*  //STAMPA DELL'ARRAY DI STRUCT PER DEBUG
    for(int j=0; j<righe; j++)
    {
        printf("%s\t%f\t%d/%d/%d\n",converti[j].nome, converti[j].tasso, converti[j].anno, converti[j].mese, converti[j].giorno );
    }
*/
    fclose(fp);

    ///(4)
    while(1)
    {
        int comando;
        printf("\n\nInserisci il comando: ");
        scanf(" %d", &comando);

        switch(comando)
        {
            case 0:
                printf("\nComando di uscita\n");
                exit(EXIT_SUCCESS);
            case 1:
                {
                    int mm, aa;
                    printf("\nIndicare mese e anno di cui calcolare il tasso medio: ");
                    scanf(" %02d %04d", &mm, &aa);
                    float tassotot=0;
                    float giorni=0;
                    for(int j=0; j<righe; j++)
                    {
                        if(converti[j].anno==aa && converti[j].mese==mm)
                        {
                            tassotot=tassotot + converti[j].tasso;
                            giorni= giorni+1;
                        }

                    }
                    printf("\nIl tasso medio del mese %02d dell'anno %04d e': %f", mm, aa, tassotot/giorni);
                }
                break;
            case 2:
                {
                    char data[8];
                    printf("\nInserire una data nel formato ggmmaaaa: ");
                    scanf(" %s", data);
                    int gg =(data[0]-'0')*10+data[1]-'0';
                    int mm = (data[2]-'0')*10+data[3]-'0';
                    int aaaa = (data[4]-'0')*1000 + (data[5]-'0')*100 + (data[6]-'0')*10 +(data[7]-'0');
                    for(int h=0; h<righe; h++)
                    {
                        if(converti[h].anno==aaaa && converti[h].mese==mm && converti[h].giorno==gg)
                            printf("\nIl tasso di cambio del giorno indicato e': %f", converti[h].tasso);
                    }

                }
                break;
            case 3:
                {
                    printf("\nStampo le prime 10 righe del file:\n");
                    for(int j=0; j< 10; j++)
                    {
                        printf("%s\t%f\t%02d/%02d/%d\n", converti[j].nome, converti[j].tasso, converti[j].giorno, converti[j].mese, converti[j].anno);
                    }
                }
                break;
            case 4:
                {
                    qsort(converti, righe, sizeof(struct valuta), ordinatasso);
                }
                break;
            case 5:
                {
                    qsort(converti, righe, sizeof(struct valuta), ordinadata);
                }
                break;
            case 6:
                {
                    FILE *fout=fopen("out.txt", "w");
                    if(!fout)
                    {
                        perror("Errore");
                        exit(EXIT_FAILURE);
                    }
                    for(int h=0; h<righe; h++)
                    {
                        fprintf(fout, "%s\t%f\t%02d/%02d/%d\n", converti[h].nome, converti[h].tasso, converti[h].giorno, converti[h].mese, converti[h].anno);
                    }
                    fclose(fout);
                }
                break;
            default:
                printf("\nIl comando inserito non è valido\n");
                break;
        }
    }
    return 0;
}


int ordinatasso(const void *a, const void *b)
{
    const struct valuta *pa=a;
    const struct valuta *pb=b;
    if(pa->tasso<pb->tasso)
        return -1;
    else if(pa->tasso>pb->tasso)
        return 1;
    else
        return 0;

}

int ordinadata(const void *a, const void *b)
{
    const struct valuta *pa=a;
    const struct valuta *pb=b;
    int dataa=pa->giorno + (pa->mese)*30 + (pa->anno)*360;
    int datab=pb->giorno + (pb->mese)*30 + (pb->anno)*360;
    return pa-pb;
}

