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

int NUMVECES(char [] , FILE*);

int main()
{

    struct INGRESO INI ;
    struct EXAMEN EXA;
    struct AUXILIAR AUX , AUX2;


    FILE*FI;
    FILE*FE;
    FILE*FAUX;
    FILE*FAUX2;

    int cont = 0 , VECES = 0 , MAX=0;
    char max_carrera[20];


    if(!(FI = fopen("INGRESO.DAT" , "rb"))){
        printf("acceso invalido ingreso");
    }
    if(!(FE = fopen("EXAMEN.DAT" , "rb"))){
        printf("acceso invalido examen");
    }
    if(!(FAUX = fopen("auxiliar.DAT" , "wb"))){
        printf("acceso invalido ingreso");
    }

    fread(&EXA , sizeof(EXA) , 1 , FE);
    fread(&INI , sizeof(INI) , 1 , FI);

    while(!feof(FI)){
        fread(&EXA , sizeof(EXA) , 1 , FE);
        while(!feof(FE)){
            if(INI.LEGAJO == EXA.LEGAJO && EXA.NOTA >=6){
                strcpy(AUX.CARRERA , INI.CARRERA);
                AUX.NOTA = EXA.NOTA;
                fwrite(&AUX , sizeof(AUX) , 1 , FAUX);
            }
            fread(&EXA , sizeof(EXA) , 1 , FE);

        }
        rewind(FE);
        fread(&INI , sizeof(INI) , 1 , FI);

    }

    fclose(FAUX) , fclose(FE) , fclose(FI);



    if(!(FAUX = fopen("auxiliar.DAT" , "rb"))){
        printf("no abre auxiliar");
    }
    if(!(FAUX2 = fopen("auxiliar.DAT" , "rb"))){
        printf("no abre auxiliar2");
    }
    fread(&AUX , sizeof(AUX) , 1 , FAUX);
    fread(&AUX2 , sizeof(AUX2) , 1 , FAUX2);

    while(!feof(FAUX)){
            VECES = NUMVECES(AUX.CARRERA , FAUX2 );
        if(MAX<VECES){
            MAX = VECES;
            strcpy(max_carrera , AUX.CARRERA);
        }
        fread(&AUX , sizeof(AUX) , 1 , FAUX);
    };

    printf("\nla carrera con mayor cantidad de ingresantes es %s con %d ingresantes\n" , max_carrera , MAX);





}

int NUMVECES(char carrera[20] , FILE*FA)
{
    int cont=0;
    struct AUXILIAR AUX;
    rewind(FA);
    fread(&AUX , sizeof(AUX) , 1 , FA);

    while(!feof(FA)){
        if(!strcmp(carrera , AUX.CARRERA)){
            cont++;
        }
        fread(&AUX , sizeof(AUX) , 1 , FA);
    }

    return cont;





}
