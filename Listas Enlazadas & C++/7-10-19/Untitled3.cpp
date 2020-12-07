

#include<stdio.h>


   class Nodo {
public :
    int dato;
    Nodo*sig;

    Nodo(){
        dato=0;
        sig=0; //metodo que se ejectuta solo cuando hago una instanciacion
    }

    Nodo(int n) {
        dato=n;
        sig=0;
    }
};

int contar(Nodo *);
void agregar(Nodo** , Nodo*);




int main(void){


    Nodo * lista = 0; // la variable lista es el puntero a un nodo
    Nodo * uno ;


    uno = new Nodo(5);
    agregar(&lista , uno);


    uno = new Nodo(10);
    agregar(&lista , uno);

    uno = new Nodo(1435);
    agregar(&lista , uno);


    uno=new Nodo;
    uno->dato = 30;
    agregar(&lista , uno);


    printf("1er nodo  : %d" , lista->dato);
    printf("\n segundo nodo : %d" , lista->sig->dato);
    printf("\n tercer nodo : %d" , lista->sig->sig->dato);
    printf("\nla lista tiene : %d nodos" , contar(uno));


}

    int contar(Nodo*inicio){

    int resultado=0 ;

    Nodo*aux = inicio;
   while(aux){
        resultado++;
        aux=aux->sig; // linked list's magic
    }

    return resultado;



}

void agregar( Nodo**inicio , Nodo*nuevo ){

    if(*inicio==0){
        printf("\n-------lista vacia------\n");
    };

    nuevo->sig = *inicio;
    *inicio = nuevo; //agrega r al inicio















}
