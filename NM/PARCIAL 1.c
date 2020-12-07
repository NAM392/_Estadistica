#include<stdio.h>

int main()

{


    int flag=0;
    float altura_rio=0;
    unsigned int peces=0;
    unsigned int MAYOR_P=0;
    float MAYOR_A=0;
    int cont=0;



    while(altura_rio>=0)
    {
        printf("ingrese altura y cantidad de peces");
        scanf("%f %u ",&altura_rio,&peces);

        if(cont==0)
        {   MAYOR_A=MAYOR_A + altura_rio;
            MAYOR_P=MAYOR_P + peces;

        }
        else  { if(altura_rio>MAYOR_A&&peces>MAYOR_P)
            {
                flag=1;
            }

                else{ if(altura_rio>MAYOR_A&&peces>MAYOR_P)
                        {
                            flag=1;
                        }

                       else {  if(MAYOR_A>altura_rio || MAYOR_P>peces)
                                {
                                    flag=0;
                                }
                                else   {
                                            if(altura_rio>MAYOR_A||peces>MAYOR_P)
                                            {
                                                flag=0;
                                            };
                                        };
                            };

                    };
                    };
        };
       cont++;



    if(flag==1)
    {
        printf("la mayor lala");
    }
    else
        {
            printf("no coincide");
        };


};
