#include "pilacola.h"


void Pila::push(Nodo* pNodo){
    insertFirst(pNodo);
}

Nodo* Pila::pop(){
    return eraseFirst();
}

Nodo* Pila::peek(){
    return seeFirst();
}


void Cola::encolar(Nodo* pNodo){
    insertFirst(pNodo);
}

Nodo* Cola::desencolar(){
    return eraseLast();
}

Nodo* Cola::verFrente(){
    return seeFirst();
}