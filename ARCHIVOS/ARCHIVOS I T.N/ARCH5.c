/*   LECTURA DE UN ARCHIVO BINARIO   IMPRESION NUMERICA  */

#include <stdio.h>
#include <stdlib.h>

int main( )
{  
		FILE * FP ;
		char CAR ;
		
		if ( ( FP = fopen ( "PEPE" , "rb") ) == NULL )  {
				printf("ERROR APERTURA ARCHIVO") ;			
				exit(1);
		}  
		
		printf("\n\n\t\t");
		CAR = getc(FP) ;
		while ( CAR != EOF ) {
			printf("%02X  " , CAR );
			CAR = getc(FP) ;
		}
				
		fclose(FP);
			
		printf("\n\n");	
		return 0 ;
}
		
		

