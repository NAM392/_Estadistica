#include<stdio.h>

int main()


{

   float AREA,RADIO,PI,DIAMETRO;
          PI=3.1415;
          printf("RADIO=");
          scanf("%f",&RADIO);
           DIAMETRO=RADIO*2;
          printf("\n\nDIAMETRO=%.1f",DIAMETRO);   //CALCULO AREA SCANF
          AREA=PI*RADIO*RADIO;
        printf("\t\t\t\n\n\nAREA=%.4f \t\n\n",AREA);
}
