#include<stdio.h>
#include<conio.h>


class CLASE{
           struct ESTRUCTURA{
                    int A ;
                    float B; } ;
           struct ESTRUCTURA DATO ;        //DATO PRIVADO
           void DOBLAR(void);              //FUNCION PRIVADA
 public:
        int N;                             //DATO PUBLICO
        void MIRAR (void);                 //FUNCIONES PUBLICAS
        void CARGAR (int , float );
        void DUPLICAR (void);
};

void CLASE::CARGAR(int X , float Y)
{
    DATO.A = X;
    DATO.B = Y;
}

void CLASE::MIRAR()
{
    printf("\n\n MOSTRANDO VALORES");
    printf("\n%d\t%f" , DATO.A , DATO.B );

}

void CLASE::DOBLAR()
{
    DATO.A *= 2 ;
    DATO.B *= 2 ;
}
void CLASE::DUPLICAR ()
{
    DOBLAR();
}

int main(void)
{

    CLASE OBJETO ;              // DECLARACION DE OBJETOS

    int ENTERO;
    float REAL;

    //clrscr();
    fflush(stdin);

   // OBJETO.DATO = 2;                                   /*1*/
    // da que CLASE::DATO no es accesible en funcion main

    printf("\n\n INGRESE EL NUMERO DE REPETICIONES \n\n");
    scanf("%d" , &(OBJETO.N) );    //se accede porque es publico

    printf("\n\n INGRESE UN VALOR ENTERO Y UNO REAL \n\n");

    OBJETO.CARGAR(ENTERO , REAL );

    //OBJETO.DOBLAR () ;                                    /*2*/
    //da que CLASE::DOBLAR() no es accesible desde la funcion main

        OBJETO.DUPLICAR();

        for(int I=0 ; I < OBJETO.N ; I++)
            OBJETO.MIRAR();

        getch();



}
