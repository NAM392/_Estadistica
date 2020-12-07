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
    struct LLAMADA nl , laux  ;
    struct VOTOS vot;
    FILE * FLL;
    FILE*FV;
    FILE * FAUX;
    int i , j;
    int N ,  cont=0 , flag=0;
    char aux[20];

    if(!(FLL = fopen("llamadas.dat" , "rb"))){
        printf("error al abrir archivo");
    }

    if(!(FV = fopen("votos.dat" , "wb"))){
        printf("error");
    }

    if(!(FAUX = fopen("llamadas.dat" , "rb"))){
        printf("2da aper");
    }

    fread(&nl , sizeof(nl) , 1 ,FLL);
    fread(&laux , sizeof(laux) , 1 ,FAUX);
    while(!feof(FLL)){
            cont = 0;
            strcpy(aux , nl.nombre);
            rewind(FAUX);
            fread(&laux , sizeof(laux) , 1 ,FAUX );
            while(!feof(FAUX)){
                if(strcmp(aux , laux.nombre)==0){
                    cont++;
                }
                fread(&laux , sizeof(laux) , 1 , FAUX);
            }
            rewind(FAUX);
            fseek(FV , 0L , SEEK_END);
            N = ftell(FV);
            if(N == 0){
                strcpy(vot.nombre , aux);
                vot.votos = cont;
                fwrite(&vot , sizeof(vot) , 1 , FV);
                fclose(FV);
            }

            else {
                    if(!(FV = fopen("votos.dat" , "rb"))){
                        printf("error");
                    };
                    fread(&vot , sizeof(vot) , 1 , FV);
                    while(!feof(FV)){
                        if(strcmp(aux , vot.nombre)==0){
                            flag=1;
                        }
                        fread(&vot , sizeof(vot) , 1 , FV);
                    };
                    fclose(FV);

                    if(flag == 0){
                        if(!(FV = fopen("votos.dat" , "ab"))){
                            printf("error");
                        };
                        strcpy(vot.nombre , aux);
                        vot.votos = cont;
                        fwrite(&vot , sizeof(vot) , 1 , FV);
                        fclose(FV);

                    }


            }
            fread(&nl , sizeof(nl) , 1 ,FLL);
    }

    fclose(FV);

    if(!(FV = fopen("votos.dat" , "rb"))){
        printf("error");
    };
    fread(&vot , sizeof(vot) , 1 , FV);
    while(!feof(FV)){
        printf("  %s   %d  \n" , vot.nombre , vot.votos);
        fread(&vot , sizeof(vot) , 1 , FV);
    }
    fclose(FV);

















}

