//WEST POINT //

#include<stdio.h>
#define MAX   200
#define MAX_MAT 12

struct SOLDADO {
int LEGAJO;
char NOM[20];
int NOTA[MAX_MAT];
char DISPONIBLE ;
};
void INGRESO (struct SOLDADO [] , int);
void ORDENA (struct SOLDADO  [] , int , int);

int main()
{
    struct SOLDADO DATO[MAX];
    int I , CODIGO , CANTIDAD , VACANTES = MAX ;

    //INGRESO
    INGRESO(DATO,MAX) ;

    while (VACANTES) {

        //PEDIDOS

        printf("ingrese codigo de asignatura preferencial");
        scanf("%d",&CODIGO);
        CODIGO-- ; //AJUSTE A LA POSICION DEL VECTOR
        printf("\n\n ingrese la cantidad de comandos solicitada");
        scanf("%d",&CANTIDAD) ;

        //ORDENAMIENTO
        ORDENA ( DATO , MAX , CODIGO) ;

        //ASIGNACION

        if (VACANTES < CANTIDAD ){
            printf("NO ALCANZAN");
            VACANTES = 0 ;
        }
        else
            VACANTES -= CANTIDAD ;
        for(I=0 ; (I<MAX)&&CANTIDAD ; I++)
        if (DATO[I].DISPONIBLE){
            DATO[I].DISPONIBLE = 0 ;
            CANTIDAD--;
            printf("\n\t%d\t%20s\t%d",DATO[I].LEGAJO , DATO[I].NOM , DATO[I].NOTA[CODIGO]);
        }
    }
}

INGRESO (struct SOLDADO FICHA[] , int N)
{
    int I ;
    int J ;

    for(I=0 ; I<N ; I++){
        printf("\n legajo  : ");
        scanf("%d", &FICHA[I].LEGAJO);
        fflush(stdin);
        printf("\n nombre  : ");
        gets(FICHA[I].NOM) ;
        printf("\n notas : ");

        for(J=0 ; J<MAX_MAT ; J++)
            scanf("%d", &FICHA[I].NOTA[J]);
        FICHA[I].DISPONIBLE = 1 ;
    }


}

ORDENA(struct SOLDADO FICHA [] , int N , int CODIGO)
{

    int I,J;
    struct SOLDADO AUX;
    for(I=0 ; I<N-1 ; I++)
        for(J=0 ; J<N-I-1 ; J++)
    if(FICHA[J].NOTA[CODIGO] < FICHA[J+1].NOTA[CODIGO]){

        AUX        =   FICHA[J] ;
        FICHA[J]   =   FICHA[J+1];
        FICHA[J+1] =   AUX;
    }
}
