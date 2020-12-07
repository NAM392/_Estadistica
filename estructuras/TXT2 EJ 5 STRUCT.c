#include<stdio.h>

#define P 3
#define N 20
#define S 2

struct PRIMARIO{

    char NOMBRE [N];
    int EDAD;
};

struct DATOS {

    char SEXO  ;
    struct PRIMARIO X [S] ;
};


void INGRESA(struct DATOS [] , int);
void ORDENA (struct DATOS [] , int);
void IMPRIME(struct DATOS [] , int);
int main()
{

    struct DATOS PERSONAS[P];

    INGRESA(PERSONAS , P);
    ORDENA (PERSONAS , P);
    IMPRIME(PERSONAS , P);

}
void INGRESA(struct DATOS PERSONAS [] , int L)
{

    int I;
    int CONT_M=0 ;
    int CONT_H=0 ;

    for (I=0 ; I<L ; I++)
    {

        printf("ingrese el sexo M/F : ");
        fflush(stdin);
        PERSONAS[I].SEXO = getchar();
        fflush(stdin);

        if(PERSONAS[I].SEXO == 'F')
            {

            fflush(stdin);
            printf("ingrese el nombre  : ");
            fflush(stdin);
            gets(PERSONAS[CONT_M].X[0].NOMBRE);
            fflush(stdin);
            printf("ingrese edad  : ");
            scanf("%d",&PERSONAS[CONT_M].X[0].EDAD);

            CONT_M++;


            }
        else
            {
            fflush(stdin);
            printf("ingrese el nombre  : ");
            fflush(stdin);
            gets(PERSONAS[CONT_H].X[1].NOMBRE);
            fflush(stdin);
            printf("ingrese edad  : ");
            scanf("%d",&PERSONAS[CONT_H].X[1].EDAD);

            CONT_H++;

            }






    }



};

void ORDENA(struct DATOS PERSONAS [] , int L)
{
    struct DATOS AUX ;

    int I,J;

    for(I=0 ; I<L-1 ; I++)
        for(J=0 ; J<L-I-1 ; J++)
            if(PERSONAS[J].X[0].EDAD > PERSONAS[J+1].X[0].EDAD)
                {


                    AUX             =   PERSONAS[J];
                    PERSONAS[J]     =   PERSONAS[J+1];
                    PERSONAS[J+1]   =   AUX ;


                }



}

void IMPRIME(struct DATOS PERSONAS [] , int L)
{

    int I;

    for(I=0 ; I<L ; I++)
    {
        printf("\n\n\t\t %s\tde\t%d\tcon\t%s\tde\t%d ",PERSONAS[I].X[0].NOMBRE , PERSONAS[I].X[0].EDAD,PERSONAS[I].X[1].NOMBRE,PERSONAS[I].X[1].EDAD);
    };






}


