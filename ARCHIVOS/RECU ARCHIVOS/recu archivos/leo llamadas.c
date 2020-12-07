#include<stdio.h>

struct llamadas {
    char votantes [20];
};

struct VOTOS {
    char nombre [20];
    int voto;
};


int main()
{

    struct llamadas per;
    struct VOTOS vot;

    FILE*FLL;
    FILE*FV;

    if(!(FLL = fopen("LLAMADAS.DAT" , "rb"))){
        printf("error al abrir llamadas");

    }

   fread(&per , sizeof(per) , 1 , FLL);

   while(!feof(FLL)){
        printf("%s\n",per.votantes);
         fread(&per , sizeof(per) , 1 , FLL);

   }

    fclose(FLL);
    printf("\n\n\t");

    if(!(FV = fopen("VOTOS.DAT" , "rb"))){
        printf("error al abrir votos");

    }

   fread(&vot , sizeof(vot) , 1 , FV);

   while(!feof(FV)){
        printf("%s  \t %d \n",vot.nombre , vot.voto);
         fread(&vot , sizeof(vot) , 1 , FV);

   }

   fclose(FV);






}
