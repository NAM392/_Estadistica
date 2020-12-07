#include<stdio.h>
#include<math.h>
unsigned long int POTEN(int,int);


int main()
{
    int x,y;
    unsigned long int P;

    printf("ingrese dos numeros  ");
    scanf("%d %d",&x,&y);

    P=POTEN(x,y);


    printf("la potencia es %d",P);



}

unsigned long int POTEN(int X, int Y)
{
    unsigned long int p;
    p= pow(X,Y);

    return p;


}


