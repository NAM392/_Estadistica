
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct concurso {
    char nombre[20];
    int long dni;
    int puntos;

};



int main()
{


    struct concurso per , X , Y;
    FILE *FP ;
    int  I , J  , MIN , MAX , ENCONTRADO , MED;
    long int N ;
    char BUSCADO[20];

    if(!(FP = fopen("CONCURSO.DAT" , "r+b"))){
        printf("concu");

    }


    /*fread(&per , sizeof(per) , 1 , FP);*/
    fseek(FP , 0L , SEEK_END);
    N = ftell(FP)/sizeof(X);
    printf("el archivo tiene %d elementos" , N);

    for(I=0 ; I<N-1 ; I++)
        for(J=0 ; J<N-I-1 ; J++){
            fseek(FP , (long)J*sizeof(per) , SEEK_SET);
            fread(&X , sizeof(X) , 1 , FP);
            fread(&Y , sizeof(Y) , 1 , FP);

            if(strcmp(X.nombre , Y.nombre )>0){
                fseek(FP , (long)J*sizeof(per) , SEEK_SET);
                fwrite(&Y , sizeof(Y) , 1 , FP);
                fwrite(&X , sizeof(X) , 1 , FP);
            }


    }

    fclose(FP);

    MIN = 0;
    MAX = N-1;
    ENCONTRADO = 0;

    while(MIN<=MAX && !ENCONTRADO){
        MED = (MAX + MIN)/2;
        fseek(FP , (long)MED*sizeof(X) ,    SEEK_SET);
        fread(&per , sizeof(per) , 1 , FP);

        if(strcmp(per.nombre , BUSCADO)==0){
            ENCONTRADO = 1;
        }
        else if (strcmp(per.nombre , BUSCADO)<0){
            MAX = MED - 1 ;
        }
        else {
              MIN = MED + 1;
        }
    }




    }
