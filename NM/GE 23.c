#include <stdio.h>
#include<math.h>
int FERMAT(int,int);
int main()

{

    int A,P,Y;

    for(A=2;A<9;A++)
    {
        for(P=3;P<8;P=P+2)
        {

            Y=FERMAT(A,P);
        };



    };



    if(Y%P==0)
    {
        printf("SE CUMPLE EL TEOREMA  ");
    };





    }

    int FERMAT(int J,int K)
    {
        int X,Y;
        X=pow(J,K);
        Y=X-J;
        return Y;



    }
