#include<stdio.h>
#include<string.h>

struct SUPER {
    char NOMBRES[20];
    long int DNI;
    int PUNTOS;


};
int main()
{
    struct SUPER SUP;
    FILE*SP;


    SP = fopen("supermercado.dat" , "rb");
    fread(&SUP , sizeof(SUP) , 1 , SP);
   while(!feof(SP)){
        printf(" \n %s   %d   %d \n" , SUP.NOMBRES , SUP.DNI , SUP.PUNTOS);
        fread(&SUP , sizeof(SUP) , 1 , SP);



    }






















}

