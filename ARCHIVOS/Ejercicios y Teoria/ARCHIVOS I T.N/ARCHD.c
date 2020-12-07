/*   ESCRITURA EN ARCHIVO DE TEXTO CON FORMATO */

#include <stdio.h>
#include <stdlib.h>

int main( )
{  
		FILE * FP ;
		int I , J ;
						
		if ( ( FP = fopen ( "HIPER.XLS" , "w") ) == NULL )  {
				printf("ERROR APERTURA ARCHIVO") ;			
				exit(1);
		}  
		
		for ( I = -10 ; I<= 10 ; I++ ) {
				for ( J = -10 ; J <= 10 ; J++ ) 		
					fprintf( FP , "%d\t" , (I*I-J*J) ) ;
				fprintf( FP , "\n");
		}
											
		fclose(FP);
			
		printf("\n\n");	
		return 0 ;
}
		
		

