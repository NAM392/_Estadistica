
// 1ra iteracion busco el minimo
// 2da iteracion  lo desengancho de la lista
//3ra lo engancho en otra lista ordenada


//los nodos se conservan en la parva , el ordenamiento
// lo engancho en otra lista ordenada
// el proceso se hace hasta que la lista original quede vacia  , lista = 0






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


    NODO * buscarMinimo(void) {
        if(inicio==0) return 0;
        NODO*aux = inicio;
        NODO * min = inicio ; //min es un puntero al minimo

        while(aux->sig !=0){
            if(aux->sig->edad < min->edad){
            min = aux->sig;
            }
            aux = aux->sig;
        }
        return min;
    }

    void desenganchar(NODO * sacar ){

        if(inicio == 0) return;
        if(sacar == inicio){ //debo sacar el primero?
            inicio = sacar->sig;
            return;
    }

    NODO * aux = inicio ;
    while(aux->sig != sacar && aux->sig != 0){ // este codigo para cuando aux llega al nodo anterior del que hay que sacar
        aux = aux->sig;
    }
    aux->sig = sacar->sig;

    }

void agregarFinal(NODO ** lista , NODO * agrega){

    if(*lista == 0 ){ // si la lista esta vacia 1ra iteracion
        *lista = agrega;
        agrega->sig = 0;
        return;
    }
    NODO * ult = *lista ;
    while(ult->sig != 0){
        ult=ult->sig;
    }
    ult->sig = agrega; //el ultimo deja de ser el ultimo
    agrega->sig = 0;
}



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




void ordenar (void) {
    NODO * ordenada = 0;
    NODO * minimo ;

    while(inicio != 0 ) {
        minimo = buscarMinimo(); //paso1
        desenganchar(minimo); //paso2
        agregarFinal(&ordenada , minimo ); //paso 3
    }
        inicio = ordenada ;

}

};

int main(){

    LISTA * l = new LISTA;
    l->mirar();  // muestra que la lista esta vacia
    l->agregar("pepe gomez " , 35 );
    l->agregar("maria lala " , 25 );
    l->agregar("luis lelo " , 15 );
    l->mirar();
    printf("\n\n");
    l->ordenar();
    l->mirar();
}

