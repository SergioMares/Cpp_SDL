#include "Coin.h"
#include "../Game.h"

Coin::~Coin()
{
	onDelete();
}

void Coin::draw()
{
	drawTexture(game->getTexture(coinTexture));
}

void Coin::update()
{
	setPosition(getX(), getY());
}

bool Coin::receiveCarCollision(Car* car)
{
	setDead(true);
	game->modCoins(1);
	return false;
}