#include <stdio.h>
#define N 2
int main()
{

    struct{
            char nombre[10];
            int nota ; } VEC[N] , aux , *P ;
    int i , j ;

    /*  INGRESO DE DATOS */

    for( P = VEC ; P < VEC+N ; P++){
        fflush(stdin);
        gets( P->nombre );
        scanf("%d" , &( P->nota));
    }

    /* ORDENAMIENTO  */

    for(P = VEC , i=0 ; i < N-1 ; i++)
          for( j=0 ; j<N-i-1 ; j++)
    if( (P+j)->nota  <  (P+j+1)->nota){

                 aux     =  *(P+j) ;
                *(P+j)   =  *(P+j+1);
                *(P+j+1) =  aux;
    }


    /*  IMPRESION DE DATOS */
    printf("\n\n\n");
    for ( i=0 ; i<N ; i++)
        printf("\n\t%12s\t%d", (P+i)->nombre , (P+i)->nota );



}
