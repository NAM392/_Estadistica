/*   LECTURA DE UN ARCHIVO EJECUTABLE  */

#include <stdio.h>
#include <stdlib.h>

int main( )
{  
		FILE * FP ;
		char CAR ;
		
		if ( ( FP = fopen ( "ARCH1.EXE" , "r") ) == NULL )  {
				printf("ERROR APERTURA ARCHIVO") ;			
				exit(1);
		}  
		
		CAR = getc(FP) ;
		while ( CAR != EOF ) {
			printf("%c" , CAR );
			CAR = getc(FP) ;
		}
				
		fclose(FP);
			
		printf("\n\n");	
		return 0 ;
}
		
		

