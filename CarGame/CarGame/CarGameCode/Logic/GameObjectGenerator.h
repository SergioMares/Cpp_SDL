#ifndef CARGAME_GAMEOBJECTGENERATOR_H
#define CARGAME_GAMEOBJECTGENERATOR_H

#include "Game.h"
#include "GameObjects/Rock.h"
#include "GameObjects/PowerUp.h"
#include "GameObjects/Coin.h"

class GameObjectGenerator {
    Point2D<int> static generateRandomPosition(Game *game, GameObject *o);
    void static addInRandomPosition(Game *game, GameObject *o);

public:
    static void generateObjects(Game *game, 
        int N_ROCKS = 0,
        int N_PU = 0,
        int N_COINS = 0)
    {        
        for(int i = 0; i < N_ROCKS; i++)
            addInRandomPosition(game, new Rock(game));
        for (int i = 0; i < N_PU; i++)
            addInRandomPosition(game, new PowerUp(game));
        for (int i = 0; i < N_COINS; i++)
            addInRandomPosition(game, new Coin(game));
    }   
};


#endif //CARGAME_GAMEOBJECTGENERATOR_H
