#include<stdio.h>
int main()
{
    int IN,MAYOR,ingreso;

    for(IN=0;IN<5;IN++)
    {
        printf("INGRESE NUMERO ");
        scanf("%d",&ingreso);

        if(IN==0)
        {
            MAYOR=ingreso;
        }
        else
        {
            if(ingreso>MAYOR)
            {
                MAYOR=ingreso;
            };
        };
    };
    printf("EL MAYOR ES %d",MAYOR);
}
