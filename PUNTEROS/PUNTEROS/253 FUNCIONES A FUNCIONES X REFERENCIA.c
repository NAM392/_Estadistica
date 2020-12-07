#include<stdio.h>

/*PROTOTIPOS*/
int suma (int , int , int(*)(int));
int cuadrado(int);
int cubo(int);

int main()
{

    int a , b , seleccion ;
    int(*p[2]) (int) ;
    p[0] = cuadrado;
    p[1] = cubo;
    printf("SUMA DE CUADRADOS : 0   SUMA DE CUBOS: 1 \n\n");

    /*MENU*/

    scanf("%d" , &seleccion );
    printf( "\n\n INGRESE DOS VALORES ");

    /*INGRESO DE DATOS */
    scanf("%d  %d  ", &a , &b);
    printf("\n\n\n RESULTADO = %d ", suma( a , b ,p[seleccion]));
}
/*FUNCIONES*/


int cuadrado ( int X )
{ return X*X ; }

int cubo(int X)
{return X*X*X ;}

int suma(int x , int y , int (*ptr)(int))
{ return (*ptr)(x) + (*ptr)(y) ;}








