#include<stdio.h>
int PRIMO(int,int);


int main()
{

    int X,Y,CONT;

    printf("INGRESE RANGO ");
    scanf("%d %d",&X,&Y);

    CONT=PRIMO(X,Y);

    printf("HAY UN TOTAL DE %d NUMEROS PRIMOS",CONT);






}

int PRIMO(int X, int Y)
{

    int NUM,DIV,PRIMO;
    int CONTP=0;

   for(NUM=X;NUM<Y;NUM++)
    {

    PRIMO=1;

    for(DIV=2;DIV<NUM;DIV++){

        if(!(NUM%DIV)){
            PRIMO=0 ; }
                              };

        if (PRIMO)
        {
        CONTP++;
        };

    };


    return CONTP;



};
