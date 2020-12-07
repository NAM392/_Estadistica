/*   ARCHIVOS BINARIOS  */
/*   ORDEN  */

#include <stdio.h>
#include <stdlib.h>

struct ALUMNO {
		char NOM[20] ;
		char SEX ;
		int EDAD ;
};


int main( )
{
		FILE * FP ;
		struct ALUMNO X , Y ;
		int ENCONTRADO , MIN , MAX , MED , N  ;

		if ( (FP = fopen("BD","r+b")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;
		}


		fseek( FP ,0L ,SEEK_END );
		N = ftell(FP) / sizeof(X) ;
		printf("\n\n EL ARCHIVO TIENE %d REGISTROS  " , N);

          /*busqueda binaria*/
          ENCONTRADO = 0;
          MIN=0;
          MAX=N-1;

          while( MIN <= MAX && !ENCONTRADO){
                MED=(MIN+MAX)/ 2;
                fseek(FP , (long)MED*sizeof(X) , SEEK_SET);
                fread (&X , sizeof(X) , 1 , FP );
                printf("\n\n NOMBRE ENCONTRADO : %s", X.NOM );
                getchar();

                if( ! strcmp( X.NOM , NOM)){
                    ENCONTRADO=1;
                    }
                else
                        if(strcmp( NOM , X.NOM ) < 0)
                            MAX=MED-1;
                        else
                            MIN=MED+1;
         }

         if(! ENCONTRADO)
         printf("\n\n  %s NO SE ENCUENTRA EN EL ARCHIVO", NOM );
         else
                printf("\n\n\t\t %-15s %10c %10d" ,
				X.NOM , X.SEX , X.EDAD );





          }





        fclose(FP) ;

		printf("\n\n");
		return 0 ;
}



