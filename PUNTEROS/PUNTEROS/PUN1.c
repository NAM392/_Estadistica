/*   PUNTEROS   */

#include <stdio.h>

int main() {
		int A ;
		int * P ;
		
		P = &A ;
		A = 654 ;
		printf("\n\n  A = %d       *P = %d" , A , *P );
    	
    	*P = 98787 ;
		
		printf("\n\n  A = %d       *P = %d" , A , *P );
    	printf("\n\n  P = %X    P = %p" , P , P );
    	printf("\n\n  &A = %X    &A = %p" , &A , &A );
    	
		printf("\n\n\n");
		return 0 ;
}


