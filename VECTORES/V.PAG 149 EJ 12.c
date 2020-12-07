#include<stdio.h>
#include<stdlib.h>
#define N 8

void CARGA(int [] , int [] , int);

void ORDEN (int [] , int [] , int);

void PLAYOFFS(int [] , int [] , int);

void MIRA (int [] , int [] , int);

int main()
{

    int CODIGO_EQUIPO[N];
    int PUNTOS[N];

    CARGA(CODIGO_EQUIPO , PUNTOS , N);

    ORDEN(CODIGO_EQUIPO , PUNTOS , N);

    MIRA(CODIGO_EQUIPO , PUNTOS , N);

    PLAYOFFS(CODIGO_EQUIPO , PUNTOS , N);





}

void CARGA(int EQUIPO[] , int  PUNTOS[] , int L)
{

        int I;

        for(I=0 ; I<L ; I++)
            {
                EQUIPO[I]= rand()%999+111;

            }


        for(I=0 ; I<L ; I++)
            {

                PUNTOS[I]=rand()%100+33;


            }







}

void ORDEN(int EQUIPO[] , int  PUNTOS[] , int L)
{

   int AUXEQ,AUXPUN,J,I;

    for(I=0 ; I<L-1 ; I++)
        for(J=0 ; J<L-I-1 ; J++)
             if(PUNTOS[J] < PUNTOS[J+1])
             {




                    //swapping//


                    AUXPUN      =  PUNTOS [J];
                    PUNTOS[J]   =  PUNTOS[J+1];
                    PUNTOS[J+1] =  AUXPUN;

                    AUXEQ       =  EQUIPO [J];
                    EQUIPO[J]   =  EQUIPO[J+1];
                    EQUIPO[J+1] =  AUXEQ;

             }





}

void MIRA(int EQUIPO[] , int  PUNTOS[] , int L)
{

     int I;


        for( I=0 ; I<L ; I++)

    printf("\n\t\t%d  EQUIPO \n\n\tPTOS %d\n\n", EQUIPO[I],PUNTOS[I]);




}

void PLAYOFFS(int EQUIPO[] , int  PUNTOS[] , int L)
{

        int I;

                for(I=0 ; I<L/2 ; I++)




                   printf("\t\nEQUIPO %d\t\t CONTRA %d",EQUIPO[I],EQUIPO[L-1-I]);






            }














