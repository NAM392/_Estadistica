#include<stdio.h>
#include<string.h>


struct INGRESO{
        int LEGAJO;
        char CARRERA [20];

};
struct EXAMEN{
    int LEGAJO;
    int NOTA;

};

int main()
{

    struct INGRESO INI;
    struct EXAMEN EXA;


    FILE*FI;
    FILE*FE;

    int i=0;


    if(!(FI = fopen("INGRESO.DAT" , "wb"))){
            printf("escritura de ingreso no valida");
       }

    for (i=0 ; i<6 ; i++){

        fflush(stdin);
        printf("ingrese legajo  ");
        scanf("%d" , &INI.LEGAJO);
        printf("INGRESE CARRERA  ");
        fflush(stdin);
        gets(INI.CARRERA );
        fwrite(&INI , sizeof(INI) , 1 , FI);
    }


    fclose(FI);


    if(!(FE = fopen("EXAMEN.DAT" , "wb"))){
        printf("escritura examen no valida ");
    }

    printf("segundo archivo");

    fflush(stdin);
    for(i=0 ; i<6 ; i++){
        printf("\ningrese legajo  ");
        fflush(stdin);
        scanf("%d" , &EXA.LEGAJO);
        printf("\ningrese nota  ");
        fflush(stdin);
        scanf("%d" , &EXA.NOTA);
        fwrite(&EXA , sizeof(EXA) , 1 , FE);
    }

    fclose(FE);















}
