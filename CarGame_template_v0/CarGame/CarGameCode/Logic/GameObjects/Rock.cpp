#include "Rock.h"
#include "../Game.h"

void Rock::update() {
     setPosition(getX(), getY());
}

Rock::~Rock() {};

void Rock::draw() {
    drawTexture(game->getTexture(rockTexture));
}