#ifndef CARGAME_ROCK_H
#define CARGAME_ROCK_H

#include "GameObject.h"

class Rock : public GameObject{

public:
    Rock(Game* game) : GameObject(game) {};
    ~Rock();

    void draw();
    void update();    
};


#endif //CARGAME_CAR_H

