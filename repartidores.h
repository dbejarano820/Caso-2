#ifndef _repartidores_
#define _repartidores_

#include <iostream>
using namespace std;

class repartidor{
    protected:
    int distanciaAlRestaurante;
    int speed;
    string tipoRepartidor;

    public:
    int calculateTime(int pDistanciaPedido){
        return (distanciaAlRestaurante + pDistanciaPedido) / speed;
    }

    void setDistanciaAlRestaurante(int pDistancia){
        distanciaAlRestaurante = pDistancia;
    }
};

class bici : public repartidor{
    public:
    bici(){
        speed = 10;
        tipoRepartidor = "Bici";
    }
};

class moto : public repartidor{
    public:
    moto(){
        speed = 20;
        tipoRepartidor = "Moto";
    }
};

class carro : public repartidor{
    public:
    carro(){
        speed = 30;
        tipoRepartidor = "Carro";
    }
};

#endif