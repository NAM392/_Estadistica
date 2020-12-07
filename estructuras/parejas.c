#include<stdio.h>
#include<string.h>
#define CANTPER 3



struct persona{
    char nombre[20];
    int edad;
    char sexo;
};
struct parejas{
    struct persona Mujer;
    struct persona Hombre;
};



void cargarV(struct persona vect[], int largo );
void ordenado(struct persona vect[], int largo);
void crear_parejas(struct persona V[], int largo, struct parejas VP[], int larp);
void imprimir_parejas(struct parejas VP[], int lar);






int main(){

    struct persona vect[CANTPER];
    struct parejas vectP[CANTPER/2];
    cargarV(vect,CANTPER);
    ordenado(vect,CANTPER);
    crear_parejas(vect, CANTPER, vectP, CANTPER/2);
    imprimir_parejas(vectP, CANTPER/2);
    if(CANTPER %2 != 0){
        printf("la persona que quedo sola es: %s (%d)", vect[CANTPER-1].nombre, vect[CANTPER-1].edad);}
    //imprime persona sola
   // printf("la persona que quedo sola es: %s (%d)", vect[CANTPER-1].nombre, vect[CANTPER-1].edad);

}

void cargarV(struct persona vect[], int largo ){
    int i;
    char nombre;
    int edad;
    for(i=0;i<largo;i++){
        printf("ingrese nombre:  ");
        scanf("%s", vect[i].nombre);
        printf("ingrese edad:  ");
        scanf("%d", &vect[i].edad);
        printf("ingrese sexo:  ");
        scanf(" %c", &vect[i].sexo);
    }
}

void ordenado(struct persona vect[], int largo){
    int i,j;
    struct persona aux;
    for(i=0;i<largo-1;i++){
        for(j=0;j<largo-i-1;j++){
            if((vect[j].edad < vect[j+1].edad) ||
            (vect[j].edad == vect[j+1].edad)){
                aux= vect[j];
                vect[j]=vect[j+1];
                vect[j+1]=aux;
            }
        }


    }
}

void crear_parejas(struct persona V[], int largo, struct parejas VP[], int larp){
    int i;
    int j=0;
    for(i=0;i<largo;i++){
        if(V[i].sexo == 'F'){
            VP[j].Mujer=V[i];
            j++;

        }
    }
    j=0;
    for(i=0;i<largo;i++){
        if(V[i].sexo == 'M'){
            VP[j].Hombre=V[i];
            j++;

        }
    }

}

void imprimir_parejas(struct parejas VP[], int lar){
    int i;
    for(i=0;i<lar;i++){
        printf("%s (%d) y %s (%d) \n",VP[i].Mujer.nombre , VP[i].Mujer.edad, VP[i].Hombre.nombre, VP[i].Hombre.edad);
    }

}




