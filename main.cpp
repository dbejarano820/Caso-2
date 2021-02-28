#include "lista.h"
#include "restaurantes.h"

int main(){

    ListaSimple<int>* lista = new ListaSimple<int>();
    //lista->insertFirst(new Nodo(4));
    cout << "FUNCIONA DE ESTA MANERA" << endl;

    Restaurante * res = new Restaurante();

    int distanciaBici;
    int distanciaMoto;
    int distanciaCarro;
    int distanciaPedido;
    cout << "Que tan lejos esta el pedido del restaurante?" << endl;
    cin >> distanciaPedido;

    cout << "Que tan lejos esta el repartidor en bici del restaurante?" << endl;
    cin >> distanciaBici;

    cout << "Que tan lejos esta el repartidor en moto del restaurante?" << endl;
    cin >> distanciaMoto;

    cout << "Que tan lejos esta el repartidor en carro del restaurante?" << endl;
    cin >> distanciaCarro;

    cout << endl;

    res->setDistanciaBici(distanciaBici);
    res->setDistanciaMoto(distanciaMoto);
    res->setDistanciaCarro(distanciaCarro);
    res->setDistanciaPedido(distanciaPedido);
    res->calculateQuickest();

    return 0;
}
