#include <iostream>
using namespace std;

class Nodo{
    public:
    int dato;
    //cualquier tipo de dato adicionales

    Nodo* siguiente;

    Nodo(){
        dato = 0;
        siguiente = NULL;
    }

    Nodo(int pDato){
        dato = pDato;
        siguiente = NULL;
    }

    Nodo(int pDato, Nodo* pNodo){
        dato = pDato;
        siguiente = pNodo;
    }
};


class listaSimple{

    public:

    Nodo* primerNodo; //first node
    Nodo* ultimoNodo; //last node

    listaSimple(){
        primerNodo = ultimoNodo = NULL;
    }

    bool isEmpty();
    void insertFirst(Nodo*);
    void insertLast(Nodo*);
    int largo();
    Nodo* eraseFirst();
    Nodo* eraseLast();
    //bool esta();

};