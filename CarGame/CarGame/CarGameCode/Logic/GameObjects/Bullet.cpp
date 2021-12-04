#include "Bullet.h"

Bullet::~Bullet() {}

void Bullet::draw()
{
	drawTexture(game->getTexture(carTexture));
}

void Bullet::update()
{
    setPosition(getX() + SPEED, getY());
    vector<Collider*> collisions = game->getContainer()->getCollisions(this);

    for (auto c : collisions)
    {
        if (c->receiveBulletCollision(this))
            setDead(true);
    }

    //delete after range
    if (getX() - initialPos >= RANGE)
    {      
        setDead(true);
    }
}
