

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct INGRESO {
    int LEGAJO;
    char CARRERA[20];
};

struct EXAMEN {
    int LEGAJO;
    int NOTA;
};
struct AUXILIAR {
    int NOTA;
    char CARRERA[20];
};



int main(){

    FILE * FI, *FE, *FAUX;
    struct INGRESO INI;
    struct EXAMEN EXA;
    struct AUXILIAR AUX;
    char mayor_carrera[20], AUX[20];
    int mayor_cant, cant, AUX_CAR, mayor_ingreso, cont;

    if ((FI = fopen("INGRESO.DAT" , "rb")) == NULL ){
        printf("ERROR EN LA APERTURA DE ARCHIVO INGRESO\n");
        exit(1);
    }

    if ((FIAUX = fopen("INGRESO.DAT" , "rb")) == NULL){
        printf("ERROR EN LA APERTURA DE ARCHIVO AUX");
        exit(1);
    }

    if ((FR = fopen("EXAMEN.DAT" , "rb")) == NULL ){
        printf("ERROR EN LA APERTURA DE ARCHIVO EXAMEN\n");
        exit(1);
    }


    cant = 0;
    mayor_cant = 0;

    fread(&I, sizeof(I), 1, FIAUX);
    while(! feof(FIAUX)){
            strcpy(AUX,I.carrera);				// CON MI PUNTERO AUXILIAR GUARDO EN LA VARIABLE AUX EL NOMBRE DE LA CARRERA
            rewind(FI);							// ESTO ES MUY IMPORTANTE PARA QUE CUANDO ENTRE EN EL SEGUNDO BUCLE, ARRANQUE DESDE LA PRIMERA POSICION
            cant=0;
            fread(&I, sizeof(I), 1, FI);


            while(! feof(FI)){					// SEGUNDO BUCLE CON UN SEGUNDO PUNTERO, PARA COMPARAR CONTRA LA VARIABLE
                    if(! strcmp(AUX, I.carrera)){
                        cant++;					// SI LA CARRERA ESTA SUMA UNA UNIDAD
                    }
                    fread(&I, sizeof(I), 1, FI);// SIEMPRE ANTES DE VOLVER A ENTRAR AL BUCLE TENGO QUE LEER, SINO QUEDA EN UN BUCLE INFINITO
            }


            if (cant > mayor_cant){				// CUANDO TERMINA EL SEGUNDO BUCLE, COMPARA LA CANTIDAD DE INSCRIPTOS
                mayor_cant = cant;
                strcpy(mayor_carrera,AUX);		// ACA GUARDO EL NOMBRE DE LA CARRERA CON MAYOR CANTIDAD DE INSCRIPTOS
            }
            fread(&I, sizeof(I), 1, FIAUX);		// SIEMPRE ANTES DE VOLVER A ENTRAR AL BUCLE TENGO QUE LEER, SINO QUEDA EN UN BUCLE INFINITO
    }


    printf("\nLA CARRERA CON MAYOR INSCRIPTOS ES %s CON %d ALUMNOS", mayor_carrera , mayor_cant);


    rewind(FI);
    rewind(FIAUX);




    mayor_ingreso=0;
    cont=0;

	fread(&I, sizeof(I), 1 , FI);
    while(! feof(FI)){
        strcpy(AUX, I.carrera);							// GUARDO CON EL PRIMER PUNTERO, LA CARRERA EN UN AUXILIAR
        rewind(FIAUX);									// ESTO ES MUY IMPORTANTE PARA QUE CUANDO ENTRE EN EL SEGUNDO BUCLE, ARRANQUE DESDE LA PRIMERA POSICION
        fread(&I , sizeof(I), 1 , FIAUX);				// LEO CON EL SEGUNDO PUNTERO

	    while(! feof(FIAUX)){
            if (!strcmp(AUX, I.carrera)){				// COMPARO EL NOMBRE DE LA CARRERA CON EL AUXILIAR
                rewind(FR);								//
                fread(&R, sizeof(R), 1, FR);
                while(!feof(FR)){						// CON UN TERCER PUNTERO, VOY A BUSCAR EL LEGAJO QUE COINCIDA CON EL LEGAJO DEL SEGUNDO PUNTERO
                    if ((I.legajo == R.legajo )&& R.nota>= 6)
                        cont++;							// SI LO ENCUENTRA Y LA NOTA ES MAYOR QUE 6, SUMA UN CONTADOR
                    fread(&R, sizeof(R), 1, FR);
                }
            }
            fread(&I, sizeof(I),1,FIAUX);
            }

        if (mayor_ingreso < cont){						// GUARDO LA CARRERA Y LA CANTIDAD DE APROBADOS PARA IR COMPARANDOLOS MIENTRAS AVANZO
            mayor_ingreso = cont;
            strcpy(mayor_carrera, AUX);
        }
        fread(&I, sizeof(I),1,FI);
        cont=0;
    }


    printf("\n\nLA CARRERA CON MAS INGRESANTES ES %s CON %d APROBADOS", mayor_carrera , mayor_ingreso);



    fclose(FI);
    fclose(FIAUX);
    fclose(FR);


    return 0;
}



}
