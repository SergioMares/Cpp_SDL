#ifndef CARGAME_GAMEOBJECTGENERATOR_H
#define CARGAME_GAMEOBJECTGENERATOR_H

#include "Game.h"

class GameObjectGenerator {
    Point2D<int> static generateRandomPosition(Game *game, GameObject *o);
    void static addInRandomPosition(Game *game, GameObject *o);

public:
    static void generate(Game *game, int N_ROCKS = 0)
    {        
        for(int i = 0; i < N_ROCKS; i++)
            addInRandomPosition(game, new Rock(game));
    }   
};


#endif //CARGAME_GAMEOBJECTGENERATOR_H
