

/*  VECTORES  */
/*  EJERCICIO 7 PAG 149    */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define NUM 5


void CARGAR ( int [] , int[] , int );
void MIRAR  ( int [] , int[] , int  );
int  IGUAL   ( int [] , int[] , int  );


int main()
{
		int VEC[NUM] ;
        int VEC2[NUM] ;




        CARGAR( VEC, VEC2 , NUM );

        MIRAR( VEC, VEC2 , NUM );










		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;
}


void CARGAR ( int V[] , int V2[] , int N )
{
		int I,S;
		for ( I = 0 ; I < N ; I++ )
        {
            scanf("%d",&V[I]);
        }

        for ( S = 0 ; S < N ; S++ )
        {
            scanf("%d",&V2[S]);
        }


}



void MIRAR ( int V[] , int V2[] , int N )
{
		int I,S ;
		printf("\n\n\n\n  IMPRESION DE LOS DATOS\n\n");

		for ( I = 0 ; I < N ; I++ )
            {
                printf("%4d",V[I]);
            }

            printf("\t");

        for ( S = 0 ; S < N ; S++ )
            {
                printf("%4d",V2[S]);
            }

        printf("\n\n\t%d",IGUAL( V, V2 , N ));

}



IGUAL( int V[] , int V2[] , int N  )
{
    int I;

    for ( I=0 ; I<N ; I++)
    {

        if((I==I)&&(V[I]==V2[I]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }


}











		/*   SWAPPING  */
			//	AUX   = V[PM];
				//V[PM] = V[PRIMERO];
			//	V[PRIMERO]  = AUX ;

      // }



