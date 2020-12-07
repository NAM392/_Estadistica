#include <stdio.h>
#include <string.h>



class Nodo {
public:
    int edad;
    char nombre[50];
    Nodo * sig;

    Nodo() {
        edad = 0;
        strcpy(nombre, "?");
        sig = 0;
    }

};

class Lista {
private:
    Nodo * inicio;

    Nodo * buscarMinimo(void) {
        if(inicio==0) return 0;
        Nodo * aux = inicio;
        Nodo * min = inicio;

        while(aux) {
            if(aux->edad  <  min->edad) {
                min = aux;
            }
            aux = aux->sig;
        }
        return min;
    }

    void desenganchar(Nodo * sacar) {
        if(inicio==0) return;
        if(sacar == inicio) { //debo sacar el primero?
            inicio = sacar->sig;
            return;
        }
        Nodo * aux = inicio;
        while(aux->sig != sacar && aux->sig!=0 ) {
            aux = aux->sig;
        }
        aux->sig = sacar->sig;
    }


public:
    Lista() {
        inicio = 0;
    }

    ~Lista() {
        //printf("\n -- lista muriendo....");
        vaciar();
    }

    void vaciar() {
        printf("\n -- lista tiene %d elementos", contar());
        while(inicio) borrar(inicio);
        printf("\n -- lista tiene %d elementos", contar());
    }

    int contar() {
        if(inicio==0) return 0;
        int cont = 0;
        Nodo * aux = inicio;
        while(aux) {
            cont++;
            aux = aux->sig;
        }
        return cont;
    }


    void borrar(Nodo * quien) {
        desenganchar(quien);
        delete quien;
    }

    void borrar(char * quien) {
        Nodo * aBorrar = buscar(quien);
        if(aBorrar==0) return;
        //desenganchar(aBorrar);
        //delete aBorrar;
        borrar(aBorrar);
    }

    Nodo * buscar(char * quien) {
        if(inicio==0) return 0;
        Nodo * aux = inicio;
        while(aux) {
            if(strcmp(quien, aux->nombre)==0) return aux;
            aux = aux->sig;
        }
        return 0;
    }

    void agregar(const char * n, int e) {
        Nodo * nuevo = new Nodo();
        nuevo->edad = e;
        strcpy(nuevo->nombre, n);

        if(inicio == 0) {
            inicio = nuevo;
            nuevo->sig = 0;
            return;
        }

        Nodo * ultimo = inicio;
        while(ultimo->sig != 0) {
            ultimo = ultimo->sig;
        }
        ultimo->sig = nuevo;
        nuevo->sig = 0;
    }

    void mirar() {
        if(inicio==0) {
            printf("lista vacia");
            return;
        }

        Nodo * aux = inicio;
        while(aux) {
            printf("\n %d %s", aux->edad, aux->nombre);
            aux = aux->sig;
        }
    }

    void ordenar(void) {
        Nodo * ordenada = 0;
        Nodo * minimo;
        while(inicio!=0) {
            minimo = buscarMinimo(); //paso 1
            desenganchar(minimo); //paso 2
            agregarFinal(&ordenada, minimo); //paso 3
        }
        inicio = ordenada;
    }


    void agregarFinal(Nodo ** lista, Nodo * agrega) {
        if (*lista==0) {  //si la lista en metodo ordenar está vacia, 1ra iterac
            *lista = agrega;
            agrega->sig = 0;
            return;
        }
        Nodo * ult = *lista;
        while( ult->sig != 0) {
            ult=ult->sig;
        }

        ult->sig = agrega; //el ultimo deja de ser el ultimo
        agrega->sig = 0;
    }
};

int main() {
    Lista * l = new Lista;
    l->agregar("Juan Gonzalez", 18);
    l->agregar("Maria Perez", 70);
    l->agregar("Pepe Gomez", 35);
    l->mirar();
    l->borrar("Juan Gonzalez");
    l->mirar();

    delete l;

    return 0;
}
