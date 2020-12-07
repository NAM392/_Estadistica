#include <stdio.h>
#include <stdlib.h>

int main()
{
    int clave = 0;

    do
    {
        printf("ingrese la clave\n");
        scanf("%i", &clave);
        if (clave!=23645)
            printf("clave incorrecta\n");
    }
    while (clave!=23645);
    printf("clave exitosa\n");
    return 0;
}
