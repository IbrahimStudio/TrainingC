 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 struct valuta{
    char nome[4];
    float tasso;
    int aa, mm, gg;
    };

int ordinatasso(const void *a, const void *b);
int ordinadata(const void *a, const void *b);

int main()
{
    char code[4];
    printf("Scegliere la valuta (code): ");
    scanf(" %s", code);
    printf("La valuta che si vuole confrontare con l'EUR e': %s", code);
    char filename[10];
    strcpy(filename, code);
    strcat(filename,".txt");
    printf("\n%s", filename);
    FILE *fp=fopen(filename, "r");
    if(!fp)
    {
        perror("ERRORE");
        exit(1);
    }
    int righe=0;
    char buffer[100];
    while((fscanf(fp, " %[^\n]", buffer))==1)
    {
        righe++;
    }
    printf("\nIl numero di righe e': %d", righe);

    ///codice prof
/*     // ALLOCO ARRAY
   struct valuta *tassi=malloc(righe*sizeof(struct valuta));
   if(!tassi)
   {
     perror("malloc");
     exit(EXIT_FAILURE);
   }

   // RILEGGO FILE RIEMPENDO ARRAY
   fseek(fp, 0, SEEK_SET); // riparto dall'inizio del file
   int riga=0;
   while(fscanf(fp,"  %[^,],%f,%d,%d,%d", tassi[riga].nome, &tassi[riga].tasso, &tassi[riga].aa, &tassi[riga].mm, &tassi[riga].gg)==5)
   {
       printf("Ho letto %s\t%f\t%d/%02d/%04d\n", tassi[riga].nome, tassi[riga].tasso, tassi[riga].gg, tassi[riga].mm, tassi[riga].aa);
      //printf("Ho letto %s\t%f\t%02d/%02d/%04d\n", tassi[riga].nome, tassi[riga].tasso, tassi[riga].gg, tassi[riga].mm tassi[riga].aa);
     // debug
     riga++;
   }
   fclose(fp);

*/

    struct valuta *tassi=malloc(righe*sizeof(struct valuta));
    if(!tassi)
    {
        printf("malloc");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_SET);
    int riga=0;

    while((fscanf(fp," %[^,],%f,%d,%d,%d", tassi[riga].nome, &tassi[riga].tasso, &tassi[riga].aa, &tassi[riga].mm, &tassi[riga].gg))==5)
    {
        //printf("%s\t%f\t%d\t%d\t%d\n", tassi[riga].nome, tassi[riga].tasso, tassi[riga].aa, tassi[riga].mm, tassi[riga].gg);
        riga++;
    }

    while(1)
    {
        int caso;
        printf("\n\nInserire comando:");
        scanf("%d", &caso);
        switch(caso)
        {
        case 0:
                printf("Sequenza di uscita");
                exit("EXIT_SUCCESS");
        case 1:
            {
                int anno, mese;
                float tasso_m;
                int giorni=0;

                printf("\nInserire un anno:");
                scanf(" %d", &anno);
                printf("\nInserire un mese:");
                scanf(" %d", &mese);
                for(int i=0; i<righe; i++)
                {
                    if(mese==tassi[i].mm && anno==tassi[i].aa)
                    {
                        tasso_m= tasso_m + tassi[i].tasso;
                        giorni++;
                    }
                }
                if(giorni)
                {
                    printf("\nIl tasso di cambio medio nel mese di %02d/%04d e': %f\n", mese, anno, tasso_m/giorni);
                }
                else
                    printf("\nNon e' stato possibile calcolare il tasso medio di cambio\n");

            }
            break;
        case 2:
            {
                char datasel[8];
                printf("Inserire una data nel formato ggmmaaaa: ");
                scanf("%s", datasel);
                int ggsel= (datasel[0]-'0')*10+(datasel[1]-'0');
                int mmsel= (datasel[2]-'0')*10+(datasel[3]-'0');
                int aasel= (datasel[4]-'0')*1000+(datasel[5]-'0')*100+(datasel[6]-'0')*10+(datasel[7]-'0');
                float tassosel=0;
                printf("Il tasso di cambio del giorno %02d/%02d/%04d e':", ggsel, mmsel, aasel);
                for(int i=0; i<righe; i++)
                {
                    if(tassi[i].aa==aasel && tassi[i].mm==mmsel && tassi[i].gg==ggsel)
                    {
                        tassosel=tassi[i].tasso;
                    }
                }
                if(tassosel!=0)
                {
                    printf(" %f", tassosel);
                }
                else
                    printf("\nAlla data inserita non corrisponde alcun tasso di cambio.");

            }
            break;
        case 3:
            {
                printf("Stampo i primi 10 valori dell'array:\n");
                for(int i=0; i<10; i++)
                {
                    printf(" %s\t%f\t%02d/%02d%04d\n", tassi[i].nome, tassi[i].tasso, tassi[i].gg, tassi[i].mm, tassi[i].aa);
                }
            }
            break;
        case 4:
            {
                qsort(tassi, righe, sizeof(struct valuta), ordinatasso);
            }
            break;
        case 5:
            {
                qsort(tassi, righe, sizeof(struct valuta), ordinadata);
            }
            break;
        case 6:
            printf("Stampo secondo il nuovo ordine in nuovo file");
            fp=fopen("out.bin", "wb");
            if(!fp)
            {
                perror("ERRORE");
                exit(1);
            }
            fwrite(tassi, sizeof(struct valuta), righe, fp);
            fclose(fp);
            break;
        default:
            printf("\nIl codice comando inserito e' errato");


        }
    }


    fclose(fp);

    return 0;
}

int ordinatasso(const void *a, const void *b)
{
    const struct valuta *pa=a;
    const struct valuta *pb=b;

    if(pa->tasso > pb->tasso)
        return 1;
    else if(pa->tasso < pb->tasso)
        return -1;
    else
        return 0;
}

int ordinadata(const void *a, const void *b)
{
    const struct valuta *pa=a;
    const struct valuta *pb=b;

    int dataa=pa->gg + (pa->mm)*30 + (pa->aa)*360;
    int datab=pb->gg + (pb->mm)*30 + (pb->aa)*360;

    return dataa-datab;
}
