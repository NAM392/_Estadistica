//USO DE MANIPULADORES

#include<iostream>
#include<conio.h>
#include<iomanip>

int main()
{
    //clrscr();

    int I , J ;

    float mat [3][4] ;

    for( I=0 ; I<3 ; I++)
        for( J=0 ; J<4 ; J++ ){
            std::cout << "\n ingrese el numero " << I << "  " << J  ;
            std::cin >> mat[I][J] ;
        }

    std::cout << std::setfill('-') ;
    std::cout << std::setprecision(2) ;
   // std::cout << std::setiosflags ( std::ios_base ) ;     NO ENCUENTRO FORMA DE HACER FUNCIONAR RESTA LINEA

    for(I=0 ; I<3 ; I++){
        std::cout << std::endl << std::endl << "\t" ;
        for(J=0 ; J<4 ; J++)
            std::cout << " " << std::setw(12) << mat[I][J] ;

    }

    std::cout << "\n\n\n\n" ;
    getch();




}
