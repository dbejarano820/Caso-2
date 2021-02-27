#include "lista.h"

bool listaSimple::isEmpty(){
    return primerNodo == NULL;
}

int listaSimple::largo(){
    int contador = 0;
    Nodo* tmp = primerNodo;
    while(tmp!=NULL){
        contador++;
        tmp = tmp->siguiente;
    }
    return contador;
}

void listaSimple::insertFirst(Nodo* pNodo){

    if(isEmpty())
        ultimoNodo = primerNodo = pNodo;
    else{

        pNodo->siguiente = primerNodo;
        primerNodo = pNodo;
    }
}

void listaSimple::insertLast(Nodo* pNodo){

    if(isEmpty())
        ultimoNodo = primerNodo = pNodo;

    else{
        ultimoNodo->siguiente = pNodo;
        ultimoNodo = pNodo;
    }
}

Nodo* listaSimple::eraseFirst(){
    if(isEmpty())
        return NULL;
    else{
        Nodo* borrado = primerNodo;
        primerNodo = primerNodo->siguiente;
        borrado->siguiente = NULL;
        if(primerNodo == NULL)
            ultimoNodo = primerNodo;
        return borrado;
    }
}

Nodo* listaSimple::eraseLast(){

    if(isEmpty())
        return NULL;

    else{
        Nodo* borrado;
        Nodo* tmp = primerNodo;
        if(tmp->siguiente == NULL){
            primerNodo = ultimoNodo = NULL;
            return tmp;
        }
        while(tmp->siguiente->siguiente != NULL)
            tmp = tmp->siguiente;

            borrado = tmp->siguiente;
            ultimoNodo = tmp;
            return borrado;
    }
}