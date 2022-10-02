#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int potenza(int a, int b);


int main()
{

    FILE *fp=fopen("telefoni.csv", "r");
    if(!fp)
    {
        perror("Errore");
        exit(1);
    }


    char temp[100];
    int righe=0;

    ///determino il numero di righe per allocare taticamente l'array di strutture
    while((fscanf(fp, " %[^\n]", temp)!= EOF))
    {
        righe++;
    }

    printf("il numero di righe/contatti e': %d\n\n", righe);


    ///inizializzo l'array di strutture
    struct numeri{
    char pal[6];
    char nome[31];
    unsigned int telefono;
    }contatti[righe];


    fseek(fp, 0, SEEK_SET);


    ///alternativo ad fseek
/*   fclose(fp);
    FILE *fp1=fopen("telefoni.csv", "r");
    if(!fp1)
    {
        perror("Errore");
        exit(1);
    }
*/


    int i=0;

    while((fscanf(fp, " %[^,],%[^,],%u", contatti[i].pal, contatti[i].nome, &contatti[i].telefono))==3)
    {
        i++;
    }


    for(int j=0; j<righe; j++)
    {
        printf("%s , %s , %u\n", contatti[j].pal, contatti[j].nome, contatti[j].telefono);
    }


    /// punto 3

    char tempo[31];
    printf("\n\nInserire una stringa: ");
    scanf("%s", tempo);


    if((isdigit(tempo[0]))!=0)
    {

         ///metodo bazza
        int numero=atoi(tempo);

        for(int h=0; h<righe; h++)
        {
            if(numero==contatti[h].telefono)
            {
                printf("%s , %s", contatti[h].pal, contatti[h].nome);
            }
        }



        ///tentativo inutile e pietoso
/*

        for(int h=0; h<c; h++)
        {
            temp_num[h]=tempo[h]-'1'+1;
           // printf("%d", temp_num[h]);    DEBUG
        }

 */

        ///converto la stringa numerica in numero unsigned
/*
        unsigned int num=0;
        for(int h=0; h<c; h++)
        {
            num = num + (temp_num[h]*(10^(c-h-1)));

        printf("%u", num);

*/



    }
    else if((islower(tempo[0]))!=0)
    {
        for(int h=0; h<righe; h++)
        {
            if(tempo==contatti[h].pal)
            {
                printf("%s %u", contatti[h].nome, contatti[h].telefono);
            }
        }
    }
      else if((islower(tempo[0]))==0)
    {
        for(int h=0; h<righe; h++)
        {
            if(tempo==contatti[h].nome)
            {
                printf("%s %s ", contatti[h].pal, contatti[h].telefono);
            }
        }
    }


    return 0;
}



