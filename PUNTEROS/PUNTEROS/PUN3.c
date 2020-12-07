/*   PUNTEROS  :  PASAJE POR REFERENCIA   */

#include <stdio.h>

void FUNCION(int *) ;

int main() {
		int A ;
		
		A = 654 ;
		printf("\n\n  A = %d    " , A );
    	
    	FUNCION ( &A ) ;
		
    	printf("\n\n  A = %d    " , A );
    	
		printf("\n\n\n");
		return 0 ;
}


void FUNCION(int * P)
{
		*P = 21 * (*P) ;
}

