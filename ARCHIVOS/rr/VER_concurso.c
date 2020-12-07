#include<stdio.h>
#include<string.h>

struct LLAMADA {
    char nombre[20];
};


int main()
{
    struct LLAMADA nl;
    FILE * FLL;

    if(!(FLL = fopen("llamadas.dat" , "rb"))){
        printf("error al abrir archivo");
    }

    printf("nombre de votantes ");
    fread(&nl , sizeof(nl) , 1 ,FLL);
    while(!feof(FLL)){
        printf("\n  %s  \n" , nl.nombre);
        fread(&nl , sizeof(nl) , 1 , FLL);
    }




















}
