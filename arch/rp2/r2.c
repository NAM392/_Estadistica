#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct{
	char nombre[20];
	long int dni;
	int puntos;
}clienteP1, clienteP2, clienteDEP;

int main()
{
	FILE * archCONCURSOP1 = fopen("CONCURSO.DAT", "rb");
	FILE * archCONCURSOP2 = fopen("CONCURSO.DAT", "rb");
	FILE * archDEPURADO = fopen("DEPURADO.DAT", "wb");
	fclose(archDEPURADO);
	
	if(archCONCURSOP1 == 0)
	{
		printf("\nHubo un error abriendo CONCURSO.DAT");
		exit(1);
	}
	
	if(archCONCURSOP2 == 0)
	{
		printf("\nHubo un error abriendo CONCURSO.DAT");
		exit(2);
	}
	
	int EXISTE = 0;
	
	fread(&clienteP1, sizeof(clienteP1), 1, archCONCURSOP1);
	while(feof(archCONCURSOP1) == 0)
	{
		EXISTE = 0;
		archDEPURADO = fopen("DEPURADO.DAT", "rb");
		fread(&clienteDEP, sizeof(clienteDEP), 1, archDEPURADO);
		
		while(feof(archDEPURADO) == 0)
		{
			
			
			if(strcmp(clienteP1.nombre, clienteDEP.nombre) == 0)
			{
				EXISTE = 1;
			}
			fread(&clienteDEP, sizeof(clienteDEP), 1, archDEPURADO);
		}
		fclose(archDEPURADO);
		
		if(EXISTE == 0)
		{
			strcpy(clienteDEP.nombre, clienteP1.nombre);
			clienteDEP.dni = clienteP1.dni;
			clienteDEP.puntos = 0;
			
			fread(&clienteP2,sizeof(clienteP2), 1, archCONCURSOP2);
			while(feof(archCONCURSOP2) == 0)
			{
				if(strcmp(clienteP2.nombre, clienteP1.nombre) == 0)
				{
					clienteDEP.puntos = clienteDEP.puntos + clienteP2.puntos;
				}
				fread(&clienteP2,sizeof(clienteP2), 1, archCONCURSOP2);
			}
			rewind(archCONCURSOP2);
			archDEPURADO = fopen("DEPURADO.DAT", "a");
			fwrite(&clienteDEP, sizeof(clienteDEP), 1 , archDEPURADO);
			fclose(archDEPURADO);
		}
		fread(&clienteP1, sizeof(clienteP1), 1, archCONCURSOP1);
	}
	
	fclose(archCONCURSOP1);
	fclose(archCONCURSOP2);
	remove("CONCURSO.DAT");
	rename("DEPURADO.DAT", "CONCURSO.DAT");
	
}
