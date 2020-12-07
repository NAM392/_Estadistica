#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5

#define T 99

  void CARGAR(char[][T],int,int);
  void ORDENAR(char[][T],int,int);
  void MOSTRAR(char[][T],int,int);







int main()
{
    char PALABRA[N][T];
    CARGAR(PALABRA,N,T);
    ORDENAR(PALABRA,N,T);
    MOSTRAR(PALABRA,N,T);



}
void CARGAR(char MAT[][T] , int L , int K)
{
    int I;

    for(I=0 ; I<L ; I++)
    {
        printf("palabra %3d : ",I+1);
        gets(MAT[I]);

    }


}
ORDENAR(char MAT[][T] , int L , int K)
{


    int I,J;
    char AUX[K];

     for(I=0 ; I<L-1 ; I++)
        for(J=0 ; J<L-I-1 ; J++)
            if(strcmp(MAT[J],MAT[J+1]) > 0)
            {
               strcpy(AUX  , MAT[J] );
               strcpy(MAT[J], MAT[J+1]);
               strcpy(MAT[J+1] , AUX  );
            }



}


MOSTRAR(char MAT[][T] , int L , int K)
{
    int I;
      printf("\n\n vector ordenado \n") ;
     for(I=0 ; I<L ; I++)
          printf("\n%s",MAT[I]);
     printf("\n\nfin del programa");



}

