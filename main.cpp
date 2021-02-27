#include "lista.h"
#include "restaurantes.h"
//probando

int main(){


    listaSimple* lista = new listaSimple();
    lista->insertFirst(new Nodo(4));

    Restaurante * res = new Restaurante();
    res->setDistanciaBici(15);
    cout << res->repBici->distanciaAlRestaurante << endl;

    cout << lista->primerNodo->dato << endl;
    cout << "funciona" << endl;

    return 0;
}
