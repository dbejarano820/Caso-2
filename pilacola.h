#ifndef _pilacola_
#define _pilacola_

#include "lista.h"

template<class T>
class Pila : public ListaSimple<T>{
    public:
    T pop(){
        return (T)ListaSimple<T>::eraseFirst();
    }
    void push(T &pValue){
        ListaSimple<T>::insertFirst(pValue);
    }

    T peek(){
        return (T)ListaSimple<T>::seeFirst();
    }
};

template<class T>
class Cola : public ListaSimple<T>{

    public:
    void encolar(T &pValue){
        ListaSimple<T>::insertLast(pValue);
    }

    T desencolar(){
        return (T)ListaSimple<T>::eraseFirst();
    }

    T verFrente(){
        return (T)ListaSimple<T>::seeFirst();
    }
};

#endif