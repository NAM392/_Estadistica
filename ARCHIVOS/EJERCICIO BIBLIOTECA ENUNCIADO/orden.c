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

    struct USUARIO USU , X , Y ;
    int N , I , J ;
    FILE*FU;

    if(!(FU=fopen("USUS" , " r+b "))){
        printf("error al abrir usus1");
    }

    fread(&USU , sizeof(USU) , 1 , FU );
    fseek(FU , 0L , SEEK_END );
    N=ftell(FU)/sizeof(USU) ;
    printf("el archivo usus tiene %d archivos\n",N);

    for(I=0 ; I<N-1 ; I++)
            for(J=0 ; J<N-I-1 ; J++){
                fseek(FU , (long)J*sizeof(USU) , SEEK_SET );
                fread(&X , sizeof(X) , 1 , FU);
                fread(&Y , sizeof(Y) , 1 , FU);
                if( strcmp(X.NOM , Y.NOM )>0 ){
                    fseek(FU , (long)J*sizeof(USU) , SEEK_SET);
                    fwrite(&Y , sizeof(Y) , 1 , FU);
                    fwrite(&X , sizeof(X) , 1 , FU);
                               }
        }
        fclose(FU);
        if(!(FU=fopen("USUS" , "rb"))){
            printf("error al abrir usu2");
        }
       fread(&USU , sizeof(USU) , 1 , FU);
       while(!feof(FU)){
            printf("\t \n %d \t %s \t %d \n" , USU.LECTOR , USU.NOM , USU.TE );
            fread(&USU , sizeof(USU) , 1 , FU);
        }

        fclose(FU);

    printf("\n\n\n\n   FIN DEL PROGRAMA\n\n");
    getchar() ;
}

