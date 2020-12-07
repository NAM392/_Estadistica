#include<stdio.h>

int main()
{   char SEL,F,M;
    int NOT=0;
    int ACUMH=0;
    int ACUMF=0;
    int CONT=0;
    int CONTF=0;
    int CONTH=0;
    int V,J;



    while(CONT<8){

        printf("\n\t\t\t\t MENU \n\n\n");
        printf("\n\t\t\t\t 1. OPCION M ");
        printf("\n\t\t\t\t 1. OPCION F ");

        printf("\n\n\nINGRESE SU OPCION : ");
        scanf("%c %d",&SEL,&NOT);


        switch (SEL)
        {
            case 'M': ACUMH=ACUMH+NOT;
                      CONTH++;
               break;
            case 'F': ACUMF=ACUMF+NOT;
                     CONTF++;
                break;
            default: printf("\nUD.SELECCIONO OTRA COSA ");
                break;


        }
        CONT++;


    };


     V=ACUMH/CONTH;
     J=ACUMF/CONTF;

     if(V>J)
     {
         printf("LOS VARONES TIENEN MEJOR PROMEDIO %d  ",V);
     }
     else
     {
         printf("LAS MUJERES TIENEN MEJOR PROMEDIO %d  ",J);
     }














}

