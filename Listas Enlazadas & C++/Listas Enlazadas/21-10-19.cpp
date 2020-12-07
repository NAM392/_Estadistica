#include<stdio.h>
#include<string.h>

class NODO{
public:
    int edad;
    char nombre[40];
    NODO * sig ;

    NODO(){

        edad=0;
        strcpy(nombre , "?");
        sig = 0;
    }
};

class LISTA {
private:
    NODO * inicio ; //es lo que se conoce de la lista enlazada , el inicio
public:
    LISTA(){
        inicio = 0;  //constructor
    }
    void agregar (char * n , int e){
        NODO * nuevo = new NODO();
        nuevo->edad = e;
        strcpy(nuevo->nombre , n);

        if(inicio == 0) {
            inicio = nuevo;
            nuevo->sig = 0;
            return ;
        }
        NODO * ultimo = inicio;
        while(ultimo->sig != 0){
            ultimo = ultimo->sig;
        }
        ultimo->sig = nuevo;
        nuevo->sig = 0;
    }

    void mirar () {
        if(inicio == 0){
            printf("lista vacia");
            return;
        }

        NODO * aux = inicio;
        while(aux){
            printf("\n %d %s" , aux->edad , aux->nombre);
            aux = aux->sig;
        };
    };
};

int main(){

    LISTA * l = new LISTA;
    l->mirar();  // muestra que la lista esta vacia
    l->agregar("pepe gomez " , 35 );
    l->agregar("maria lala " , 25 );
    l->agregar("luis lelo " , 15 );
    l->mirar();
}
