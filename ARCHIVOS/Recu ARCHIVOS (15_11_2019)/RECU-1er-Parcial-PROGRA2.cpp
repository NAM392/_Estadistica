
/****************************************************************/
/*                    RECUPERATORIO ARCHIVOS                    */
/*                          15/11/2019                          */
/*                                                              */
/*  Se dispone del archivo "INGRESO" en el que se encuentran    */
/*  los datos de todos los alumnos inscriptos para el ingreso   */
/*  a una universidad. Estos datos consisten en: Legajo(int) y  */
/*  Carrera(string de 20 caracteres).                           */
/*  En el archivo "EXAMEN" se tienen los resultados del examen  */
/*  de ingreso general a la universidad (todas las carreras) de */
/*  los alumnos que se presentaron al mismo. Estos resultados   */
/*  están estructurados como Legajo (int) y Nota(int).          */
/*  Se pide permitir el ingreso por teclado del nombre de una   */
/*  carrera e indicar cuántos son los alumnos de dicha carrera  */
/*  que: a) se inscribieron, b) se presentaron al examen y      */
/*  c) aprobaron el mismo (Nota >= 6).                          */
/*                                                              */
/****************************************************************/

#include <stdio.h>
#include <string.h>

struct INGRESO{
    int legajo;
    char carrera[ 20 ];
};

struct EXAMEN{
    int legajo;
    int nota;
};

int main(){
    FILE * fp, * fp2;
    struct INGRESO ing;
    struct EXAMEN exam;
    char nomCarr[ 20 ];
    int legajo = 0, inscriptos = 0, present = 0, approved = 0;

    if( ( fp = fopen( "INGRESO.DAT", "rb" ) ) == NULL ){                /// Lo abrí en modo "rb", también abre en "r"
        printf( "\nNo se pudo cargar el archivo." );
        return 1;
    }

    if( ( fp2 = fopen( "EXAMEN.DAT", "r" ) ) == NULL ){                 /// Lo abrí en modo "r", también abre en "rb"
        printf( "\nNo se pudo cargar el archivo." );
        return 1;
    }

    fread( &ing, sizeof( ing ), 1, fp );
    printf( "\nIngrese el nombre de la carrera que desea buscar: " );
    fflush( stdin );
    gets( nomCarr );
    fread( &ing, sizeof(ing), 1, fp );
    while( !feof( fp ) ){
        if( strcmp( nomCarr, ing.carrera ) == 0 ){
            inscriptos++;
            legajo = ing.legajo;
            fread( &exam, sizeof( exam ), 1, fp2 );
            while( !feof( fp2 ) ){
                if( legajo == exam.legajo ){
                    present++;
                    if( exam.nota >= 6 )
                        approved++;
                }
                fread( &exam, sizeof( exam ), 1, fp2 );
            }
            rewind( fp2 );
        }
        fread( &ing, sizeof(ing), 1, fp );
    }
    fclose( fp2 );
    fclose( fp );
    printf( "\n\nSe inscribieron a %s: %d alumnos.\nSe presentaron %d al examen y aprobaron %d.", nomCarr, inscriptos, present, approved );
    return 0;
}
