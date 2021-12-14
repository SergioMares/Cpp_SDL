#include "Truck.h"
#include "../Game.h"

Truck::~Truck()
{
    onDelete();
}

void Truck::draw()
{
	drawTexture(game->getTexture(truckTexture));
}

void Truck::update()
{
	setPosition(getX()-5, getY());
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
    return false;
}
