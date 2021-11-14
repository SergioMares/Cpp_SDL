#ifndef CARGAME_BADOBJECT_H
#define CARGAME_BADOBJECT_H

class Game;
#include "GameObject.h"

class BadObject : public GameObject {
protected:
    bool alive;
public:
    static int instances;
    BadObject(Game *game): GameObject(game) {
        alive = true;
    };
    ~BadObject() override = default;
    void update() override{};
    bool toDelete() override;

    void onEnter() override;
    void onDelete() override;
    void static reset();
};


#endif //CARGAME_BADOBJECT_H
