#pragma once
#include "BadObject.h"
class Truck : public BadObject
{
    const int velT = 5;
public:
    Truck(Game* game) : BadObject(game)
    {
        setDimension(120, 60);
    };
    ~Truck();

    void draw();
    void update();

    bool receiveCarCollision(Car* car) override;
    bool receiveBulletCollision(Bullet* bullet) override;
};

