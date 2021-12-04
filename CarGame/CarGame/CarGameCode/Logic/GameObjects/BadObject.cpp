#include "BadObject.h"
#include "../Game.h"
// TODO: add includes

void  BadObject::onEnter(){
    instances += 1;
};

void  BadObject::onDelete(){
    instances -= 1;
};

void BadObject::reset(){
    instances = 0;
}
bool BadObject::wave(int value)
{
    while (value > 0)
    {
        setPosition(getX() + 1, getY());
        value--;
    }
    return false;
}
;

bool BadObject::toDelete() {
    return !alive || game->isRebased(this);
}

int BadObject::instances = 0;