
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

struct MAS_DE_DOS{
                 int LECTOR ;
                 int CODIGO ;

};






int main(){


    struct MOVIMIENTO MOVI;
    struct USUARIO USU;
    struct LIBRO LIB ;
    struct MAS_DE_DOS MAS , X , Y ;

    int I , J , K , N ;

    FILE*FM;
    FILE*FL;
    FILE*FU;
    FILE*MD;



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


/*   3.   MOSTRAR LOS DATOS DE LOS CLIENTES QUE TENGAN MAS DE 2 LIBROS  */

/*REINICIAMOS LOS ARCHIVOS*/

	printf("\n\n\n\n    CREANDO AL ARCHIVO MAS DOS ...");
	printf("\n\n\n");

	if ( !(MD = fopen("MAS_DOS","wb"))) {
			printf("\n\n   ERROR CREACION ARCHIVO DE M2 " );
			exit(1);
	}


    rewind(FU);
    rewind(FL);
    rewind(FM);


    fread ( &LIB , sizeof(LIB) , 1 , FL);
    fread ( &USU , sizeof(USU) , 1 , FU);

    while(!feof(FL)){
        if(LIB.STATUS != 0 ){
            fread ( &LIB , sizeof(LIB) , 1 , FL);
            while ( ! feof(FL)) {
                LIB.LECTOR = MAS.LECTOR ;
                LIB.CODIGO = MAS.CODIGO ;
                fwrite ( &MAS , sizeof(MAS) , 1 , MD);
                fread ( &LIB , sizeof(LIB) , 1 , FL);
            }

        }

    }

    fclose(MD);


    	printf("\n\n\n\n    ORDENANDO EL ARCHIVO DE INDICES ...");
	printf("\n\n\n");

	if ( !(MD = fopen("MAS_DOS","r+b"))) {
			printf("\n\n   ERROR APERTURA ARCHIVO DE m2" );
			exit(1);
	}

	fseek(MD , 0L , SEEK_END);
	N = ftell(MD)/sizeof(MAS) ;
	printf("\n\n\n  EL ARCHIVO DE INDICES TIENE %d REGISTROS" , N );

	for ( I = 0 ; I < N-1 ; I++ )
			for ( J = 0 ; J < N-I-1 ; J++ )  {
				 fseek( MD , (long)J*sizeof(MAS) , SEEK_SET );
				 fread ( &X , sizeof(X) , 1 , MD);
				 fread ( &Y , sizeof(Y) , 1 , MD);
				 if ( X.CODIGO > Y.CODIGO ) {
				 		fseek( MD , (long)J*sizeof(MAS) , SEEK_SET );
				 		fwrite ( &Y , sizeof(Y) , 1 , MD);
				 		fwrite ( &X , sizeof(X) , 1 , MD);
				 }
			}

	fclose(MD);
    fclose(FU);
    fclose(FL);
    fclose(FM);

    fread ( &MAS , sizeof(MAS) , 1 , MD ) ;
    fread ( &USU , sizeof(USU) , 1 , FU ) ;

		while ( ! feof(MD)){
                while (! feof(FU)){

                        if ( MAS.LECTOR == USU.LECTOR )  {
                            fseek ( FU , (long)USU.LECTOR*sizeof(USU) , SEEK_SET);
                            fread ( &USU , sizeof(USU) , 1 , FU);
                            printf("\n\n %10d %-10s %-20d" ,
                            USU.LECTOR , USU.NOM , USU.TE );
                        }

                        fread ( &USU , sizeof(USU) , 1 , FU ) ;
                }



				fread ( &MAS , sizeof(MAS) , 1 , MD ) ;
		}

    fclose(MD) , fclose(FU);














	/*	fread ( &X , sizeof(X) , 1 , FP ) ;
		while ( ! feof(FP) ) {
				if ( X.SEX == 'F' )  {
						X.EDAD = 2 * X.EDAD  ;
						fseek ( FP , (long)(-1)*sizeof(X) , SEEK_CUR );
						fwrite ( &X , sizeof(X) , 1 , FP ) ;
						fseek ( FP , 0L , SEEK_CUR );
				}

				fread ( &X , sizeof(X) , 1 , FP ) ;
		}



	fclose(IX) ;



    */












    printf("\n\n\n\n   FIN DEL PROGRAMA\n\n");

}




