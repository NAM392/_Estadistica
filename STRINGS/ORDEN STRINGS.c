#include<stdio.h>
#include<string.h>

#define MAX 20
#define NUM 10

int main()
{

    char MAT[NUM] [MAX] , AUX[MAX] ;
    int I,J ;
    printf("ingrese 10 palabras.\n\n");

    //ingreso

    for(I=0 ; I<NUM ; I++)
    {
        printf("palabra %3d : ",I+1);
        gets(MAT[I]);

    }

    //ordenamiento

    for(I=0 ; I<NUM-1 ; I++)
        for(J=0 ; J<NUM-I-1 ; J++)
            if(strcmp(MAT[J],MAT[J+1]) > 0)
            {
               strcpy(AUX  , MAT[J] );
               strcpy(MAT[J], MAT[J+1]);
               strcpy(MAT[J+1] , AUX  );
            }

     //impresion
     printf("\n\n vector ordenado \n") ;
     for(I=0 ; I<NUM ; I++)
          printf("\n%s",MAT[I]);
     printf("\n\nfin del programa");



}
