#include<stdio.h>

#define N 11
int main()
{
    int VEC[N];
    int I,J;
    int cont=0;
    int MAYOR=0;
    int AUX;
    int POS=0;

    VEC[0]=1;
    VEC[1]=8;
    VEC[2]=1;
    VEC[3]=2;
    VEC[4]=5;
    VEC[5]=10;
    VEC[6]=100;
    VEC[7]=7;
    VEC[8]=7;
    VEC[9]=100;
    VEC[10]=100;


    for(I=0 ; I<N-1 ; I++)
        for(J=0 ; J<N-I-1 ; J++)
            if(VEC[J] < VEC[J+1]){

                    AUX         =   VEC[J];
                    VEC[J]      =   VEC[J+1];
                    VEC[J+1]    =   AUX;

            };



    for(I=1 ; I<N ; I++){

         if(VEC[I] == VEC[I-1]){
                cont++;
            if( MAYOR < cont){

                MAYOR   = cont;
                  POS   =  I;
                }
           }
         else {cont=0;};

     }

     printf("\n\n\tel numero que mas se repite es %d\n\n",VEC[POS]);







}

