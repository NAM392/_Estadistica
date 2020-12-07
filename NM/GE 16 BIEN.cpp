#include <stdio.h>

int main ()

{
   int NUM,DIV,PRIMO;
   int LALA=0;
   int CONTP=0;
   int CONTR=0;



while(!(LALA<1000&&LALA>10000||CONTR==1)){

   printf("INGRESE NUMERO \t");
   scanf("%d",&LALA);

   for(NUM=1000;NUM<10000;NUM++){

                            PRIMO=1;

                            for(DIV=2;DIV<NUM;DIV++){


                                if(!(NUM%DIV)){
                                    PRIMO=0 ; }
                                                    };

                            if (PRIMO){
                                       if (LALA==NUM){
                                        CONTR=CONTR+1;}
                                        else{
                                            CONTR-1;

                                            }


                                       };}
                                       ;

                                      };
                                       printf("\t\n %d 4 DIGITOS PRIMO",LALA);


}





