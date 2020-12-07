

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

    int I , J , K;
    char NOMBRE [20];

    FILE*FM;
    FILE*FL;
    FILE*FU;


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
		/*	printf("\n\n %5d  %s   %s  %s  %c  %d" ,
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






/*REINICIAMOS LOS ARCHIVOS*/
rewind(FU);
rewind(FL);
rewind(FM);
/*EMPEZAMOS A RECORRER DE 0*/
gets(NOMBRE);
fread ( &USU , sizeof(USU) , 1 , FU);
fread ( &LIB , sizeof(LIB) , 1 , FL);
fread ( &MOVI , sizeof(MOVI) , 1 , FM);
/*RECORRO PRIMER ARCHIVO DE USUARIO*/
	while ( ! feof(FU)) {
    /* COMPARO NOMBRE RECIBIDO CON TODOS LOS USUARIO*/
	if (! strcmp(NOMBRE ,  USU.NOM)){
            /*EMPIEZO A RECORRER LOS MOVIMIENTOS*/
        while ( ! feof(FM)) {
            /*COMPARO CODIGO DE LECTOR DE USUARIO CON EL CODIGO DEL LECTOR DEL MOVIENTO*/
            if(USU.LECTOR == MOVI.LECTOR){
                /*DISTINTO DE 0 POR QUE NO SABEMOS LO QUE RECIBIMOS*/
                if(MOVI.OPERACION != '0'){
                    /*EMPIEZO A RECORRER LOS LIBROS*/
                    while ( ! feof(FL)) {
                        /*COMPARO CODIGO DE LIBRO QUE TIENE MOVIENTO CON EL CODIGO DE LIBRO*/
                        if(MOVI.CODIGO == LIB.CODIGO){
                            printf("   %s   \n", LIB.TITULO);
                        }
                        fread ( &LIB , sizeof(LIB) , 1 , FL);
                    }
                    /*AL TERMINAR DE RECORRER HAY QUE REINICIARLO PARA DAR OTRA VUELTA Y PREGUNTAR POR LOS SIGUIENTES*/
                    rewind(FL);
                }
            }

            fread ( &MOVI , sizeof(MOVI) , 1 , FM);
        }
        rewind(FM);

	}

	fread ( &USU , sizeof(USU) , 1 , FU);
	}







}
