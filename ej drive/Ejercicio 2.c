#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador = 0;
    int pares = 0;
    int impares = 0;
    int ingreso = 0;
        while (contador<100)
        {
            contador++;
            printf("ingrese un numero\n");
            scanf("%i",&ingreso);
                if (ingreso % 2 == 0)
                    pares+=ingreso;
                else
                    impares+=ingreso;
        }
    if (pares>impares)
        printf("%i", pares);
    else
        printf("%i", impares);
    return 0;
}
