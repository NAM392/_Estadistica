#include<stdio.h>

int main ()
{

    int A , B , C , *P , *Q , *R ;
    P=&A ; Q=&B ; R=&C ;
    printf("%p  %p  %p ", P , Q , R);


    printf("\n\nP , Q y R MUESTRAN LA DIRECCION DE MEMORIA DE LAS VARIABLES QUE FUEROIN ASIGNADAS , DECRECIENDO EN LA PILA");


    return 0;




}



