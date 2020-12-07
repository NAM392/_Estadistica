#include<stdio.h>
#include<string.h>

class NODO{
public:
    int edad;
    char nombre[20];
    NODO*sig;

    NODO(){
        edad = 0;
        sig = 0;
        nombre[0] = 0;
    }
};
class LISTA {
private:
    NODO*inicio;

public:
    LISTA(){
        inicio = 0;
    }

    int contar(){
        if(inicio==0) return 0;

        int cont = 1;
        NODO*aux = inicio;

        while(aux->sig != 0){
            aux = aux->sig;
            cont++;
        }
        return cont;
    }

    void agregar_al_final(NODO ** lista , NODO * agrega ){


        if(inicio == 0){
            inicio = agrega;
            agrega->sig = 0;
            return;
        }

        NODO*ultimo = *lista;
        while(ultimo->sig != 0){
            ultimo=ultimo->sig;
        }
        ultimo->sig = agrega;
        agrega->sig = 0;

    };
    NODO * minimo(void){

        if(inicio == 0 ){
            return 0;
        }

        NODO * aux = inicio;
        NODO * min = inicio;

        while(aux->sig != 0 ){
            if (aux->sig->edad < min->edad ){
                min = aux->sig;
            }
        aux = aux->sig;
        }
        return min;
    };



    void desenganchar(NODO * sacar){
        if (inicio == 0) return;

        if (sacar == inicio){ //debo sacar el primero?
            inicio = sacar->sig;
            return;
        }

        NODO*aux = inicio;

        while(aux->sig != sacar && aux->sig !=0 ){
            aux = aux->sig;
        }

        aux->sig = sacar->sig;

        }

    void mirar(void){
            if (inicio == 0){
            return;
            }
            NODO * aux = inicio;
            int cont = 1;

            while(aux){
                printf("\nNODO %d  nombre %s y edad %d " , cont , aux->nombre , aux->edad );
                cont ++;
                aux = aux->sig;
            }
        }
        void ordenar(void){
            NODO * ordenada = 0 ;
            NODO * min  ;


            while(inicio != 0){
                min = minimo();
                desenganchar(min);
                agregar_al_final( &ordenada , min );
            }
            inicio = ordenada;

        }



};

int main()
{

    char nombre[20];
    int edad;
    LISTA * LALA = new LISTA ;
    NODO * aux = new NODO;

    printf("ingrese nombre :  ");
    fflush(stdin);
    gets(nombre);

    printf("ingrese edad : ");
    scanf("%d",&edad);

    while (edad != -1 ){


        LALA->agregar_al_final( &aux , edad );
        fflush(stdin);
        printf("ingrese nombre : ");
        gets(nombre);
        printf("ingrese edad : ");
        scanf("%d",&edad);


    }


    LALA->mirar();
    LALA->ordenar();
    LALA->mirar();
















}




