
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


int main(){


    struct MOVIMIENTO MOVI;
    struct USUARIO USU;
    struct LIBRO LIB ;

    int I , J , K , MAXVECES , VECES ;
    char NOMBRE [20];

    FILE*FM ;
    FILE*FM1 ;
    FILE*FL;
    FILE*FU;
    int MAX_CODIGO;


    /*   1.   MOSTRAR EN PANTALLA LOS 3 ARCHIVOS  */


   /*APERTURA Y MUESTRA DE ARCHIVOS*/

   	if ( !(FM = fopen("MOVIMIENTOS","rb"))) {
			printf("\n\n   ERROR APERTURA DE LA BASE DE DATOS" );
			exit(1);
    	}

		if ( !(FU = fopen("USUARIOS","rb"))) {
			printf("\n\n   ERROR APERTURA DE LA BASE DE DATOS" );
			exit(1);
	}

        if ( !(FL = fopen("BIBLIOTECA","rb"))) {
			printf("\n\n   ERROR APERTURA DE LA BASE DE DATOS" );
			exit(1);
	}

    fread ( &LIB , sizeof(LIB) , 1 , FL);
	while ( ! feof(FL)) {
			/*printf("\n\n %5d  %s   %s  %s  %c  %d" ,
			LIB.CODIGO , LIB.TITULO , LIB.AUTOR , LIB.TEMATICA , LIB.STATUS , LIB.LECTOR  );*/
			fread ( &LIB , sizeof(LIB) , 1 , FL);
	}





    fread ( &USU , sizeof(USU) , 1 , FU);
	while ( ! feof(FU)) {
          /* MOSTRE DATOS DE UN USUARIO PARA INGRESARLO DE FORMA MAS FACIL

          if(USU.LECTOR == 6512){
                printf("\n\n %10d %-10s  %5d" ,
                USU.LECTOR , USU.NOM , USU.TE );
			}*/
			fread ( &USU , sizeof(USU) , 1 , FU);
	}



    fread ( &MOVI , sizeof(MOVI) , 1 , FM);
	while ( ! feof(FM)) {
			/*printf("\n\n %d \t%d\t %c \n" ,
			MOVI.LECTOR , MOVI.CODIGO , MOVI.OPERACION );*/
			fread ( &MOVI , sizeof(MOVI) , 1 , FM);
	}





/*   2.   INGRESAR EL NOMBRE DE UN CLIENTE E INDICAR QUE LIBROS   */
/*        TIENE EN ESTE MOMENTO                                   */


	/*BUSQUEDA DEL NOMBRE*/

	printf("ingrese nombre");
	gets(NOMBRE);

/*REINICIAMOS LOS ARCHIVOS*/
rewind(FU);
rewind(FL);
rewind(FM);
/*EMPEZAMOS A RECORRER DE 0*/
fread ( &USU , sizeof(USU) , 1 , FU);
fread ( &LIB , sizeof(LIB) , 1 , FL);
/*RECORRO PRIMER ARCHIVO DE USUARIO*/
	while ( ! feof(FU)) {
    /* COMPARO NOMBRE RECIBIDO CON TODOS LOS USUARIOS */
	if (! strcmp(NOMBRE ,  USU.NOM)){
            /*EMPIEZO A RECORRER LOS MOVIMIENTOS*/
        while ( ! feof(FL)) {
            /*COMPARO CODIGO DE LECTOR DE USUARIO CON EL CODIGO DEL LECTOR DEL MOVIENTO*/
            if(USU.LECTOR == LIB.LECTOR){
                /*DISTINTO DE 0 POR QUE NO SABEMOS LO QUE RECIBIMOS*/
                if(LIB.STATUS != '0'){
                        printf("   %s   \n", LIB.TITULO);
                    }
                }
                fread ( &LIB , sizeof(LIB) , 1 , FL);
            }
             rewind(FL);
        }

        fread ( &USU , sizeof(USU) , 1 , FU);
	}


	fclose(FU);

	fclose(FL);

	fclose(FM);




    printf("\n\n\n\n   FIN DEL PROGRAMA\n\n");

}



