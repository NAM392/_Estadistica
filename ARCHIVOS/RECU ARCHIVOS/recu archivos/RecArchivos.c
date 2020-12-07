#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LLAMADAS{
	char nombre[20];
};

struct VOTOS {
	char nombre[20];
	int voto;
};

int main()
{
    struct LLAMADAS llamada , aux;
    struct VOTOS candidato, auxCandidato;


	FILE * aux1;
	FILE * aux2;
	FILE * FV;

	if(!(aux1 = fopen("LLAMADAS.DAT", "rb"))){
        printf("error al abrir llamadas");
	}

    if(!(aux2 = fopen("LLAMADAS.DAT", "rb"))){
        printf("error al abrir llamadas 2da vez");
	}
    if(!(FV = fopen("VOTOS.DAT", "wb"))){
        printf("error al abrir llamadas 2da vez");
	}
	fclose(FV);

	int FLAG;

	fread(&llamada, sizeof(llamada),1, aux1);
	while(! feof(FV)) {
		FLAG = 0;

        if(!(FV = fopen("VOTOS.DAT", "rb"))){
            printf("error al abrir votos");
        }
		fread(&candidato, sizeof(candidato), 1 , FV );
		while(!feof(FV))
		{
			if(strcmp(llamada.nombre, auxCandidato.nombre) == 0)
			{
				FLAG = 1;
			}

			fread(&auxCandidato, sizeof(auxCandidato), 1, FV);
		}
		fclose(FV);

		if(FLAG == 0)
		{
			strcpy(candidato.nombre, llamada.nombre);
			candidato.voto = 0;

			fread(&aux, sizeof(aux), 1, aux2);

			while(!feof(aux2))
			{
				if(strcmp(auxCandidato.nombre, llamada.nombre) == 0 )
				{
					candidato.voto++;
				}

				fread(&aux, sizeof(aux), 1, aux2);
			}
			rewind(aux2);

        if(!(FV = fopen("VOTOS.DAT", "a"))){
            printf("error al agregar");
	}
			fwrite(&candidato, sizeof(candidato), 1 , FV);
			fclose(FV);
		}

		fread(&llamada, sizeof(llamada), 1, aux1);
	}

////////////////////////////////BUSCAR EL QUE TIENE MÁS VOTOS///////////////////////
	int MAYOR = 0;
	char GANADOR[20];
	    if(!(FV = fopen("VOTOS.DAT", "rb"))){
        printf("error al abrir llamadas 2da vez");
	}

	fread(&auxCandidato, sizeof(auxCandidato), 1, FV);

	while(!feof(FV))
	{

		if(auxCandidato.voto > MAYOR)
		{
			MAYOR = auxCandidato.voto;
			strcpy(GANADOR, auxCandidato.nombre);
		}


		fread(&auxCandidato, sizeof(auxCandidato), 1, FV);
	}

	printf("\n EL GANADOR ES %s CON %d VOTOS\n", GANADOR, MAYOR);


	fclose(aux1);
	fclose(aux2);
	fclose(FV);
}
