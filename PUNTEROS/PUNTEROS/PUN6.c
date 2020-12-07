/*   ARITMETICA DE PUNTEROS   */

#include <stdio.h>

#define N 8

int main() {
		int VEC[N] , * P , I , * PMIN ;
		
		/*  CARGA DEL VECTOR  */
		for ( P = VEC ; P < VEC+N ; P++ ) {
				printf("\n\n    VALOR  =  ");
				scanf("%d" , P );	
		}
		
		printf("\n\n\n\t\t");
		for ( P = VEC ; P < VEC+N ; P++ ) 
				printf("%6d" , *P );
		
		
		printf("\n\n\n\t\t");
		for ( P = VEC , I = 0 ; I < N ; I++ ) 
				printf("%6d" , *(P+I) );
		getchar() ; getchar();		
				
		
		/*   BUSQUEDA DEL MINIMO  */
		for ( PMIN = P = VEC ; P < VEC+N ; P++ ) 
				if ( *P < *PMIN )
						PMIN = P ;
		
		printf("\n\n  EL VALOR MINIMO ES %d" , *PMIN );
    	printf("\n\n  Y SE ENCUENTRA EN LA POSICION %d" , PMIN - VEC );    			
		
		printf("\n\n\n");
		return 0 ;
}



