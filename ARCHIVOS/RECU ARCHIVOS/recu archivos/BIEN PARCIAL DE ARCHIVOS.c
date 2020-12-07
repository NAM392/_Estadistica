#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ingreso {
    int legajo;
    char carrera[20];
};

struct examen{
    int legajo;
    int nota;
};


int main()
{
    struct ingreso ini;
    struct examen exa;
    FILE*FE;
    FILE*FI;
    FILE*AUX;


    if(!(FE=fopen("EXAMEN.DAT" , "rb"))){
        printf("error apertura examen");
    };

    if(!(FI=fopen("INGRESO.DAT" , "rb"))){
        printf("error apertura ingreso");
    };

    if(!(AUX=fopen("INGRESO.DAT" , "rb"))){
        printf("error 2da apertura ingreso");
    };


    fread(&ini , sizeof(ini) , 1 , FI);
    fread(&exa , sizeof(exa) , 1 , FE);
    fread(&ini , sizeof(ini) , 1 , AUX);


}
