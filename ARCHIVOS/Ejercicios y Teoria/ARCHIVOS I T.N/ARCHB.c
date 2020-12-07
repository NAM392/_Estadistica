/*   ESCRITURA EN ARCHIVO DE TEXTO CON FORMATO */

#include <stdio.h>
#include <stdlib.h>

int main( )
{  
		FILE * FP ;
		char CAR ;
				
		if ( ( FP = fopen ( "FORMATO.TXT" , "w") ) == NULL )  {
				printf("ERROR APERTURA ARCHIVO") ;			
				exit(1);
		}  
		
		fprintf( FP , "\n\n\t  ESCRITURA CON FORMATO" ) ;
											
		fclose(FP);
			
		printf("\n\n");	
		return 0 ;
}
		
		

