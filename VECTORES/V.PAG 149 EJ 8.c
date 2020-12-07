

/*  VECTORES  */
/*  EJERCICIO 8 PAG 149    */

#include<stdio.h>
#define N 10

void MOSTRAR ( int[] , char[] , float[] , int);
void ACCESO ( int[] , char[] , float[] , int , char);
int BUSCAR (char [] ,float [],int[], int , char);

int main()
{
    int CUENTA [N]= {458,321,744,228,349,201,198,705,789,227};
    char TIPO [N]=  {'B','A','C','C','B','A','C','A','B','C'};
    float SALDO[N]= {458.32,105.00,750.00,250.00,633.50,\
                        129.00,732.40,900.00,498.99,867.66};
     char C;

    MOSTRAR(CUENTA,TIPO,SALDO,N);
    printf("\n\n\nNUMERO DE CUENTA A CONSULTAR = ");
    scanf("%c",&C);
    ACCESO(CUENTA,TIPO,SALDO,N,C);
}
void MOSTRAR(int CUENTA[] , char TIPO [] , float SALDO [] , int L)
{


int I;
printf("\n\t\t  CUENTA  \t  TIPO  \t   SALDO\n\n");

for(I=0; I<L ; I++)
    printf("\n%25d%14c%20.2f",CUENTA[I],TIPO[I],SALDO[I]);

}

//ACCEDE A LA BUSQUEDA Y MUESTRA SI LA CUENTA NO EXISTE//

void ACCESO(int CUENTA[] , char TIPO [] , float SALDO [] , int L , char C)
{
    int R;
   int POS;
   POS=BUSCAR(TIPO,SALDO,CUENTA,L,C);

   if (POS<0)
    printf("\n\n\nNUMERO DE CUENTA INEXISTENTE");

}
//IMPRIME LA/LAS POSICION/ES DE LA CUENTA BUSCADA O -1 //

int BUSCAR(char TIPO[] ,float SALDO[] , int CUENTA[] , int L , char CE)
{
    int I,CONT=0;

    for(I=0 ; I<L ; I++)
        if( TIPO [I]==CE)
            {
                printf("\n\n\n");
                printf("%25d%14c%20.2f",CUENTA[I],TIPO[I],SALDO[I]);
                CONT++;
            }

        if(CONT==0)
        {
            return -1;

        }






}












		/*   SWAPPING  */
			//	AUX   = V[PM];
				//V[PM] = V[PRIMERO];
			//	V[PRIMERO]  = AUX ;

      // }





