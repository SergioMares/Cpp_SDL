#pragma once
#include "GameObject.h"
#include "../Game.h"
class Bullet : public GameObject
{
	const int w = 20; 
	const int h = 5;

	const int SPEED = 15;
	const int RANGE = 700;

public:
	Bullet(Game* game) : GameObject(game)
	{
		setDimension(w, h);		
		//cout << game->getOrigin().getX() << endl;
	};

	~Bullet();
	
	void draw() override;
	void update() override;
};

