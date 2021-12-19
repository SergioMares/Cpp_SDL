#pragma once
#include "GameObject.h"
#include "../Game.h"
class Bullet : public GameObject
{
	const int w = 20; 
	const int h = 5;

	const int SPEED = 30;
	const int RANGE = 1400;
	int initialPos = 0;

public:
	Bullet(Game* game) : GameObject(game)
	{
		setDimension(w, h);				
	};

	~Bullet() = default;
	
	void draw() override;
	void update() override;

	void setInitPos(int initPos) { initialPos = initPos; };
};

