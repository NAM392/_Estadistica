/*   PUNTEROS   */

#include <stdio.h>

int main() {
		int A ;
		int * P ;
		float * Q ;
		
		P = &A ;
		A = 654 ;
		printf("\n\n  A = %d       *P = %d" , A , *P );
    	
    	Q = (float *)P ;
		
		printf("\n\n  P = %p    Q = %p" , P , Q );
    	printf("\n\n   *P = %d    *Q = %f" , *P , *Q );
    	
    	P = (int *)0X22FEDC ;
    	printf("\n\n   P = %p    *P = %d" , P , *P );
    	
		printf("\n\n\n");
		return 0 ;
}


