#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define E 4

struct examen{
    char alumno[50];
    unsigned int notas [4];

};

void muestra_examenes(struct examen [] , int );


int main()
{
    struct examen exa[E];

    int I , J ;
    int cont;

    for(I=0 ; I<E ; I++){
        printf("ingrese nombre del alumno  : ");
        fflush(stdin);
        gets(exa[I].alumno);

        cont =1 ;
        for(J=0 ; J<4 ; J++){
            printf("ingrese nota %d  : " , cont);
            scanf("%u",&exa[I].notas[J]);
            cont ++ ;
        }
    }


    muestra_examenes(exa , E );

}

void muestra_examenes(struct examen exa [] , int VE)
{

    float NOTAS;
    int I , J ;
    float X;

    for(I=0 ; I<VE ; I++){
            NOTAS=0;
        for(J=0 ; J<4 ; J++){

            NOTAS = exa[I].notas[J] + NOTAS ;

        }
        X=NOTAS / 4 ;

        if (X >= 8.5 ){
            printf("alumno %s APROBADO DISTINGUIDO %f\n\n", exa[I].alumno ,NOTAS/4);
        }
        else if (X >=6 ){

                printf("alumno %s APROBADO\n%f \n\n", exa[I].alumno , X) ;

                }
            else {printf("alumno %s DESAPROBADO \n%f\n\n", exa[I].alumno , NOTAS/4 ) ; };




}
}

