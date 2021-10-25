//
// Created by eys on 21/8/21.
//

#include "Car.h"
#include "../Game.h"

Car::Car(Game *game){
    this->game = game;
    //texture = nullptr;
    actualVel = 0;    
}

void Car::setDimension(int width, int height){
    w = width;
    h = height;
};

void  Car::setPosition(double x, double y){
    pos = Point2D<double>(x, y);
};

void Car::setVelocity(double _newVel)
{
    actualVel = _newVel;
}

void Car::update() {
    pos = Point2D<double>(getX() + actualVel, getY());
}


//new definitions
void Car::moveCar(int _DirX, int _DirY)
{
    double actPosY, newPosX, newPosY;    
    actPosY = getY();

    if (_DirX == 1 && actualVel < MAX_SPEED)
    {
        //puts("aumento");
        if (actualVel == 0)
            actualVel++;
        else
            actualVel *= ACCELERATION;
    }
    else if (_DirX == -1)
    {
        //puts("decremento");
        if (actualVel > 1)
            actualVel *= DECELERATION;
        else
            actualVel = 0;
    }


    //cout << actualVel << endl;
    
    newPosY = actPosY - (VSPEED * double(_DirY));
    
    setPosition(getX(), newPosY);

}



Car::~Car(){};

void Car::draw() {
    drawTexture(game->getTexture(carTexture));
}


void Car::drawTexture(Texture *texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h};
    SDL_Rect massBox = { getX() +dX-5, getY()-5, 10, 10 };
    texture->render(textureBox);
    if (game->getDebug())
    {
        Box(textureBox, BLACK).render(game->getRenderer());
        Box(massBox, BLACK).render(game->getRenderer());
    }
    cout << getX() << endl;
}


SDL_Rect Car::getCollider(){
    return { int(getX() - getWidth()),
             int(getY() - getHeight()/2),
             getWidth(),
             getHeight()};
}