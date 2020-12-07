#include<stdio.h>
#include<stdlib.h>

#define N 3

void CARGAR(int [] , char [] , int);

void ORDEN (int [] , char [] , int);

void MIRAR (int [] , char [] , int);

int  BUSCAR(int [] , char [] , int);

int main()
{
    int DOCUMENTOS[N];
    char EDADES[N];

    CARGAR(DOCUMENTOS,EDADES,N);

    ORDEN (DOCUMENTOS,EDADES,N);

    MIRAR(DOCUMENTOS,EDADES,N);


}
void CARGAR(int DOCU[] , char EDAD [] , int L)
{
    int I=0,DNI;
    char NUMERO_EDAD;

    while(I<L)
        {
            fflush;

            printf(" ingrese documento ");



            scanf("%d",&DNI);


            DOCU[I]=DNI;



            fflush;

            printf(" ingrese edad ");


            scanf("%s",EDAD);

            fflush;

            I++;

        }
}

void ORDEN(int DOCU[] , char EDAD [] ,int L)
{
    int I,J,AUX_DOCU;
    char AUX_EDAD;

    for(I=0 ; I<L-1 ; I++)
        for(J=0 ; J<L-I-1 ; J++)
            if( DOCU[J]< DOCU[J+1])
            {

                AUX_DOCU  = DOCU[J];
                DOCU[J]   = DOCU[J+1];
                DOCU[J+1] = AUX_DOCU;

                AUX_EDAD  =  EDAD[J];
                EDAD[J]   =  EDAD[J+1];
                EDAD[J+1] =  AUX_EDAD;


            }

}
void MIRAR(int DOCU[] , char EDAD [] , int L)
{
    int I,B;

    printf("\n\n DOCUMENTO\t\tEDAD\n\n");

    for(I=0 ; I<L ; I++)
        {
           printf("\n\n %d\t\t%c\n\n",DOCU[I],EDAD[I]);

        }

        B=BUSCAR(DOCU,EDAD,L);

        if(B>0)
            {
                printf("\n\nse encontro el DOCUMENTO %d\t\tEDAD\t %c",DOCU[B],EDAD[B]);

            }
        else printf("No se encontro docu");










}

int BUSCAR (int DOCU[] , char EDAD [] ,int L)

{
    int BUSQUEDA=0;
    int BAJO=0;
    int ALTO=L-1;
    int MED=0;

    printf("ingrese documento a buscar");
    scanf("%d",&BUSQUEDA);

    while(BAJO<=ALTO)
        {
            MED=(BAJO+ALTO)/2 ;

            if(DOCU[MED]==BUSQUEDA)
                return MED;

            if(BUSQUEDA<DOCU[MED])
                ALTO=MED-1;

            else
                BAJO=MED+1;
        }
        return -1;

}




