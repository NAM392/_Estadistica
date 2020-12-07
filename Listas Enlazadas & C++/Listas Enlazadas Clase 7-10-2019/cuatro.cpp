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
void agregar(Nodo**, Nodo*);
void mirar(Nodo*);

int main(void) {
    Nodo * lista=0;
    Nodo * uno;

    uno = new Nodo(5);
    agregar(&lista, uno);

    uno = new Nodo(25);
    agregar(&lista, uno);

    uno = new Nodo(8);
    agregar(&lista, uno);

    uno = new Nodo(9);
    agregar(&lista, uno);

    uno = new Nodo;
    uno->dato = 30;
    agregar(&lista, uno);

    /*printf("1er nodo: %d", lista->dato);
    printf("\n2do nodo: %d", lista->sig->dato);
    printf("\n3er nodo: %d", lista->sig->sig->dato);*/
    mirar(lista);
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


void agregar(Nodo** inicio, Nodo* nuevo) {

    if(*inicio == 0) {
        printf("---lista vacia---");
    }

    nuevo->sig = *inicio;
    *inicio = nuevo; //agregar al inicio

}

void mirar(Nodo * primero ) {
    if(primero==0) {
        printf("lista vacia");
        return;
    }
    printf("\n\n");
    while(primero) {
        printf("dato: %d \n", primero->dato);
        primero = primero->sig;
    }

}
