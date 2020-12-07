/*   LECTURA DE UN ARCHIVO EJECUTABLE  IMPRESION HEXA  */

#include <stdio.h>
#include <stdlib.h>

int main( )
{  
		FILE * FP ;
		unsigned char CAR ;
		
		if ( ( FP = fopen ( "ARCH1.EXE" , "rb") ) == NULL )  {
				printf("ERROR APERTURA ARCHIVO") ;			
				exit(1);
		}  
		
		CAR = getc(FP) ;
		while ( ! feof(FP) ) {
			printf("%02X  " , CAR ); 
			CAR = getc(FP) ;
		}
				
		fclose(FP);
			
		printf("\n\n");	
		return 0 ;
}
		
		

