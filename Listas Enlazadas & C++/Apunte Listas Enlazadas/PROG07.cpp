//MANEJO DE UNA PILA COMPACTA



#include<iostream>
#include<conio.h>

#define MAX 10
#define MENU getch() ;  std::cout << "\n\n\n\t\t\t0\tSALIR " ; \
            std::cout << "\n\n\n\t\t\t1\tPONER\n\n\n\t\t\t2\t SACAR\n\n\n";


class PILA {
            int VEC [MAX] ;            /*DATOS PRIVADOS*/
            int * P ;
  public:
        void Inicializar (void) ;      /*FUNCIONES PUBLICAS*/
        void PUSH (int) ;
        void PULL (void) ;


};

PILA pila ;

void poner() ;
void sacar () ;

int main (void)
{

    int SELEC = 1 ;

    pila.Inicializar();

    //clrscr();

    while(SELEC){
        MENU ;
        std::cin >> SELEC ;
        switch (SELEC) {
                case 1 : poner() ; break ;
                case 2 : sacar () ; break ;
                };
    }


}

void poner()
{
    PILA Pila ;
    int DATO;
    std::cout << "\nIngrese un entero " ;
    std::cin >> DATO ;
    Pila.PUSH (DATO );


}
void sacar()
{
    PILA Pila ;
    std::cout << "\nDato = " << Pila.PULL () ;
}
void PILA::Inicializar()
{
    PILA Pila ;
    P=VEC;
}
void PILA::PUSH (int DATO )
{
    if ( P >= VEC + MAX )
        std::cout << "\nDesborde de pila .\nDato perdido.\n" ;
    else {
        *P = DATO ;
         P++;
    }
}
int PILA::PULL ()
{
    if(P <= VEC ){
        std::cout << "\nPila vacia.\nDato nulo .\n" ;
        return 0;
    }
    P--;
    return *P ;
}
