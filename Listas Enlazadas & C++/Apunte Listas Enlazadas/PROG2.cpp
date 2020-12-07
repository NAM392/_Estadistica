//FLUJOS STANDARD

#include<iostream>
#include<stdio.h>
#include<conio.h>
int main()
{
    //clrscr()



    int I;
    std::cout << "ingrese un entero \n";
    std::cin >> I ;

    float F;
    std::cout << "ingrese un flotante\n" ;
    std::cin >> F;

    char C ;
    std::cout <<"ingrese un caracter \n" ;
    std::cin >>C ;

    long L;
    std::cout <<"ingrese un long \n" ;
    std::cin >>L ;

    char palabra[20];
    std::cout <<"ingrese una palabra \n" ;
    std::cin >>palabra ;


    std::cout <<"\nENTERO = "<< I << "\nFLOTANTE = " << F \
    << "\nCARACTER  = " << C << "\n LONG = " << L ;
    std::cout <<"\nPALABRA = " << palabra ;

    getch();


}
