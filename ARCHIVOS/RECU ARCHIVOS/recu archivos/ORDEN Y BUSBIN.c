#include<stdio.h>
#include<string.h>
struct datos {
    char nombre[20];
    char sexo;
    int edad;
};


int main()
{
    struct datos DAT , X , Y ;
    FILE*FD;
    int MIN , MAX , ENCONTRADO = 0 , MED ;
    int I , J ;
    char BUSCAR [20];

    if(!(FD = fopen("DATOS.DAT" , "r+b"))){
        printf("error al leer archivo");
    }

    fseek(FD , 0L , SEEK_END);
    fread(&DAT , sizeof(DAT) , 1 , FD);
    int N = (long)ftell(FD)/sizeof(X);
    for(I=0 ; I<N-1 ; I++)
        for(J=0 ; J<N-I-1 ; J++){
            fseek(FD , (long)J*sizeof(DAT) , SEEK_SET);
            fread(&X , sizeof(X) , 1 , FD );
            fread(&Y , sizeof(Y) , 1 , FD );

            if(strcmp(X.nombre , Y.nombre )>0){
                fseek(FD , (long)J*sizeof(DAT) , SEEK_SET);
                fwrite(&Y , sizeof(Y) , 1 , FD);
                fwrite(&X , sizeof(X) , 1 , FD);

            }
        }

        fclose(FD);

        if(!(FD = fopen("DATOS.DAT" , "rb"))){
            printf("error al leer dat");
        }

        printf("ingrese nombre a buscar  : ");
        gets(BUSCAR);

        MIN = 0;
        MAX = N-1;

        while(MIN <= MAX && !ENCONTRADO){
            MED = (MAX+MIN)/2 ;
            fseek(FD , (long)MED*sizeof(DAT) , SEEK_SET);
            fread(&DAT , sizeof(DAT) , 1 , FD);
            if (strcmp(DAT.nombre , BUSCAR) == 0){
                ENCONTRADO = 1;
            }
            else
                if (strcmp(BUSCAR , DAT.nombre) < 0){
                    MAX = MED -1;
                }
                else {
                    MIN = MED + 1 ;
                }
        }

        if( ENCONTRADO ){
            printf("lo encontre");
        }
        else {printf("no lo encontre");}


}














