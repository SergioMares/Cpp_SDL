#ifndef CARGAME_BADOBJECT_H
#define CARGAME_BADOBJECT_H

class Game;
#include "GameObject.h"

class BadObject : public GameObject {

public:
    static int instances;
    BadObject(Game *game): GameObject(game){};
    ~BadObject() override = default;
    void update() override{};

    void onEnter() override;
    void onDelete() override;
    void static reset();

    bool wave(int value = 150) override;
    bool blast() override;
};


#endif //CARGAME_BADOBJECT_H
