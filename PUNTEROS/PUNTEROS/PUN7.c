/*   ARITMETICA DE PUNTEROS   */

#include <stdio.h>

#define N 8

int main() {
		int VEC[N] , * P , I , J , AUX ;
		
		/*  CARGA DEL VECTOR  */
		for ( P = VEC ; P < VEC+N ; P++ ) {
				printf("\n\n    VALOR  =  ");
				scanf("%d" , P );	
		}
		
		printf("\n\n\n\t\t");
		for ( P = VEC ; P < VEC+N ; P++ ) 
				printf("%6d" , *P );
		getchar() ; getchar();	
		
		/*  ORDENAMIENTO  */
		for ( P = VEC , I = 0 ; I < N-1 ; I++ )
				for ( J = 0 ; J < N-I-1 ; J++ )
						if ( *(P+J) > *(P+J+1) ) {
								/*  SWAPPING  */
								AUX = *(P+J) ;
								*(P+J) = *(P+J+1) ;
								*(P+J+1) = AUX ;							
						}
				
		printf("\n\n\n\t\t");
		for ( P = VEC , I = 0 ; I < N ; I++ ) 
				printf("%6d" , *(P+I) );
			
		printf("\n\n\n");
		return 0 ;
}



