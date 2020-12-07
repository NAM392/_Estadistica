#include<stdio.h>

int main()

{
    float TOTAL,POR,DESC,PANT,LIST;
    printf("INGRESE TOTAL DE FACTURA=");
    scanf("%f",&TOTAL);
    printf("INGRESE PORCENTAJE A DESCONTAR=");
    scanf("%f",&DESC);

   LIST=DESC/100;

   POR=TOTAL*LIST;

   PANT=TOTAL-POR;

    printf("EL PRECIO FINAL ES %.2f",PANT);







}
