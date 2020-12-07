#include<stdio.h>

int main()

{  int D,M,A,F,_31,NUM;   /////reveer todo el puto codigo de mierda este

   D=1;

   M=1;

   A = 0;

   NUM=0;

   F=M==2;

   _31=M==1||M==3||M==5||M==7||M==8||M==10||M==12;

   printf("INGRESE FECHA CON FORMATO DD/M/AAAA \n\n");

   NUM= scanf("%d/%d/%d",&D,&M,&A);

   if (NUM==3){

 if(A>=1900 && A<=2100){

                if(M<=12) {

                            if (F){
                                       if(D>28){printf("EL DIA ES inCORRECTO C");};}
                             else{

                                        if (_31!=0){

                                             if (D<=31){printf("EL DIA ES CORRECTO A ");

                                                       }
                                               else {printf(" mal el dia a");};}

                                                 else if(M==4||M==6||M==9||M==11){


                                 if (D<=30){printf("EL DIA ES CORRECTO B");}


                                    else {printf("MAL 30");};            };


                                               ;}






                }
                else {printf("MAL MES");};

 }

 else {printf("MAL ANNI");};



 }


   else {printf("mal parametros");};



   }

