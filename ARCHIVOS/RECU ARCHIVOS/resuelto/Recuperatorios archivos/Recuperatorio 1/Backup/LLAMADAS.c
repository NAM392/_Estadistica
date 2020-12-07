#include <stdio.h>
#include <stdlib.h>

struct{
	char nombre[20];
}LLAMADAS;

int main()
{
	FILE *puntero1;
	int cantidad, i;
	
	puntero1 = fopen("LLAMADAS.DAT", "wb");

	
	if(puntero1 == NULL)
	{
		printf("Hubo un error con LLAMADAS.DAT");
		exit(1);
	}
	
	printf("Ingrese la cantidad de registros que tendra la base de datos: ");
	scanf("%d", &cantidad);
	fflush(stdin);
	
	for(i = 0; i < cantidad; i++)
	{
		printf("\nIngrese nombre: ");
		gets(LLAMADAS.nombre);
		fwrite(&LLAMADAS, sizeof(LLAMADAS), 1, puntero1);
	}
	
	fclose(puntero1);
	
	
}
	
