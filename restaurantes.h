#ifndef _restaurante_
#define _restaurante_

#include <iostream>
#include <vector>
#include <list>
#include "repartidores.h"
#include "lista.h"
using namespace std;


class IObservable //abstract class
{
    public:
        virtual void addObserver(IObserver *pObserver) = 0;
        virtual void removeObserver(IObserver *pObserver) = 0;
        virtual void notify() = 0;
};



class Restaurante : public IObservable{
    protected:
    ListaSimple<IObserver*>* listaRepartidores;

    Repartidor * repartidorMasCercano;
    double tiempoMasCorto;

    public:

    virtual void addObserver(IObserver* pObserver){
        listaRepartidores->insertLast(pObserver);
    }

    virtual void removeObserver(IObserver* pObserver){
        //listObservers.erase(remove(listObservers.begin(),listObservers.end(), pObserver), listObservers.end());
    }

    virtual void notify(){
        cout << "entro" << endl;
        calculateQuickest();
        for (int index = 0; index < listaRepartidores->getSize(); index++){
            cout << index << endl;
            Repartidor * repartidorActual = (Repartidor*)listaRepartidores->getIndex(index);
            if (repartidorActual == repartidorMasCercano){
                repartidorActual->update(true);
            } else{
                repartidorActual->update(false);
            }
        }

    }

    Restaurante(){
        
        tiempoMasCorto = 0;
        repartidorMasCercano = NULL;
        listaRepartidores = new ListaSimple<IObserver*>();
        addObserver(new Bicycle());
        addObserver(new Motorcycle());
        addObserver(new Car());
    }

    void setDistanciaBici(int pDistancia){
        Repartidor * bici = getRepartidor("bicycle");
        bici->setDistance(pDistancia);
    }

    void setDistanciaMoto(int pDistancia){
        Repartidor * moto = getRepartidor("motorcycle");
        moto->setDistance(pDistancia);
    }

    void setDistanciaCarro(int pDistancia){
        Repartidor * carro = getRepartidor("car");
        carro->setDistance(pDistancia);
    }

    Repartidor * getRepartidor(string pTipoRepartidor){
        for (int index = 0; index < listaRepartidores->getSize(); index++){
            Repartidor* repartidor = (Repartidor*)listaRepartidores->getIndex(index);
            if (repartidor->getType() == pTipoRepartidor){
                return repartidor;
            }
        }
        return NULL;
    }

    void calculateQuickest(){
        Repartidor * repartidor = (Repartidor*)listaRepartidores->getIndex(0);
        tiempoMasCorto = repartidor->calculateTime();
        repartidorMasCercano = repartidor;
        cout << "The " << repartidor->getType() << " takes " << tiempoMasCorto <<endl;

        for (int index = 1; index < listaRepartidores->getSize(); index++){
            repartidor = (Repartidor*)listaRepartidores->getIndex(index);
            double tiempo = repartidor->calculateTime();
            if (tiempo < tiempoMasCorto){
                tiempoMasCorto = tiempo;
                repartidorMasCercano = repartidor;
            }
            cout << "The " << repartidor->getType() << " takes " << tiempoMasCorto <<endl;
        }
    }
};




#endif