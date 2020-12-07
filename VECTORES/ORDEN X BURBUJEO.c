/*ordena los vectores en base al campo clave y cuenta*/

/*los vectores tipo y saldo son arrastrados*/


void ORDENAR(int CUENTA[],char TIPO [], float SALDO [],int L)
{

    int I,J;

    int AUXINT ;
    char AUXCHAR ;
    float AUXFLOAT ;

    for(I=0 ; I<L-1 ; I++)
        for(J=0 ; J<L-I-1 ; J++)
             if(CUENTA[J] > CUENTA[J+1])  /*ORDEN DE MENOR A MAYOR*/
                {

                    /*swapping*/

                    AUXINT = CUENTA [J];
                    CUENTA[J] = CUENTA[J+1];
                    CUENTA[J+1]=AUXINT;

                    /*ARRASTRE DE TIPO*/
                    AUXCHAR = TIPO[J];
                    TIPO[J] = TIPO[J+1];
                    TIPO[J+1] = AUXCHAR;

                    /*ARRASTRE DE SALDO*/
                    AUXFLOAT = SALDO[J];
                    SALDO[J] = SALDO[J+1];
                    SALDO[J+1] = AUXFLOAT;
                }





}
