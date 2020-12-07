/*  MATRICES  */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

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

        S=SUMAR ( MAT , FIL , COL );
        C=CONTRA ( MAT , FIL , COL );

		printf("\n\n\n\t\t\t SUMA DE LA DIAGONAL PRINCIPAL %d \n\n\n\t\t\t SUMA DE LA DIAGONAL SECUNDARIA %d ",S,C);

		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;
}


void CARGAR ( int M[][COL] , int F , int C )
{
		int I , J ;
		for ( I = 0 ; I < F ; I++ )
            {
                for ( J = 0 ; J < C ; J++ )
                {
                    M[I][J] = rand()%100  ;
                }

            }



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


}


int SUMAR(int M[][COL] , int F , int C )
{

int I , J ,ACUM=0;
		for ( I = 0 ; I < F ; I++ )
            {
                for ( J = 0 ; J < C ; J++ )
                {
                    if(I==J)
                    {
                        ACUM=ACUM+M[I][J];
                    }

                }

            }

            return ACUM;





}

int CONTRA(int M[][COL] , int F , int C )
{
int I , J ,ACUM=0;
		for ( I = 0 ; I < F ; I++ )
            {
                for ( J=7 ; J >=0 ; J-- )
                {

                        ACUM=ACUM+M[I][J];


                }

            }

            return ACUM;






}



