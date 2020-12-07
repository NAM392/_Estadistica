



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

    /*   3.   MOSTRAR LOS DATOS DE LOS CLIENTES QUE TENGAN MAS DE 2 LIBROS  */


    struct MOVIMIENTO MOVI;
    struct USUARIO USU;
    struct LIBRO LIB ;

    int I , J , K ;
    char NOMBRE [20];

    FILE*FM;
    FILE*FL;
    FILE*FU;
    FILE*LM;

    int cont ;



		if ( !(FU = fopen("USUARIOS","rb"))) {
			printf("\n\n   ERROR APERTURA DE LA BASE DE DATOS" );
			exit(1);
        }

        if ( !(FL = fopen("BIBLIOTECA","rb"))) {
			printf("\n\n   ERROR APERTURA DE LA BASE DE DATOS" );
			exit(1);
        }


    fread ( &LIB , sizeof(LIB) , 1 , FL);
    fread ( &USU , sizeof(USU) , 1 , FU);


    printf("LISTA DE USUARIOS CON 2 O MAS LIBROS : ");


        while (! feof(FU)) {
            cont = 0;  /* SI NO DEJO EL CONT EN 0 A PARTIR DEL SIGUIENTE IMPRIMIRIA TODOS */
            while(!feof(FL)) {
                            if (USU.LECTOR == LIB.LECTOR ) {
                                cont ++ ;
                                if(cont==2){
                                printf("\n \t %s " , USU.NOM );
                                }
                            }
                            fread ( &LIB , sizeof(LIB) , 1 , FL);
                            }
                            /*cont = 0  ES LO MISMO */
                            rewind(FL);
                    fread ( &USU , sizeof(USU) , 1 , FU);
                        }

        fclose(FU) , fclose(FL) ;

}

