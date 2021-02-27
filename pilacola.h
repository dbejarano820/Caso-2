#include "lista.h"

class Pila : public listaSimple{
    public:
    Nodo* pop();
    Nodo* push();
    Nodo* peek();
};

class Cola : public listaSimple{

    public:
    Nodo* encolar();
    Nodo* desencolar();
    Nodo* verFrente();
};