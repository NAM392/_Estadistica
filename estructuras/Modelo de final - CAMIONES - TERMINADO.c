#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///VARIABLE DE FECHAS
typedef struct fecha{
    int dia,mes,anio;
}fecha_t;

///VARIABLE DE VIAJES
typedef struct viaje {  ///El type def es para renombrar la estructura y ahorrar tiempo a la hora de escribir.
	char patente[10];
	char ciudad_origen[50];
	char ciudad_destino[50];
	float peso_transportado;
	fecha_t fecha_viaje;
} v_camion;

///VARIABLE PARA NRO DE VIAJES LIGADO A PATENTES
typedef struct patentes_viajes {
    char patente[10];
    int nro_viajes;
} seguimiento;

///FUNCION PARA CREAR FECHAS
fecha_t crear_fecha(){
    fecha_t nueva_fecha;
    do {
        printf("\nIngrese el la fecha: dd/mm/aaaa.\n"); /// Le indicamos al usuario el orden en que debe ingresar los datos.
        scanf("%d/%d/%d",&nueva_fecha.dia,&nueva_fecha.mes,&nueva_fecha.anio); ///Hacemos todo de una, para ahorrar tiempo.
    }
    while (!(nueva_fecha.anio>1900 && nueva_fecha.anio<2100 && nueva_fecha.mes<13 && nueva_fecha.mes>0 && nueva_fecha.dia>0 && nueva_fecha.dia<32));
    return nueva_fecha;
}

///FUNCION PARA CREAR VIAJES
v_camion crear_viaje (){
    v_camion nuevo_viaje;
    printf("\nIngrese la patente del camion:");
    fflush(stdin);
    gets(nuevo_viaje.patente);
    printf("\nIngrese la ciudad de origen del camion:");
    fflush(stdin);
    gets(nuevo_viaje.ciudad_origen);
    printf("\nIngrese la ciudad de destino del camion:");
    fflush(stdin);
    gets(nuevo_viaje.ciudad_destino);
    printf("\nIngrese el peso a transportar en el camion:");
    fflush(stdin);
    scanf("%f", &nuevo_viaje.peso_transportado);
    nuevo_viaje.fecha_viaje = crear_fecha();
    return nuevo_viaje; ///Retornamos la estructura completa con todos los datos solicitados.
}
///                                     Atencion a lo que dice aca abajo
int cgt_op (v_camion camiones[]/*IMPORTANTE ACLARAR QUE VAMOS A RECIBIR UN VECTOR*/,int size_vector, int viajes_max){
        ///Size_Vector es el tamaño que va a tener el Vector. En el camino lo vamos a ir ajustando.
        for (int i = 0 ; i < size_vector ; i++) {
            ///Aca vamos viendo que cada camion no se pase del numero de viajes que esta previsto
            for (int viaje = 1; viaje < viajes_max+1 ; viaje++) {
                camiones[i] = crear_viaje();
                int flag_ingreso=0; ///Un flag para usar mas abajo.
                if (viaje != viajes_max){
                    printf("\nPulse 1 si desea ingresar otro viaje para este camion.\n");
                    scanf("%d",&flag_ingreso);
                }
                if (flag_ingreso==1) ///Usamos el flag para incrementar i para que el vector crezca y no se sobreescriba,
                    i++;            ///debido a que no salio del loop todavia.
                else {      ///Aca vamos ajustando el tamaño del vector en medida de lo que necesitemos.
                    size_vector = size_vector - (viajes_max - viaje);
                    viaje=viajes_max;
                }
            }
    }
return size_vector; ///Retornamos el tamaño del vector (Ya ajustado, para que no se impriman los lugares que no usamos).
}

void necesito_orden (v_camion camiones[],int size_vector,int camiones_max) {
    v_camion auxiliar;
    ///Ordenamos el vector ayudandonos del metodo de burbujeo (pag 137 del libro) y usando como informacion las patentes.
    for (int i=0; i < size_vector - 1 ; i++) {
        for (int j=0; j < size_vector - i - 1; j++) {
            if (strcmpi(camiones[j].patente,camiones[j+1].patente)>0) {
                auxiliar = camiones[j];
                camiones[j]  = camiones[j+1];
                camiones[j+1]= auxiliar;
            }
        }
    }
}

void patentes_print_sin_repetir (v_camion camiones[],int size_vector,int camiones_max){
    int contador=0;
    seguimiento chapa[camiones_max];
    necesito_orden(camiones,size_vector,camiones_max); ///Funcion que ordena
    ///Ya ordenado, podemos sacar facilmente cuales son las patentes que ingreso el gordo teton del usuario.
    printf("\nSe usaron las siguientes patentes.\n");
    for (int k=0; k < size_vector; k++){
        if (strcmpi(camiones[k].patente,camiones[k+1].patente)!=0) {
            strcpy(chapa[contador].patente,camiones[k].patente);
            printf("\t\t%s",chapa[contador].patente);
            contador++;
        }
    }
}


