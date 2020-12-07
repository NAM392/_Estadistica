#include<stdio.h>

struct FECHA{
int DIA ;
int MES ;
int ANIO;
};

//prototipo de la funcion
struct FECHA corregir(struct FECHA) ;

int main (void)
{

    struct FECHA HOY ;
    printf("ingrese la fecha con formato DD-MM-AAAA\t");
    scanf("%d-%d-%d",&HOY.DIA , &HOY.MES , &HOY.ANIO) ;

    HOY = corregir(HOY) ;

    printf("\n\nFECHA CORRECTA  :  ");
    printf("%02d-%02d-%02d",HOY.DIA , HOY.MES , HOY.ANIO) ;



}

struct FECHA corregir(struct FECHA DIA)
{
    if(DIA.DIA==29 && DIA.MES == 2){

        DIA.DIA=3;
        DIA.MES=1;
    }
    return DIA ;


};
