/*   ESCRITURA EN ARCHIVO DE TEXTO CON FORMATO */

#include <stdio.h>
#include <stdlib.h>

int main( )
{  
		FILE * FP ;
		float F ;
		
		F = 7.5 ;
				
		if ( ( FP = fopen ( "FLOTA" , "w") ) == NULL )  {
				printf("ERROR APERTURA ARCHIVO") ;			
				exit(1);
		}  
		
		fprintf( FP , "%f" , F ) ;
											
		fclose(FP);
			
		printf("\n\n");	
		return 0 ;
}
		
		

