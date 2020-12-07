#include<stdio.h>
#include<string.h>

struct VOTOS {
    char nombre [20];
    int voto;
};

struct llamadas {
    char nombre [20];
};

int main(){

    struct VOTOS vot;
    struct llamadas per , X , Y , auxLL ;
    int N;

    FILE*FV;
    FILE*FLL;
    FILE*AUX;
    FILE*auxi;

    char aux_nombre[20];
    int cont = 0;

    if(!(FLL = fopen("LLAMADAS.DAT" , "r+b"))){
        printf("error apertura de archivo");
        return 1;
    }

    fread(&per , sizeof(per) , 1 , FLL);

    fseek(FLL , 0L , SEEK_END);
    N = ftell(FLL) / sizeof(X);
    printf("\n\n  EL ARCHIVO TIENE %d REGISTROS " , N);

    for(int I=0 ; I<N-1 ; I++)
        for(int J=0 ; J<N-I-1 ; J++){
                fseek(FLL , (long)J*sizeof(X) ,SEEK_SET);
                fread(&X , sizeof(X) , 1 , FLL);
                fread(&Y , sizeof(Y) , 1 , FLL);

                if(strcmp(X.nombre , Y.nombre)>0){
                    fseek(FLL , (long)J*sizeof(X) ,SEEK_SET);
                    fwrite(&Y , sizeof(Y) , 1 ,FLL );
                    fwrite(&X , sizeof(X) , 1 , FLL);
                }
        }
        fclose(FLL);

        if(!(FLL = fopen("LLAMADAS.DAT" , "rb"))){
            printf("error 2da apertura de archivo");
            return 1;
        }


    /*    if(!(AUX = fopen("LLAMADAS.DAT" , "rb"))){
            printf("error al abrir archivo 2DA");
            return 1;
        }*/
        if(!(FV = fopen("VOTOS.DAT" , "wb"))){
            printf("error escritura de archivo");
            return 1;
        }
        if(!(auxi = fopen("LLAMADAS.DAT" , "rb"))){
            printf("error 2da apertura de archivo");
            return 1;
        }


        fread(&per , sizeof(per) , 1 , FLL);
       /* fread(&per , sizeof(per) , 1 , AUX);*/
        fread(&auxLL , sizeof(auxLL) , 1 , auxi);



        while(!feof(auxi)){

                   strcpy(aux_nombre , auxLL.nombre);
                   strcpy(vot.nombre , auxLL.nombre);
                   fwrite(&vot , sizeof(vot) , 1 , FV);
                   rewind(FLL);
                   while(!feof(FLL)){
                            if(strcmp(aux_nombre , per.nombre)!= 0 ){
                                strcpy(aux_nombre , per.nombre);
                                strcpy(aux_nombre , per.nombre);
                                fread (&per , sizeof(per) , 1 , FLL);
                                fwrite(&vot , sizeof(vot) , 1 , FV );
                            }
                            fread (&per , sizeof(per) , 1 , AUX);
                   }
        }

}

/*int nombres(char nombre[] , FILE*puntero , variable char)
{
    struct llamadas per;

    fread(&ini , sizeof(ini) , 1 , puntero)

    rewind(puntero);

    while(!feof(puntero)){
        if(strcmp(nombre , per.nombre) == 0){
                cont++;
        }
        variable = per.nombre;
        fread(&ini , sizeof(ini) , 1 , puntero)
    }

    return cont;



}









}*/
