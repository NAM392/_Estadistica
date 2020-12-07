#include<stdio.h>
int main()

{

int PAR=0;

int IMPAR=0;

int CONT=1;

int VALOR=0;



    while (CONT<=10){
        printf("INGRESE UN VALOR=");
        scanf("%d",&VALOR);

            if(CONT % 2 == 0){PAR + VALOR==PAR;}
            else {IMPAR + VALOR==IMPAR;}

            CONT ++ ;}

            if (PAR>IMPAR)
                printf("LA MAYOR SUMA ES PAR = %d ",PAR);
            else
                printf("LA MAYOR SUMA ES IMPAR = %d ",IMPAR);

            return 0;






             }




