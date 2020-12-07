#include <stdio.h>
int sumar ( int , int );
int restar ( int , int );

int main()
{





    int a , b , i ;
    int (*p[])( ) = { sumar , restar } ;

    scanf("%d %d" , &a , &b);  /*INGRESO DE DATOS*/
    do{
        printf("\n\n INGRESE OPCION. 0-SUMAR   1-RESTAR\n");
        scanf("%d",&i);
     } while ((i != 0 )&& (i!=1)) ;
     printf("\n\n RESULTADO  = %d " ,  (*p[i])(a,b) );

}

int sumar ( int x , int y)
{  return x+y ;}

int restar ( int x , int y)
{   return x-y ; }
