#include<stdio.h>


class NODO {
public:
        int dato;
        NODO*sig;
            NODO(){    //constructor
                sig=0;
                dato=0;
            }
};

void agregar_al_final(NODO ** , NODO * );

void agregar_principio(NODO ** , NODO * );

int contar (NODO *);

void mostrar(NODO *);

int existe(NODO * , int );

int agregar_ordenado (NODO ** , NODO * );


int main(void){

    NODO * lista = 0;

    int ingreso = 0 ;

    int busqueda = 0;


    printf("ingrese un dato en un nodo  : ");
    scanf("%d" , &ingreso);

    while(ingreso != -1) {
        NODO * conti = new NODO;
        conti->dato = ingreso;
        agregar_ordenado(&lista , conti);
        printf("ingrese un dato en un nodo  : ");
        scanf("%d" , &ingreso);

    }

    mostrar(lista);

    printf("\n ingrese un numero a buscar  : ");
    scanf("%d" , &busqueda);



  if( existe(lista , busqueda ) != 0 ){
     printf("esta en el nodo" );
  }
  else {printf("no esta en el nodo");};


}
void agregar_al_final(NODO ** inicio , NODO * nuevo){

    if(*inicio == 0){
    *inicio = nuevo;
    return;
    }

    NODO * ultimo = *inicio; // a ultimo le paso la direccion de memoria de inicio

    while (ultimo->sig != 0){  // distinto a !=0 para asegurarnos que no es el primer nodo
        ultimo = ultimo->sig;
    }

     ultimo->sig = nuevo;


}
void agregar_principio (NODO ** inicio , NODO * nuevo){
    if(*inicio == 0){
        *inicio = nuevo;
        return;
    }

    nuevo->sig = *inicio;
    *inicio = nuevo ;



}

int contar(NODO * inicio){

    if (inicio == 0){
        printf("lista vacia ");
        return 0;
    };

    int cont = 1;
    NODO * proximo ;

    proximo = proximo->sig;
    while(proximo != 0){
        cont++;
        proximo = proximo->sig;
    }


}

void mostrar (NODO * inicio){
    if (inicio == 0){  // lista vacia
        printf("\nlista vacia");
    }

    //lista tiene algo

    int cont=1;
    printf("\n NODO nro :  %d con dato  : %d" , cont , inicio->dato );

    while(inicio->sig != 0 ){
        inicio = inicio->sig;
        cont++;
        printf("\n NODO nro :  %d con dato  : %d" , cont , inicio->dato );
    }

    printf("\n\n");
}

int existe(NODO * inicio , int BUSCAR ){

    //NODO * aux = inicio;
    int flag = 0;

    while(inicio != 0 ){
        if(inicio->dato == BUSCAR){
            flag = 1;
        }
        inicio = inicio->sig;
    }

    return flag;



}
int agregar_ordenado (NODO ** inicio , NODO * nuevo ){
    if(*inicio == 0){
        *inicio = nuevo;

         return 0 ;
    }


    NODO*aux = *inicio;
    NODO*ant = 0;

    while(aux){
            if(aux->dato < nuevo->dato){
                ant = aux;
                aux = aux->sig;       //BARRIDO

            }
            else {
                  if (ant){
                    nuevo->sig = aux;
                    ant->sig = nuevo;
                    return 0;
                  }
                  agregar_principio(inicio , nuevo);
                  /*nuevo->sig = *inicio;
                  *inicio = nuevo;
                  return 0 ; */
            }

    }
       agregar_al_final(inicio , nuevo);
            /* nuevo->sig = 0;
            ant->sig = nuevo; */




}
