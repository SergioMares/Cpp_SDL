#include "Bullet.h"

Bullet::~Bullet() {}

void Bullet::draw()
{
	drawTexture(game->getTexture(carTexture));
}

void Bullet::update()
{
    setPosition(getX() + SPEED, getY());

    //the car ask who is colliding with him

    vector<Collider*> collisions = game->getContainer()->getCollisions(this);

    for (auto c : collisions)
    {
        if (c->receiveBulletCollision(this))
            setDead(true);
    }
}
