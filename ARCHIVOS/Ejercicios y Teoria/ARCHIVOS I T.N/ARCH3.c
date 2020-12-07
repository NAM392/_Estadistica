/*   LECTURA DE UN PROGRAMA FUENTE  */

#include <stdio.h>
#include <stdlib.h>

int main( )
{  
		FILE * FP ;
		char CAR ;
		
		if ( ( FP = fopen ( "ARCH1.C" , "r") ) == NULL )  {
				printf("ERROR APERTURA ARCHIVO") ;			
				exit(1);
		}  
		
		CAR = getc(FP) ;
		while ( CAR != EOF ) {
			putchar( CAR );
			CAR = getc(FP) ;
		}
				
		fclose(FP);
			
		printf("\n\n");	
		return 0 ;
}
		
		

