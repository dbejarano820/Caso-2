#ifndef _repartidores_
#define _repartidores_
#include <iostream>
using namespace std;

class IObserver //interface
{
    public:
        virtual void update(bool) = 0;
};

class Repartidor : public IObserver{
    public:
        int distance;
        int speed;
        bool pendingOrder;

        virtual double calculateTime(){
            return (distance / (speed + 0.0));
        }

        virtual void setDistance(int pDistance){
            distance = pDistance;
        }

        virtual string getType() = 0;
};

class Bicycle : public Repartidor{
    public:
        Bicycle(){
            speed = 5;
            pendingOrder = false;
        }

        virtual void update(bool pOrder){
            pendingOrder = pOrder;
            if (pendingOrder){
                cout << "The bicycle will deliver the order" << endl;
            } else{
                cout << "The bicycle will not deliver the order" << endl;
            }
        }

        virtual string getType() {
            return "bicycle";
        }
};

class Motorcycle : public Repartidor{
    public:
        Motorcycle(){
            speed = 20;
            pendingOrder = false;
        }

        virtual void update(bool pOrder){
            pendingOrder = pOrder;
            if (pendingOrder){
                cout << "The motorcycle will deliver the order" << endl;
            } else{
                cout << "The motorcycle will not deliver the order" << endl;
            }
        }

        virtual string getType() {
            return "motorcycle";
        }
};

class Car : public Repartidor{
    public:
        Car(){
            speed = 15;
            pendingOrder = false;
        }

        virtual void update(bool pOrder){
            pendingOrder = pOrder;
            if (pendingOrder){
                cout << "The car will deliver the order" << endl;
            } else{
                cout << "The car will not deliver the order" << endl;
            }
        }

        virtual string getType() {
            return "car";
        }
};
#endif