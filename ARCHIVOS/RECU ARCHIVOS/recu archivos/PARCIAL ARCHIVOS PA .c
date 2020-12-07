#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct INGRESO{
    int LEGAJO;
    char CARRERA[20];

};

struct EXAMEN {
    int LEGAJO;
    int NOTA;
};

int NUMVECES(char[] , FILE*);

int main(){

    struct INGRESO INI , X , Y ;

    FILE*FI;

    FILE*AUX;

    char MAX_CARRERA[20];
    int VECES , MAX_VECES , N ;

    if(!(FI = fopen("INGRESO" , "rb" ))){
        printf("error al abrir ingreso");
    }

    fread(&INI , sizeof(INI) , 1 , FI);
    fread(&INI , sizeof(INI) , 1 , AUX);

    fseek(FI , 0L , SEEK_END);

    N = ftell(FI)/sizeof(INI);

    for(I=0 ; I<N-1 ; I++)
        for(J=0 ; J<N-I-1 ; J++){
            fseek(FI , (long)J*sizeof(INI) , SEEK_SET);
            fread(&X , sizeof(X) , 1 , FI);
            fread(&Y , sizeof(Y) , 1 , FI);

            if((strcmp(X.CARRERA , Y.CARRERA )>0)){
                fseek(FI , (long)J*sizeof(INI) , SEEK_SET);
                fwrite(&Y , sizeof(Y) , 1 , FI);
                fwrite(&X , sizeof(X) , 1 , FI);

            }
    }
    fclose(FI);

    if(!(FI = fopen("INGRESO" , "rb"))){
        printf("error al abrir ingreso");
    }

    fread(&INI , sizeof(INI) , 1 , FI);

    while(!feof(FI)){
        VECES = NUMVECES(INI.CARRERA , AUX);
        if(MAXVECES < VECES){
            MAXVECES = VECES;
            strcpy(MAX_CARRERA , INI.CARRERA);
        }
        fread(&INI , sizeof(INI) , 1 , FI);
    };

    printf("la carrera con mas ingresos fue %s con %d alumnos " , MAX_CARRERA , MAX_VECES);
    fclose(FI) , fclose(AUX) ;
}
