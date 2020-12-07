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

int main(){

    struct examen exa;
    struct ingreso ini;
    FILE*FE;
    FILE*FI;
    int i , N;

    if(!(FI = fopen("INGRESO.DAT" , "wb"))){
        printf("error apertura de archivo \n\n");
        return 1;
    }

    printf("indique cuantos datos ingresara = ");
    scanf("%d" ,&N);

    for(i=0 ; i<N ; i++){
        printf("\nLEGAJO  Y CARRERA \n");
        fflush(stdin);
        scanf("%d" , &ini.legajo);
        fflush(stdin);
        gets(ini.carrera);
        fwrite(&ini , sizeof(ini) , 1 , FI);
    }
    fclose(FI);

    if(!(FE = fopen("EXAMEN.DAT" , "wb"))){
        printf("error apertura de archivo \n\n");
        return 1;
    }

    for(i=0 ; i<N ; i++){
        printf("\nLEGAJO Y NOTA \n");
        fflush(stdin);
        scanf("%d" , &exa.legajo);
        scanf("%d" , &exa.nota);
        fwrite(&exa , sizeof(exa) , 1 , FE);
    }
    fclose(FE);



}
