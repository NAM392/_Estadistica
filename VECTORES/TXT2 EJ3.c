#include<stdio.h>
#define NUM 10


float CARGA(float[],float[],int );
float IGUALES(float[],float[],int );
float MIRAR(float[],float[],int );


int main()
{
    float VECTOR[NUM];
    float VECTOR2[NUM];


   CARGA(VECTOR,VECTOR2,NUM );
   MIRAR(VECTOR,VECTOR2,NUM );



}

float CARGA(float V[] , float V2[] , int N)
{

    int I;

    for(I=0 ; I<N ; I++)
    {
       V[I]=(rand()%99)+1;

    }

      for(I=0 ; I<N ; I++)
    {
       V2[I]=(rand()%99)+1;

    }









}
float IGUALES(float V[] , float V2[] , int N)
{

    int I ;

    for(I=0 ; I<N ; I++)
        {
           if(V[I]==V2[I])

           return 1;

           else return 0;

        }








}

float MIRAR(float V[] , float V2[] , int N)
{
    int I;

     printf("\n\n\n");

   for(I=0 ; I<N ; I++)
   {
      printf("%2.2f\n",V[I]);

   }

   printf("\n\n\n");

    for(I=0 ; I<N ; I++)
   {
        printf("%2.2f\n",V2[I]) ;

   }

    printf("\n\n\n");



       printf("\n\n\n%20.2f\n\n\n",IGUALES(V,V2,N));


}
