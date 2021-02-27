#include "lista.h"
#include "restaurantes.h"

int main(){


    listaSimple* lista = new listaSimple();
    lista->insertFirst(new Nodo(4));
<<<<<<< HEAD
    cout << "FUNCIONA DE ESTA MANERA" << endl;
=======
>>>>>>> a1a1ad867728fc95cfc6072abdcf8a713462dc12

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
