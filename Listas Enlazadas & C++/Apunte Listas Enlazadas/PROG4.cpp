
//ANCHOS Y RELLENOS

#include<iostream>
#include<conio.h>
#include<iomanip>

int main ()
{
    //clrscr();

    char mat [3][4][10] ;

    for(int I=0 ; I<3 ; I++){
        for(int J=0 ; J<4 ; J++){
            std::cout << "\n INGRESE EL NOMBRE  " << I << " " << J ;
            std::cin >> mat[I][J] ;
        }
    }

    std::cout << std::setfill('_') ;

    for( int R=0 ; R<3 ; R++){
        std::cout << std::endl << "\t" ;
        for(int S=0 ; S<4 ; S++)
            std::cout << "  " << std::setw(12) << mat[R][S] ;
    }

    std::cout << "\n\n\n\n" ;

    getch() ;







}
