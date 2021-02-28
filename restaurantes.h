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
        repBici->setDistanciaAlRestaurante(pDistancia);
    }

    void setDistanciaMoto(int pDistancia){
        repMoto->setDistanciaAlRestaurante(pDistancia);
    }

    void setDistanciaCarro(int pDistancia){
        repCarro->setDistanciaAlRestaurante(pDistancia);
    }

    Repartidor * getRepartidor(string tipoRepartidor){
        Nodo<Repartidor*> * nodo = listaRepartidores->current;

    }

    void calculateQuickest(){
        tiempoMasCorto = repBici->calculateTime(distanciaPedido);
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

        cout << "El repartidor mas rapido es el que va en "<<repartidorMasCercano->getTipoRepartidor() << endl;
    }
};

#endif