#include "GoodObject.h"
#include "../Game.h"
// TODO: add includes

void  GoodObject::onEnter() {
    instances += 1;
};

void  GoodObject::onDelete() {
    instances -= 1;
};

void GoodObject::reset() {
    instances = 0;
}

bool GoodObject::wave(int value)
{
    while (value > 0)
    {
        setPosition(getX() - 1, getY());
        value--;
    }
    return false;
}



bool GoodObject::toDelete() {
    return !alive || game->isRebased(this);
}

int GoodObject::instances = 0;