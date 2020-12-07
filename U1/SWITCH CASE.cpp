#include<stdio.h>

int main()
{
    int SEL;

    printf("\n\t\t\t\t MENU \n\n\n");
    printf("\n\t\t\t\t 1. OPCION 1 ");
    printf("\n\t\t\t\t 1. OPCION 2 ");
    printf("\n\t\t\t\t 1. OPCION 3 ");
    printf("\n\n\nINGRESE SU OPCION : ");
    scanf("%d",&SEL);

    switch (SEL)
    {
        case 1: printf("\nUD.SELECCIONO OPCION 1");
                break;
        case 2: printf("\nUD.SELECCIONO OPCION 2");
                break;
        case 3: printf("\nUD.SELECCIONO OPCION 3");
                break;
        default: printf("\nUD.SELECCIONO OTRA COSA");
                break;


    }















}
