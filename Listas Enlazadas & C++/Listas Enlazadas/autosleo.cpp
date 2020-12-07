#include <stdio.h>
#include <string.h>

class Auto{
public:
char modelo[30];
    	int anio;
    	Auto * sig;

Auto(const char * m, int a){
        	strcpy(modelo, m);
        	anio = a;
        	sig = 0;}

~Auto () {;}
};

class Cliente{
public:
    	char nombre[30];
    	char telefono[20];
    	Auto * autos;
    	Cliente * sig;

Cliente(const char * n, const char * t){
    	strcpy(nombre, n);
    	strcpy(telefono, t);
    	autos = 0;
    	sig = 0;}

~Cliente (){;}

void agregarAuto(const char * m, int a){
    	Auto * nuevo = new Auto(m, a);
    	if(autos == 0){
        		autos = nuevo;
        		nuevo->sig = 0;
       	 return;}

    Auto * ultimo = autos;
    	while(ultimo->sig != 0){
        		ultimo = ultimo->sig;}
    	ultimo->sig = nuevo;
   	nuevo->sig = 0;}

int cantAutos(){
    	int cantidad = 0;

   	 if(autos==0) return 0;

    	Auto * aux = autos;
    	while(aux != 0){
        		cantidad++;
       		 aux = aux->sig;}
      	return cantidad;}

void vaciarAutos(){
    	while(autos!=0){
        	borrar(autos);}
}

void borrar(Auto * a_borrar){
    	desenganchar(a_borrar);
   	 delete(a_borrar);}

void desenganchar(Auto * sacar){
    	if(autos==0) return;

   	 if(sacar==autos){ //hay que sacar el primero?
        		autos = sacar->sig;
       		 return;}

    	Auto * aux = autos;
    		while(aux->sig != sacar && aux->sig != 0){
        			aux = aux->sig;}
   		 aux->sig = sacar->sig;}

void mirarAutos(){
    	if(autos==0){
        		printf("\nLISTA DE AUTOS VACIA");
        		return;}

    	Auto * aux = autos;
    	while(aux){
        		printf("\nModelo:%s  Anio:%d",aux->modelo, aux->anio);
        		aux = aux->sig;}
}};

class ListaClientes{
private:
    	Cliente* inicio;

public:
ListaClientes(){
    	inicio = 0;}

void agregar(const char * n, const char * t){
    	Cliente * nuevo = new Cliente(n, t);
    	if(inicio == 0){
       		 inicio = nuevo;
        		nuevo->sig = 0;
       		 return;}

    	Cliente * ultimo = inicio;
    	while(ultimo->sig != 0){
        		ultimo = ultimo->sig;}
    	ultimo->sig = nuevo;
    	nuevo->sig = 0;}

void mirarCliente_Auto(){
        	if(inicio==0){
            		printf("\nLISTA VACIA");
            		return;}

        	Cliente * aux = inicio;
        	while(aux){
            		printf("\nCliente:%s",aux->nombre);
            		aux->mirarAutos();
            		printf("\n");
            		aux=aux->sig;}
}

Cliente * buscar(const char * name){
    	if(inicio == 0) return 0; // si no lo encuentra

    	Cliente * aux = inicio;
    	while(aux != 0){
        		if(strcmp(name, aux->nombre) == 0){
            			return aux;}
        		aux = aux->sig;}
    		return 0;}
};

int main(void) {
    	ListaClientes * lc = new ListaClientes;

    	lc->agregar("Pepe", "4555-6565");
    	lc->agregar("Maria", "4444-3232");
        lc->agregar("Carlos", "5460-1111");

    	lc->buscar("Pepe")->agregarAuto("Renault 12", 1980);
    	lc->buscar("Pepe")->agregarAuto("Renault Fluence", 2013);
        printf("\n\n");

        lc->mirarCliente_Auto();
    	printf("\nPepe tiene %d autos", lc->buscar("Pepe")->cantAutos());
        lc->buscar("Pepe")->mirarAutos();
    	printf("\n\n");

    	lc->buscar("Pepe")->vaciarAutos();
   	lc->buscar("Pepe")->mirarAutos();
    	printf("\n\n");
printf("\nPepe tiene %d autos", lc->buscar("Pepe")->cantAutos() );
    	printf("\n\n");
return 0;}

