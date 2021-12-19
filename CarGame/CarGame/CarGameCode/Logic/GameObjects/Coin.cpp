#include "Coin.h"
#include "../Game.h"


void Coin::draw()
{
	drawTexture(game->getTexture(coinTexture));
}

bool Coin::receiveCarCollision(Car* car)
{
	setDead(true);
	game->modCoins(1);
	return false;
}
