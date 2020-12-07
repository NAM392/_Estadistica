#include<stdio.h>

int main()


{

    float PRECIO,CLIENTE,VUELTO,RESTO;

    PRECIO=0;
    CLIENTE=0;
    RESTO=0;


    int CONT1,CONT50,CONT25,CONT10;

    CONT1=0;
    CONT50=0;
    CONT25=0;
    CONT10=0;



    printf("INGRESE PRECIO CON FORMATO $.$ \t\n");
    scanf("%f",&PRECIO);

    printf("INGRESE $ ENTREGADO POR EL CLIENTE\t\n");
    scanf("%f",&CLIENTE);

    VUELTO = CLIENTE-PRECIO;
    RESTO= CLIENTE-PRECIO;

    while(VUELTO>1 ){

             CONT1++;

             VUELTO --;



          };

          while(VUELTO>=0.5){

            CONT50++;

            VUELTO = VUELTO-0.5;
          };


        while (VUELTO>=0.25){

        CONT25++;
        VUELTO=VUELTO - 0.25;
        };



          while(VUELTO>=0.1){

         CONT10++;
        VUELTO= VUELTO - 0.1;};




         printf("EL PRECIO FUE %.2f Y VUELTO %.2f\n",PRECIO,RESTO);

           printf("SE ENTREGARON %d MONEDAS DE 1 PESO \n %d MONEDAS DE 50c \n %d MONEDAS DE 25c \n %d MONEDAS DE 10c \n\n ",CONT1,CONT50,CONT25,CONT10);


};



