#pragma once

#include "GameObject.h"

class Goal : public GameObject{

public:
    Goal(Game* game) : GameObject(game) {};
    ~Goal();

    void draw();
    void update();
};