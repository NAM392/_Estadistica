#include <stdio.h>

int main ()

{
   int NUM,DIV,PRIMO;
   int CONTP=0;

   for(NUM=1000;NUM<10000;NUM++){

                            PRIMO=1;

                            for(DIV=2;DIV<NUM;DIV++){

                                if(!(NUM%DIV)){
                                    PRIMO=0 ; }
                                                    };

                            if (PRIMO){
                                       CONTP++;
                            printf("%8d",NUM);

                                      }

                            };

                             printf("\nPRIMOS\n %d",CONTP);

   }

