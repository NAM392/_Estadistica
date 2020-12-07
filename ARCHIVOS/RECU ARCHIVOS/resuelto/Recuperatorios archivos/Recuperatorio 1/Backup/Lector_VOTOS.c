#include <stdio.h>
#include <stdlib.h>

struct{
	char nombre[20];
	int voto;
}VOTOS;

int main()
{
	FILE *puntero1;
	
	puntero1 = fopen("VOTOS.DAT", "rb");

	
	if(puntero1 == NULL)
	{
		printf("Hubo un error con VOTOS.DAT");
		exit(1);
	}
	
	printf("CONTENIDO DE LA BASE DE DATOS...\n\n ");
		
	fread(&VOTOS, sizeof(VOTOS), 1, puntero1);
	while(feof(puntero1)==0)
	{
		printf("\n%s fue votado por %d.", VOTOS.nombre, VOTOS.voto );
		fread(&VOTOS, sizeof(VOTOS), 1, puntero1);
	}
	
	fclose(puntero1);
	
	
}
