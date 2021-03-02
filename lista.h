#ifndef _lista_
#define _lista_

#include <iostream>
using namespace std;

template <class T>
class Nodo{
    public:
    T* dato;
    Nodo<T>* siguiente;

    public:
    Nodo(T &pData){
        this->dato = &pData;
        this->siguiente = nullptr;
    }

    T getValue(){
        return (*this->dato);
    }

    Nodo<T>* getSiguiente(){
        return this->siguiente;
    }

    void setSiguiente(Nodo<T>* pSiguiente){
        this->siguiente = pSiguiente;
    }
};

template<class T>
class ListaSimple{

    private:
    int count;
    Nodo<T>* primerNodo; //first node
    Nodo<T>* ultimoNodo; //last node
    Nodo<T>* current;

    public:
    ListaSimple(){
        primerNodo = ultimoNodo = current = nullptr;
        count = 0;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insertFirst(T &pValue){
        Nodo<T>* nuevoNodo = nullptr;
        nuevoNodo = new Nodo<T>(pValue);
        if (this->primerNodo != nullptr){
            nuevoNodo->setSiguiente(primerNodo);
            this->primerNodo = nuevoNodo;
        } else{
            this->primerNodo = this->ultimoNodo = nuevoNodo;
        }
        this->count++;
        this->current = this->primerNodo;
    }

    void insertLast(T &pValue){
        Nodo<T>* nuevoNodo = nullptr;
        nuevoNodo = new Nodo<T>(pValue);
        if (this->ultimoNodo != nullptr){
            this->ultimoNodo->setSiguiente(nuevoNodo);
            this->ultimoNodo = nuevoNodo;
        } else{
            this->primerNodo = this->ultimoNodo = nuevoNodo;
        }
        this->count++;
        this->current = this->primerNodo;
    }

    T eraseFirst(){   
        this->current = this->primerNodo->siguiente;
        T first = (*this->primerNodo).getValue();
        this->primerNodo = this->current;
        return first;
    }

    T seeFirst(){
            this->current = this->primerNodo;
            return (T)(*primerNodo).getValue();
    }

    T getIndex(int pIndex){
        if (pIndex >=0 && pIndex < count){
            Nodo <T>* nodoTmp = primerNodo;
            for(int currentIndex = 0; currentIndex < pIndex; currentIndex++){
                nodoTmp = nodoTmp->getSiguiente();
                //current = current->getSiguiente();
            }
            return  nodoTmp->getValue();  //current->getValue();
        } else{
            return (T)NULL;
        }
    }

    int getSize(){
        return count;
    }

};

struct DummyStruct{
    public:
    int num;
    string name;    
};

#endif