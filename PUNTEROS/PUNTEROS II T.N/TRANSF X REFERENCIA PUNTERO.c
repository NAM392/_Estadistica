#include<stdio.h>
#define N 4


/*int agregar ( int [] , int* , int );*/
int agregar ( int [] , int** , int );


int main ()
{

    int VEC[N] , *P_ultimo , A ;
    P_ultimo=VEC ;
    /*agregar( VEC , P_ultimo , A);*/
    agregar( VEC , &P_ultimo , A);


}


/*agregar( int * VEC , int*P_ultimo , int nuevo) */


agregar( int * VEC , int**P , int nuevo)
{

   /* if(P_ultimo == VEC + N) {
        printf("No hay lugar");
        return ;}
     *P_ultimo = nuevo ;
     P_ultimo ++ ;

    */


    if(*P == VEC + N){
        printf("No hay lugar ");
        return ;  }
    **P = nuevo ;
    (*P) ++ ;


}
