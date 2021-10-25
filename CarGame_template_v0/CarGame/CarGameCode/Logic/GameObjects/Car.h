//
// Created by eys on 21/8/21.
//

#ifndef CARGAME_CAR_H
#define CARGAME_CAR_H


class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"

class Car {

private:

    const double ACCELERATION = 1.3;
    const double DECELERATION = 0.9;
    const int VSPEED = 5;
    const int MAX_SPEED = 10;
    const int INITIAL_POWER = 3;

    double actualVel;

    Point2D<double> pos;
    int w, h;    
    Game *game;
    //Texture *texture;


public:
    Car(Game *game);
    ~Car();

    void draw();
    void update();

    //new declarations
    void moveCar(int dirX, int dirY);    

    void drawTexture(Texture* texture);

    void setDimension(int width, int height);
    void setPosition(double x, double y);
    void setVelocity(double NewVel);    

    double getX() { return pos.getX(); };
    double getY() { return pos.getY(); };   
    int getWidth() {return w;};
    int getHeight() {return h;};
    double getVelocity() { return actualVel; };
    int getPower() { return INITIAL_POWER; };



    SDL_Rect getCollider();
};


#endif //CARGAME_CAR_H
