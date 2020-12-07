#include<stdio.h>
#include<math.h>
int AMIGO_(int,int);

int main()
{
    int A,F,B;

    printf("ingrese numeros ");
    scanf("%d %d",&A,&F);

    B=AMIGO_(A,F);

    if (B==1)
    {
        printf("los numeros son amigos");
    }
    else
    {
        printf("los numeros no son amigos");
    };



}
int AMIGO_(int X,int Y)
{
    int DIV;
    int ACUMX=0;
    int ACUMY=0;
    int FLAG=0;

    for (DIV=1;DIV<X;DIV++)
    {

        if(X%DIV==0)
        {
            ACUMX=ACUMX+DIV;
        };

    };

    for (DIV=1;DIV<Y;DIV++)
    {
        if(Y%DIV==0)
        {
            ACUMY=ACUMY+DIV;
        };

    };


    if(ACUMY==X)
    {
        FLAG=1;
    }

    else
    {
        FLAG=0;
    };

    return FLAG;






}
