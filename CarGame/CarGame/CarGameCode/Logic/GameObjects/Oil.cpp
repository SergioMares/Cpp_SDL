#include "Oil.h"
#include "../Game.h"

bool Oil::receiveCarCollision(Car* car)
{   
    car->setVelocity(1);    
    return false;
}

bool Oil::receiveBulletCollision(Bullet* bullet)
{
    return true;
}



void Oil::draw() {
    drawTexture(game->getTexture(oilTexture));
}