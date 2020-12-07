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


    SP = fopen("supermercado.dat" , "wb");

    for(int i=0 ; i<6 ; i++){
        printf("\n  ingrese nombre , dni , puntos  \n");
        fflush(stdin);
        gets(SUP.NOMBRES);
        scanf("%d" , &SUP.DNI);
        fflush(stdin);
        scanf("%d" , &SUP.PUNTOS);
        fflush(stdin);
        fwrite(&SUP , sizeof(SUP) , 1 , SP);




    }






















}
