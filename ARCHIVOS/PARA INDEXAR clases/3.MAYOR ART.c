/*3.  DETERMINAR QUIEN ES EL PROVEEDOR QUE MAS ARTICULOS SUMINISTRA

usar ftell para medir la cantidad e proveedores ,
con esa cantidad se puede hacer un for
el cual va a comparar entre una estructura y otra igual con
esto mas un contador voy a saber la cantidad de p´roveedores que hay(
siempre guardando dentro de una variable todos los proveedores)

uso untitled 4 para probar la funcion FTELL





*/


#include <stdio.h>
#include <stdlib.h>


struct ARTI {
	short int ART ;
	char COD[50];
	char DESC[100];
	char FAB[50];
	short int STOCK ;
};

int main( )
{
		FILE * FP ;
		struct ARTI X , Y ;

		if ( (FP = fopen("BDARTICULOS","rb")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;
		}






		printf("\n\n\t\t %-15s %10s %10s  %10s  %10s\n "  ,
		"ARTICULO" , "CODIGO" , "DESCUENTO" , "FABRICANTE" , "STOCK");
		fread ( &X , sizeof(X) , 1 , FP ) ;
		while ( ! feof(FP) ) {
				printf("\n\n\t %6d %10s %10s  %10s  %10d\n "  ,
				X.ART , X.COD , X.DESC , X.FAB , X.STOCK );

				fread ( &X , sizeof(X) , 1 , FP ) ;
		}

		fclose(FP) ;

		printf("\n\n");
		return 0 ;
}


