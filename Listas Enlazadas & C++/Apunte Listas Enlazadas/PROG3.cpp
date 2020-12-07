//USO DE MANIPULADORES


#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<iomanip>

int main()                      //NO ME FUNCIONA CUANDO ESCRIBO void main  ()
{
    //clrscr();         //NO RECONOCE ESTA FUNCION

    int OCTAL;
    std::cout << "ingrese un entero octal \n" ;
    /* std::cin >> oct >> OCTAL ;                        NO FUNCIONA oct , hex , dec */

    int I;
    std::cout << "ingrese un entero decimal \n" ;
    std::cin  >> "%d" >> I ;                                    //PROBANDO PORQUE NO ANDA

    int H;
    std::cout << "ingrese un entero hexadecimal \n" ;
    std::cin >> hex >> I ;

    float F;
    std::cout << "ingrese un flotante \n" ;                 //SI O SI TENGO QUE PONER std:: ANTES DE CIN O  COUT
    std::cin >> F ;

    char C;
    std::cout << "ingrese un entero hexadecimal \n" ;
    std::cin >> C ;

    long L;
    std::cout << "ingrese un long \n" ;
    std::cin >> L ;

    int H;
    std::cout << "ingrese un entero hexadecimal \n" ;
    std::cin >> hex >> I ;

}
