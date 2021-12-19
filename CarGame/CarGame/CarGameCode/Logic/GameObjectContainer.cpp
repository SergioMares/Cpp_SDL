#include "GameObjectContainer.h"
#include "GameObjects/GameObject.h"

GameObjectContainer::~GameObjectContainer()
{
	for (auto obj : gameObjects)
	{
		obj->onDelete();
		delete obj;		
	}
	gameObjects.clear();
}

void GameObjectContainer::update()
{
	for (auto obj : gameObjects)
	{
		obj->update();
	}
		
		
	//cout << "total G&B Objects" << gameObjects.size() << endl;
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
	gameObject->onEnter();
}

void GameObjectContainer::removeDead()
{
	for (auto i = gameObjects.begin(); i != gameObjects.end(); ++i) 
	{
		if ((*i)->getDead())
		{
			(*i)->onDelete();
			delete *i;
			gameObjects.erase(i);
			break;
		}
	}
}

bool GameObjectContainer::hasCollision(GameObject* g)
{	
	if (getCollisions(g).size() > 0)
	{
		return true;
	}
	else 
		return false;
}

vector<GameObject*> GameObjectContainer::getObjects()
{
	return gameObjects;
}

vector<Collider*> GameObjectContainer::getCollisions(GameObject* g)
{
	Point2D<int> l1, r1, l2, r2;
	SDL_Rect	GO1 = g->getCollider(),
				*GO2 = NULL;
	vector<Collider*> colls;

	
	if (!gameObjects.empty())
	{
		for (auto obj : gameObjects)
		{

			GO2 = &obj->getCollider();

			l1 = { GO1.x, GO1.y };
			r1 = { GO1.x + GO1.w, GO1.y + GO1.h };

			l2 = { GO2->x, GO2->y };
			r2 = { GO2->x + GO2->w, GO2->y + GO2->h };

			// If one rectangle is on left side of other or above
			if (!((l1.getX() >= r2.getX() || l2.getX() >= r1.getX()) || 
				(r1.getY() <= l2.getY() || r2.getY() <= l1.getY())))
				colls.push_back(obj);			
		}
	}			

	return colls;
}

vector<Collider*> GameObjectContainer::getCollisions(int x, int y, int range)
{
	Point2D<int>		l1, r1, l2, r2;
	SDL_Rect*			GO2 = NULL;
	vector<Collider*>	colls;	


	if (!gameObjects.empty())
	{
		for (auto obj : gameObjects)
		{
			GO2 = &obj->getCollider();

			l1 = { x - (range / 2), y - (range / 2) };
			r1 = { x + (range / 2), y + (range / 2) };

			l2 = { GO2->x, GO2->y };
			r2 = { GO2->x + GO2->w, GO2->y + GO2->h };


			cout << "clicked x: " << x << endl;
			cout << "fixed x: " << r1.getX() << endl;

			// If one rectangle is on left side of other or above
			if (!((l1.getX() >= r2.getX() || l2.getX() >= r1.getX()) ||
				(r1.getY() <= l2.getY() || r2.getY() <= l1.getY())))
				colls.push_back(obj);
		}
	}

	return colls;
}

vector<Collider*> GameObjectContainer::getCollisions()
{
	vector<Collider*> colls;

	if (!gameObjects.empty())
	{
		for (auto obj : gameObjects)					
			colls.push_back(obj);		
	}

	return colls;
}
