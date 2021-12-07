#include "Oil.h"
#include "../Game.h"

void Oil::update() {
    setPosition(getX(), getY());
}

bool Oil::receiveCarCollision(Car* car)
{
    car->setVelocity(0);
    

    return false;
}

bool Oil::receiveBulletCollision(Bullet* bullet)
{
    return true;
}

Oil::~Oil()
{
    onDelete();
    puts("De el");
};

void Oil::draw() {
    drawTexture(game->getTexture(oilTexture));
}