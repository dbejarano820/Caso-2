#ifndef _restaurante_
#define _restaurante_

#include <iostream>
#include "repartidores.h"
using namespace std;

class Restaurante{
    public:
    Bici * repBici;
    Moto * repMoto;
    Carro * repCarro;
    int distanciaPedido;

    Repartidor * repartidorMasCercano;
    int distanciaMasCercano;

    //public:
    Restaurante(){
        repBici = new Bici();
        repMoto = new Moto();
        repCarro = new Carro();
        distanciaPedido = 0;
        distanciaMasCercano = 0;
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

    }
};

#endif