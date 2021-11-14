#include "Car.h"
#include "../Game.h"

void Car::setVelocity(double _newVel)
{
    actualVel = _newVel;
}

void Car::update() {
    
    setPosition(getX() + actualVel, getY());

    //the car ask who is colliding with him

    vector<Collider*> collisions = game->getContainer()->getCollisions(this);

    for (auto c : collisions)
        c->receiveCarCollision(this);
}


//new definitions
void Car::moveCar(int _DirX, int _DirY)
{
    double actPosY, newPosX, newPosY;    
    actPosY = getY();

    if (_DirX == 1 && actualVel < MAX_SPEED)
    {
        //puts("aumento");
        if (actualVel == 0)
            actualVel++;
        else
            actualVel *= ACCELERATION;
    }
    else if (_DirX == -1)
    {
        //puts("decremento");
        if (actualVel > 1)
            actualVel *= DECELERATION;
        else
            actualVel = 0;
    }


    //cout << actualVel << endl;
    
    newPosY = actPosY - (VSPEED * double(_DirY));
    
    setPosition(getX(), newPosY);

}

Car::~Car(){};

void Car::draw() {
    drawTexture(game->getTexture(carTexture));
}