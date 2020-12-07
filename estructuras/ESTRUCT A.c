#include<stdio.h>
#include <string.h>
#define N 20
#define P 4


struct PERSONAS{
char NOMBRE [N];
int EDAD ;
char SEXO;
};

void PROMEDIO(struct PERSONAS [] , int  );


int main()
{

    struct PERSONAS DATOS[P];
    struct PERSONAS AUX;
    int I;
    int J;

    for(I=0 ; I<P ; I++)
    {
        fflush(stdin);
        printf("ingrese nombre\t");
        gets(DATOS[I].NOMBRE);

        printf("ingrese edad\t");
        scanf("%d",&DATOS[I].EDAD);

        fflush(stdin);
        printf("ingrese sexo  M/F\t");
        DATOS[I].SEXO = getchar();



    }


    for(I=0 ; I<P-1 ; I++){
        for(J=0 ; J<P-I-1 ; J++){
                if((DATOS[J].EDAD) < (DATOS[J+1].EDAD))
                        {
                            AUX         = DATOS[J];
                            DATOS[J]    = DATOS[J+1];
                            DATOS[J+1]  = AUX;
                        }
                if(DATOS[J].SEXO == 'M')
                        {
                            AUX         = DATOS[J];
                            DATOS[J]    = DATOS[J+1];
                            DATOS[J+1]  = AUX;
                        }

    }
}


    for(I=0 ; I<P ; I++)
    {
        printf("\n\n\t\t%s\t\t%d\t\t\n",DATOS[I].NOMBRE , DATOS[I].EDAD);
    }


    PROMEDIO( DATOS , P);



}
void PROMEDIO(struct PERSONAS DATOS [] , int L)
{

    int I;
    int cont_m=0 , cont_f=0 , acum_m=0 , acum_f=0 , F , M ;

    for(I=0 ; I<L ; I++)
    {
        if(DATOS[I].SEXO == 'M')
            {
                cont_m = cont_m + DATOS[I].EDAD ;
                acum_m++;
            }


        else
            {
               cont_f = cont_f + DATOS[I].EDAD ;
               acum_f++;
            }

    }

    if((F=cont_f / acum_f) < (M= cont_m / acum_m))
    {
        printf("\n\nel mayor promedio es de los hombres con %d\n\n",M);
    }
    else { printf("\n\nel mayor promedio es de las mujeres con %d\n\n",F);};





}




