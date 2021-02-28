#ifndef _repartidores_
#define _repartidores_

#include <iostream>
using namespace std;


class Repartidor{
    public:
    int distanciaAlRestaurante;
    int speed;
    string tipoRepartidor;
    bool pedidoPendiente = false;


    double calculateTime(int pDistanciaPedido){
        return (distanciaAlRestaurante + pDistanciaPedido) / (speed + 0.0);
    }

    void setDistanciaAlRestaurante(int pDistancia){
        distanciaAlRestaurante = pDistancia;
    }

    string getTipoRepartidor(){
        return tipoRepartidor;
    }
};

class Bici: public Repartidor{
    public:
    Bici(){
        speed = 10;
        tipoRepartidor = "Bici";
    }
};

class Moto: public Repartidor{
    public:
    Moto(){
        speed = 20;
        tipoRepartidor = "Moto";
    }
};

class Carro: public Repartidor{
    public:
    Carro(){
        speed = 30;
        tipoRepartidor = "Carro";
    }
};

#endif