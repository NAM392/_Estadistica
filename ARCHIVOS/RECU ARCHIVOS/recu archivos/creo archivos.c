
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct datos {
    char nombre[20];
    char sexo;
    int edad;
};


int main(){

struct datos datos;
FILE*puntero;
int i , N;

if(!(puntero = fopen("DATOS.DAT" , "wb"))){
    printf("error apertura de archivo \n\n");
    return 1;
}

printf("indique cuantos datos ingresara = ");
scanf("%d" ,&N);

for(i=0 ; i<N ; i++){
    printf("\nNOMBRE , SEXO Y EDAD \n");
    fflush(stdin);
    gets(datos.nombre);
    datos.sexo = getchar();
    scanf("%d" , &datos.edad);
    fwrite(&datos , sizeof(datos) , 1 , puntero);
}

fclose(puntero);



}
