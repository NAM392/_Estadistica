#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ingreso = 0;
    int contador = 0;
        while (ingreso!=-1)
            {
                printf("ingrese un numero\n");
                scanf("%i", &ingreso);
                if (ingreso % 2 == 0)
                    contador++;
            }
    printf("%i numeros son pares", contador);
    return 0;
}
