#include "Superrocks.h"
#include "../Game.h"

void Superrock::update() {
    setPosition(getX(), getY());
}

bool Superrock::receiveCarCollision(Car* car)
{
    car->setVelocity(0);
    setDead(true);
    if (game->modPower(-2))
    {
        game->setEnding(false);
        game->state = game->GameOver;
    }

    return false;
}

bool Superrock::receiveBulletCollision(Bullet* bullet)
{
    return true;
}

Superrock::~Superrock()
{
    onDelete();
    puts("VOLO");
};

void Superrock::draw() {
    drawTexture(game->getTexture(superRockTexture));
}