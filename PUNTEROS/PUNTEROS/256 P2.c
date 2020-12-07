
/*NO SE PUEDE CONOCER LA DIRECCION DE MEMORIA DE UNA VARIABLE GLOBAL PORQUE NO ES UNA VARIABLE

 SINO QUE EN TIEMPO DE COMPILACION CADA VARIABLE GLOBAL SE REEMPLAZA POR EL NUMERO QUE LE FUE ASIGNADO*/

#include<stdio.h>

/* #define N 12 */

int main ()


{

    int RR = 25 ;

    int * PL = &RR ;

   /*  int * PG = &N ; */




    printf(" \n\n\tDireccion P.Local %p \n\n", PL  /*  PG */  );





}
