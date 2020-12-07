#include<stdio.h>
#include<string.h>

struct LLAMADA {
    char nombre[20];
};

struct VOTOS{
    char nombre[20];
    int votos;
};

int main()
{

    struct VOTOS vot , X , Y ;
    FILE*FV;
    int i , j;
    int N=0 ;

    if(!(FV = fopen("votos.dat" , "r+b"))){
        printf("error");
    }

    fseek(FV , 0L , SEEK_END);
    N = ftell(FV)/sizeof(vot);

    for (i=0 ; i<N-1 ; i++)
        for(j=0 ; j<N-i-1 ; j++){
            fseek(FV , (long)j*sizeof(vot) , SEEK_SET);
            fread(&X , sizeof(X) , 1 , FV);
            fread(&Y , sizeof(Y) , 1 , FV);
            if(strcmp(X.nombre , Y.nombre) >0 ){
                fseek(FV , (long)j*sizeof(vot) , SEEK_SET);
                fwrite(&Y , sizeof(Y) , 1 , FV);
                fwrite(&X , sizeof(X) , 1 , FV);

            }
    }

    rewind(FV);

    fread(&vot , sizeof(vot) , 1 , FV);
    while(!feof(FV)){
        printf("   %s     %d  \n" , vot.nombre , vot.votos );
        fread(&vot , sizeof(vot) , 1 , FV);

    }





}
