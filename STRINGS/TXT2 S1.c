#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 20

int main()
{

    int L,I;

   char STG[N];

   printf("ingrse nombre\t");
   fflush(stdin);

   gets(STG);

      printf("\n\n");
    printf("%s",STG);

    L=strlen(STG);

    printf("\n\n");

    for(I=L ; I ; I--)

        putchar(STG[I-1]);


         printf("\n\n\n");




}