void patente_que_mas_viajes_realizo (v_camion camiones[],int size_vector,int camiones_max){
    int contador=0;
    int viajes=0;
    seguimiento chapa[camiones_max];
    seguimiento aux;
    for (int k=0; k < size_vector; k++){
        viajes++;
        if (strcmpi(camiones[k].patente,camiones[k+1].patente)!=0) {
            strcpy(chapa[contador].patente,camiones[k].patente);
            chapa[contador].nro_viajes=viajes;
            contador++;
            viajes=0;
        }
    }
    for (int i=0; i < camiones_max -1; i++){
        for (int j=0; j < camiones_max -1 - i; j++) {
            if (chapa[j].nro_viajes<chapa[j+1].nro_viajes){
                aux = chapa[j];
                chapa[j]   = chapa[j+1];
                chapa[j+1] = aux;
            }

        }
    }
    printf("\n\nLa patente que realizo mas viajes fue %s con %d viajes.\n",chapa[0].patente,chapa[0].nro_viajes);
}


void orden_por_fecha (v_camion camiones[],int size_vector,int camiones_max) {
    v_camion aux;
    ///Burbujeo
    for (int i = 0; i < size_vector - 1; i++){
        for (int j = 0; j < size_vector - 1 - i; j++) {
            if (camiones[j].fecha_viaje.anio<camiones[j+1].fecha_viaje.anio){
                aux = camiones[j];
                camiones[j]   = camiones[j+1];
                camiones[j+1] = aux;
            }
            else if (camiones[j].fecha_viaje.anio==camiones[j+1].fecha_viaje.anio){
                if (camiones[j].fecha_viaje.mes<camiones[j+1].fecha_viaje.mes) {
                    aux = camiones[j];
                    camiones[j]   = camiones[j+1];
                    camiones[j+1] = aux;
                }
                else if (camiones[j].fecha_viaje.mes==camiones[j+1].fecha_viaje.mes){
                    if (camiones[j].fecha_viaje.dia<camiones[j+1].fecha_viaje.dia){
                        aux = camiones[j];
                        camiones[j]   = camiones[j+1];
                        camiones[j+1] = aux;
                    }
                    else if (camiones[j].fecha_viaje.dia==camiones[j+1].fecha_viaje.dia){
                        if (camiones[j].peso_transportado==camiones[j+1].peso_transportado){
                            aux = camiones[j];
                            camiones[j]   = camiones[j+1];
                            camiones[j+1] = aux;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int camiones_max,viajes_max;
    ///Pedimos datos al usuario.
    printf("\n¿Cuantos camiones quiere ingresar?.\n");
    scanf("%d",&camiones_max);
    printf("\n¿Cuantos viajes maximos por camion?.\n");
    scanf("%d",&viajes_max);
    int size_vector = camiones_max * viajes_max;
    /// Con la multiplicacion de arriba, sacamos facilmente el tamaño de vector MAXIMO que vamos a necesitar.
    v_camion camiones[size_vector]; ///Declaramos el vector.

    ///PUNTO A - Permita el ingreso de los datos de ??? camiones y ??? viajes para cada uno.
    size_vector=cgt_op(camiones,size_vector,viajes_max);
    ///Aprovechamos para actualizar el valor de nuestro vector de estructuras.

    ///PUNTO B - Muestre en pantalla las patentes, sin repetir.
    patentes_print_sin_repetir(camiones,size_vector,camiones_max);

    ///PUNTO C - Muestre en pantalla la patente del camión que más viajes realizó.
    patente_que_mas_viajes_realizo (camiones,size_vector,camiones_max);
    ///Si hay varias con el numero de viajes maximo, no joda, se pone cualquiera de esos. No lo pienso mejorar xD

    ///PUNTO D - Muestre en pantalla todos los viajes, ordenados por fecha. Los que son de la misma fecha se deben ordenar por peso transportado descendente.
    orden_por_fecha (camiones,size_vector,camiones_max);

///LOOP QUE IMPRIME EL VECTOR COMPLETO
    for (int k = 0; k < size_vector ; k++)
        printf("\n\tPatente: %s\tOrigen: %s\t\tDestino: %s\n\tCarga: %f\tFecha: %d/%d/%d\n",
        camiones[k].patente, camiones[k].ciudad_origen, camiones[k].ciudad_destino,
         camiones[k].peso_transportado, camiones[k].fecha_viaje.dia, camiones[k].fecha_viaje.mes,
          camiones[k].fecha_viaje.anio);
}
