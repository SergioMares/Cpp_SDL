//
// Created by eys on 21/8/21.
//

#ifndef CARGAME_CAR_H
#define CARGAME_CAR_H

#include "GameObject.h"

class Car : public GameObject{

private:

    const double ACCELERATION = 1.3;
    const double DECELERATION = 0.9;
    const int VSPEED = 5;
    const int MAX_SPEED = 10;
    const int INITIAL_POWER = 3;

    double actualVel;

public:
    Car(Game* game) : GameObject(game) {};

    ~Car();

    void draw();
    void update();

    //new declarations
    void moveCar(int dirX, int dirY);    

    void setVelocity(double NewVel);    

    double getVelocity() { return actualVel; };
    int getPower() { return INITIAL_POWER; };

    void needforspeed(){ actualVel = 20.0; }

};


#endif //CARGAME_CAR_H
