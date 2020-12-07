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

int MAXVECES(int , FILE*);



int main(){

    /*   4.   DETERMINAR CUAL ES EL LIBRO DE MAYOR USO (CANTIDAD DE PRESTAMOS) */


    struct MOVIMIENTO MOVI;
    struct LIBRO LIB;

    int VECES , MAXMOVI=0 , MAXLIBRO=0 ;

    FILE*FL;
    FILE*FM;
    FILE*FAUX;

    if(!(FL=fopen("BIBLIOTECA" , "rb"))){
        printf("error al abrir biblio");
    }

    if(!(FM=fopen("MOVIMIENTOS" , "rb"))){
        printf("error al abrir movi");
    }

    if(!(FAUX=fopen("MOVIMIENTOS" , "rb"))){
        printf("error al abrir aux");
    }


    fread(&MOVI , sizeof(MOVI), 1 , FM);
    fread(&LIB , sizeof(LIB) , 1 , FL);
    fread(&MOVI , sizeof(MOVI) , 1 , FAUX);


    while(!feof(FM)){
        if(MOVI.OPERACION != '0'){
            while(!feof(FL)){

                VECES = MAXVECES(MOVI.CODIGO , FAUX );
                if(VECES>MAXMOVI){
                    MAXMOVI=VECES;
                    MAXLIBRO=MOVI.CODIGO;
              }

                fread(&LIB , sizeof(LIB) , 1 , FL);
            }
            rewind(FL);
        }
        fread(&MOVI , sizeof(MOVI), 1 , FM);
    }



    rewind(FL);
    fread(&LIB , sizeof(LIB) , 1 , FL);
    while(!feof(FL)){
        if(MAXLIBRO==LIB.CODIGO){
            printf("\t\n%s\t %d\n",LIB.TITULO , MAXMOVI );
        }
       fread(&LIB , sizeof(LIB) , 1 , FL);

    }

    fclose(FL) , fclose(FM) , fclose(FAUX) ;




    printf("\n\n\n\n   FIN DEL PROGRAMA\n\n");
    getchar() ;
}
int MAXVECES(int LALA , FILE*puntero)
{
    int cont=0;
    struct MOVIMIENTO MOVI;

    rewind(puntero);
    fread(&MOVI , sizeof(MOVI) , 1 , puntero );
    while(!feof(puntero)){
        if(LALA==MOVI.CODIGO){
            cont++;
        }
        fread(&MOVI , sizeof(MOVI) , 1 , puntero );
    }

    return cont;


}

