#include "Turbo.h"
#include "../Game.h"

Turbo::~Turbo()
{
	onDelete();
}

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
	car->needforspeed();
	return false;
}
