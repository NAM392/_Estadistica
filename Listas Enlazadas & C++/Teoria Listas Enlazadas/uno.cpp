#include <stdio.h>

class Nodo {
public:
    int dato;
    Nodo * sig;
};

int contar(Nodo * );

int main(void) {
    Nodo * lista=0;
    Nodo * uno = new Nodo;

    uno->dato = 5;

    lista = uno;

    Nodo * dos = new Nodo;
    dos->dato = 10;
    dos->sig = 0;

    lista->sig = dos;  //enlazado

    printf("1er nodo: %d", lista->dato);
    printf("\n2do nodo: %d", lista->sig->dato);
    printf("\nla lista tiene %d nodos", contar(lista));
}


int contar(Nodo * inicio) {
    int resultado = 0;

    Nodo * aux = inicio;
    while(aux) {
        resultado++;
        aux = aux->sig;  //linked list's magic
    }

    return resultado;

}
