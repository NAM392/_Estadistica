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

    struct EXAMEN EXA;
    struct INGRESO INI , IN2;
    struct AUXILIAR AUX;

    FILE*FE;
    FILE*FI , *FA2;
    FILE*FAUX;

    FAUX = fopen("INGRESO.DAT" , "rb");
    FE = fopen("EXAMEN.DAT" , "rb");
    FI = fopen("INGRESO.DAT" , "rb");
    FA2 = fopen("AUXILIAR.DAT" , "wb");

    char aux[20];

    fread(&INI , sizeof(INI), 1 , FI);
    fread(&IN2 , sizeof(IN2), 1 , FAUX);
    fread(&EXA , sizeof(EXA), 1 , FE);


    while(!feof(FI)){ ///legajo, carrera medico
        strcpy(aux , INI.CARRERA);
        rewind(FAUX);
        fread(&INI , sizeof(INI) , 1 , FAUX);
        while(!feof(FAUX)){ ///legajo, carrera medico , psiquiatra
            if(strcmp(aux , INI.CARRERA)==0){
                fread(&EXA , sizeof(EXA) , 1 , FE);
                while(!feof(FE)){
                    if(INI.LEGAJO == EXA.LEGAJO && EXA.NOTA >= 6){
                        strcpy(AUX.CARRERA , aux);
                        AUX.NOTA = EXA.NOTA;
                        fwrite(&AUX , sizeof(AUX) , 1 , FA2);
                        }
                    fread(&EXA , sizeof(EXA) , 1 , FE);

                }
                rewind(FE);

            }
            fread(&INI , sizeof(INI) , 1 , FAUX);
        }
        rewind(FAUX);
        fread(&INI , sizeof(INI) , 1 , FI);

    }

    fclose(FI) ,  fclose(FE) , fclose(FAUX) , fclose(FA2);

    FA2 = fopen("AUXILIAR.DAT" , "rb");
    fread(&AUX , sizeof(AUX) , 1 , FAUX);

    while(!feof(FA2)){
        printf(" \n  %s   %d  \n" , AUX.CARRERA , AUX.NOTA);
        fread(&AUX , sizeof(AUX) , 1 , FA2);
    }



}

