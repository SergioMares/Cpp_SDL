//
// Created by eys on 20/8/21.
//

#ifndef CARGAME_GAME_H
#define CARGAME_GAME_H

#include <iostream>
#include <string>
#include <vector>

#include "../View/TextureContainer.h"
#include "../View/Texture.h"
#include "../View/Box.h"
#include "../View/Font.h"

#include "GameObjects/Car.h"
#include "GameObjects/Goal.h"
#include "GameObjects/Bullet.h"
#include "GameObjectContainer.h"
#include "GameObjectGenerator.h"
#include "../View/Infobar.h"

using namespace std;

class Game{
private:
    string name;
    
    bool doExit;
    bool bMoveUp;
    bool bMoveDown;
    bool bMoveForward;
    bool bMoveBackward;
    bool goodEnding;
    bool debug;
    
    int roadLength;
    int width;
    int height;    
    int infoSize;
    int power;
    int coins;
    int initTime;
    int time;
    int record;

    const unsigned int OBSTACLES = 20;
    const unsigned int POWERUPS = 3;
    const unsigned int COINS = 10;
    const unsigned int INITIAL_COINS = 3;

    //objects
    GameObjectContainer *goContainer = nullptr;
    Car *car = nullptr;
    Goal* goal = nullptr;
    Bullet* bullet = nullptr;
    //vector<Rock*> rocks;

    TextureContainer *textureContainer;
    SDL_Renderer* renderer = nullptr;
    Font *font;        

public:
    const unsigned int CAR_WIDTH = 100;
    const unsigned  int CAR_HEIGHT = 50;

    const unsigned int ROCK_SIZE = CAR_HEIGHT;
    const unsigned int ROCK_RANGE = ROCK_SIZE/2;

    const unsigned int PU_SIZE = CAR_HEIGHT * 0.9;
    const unsigned int COIN_SIZE = CAR_HEIGHT * 0.5;

    Game(string name, int width, int height, int roadLength);
    ~Game();

    void startGame();
    void update();
    void draw();
    
    void setMovement(int Direction);   
    bool modPower(int PowerModifier);
    void modCoins(int coinsModifier);
    bool getDebug() { return debug; };
    void setDebug(bool DebugState);
    bool isRebased(GameObject *go);
    void spawnBullet();
    
    enum { Menu, Playing, GameOver } state;  

    void setUserExit();
    bool isUserExit();
    bool doQuit();

    int getWindowWidth();
    int getWindowHeight();
    int getRoadLength();
    int getInfoSize();
    int getCoins();
    int getCarX();
    int getCarY();
   
    vector<Collider*> getCollisions(GameObject* g);
    vector<Collider*> getCollisions();
    bool hasCollisions(GameObject* g);
    void addToContainer(GameObject* g);



    Point2D<int> getOrigin();

    string getGameName();

    void setEnding(bool ending);
    void setRenderer(SDL_Renderer *renderer);
    void loadTextures();
    Texture *getTexture(TextureName name);
    SDL_Renderer *getRenderer();
    void renderText(string text, int x, int y, SDL_Color color={0,0,0});

    friend class Infobar;
};


#endif //CARGAME_GAME_H
