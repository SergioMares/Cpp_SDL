#include "Turbo.h"
#include "../Game.h"


void Turbo::draw()
{
	drawTexture(game->getTexture(turboTexture));
}

void Turbo::update()
{
	setPosition(getX(), getY());
}

bool Turbo::receiveCarCollision(Car* car)
{
	setDead(true);
	car->setVelocity(20);
	return false;
}
