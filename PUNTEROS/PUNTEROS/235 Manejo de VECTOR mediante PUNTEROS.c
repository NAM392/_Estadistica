#include<stdio.h>
#define N 10

int main ()
{
    int VEC[N] , *p , *max , i ;

    /* INGRESO DE DATOS */
    for( p=VEC ; p < VEC+N ; p++)
        scanf("%d", p);

    /* CALCULO DEL MAXIMO*/
    for ( max = p = VEC , i=0 ; i<N ; i++)
            if(*(p+i) > *max)
            max = p+i ;

    /* IMPRESION DE RSULTADOS*/
    printf("\n\n MAX = %d ", *max);
    printf("  \n  POS = %d " , max - VEC );

    /* UBICACION EN MEMORIA*/
    printf("\n\n\t\t %p ", max);




}
