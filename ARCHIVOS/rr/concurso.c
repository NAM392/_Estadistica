#include<stdio.h>
#include<string.h>

struct LLAMADA{
    char nombre[20];

};





int main()
{


    struct LLAMADA nl;

    FILE * FLL;

    if(!(FLL = fopen("llamadas.dat" , "wb"))){
        printf("error al escribir");
    };

    for(int i=0 ; i<4; i++){
        gets(nl.nombre);
        fwrite(&nl , sizeof(nl) , 1 , FLL);
    }
    fclose(FLL);

}
