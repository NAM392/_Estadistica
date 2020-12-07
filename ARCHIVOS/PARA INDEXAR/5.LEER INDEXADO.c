/*   ARCHIVOS BINARIOS  */
/*   LECTURA DE UN ARCHIVO */

/*LEER INDEXADO ABRE EL ARCHIVO DE INDICES RECORDANDO
QUE EL RESTO DE LOS CAMPOS CONTIENEN DIRECCIONES DE MEMORIA DEL RESTO DE LOS DATOS*/

/*RELEER*/

#include <stdio.h>
#include <stdlib.h>


struct INDICES {
	short int ART ;
	int POS ;
};

int main( )
{
		FILE * FP ;
		struct INDICES X ;

		if ( (FP = fopen("IX","rb")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;
		}

		printf("\n\n\t\t %-15s %10s \n "  ,
		"ARTICULO" , "POSICION" );
		fread ( &X , sizeof(X) , 1 , FP ) ;
		while ( ! feof(FP) ) {
				printf("\n\n\t %6d \t %10d\n "  , X.ART , X.POS  );

				fread ( &X , sizeof(X) , 1 , FP ) ;
		}

		fclose(FP) ;

		printf("\n\n");
		return 0 ;
}



