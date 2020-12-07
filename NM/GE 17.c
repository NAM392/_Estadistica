#include <stdio.h>

int main ()

{


   int ING;
   int NUM=0;
   int cont=0;
   int acum=0;
   int perf=0;



   printf("\t\nINGRESE NUMERO \t");
   scanf("%d",&ING);



for(NUM=1;NUM<20000;NUM++){


    if(ING%NUM==0){

            acum=acum+NUM;
                   };

                            };

    perf=acum-ING;


    if (perf==ING){

    printf("%d ES PERFECTO",perf);
                  }
    else{
       printf("NO ES PERFECTO");
    };



}




