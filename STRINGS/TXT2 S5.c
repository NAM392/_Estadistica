#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 4
#define ABC 25
#define T 20

int main()
{

    int cont=0;
    int cont2=0;

    int I,J,SLEN;
    char PALABRA[N][T];
     //    AUX[ABC];
    char M;


    /*for(I=0 ; I<ABC ; I++)
        int AUX[I]=0;
     */


  for(I=0 ; I<N ; I++)
    {
        printf("ingrese palabra  ");
        gets(PALABRA[I]);

    }





    for(I=0 ; I<N ; I++)
        for(J=0 ; J<T ; J++)
           for(M=65; M<91; M++)
            if( !strcmp(M,PALABRA[I][J]))

                cont ++;




                printf("%d",cont);




}

