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
    int i;

    if(!(FE = fopen("EXAMEN.DAT" , "rb"))){
        printf("apertura de archivo invalida \n");
    }

    printf("\n \t\t\t  CONTENIDO DE EXAMEN \n\n");

    fread(&exa , sizeof(exa) , 1 , FE);
    while(!feof(FE)){
        printf("\n%10d%10d" , exa.legajo , exa.nota);
        fread(&exa , sizeof(exa) , 1 , FE);
    }
    fclose(FE);

    if(!(FI = fopen("INGRESO.DAT" , "rb"))){
        printf("apertura de archivo invalida \n");
    }

    printf("\n\n \t\t\t  CONTENIDO DE INGRESO \n\n");
    fread(&ini , sizeof(ini) , 1 , FI);
    while(!feof(FI)){
        printf("\n%10d%30s" , ini.legajo , ini.carrera );
        fread(&ini , sizeof(ini) , 1 , FI);
    }
    fclose(FI);




}
