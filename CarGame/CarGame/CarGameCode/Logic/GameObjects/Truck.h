#pragma once
#include "Rock.h"
class Truck : public Rock
{
    const int velT = 5;
public:
    Truck(Game* game) : Rock(game)
    {
        setDimension(120, 60);
    };
    void draw();
    void update();

};

