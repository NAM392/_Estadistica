
//MANEJO DE UNA PILA COMPACTA USANDO CONSTRUCTOR



#include<iostream>
#include<conio.h>

#define MAX 10
#define MENU getch() ;  std::cout << "\n\n\n\t\t\t0\tSALIR " ; \
            std::cout << "\n\n\n\t\t\t1\tPONER\n\n\n\t\t\t2\t SACAR\n\n\n";


class PILA {
            int VEC [MAX] ;            /*DATOS PRIVADOS*/
            int * P ;
  public:
        PILA (void) ;       /* CONSTRUCTOR */
        void PUSH (int) ;
        int  PULL (void) ;


};

PILA pila ;

void poner() ;
void sacar () ;

int main (void)
{

    int SELEC = 1 ;

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
    PILA Pila;
    int DATO;
    std::cout << "\nIngrese un entero " ;
    std::cin >> DATO ;
    Pila.PUSH (DATO);


}
void sacar()
{
    PILA Pila;
    std::cout << "\nDato = " << Pila.PULL () ;
}
 PILA::PILA()
{
    //PILA Pila;
    std::cout << "\nConstructor en accion.\n" ;
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
