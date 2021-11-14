#include "Rock.h"
#include "../Game.h"

void Rock::update() {
     setPosition(getX(), getY());
}

bool Rock::receiveCarCollision(Car* car)
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

Rock::~Rock() 
{ 
    onDelete(); 
    puts("petó");
};

void Rock::draw() {
    drawTexture(game->getTexture(rockTexture));
}