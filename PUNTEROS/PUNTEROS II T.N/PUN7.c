
#include <stdio.h>
#include <stdlib.h>

#define N 6

int PONER ( int * , int ** , int );

int main( )
{
		int VEC[N] , *SP , DATO ;

		SP = VEC ;
		do {
			printf("\n\n   DATO  =  ");
			scanf("%d" , &DATO);
		} while ( PONER(VEC,&SP,DATO) );

		printf("\n\n\n\n\t\t");
		for ( SP = VEC ; SP < VEC+N ; SP++ )
				printf("%5d" , *SP);

		printf("\n\n");
		return 0 ;
}

int PONER ( int * VEC , int ** PP , int DATO )
{
		/*  PP EQUIVALE A   & SP */
		/*  *PP  EQUIVALE A   SP */

		**PP = DATO ;
		(*PP)++ ;
		if ( *PP == VEC+N ) return 0 ;
		return 1 ;
}
