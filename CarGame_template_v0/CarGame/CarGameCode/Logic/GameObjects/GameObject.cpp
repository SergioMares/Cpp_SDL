#include "GameObject.h"
#include "../Game.h"

void GameObject::drawTexture(Texture* texture)
{
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();



    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    SDL_Rect massBox = { getX() + dX - 5, getY() - 5, 10, 10 };
    texture->render(textureBox);
    if (game->getDebug())
    {
        Box(textureBox, BLACK).render(game->getRenderer());
        Box(massBox, BLACK).render(game->getRenderer());
    }
    
}

void GameObject::drawDebug()
{
	puts("debug jeje");
}

void GameObject::setPosition(double x, double y)
{
    pos = Point2D<double>(x, y);
}

void GameObject::setDimension(double width, double height)
{
    w = width;
    h = height;
}

void GameObject::setDead(bool _dead)
{
    isDead = _dead;
}

SDL_Rect GameObject::getCollider()
{
    return { int(getX() - getWidth()),
             int(getY() - getHeight() / 2),
             getWidth(),
             getHeight() };
}

SDL_Rect GameObject::getCenter()
{
    return { int(getX() - getWidth()),
             int(getY() - getHeight() / 2),
             1,
             1};
}

bool GameObject::collide(SDL_Rect other)
{
    return false;
}
