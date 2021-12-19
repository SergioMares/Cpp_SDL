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

void GameObjectGenerator::forceAddObject(Game* game, int id)
{
    GameObject* o = nullptr;
    switch (id)
    {
    case 1:
        o = new Rock(game);
        break;
    case 2:
        o = new PowerUp(game);
        break;
    case 3:
        o = new Coin(game);
        break;
    case 4:
        o = new Turbo(game);
        break;
    case 5:
        o = new Superrock(game);
        break;
    case 6:
        o = new Oil(game);
        break;
    case 7:
        o = new Truck(game);
        break;
    default:
        break;
    }

    if (o != nullptr)
    {
        o->setPosition(game->getCarX() + game->getWindowWidth() / 2, game->getInfoSize() + o->getHeight()/2);
        game->addToContainer(o);
    }
}
