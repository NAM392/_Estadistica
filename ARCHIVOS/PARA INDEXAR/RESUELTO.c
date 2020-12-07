/*  LA BASE DE DATOS BDARTICULOS ESTA ESTRUCTURADA DE LA SIGUIENTE MANERA */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ARTI {
	short int ART ;
	char COD[50];
	char DESC[100];
	char FAB[50];
	short int STOCK ;
};

struct INDICES {
	short int ART ;
	int POS ;
};


/*

1.  HACER UN PROGRAMA DE LECTURA
2.  MOSTRAR LOS ARTICULOS CUYO STOCK ES MENOR QUE 8
3.  DETERMINAR QUIEN ES EL PROVEEDOR QUE MAS ARTICULOS SUMINISTRA
4.  PERMITIR EL INGRESO DE UN #ART Y BUSCARLO
5.  INDEXAR EL ARCHIVO
6.  ORDENAR EL INDICE
7.  REPETIR EL PUNTO 4 CON UNA BUSQUEDA BINARIA INDEXADA.

*/

int NUMVECES ( char [] , FILE * );

int main()
{
	FILE * FP , * FP1 , * IX ;
	struct ARTI ART ;
	char MAXFAB[50];
	int MAXVECES , VECES , POS ;
	int I , J , N ;
	struct INDICES IND , X , Y ;
	int MIN , MAX , MED , ENCONTRADO ;
	short int ARTICULO ;
	
	if ( !(FP = fopen("BDARTICULOS","rb"))) {
			printf("\n\n   ERROR APERTURA DE LA BASE DE DATOS" );
			exit(1);		
	}
	
	/*********************************************/
	/*                                           */
	/*  	1.  HACER UN PROGRAMA DE LECTURA     */
	/*                                           */
	/*********************************************/
	
	fread ( &ART , sizeof(ART) , 1 , FP);
	while ( ! feof(FP)) {
			printf("\n\n %10d %-10s %-20s %-10s %5d" , 
			ART.ART , ART.COD , ART.DESC , ART.FAB , ART.STOCK ); 
			fread ( &ART , sizeof(ART) , 1 , FP);
	}
	getchar() ;
	
	/*************************************************/
	/*                                               */
	/*  	3.  DETERMINAR QUIEN ES EL PROVEEDOR     */
	/*          QUE MAS ARTICULOS SUMINISTRA         */
	/*                                               */
	/*************************************************/
	
	printf("\n\n\n\n    BUSCANDO AL PROVEEDOR MAS FRECUENTE ...");
	printf("\n\n\n");
	
	if ( !(FP1 = fopen("BDARTICULOS","rb"))) {
			printf("\n\n   ERROR SEGUNDA APERTURA DE LA BASE DE DATOS" );
			exit(1);		
	}
	
	rewind(FP) ;
	MAXVECES = 0 ;
	
	/*  LECTURA CON FP */
	fread ( &ART , sizeof(ART) , 1 , FP);
	while ( ! feof(FP)) {
			VECES = NUMVECES ( ART.FAB , FP1 );
			if ( VECES > MAXVECES ) {
					MAXVECES = VECES ;
					strcpy ( MAXFAB , ART.FAB );
			}
			fread ( &ART , sizeof(ART) , 1 , FP);
	}
	fclose(FP1);
	
	printf("\n\n   PROVEEDOR MAS FRECUENTE  :  %s" , MAXFAB);
	printf("\n\n   CANTIDAD DE ARTICULOS    :  %d" , MAXVECES);
	
	
	/*************************************/
	/*                                   */
	/*  	5.  INDEXAR EL ARCHIVO       */
	/*                                   */
	/*************************************/
	
	printf("\n\n\n\n    CREANDO AL ARCHIVO DE INDICES ...");
	printf("\n\n\n");
	
	if ( !(IX = fopen("IX","wb"))) {
			printf("\n\n   ERROR CREACION ARCHIVO DE INDICES" );
			exit(1);		
	}
	
	rewind(FP) ;
	POS = 0 ;
	fread ( &ART , sizeof(ART) , 1 , FP);
	while ( ! feof(FP)) {
			IND.ART = ART.ART ; 
			IND.POS = POS++ ;
			fwrite ( &IND , sizeof(IND) , 1 , IX);
			fread ( &ART , sizeof(ART) , 1 , FP);
	}
	
	fclose(IX) ;
	
	
	/*************************************/
	/*                                   */
	/*  	6.  ORDENAR EL INDICE        */
	/*                                   */
	/*************************************/
	
	printf("\n\n\n\n    ORDENANDO EL ARCHIVO DE INDICES ...");
	printf("\n\n\n");
	
	if ( !(IX = fopen("IX","r+b"))) {
			printf("\n\n   ERROR APERTURA ARCHIVO DE INDICES" );
			exit(1);		
	}
	
	fseek(IX , 0L , SEEK_END);
	N = ftell(IX)/sizeof(IND) ;
	printf("\n\n\n  EL ARCHIVO DE INDICES TIENE %d REGISTROS" , N );
	
	for ( I = 0 ; I < N-1 ; I++ )
			for ( J = 0 ; J < N-I-1 ; J++ )  {
				 fseek( IX , (long)J*sizeof(IND) , SEEK_SET );
				 fread ( &X , sizeof(X) , 1 , IX);	
				 fread ( &Y , sizeof(Y) , 1 , IX);
				 if ( X.ART > Y.ART ) {
				 		fseek( IX , (long)J*sizeof(IND) , SEEK_SET );
				 		fwrite ( &Y , sizeof(Y) , 1 , IX);
				 		fwrite ( &X , sizeof(X) , 1 , IX);
				 }				
			}
	fclose(IX) ;		
	
	/********************************************/
	/*                                          */
	/*  	7.  BUSQUEDA BINARIA INDEXADA       */
	/*                                          */
	/********************************************/
	
	printf("\n\n\n\n    BUSQUEDA BINARIA INDEXADA ...");
	printf("\n\n\n");
	
	if ( !(IX = fopen("IX","rb"))) {
			printf("\n\n   ERROR APERTURA ARCHIVO DE INDICES" );
			exit(1);		
	}
	
	printf("\n\n\n    NUMERO DE ARTICULO   :   ");
	scanf("%d" , &ARTICULO);
	
	MIN = 0 ;
	MAX = N-1 ;
	ENCONTRADO = 0 ;
	while ( MIN <= MAX && ! ENCONTRADO ) {
			MED = (MIN+MAX)/2 ;
			fseek( IX , (long)MED*sizeof(IND) , SEEK_SET );
			fread ( &IND , sizeof(IND) , 1 , IX);
			if ( ARTICULO == IND.ART )
					ENCONTRADO = 1 ;
			else
					if ( ARTICULO < IND.ART )
							MAX = MED-1 ;
					else
							MIN = MED+1 ;
	}
	
	if ( ! ENCONTRADO )
			printf("\n\n  NO SE ENCONTRO EL ARTICULO ");
	else  {
			fseek ( FP , (long)IND.POS*sizeof(ART) , SEEK_SET);
			fread ( &ART , sizeof(ART) , 1 , FP);
			printf("\n\n %10d %-10s %-20s %-10s %5d" , 
			ART.ART , ART.COD , ART.DESC , ART.FAB , ART.STOCK ); 
	}
	
	fclose(IX) ;
	fclose(FP) ;
			
			
			
			
	printf("\n\n\n\n\n   FIN DEL PROGRAMA");
	return 0 ;
}


int NUMVECES ( char FAB[] , FILE * FP )
{
		int NUM = 0 ;
		struct ARTI ART ;
		
		rewind(FP);
	
		fread ( &ART , sizeof(ART) , 1 , FP);
		while ( ! feof(FP)) {
			if ( !strcmp (ART.FAB , FAB)  )
					NUM++ ; 
			fread ( &ART , sizeof(ART) , 1 , FP);
		}
	
		return NUM ;	
}
