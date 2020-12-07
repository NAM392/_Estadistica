
#include <stdio.h>

struct EXAMEN{
    int legajo;
    int nota;
};

int main( ){
    FILE * fp;
    struct EXAMEN exam;
    int N = 0, i;

    if( ( fp = fopen( "EXAMEN.DAT", "ab" ) ) == NULL ){
        printf( "\nNo se pudo cargar el archivo" );
        return 1;
    }

    printf( "\nCuantos datos desea ingresar?: " );
    scanf( "%d", &N );

    fwrite( &exam, sizeof( exam ), 1, fp );

    for( i = 0; i < N; i++ ){
        fflush( stdin );
        printf( "\nIngrese el numero de legajo: " );
        scanf( "%d", &exam.legajo );
        getchar( );
        fflush( stdin );
        printf( "\nIngrese la nota: " );
        scanf( "%d", &exam.nota );
        getchar( );
        fflush( stdin );
        fwrite( &exam, sizeof( exam ), 1, fp );
    }
    fclose( fp );
    return 0;
}
