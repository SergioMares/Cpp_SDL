#pragma once
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
class Game;
class Goal {

private:
    Point2D<double> pos;
    int w, h;
    Game* game;
    //Texture* texture;

public:
    Goal(Game* game);
    ~Goal();

    void draw();

    //new declarations


    void drawTexture(Texture* texture);

    void setDimension(int width, int height);

    double getX() { return pos.getX(); };
    double getY() { return pos.getY(); };
    int getWidth() { return w; };
    int getHeight() { return h; };

    void setPosition(double x, double y);

    SDL_Rect getCollider();
};


