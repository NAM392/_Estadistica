#include <stdio.h>
#define N 10

void MOSTRAR ( int[] , char[] , float[] , int);
float MAYOR   ( float[] , int);

int main()
{
    int CUENTA [N]= {458,321,744,228,349,201,198,705,789,227};
    char TIPO [N]=  {'B','A','C','C','B','A','C','A','B','C'};
    float SALDO[N]= {458.32,105.00,750.00,250.00,633.50,\
                        129.00,732.40,900.00,498.99,867.66};


    MOSTRAR(CUENTA,TIPO,SALDO,N);
    int POS=MAYOR(SALDO,N);

     printf("\n\n\n");
       printf("%25d%14c%20.2f",CUENTA[POS],TIPO[POS],SALDO[POS]);


}
void MOSTRAR(int CUENTA[] , char TIPO [] , float SALDO [] , int L)
{


int I;
printf("\n\t\t  CUENTA  \t  TIPO  \t   SALDO\n\n");

for(I=0; I<L ; I++)
    printf("\n%25d%14c%20.2f",CUENTA[I],TIPO[I],SALDO[I]);

}
float MAYOR (float V [] ,  int L )
{
    int I , S=0;

    for(I=0 ; I<N ; I++)
    {

         if(V[I+1]>V[I])
                S=I+1;
    }
    return S;








}













