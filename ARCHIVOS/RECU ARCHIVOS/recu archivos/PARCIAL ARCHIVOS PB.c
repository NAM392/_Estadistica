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

int numveces(char[] , FILE*);

int main()
{

    struct ingreso ini;
    struct examen exa;
    int veces , maxveces = 0;
    char max_inscriptos[20];

    FILE*FI;
    FILE*FE;
    FILE*aux;

    if(!(FI = fopen("INGRESO.DAT" , "rb"))){
        printf("\nerror al abrir archivo ingreso");
    }
    if(!(FE = fopen("EXAMEN.DAT" , "rb"))){
        printf("\nerror al abrir archivo examen");
    }

    if(!(aux = fopen("INGRESO.DAT" , "rb"))){
        printf("\nerror al abrir archivo ingreso");
    }

    fread(&ini , sizeof(ini) , 1 , FI);
    fread(&exa , sizeof(exa) , 1 , FE);
    fread(&ini , sizeof(ini) , 1 , aux);

    while(!feof(FE)){
        if(exa.nota >=6){
            while(!feof(FI)){
                veces = numveces(ini.carrera , aux);
                if(maxveces < veces){
                    maxveces = veces;
                    strcpy(max_inscriptos , ini.carrera);
                }
                fread(&ini , sizeof(ini) , 1 , FI);
            }
            rewind(FI);
        }
        fread(&exa , sizeof(exa) , 1 , FE );
    }

    printf("la carrera con mayor cantidad de ingresantes due %s con %d " , max_inscriptos , maxveces);

    fclose(FI) , fclose(aux);

}

int numveces(char ingreso[20] , FILE*P)
{
    int cont = 0;
    struct ingreso ini;
    rewind(P);
    fread(&ini , sizeof(ini ) , 1 , P);

    while(!feof(P)){
        if(!strcmp(ingreso , ini.carrera)){
            cont++;
        }
        fread(&ini , sizeof(ini) , 1 , P);
    }
    return cont;

}
