#ifndef CARGAME_SUPERROCK_H
#define CARGAME_SUPERROCK_H

#include "BadObject.h"

class Superrock : public BadObject {

public:
    Superrock(Game* game) : BadObject(game)
    {
        onEnter();
        setDimension(160, 80);

    };
    ~Superrock();

    void draw();
    void update();

    bool receiveCarCollision(Car* car) override;
    bool receiveBulletCollision(Bullet* bullet) override;
};


#endif //CARGAME_CAR_H