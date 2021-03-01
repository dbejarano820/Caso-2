#ifndef _repartidores_
#define _repartidores_
#include <iostream>
using namespace std;

class IObserver //interface
{
    public:
        virtual void update(bool) = 0; 
};


class Bicycle : public IObserver{
    public:
        int distance;
        int speed;
        bool pendingOrder;

        Bicycle(){
            speed = 5;
            pendingOrder = false;
        }

        virtual void update(bool pOrder){
            pendingOrder = pOrder;
        }

        void setDistance(int pDistance){
            distance = pDistance;
        }

        int calculateDistance(){
            return (distance / speed);
        }
};

class Motorcycle : public IObserver{
    public:
        int distance;
        int speed;
        bool pendingOrder;

        Motorcycle(){
            speed = 5;
            pendingOrder = false;
        }

        virtual void update(bool pOrder){
            pendingOrder = pOrder;
        }

        void setDistance(int pDistance){
            distance = pDistance;
        }

        int calculateDistance(){
            return (distance / speed);
        }
};

class Car : public IObserver{
    public:
        int distance;
        int speed;
        bool pendingOrder;

        Car(){
            speed = 5;
            pendingOrder = false;
        }

        virtual void update(bool pOrder){
            pendingOrder = pOrder;
        }

        void setDistance(int pDistance){
            distance = pDistance;
        }

        int calculateDistance(){
            return (distance / speed);
        }
};
/*
class Repartidor {
    public:
    int distanciaAlRestaurante;
    int speed;
    string tipoRepartidor;
    bool pedidoPendiente;


    int calculateTime(int pDistanciaPedido){
        return (distanciaAlRestaurante + pDistanciaPedido) / speed;
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
        pedidoPendiente = false;
    }
};

class Moto: public Repartidor{
    public:
    Moto(){
        speed = 20;
        tipoRepartidor = "Moto";
        pedidoPendiente = false;
    }
};

class Carro: public Repartidor{
    public:
    Carro(){
        speed = 30;
        tipoRepartidor = "Carro";
        pedidoPendiente = false;
    }
};
*/
#endif