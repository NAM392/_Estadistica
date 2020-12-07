#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std ;

class NODO{
public :
	NODO(char *) ;
	~NODO ();
	char NOM[20] ;
	NODO * SIG;

};

NODO::NODO (char * S){
strcpy (NOM , S);

}

NODO::~NODO(){

cout << "\n\n MATANDO " << NOM ;
getchar();	

}



class LISTA {
	private :
		NODO * INICIO ;
		void PONER_P (NODO *);
	
	public :
		LISTA();
		~LISTA();
		void ABREGAR_P (char *);
		void MIRAR ();
};

LISTA::LISTA(){

INICIO = NULL;

}

void LISTA::ABREGAR_P(char * S){

	NODO * P ;
	P = new NODO (S) ;
	
	
	PONER_P(P);
	
}

void LISTA::PONER_P( NODO * PN){

PN->SIG = INICIO;
INICIO = PN;

}

void LISTA::MIRAR(){
	
	NODO * P ;
	P = INICIO ;
	
	cout << "\n\n\n\tCONTENIDO DE LA LISTA \n";
	
	while ( P ){
	
	cout << "\n\t" << P->NOM << "\n" ;
	
	P = P->SIG;
	
	}
getchar();

}

LISTA::~LISTA() {

cout << "\n\n MATADO A ... TODOS LOS NODOS" ;
getchar () ;

}

int main () {

	LISTA L ;

	char BUF[20];
	
	cout << "\n\n NOMBRE : " ;
	cin >> BUF ;
	
	while ( strcmp (BUF, "FIN") ){
	
	L.ABREGAR_P(BUF);
	
	
	
	
	cout << "\n\n NOMBRE : " ;
	cin >> BUF ;
	}

L.MIRAR();
return 0;}
