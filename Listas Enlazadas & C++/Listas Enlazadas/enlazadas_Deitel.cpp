/*OPERANDO Y MANTENIENDO UNA LISTA*/

#include<stdio.h>
#include<stdlib.h>

struct listNode {           /*ESTRUCTURA AUTOREFERENCIADA*/
    char data ;
    struct listNode * nextPtr;
    };

typedef struct listNode LISTNODE;
typedef LISTNODE * LISTNODEPTR;

void insertar (LISTNODEPTR * , char );
char borrar (LISTNODEPTR * , char );
int isEmpty(LISTNODEPTR);
void printList(LISTNODEPTR);
void Instrucciones(void);

main()
{
    LISTNODEPTR EmpiezaPtr = NULL;
    int eleccion;
    char item;

    Instrucciones(); /* MUESTRA EL MENU */
    printf("?");
    scanf("%d",%eleccion);

    while(eleccion!=3){
        switch(eleccion){
        case 1:
            printf("Ingresa un caracter : ");
            scanf("\n%c", &item);
            insertar (&EmpiezaPtr , item );
            printList(EmpiezaPtr);
            break
        case 2:
            if(!isEmpty(EmpiezaPtr)){
                printf("Introduce un caracter que se va a eliminar");
                scanf("\n%c" , &item );

                if(delete(&EmpiezaPtr , item )) {
                    printf("%c deleted.\n " , item );
                    printList(EmpiezaPtr);
                }
                else
                    printf("%c not found .\n\n " , item );
            }
            else
                printf("Lista encontrada . \n\n");

            break;

                default;
                    printf("eleccion invalida.\n\n");
                    Instrucciones();
                    break;
        }
        printf("? ");
        scanf("%d" , &choice );
    }
    printf("Fin del programa :\n");
    return 0;
}

/*IMPRIME LAS INSTRUCCIONES */

void Instrucciones (void)
{
    printf("Elige su opcion : \n"
           "  1 para insertar un elemento en la lista.\n
           "  2 para borrar un elemento de la lista .\n
           "  3 para terminar .\n");

}

/*INSERTAR UN NUEVO VALOR DENTRO DE LA LISTA ORDENADAMENTE*/

void insertar (LISTNODEPTR*sPTR , char value )
{
    LISTNODEPTR nuevoPTR , anteriorPTR , estePTR ;

    nuevoPTR = malloc(sizeof(LISTNODE));

    if(nuevoPTR != NULL ){  /*EL ESPACIO ESTA DISPONIBLE*/
       nuevoPTR->data = value;
       nuevoPTR->proximoPTR = NULL ;

       anteriorPTR = NULL;
       estePTR = *sPTR;

       while(estePTR != NULL && value > estePTR ->data ){
            anteriorPTR = estePTR;              /*VOY A ...*/
            estePTR = estePTR->proximo->PTR ;   /*...SIGUIENTE NODO */
       }
       if( anteriorPTR == NULL){
            nuevoPTR ->proximoPTR = *sPTR;
            *sPTR = nuevoPTR;
       }
       else {
            anteriorPTR->proximoPTR = nuevoPTR;
            nuevoPTR -> proximoPTR = estePTR;
       }

    }
    else
        printf("%c no insertado . no hay memoria disponible . \n" , value );
}

/*BORRAR UN ELEMENTO DE LA LISTA */

char borrar(LISTNODEPTR*sPTR , estePTR , tempPTR)
{
    if(value == (*sPTR)-> data ){
        tempPTR = *sPTR ;
        *sPTR = (*sPTR)->proximoPTR ;   /*DESHEBRAR EL NODO */
        free(tempPTR)
    }
}







    }
