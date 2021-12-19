#pragma once

#include "GameObject.h"

class Goal : public GameObject{

public:
    Goal(Game* game) : GameObject(game) {};
    ~Goal() = default;

    void draw();
};