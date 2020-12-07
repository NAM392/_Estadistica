

/*  VECTORES  */
/*  EJERCICIO 6 PAG 149    */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define NUM 5


void CARGAR ( int [] , int  );
void MIRAR  ( int [] , int  );
int ORDEN( int [] , int  );


int main()
{
		int VEC[NUM] ;
        rand()%100;




        CARGAR( VEC, NUM );

        MIRAR( VEC, NUM );


        printf("\n\n\t\t%d",ORDEN( VEC, NUM ));





		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;
}


void CARGAR ( int V[] ,  int N )
{
		int I,S;
		for ( I = 0 ; I < N ; I++ )
        {
            scanf("%d",&V[I]);
        }

        getchar();
}



void MIRAR ( int V[] ,int N )
{
		int I ;
		printf("\n\n\n\n  IMPRESION DE LOS DATOS\n\n");

		for ( I = 0 ; I < N ; I++ )

            printf("%4d",V[I]);


}

ORDEN(int V[] ,int N )
{
    int I;

    for(I=0 ; I<N ; I++)
    {


        if(V[I]<V[I+1])

        {
            return 1;

        }

        else return 0;

    }



}











		/*   SWAPPING  */
			//	AUX   = V[PM];
				//V[PM] = V[PRIMERO];
			//	V[PRIMERO]  = AUX ;

      // }




