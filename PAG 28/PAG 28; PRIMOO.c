#include <stdio.h>

int main ()

{
   int NUM,DIV,PRIMO;

   for(NUM=2;NUM<10000;NUM++){

    PRIMO=1;

    for(DIV=2;DIV<NUM;DIV++){

        if(!(NUM%DIV)){
            PRIMO=0 ; }
                              };

        if (PRIMO){
            printf("%8d",NUM);
        };

    };


   }

