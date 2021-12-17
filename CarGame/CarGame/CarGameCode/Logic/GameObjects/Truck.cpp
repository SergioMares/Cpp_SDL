#include "Truck.h"
#include "../Game.h"

void Truck::update() {
    setPosition(getX()-velT, getY());
}

bool Truck::receiveCarCollision(Car* car)
{
    car->setVelocity(0);
    setDead(true);
    if (game->modPower(-1))
    {
        game->setEnding(false);
        game->state = game->GameOver;
    }

    return false;
}

bool Truck::receiveBulletCollision(Bullet* bullet)
{
    setDead(true);
    bullet->setDead(true);
    return true;
}

Truck::~Truck()
{
    onDelete();
};

void Truck::draw() {
    drawTexture(game->getTexture(truckTexture));
}
