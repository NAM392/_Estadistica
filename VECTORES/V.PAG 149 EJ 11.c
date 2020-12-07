#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 4
void CARGA  (int [],int [],int);
void ORDENAR(int [],int [],int );
void MIRAR  (int [],int [],int );

int main()
{
    int  BUZO[N];
    int  CODIGO[N];

    CARGA  (BUZO,CODIGO,N);

    ORDENAR(BUZO,CODIGO, N);

    MIRAR  (BUZO,CODIGO,N);

    return 0;


}
void CARGA(int BUCEADOR[] , int CODIGO_BUZO[] , int L)
{
    int I;
    int NUMERO_BUZO=0;



    for(I=0 ; I<L ; I++)
    {
       BUCEADOR[I]=0;

       CODIGO_BUZO[I]=0;
    }



    printf("ingrese el numero de buzo");
    scanf("%d",&NUMERO_BUZO);

    for(I=0 ; NUMERO_BUZO>=0 ; I++)
        {

                BUCEADOR[NUMERO_BUZO-1]=BUCEADOR[NUMERO_BUZO-1]+rand()%300+133;



                CODIGO_BUZO[NUMERO_BUZO-1]=NUMERO_BUZO;

                    printf("ingrese el numero de buzo");
                scanf("%d",&NUMERO_BUZO);



        }




}


void ORDENAR(int BUCEADOR[] , int CODIGO_BUZO[]  ,  int L)
{

    int I , J , AUXCOD , AUXPJE ;

    for(I=0 ; I<L-1 ; I++)
        for(J=0 ; J<L-I-1 ; J++)
             if(BUCEADOR[J] < BUCEADOR[J+1])
                {

                    //swapping//

                    AUXPJE      =  BUCEADOR [J];
                    BUCEADOR[J]  =  BUCEADOR[J+1];
                    BUCEADOR[J+1]=  AUXPJE;

                    AUXCOD      =  CODIGO_BUZO [J];
                    CODIGO_BUZO[J]  =  CODIGO_BUZO[J+1];
                    CODIGO_BUZO[J+1]=  AUXCOD;



                }


}


void MIRAR(int BUCEADOR[] , int CODIGO_BUZO[] , int L)
{
        int I;

      printf("\n\n");


   for(I=0 ; I<L ; I++)
   {

       printf("\n\n\tbuceador %d atrapo una cantidad de %d peces",CODIGO_BUZO[I],BUCEADOR[I]);


   }

   printf("\n\n");





}





