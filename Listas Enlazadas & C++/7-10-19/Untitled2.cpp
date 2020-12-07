
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




int main(void){


     Nodo * lista = 0;
     Nodo * uno ;
     int ingreso;

      uno = new Nodo(5);
     //uno->dato = 5;
     uno->sig = lista;
     lista = uno;

     uno = new Nodo(25);
     //uno->dato = 25;
     uno->sig = lista;
     lista = uno;

      uno = new Nodo;
     uno->dato = 65;
     uno->sig = lista;
     lista = uno;

   // lista -> sig = uno; //enlazada

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
