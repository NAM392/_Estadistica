#include <stdio.h>
#include <string.h>

struct alumno {
    char nombre[100];
    float notas[3];
};

void cargar(struct alumno [], int);
void ordenar(struct alumno [], int);
void mirar(struct alumno [], int);
float promedio(struct alumno );

#define CANTALUMNOS 4

int main() {
    struct alumno a[CANTALUMNOS];

    char materias[3][40];
    strcpy(materias[0], "Matematica");
    strcpy(materias[1], "Programacion 1");
    strcpy(materias[2], "Sist de Proc de datos");

    cargar(a, CANTALUMNOS);
    ordenar(a, CANTALUMNOS);
    mirar(a, CANTALUMNOS);
}

void cargar(struct alumno vec[], int n) {
    vec[0].notas[0] = 10;
    vec[0].notas[1] = 2;
    vec[0].notas[2] = 6;
    strcpy(vec[0].nombre, "Pepe");
    //vec[0].nombre = "Pepe"; //NOOO

    vec[1].notas[0] = 8;
    vec[1].notas[1] = 6;
    vec[1].notas[2] = 9;
    strcpy(vec[1].nombre, "Maria");

    vec[2].notas[0] = 2;
    vec[2].notas[1] = 2;
    vec[2].notas[2] = 2;
    strcpy(vec[2].nombre, "Jose");

    vec[3].notas[0] = 10;
    vec[3].notas[1] = 10;
    vec[3].notas[2] = 9.99;
    strcpy(vec[3].nombre, "Juancito");
}

void ordenar(struct alumno datos[], int cuantos) {
    int i, j;
    struct alumno aux;

    for(i=0; i<cuantos-1; i++) {
        for(j=0; j<cuantos-i-1; j++) {
            if ( promedio(datos[j]) > promedio(datos[j+1]) ) {
                aux = datos[j];
                datos[j] = datos[j+1];
                datos[j+1] = aux;
            }
        }
    }
}

float promedio(struct alumno a) {
    return (a.notas[0] + a.notas[1] + a.notas[2]) / 3;
}

void mirar(struct alumno a[], int n) {
    int i;

    for(i=0; i<n; i++) {
        printf("%s %f \n", a[i].nombre, promedio(a[i]));
    }

}
