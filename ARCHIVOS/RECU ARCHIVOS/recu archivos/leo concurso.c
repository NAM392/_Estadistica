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

    if(!(FC = fopen("CONCURSO.DAT" , "rb"))){
        printf("error al crear");
    }
    fread(&con , sizeof(con) , 1 , FC);
    while(!feof(FC)){
        printf("\n%10s%10d%10d" , con.nombre , con.dni , con.puntos);
        fread(&con , sizeof(con) , 1 , FC);
    }

    fclose(FC);





}
