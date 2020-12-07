#include <stdio.h>
#define N 10

void MOSTRAR ( int[] , char[] , float[] , int);
void ORDENAR(int [],char[], float [],int);

int main()
{
    int CUENTA [N]= {458,321,744,228,349,201,198,705,789,227};
    char TIPO [N]=  {'B','A','C','C','B','A','C','A','B','C'};
    float SALDO[N]= {458.32,105.00,750.00,250.00,633.50,\
                        129.00,732.40,900.00,498.99,867.66};

        ORDENAR(CUENTA,TIPO,SALDO,N);
        MOSTRAR(CUENTA,TIPO,SALDO,N);

}
void MOSTRAR(int CUENTA[] , char TIPO [] , float SALDO [] , int L)
{


    int I;
    printf("\n\t\t  CUENTA  \t  TIPO  \t   SALDO\n\n");

    for(I=0; I<L ; I++)
    printf("\n%25d%14c%20.2f",CUENTA[I],TIPO[I],SALDO[I]);

    printf("\n\n\n");

}
void ORDENAR(int CUENTA[],char TIPO [], float SALDO [],int L)
{

    int I,J;

    int AUXINT ;
    char AUXCHAR ;
    float AUXFLOAT ;

    for(I=0 ; I<L-1 ; I++)
        for(J=0 ; J<L-I-1 ; J++)
             if(SALDO[J] < SALDO[J+1])
                {

                    //swapping//

                    AUXINT = CUENTA [J];
                    CUENTA[J] = CUENTA[J+1];
                    CUENTA[J+1]=AUXINT;

                    //ARRASTRE DE TIPO//
                    AUXCHAR = TIPO[J];
                    TIPO[J] = TIPO[J+1];
                    TIPO[J+1] = AUXCHAR;

                    //ARRASTRE DE SALDO//
                    AUXFLOAT = SALDO[J];
                    SALDO[J] = SALDO[J+1];
                    SALDO[J+1] = AUXFLOAT;
                }



                for(I=0 ; I<L ; I++)

                    if(SALDO[I]>500)

                    printf("\n%25d%14c%20.2f",CUENTA[I],TIPO[I],SALDO[I]);





}

