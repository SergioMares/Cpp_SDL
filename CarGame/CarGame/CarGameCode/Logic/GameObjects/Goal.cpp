#include "Goal.h"
#include "../Game.h"

void Goal::update() {
    setPosition(getX(), getY());
}

Goal::~Goal() {};

void Goal::draw() {
    drawTexture(game->getTexture(goalTexture));
}