#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*   4.   DETERMINAR CUAL ES EL LIBRO DE MAYOR USO (CANTIDAD DE PRESTAMOS) */





struct LIBRO {
       int CODIGO ;          	/*  ID DEL LIBRO  */
       char TITULO[30];
       char AUTOR[20];
       char TEMATICA[20];		/*  GENERO DEL LIBRO  */
       char STATUS ;			/*  0 = DISPONIBLE   1 = PRESTADO  */
       int LECTOR ;				/*  CODIGO DE ID DEL USUARIO  */
};


struct USUARIO {
               int LECTOR ;		/*  CODIGO DE ID DEL USUARIO  */
               char NOM[20];
               int TE ;
};


struct MOVIMIENTO {
                  int LECTOR ;		/*  CODIGO DE ID DEL USUARIO  */
                  int CODIGO ;		/*  CODIGO DE ID DEL LIBRO  */
                  char OPERACION ;  /*  0 = DEVOLUCION    1 = PRESTAMO  */
};

int NUMVECES (int , FILE *);



int main(){


    struct MOVIMIENTO MOVI ;
    struct USUARIO USU;
    struct LIBRO LIB , X , Y ;


    FILE*FU ;
    FILE*FL ;
    FILE*FM ;
    FILE*FL1;

    int I , J , MAXLIB  , N  , MAXVECES=0 ;
    int  VECES=0 ;


    if(!(FL = fopen("BIBLIOTECA" , "r+b" ))){
        printf("\nERRO AL ABRIR ARCHIVO AUXILIAR USUARIO");
        exit(1);
    }

    fread(&LIB , sizeof(LIB), 1 , FL);

    N = ftell(FL)/sizeof(X);

    for(I=0 ; I<N-1 ; I++)
            for(J=0 ; J<N-I-1 ; J++){
                fseek( FL , (long)J*sizeof(LIB) , SEEK_SET );
                fread(&X , sizeof(X) , 1 , FL);
                fread(&Y , sizeof(Y) , 1 , FL);
                if(X.CODIGO > Y.CODIGO){
                    fseek(FL , (long)J*sizeof(LIB) , SEEK_SET);
                    fread(&X , sizeof(X) , 1 , FL );
                    fread(&Y , sizeof(Y) , 1 , SEEK_SET );
            }}


    fclose(FL);


    		if ( (FL = fopen("BIBLIOTECA","rb")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;
    		}



    fread( &LIB ,sizeof(LIB) , 1 , FL );


    while(!feof(FL)) {

            if(LIB.STATUS != '0'){
                VECES = NUMVECES ( LIB.CODIGO , FL1 );
                 if ( VECES > MAXVECES ) {
					 MAXVECES = VECES ;
                    MAXLIB = LIB.CODIGO ;
                  }

            }rewind(FL);



			fread ( &LIB , sizeof(LIB) , 1 , FL);

	}

	/*fclose(FL) , fclose(FL1) ;*/


	    if(!( FL = fopen("BIBLIOTECA" , "r+b" ))){
        printf("\nERRO AL ABRIR ARCHIVO AUXILIAR USUARIO");
        exit(1);
    }

    fread ( &LIB , sizeof(LIB) , 1 , FL);

    while(!feof(FL)){

        if(MAXLIB==LIB.CODIGO){

            printf("\n\t%d\t\t %s\t\t %s\t\t %s\t\t %c\t %d\n");
        }

        fread ( &LIB , sizeof(LIB) , 1 , FL);

    }

    fclose(FL) , fclose(FM) , fclose(FU) ;




    printf("\n\n\n\n   FIN DEL PROGRAMA\n\n");
    getchar() ;



}


int NUMVECES (int LEC, FILE *LB ){

    int NUM=0;
    struct LIBRO LIB;

    rewind(LB);
        fread(&LIB,sizeof(LIB),1,LB);
            while(!feof(LB)){
                if(LIB.LECTOR==LEC)
                    NUM++;
                    fread(&LIB,sizeof(LIB),1,LB);
            }
    return NUM;
}











