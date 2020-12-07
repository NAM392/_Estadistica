#include <stdio.h>
#include <string.h>

struct persona {
    char nombre[100];
    unsigned int edad;
};

void cargar(struct persona [], int);
void ordenar(struct persona [], int);
void mirar(struct persona [], int);

#define CANTPERSONAS 4

int main() {
    struct persona p[CANTPERSONAS];

    //printf("%p", p);

    cargar(p, CANTPERSONAS);
    ordenar(p, CANTPERSONAS);
    mirar(p, CANTPERSONAS);
}

void cargar(struct persona vec[], int n) {
    vec[0].edad = 20;
    strcpy(vec[0].nombre, "Pepe");
    //vec[0].nombre = "Pepe"; //NOOO

    vec[1].edad = 30;
    strcpy(vec[1].nombre, "Maria");

    vec[2].edad = 30;
    strcpy(vec[2].nombre, "Jose");

    vec[3].edad = 5;
    strcpy(vec[3].nombre, "Juancito");
}

void ordenar(struct persona datos[], int cuantos) {
    int i, j;
    struct persona aux;

    for(i=0; i<cuantos-1; i++) {
        for(j=0; j<cuantos-i-1; j++) {
            if((datos[j].edad > datos[j+1].edad) ||
               (datos[j].edad == datos[j+1].edad &&
                    strcmp(datos[j].nombre,datos[j+1].nombre) == 1)
               ) {
                aux = datos[j];
                datos[j] = datos[j+1];
                datos[j+1] = aux;
            }
        }
    }
}

void mirar(struct persona p[], int n) {
    int i;

    for(i=0; i<n; i++) {
        printf("%d %s \n", p[i].edad, p[i].nombre);
    }

}
