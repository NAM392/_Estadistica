



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


    struct MOVIMIENTO MOVI;
    struct USUARIO USU;
    struct LIBRO LIB ;

    int I , J , K;
    char NOMBRE [20];

    FILE*FM;
    FILE*FL;
    FILE*FU;
    FILE*LM;

    int cont_romantico , cont_terror ;


    /*   1.   MOSTRAR EN PANTALLA LOS 3 ARCHIVOS  */


   /*APERTURA Y MUESTRA DE ARCHIVOS*/

    	if ( !(FM = fopen("MOVIMIENTOS","rb"))) {
			printf("\n\n   ERROR APERTURA DE LA BASE DE DATOS" );
			exit(1);
    	};

        if ( !(FL = fopen("BIBLIOTECA","rb"))) {
			printf("\n\n   ERROR APERTURA DE LA BASE DE DATOS" );
			exit(1);
    	};



    fread ( &MOVI , sizeof(MOVI) , 1 , FM);
    fread ( &LIB , sizeof(LIB) , 1 , FL);





            /*EMPIEZO A RECORRER LOS MOVIMIENTOS*/

        while ( ! feof(FL)) {

                while(!feof(FM)) {

                    if ( MOVI.OPERACION != '0' ) {
                        if (!strcmp(LIB.TEMATICA , "TERROR")) {
                            cont_terror++;
                        }

                        if (!strcmp(LIB.TEMATICA , "NOVELA ROMANTICA") ) {
                            cont_romantico++;
                        }
                    }
               fread ( &MOVI , sizeof(MOVI) , 1 , FM);

            }
    fread ( &LIB , sizeof(LIB) , 1 , FL);
        }


    if(cont_romantico > cont_terror){
        printf("NOVELA ROMANTICA ES EL GENERO MAS POPULAR %d", cont_romantico );
    }
    else {
        printf("TERROR ES EL GENERO MAS POPULAR %d", cont_terror );
    }


    fclose(FL) , fclose(FM)  ;

}


