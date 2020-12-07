/*   PUNTERO A PUNTERO   */


#include <stdio.h>
#include <stdlib.h>

int main( )
{  
		int A , *P , **PP ;
		
		A = 654 ;
		P = &A ;
		PP = &P ;
		
		printf("\n\n   &A = %p    &P = %p     &PP = %p" , &A , &P , &PP );
		printf("\n\n   A = %d    P = %p     PP = %p" , A , P , PP );	
		printf("\n\n   *P = %d    *PP = %p     **PP = %d" , *P , *PP , **PP );
		
		**PP = 32154 ;
		
		printf("\n\n\n\n   A = %d  " , A  );
		
		
		printf("\n\n");	
		return 0 ;
}
		

