#include "Rock.h"
#include "../Game.h"

Rock::Rock(Game* game) {
    this->game = game;
    //texture = nullptr;
}

void Rock::setDimension(int width, int height) {
    w = width;
    h = height;
};

void  Rock::setPosition(double x, double y) {
    pos = Point2D<double>(x, y);
};

void Rock::update() {
    pos = Point2D<double>(getX(), getY());
}

Rock::~Rock() {};

void Rock::draw() {
    drawTexture(game->getTexture(rockTexture));
}


void Rock::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
    if (game->getDebug())
        Box(textureBox, BLACK).render(game->getRenderer());
        
}


SDL_Rect Rock::getCollider() {
    return { int(getX() - getWidth()),
             int(getY() - getHeight() / 2),
             getWidth(),
             getHeight() };
}