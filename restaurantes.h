#ifndef _restaurante_
#define _restaurante_

#include <iostream>
#include "repartidores.h"
using namespace std;

class Restaurante{
    protected:
    Bici * repBici;
    Moto * repMoto;
    Carro * repCarro;
    int distanciaPedido;

    Repartidor * repartidorMasCercano;
    double tiempoMasCorto;

    public:
    Restaurante(){
        repBici = new Bici();
        repMoto = new Moto();
        repCarro = new Carro();
        distanciaPedido = 0;
        tiempoMasCorto = 0;
        repartidorMasCercano = NULL;
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

    void calculateQuickest(){
        tiempoMasCorto = repBici->calculateTime(distanciaPedido);
        repartidorMasCercano = repBici;
        cout << "Bici: " << repBici->calculateTime(distanciaPedido) << endl;

        if (repMoto->calculateTime(distanciaPedido) < tiempoMasCorto){
            tiempoMasCorto = repMoto->calculateTime(distanciaPedido);
            repartidorMasCercano = repMoto;
        }
        cout << "Moto: " << repMoto->calculateTime(distanciaPedido) << endl;

        if (repCarro->calculateTime(distanciaPedido) < tiempoMasCorto){
            tiempoMasCorto = repCarro->calculateTime(distanciaPedido);
            repartidorMasCercano = repCarro;
        }
        cout << "Carro: " << repCarro->calculateTime(distanciaPedido) << endl;

        cout << repartidorMasCercano->getTipoRepartidor() << endl;
    }
};

#endif