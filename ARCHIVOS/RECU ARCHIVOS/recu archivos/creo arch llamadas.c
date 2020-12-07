#include<stdio.h>

struct llamadas {
    char votantes [20];
};

int main()
{

    struct llamadas per;

    FILE*FP;

    if(!(FP = fopen("LLAMADAS.DAT" , "wb"))){
        printf("error al escribir archivo");
    }

    fread(&per , sizeof(per) , 1 ,FP);
     printf("\ningrese nombre\n");
    for(int I=0 ; I<5 ; I++){

        fflush(stdin);
        gets(per.votantes);


        fwrite(&per , sizeof(per) , 1 ,FP);

    }

fclose(FP);









}
