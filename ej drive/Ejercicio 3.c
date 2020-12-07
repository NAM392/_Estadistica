#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ingreso=0;
    int contador=0;
        while (ingreso != 235)
        {
            printf("ingrese un numero\n");
            scanf("%i", &ingreso);
                if (ingreso==23)
                    contador++;
        }
    printf("el numero 23 se ingreso %i veces", contador);
    return 0;
}
