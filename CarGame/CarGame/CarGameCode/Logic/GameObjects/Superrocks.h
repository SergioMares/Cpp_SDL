#ifndef CARGAME_SUPERROCK_H
#define CARGAME_SUPERROCK_H

#include "BadObject.h"

class Superrock : public BadObject {

public:
    Superrock(Game* game) : BadObject(game)
    {
        setDimension(160, 80);
    };
    ~Superrock() = default;

    void draw();

    bool receiveCarCollision(Car* car) override;
    bool receiveBulletCollision(Bullet* bullet) override;
};


#endif //CARGAME_CAR_H