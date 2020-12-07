#include<stdio.h>

#define P 5
#define N 20

struct DATOS {
char NOMBRE [N];
int EDAD ;
char SEXO ;
};

void INGRESA(struct DATOS [] , int );
void ORDENA (struct DATOS [] , int );
void IMPRIME(struct DATOS [] , int );

int main()
{

    struct DATOS PERSONA [P];

    INGRESA ( PERSONA  , P);
    ORDENA  ( PERSONA  , P);
    IMPRIME ( PERSONA  , P);


}
void INGRESA(struct DATOS PERSONA [] , int L)
{
    int I;
    for(I=0 ; I<L ; I++)
    {
        fflush(stdin);
        printf("ingrese nombre  : ");
        gets(PERSONA [I].NOMBRE);

        fflush(stdin);
        printf("ingrese sexo M/F  : ");
        fflush(stdin);
        PERSONA[I].SEXO=getchar();
        fflush(stdin);
        printf("ingrese edad  : ");
        scanf("%d",&PERSONA[I].EDAD);





    }



}

void ORDENA(struct DATOS PERSONA [] , int L)
{
    struct DATOS AUX ;
    int I,J;

    for(I=0 ; I<L-1 ; I++)
        for(J=0 ; J<L-I-1 ; J++)
            if(PERSONA[J].EDAD < PERSONA[J+1].EDAD)
                {


                    AUX          =   PERSONA[J] ;
                    PERSONA[J]   =   PERSONA[J+1];
                    PERSONA[J+1] =   AUX ;

                }



}

void IMPRIME(struct DATOS PERSONA [] , int L)
{
    int I;

    for(I=0 ; I<L ; I++)
    {
        if(PERSONA[I].SEXO=='F')

        printf("\n\n\t %s  \t\t  %c  \t\t  %d \n\n ", PERSONA[I].NOMBRE ,PERSONA [I].SEXO , PERSONA[I].EDAD);

    }
     for(I=0 ; I<L ; I++)
    {
        if(PERSONA[I].SEXO=='M')

        printf("\n\n\t %s  \t\t  %c  \t\t  %d \n\n ", PERSONA[I].NOMBRE ,PERSONA [I].SEXO , PERSONA[I].EDAD);

    }





}
