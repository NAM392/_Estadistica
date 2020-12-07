#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define L 4



int main ()
{
    int I;
    char STRG[L][10];
    int edad[L];
    int POSMIN=0;

    for(I=0 ; I<L ; I++)
        {
            fflush(stdin);

            printf("ingrese nombre\t");
            fflush(stdin);
            gets(STRG[I]);

            fflush(stdin);

            printf("ingrese edad\t");
            scanf("%d",&edad[I]);


        }

        for(I=0 ; I<L ; I++)
        {


            if (edad[I]<edad[POSMIN])
                POSMIN=I;




        }

        printf("\n\n\t\t %s \t\t tiene \t\t %d \n\n",STRG[POSMIN],edad[POSMIN]);







}
