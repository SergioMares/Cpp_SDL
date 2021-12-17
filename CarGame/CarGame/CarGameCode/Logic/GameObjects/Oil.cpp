#include "Oil.h"
#include "../Game.h"

void Oil::update() {
    setPosition(getX(), getY());
}

bool Oil::receiveCarCollision(Car* car)
{
    car->nospeed();
    car->setVelocity(3);
    

    return false;
}

bool Oil::receiveBulletCollision(Bullet* bullet)
{
    return true;
}

Oil::~Oil()
{
    onDelete();  
};

void Oil::draw() {
    drawTexture(game->getTexture(oilTexture));
}