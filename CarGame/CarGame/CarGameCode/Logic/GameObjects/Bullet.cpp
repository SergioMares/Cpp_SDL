#include "Bullet.h"

Bullet::~Bullet() {}

void Bullet::draw()
{
	drawTexture(game->getTexture(carTexture));
}

void Bullet::update()
{
    setPosition(getX() + SPEED, getY());
    vector<Collider*> collisions = game->getCollisions(this);

    for (auto c : collisions)
        c->receiveBulletCollision(this);

    //delete after range
    if (getX() - initialPos >= RANGE)
    {      
        setDead(true);
    }
}
