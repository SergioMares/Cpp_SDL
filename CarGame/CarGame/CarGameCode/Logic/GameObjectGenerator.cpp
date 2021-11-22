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
	/*unsigned int tempoSize = rand() % game->ROCK_SIZE + game->ROCK_RANGE;
	o->setDimension(tempoSize, tempoSize);*/
		
	unsigned int tempoPosX = rand() % (game->getRoadLength() - game->ROCK_SIZE)+ (game->ROCK_SIZE + game->CAR_WIDTH);
	unsigned int tempoPosY = rand() % (game->getWindowHeight() - game->ROCK_SIZE) + game->getInfoSize();

	o->setPosition(tempoPosX, tempoPosY);

	if (!game->getContainer()->hasCollision(o))
		game->getContainer()->add(o);
	else
		delete o;
}
