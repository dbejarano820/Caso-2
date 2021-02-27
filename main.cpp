#include "lista.h"
#include "restaurantes.h"

int main(){


    listaSimple* lista = new listaSimple();
    lista->insertFirst(new Nodo(4));
    cout << "FUNCIONA DE ESTA MANERA" << endl;

    Restaurante * res = new Restaurante();
    res->setDistanciaBici(205);
    res->setDistanciaMoto(80);
    res->setDistanciaCarro(900);
    res->setDistanciaPedido(15);
    res->calculateQuickest();

    cout << lista->primerNodo->dato << endl;
    cout << "funciona" << endl;

    return 0;
}
