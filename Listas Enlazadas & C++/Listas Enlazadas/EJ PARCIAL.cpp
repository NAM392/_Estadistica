







int main(void) {

    ListaClientes * lc = new ListaClientes;

    lc->agregar("pepe" , "4555-6565");
    lc->agregar("maria" , "4444-3232");
    lc->agreagar("carlos" , "5460-1111");

    lc-buscar("pepe")->agregarAuto("Renault 12 " , 1980);
    lc->buscar("pepe")->agregarAuto("Renault Fluence" , 2013);

    printf("\n pepe tiene %d autos" ,
                    lc-Zbuscar("pepe")->cantAutos() );

    lc->buscar("pepe")->vaciarAutos();

    printf("\n pepe tiene %d autos" ,
                    lc->buscar("pepe")->cantAutos());

















}
