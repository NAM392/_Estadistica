#include <stdio.h>
#include <stdlib.h>

int main()
{
    int clave = 0;
    int contador = 0;

    do
    {
        printf("ingrese la clave\n");
        scanf("%i", &clave);
        if (clave!=23645)
            {
                printf("clave incorrecta\n");
                contador++;
            }
        if (contador>=3)
            goto ADVERTENCIA;
    }
    while (clave!=23645);
    printf("clave exitosa\n");
    ADVERTENCIA:
        if (contador>=3)
            printf("SACA LA MANO DE AHI CARAJO");
    return 0;
}
