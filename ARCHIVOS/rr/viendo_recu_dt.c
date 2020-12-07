/*

SE DISPONE DEL ARCHIVO "INGRESO" EN EL QUE SE ENCUENTRAN LOS DATOS DE TODOS LOS ALUMNOS INSCRITOS PARA
EL INGRESO A UNA UNIVERSIDAD. ESTOS DATOS CONSISTEN EN: LEGAJO (INT) Y CARRERA (STRING DE 20 CARACTERRES).
EN EL ARCHIVO "EXAMEN" SE TIENEN LOS RESULTADOS DEL EXAMEN DE INGRESO GENERAL A LA UNIVERSIDAD (TODAS
LAS CARRERAS) DE LOS ALUMNOS QUE SE PRESENTAN AL MISMO. ESTOS RESULTADOS ESTAN ESTRUCTURADOS COMO:
LEGAJO (INT) Y NOTA (INT).
SE PIDE INDICAR a) CUAL ES LA CARRERA EN LA QUE HUBO MAS INSCRIPTOS Y b) CUAL ES LA CARRERA A LA QUE
INGRESARON MAS ALUMNOS (NOTA DE APROBACION >= 6).

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct INSCRIPTOS {
    int legajo;
    char carrera [20];
};

struct RESULTADOS {
    int legajo;
    int nota;
};


int main(){

    FILE * FI, *FR, *FIAUX;
    struct INSCRIPTOS I;
    struct RESULTADOS R;
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
