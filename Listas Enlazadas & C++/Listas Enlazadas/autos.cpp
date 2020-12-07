#include<stdio.h>
#include<string.h>

class Auto{
public:
       char modelo[30];
       int anio;
       Auto*sig;

       Auto(const char * m , int a){
        strcpy(modelo , m);
        anio = 0;
        sig = 0;
        }

        ~Auto (){;}



} ;


class Cliente{
public:
    char nombre[30];
    char telefono[20];
    Auto * autos;
    Cliente*sig;


    Cliente(const char * n , const char * t){
        strcpy(nombre , n);
        strcpy(telefono , t);
        autos = 0;
        sig = 0;
    }
   ~Cliente();

      void agregarAuto( const char * AUTO , int E){
        Auto * nuevo  = new Auto(AUTO , E);
        if(autos == 0) {
            autos = nuevo;
            nuevo->sig = 0;
            return ;
        }
        Auto * ultimo = autos;
        while(ultimo->sig != 0){
            ultimo = ultimo->sig;
        }
        ultimo->sig = nuevo;
        nuevo->sig = 0;
    }



   int cantAutos(){

        if(autos == 0){
            return 0;
        }
        Auto*aux = autos;
        int contar = 0;
        while(aux != 0){
            contar++;
        aux = aux->sig;
        }
        return contar;
    }

        void vaciarAutos(){
        while(autos != 0){
            borrar(autos);
        }
    }

        void borrar ( Auto * aBorrar){
        desenganchar(aBorrar);
        delete(aBorrar);
}


    void desenganchar(Auto * cual ){

    if (autos == 0) return;
    if(autos == cual){
            autos = cual->sig ;
           return;
    }

    Auto*aux = autos;
    while(aux->sig != cual && aux->sig != 0){
        aux = aux->sig;
    }
    aux->sig = cual->sig;
    }

    void mirarAutos(){
        if (autos==0){
            printf("\nlista vacia\n");
            return;
        }

        Auto*aux = autos;

        while(aux){
            printf("\n el auto %s con modelo %d " , autos->modelo , autos->anio);
            aux = aux->sig;
        }



    }


};




class ListaClientes {
private :
    Cliente*inicio;

public:
    ListaClientes(){
       inicio=0;
    }

    //agrega

    void agregar(const char * NOM ,const  char * TEL ) {
        Cliente*nuevo = new Cliente (NOM , TEL);

        if(inicio == 0) {
            inicio = nuevo;
            nuevo->sig = 0;
            return ;
        }
        Cliente * ultimo = inicio;
        while(ultimo->sig != 0){
            ultimo = ultimo->sig;
        }
        ultimo->sig = nuevo;
        nuevo->sig = 0;
        }

    Cliente * buscar(const char * NOM){
        if(inicio==0){return 0 ;};
        Cliente * aux = inicio ;
        while (aux){
            if (strcmp( NOM , aux->nombre )==0 ){
                return aux;
            }
            aux = aux->sig;
        }
        return 0;
    }


    void mirarCliente(){
        if(inicio==0){
            return;
        }
        Cliente*aux = inicio;

        while(aux){
            printf("\nCliente %s \n" , aux->nombre);
            aux->mirarAutos();

            aux = aux->sig;
        }





    }







};





    // , contar ,// mostrar ,// etc


int main(void){
    ListaClientes * lc = new ListaClientes;

    lc->agregar("pepe" , "444-444");
    lc->agregar("maria" , "555-555");
    lc->agregar("carlos" , "666-666");

    lc->buscar("pepe")->agregarAuto("Renault fluence" , 2013);

    lc->buscar("pepe")->agregarAuto("renault 12" , 1989);

    lc->mirarCliente();

    printf("\n pepe tiene %d autos" ,
           lc->buscar("pepe")->cantAutos() );

    lc->buscar("pepe")->vaciarAutos();

    printf("\n pepe tiene %d autoss" ,
           lc->buscar("pepe")->cantAutos() );



}
