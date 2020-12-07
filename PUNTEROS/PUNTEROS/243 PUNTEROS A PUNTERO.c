#include<stdio.h>
int main ()
{
    int A , *P , **PP ;
    A=10;
    P=&A;
    PP=&P;

    printf("%4d%4d%4d", A , *P , **PP );






}
