
#include<stdio.h>
#include<conio.h>

int main ()

{
    int CONT=1;
    int VALOR=0;
    int PAR=0;
    int IMPAR=0;

    while(CONT<=5)

    {
        printf("INGRESE UN VALOR=");
        scanf("%d",&VALOR);



            if (CONT % 2 == 0)

                 (PAR+=VALOR);
            else

                 (IMPAR+=VALOR);

               CONT++;

         }

    if (PAR<IMPAR)

    printf("HAY MAS IMPARES %d",IMPAR);

    else
        printf("hay mas pares  %d",PAR);





        return 0;


}
