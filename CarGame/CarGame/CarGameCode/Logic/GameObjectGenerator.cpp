#include "GameObjectGenerator.h"

Point2D<int> GameObjectGenerator::generateRandomPosition(Game* game, GameObject* o)
{
	return Point2D<int>(
		rand() % game->getRoadLength() + o->getWidth(),
		rand() % game->getWindowHeight() + game->getInfoSize()
		);	
}

void GameObjectGenerator::addInRandomPosition(Game* game, GameObject* o)
{
	int maxX = game->getRoadLength() - o->getWidth();
	int minX = o->getWidth();
	int tempoPosX = rand() % (maxX - minX + 1) + minX;

	int maxY = game->getWindowHeight() - o->getHeight();
	int minY = o->getHeight();
	int tempoPosY = rand() % (maxY - minY + 1) + minY;

	o->setPosition(tempoPosX, tempoPosY);

	if (!game->hasCollisions(o))
		game->addToContainer(o);
	else
		delete o;
}
