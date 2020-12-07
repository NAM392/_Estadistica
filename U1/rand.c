#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alea(int desde, int hasta)
{
	return rand()%(hasta-desde+1)+desde;
}

int main()
{
	int i;

	/* Conseguimos una semilla con la fecha */
	srand(time(NULL));

	/* Usamos la función para obtener números */
	for(i=0;i<10;i++)
	{
		printf("%i\n",alea(1,100));
	}

	return 0;
}
