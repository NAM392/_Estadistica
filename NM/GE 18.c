#include <stdio.h>

int main ()

{

    int ING,DIV,perf,ACUM;

    for(ING=3;ING<200;ING++)
    {
        for(DIV=3;DIV<ING;DIV++)
        {
           if(ING%DIV==0)
           {
               ACUM=ACUM+DIV;
           };

        }
        perf=ACUM-ING;
        printf("%8d",perf);

        if(perf==ING){

            printf("%8d",perf);
        }


    }











}





