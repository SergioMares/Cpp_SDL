#ifndef CARGAME_ROCK_H
#define CARGAME_ROCK_H

#include "BadObject.h"

class Rock : public BadObject{

public:
    Rock(Game* game) : BadObject(game) 
    {  
        setDimension(50, 50);        
    };
    ~Rock() = default;
    
    void draw();
    void update();    
    
    bool receiveCarCollision(Car* car) override;
    bool receiveBulletCollision(Bullet* bullet) override;
};


#endif //CARGAME_CAR_H