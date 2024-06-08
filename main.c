#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "main.h"
#include "realizacija.c"
const int SP = 6;
const int lengvas = 5, vidutinis = 6, sunkus = 7;
int main()
{
char vardas[13];
FILE *lyderiai = NULL;
FILE *info = NULL;
char infoo;
char skaito;
printf("\n");
printf("Iveskite savo varda (max 12 simboliu)\n");
fgets(vardas, sizeof(vardas), stdin);
printf("\n");
size_t len = strlen(vardas);
    if (len > 0 && vardas[len - 1] == '\n') {
        vardas[len - 1] = '\0';
    }
printf("Sveiki, %s, tai zaidimas ZODLE\n", vardas);
printf("\n");
lyderiai = fopen("Lyderiai.txt", "r");
if (lyderiai == NULL)
{
printf("+--------------------Nepavyko atvaizduoti anksciau zaidusiu zaideju--------------------+\n");
}
else
{
    while ((skaito = fgetc(lyderiai)) != EOF)
{
        printf("%c", skaito);
}
}
fclose(lyderiai);

printf("+--------------------------------------------------------------------------------------+\n");

info = fopen("Info.txt", "r");
if (info == NULL)
{
printf("+--------------------Nepavyko atvaizduoti zaidimo taisykliu----------------------------+\n");
}
else
{
    while ((infoo = fgetc(info)) != EOF)
{
        printf("%c", infoo);
}
}
fclose(info);

realizacija(vardas, lyderiai, info, infoo, skaito);
}