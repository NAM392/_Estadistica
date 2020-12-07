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


        struct LIBRO LIB;

        FILE*FL;

        if(!(FL=fopen("BIBLIOTECA" , "rb" ))){
            printf("error al abrir archivo");
        }

        fread(&LIB , sizeof(LIB), 1 , FL );

        while(!feof(FL)){
            printf(" %d\t  %s \t %s\t  %s\t  %c\t  %d \n", LIB.CODIGO , LIB.TITULO , LIB.AUTOR , LIB.TEMATICA , LIB.STATUS , LIB. LECTOR );

            fread(&LIB , sizeof(LIB) , 1 , FL);
        }

        fclose(FL);
























    printf("\n\n\n\n   FIN DEL PROGRAMA\n\n");
    getchar() ;
}

