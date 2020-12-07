#include <stdio.h>
#include <stdlib.h>
#include <string.h>
////////////////////////////////ESTRUCTURAS////////////////////////////////////////
struct{
	char nombre[20];
}llamada, auxLlamada;

struct{
	char nombre[20];
	int voto;
}candidato, auxCandidato;
///////////////////////////////DECLARACIONES//////////////////////////////////////
int main()
{
	FILE * archLLAMADAS1 = fopen("LLAMADAS.DAT", "rb");
	FILE * archLLAMADAS2 = fopen("LLAMADAS.DAT", "rb");
	FILE * archVOTOS = fopen("VOTOS.DAT", "wb");
	fclose(archVOTOS);
		
	if(archLLAMADAS1 == 0)
	{
		printf("Hubo un error con LLAMADAS.DAT");
		exit(1);
	}
	
	if(archLLAMADAS2 == 0)
	{
		printf("Hubo un error con LLAMADAS.DAT");
		exit(2);
	}
	
	if(archVOTOS == 0)
	{
		printf("Hubo un error creando VOTOS.DAT");
		exit(3);
	}
	
	if(archVOTOS == 0)
	{
		printf("Hubo un error creando VOTOS.DAT");
		exit(4);
	}
	
	int FLAG;
	
	fread(&llamada, sizeof(llamada),1, archLLAMADAS1); 
	while(feof(archLLAMADAS1) == 0) 
	{
		FLAG = 0;
		
		archVOTOS = fopen("VOTOS.DAT", "rb");
		fread(&auxCandidato, sizeof(auxCandidato), 1, archVOTOS);
		while(feof(archVOTOS) == 0)
		{
			if(strcmp(llamada.nombre, auxCandidato.nombre) == 0)
			{
				FLAG = 1;
			}
						
			fread(&auxCandidato, sizeof(auxCandidato), 1, archVOTOS); 
		}
		fclose(archVOTOS);
		
		if(FLAG == 0)
		{
			strcpy(candidato.nombre, llamada.nombre);
			candidato.voto = 0;
			
			fread(&auxLlamada, sizeof(auxLlamada), 1, archLLAMADAS2);
			
			while(feof(archLLAMADAS2) == 0)
			{
				if(strcmp(auxLlamada.nombre, llamada.nombre) == 0 )
				{
					candidato.voto++;
				}
					
				fread(&auxLlamada, sizeof(auxLlamada), 1, archLLAMADAS2);
			}
			rewind(archLLAMADAS2);
			
			archVOTOS = fopen("VOTOS.DAT", "a");
			fwrite(&candidato, sizeof(candidato), 1 , archVOTOS); 
			fclose(archVOTOS);
		}
	
		fread(&llamada, sizeof(llamada), 1, archLLAMADAS1);
	}
	
////////////////////////////////BUSCAR EL QUE TIENE MÁS VOTOS///////////////////////
	int MAYOR = 0;
	char GANADOR[20];
	archVOTOS = fopen("VOTOS.DAT", "rb");
	
	fread(&auxCandidato, sizeof(auxCandidato), 1, archVOTOS);
	
	while(feof(archVOTOS) == 0)
	{
		//---------------------------------//
		if(auxCandidato.voto > MAYOR)
		{
			MAYOR = auxCandidato.voto;
			strcpy(GANADOR, auxCandidato.nombre);
		}
		//---------------------------------//
		
		fread(&auxCandidato, sizeof(auxCandidato), 1, archVOTOS);
	}
	
	printf("\n EL GANADOR ES %s CON %d VOTOS\n", GANADOR, MAYOR);
	
/////////////////////////////////CIERRE DE ARCHIVOS/////////////////////////////////
	fclose(archLLAMADAS1);
	fclose(archLLAMADAS2);
	fclose(archVOTOS);
}
