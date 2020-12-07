#include <stdio.h>
#include <stdlib.h>

struct{
	char nombre[20];
}LLAMADAS;

int main()
{
	FILE *puntero1;
	
	puntero1 = fopen("LLAMADAS.DAT", "rb");

	
	if(puntero1 == NULL)
	{
		printf("Hubo un error con LLAMADAS.DAT");
		exit(1);
	}
	
	printf("CONTENIDO DE LA BASE DE DATOS...\n\n ");
		
	fread(&LLAMADAS, sizeof(LLAMADAS), 1, puntero1);
	while(feof(puntero1)==0)
	{
		printf("\n%s", LLAMADAS.nombre );
		fread(&LLAMADAS, sizeof(LLAMADAS), 1, puntero1);
	}
	
	fclose(puntero1);
	
	
}
