#include <iostream>
using namespace std;

#include "pilacola.h"
#include "restaurantes.h"
#include "repartidores.h"

int main(){

    //Pregunta #1
    //Pila y cola heredan de lista simple, son objetos sin embargo la misma implementacion PUEDE funcionar para structs
    // Los nodos de la istaSimple pueden contener cualquier tipo de dato.
    cout << endl <<  "---------Pregunta #1----------" << endl;
    int valor = 4;
    int valor2 = 6;
    int valor3 = 10;
    int valor4 = 98;
    int valor5 = 43;

    ListaSimple<int> lista;
    lista.insertFirst(valor);;


    cout << "Pila: " << endl;
    Pila<int> p;
    p.push(valor2);
    cout << valor2 << " is pushed" << endl;
    p.push(valor3);
    cout << valor3 << " is pushed" << endl;
    p.push(valor4);
    cout << valor4 << " is pushed" << endl;
    p.push(valor5);
    cout << valor5 << " is pushed" << endl;
    cout << p.pop() << " is popped" << endl;
    cout << "Peek after pop: ";
    cout << p.peek() << endl;;
    cout << endl << endl;


    cout << "Cola: " << endl;
    Cola<int> c;
    c.encolar(valor4);
    cout << valor4 << " is queued" << endl;
    c.encolar(valor2);
    cout << valor2 << " is queued" << endl;
    c.encolar(valor3);
    cout << valor3 << " is queued" << endl;
    c.encolar(valor5);
    cout << valor5 << " is queued" << endl;
    cout << c.desencolar() << " is unqueued" << endl;
    cout << "Next element to be unqueued would be: ";
    cout << c.verFrente() << endl;;
    cout << endl << endl;

    //Funciona para struct tambien
    cout << "Pila con structs:" << endl;
    DummyStruct struct1 = DummyStruct();
    struct1.name = "struct1";
    DummyStruct struct2 = DummyStruct();
    struct2.name = "struct2";
    DummyStruct struct3 = DummyStruct();
    struct3.name = "struct3";

    Pila<DummyStruct> pilaStructs;

    pilaStructs.push(struct2);
    cout << struct2.name << " is pushed" << endl;
    pilaStructs.push(struct3);
    cout << struct3.name << " is pushed" << endl;
    pilaStructs.push(struct1);
    cout << struct1.name << " is pushed" << endl;
    
    cout << pilaStructs.pop().name << " is popped" << endl;
    cout << "Peek after pop: ";
    cout << pilaStructs.peek().name << endl << endl;



   //Pregunta #2, Opción B
   //Se utiliza Observer and Strategy pattern, se deben de ingresar las distancias de cada repartidor del restaurante
   // Bicycle speed = 5 km/h
   // Car speed = 15 km/h
   // Motorcycle speed = 20 km/h

    cout << "---------Pregunta #2----------" << endl << endl;
    
    Restaurante * restaurante = new Restaurante();

    int distanciaBici;
    int distanciaMoto;
    int distanciaCarro;

    cout << "How far is the delivery driver on motorcycle from the restaurant?" << endl;
    cin >> distanciaMoto;

    cout << "How far is the delivery driver on bicycle from the restaurant?" << endl;
    cin >> distanciaBici;

    cout << "How far is the delivery driver on car from the restaurant?" << endl;
    cin >> distanciaCarro;

    cout << endl;

    Repartidor * moto = new Motorcycle();
    Repartidor * bici = new Bicycle();
    Repartidor * car = new Car();
    
    moto->setDistance(distanciaMoto);
    bici->setDistance(distanciaBici);
    car->setDistance(distanciaCarro);

    restaurante->addObserver(moto);
    restaurante->addObserver(bici);
    restaurante->addObserver(car);

    restaurante->recibirPedido();

    cout << endl << endl;
    return 0;
};
