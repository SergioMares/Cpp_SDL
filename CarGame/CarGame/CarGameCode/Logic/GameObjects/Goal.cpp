#include "Goal.h"
#include "../Game.h"

void Goal::update() {
    setPosition(getX(), getY());
}



void Goal::draw() {
    drawTexture(game->getTexture(goalTexture));
}