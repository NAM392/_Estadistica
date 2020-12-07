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

int main()
{
    struct EXAMEN EXA;
    struct INGRESO INI;

    FILE*FI;
    FILE*FE;

    char carrera[20];
    int cont_carrera = 0;
    int cont_examen = 0;
    int cont_aprobado=0;

    if(!(FI = fopen("INGRESO.DAT" , "rb"))){
        printf("apertura ingreso invalida");
    }
    if(!(FE = fopen("EXAMEN.DAT" , "rb"))){
        printf("apertura examen invalida");
    }

    fread(&EXA , sizeof(EXA) , 1 , FE);


    /*ALUMNOS QUE SE INSCRIBIERON A :*/

    printf("ingrese la carrera a buscar  ");
    gets(carrera);
    fread(&INI , sizeof(INI) , 1 , FI);
    while(!feof(FI)){

        if(strcmp(INI.CARRERA , carrera)==0){
            cont_carrera++;
        }
        fread(&INI , sizeof(INI) , 1 , FI);
    }
    printf("\n en la carrera %s hay %d alumnos que se inscribieron \n" , carrera , cont_carrera);

    rewind(FE);
    rewind(FI);

    fread(&INI , sizeof(INI) , 1 , FI);

    while(!feof(FI)){
        if(strcmp(carrera , INI.CARRERA)==0){
            fread(&EXA , sizeof(EXA) , 1 , FE);
            while(!feof(FE)){
                if(INI.LEGAJO == EXA.LEGAJO){
                    cont_examen++;
                }
                fread(&EXA , sizeof(EXA) , 1 , FE);
            }
            rewind(FE);
        }
        fread(&INI , sizeof(INI) ,1 , FI);
    }

    printf("\n en la carrera %s ingresaron %d alumnos de los cuales rindieron el examen %d alumnos  \n" , carrera , cont_carrera , cont_examen);


    rewind(FE);
    rewind(FI);

    fread(&INI , sizeof(INI) , 1 , FI);
    while(!feof(FI)){
        if(!strcmp(carrera , INI.CARRERA)){
            fread(&EXA , sizeof(EXA) , 1 , FE);
            while(!feof(FE)){
                if(INI.LEGAJO == EXA.LEGAJO && EXA.NOTA >= 6){
                        cont_aprobado++;

                }
                fread(&EXA , sizeof(EXA) , 1 , FE);
            }
            rewind(FE);
        }
        fread(&INI , sizeof(INI) , 1 , FI);
    }

    printf("\n en la carrera %s ingresaron %d alumnos de los cuales aprobaron %d \n" ,carrera , cont_carrera , cont_aprobado );








}
