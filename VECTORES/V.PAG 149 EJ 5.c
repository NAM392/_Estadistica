
/*  VECTORES  */
/*  EJERCICIO 5 PAG 149    */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define NUM 10000
#define DA 6

void CARGAR ( int [] ,int [] , int ,int );
void MIRAR  ( int [] , int[],int,int );
void CARAS(int [] , int [] , int , int );


int main()
{

        int VECD [DA] ;
		int VEC[NUM] ;

        CARGAR( VEC, VECD, NUM ,DA );

		CARAS (VEC,VECD,NUM,DA);

		MIRAR ( VEC, VECD , NUM , DA );

		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;
}


void CARGAR ( int V[] , int V2[] , int N , int D )
{
		int I,S;
		for ( I = 0 ; I < N ; I++ )
        {
            V[I] = (rand()%6+1);
        }
        for(S=0 ; S<D ; S++)
        {
            V2[S]=0;
        }
}



void MIRAR ( int V[] ,int V2[] ,int N , int D )
{
		int I ;
		printf("\n\n\n\n  IMPRESION DE LOS DATOS\n\n");

		for ( I = 0 ; I < N ; I++ )

            printf("%4d",V[I]);

         printf(" \n\n\n\t\t\tAPARECIO \n\n\n %d veces el 1 \t\n %d veces el 2\t\n %d veces el 3\t\n %d veces el 4\t\n %d veces el 5\t\n %d veces el 6",V2[0],V2[1],V2[2],V2[3],V2[4],V2[5]);
}


void CARAS(int V[] , int V2[] , int N , int D)
{
    int I,X;



    for( I=0 ; I<N ; I++)
    {

        for(X=0 ; X<D+1 ; X++)
        {

            if(V[I]==X)

                {
                    V2[X-1]=V2[X-1]+1;

                }


        }

    }




}
