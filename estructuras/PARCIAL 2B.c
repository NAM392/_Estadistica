#include<stdio.h>

#define N 20
#define ALU 5
#define MAT 3



struct DATOS{

    char   NOMBRE[N];
    float  NOTAS[MAT]

};


void CARGAR   (struct DATOS [] , int  , int );
int REPROBADOS(struct DATOS [] , int  , int );
void ordenados(struct DATOS [] , int  , int );
void IMPRIME  (struct DATOS [] , int  , int );

int main()
{

    struct DATOS ALUMNOS[ALU];
    int X;
    int MATERIA;

    CARGAR(ALUMNOS , ALU , MAT) ;


    printf("CONSULTA MATERIA  : ");
    scanf("%d",&MATERIA);
    X = REPROBADOS(ALUMNOS, MAT , MATERIA);
    printf("reprobaron %d alumnos ",X);


    ordenados(ALUMNOS , ALU , MATERIA );

    IMPRIME(ALUMNOS , ALU , MATERIA);

}


void CARGAR(struct DATOS ALUMNOS [] , int A , int M )
{
    int I , J ;
    for(I=0 ; I<A ; I++)
       {
            printf("ingrese nombre de alumno  : ");
            fflush(stdin);
            gets(ALUMNOS[I].NOMBRE);


            for(J=0 ; J<M ; J++)
               {
                    fflush(stdin);
                  printf("INGRESE NOTAS  : ");

                  scanf("%f",&ALUMNOS[I].NOTAS[J]);
                    fflush(stdin);
               }

       }

}
int REPROBADOS(struct DATOS ALUMNOS[], int M , int MATERIA)
{
    int I;
    int cont=0 ;

    for(I=0 ; I<ALU ; I++)
    {

        if((ALUMNOS[I].NOTAS[MATERIA]) <= 4)          //desaprobas con 4
            {

             printf("\t\t\n\nALUMNO\t %s\t DESAPROBO LA MATERIA\t %d \n\n",ALUMNOS[I].NOMBRE , MATERIA );
             cont++;

            }

    }



           return cont;



}

void ordenados(struct DATOS ALUMNOS [], int M , int MATERIA)
{

    printf("lala");
    struct DATOS AUX;
    int I , J ;

    for(I=0 ; I<ALU-1 ; I++)
        for(J=0 ; J<ALU-I-1 ; J++)
            if ((ALUMNOS[J].NOTAS[MATERIA]) < (ALUMNOS[J+1].NOTAS[MATERIA]))

                {

                        AUX          = ALUMNOS[J];
                        ALUMNOS[J]   = ALUMNOS[J+1];
                        ALUMNOS[J+1] = AUX;
                }

           if((ALUMNOS[J].NOTAS[MATERIA]) <=4)
                {


                    if(strcmp((ALUMNOS[J].NOMBRE , ALUMNOS[J+1].NOMBRE) > 0))

                    {

                        AUX          = ALUMNOS[J];
                        ALUMNOS[J]   = ALUMNOS[J+1];
                        ALUMNOS[J+1] = AUX;

                    }

                }


}


void IMPRIME(struct DATOS ALUMNOS [] , int M , int MATERIA)
{
    int I;

    for(I=0 ; I<M ; I++)
        printf(" \n\n\t ALUMNO\t\t%s\t\t NOTA \t\t%f\t\t\n", ALUMNOS[I].NOMBRE ,ALUMNOS[I].NOTAS[MATERIA] );



}
