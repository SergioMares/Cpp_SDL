#include "PowerUp.h"
#include "../Game.h"


void PowerUp::draw()
{
	drawTexture(game->getTexture(powerUpTexture));
}

void PowerUp::update()
{
	setPosition(getX(), getY());
}

bool PowerUp::receiveCarCollision(Car* car)
{
	setDead(true);
	return game->modPower(1);
}
