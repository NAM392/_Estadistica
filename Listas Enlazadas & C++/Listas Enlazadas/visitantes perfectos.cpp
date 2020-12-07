#include<stdio.h>
#include<string.h>


class Visitante {
public:
    char nombre[20];
    int edad ;
    Visitante*sig;

    Visitante(const char * N) {
        strcpy(nombre , "N");

    }



};

class Museo {
public:
    const char nom_museo[50];
    Museo*sig ;
    Visitante*Visit;

    Museo(const char * nm ){
        strcpy(nom_museo , "NM");
        Visit = 0;
        sig = 0;
    }

    Museo();

    void agregar_visita(const char * V){
        Visitante*nuevo = new Visitante(V);

        if(Visit == 0){
            Visit = nuevo;
            nuevo->sig = 0;
            return;
        }
        Visitante*ultimo = Visit;
        while(ultimo->sig != 0){
            ultimo=ultimo->sig;
        }
        ultimo->sig = nuevo;
        nuevo->sig = 0;

    }







};

class RegistroVisitas {
private:
        Visitante * visitor = 0; ;
        Museo * museum ;
        Museo * inicio = 0;
public:
    RegistroVisitas();


    registrarVisita (const char MUSEO , const char NOM) {
        if(inicio==0){
            return;
        }
        buscar(MUSEO)->agregar_visita(NOM);
    }

    void nuevoMuseo(char * museo){
        Museo*nuevo = new Museo;
        strcpy(nuevo->nom_museo , museo);

        if(inicio == 0) {
            museum = nuevo;
            nuevo->sig = 0;
            return;
        }
        Museo * ultimo = inicio;
        while(ultimo->sig != 0){
        ultimo = ultimo->sig;
        }
        ultimo->sig = nuevo;
        nuevo->sig = 0;
    }

    Museo*buscar(constant char * M){
        if(inicio==0){
            return 0;
        }
        Museo*aux = inicio;
        while(aux){
            if(strcmp(M ,aux->nom_museo )==0){
                    return aux;
            }
            aux = aux->sig;
        }
        return 0;
    }

        void verVisitantesPerfectos(){
        if(inicio==0){
            return ;
        }
        char nombre [60];
        Museo*aux = inicio;
        strcpy(aux->Visit , nombre );
        while(aux){
            if(strcmp(nombre , aux->visit)==0){
                cont++;

            }


        }

    }



};




int main() {
	RegistroVisitas * lista = new RegistroVisitas;

	lista->nuevoMuseo("MALBA");
	lista->nuevoMuseo("Museo Historico Nacional");
	lista->nuevoMuseo("Museo de Ciencias Naturales");

	lista->registrarVisita("MALBA", "Pepe Gomez");
	lista->registrarVisita("Museo Historico Nacional", "Pepe Gomez");
	lista->registrarVisita("MALBA", "Maria Alvarez");
	lista->registrarVisita("Museo de Ciencias Naturales", "Pepe Gomez");
	lista->registrarVisita("Museo de Ciencias Naturales", "Roberto Sanchez");

	printf("\n Las personas que han visitado todos los museos son: ");
	lista->verVisitantesPerfectos();
}
