#include<stdio.h>

int main()
{
int VALOR=0;
int CONT=0;

while (VALOR>=0)
    {
        printf("\t\t\n\nINGRESAR NUMEROS=");

        scanf("%d",&VALOR);

        if (VALOR % 2 ==0)
            CONT++;
        }

        printf("HAY %d VALORES PARES",CONT);
}
