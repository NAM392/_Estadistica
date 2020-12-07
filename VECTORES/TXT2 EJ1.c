#include<stdio.h>
#define NUM 10
void CARGA(int[] , int);
void MIRAR(int[] , int);


int main()
{

    int VECTOR[NUM] ;



    CARGA(VECTOR, NUM);
    MIRAR(VECTOR, NUM);








}
void CARGA(int V[] , int N)
{
    int I;

    for(I=0 ; I<N ; I++)
        {

            printf("ingrese valor ");
            scanf("%d",&V[I]);


        }


}

void MIRAR(int V[] , int N)
{

    int I;

       printf("\n\n\n");

    for(I=0 ; I<N ; I++)
        {

            printf("%4d",V[I]);



        }

    printf("\n\n\n");

    for(I=9; I>=0 ; I--)


       {
         printf("%4d",V[I]);
       }



    printf("\n\n\n");







}
