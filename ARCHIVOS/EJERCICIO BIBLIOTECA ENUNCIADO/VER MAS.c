/*   ARCHIVOS BINARIOS  */
/*   LECTURA DE UN ARCHIVO */

#include <stdio.h>
#include <stdlib.h>


struct MAS_DE_DOS{
                 int LECTOR ;
                 int CODIGO ;

};


int main( )
{
		FILE * FP ;
		struct MAS_DE_DOS X ;

		if ( (FP = fopen("MAS_DOS","rb")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;
		}

		fread ( &X , sizeof(X) , 1 , FP ) ;
		while ( ! feof(FP) ) {

                printf("\n\n %10d %-20d" ,
                X.LECTOR , X.CODIGO );
                fread ( &X , sizeof(X) , 1 , FP ) ;
		}

		fclose(FP) ;

		printf("\n\n");
		return 0 ;
}


