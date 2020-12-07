#include<stdio.h>
#define N 6

//prototipo de la funcion

void funcion(int[]);



int main()
{

    int VEC[N];

    printf("\n EL TAMANIO DE VEC ES %d",sizeof(VEC));

    funcion(VEC);

}

void funcion(int VECTOR[])
{


        printf("\n\n TAMANIO DEL VECTOR =%d \n\n",sizeof(VECTOR));
};
