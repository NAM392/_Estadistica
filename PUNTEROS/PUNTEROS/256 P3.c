#include<stdio.h>
#define N 4

int main ()
{
    int Q , W , E , R , T , Y , i ;



    int VECTOR[N];               /*= 123 , VECTOR[1]= 1234 , VECTOR[2] = 12 , VECTOR[3] = 2 ;*/

    int * P[N];

    int *PQ = &Q , *PW=&W , *PE=&E , *PR=&R , *PT=&T , *PY=&Y ;

    printf(" Q=%p\t\tW=%p\t\tE=%p\t\tR=%p\t\tT=%p\t\tY=%p\t\t ", PQ , PW , PE , PR , PT , PY );



    printf("\n\n\tLAS ASIGNACIONES DECRECEN 4 BYTES\n\n");


   for(i=0; i<N ; i++){
        P[i] = &VECTOR[i] ;

   };

   for(i=0 ; i<N ; i++){
    printf("\n\n\n\t vector[%d] tiene direccion %p \n\n ", i , P[i] );
   };


   printf("\n\nLAS ASIGNACIONES SUBEN 4 BYTES\n\n");











}
