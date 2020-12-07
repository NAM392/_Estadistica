#include<stdio.h>
#define N 4
int main ()
{
    struct {
            char nombre [10] ;
            int nota; } VEC[N] , *PUNT[N] , *PAUX ;
    int i , k ;

    /* INGRESO DE DATOS */
    for (PAUX = VEC ; PAUX < VEC+N ; PAUX++){
        fflush(stdin);
        gets(PAUX-> nombre );
        scanf("%d",&( PAUX->nota ));
    }

    /* INICIALIZACION DEL VECTOR DE PUNTEROS */
    for(i=0 ; i<N ; i++)
        *(PUNT+i) = VEC+i ;

    /* ORDENAMIENTO */
    for ( i=0 ; i<N-1 ; i++)
        for( k=0 ; k< N-i-1 ; k++)
    if (PUNT [k]->nota  <  PUNT[k+1]->nota ){

            PAUX        =  PUNT[k] ;
            PUNT[k]     =  PUNT[k+1];
            PUNT[k+1]   =  PAUX;

    }

 /* IMPRESION DE DATOS */
 printf("\n\n\n");
 for ( i=0 ; i<N ; i++)
        printf("\n\t%12s\t%d" , PUNT[i]->nombre , PUNT[i]->nota );










}
