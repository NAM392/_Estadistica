#include<stdio.h>
#include<string.h>

#define MAX 20
#define NUM 10

int main()
{

    char MAT[NUM][MAX] , palabra[MAX];
    int I , POS = -1;
    printf("ingrese 10 palabras . \n\n");

    //ingreso
    for(I=0 ; I<NUM ; I++)
    {
        printf("palabra %3d : ",I+1) ;
        gets(MAT[I]);

    }

    printf("\n\ningrese palabra a buscar : ");
    gets(palabra);

    //busqueda
    for(I=0 ; (I<NUM)&&(POS==-1) ; I++)
        if ( !strcmp(MAT[I] , palabra))

            POS= I ;

    //impresion
    printf("\n\nvector de busqueda \n");
    for(I=0 ; I<NUM ; I++)
        printf("\n%10d\t%s" , I , MAT[I]);
    printf("\n\n");

    if(POS==-1)
        printf("%s no se encontro",palabra);
    else
        printf("%s esta en la posicion %d",palabra,POS);

    printf("\n\nfin del programa");







}
