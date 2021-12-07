#ifndef CARGAME_OIL_H
#define CARGAME_OIL_H

#include "BadObject.h"

class Oil : public BadObject {

public:
    Oil(Game* game) : BadObject(game)
    {
        onEnter();
        setDimension(40, 40);

    };
    ~Oil();

    void draw();
    void update();

    bool receiveCarCollision(Car* car) override;
    bool receiveBulletCollision(Bullet* bullet) override;
};


#endif //CARGAME_CAR_H