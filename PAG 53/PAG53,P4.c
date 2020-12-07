#include<stdio.h>
int main ()

{


    float TEMP,FAR_A_CEL,FAR_A_KEL,CEL_A_KEL,CEL_A_FAR,KEL_A_CEL,KEL_A_FAR,COMPKAF,COMPFAK;

    printf("TEMPERATURA=",TEMP);
    scanf("%f",&TEMP);
    FAR_A_CEL=TEMP*1.8+32;
    CEL_A_FAR=TEMP-32;
    KEL_A_FAR=TEMP-273.15;
    FAR_A_KEL=TEMP-32;
    KEL_A_CEL=TEMP-273.15;
    CEL_A_KEL=TEMP+273.15;
    COMPFAK=5/9;
    COMPKAF=9/5;

    printf("\n\n\t\tKelvin A Farenheit=%.2f F",KEL_A_FAR*COMPKAF);

    printf("\n\n\t\tFarenheit A Kelvin=%.2f K",FAR_A_KEL*COMPFAK+273.15);

    printf("\n\n\t\tCelsius A Farenheit=%.2f F",CEL_A_FAR);

    printf("\n\n\t\tFarenheit A Celsius=%.2f C",FAR_A_CEL);

    printf("\n\n\t\tCelsius A Kelvin=%.2f K",CEL_A_KEL);

    printf("\n\n\t\tKelvin A Celsius=%.2f C",KEL_A_CEL);


    return=0;






    printf("\n\n\n\n\n");














}
