/*   ESCRITURA EN ARCHIVO DE TEXTO  */

#include <stdio.h>
#include <stdlib.h>

int main( )
{  
		FILE * FP ;
		char CAR ;
		
		if ( ( FP = fopen ( "PEPE2" , "w") ) == NULL )  {
				printf("ERROR APERTURA ARCHIVO") ;			
				exit(1);
		}  
		
		CAR = getchar() ;
		while ( CAR != '$' ) {
			putc( CAR , FP );
			CAR = getchar() ;
		}
				
		fclose(FP);
			
		printf("\n\n");	
		return 0 ;
}
		
		

