/*   PUNTEROS A ESTRUCTURA  */

#include <stdio.h>
#include <stdlib.h>

struct ALFA {
		int A ;
		float F ;
};

int main( )
{  
		struct ALFA X , *P ;
		
		X.A = 654 ;
		X.F = 75.2356 ;
		
		P = &X ;
		
		printf("\n\n\n    P->A = %d      P->F = %f" , P->A , P->F );
		
		P->A = 2 * P->A ;
		P->F = 2 * P->F ;
		
		printf("\n\n\n    P->A = %d      P->F = %f" , P->A , P->F );
			
		printf("\n\n");	
		return 0 ;
}
		
		

