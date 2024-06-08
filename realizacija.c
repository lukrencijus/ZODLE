#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
int realizacija(char vardas[13], FILE *lyderiai, FILE *info, char infoo, char skaito)
{
FILE *duom = NULL;
int sunk, n, tesimas = 1;
char mas[11];
int kiekis = 0;
int taskai = 0;
struct spejimai *spej;
struct zodziai *zod;
int GeraVieta, BlogaVieta;
char TinkamaVietaGeraRaide[8];
char NetinkamaVietaGeraRaide[8];

scanf("%d", &sunk);
printf("\n");
duom = failatid(sunk);
printf("\e[1;1H\e[2J");
if(duom == NULL)
{
    printf("Ivestas perdidelis kiekis simboliu, neteisingai pasirinktas lygis arba nerastas failas \nIseinama is zaidimo");
    return 0;
}
n = faildyd(duom);
zod = zd_atmintis(n, sunk, zod);
if(zod == NULL)
{
    printf("Nepavyksta skirti atminties \nIseinama is zaidimo");
    return 0;
}
pakrauna(duom, zod, n);
fclose(duom);
spej = sp_atmintis(sunk, spej);
if(spej == NULL)
{ 
printf("Nepavyksta skirti atminties \nIseinama is zaidimo");
return 0;
}        
            printf("+--------------------+\n");
            printf("|Pradedamas zaidimas!|\n");
            printf("+--------------------+\n");
printf("\n");
for(int i = 0; i < n; i++)
{
    spej = sp_atmintis(sunk, spej);
    if(spej == NULL)
    { 
        printf("Nepavyksta skirti atminties \nIseinama is zaidimo");
        return 0;
    }
    spejimu_rasymas(spej, sunk, SP);
    printf("Iveskite zodi\n");

    for(int j = 0; j < SP;)
    {
        scanf("%s", mas);
        printf("\n");
        printf("\n");
        if (strcmp(mas, "iseiti") == 0) 
        {
        goto iseiti;
        sp_memfree(spej, SP);    
        free(spej);
        }
        if(patikra(mas, sunk) == 0)
        {
            strcpy(spej[j].spej, mas);
        printf("\n");
        printf("|||||||||||||||||||\n");
        printf("%s\n", spej[0].spej);
        printf("%s\n", spej[1].spej);
        printf("%s\n", spej[2].spej);
        printf("%s\n", spej[3].spej);
        printf("%s\n", spej[4].spej);
        printf("%s\n", spej[5].spej);
        printf("|||||||||||||||||||\n");
                TikrintiZodzius(mas, zod[i].zod, sunk, &GeraVieta, &BlogaVieta, TinkamaVietaGeraRaide, NetinkamaVietaGeraRaide);
                printf("Tinkamos raides GEROSE vietose: %d - ", GeraVieta);
                for (int k = 0; k < GeraVieta; k++) {
                    printf("%c ", TinkamaVietaGeraRaide[k]);
                }
                printf("\n");

                printf("Tinkamos raides BLOGOSE vietose: %d - ", BlogaVieta);
                for (int k = 0; k < BlogaVieta; k++) {
                    printf("%c ", NetinkamaVietaGeraRaide[k]);
                }
                printf("\n");

        if(strcmp(mas, zod[i].zod) == 0)
        {
            taskai = tasksk(j, sunk, taskai);


            kiekis++;
            printf("\n");
            printf("+---------------+\n");
            printf("|Zodis atspetas!|\n");
            printf("+---------------+\n");
            printf("\n");
            break;
        }
       if(patikra(mas, sunk) == 0) 
       j++;
       } else {
         printf("Ivestas neleistinas zodis, bandykite vel\n");
            }
    }
    sp_memfree(spej, SP);    
    free(spej);
    printf("Zodis buvo: %s \n", zod[i].zod);
    printf("Visi jusu pelnyti taskai: %d\n", taskai);
    printf("Jeigu norite testi zaidima iveskite [1]\n");
    printf("Jeigu norite irasyti savo taskus i lentele ir iseiti iveskite [0]\n");
    tesimas = 0;
    scanf("%d", &tesimas);
    printf("\e[1;1H\e[2J");
    printf("\n");
    if(tesimas != 1)
    {
        iseiti:  
        lyderiai = NULL;
        lyderiai = fopen("Lyderiai.txt", "a");
        if (lyderiai == NULL)
        {
        printf("Nepavyko issaugoji Jusu progreso\n");
        }
        else
        {
        char *sunkumas;
        if(sunk == 1) sunkumas = "Lengvas";
        else if (sunk == 2) sunkumas = "Vidutinis";
        else sunkumas = "Sunkus";
        vardas[strcspn(vardas, "\n")] = 0;
        fprintf(lyderiai, "| %-12s |    %-13s     |     %-14d    |     %-15d    |\n", vardas, sunkumas, kiekis, taskai);
        printf("\e[1;1H\e[2J");
        printf("+---------------+\n");
        printf("|Iki kito karto!|\n");
        printf("+---------------+\n");
        printf("\n");
        fclose(lyderiai);
        fclose(info);
        }
        break;
    }
}
zd_memfree(zod, n);
free(zod);
return 0;
}