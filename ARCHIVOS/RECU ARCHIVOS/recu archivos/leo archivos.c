#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct datos {
    char nombre[20];
    char sexo;
    int edad;
};


int main()
{
    struct datos ini;
    FILE*FI;
    int i;


    if(!(FI = fopen("DATOS.DAT" , "rb"))){
        printf("apertura de archivo invalida \n");
    }

    printf("\n\n \t\t\t  CONTENIDO DE arch \n\n");
    fread(&ini , sizeof(ini) , 1 , FI);
    while(!feof(FI)){
        printf("\n%10s%30c%10d" , ini.nombre , ini.sexo , ini.edad );
        fread(&ini , sizeof(ini) , 1 , FI);
    }
    fclose(FI);




}
