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
    struct USUARIO USU;

    FILE*FL;
    FILE*FU;
    char NOMBRE[20];

    if(!(FL=fopen("BIBLIOTECA" , "rb"))){
        printf("error al abrir archivo lib");
    };
    if(!(FU=fopen("USUARIOS" , "rb"))){
        printf("error al abrir usu");
    };

    printf("ingrese nombre ");
    gets(NOMBRE);
    fread(&LIB , sizeof(LIB) , 1 , FL);
    fread(&USU , sizeof(USU) , 1 , FU);

    while(!feof(FL)){
        if(LIB.STATUS != '0'){
            while(!feof(FU)){
                if (!strcmp(USU.NOM , NOMBRE )){
                    printf("\t %s \n",LIB.TITULO);
                }
                fread(&USU , sizeof(USU) , 1 , FU );
            }
        }        fread(&LIB , sizeof(LIB) , 1 , FL);
    }

    fclose(FL) , fclose(FU) ;



    /*   2.   INGRESAR EL NOMBRE DE UN CLIENTE E INDICAR QUE LIBROS   */
    /*        TIENE EN ESTE MOMENTO                                   */










    printf("\n\n\n\n   FIN DEL PROGRAMA\n\n");
    getchar() ;
}
