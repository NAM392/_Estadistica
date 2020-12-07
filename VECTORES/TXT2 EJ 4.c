#include<stdio.h>
#include<stdlib.h>
#define N 10
void CARGA(float [] , int[] , int);

void ORDENAR(float [] , int[] , int);

void MIRAR(float [] , int[] , int);

int main()
{

    float SUELDO[N];
    int LEGAJO[N];

    CARGA(SUELDO,LEGAJO,N);
    ORDENAR(SUELDO,LEGAJO,N);
    MIRAR(SUELDO,LEGAJO,N);



}
void CARGA(float SUELDO[], int LEGAJO[] , int L)
{
    int I;

    for(I=0 ; I<L ; I++)
    {

        LEGAJO[I]=rand()%4444+1222;

        SUELDO[I]=rand()%10000+133;

    }
}

void ORDENAR(float SUELDO[], int LEGAJO[] , int L)
    {
        int AUX_LEGAJO,I,J;
        float AUX_SUELDO;



    for(I=0 ; I<L-1 ; I++)
        for(J=0 ; J<L-I-1 ; J++)
             if(SUELDO[J] < SUELDO[J+1])
             {



                    //swapping//

                    AUX_SUELDO = SUELDO [J];
                    SUELDO[J] = SUELDO[J+1];
                    SUELDO[J+1]=AUX_SUELDO;

                    //swapping//

                    AUX_LEGAJO = LEGAJO [J];
                    LEGAJO[J] = LEGAJO[J+1];
                    LEGAJO[J+1]=AUX_LEGAJO;

                }




}



void MIRAR(float SUELDO[], int LEGAJO[] , int L)
{
    int I;


    for(I=0 ; I<L ; I++)
    {
        if(SUELDO[I]>5000)
            printf("\n\n SUELDOS 5K \t\t%.2f\t\t LEGAJO %d\n\n",SUELDO[I],LEGAJO[I]);
    }






}



