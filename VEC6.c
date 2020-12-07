/*  VECTORES  */
/*  VECTORES APAREADOS  */
/*  CARGA AUTOMATICA  */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define NUM 16

void CARGAR ( int [] , char [] , float [] , int );
void MIRAR  ( int [] , char [] , float [] , int );

int main()
{
		int LEG[NUM] ;
		char SEX[NUM] ;
		float PROM[NUM] ;


		CARGAR ( LEG , SEX , PROM , NUM );
		MIRAR ( LEG , SEX , PROM , NUM );

		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;
}


void CARGAR ( int L[] , char S[] , float P[] , int N )
{
		int I ;
		for ( I = 0 ; I < N ; I++ ) {
				L[I] = 10000 + rand()%90000     ;

				if ( rand()%2 )
						S[I] = 'M' ;
				else
						S[I] = 'F' ;


				 S[I] = 'F' + (rand()%2)*('M'-'F') ;

				//CONDICION ? OPCIONxSI : OPCIONxNO
				S[I] = (rand()%2) ? 'M' : 'F' ;

				P[I] =  2+(rand()%801)/100.0    ;
		}
}

void MIRAR ( int L[] , char S[] , float P[] , int N )
{
		int I ;
		printf("\n\n\t\t %10s\t%5s\t%10s\n" , "LEGAJO" , "SEXO" , "PROMEDIO" );
		for ( I = 0 ; I < N ; I++ )
				printf("\n\t\t %10d\t%5c\t%10.2f" , L[I] , S[I] , P[I] );
		printf("\n");getchar() ;
}


