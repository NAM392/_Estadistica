#include<stdio.h>
#include<string.h>

struct concurso {
    char nombre[20];
    int long dni;
    int puntos;

};

int numveces(char [] , FILE*);

int main()
{


    struct concurso con ;
    int cont=0;

    int MAX = 0;
    char MAX_nombre [20];
    int veces = 0;

    FILE*FC;
    FILE*AUX;

    if(!(FC = fopen("CONCURSO.DAT" , "rb"))){
        printf("error al abrir");
    }
    if(!(AUX = fopen("CONCURSO.DAT" , "rb"))){
        printf("error al abrir 2");
    }

    fread(&con , sizeof(con) , 1 , FC);

    while(!feof(FC)){

            veces = numveces(con.nombre , AUX);
            if(veces > MAX ){
                MAX = veces;
                strcpy(MAX_nombre , con.nombre);
            }
            fread(&con , sizeof(con) , 1 , FC);
    }

       printf("el ganador del concurso es %s con %d votos", MAX_nombre , MAX );




    }

int numveces(char nombre[] , FILE*puntero)
{

    struct concurso con ;
    int cont=0;

    rewind(puntero);
    fread(&con , sizeof(con) , 1 , puntero);
    while(!feof(puntero)){
           /* printf("\n%s\n" , con.nombre);*/
        if(strcmp(nombre , con.nombre)==0){
            cont ++;
        }
        fread(&con , sizeof(con) , 1 , puntero);

    }
    return cont;





















    }


