


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

    int MAXLIB , VECES , MAXVECES ;


    /*   1.   MOSTRAR EN PANTALLA LOS 3 ARCHIVOS  */


   /*APERTURA Y MUESTRA DE ARCHIVOS*/

    	if ( !(FM = fopen("MOVIMIENTOS","rb"))) {
			printf("\n\n   ERROR APERTURA DE LA BASE DE DATOS" );
			exit(1);
    	};


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

fread ( &LIB , sizeof(LIB) , 1 , FL);
fread ( &MOVI , sizeof(MOVI) , 1 , FM);

if ( !(LM = fopen("MOVIMIENTOS","rb"))) {
			printf("\n\n   ERROR SEGUNDA APERTURA DE LA BASE DE DATOS" );
			exit(1);
	}

            /*EMPIEZO A RECORRER LOS MOVIMIENTOS*/

        while ( ! feof(FM)) {
                /*DISTINTO DE 0 POR QUE NO SABEMOS LO QUE RECIBIMOS*/
                if(MOVI.OPERACION != '0'){
                    /*EMPIEZO A RECORRER LOS LIBROS*/
                        while(!feof(FL)) {
                            VECES = NUMVECES ( MOVI.CODIGO , LM );
                                if ( VECES > MAXVECES ) {
                                    MAXVECES = VECES ;
                                    MAXLIB = MOVI.CODIGO ;
                                }
                            fread ( &LIB , sizeof(LIB) , 1 , FL);
                            }
                        rewind(FL);
                        }
                    fread ( &MOVI , sizeof(MOVI) , 1 , FM);
                }
    rewind(FL);
    fread(&LIB , sizeof(LIB) , 1 , FL );
    while(!feof(FL)){
        if( MAXLIB==LIB.CODIGO){
            printf("EL LIBRO ES %s QUE SE REPITE %d " , LIB.TITULO , MAXVECES );

        }

        fread(&LIB , sizeof(LIB) , 1 , FL );


    }


    fclose(FU) , fclose(FM) , fclose(FL) ;

}

int NUMVECES (int LEC, FILE *FM ){
    int NUM=0;
    struct MOVIMIENTO MOVI;
    rewind(FM);
    fread(&MOVI,sizeof(MOVI),1,FM);
    while(!feof(FM)){
        if(MOVI.CODIGO == LEC){
            NUM++;
            }
        fread(&MOVI,sizeof(MOVI),1,FM );
    }
    return NUM;
}

