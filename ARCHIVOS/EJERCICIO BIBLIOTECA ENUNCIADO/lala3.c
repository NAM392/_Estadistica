
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
    int cont=0;

   FILE*FU;
   FILE*FM;

   if(!(FU=fopen("USUARIOS" , "rb" ))){
    printf("error al abrir usu");
   }
   if(!(FM=fopen("MOVIMIENTOS" , "rb"))){
    printf("error al abrir movi");
   }

   fread(&MOVI , sizeof(MOVI) , 1 , FM);
   fread(&USU , sizeof(USU) , 1 , FU );

   while(!feof(FM)){
    if(MOVI.OPERACION != '0'){
        while(!feof(FU)){
            if(USU.LECTOR == MOVI.LECTOR){
                cont++;
            }
            fread(&USU , sizeof(USU) , 1 , FU );


            if(cont==2){
                printf("\t%s\n" , USU.NOM );
            }

        }
        rewind(FU);
    }
       fread(&MOVI , sizeof(MOVI) , 1 , FM);


   }





















    printf("\n\n\n\n   FIN DEL PROGRAMA\n\n");
    getchar() ;
}
