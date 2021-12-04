#pragma once

class Game;
#include "GameObject.h"

class GoodObject : public GameObject {
protected:
    bool alive;
public:
    static int instances;
    GoodObject(Game* game) : GameObject(game) {
        alive = true;
    };
    ~GoodObject() override = default;
    void update() override {};
    bool toDelete() override;

    void onEnter() override;
    void onDelete() override;
    void static reset();

    bool wave(int value = 150) override;
};