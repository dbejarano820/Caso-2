#include "lista.h"
/*
template <class T>
bool ListaSimple<T>::isEmpty(){
    return primerNodo == nullptr;
}

template<class T>
void ListaSimple<T>::insertFirst(T &pValue){
        Nodo<T>* nuevoNodo = nullptr;
        nuevoNodo = new Nodo<T>(pValue);
        if (this->primerNodo != nullptr){
            nuevoNodo->setSiguiente(primerNodo);
            primerNodo = nuevoNodo;
        } else{
            primerNodo = ultimoNodo = nuevoNodo;
        }
        count++;
        current = primerNodo;
    }

template<class T>
void ListaSimple<T>::insertLast(T &pValue){
    Nodo<T>* nuevoNodo = new Nodo<T>(pValue);
    if (this->ultimoNodo != nullptr){
        this->ultimoNodo->setSiguiente(nuevoNodo);
        this->ultimoNodo = nuevoNodo;
    } else{
        primerNodo = ultimoNodo = nuevoNodo;
    }
    count++;
    current = primerNodo;
}

template<class T>
T ListaSimple<T>::eraseFirst(){
    if(isEmpty())
        return nullptr;
    else{
        count--;
        Nodo<T>* primero = primerNodo;
        if (count == 0){
            ultimoNodo = primerNodo = nullptr;
        } else{
            primerNodo = primerNodo->getSiguiente();
        }
        current = primerNodo;
        
        return (T)(*primero).getValue;
    }
}

template<class T>
T ListaSimple<T>::seeFirst(){
    return primerNodo->getValue();
}
*/