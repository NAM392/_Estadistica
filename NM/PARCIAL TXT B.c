#include<stdio.h>

int main()

{

    int NUM,DIV,PRIMO,PAR;

    printf("ingrese un numero par  ");
    scanf("%d",&PAR);


   for(NUM=3;NUM<PAR;NUM++){

    PRIMO=1;

    for(DIV=2;DIV<NUM;DIV++){

        if(!(NUM%DIV)){
            PRIMO=0 ; }
                              };

        if (PRIMO){

            if (NUM + (!(NUM)) == PAR){printf("%d + %d = %d",NUM,NUM,PAR);};
        };

    };


   }

