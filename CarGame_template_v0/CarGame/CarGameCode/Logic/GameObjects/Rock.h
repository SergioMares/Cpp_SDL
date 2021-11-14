#ifndef CARGAME_ROCK_H
#define CARGAME_ROCK_H

#include "BadObject.h"

class Rock : public BadObject{

public:
    Rock(Game* game) : BadObject(game) { onEnter(); };
    ~Rock();

    void draw();
    void update();    
    
    bool receiveCarCollision(Car* car) override;
};


#endif //CARGAME_CAR_H