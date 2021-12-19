#include "Goal.h"
#include "../Game.h"

void Goal::draw() {
    drawTexture(game->getTexture(goalTexture));
}