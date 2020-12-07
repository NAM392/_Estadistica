/*PILA.c*/

#include<stdio.h>
#include<conio.h>

#define N 10
#define MENU printf("\n\n\t\t1.PONER DATO \
                      \n\t\t2.SACAR DATO\
                      \n\t\t0.SALIR " ) ;

/*PROTOTIPOS*/
void PUSH(int);
int PULL (void);
void MIRAR(void);
void PONER(void);
void SACAR(void);

/*VARIABLES GLOBALES*/
int VEC[N] , *SP ;

int  main()
{

    char SEL ;
    SP = VEC;

    do {
        /*clrscr();*/
        MENU;
        printf("\n\n\n INGRESE OPCION : ");
        scanf("%d" , &SEL);
        switch (SEL) {
                case 1: PONER() ; break ;
                case 2: SACAR() ; break ;
                case 3: MIRAR() ; break ;
                }
    }while(SEL);
}
void PONER()
{

    int NUM;
    /*clrscr();*/
    printf("INGRESE UN VALOR ENTERO : ");
    scanf("%d" , &NUM );
    PUSH(NUM);
    getch();
}
void SACAR()
{
    /*clrscr();*/
    printf("\nEL VALOR OBTENIDO ES %d \n " , PULL() );
    getch();
}
void PUSH(int NUM)
{
    if (SP < VEC+N){
        *SP = NUM ;
        SP++;
    }
    else
        printf("PILA LLENA . OPERACION CANCELADA . \n\n");
}
int PULL()
{
    if( SP == VEC ){
        printf("PILA VACIA . \n EL VALOR RETORNADO NO ES VALIDO ");
        return 0;
    }
    else {
        SP -- ;
        return *SP ;
    }

}

void MIRAR()
{
    int *P ;
    /*clrscr();*/
    printf("CONTENIDO DE LA PILA \n");
    for (P = VEC ; P<SP ; P++)
        printf("\n %d" , *P);
    getch();

}
