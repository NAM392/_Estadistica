#include <stdio.h>

class Nodo {
public:
    int dato;
    Nodo * sig;

    Nodo() {
        dato = 0;
        sig = 0;
    }

    Nodo(int n) {
        dato = n;
        sig = 0;
    }

};

int contar(Nodo * );

int main(void) {
    Nodo * lista=0;
    Nodo * uno;
    int ingreso;

    uno = new Nodo(5);
    uno->sig = lista;
    lista = uno;

    uno = new Nodo(25);
    uno->sig = lista;
    lista = uno;

    uno = new Nodo;
    uno->dato = 30;
    uno->sig = lista;
    lista = uno;

    printf("1er nodo: %d", lista->dato);
    printf("\n2do nodo: %d", lista->sig->dato);
    printf("\n3er nodo: %d", lista->sig->sig->dato);
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
