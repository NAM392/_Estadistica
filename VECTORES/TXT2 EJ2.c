
//2) Realice una función que reciba un vector de int y su largo, y retorne el
//promedio de sus valores Construya una función main para testear el funcionamiento.//


#include<stdio.h>
#define NUM 8
void CARGA(int [] , int);
void MIRAR (int [],int );
int PROMEDIO (int [],int );



int main()

{

    int VECTOR[NUM];
    CARGA(VECTOR,NUM);
    MIRAR(VECTOR,NUM);





}


CARGA(int V[],int N)
{

    int I;

    for(I=0 ; I<N ; I++)
    {
        V[I]=rand()%100;

    }



}


PROMEDIO(int V[],int N)
{
    int I,acum=0,PROM=0;

    for(I=0 ; I<N ; I++)

        {

           acum=acum+V[I];

        }

        PROM=acum/N;

        return PROM;


}


MIRAR(int V[],int N)
{

    int I;

    for(I=0 ; I<N ; I++)
    {
        printf("%4d",V[I]);
    }


    printf("\n\nEL PROMEDIO ES %d",PROMEDIO(V,N));


}

