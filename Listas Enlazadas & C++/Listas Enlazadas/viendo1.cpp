#include<stdio.h>


class NODO {
public:
        int dato;
        NODO*sig;

        NODO(){       //constructor
            sig=0;
            dato=0;
        }
    };


int contar(NODO * );

void agregar(NODO ** , NODO*);

void agregar_al_final(NODO** , NODO* );

void mirar(NODO*);



int main(void)
{


    NODO*lista=0;  //inicializo la lista con 0 para que no sea descointrolado

    NODO*uno = new NODO;   //creo un nodo con nombre "uno"

    uno->dato=5;           // asigno el dato 5 en la clase nodo

    lista=uno; // pongo la direccion de "uno" para enlazar

    NODO*dos = new NODO;   // creo el nodo "dos"

    dos->dato=10;         //asigno el numero 10 al dato del nodo "dos"

    lista->sig=dos;      //asigno la direccion de "dos" para enlazar

    NODO*tres =  new NODO;  //agrego al principio el tercer nodo
    tres->dato = 14;
    agregar(&lista , tres);

    NODO * cuatro= new NODO;
    cuatro->dato = 73;
    agregar_al_final(&lista , cuatro);

    int ingreso = 0;

    printf("ingrese datos de los nodos  : ");
    scanf("%d" , &ingreso);

    while(ingreso != -1){

        NODO*conti = new NODO;
        conti->dato = ingreso;
        agregar_al_final(&lista , conti);
        printf("ingrese datos de los nodos  : ");
        scanf("%d" , &ingreso);

    }
    mirar(lista);


  /*  printf("\n1er NODO %d ", lista->dato);
    printf("\n2do nodo : %d ", lista->sig->dato);
    printf("\n3er nodo : %d ",lista->sig->sig->dato);
    printf("\nhay %d nodos", contar(lista));
    printf("\n");
    mirar(lista);
    printf("\n");
*/

}
//la funcion debe agregar el nodo al principio de la lista
void agregar(NODO**inicio , NODO*nuevo)  //agrega al principio
{
    if(*inicio == 0){ //lista vacia
        *inicio=nuevo;
        return;
    }

    //lista tiene algo

    nuevo->sig = *inicio;
    *inicio = nuevo;
}
//la funcion debe agregar el nodo al final de la lista
void agregar_al_final(NODO**inicio , NODO*nuevo ){

    if(*inicio == 0){ //lista vacia
        *inicio = nuevo ;
        return;
    }

    //lista tiene nodos
    //busco el ultimo elemento :
    NODO * ultimo = *inicio;  /* NODO * aux = *inicio */
    while (ultimo->sig != 0){
        ultimo = ultimo->sig;
    }

  ultimo->sig = nuevo;



}

int contar(NODO*inicio){
    int resultado = 0;

    NODO * aux = inicio;
    while(aux) {      //mientras aux no haya llegado al final
        resultado++;
        aux = aux->sig;  //avanzo al siguiente nodo
    }

    return resultado;
}

void mirar(NODO*inicio){
    if (inicio==0){
        printf("lista vacia");
        return ;
    }
    int cont=1;
    NODO*aux = inicio;

    while (aux){
        printf("\n %d nodo : %d \n " ,cont ,  aux->dato );
        aux = aux->sig ;
        cont++;
    }
}

