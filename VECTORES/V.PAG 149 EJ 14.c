

/*  MATRICES  */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<time.h>

#define FIL 8
#define COL 8

void CARGAR ( int [][COL] , int , int );
void MIRAR ( int [][COL] , int , int );
int SUMAR ( int [][COL] , int , int );
int CONTRA ( int [][COL] , int , int );

int main()
{
		int MAT[FIL][COL] ,S,C ;




		CARGAR ( MAT , FIL , COL );


		MIRAR ( MAT , FIL , COL );


}


void CARGAR ( int M[][COL] , int F , int C )
{
		int I , J ,coso , pedro , jeny , tacho;
		for ( I = 0 ; I < F ; I++ )
            {
                for ( J = 0 ; J < C ; J++ )
                {
                    M[I][J] = 0  ;
                }


            }

            M[rand()%8][rand()%8]=1;
            M[rand()%8][rand()%8]=1;




}

void MIRAR ( int M[][COL] , int F , int C )
{
		int I , J , ACUM;

		/*   IMPRESION DE LA MATRIZ   */
		printf("\n\n\n\n");
		for ( I = 0 ; I < F ; I++ ) {
				printf("\n\n\t\t");
				for ( J = 0 ; J < C ; J++ )
						printf("%5d" , M[I][J] );



		}


		printf("\n\n");



}



