#include <iostream>
using namespace std;

template <class T>
class Nodo{
    private:
    T* dato;
    Nodo<T>* siguiente;

    public:
    Node(T &pData){
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
    int count = 0;
    Nodo<T>* primerNodo; //first node
    Nodo<T>* ultimoNodo; //last node
    Nodo<T>* current;

    public:
    ListaSimple(){
        primerNodo = ultimoNodo = current = nullptr;
        count = 0;
    }

    bool isEmpty();
    void insertFirst(T &pValue);
    void insertLast(T &pValue);
    T eraseFirst();
    T seeFirst();
    //bool esta();

};
