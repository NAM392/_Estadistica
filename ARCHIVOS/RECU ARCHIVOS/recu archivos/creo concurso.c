#include<stdio.h>
#include<string.h>

struct concurso {
    char nombre[20];
    int long dni;
    int puntos;

};

int main()
{


    struct concurso con;

    FILE*FC;

    if(!(FC = fopen("CONCURSO.DAT" , "wb"))){
        printf("error al crear");
    }


    for(int I = 0 ; I<10 ; I++){
             printf("nombre  ");
            fflush(stdin);
            gets(con.nombre);
             printf("dni  ");
            fflush(stdin);
            scanf("%d" , &con.dni );
            con.puntos = 1;
            fwrite(&con , sizeof(con) , 1 , FC);
    }

    fclose(FC);

















}
