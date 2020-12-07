#include<stdio.h>
#define N 2
#define T 20

struct FECHA{
    int DIA;
    int MES;
    int ANIO;
};

struct ALUMNO {
    char NOMBRE[T];
    struct FECHA NACIM ;
    float PROMEDIO;
};

//prototipos
void INGRESAR( struct ALUMNO [] , int);
void ORDENAR ( struct ALUMNO [] , int);
void IMPRIMIR ( struct ALUMNO [], int );
unsigned int DIAS ( struct FECHA) ;

int main (void)
{

    struct ALUMNO DATO [N];

    INGRESAR (DATO , N);
    ORDENAR ( DATO , N);
    IMPRIMIR ( DATO , N);



}
void INGRESAR ( struct ALUMNO V [] , int NUM)
{
    int I;
    float F;

    for(I=0 ; I<NUM ; I++)
    {
        printf("ingrese el nombre del alumno  : ");

        fflush(stdin);
        gets(V[I].NOMBRE);

        printf("ingrese la fecha con forma DD-MM-AA  : ");
        scanf("%d-%d-%d",&V[I].NACIM.DIA , &V[I].NACIM.MES , &V[I].NACIM.ANIO);


/*unsigned int DIAS(struct FECHA date)
{

    long X ;
    X= 365*date.ANIO + 31*date.MES + date.DIA ;
    return X;



}*/

        fflush(stdin);

        printf("ingrese el promedio del alumno ");
        scanf("%f",&F);
        V[I].PROMEDIO = F ;

        fflush(stdin);
    }



}

void ORDENAR ( struct ALUMNO V[] , int NUM)
{

    struct ALUMNO AUX ;
    int I , J ;

    for(I=0 ; I< NUM-1 ; I++)
        for(J=0 ; J<NUM-I-1 ; J++)
            if ( DIAS(V[J].NACIM) < DIAS(V[J+1].NACIM) )
                {
                        AUX     =   V[J];
                        V[J]    =   V[J+1];
                        V[J+1]  =   AUX;
                }



}
void IMPRIMIR (struct ALUMNO V [] , int NUM)
{
    int I;
    for(I=0 ; I<NUM ; I++)
      printf("\n%20s%10d%4d%4d%12.2f",V[I].NOMBRE, V[I].NACIM.DIA , V[I].NACIM.MES , V[I].NACIM.ANIO ,V[I].PROMEDIO);
}
unsigned int DIAS(struct FECHA date)
{

    long X ;
    X= 365*date.ANIO + 31*date.MES + date.DIA ;
    return X;



}








