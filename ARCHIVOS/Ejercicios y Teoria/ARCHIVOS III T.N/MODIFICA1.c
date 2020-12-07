/*   ARCHIVOS BINARIOS  */
/*   LECTURA DE UN ARCHIVO */

#include <stdio.h>
#include <stdlib.h>

struct ALUMNO {
		char NOM[20] ;
		char SEX ;
		int EDAD ;	
};


int main( )
{  
		FILE * FP ;
		struct ALUMNO X ;
		int ESTA = 0 ;
				
		if ( (FP = fopen("BD","r+b")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;			
		}
		
		
		fread ( &X , sizeof(X) , 1 , FP ) ;
		while ( ! feof(FP) && ! ESTA ) {
				if ( ! strcmp(X.NOM , "LUCRECIA") ) {
						X.EDAD = 2 * X.EDAD ;
						fseek ( FP , (long)(-1)*sizeof(X) , SEEK_CUR );
						fwrite ( &X , sizeof(X) , 1 , FP ) ;	
						ESTA = 1 ;
				}
				
				fread ( &X , sizeof(X) , 1 , FP ) ;	
		}
				
		fclose(FP) ;
					
		printf("\n\n");	
		return 0 ;
}
		
		

