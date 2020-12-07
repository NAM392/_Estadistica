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
	FILE * archCONCURSO = fopen("CONCURSO.DAT", "rb");
	
	if(archCONCURSO == 0)
	{
		printf("\nHubo un error abriendo el archivo CONCURSO.DAT");
		exit (1);
	}
	
	int i;
	
	fread(&cliente, sizeof(cliente), 1, archCONCURSO);
	while(feof(archCONCURSO) == 0)
	{
		printf("\n%s %d %d",cliente.nombre, cliente.dni, cliente.puntos);
		
		fread(&cliente, sizeof(cliente), 1, archCONCURSO);
	}
	
	fclose(archCONCURSO);
}
