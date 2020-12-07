#include<stdio.h>
#define N 6

//prototipo de la funcion

void funcion(int[N],int);



int main()
{

    int VEC[N],I,A=3;

    for(I=0;I<N;I++)
    {
        VEC[I]=I;
    };

    funcion(VEC,A);

    printf("\n VALOR DE A=%d \n\n\n\n",A);
    printf("VALORES DEL VECTOR \n\n");
    for(I=0;I<N;I++)
    {
        printf("%7d",VEC[I]);
    };


}

void funcion(int VECTOR[N],int A)
{
    int I;
    for(I=0;I<N;I++)
    {
        VECTOR[I]=VECTOR[I]*2;

        A=8;
    };



}
