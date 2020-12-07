#include<stdio.h>
#define N 10

int main()
{
    int VEC[N],I;
    int ACUM =0,CONT=0;
    float PROM;

    //ingreso de valores

    for(I=0;I<N;I++)
    {
        printf("\nVEC[%d]=",I);
        scanf("%d",&VEC[I]);

    }

    //calculo del promedio

    for (I=0;I<N;I++)

            ACUM=ACUM+VEC[I];

    PROM=(float)ACUM/N;

    printf("\n\n") ;

    for(I=0;I<N;I++)
        {
            printf("%7d",VEC[I]);
            if(VEC[I]>PROM)
                CONT++;
        };

        printf("\n\n HAY %d VALORES MAYORES QUE %4.2f.",CONT,PROM);
}











