#include <stdio.h>
int main()
{

    struct{
          char nombre[20];
          char sexo;
          int edad;
          }datos;

    FILE*puntero;
    int I;

   	if ( (puntero = fopen("datos.dat","rb")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;
		}

	fread(&datos , sizeof(datos ), 1 , puntero);
	while ( !feof(puntero)){
                printf("\\")
	}
















}
