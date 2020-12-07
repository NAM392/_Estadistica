/*  VECTORES  */
/*  INTERCAMBIO ENTRE EL MINIMO Y EL PRIMERO    */
// ORDEN POR SELECCION //

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define NUM 20

void CARGAR ( int [] , int );
void MIRAR ( int [] , int );
void SELECCION ( int [] , int );

int main()
{
		int VEC[NUM] ;
		srand(3771);

		CARGAR ( VEC , NUM );
		MIRAR ( VEC , NUM );

		SELECCION ( VEC , NUM );
		MIRAR ( VEC , NUM );

		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;
}


void CARGAR ( int V[] , int N )
{
		int I ;
		for ( I = 0 ; I < N ; I++ )
				V[I] = rand()%100 ;
}

void MIRAR ( int V[] , int N )
{
		int I ;
		printf("\n\n\n\n  IMPRESION DE LOS DATOS\n\n");
		for ( I = 0 ; I < N ; I++ )
				printf("%4d" , I );
		printf("\n");
		for ( I = 0 ; I < N ; I++ )
				printf("%4d" , V[I] );
		getchar();
}


void SELECCION ( int V[] , int N )
{
		int I , PM , AUX , PRIMERO ;

		for ( PRIMERO = 0 ; PRIMERO < N-1 ; PRIMERO++ ) {
				PM = PRIMERO ;
				for ( I = PRIMERO+1 ; I < N ; I++ )
						if ( V[I] < V[PM] )
								PM = I ;

				/*   SWAPPING  */
				AUX   = V[PM];
				V[PM] = V[PRIMERO];
				V[PRIMERO]  = AUX ;

		}
}

