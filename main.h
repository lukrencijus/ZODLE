#ifndef HEADERIS
#define HEADERIS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
extern const int SP;
extern const int lengvas, vidutinis, sunkus;
struct zodziai
{
    char *zod;
};

struct spejimai
{
    char *spej;
};

void TikrintiZodzius(char *SpetasZodis, char *TikrasisZodis, int sunk, int *GeraVieta, int *BlogaVieta, char *TinkamaVietaGeraRaide, char *NetinkamaVietaGeraRaide)
{
    *GeraVieta = 0;
    *BlogaVieta = 0;
    if(sunk == 1) sunk = lengvas;
    else if (sunk == 2) sunk = vidutinis;
    else sunk = sunkus;
    
    for (int i = 0; i < sunk; i++) 
    {
        if (SpetasZodis[i] == TikrasisZodis[i])
        {
            (*GeraVieta)++;
            TinkamaVietaGeraRaide[*GeraVieta - 1] = SpetasZodis[i];
        }
         else
        {
             for (int j = 0; j < sunk; j++) 
            {
                if (SpetasZodis[i] == TikrasisZodis[j]) 
                {
                    (*BlogaVieta)++;
                    NetinkamaVietaGeraRaide[*BlogaVieta - 1] = SpetasZodis[i];
                    break;
                }
            }
        } 
    }
}

int patikra(char mas[], int sunk)
{
    int kiek = 0;
    if(sunk == 1) sunk = 6;
    else if(sunk == 2) sunk = 7;
    else sunk = 8;
    if(strlen(mas) == sunk-1)
    {
        for(int i = 0; i < strlen(mas); i++)
        {
            if(isalpha(mas[i]) && isupper(mas[i])) kiek++;
            else return 1;
        }
    }
    else return 1;
    return 0;
}
FILE* failatid(int sunk)
{
    FILE* duom;
    if(sunk == 1) duom = fopen("Lengvas.txt", "r");
    else if(sunk == 2) duom = fopen("Vidutinis.txt", "r");
    else if(sunk == 3) duom = fopen("Sunkus.txt", "r");
    else duom = NULL;
    return duom;
}
int faildyd(FILE *duom)
{   
    char a[20];
    int n = 0;
    while(fgets(a, 20, duom) != NULL)
    {
        n++;
    }
    rewind(duom);
    return n;
}
int tasksk(int j, int sunk, int taskai)
{
    if(j == 0 && sunk == 1) taskai = taskai + 100;
    if(j == 1 && sunk == 1) taskai = taskai + 80;
    if(j == 2 && sunk == 1) taskai = taskai + 60;
    if(j == 3 && sunk == 1) taskai = taskai + 40;
    if(j == 4 && sunk == 1) taskai = taskai + 20;
    if(j == 5 && sunk == 1) taskai = taskai + 5;

    if(j == 0 && sunk == 2) taskai = taskai + 200;
    if(j == 1 && sunk == 2) taskai = taskai + 160;
    if(j == 2 && sunk == 2) taskai = taskai + 120;
    if(j == 3 && sunk == 2) taskai = taskai + 80;
    if(j == 4 && sunk == 2) taskai = taskai + 40;
    if(j == 5 && sunk == 2) taskai = taskai + 10;

    if(j == 0 && sunk == 3) taskai = taskai + 300;
    if(j == 1 && sunk == 3) taskai = taskai + 240;
    if(j == 2 && sunk == 3) taskai = taskai + 180;
    if(j == 3 && sunk == 3) taskai = taskai + 120;
    if(j == 4 && sunk == 3) taskai = taskai + 60;
    if(j == 5 && sunk == 3) taskai = taskai + 15;
    return taskai;
}
struct zodziai* zd_atmintis(int n, int sunk, struct zodziai *zod)
{
    if(sunk == 1) sunk = 6;
    else if(sunk == 2) sunk = 7;
    else sunk = 8;
    zod = (struct zodziai*) calloc(n, sizeof(struct zodziai));
    if(zod == NULL) return NULL;
    for(int i = 0; i < n; i++)
    {
        zod[i].zod = (char*)calloc(sunk, sizeof(char));
        if(zod[i].zod == NULL)
        {
            for(int j = 0; j < n; j++)
            free(zod[j].zod);
            free(zod);
            return NULL;
        }
    }
    return zod;
}
struct spejimai* sp_atmintis(int sunk, struct spejimai *spej)
{
    if(sunk == 1) sunk = 6;
    else if(sunk == 2) sunk = 7;
    else sunk = 8;
    spej = (struct spejimai*) calloc(SP, sizeof(struct spejimai));
    if(spej == NULL) 
    {
        return NULL;
    }
    for(int i = 0; i < SP; i++)
    {
        spej[i].spej = (char*)calloc(sunk, sizeof(char));
        if(spej[i].spej == NULL)
        {
            for(int j = 0; j < SP; j++)
            free(spej[j].spej);
            free(spej);
            return NULL;
        }
    }
    return spej;
}
 void spejimu_rasymas(struct spejimai *spej, int sunk, int SP)
 {
    char *lengvas = {"-----"};
    char *vidutinis = {"------"};
    char *sunkus = {"-------"};
    if(sunk == 1)
    for(int i = 0; i < SP; i++)
    strcpy(spej[i].spej, lengvas);
    if(sunk == 2)
    for(int i = 0; i < SP; i++)
    strcpy(spej[i].spej, vidutinis);
    if(sunk == 3)
    for(int i = 0; i < SP; i++)
    strcpy(spej[i].spej, sunkus);
 }
 void zd_memfree(struct zodziai *zod, int n)
{
    for(int i = 0; i < n; i++)
    {
    free(zod[i].zod);
    }
}
void sp_memfree(struct spejimai *spej, int n)
{
    for(int i = 0; i < n; i++)
    {
    free(spej[i].spej);
    }
}
void pakrauna(FILE *duom, struct zodziai *zod, int n)
{
    for(int i = 0; i < n; i++)
    {
        fscanf(duom, "%s", zod[i].zod);
    }
    
}
#endif