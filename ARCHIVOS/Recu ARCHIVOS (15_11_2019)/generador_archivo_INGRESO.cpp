
#include <stdio.h>

#define N 5

struct INGRESO{
    int legajo;
    char carrera[ 20 ];
};

int main(){
    FILE * fp;
    struct INGRESO ing;
    int i;

    if( ( fp = fopen( "INGRESO.DAT", "ab" ) ) == NULL ){
        printf( "\nNo se pudo cargar el archivo" );
        return 1;
    }

    fwrite( &ing, sizeof( ing ), 1, fp );
    for( i = 0; i < N; i++ ){
        fflush( stdin );
        printf( "\nIngrese el numero de legajo: " );
        scanf( "%d", &ing.legajo );
        getchar();
        printf( "\nIngrese el nombre de la carrera: " );
        fflush( stdin );
        gets( ing.carrera );
        fwrite( &ing, sizeof( ing ), 1, fp );
    }
    fclose( fp );
    return 0;
}
