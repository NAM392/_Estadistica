#include<stdio.h>

int main()

{

    float NOTAS,CONT,SUMA,PROMEDIO;

   NOTAS=0;


                while(NOTAS>=0){

                printf("INGRESE NOTAS \n\n");
                scanf("%f",&NOTAS);

                    CONT++;
                    SUMA=SUMA+NOTAS;
                };

                PROMEDIO=SUMA/CONT;

                if(PROMEDIO>=4){
                    printf("el promedio es %f el alumno aprobo",PROMEDIO);
                }
                else {printf(" el promedio es %f el alumno desaprobo",PROMEDIO);};










}
