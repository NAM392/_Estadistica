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





int main(){



    struct LIBRO LIB ;

    FILE*FL;


        if ( !(FL = fopen("BIBLIOTECA","rb"))) {
			printf("\n\n   ERROR APERTURA DE LA BASE DE DATOS" );
			exit(1);
	}

    fread ( &LIB , sizeof(LIB) , 1 , FL);
	while ( ! feof(FL)) {
			printf("\n\n %5d  %s   %s  %s  %c  %d" ,
			LIB.CODIGO , LIB.TITULO , LIB.AUTOR , LIB.TEMATICA , LIB.STATUS , LIB.LECTOR  );
			fread ( &LIB , sizeof(LIB) , 1 , FL);
	}







    printf("\n\n\n\n   FIN DEL PROGRAMA\n\n");

}

