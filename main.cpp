#include "lista.h"
#include "restaurantes.h"
//probando

int main(){


    listaSimple* lista = new listaSimple();
    lista->insertFirst(new Nodo(4));
<<<<<<< HEAD
    cout << "FUNCIONA DE ESTA MANERA" << endl;
=======
>>>>>>> a1a1ad867728fc95cfc6072abdcf8a713462dc12

    Restaurante * res = new Restaurante();
    res->setDistanciaBici(15);
    cout << res->repBici->distanciaAlRestaurante << endl;

    cout << lista->primerNodo->dato << endl;
    cout << "funciona" << endl;

    return 0;
}
