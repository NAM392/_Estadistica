/*OPERANDO Y MANTENIENDO UNA LISTA*/

#include<stdio.h>
#include<stdlib.h>

struct listNode {           /*ESTRUCTURA AUTOREFERENCIADA*/
    char data ;
    struct listNode * nextPTR;
    };

typedef struct listNode LISTNODE;
typedef LISTNODE * LISTNODEPTR;

void insertar (LISTNODEPTR * , char );
char borrar (LISTNODEPTR * , char );
int isEmpty(LISTNODEPTR);
void printList(LISTNODEPTR);
void Instrucciones(void);

int  main()
{
    LISTNODEPTR EmpiezaPtr = NULL;
    int eleccion;
    char item;

    Instrucciones(); /* MUESTRA EL MENU */
    printf("\n\t?");
    scanf("%d",&eleccion);

    while(eleccion!=3){
        switch(eleccion){
        case 1:
            printf("Ingresa un caracter : ");
            scanf("\n%c", &item);
            insertar (&EmpiezaPtr , item );
            printList(EmpiezaPtr);
            break;
        case 2:
            if(!isEmpty(EmpiezaPtr)){
                printf("\tIntroduce un caracter que se va a eliminar : ");
                scanf("\n%c" , &item );

                if( borrar(&EmpiezaPtr , item )) {
                    printf("\t%c BORRADO.\n " , item );
                    printList(EmpiezaPtr);
                }
                else
                    printf("\t%c NO FUNCIONA .\n\n " , item );
            }
            else
                printf("\tLISTA ENCONTRADA . \n\n");

            break;

                default:
                    printf("\tELECCION INVALIDA .\n\n");
                    Instrucciones();
                    break;
        }
        printf("? ");
        scanf("%d" , &eleccion );
    }
    printf("Fin del programa :\n");
    return 0;
}

/*IMPRIME LAS INSTRUCCIONES */

void Instrucciones (void)
{
    printf("Elige su opcion : \n"
           "  1 para insertar un elemento en la lista.\n"
           "  2 para borrar un elemento de la lista .\n"
           "  3 para terminar .\n");

}

/*INSERTAR UN NUEVO VALOR DENTRO DE LA LISTA ORDENADAMENTE*/

void insertar (LISTNODEPTR*sPTR , char value )
{
    LISTNODEPTR nuevoPTR , anteriorPTR , estePTR ;

    nuevoPTR = malloc(sizeof(LISTNODE));

    if(nuevoPTR != NULL ){          /*EL ESPACIO ESTA DISPONIBLE*/
       nuevoPTR->data = value;
       nuevoPTR->nextPTR = NULL ;

       anteriorPTR = NULL;
       estePTR = *sPTR;

       while(estePTR != NULL && value > estePTR ->data ){
            anteriorPTR = estePTR;              /*VOY A ...*/
            estePTR = estePTR->nextPTR ;   /*...SIGUIENTE NODO */
       }
       if( anteriorPTR == NULL){
            nuevoPTR ->nextPTR = *sPTR;
            *sPTR = nuevoPTR;
       }
       else {
            anteriorPTR->nextPTR = nuevoPTR;
            nuevoPTR -> nextPTR = estePTR;
       }

    }
    else
        printf("%c no insertado . no hay memoria disponible . \n" , value );
}

/*BORRAR UN ELEMENTO DE LA LISTA */

char borrar(LISTNODEPTR*sPTR , char value )
{
    LISTNODEPTR anteriorPTR , estePTR , tempPTR ;

    if(value == (*sPTR)-> data ){
        tempPTR = *sPTR ;
        *sPTR = (*sPTR)->nextPTR ;   /*DESHEBRAR EL NODO */
        free(tempPTR);          /*LIBERA EL NODO DESHEBRADO*/
        return value;
    }
    else {
        anteriorPTR = *sPTR;
        estePTR = (*sPTR)->nextPTR;

        while ( estePTR != NULL && estePTR ->data != value ){
                anteriorPTR = estePTR;          /*YENDO A ...*/
                estePTR = estePTR->nextPTR ; /*...PROXIMO NODO */
        }
        if(estePTR != NULL){
            tempPTR = estePTR;
            anteriorPTR -> nextPTR = estePTR ->nextPTR ;
            return value;
        }
    }
    return '\0' ;
}

/*RETORNA 1 SI LA LISTA ES ENCONTRADA , SINO 0 */

int isEmpty(LISTNODEPTR sPTR)
{
    return sPTR == NULL ;
}

/*IMPRIMIR LA LISTA */
void printList(LISTNODEPTR estePTR)
{
    if (estePTR == NULL)
        printf("LISTA ENCONTRADA .\n\n");
    else {
        printf("LA LISTA ES :\n");

        while(estePTR != NULL ) {
            printf("%c --> " , estePTR->data);
            estePTR = estePTR->nextPTR;
        }
        printf("NULL\n\n");
    }
}


