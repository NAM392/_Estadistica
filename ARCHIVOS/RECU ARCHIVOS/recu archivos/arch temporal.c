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

    FILE*FI;
    FILE*FE;
    FILE*tmp;
    FILE*aux;

    if(!(FE = fopen("EXAMEN.DAT" , "rb"))){
        printf("apertura de archivo invalida \n");
    }

    if(!(FI = fopen("INGRESO.DAT" , "rb"))){
        printf("apertura de archivo invalida \n");
    }

    if((tmp = tmpfile() )== NULL){
        printf("error al crear temporal");
    }

    fread(&ini , sizeof(ini) , 1 , FI);
    fread(&exa , sizeof(exa) , 1 , FE);

    while(!feof(FI)){
            while(!feof(FE)){
                if(ini.legajo == exa.legajo){
                    fwrite(&exa , sizeof(exa) , 1 , FE);
                }
                fread(&exa , sizeof(exa) , 1 , FE);
            }
            fread(&ini , sizeof(ini) , 1 , FI);
    }
    fclose(FE) , fclose(FI);

    rewind(tmp);

    if(!(aux = fopen("auxiliar.DAT" , "wb"))){
        printf("apertura de archivo invalida \n");
    }

    fread(&exa , sizeof(exa) , 1 , tmp);
    while(!feof(tmp)){
        fwrite(&exa, sizeof(aux) , 1 , aux);
        fread(&exa , sizeof(exa) , 1 , tmp);
    }










}
