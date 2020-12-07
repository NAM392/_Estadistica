#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20

int main()
{
    int I,L;
    char STRG[N];
    printf("ingrese palabra\t");
    gets(STRG);

    L=strlen(STRG);

    printf("\n\n");
    puts(STRG);

    for(I=0 ; I<L ; I++)

       putchar(STRG[I]=STRG[I]+3);









}
