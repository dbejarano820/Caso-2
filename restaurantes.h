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
    vector <Repartidor*> listaRepartidores;

    public:
    void recibirPedido(){
        notify();
    }

    virtual void addObserver(IObserver* pObserver){
        Repartidor* repartidor = (Repartidor*) pObserver;
        listaRepartidores.push_back(repartidor);
    }

    virtual void removeObserver(IObserver* pObserver){
        //listaRepartidores.erase(remove(listaRepartidores.begin(),listaRepartidores.end(), pObserver), listaRepartidores.end());
    }

    virtual void notify(){

        Repartidor* repartidorMasCercano = calculateQuickest();
        for(vector<Repartidor*>::const_iterator iter = listaRepartidores.begin(); iter != listaRepartidores.end(); ++iter)
        {
            if((*iter) == repartidorMasCercano)
            {
                (*iter)->update(true);
            }
            else{
                (*iter)->update(false);
            }
        }
    }


    Repartidor* calculateQuickest(){

        Repartidor* repartidor = listaRepartidores[0];
        double tiempoMasCorto = repartidor->calculateTime();
        Repartidor* repartidorMasCercano = repartidor;    

        for(vector<Repartidor*>::iterator iter = listaRepartidores.begin(); iter != listaRepartidores.end(); ++iter)
        {
            double tiempo = (*iter)->calculateTime();
            if(tiempo < tiempoMasCorto){
                tiempoMasCorto = tiempo;
                repartidorMasCercano = (Repartidor*)(*iter);
            }

        }
        cout << "The " << repartidorMasCercano->getType() << " delivery driver was chosen for the delivery with an estimated time of " << tiempoMasCorto << " h" << endl << endl;
        return repartidorMasCercano;
    }

};

#endif