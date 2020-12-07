#include<stdio.h>
#include<string.h>

struct INGRESO {
    int LEGAJO;
    char CARRERA [20];

};

struct EXAMEN {
    int LEGAJO;
    int EXAMEN;

};

int NUMVECES(char[20] , FILE* );

int main()
{
    struct EXAMEN EXA;
    struct INGRESO INI , AUX ;

    FILE*FI;
    FILE*FE;
    FILE*FAUX;
    int VECES=0;
    int MAX=0;
    char MAX_CARRERA[20];

    if(!(FI = fopen("INGRESO.DAT" , "rb"))){
        printf("apertura ingreso inva");
    }
    if(!(FE = fopen("EXAMEN.DAT" , "rb"))){
        printf("apertura examen inv");
    }
    if(!(FAUX = fopen("INGRESO.DAT" , "rb"))){
        printf("2da apartura arch ingreso");
    }

    fread(&INI , sizeof(INI) , 1 , FI);
    fread(&AUX , sizeof(AUX) , 1 , FAUX);

    while(!feof(FI)){
        VECES = NUMVECES(INI.CARRERA , FAUX);
        if (MAX < VECES){
            MAX = VECES;
            strcpy(MAX_CARRERA , INI.CARRERA);
        }
        fread(&INI , sizeof(INI) , 1 , FI);
        fread(&AUX , sizeof(AUX) , 1 , FAUX);

    }

    printf("la carrera con mas ingresantes es %s \n" , MAX_CARRERA);


    fclose(FI) , fclose(FAUX);

}

int NUMVECES(char carrera[20] , FILE*FI)
{
    struct INGRESO INI;
    int cont = 0;
    rewind(FI);
    fread(&INI , sizeof(INI) , 1 , FI);

    while(!feof(FI)){
        if(strcmp(carrera , INI.CARRERA)==0){
            cont++;
        }
        fread(&INI , sizeof(INI) , 1 , FI);
    };

    return cont;

}
