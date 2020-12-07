#include<stdio.h>
#include<string.h>

struct INGRESO {
    int LEGAJO;
    char CARRERA[20];
};

struct EXAMEN {
    int LEGAJO;
    int NOTA;
};
struct AUXILIAR {
    int NOTA;
    char CARRERA[20];
};



int main()
{

    struct INGRESO INI , INI2;
    struct EXAMEN EXA;



    FILE*FI;
    FILE*FE;
    FILE*FAUX;

    int cont = 0 , veces = 0 , MAX=0;
    char max_carrera[20];
    char aux[20];

    if(!(FI = fopen("INGRESO.DAT" , "rb"))){
        printf("acceso invalido ingreso");
    }
    if(!(FE = fopen("EXAMEN.DAT" , "rb"))){
        printf("acceso invalido examen");
    }
    if(!(FAUX = fopen("INGRESO.DAT" , "rb"))){
        printf("acceso invalido ingreso");
    }

    fread(&EXA , sizeof(EXA) , 1 , FE);
    fread(&INI , sizeof(INI) , 1 , FI);
    fread(&INI2 , sizeof(INI2) , 1 , FAUX);

    while(!feof(FI)){ ///legajo, carrera medico
        strcpy(aux , INI.CARRERA);
        rewind(FAUX);
        fread(&INI , sizeof(INI) , 1 , FAUX);
        while(!feof(FAUX)){ ///legajo, carrera medico , psiquiatra
            if(!strcmp(aux , INI.CARRERA)){
                rewind(FE);
                fread(&EXA , sizeof(EXA) , 1 , FE);
                while(!feof(FE)){
                    if(INI.LEGAJO == EXA.LEGAJO && EXA.NOTA >= 6){
                        cont++;
                        }
                    fread(&EXA , sizeof(EXA) , 1 , FE);

                }
            }
            fread(&INI , sizeof(INI) , 1 , FAUX);
        }

        if(cont > MAX){
            MAX = cont;
            strcpy(max_carrera , aux);
        }
        cont = 0;

        fread(&INI , sizeof(INI) , 1 , FI);

    }

    printf("%s   %d ", max_carrera , MAX);


























}

