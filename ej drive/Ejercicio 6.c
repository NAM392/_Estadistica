#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ingreso=1;
    while (ingreso>0)
    {
        printf("ingrese el numero a revisar\n");
        scanf("%i", &ingreso);
            if (ingreso % 2 == 0 || ingreso % 3 == 0 || ingreso % 5 == 0 || ingreso % 7 == 0)
            {
                switch(ingreso)
                {
                    case 2: ingreso=2;
                        printf("%i es numero primo\n", ingreso);
                        break;
                    case 3: ingreso=3;
                        printf("%i es numero primo\n", ingreso);
                        break;
                    case 5: ingreso=5;
                        printf("%i es numero primo\n", ingreso);
                        break;
                    case 7:  ingreso=7;
                        printf("%i es numero primo\n", ingreso);
                        break;
                    default:
                        printf("%i NO es numero primo\n", ingreso);
                        break;
                }
            }
            else if (ingreso==1)
                printf("%i NO es numero primo\n", ingreso);
            else
                printf("%i es numero primo\n", ingreso);
    }
    return 0;
}
