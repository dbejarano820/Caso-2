#include "pilacola.h"
#include "restaurantes.h"
#include "repartidores.h"

int main(){
    int valor = 4;
    int valor2 = 6;
    int valor3 = 10;
    ListaSimple<int> lista;
    lista.insertFirst(valor);;
    lista.seeFirst();

    Pila<int> p;
    p.push(valor2);
    p.push(valor3);
    cout << p.pop() << endl;
    p.peek();

    Cola<int> c;
    c.encolar(valor);
    c.encolar(valor2);
    c.encolar(valor3);
    c.verFrente();
    cout << c.desencolar() << endl;
    cout << c.desencolar() << endl;;
    c.verFrente();


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
