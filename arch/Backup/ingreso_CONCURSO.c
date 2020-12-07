#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct{
	char nombre[20];
	long int dni;
	int puntos;
}cliente;

int main()
{
	FILE * archCONCURSO = fopen("CONCURSO.DAT", "wb");
	
	if(archCONCURSO == 0)
	{
		printf("\nHubo un error creando el archivo CONCURSO.DAT");
		exit (1);
	}
	
	int i;
	
	for(i = 0; i < 6 ; i++)
	{
		printf("\nIngrese Nombre del cliente: ");
		fflush(stdin);
		gets(cliente.nombre);
		printf("\nIngrese dni del cliente: ");
		scanf("%d", &cliente.dni);
		printf("\nIngrese puntos del cliente: ");
		scanf("%d", &cliente.puntos);
	
	fwrite(&cliente, sizeof(cliente), 1 , archCONCURSO );
	}
	
	fclose(archCONCURSO);
}
