#include "Truck.h"
#include "../Game.h"

void Truck::update() {
    setPosition(getX()-velT, getY());
}

void Truck::draw() {
    drawTexture(game->getTexture(truckTexture));
}
