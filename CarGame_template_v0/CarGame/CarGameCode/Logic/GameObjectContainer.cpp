#include "GameObjectContainer.h"
#include "GameObjects/GameObject.h"

GameObjectContainer::~GameObjectContainer()
{
	puts("destructor gameObjectContainer pendiente");
}

void GameObjectContainer::update()
{
	for (auto obj : gameObjects)
		obj->update();
}

void GameObjectContainer::draw()
{
	for (auto obj : gameObjects)
		obj->draw();
}

void GameObjectContainer::drawDebug()
{
	for (auto obj : gameObjects)
		obj->drawDebug();
}

void GameObjectContainer::add(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}

void GameObjectContainer::removeDead()
{
	for (auto i = gameObjects.begin(); i != gameObjects.end(); ++i) 
	{
		if ((*i)->getDead()) 
			gameObjects.erase(i);
	}
}

bool GameObjectContainer::hasCollision(GameObject* g)
{
	return false;
}

vector<Collider*> GameObjectContainer::getCollisions(GameObject* g)
{
	return vector<Collider*>();
}
