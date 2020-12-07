#include<stdio.h>
#include<string.h>

struct INGRESO {
    int LEGAJO ;
    char CARRERA[20];

};

struct EXAMEN {
    int LEGAJO;
    int NOTA;

};

int main()
{

    struct INGRESO INI;
    struct EXAMEN EXA;

    FILE*FE;
    FILE*FI;


    if(!(FI = fopen("INGRESO.DAT" , "rb"))){
        printf("lectura de archivos erronea");
    }
    if(!(FE = fopen("EXAMEN.DAT" , "rb"))){
        printf("error al abrir examen");
    }

    fread(&INI , sizeof(INI) , 1 , FI);
    fread(&EXA , sizeof(EXA) , 1 , FE);

    printf("\n LEGAJO \t CARRERA ");
    while(!feof(FI)){
        printf("\n %d  \t  %s " , INI.LEGAJO , INI.CARRERA);
        fread(&INI , sizeof(INI) , 1 , FI);
    }
    fclose(FI);
    printf("\n\n\n LEGAJO \t NOTA ");
    while(!feof(FE)){
        printf("\n %d \t %d " , EXA.LEGAJO , EXA.NOTA);
        fread(&EXA , sizeof(EXA) , 1 , FE);
    }

    fclose(FE);









}
