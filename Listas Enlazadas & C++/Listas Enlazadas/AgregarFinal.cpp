#include<stdio.h>
#include<stdlib.h>

class NODO {
public :
    int dato;
    NODO * sig;
};

void agregaralfinal(NODO ** , NODO *);

int main()
{

    NODO * lista = 0 ;
    NODO * nuevo = new NODO;
    nuevo->dato = 23;
    lista = nuevo ;

    agregaralfinal(&lista , nuevo);

    printf("%d ver" , nuevo->dato);

}
void agregaralfinal(NODO **lista , NODO * nuevo)
{
    if(*lista == 0){ //lista vacia
        *lista = nuevo;
        printf("lista vacia ");

    }

    //lista tiene nodos
    //busco el ultimo elemento
    NODO * ultimo = *lista ;
    while (ultimo->sig != 0) {
        ultimo = ultimo->sig;
    }
    ultimo->sig = nuevo;

    ultimo->dato = 75;
    ultimo->sig->dato = 99;

    printf("%d ulti .....  %d ultisiguiente" , ultimo->dato , ultimo->sig->dato);
}


