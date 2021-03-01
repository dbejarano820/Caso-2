#ifndef _restaurante_
#define _restaurante_

#include <iostream>
#include "repartidores.h"
#include "lista.h"
using namespace std;

class Restaurante{
    protected:
    int distanciaPedido;
    ListaSimple<Repartidor*>* listaRepartidores;

    Repartidor * repartidorMasCercano;
    double tiempoMasCorto;

    public:
    Restaurante(){
        
        distanciaPedido = 0;
        tiempoMasCorto = 0;
        repartidorMasCercano = NULL;
        Repartidor * repBici = new Bici();
        Repartidor * repMoto = new Moto();
        Repartidor * repCarro = new Carro();
        listaRepartidores = new ListaSimple<Repartidor*>();
        listaRepartidores->insertLast(repBici);
        listaRepartidores->insertLast(repMoto);
        listaRepartidores->insertLast(repCarro);

    }

    void setDistanciaPedido(int pDistancia){
        distanciaPedido = pDistancia;
    }

    void setDistanciaBici(int pDistancia){
        Repartidor * bici = getRepartidor("bici");
        bici->setDistanciaAlRestaurante(pDistancia);
    }

    void setDistanciaMoto(int pDistancia){
        Repartidor * moto = getRepartidor("moto");
        moto->setDistanciaAlRestaurante(pDistancia);
    }

    void setDistanciaCarro(int pDistancia){
        Repartidor * carro = getRepartidor("carro");
        carro->setDistanciaAlRestaurante(pDistancia);
    }

    Repartidor * getRepartidor(string pTipoRepartidor){
        for (int index = 0; index < listaRepartidores->getSize(); index++){
            Repartidor* repartidor = listaRepartidores->getIndex(index);
            if (repartidor->tipoRepartidor == pTipoRepartidor){
                return repartidor;
            }
        }
        return NULL;
    }

    void calculateQuickest(){
        Repartidor * repartidor = listaRepartidores->getIndex(0);
        tiempoMasCorto = repartidor->calculateTime(distanciaPedido);
        repartidorMasCercano = repartidor;
        cout << "El repartidor en " << repartidor->getTipoRepartidor() << " dura " << tiempoMasCorto <<endl;

        for (int index = 1; index < listaRepartidores->getSize(); index++){
            repartidor = listaRepartidores->getIndex(index);
            double tiempo = repartidor->calculateTime(distanciaPedido);
            if (tiempo < tiempoMasCorto){
                tiempoMasCorto = tiempo;
                repartidorMasCercano = repartidor;
            }
            cout << "El repartidor en " << repartidor->getTipoRepartidor() << " dura " << tiempoMasCorto <<endl;
        }

        /*tiempoMasCorto = repBici->calculateTime(distanciaPedido);
        repartidorMasCercano = repBici;
        cout << "La bici dura " << repBici->calculateTime(distanciaPedido) << endl;

        if (repMoto->calculateTime(distanciaPedido) < tiempoMasCorto){
            tiempoMasCorto = repMoto->calculateTime(distanciaPedido);
            repartidorMasCercano = repMoto;
        }
        cout << "La moto dura " << repMoto->calculateTime(distanciaPedido) << endl;

        if (repCarro->calculateTime(distanciaPedido) < tiempoMasCorto){
            tiempoMasCorto = repCarro->calculateTime(distanciaPedido);
            repartidorMasCercano = repCarro;
        }
        cout << "El carro dura " << repCarro->calculateTime(distanciaPedido) << endl;
        */
        
        cout << "El repartidor mas rapido es el que va en "<<repartidorMasCercano->getTipoRepartidor()
        << "y dura " << tiempoMasCorto << endl;
    }
};

#endif