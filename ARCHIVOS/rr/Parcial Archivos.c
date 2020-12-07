#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct INGRESO {
    int legajo;
    char carrera [20];
};

struct EXAMEN {
    int legajo;
    int nota;
};


int main(){

    FILE * FI, *FE , *FIAUX;
    struct INGRESO INI;
    struct EXAMEN EXA;
    char mayor_carrera[20], AUX[20];
    int mayor_cant=0, cant=0, AUX_CAR, mayor_ingreso, cont;

    if ((FI = fopen("INGRESO.DAT" , "rb")) == NULL ){
        printf("ERROR EN LA APERTURA DE ARCHIVO INGRESO\n");
        exit(1);
    }
    if ((FIAUX = fopen("INGRESO.DAT" , "rb")) == NULL){
        printf("ERROR EN LA APERTURA DE ARCHIVO AUX");
        exit(1);
    }
    if ((FE = fopen("EXAMEN.DAT" , "rb")) == NULL ){
        printf("ERROR EN LA APERTURA DE ARCHIVO EXAMEN\n");
        exit(1);
    }




    mayor_ingreso=0;
    cont=0;

	fread(&INI, sizeof(INI), 1 , FI);
    while(! feof(FI)){
        strcpy(AUX, INI.carrera);
        rewind(FIAUX);
        fread(&INI , sizeof(INI), 1 , FIAUX);
	    while(! feof(FIAUX)){
            if (!strcmp(AUX, INI.carrera)){
                rewind(FE);
                fread(&EXA, sizeof(EXA), 1, FE);
                while(!feof(FE)){
                    if ((INI.legajo == EXA.legajo )&& EXA.nota>= 6)
                        cont++;
                    fread(&EXA, sizeof(EXA), 1, FE);
                }
            }
            fread(&INI, sizeof(INI),1,FIAUX);
            }

        if (mayor_ingreso < cont){
            mayor_ingreso = cont;
            strcpy(mayor_carrera, AUX);
        }
        fread(&INI, sizeof(INI),1,FI);
        cont=0;
    }


    printf("\n\nLA CARRERA CON MAS INGRESANTES ES %s CON %d APROBADOS", mayor_carrera , mayor_ingreso);



    fclose(FI);
    fclose(FIAUX);
    fclose(FE);


    return 0;
}
