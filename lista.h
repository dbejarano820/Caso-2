#ifndef _lista_
#define _lista_

#include <iostream>
using namespace std;

template <class T>
class Nodo{
    private:
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
        Nodo<T>* nuevoNodo = new Nodo<T>(pValue);
        if (this->primerNodo != nullptr){
            nuevoNodo->setSiguiente(primerNodo);
            primerNodo = nuevoNodo;
        } else{
            primerNodo = ultimoNodo = nuevoNodo;
        }
        count++;
        current = primerNodo;
    }

    void insertLast(T &pValue){
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

    T eraseFirst(){
        if(count == 0){
            return (T)NULL;
        }
        else{
            count--;
            Nodo<T>* primero = primerNodo;
            if (count == 0){
                ultimoNodo = primerNodo = nullptr;
            } else{
                primerNodo = primerNodo->getSiguiente();
            }
            current = primerNodo;
            
            return (T)(*primero).getValue();
        }
    }

    T seeFirst(){
         if (count == 0){
            cout << "VACIA" << endl;
            return (T)NULL;
        } else{
            cout << primerNodo->getValue() << endl;
            return primerNodo->getValue();
        }
    }
    //bool esta();

};

#endif